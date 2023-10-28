#include <stdio.h>
#include <stdlib.h>

void user_input()
{
    int integer1;
    int integer2;
    printf("Give two integers: ");
    scanf("%d", &integer1);
    scanf("%d", &integer2);
    printf("You entered %d and %d, their sum is: %d\n", integer1, integer2, integer1 + integer2);
    float mult1;
    float mult2;
    printf("Give two floats: ");
    scanf("%f", &mult1);
    scanf("%f", &mult2);
    printf("You entered %f and %f, their product is %f\n", mult1, mult2, mult1 * mult2);
    char printTwice[] = "word";
    printf("Give a word: ");
    scanf("%s", printTwice);
    printf("%s, %s\n", printTwice, printTwice);
}


int main()
{
    user_input();
    return 0;
}
