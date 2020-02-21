#include<stdio.h>
#include<string.h>
int main()
{
    char yoda[] = "Do or do not, there is no try.";
    char babyoda[] = "Ok, boomer.";
    printf("yoda: %s\nbabyoda: %s\n", yoda, babyoda);
    printf("performing memcpy\n");
    memcpy(yoda, babyoda, 12);
    printf("after memcpy\n");
    printf("yoda: %s\nbabyoda: %s\n", yoda, babyoda);

    char message[] = "Hello, my name is ______________";
    char name[] = "Dorian Electra";

    printf("\n\nmessage: %s\nname: %s\n",message, name);
    printf("inserting in the middle of a c-string\n");
    memcpy(message + 18, name, 15);
    printf("AFTER:\nmessage: %s\n",message);
}
