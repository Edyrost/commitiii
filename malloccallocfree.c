#include <stdio.h>

int main() {
    int *a, b;
    b = 10;
    a = (int *)malloc(sizeof(int));
    *a = 20;
    free(a);
    a = &b;
    printf("Valor de b: %d\n", *a);

    return 0;
    


}