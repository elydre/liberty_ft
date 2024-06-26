/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:15:28 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 17:24:42 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_liberty.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = rt_malloc(10, 0);
	b = rt_malloc(20, 1);
	c = rt_malloc(30, 1);
	strcpy(a, "Hello");
	strcpy(b, "World");
	strcpy(c, "!");
	printf("a: %s\n", a);
	rt_free(a);
	printf("c: %s\n", c);
	rt_free(c);
	printf("b: %s\n", b);
	rt_free(b);
	printf("total free: %d\n", rt_free_all());
	return (0);
}
