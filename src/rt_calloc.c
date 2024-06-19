/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:21 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 17:25:55 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_malloc.h"

void	*rt_realloc(void *ptr, size_t size)
{
	t_block	*block;
	void	*new;

	if (ptr == NULL)
		return (rt_malloc(size, 0));
	block = (t_block *)ptr - 1;
	new = rt_malloc(size, block->level);
	if (new == NULL)
		return (NULL);
	rt_free(ptr);
	return (new);
}

void	*rt_calloc(size_t nmemb, size_t size, int level)
{
	void	*ptr;
	size_t	i;

	ptr = rt_malloc(nmemb * size, level);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}

char	*rt_strdup(const char *str, int level)
{
	char	*ptr;
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	ptr = rt_malloc(len + 1, level);
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
	{
		ptr[len] = str[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
