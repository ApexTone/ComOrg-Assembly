#include <stdio.h>
int main()
{
    int a,b;
    printf("Positive modulus\n");
    printf("Enter number 1: ");
    scanf("%d", &a);
    printf("Enter number 2: ");
    scanf("%d", &b);
    int i=mod_func(a,b);
    printf("%d %% %d = %d",a,b,i);
    return 0;
}
