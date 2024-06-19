/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:12:29 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 14:20:34 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "ft_liberty.h"

typedef struct s_block
{
	struct s_block	*next;
	struct s_block	*prev;
	size_t			size;
	int				level;
}					t_block;

#endif
