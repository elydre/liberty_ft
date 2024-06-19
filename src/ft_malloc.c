/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:05:09 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 14:27:46 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include <stdlib.h>

static t_block	**get_block(void)
{
	static t_block	*first = NULL;

	return (&first);
}

void	*ft_malloc(size_t size, int level)
{
	t_block	*block;

	block = malloc(sizeof(t_block) + size);
	if (block == NULL)
		return (NULL);
	block->size = size;
	block->level = level;
	block->next = *get_block();
	block->prev = NULL;
	if (block->next != NULL)
		block->next->prev = block;
	*get_block() = block;
	return ((void *)(block + 1));
}

void	ft_free(void *ptr)
{
	t_block	*block;

	block = (t_block *)ptr - 1;
	if (block->prev != NULL)
		block->prev->next = block->next;
	if (block->next != NULL)
		block->next->prev = block->prev;
	if (*get_block() == block)
		*get_block() = block->next;
	free(block);
}

int	ft_free_level(int level)
{
	t_block	*block;
	t_block	*next;
	int		count;

	count = 0;
	block = *get_block();
	while (block != NULL)
	{
		next = block->next;
		if (block->level == level)
		{
			if (block->prev != NULL)
				block->prev->next = block->next;
			if (block->next != NULL)
				block->next->prev = block->prev;
			if (*get_block() == block)
				*get_block() = block->next;
			free(block);
			count++;
		}
		block = next;
	}
	return (count);
}

int	ft_free_all(void)
{
	t_block	*block;
	t_block	*next;
	int		count;

	count = 0;
	block = *get_block();
	while (block != NULL)
	{
		next = block->next;
		if (block->prev != NULL)
			block->prev->next = block->next;
		if (block->next != NULL)
			block->next->prev = block->prev;
		free(block);
		block = next;
		count++;
	}
	*get_block() = NULL;
	return (count);
}
