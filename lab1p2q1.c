#include <stdio.h>
#include <stdlib.h>


void print_function()
{
    int half = 50;
    int subtract1 = 10;
    int subtract2 = 3;
    float divide1 = 5.44;
    float divide2 = 2.31;
    int a = 10;
    int *aptr;
    aptr = &a;
    int b = 0;
    b = *aptr;
    printf("%d\n", a);
    int c = 5;
    *aptr = c;
    printf("One half is %d%%\n", half);
    printf("The difference between %d and %d is %d\n", subtract1, subtract2, subtract1 - subtract2);
    printf("%f / %f is %f\n",divide1, divide2, divide1/divide2);
    printf("$\n");
}

int main()
{
    print_function();
    return 0;
}
