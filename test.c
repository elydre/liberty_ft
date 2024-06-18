#include "ft_liberty.h"

#include <string.h>
#include <stdio.h>

ft_jmp_buf env;

void f() {
    printf("f() called\n");
    ft_longjmp(env, 1);
    printf("should not be called\n");
}

int main() {
    int a = ft_setjmp(env);

    printf("setjmp returned %d\n", a);

    if (a == 0) {
        f();
        printf("should not be called\n");
    }
    
    printf("end of main\n");

    void *p = ft_alloca(100);
    memset(p, 0, 100);

    return 0;
}
