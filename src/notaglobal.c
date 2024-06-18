/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notaglobal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:31:46 by pf4               #+#    #+#             */
/*   Updated: 2024/06/18 21:01:40 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_liberty.h"

void	*nag(int index)
{
	static void	*mem[32] = {NULL};

	if (index < 0 || index >= 32)
		return (NULL);
	return (mem + index);
}

int	nag_write(int index, void *ptr)
{
	void	**mem;

	mem = nag(index);
	if (!mem)
		return (-1);
	*mem = ptr;
	return (0);
}

void	*nag_read(int index)
{
	void	**mem;

	mem = nag(index);
	if (mem)
		return (*mem);
	return (NULL);
}
