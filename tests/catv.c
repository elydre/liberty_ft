/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:56:15 by pf4               #+#    #+#             */
/*   Updated: 2024/06/23 13:56:40 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_liberty.h"
#include <stdio.h>

int	main(void)
{
	char	*out;

	out = rt_catv("Hello", " ", "World", "!", NULL);
	printf("%s\n", out);
	rt_free(out);
	return (0);
}
