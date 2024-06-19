/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liberty.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:23:43 by pf4               #+#    #+#             */
/*   Updated: 2024/06/19 14:26:29 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBERTY_H
# define FT_LIBERTY_H

# include <stddef.h>

// idk, probably not the right size
typedef long long	t_jmp_buf[16];

// defined in ft_setjmp.s
int			ft_setjmp(t_jmp_buf env);
void		ft_longjmp(t_jmp_buf env, int val);

// defined in notaglobal.c
void		*nag(int index);
int			nag_write(int index, void *ptr);
void		*nag_read(int index);

// defined in ft_alloca.s
void		*ft_alloca(size_t size);

# ifdef _GNUC_
#  define FT_ALLOCA __builtin_alloca
# else

// unused with modern compilers
extern void	*alloca(size_t size);

#  define FT_ALLOCA alloca
# endif

// defined in ft_malloc.c
void		*ft_malloc(size_t size, int level);
void		ft_free(void *ptr);
int			ft_free_level(int level);
int			ft_free_all(void);

// defined in ft_realloc.c
void		*ft_realloc(void *ptr, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_stralloc(const char *str);

#endif
