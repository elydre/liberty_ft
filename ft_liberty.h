#ifndef FT_SETJMP_H
#define FT_SETJMP_H

#include <stddef.h>

// idk, probably not the right size
typedef long long ft_jmp_buf[16];

// defined in ft_setjmp.s
int  ft_setjmp(ft_jmp_buf env);
void ft_longjmp(ft_jmp_buf env, int val);

#ifdef __GNUC__
// gcc has a built-in alloca
void *ft_alloca(size_t size);
#define ft_alloca(size) __builtin_alloca(size)
#else
// fuck you warning
void *alloca(size_t size);
#define ft_alloca(size) alloca(size)
#endif

#endif
