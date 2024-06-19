/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:55 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 17:24:42 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_liberty.h"

#include <string.h>
#include <stdio.h>

void	jump_test(void)
{
	printf("f() called\n");
	rt_longjmp(**(t_jmp_buf **) nag(0), 42);
	printf("should not be called\n");
}

int	main(void)
{
	t_jmp_buf	env;
	int			a;

	*(t_jmp_buf **) nag(0) = &env;
	a = rt_setjmp(env);
	printf("setjmp returned %d\n", a);
	if (a == 0)
	{
		jump_test();
		printf("should not be called\n");
	}
	printf("end of main\n");
	return (0);
}
