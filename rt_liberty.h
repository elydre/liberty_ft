/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_liberty.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pf4 <oui@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:23:43 by pf4               #+#    #+#             */
/*   Updated: 2024/06/23 13:49:21 by pf4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_LIBERTY_H
# define RT_LIBERTY_H

# include <stddef.h>
# include <stdint.h>

// idk, probably not the right size
typedef int64_t	t_jmp_buf[16];

// defined in rt_setjmp.s
int			rt_setjmp(t_jmp_buf env);
void		rt_longjmp(t_jmp_buf env, int val);

// defined in rt_nag.c
void		*nag(int index);
int			nag_write(int index, void *ptr);
void		*nag_read(int index);

// defined in rt_alloca.s
void		*rt_alloca(size_t size);

# ifdef _GNUC_
#  define RT_ALLOCA __builtin_alloca
# else

// unused with modern compilers
extern void	*alloca(size_t size);

#  define RT_ALLOCA alloca
# endif

// defined in rt_malloc.c
void		*rt_malloc(size_t size, int level);
void		rt_free(void *ptr);
int			rt_free_level(int level);
int			rt_free_all(void);

// defined in rt_realloc.c
void		*rt_realloc(void *ptr, size_t size);
void		*rt_calloc(size_t nmemb, size_t size, int level);
char		*rt_stralloc(const char *str, int level);

// defined in rt_catv.c
char		*rt_catv(char *str, ...);

#endif
