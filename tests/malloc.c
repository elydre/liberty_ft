/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:15:28 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 14:27:57 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_liberty.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = ft_malloc(10, 0);
	b = ft_malloc(20, 1);
	c = ft_malloc(30, 1);
	strcpy(a, "Hello");
	strcpy(b, "World");
	strcpy(c, "!");
	printf("a: %s\n", a);
	ft_free(a);
	printf("c: %s\n", c);
	ft_free(c);
	printf("b: %s\n", b);
	ft_free(b);
	printf("total free: %d\n", ft_free_all());
	return (0);
}
