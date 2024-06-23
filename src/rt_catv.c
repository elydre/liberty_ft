/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_catv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:46:40 by pf4               #+#    #+#             */
/*   Updated: 2024/06/23 13:55:44 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_malloc.h"
#include <stdarg.h>

static void	_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
}

static int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*rt_catv(char *str, ...)
{
	va_list	ap;
	char	*tmp;
	char	*new;
	int		len;

	va_start(ap, str);
	len = 0;
	tmp = va_arg(ap, char *);
	while (tmp != NULL)
	{
		len += _strlen(tmp);
		tmp = va_arg(ap, char *);
	}
	va_end(ap);
	new = rt_calloc(len + _strlen(str) + 1, sizeof(char), 0);
	_strcat(new, str);
	va_start(ap, str);
	tmp = va_arg(ap, char *);
	while (tmp != NULL)
	{
		_strcat(new, tmp);
		tmp = va_arg(ap, char *);
	}
	va_end(ap);
	return (new);
}
