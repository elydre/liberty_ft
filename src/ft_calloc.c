/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:21 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 14:24:32 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	t_block	*block;
	void	*new;

	block = (t_block *)ptr - 1;
	new = ft_malloc(size, block->level);
	if (new == NULL)
		return (NULL);
	ft_free(ptr);
	return (new);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = ft_malloc(nmemb * size, 0);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}

char	*ft_stralloc(const char *str)
{
	char	*ptr;
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	ptr = ft_malloc(len + 1, 0);
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
