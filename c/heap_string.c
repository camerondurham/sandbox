#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* strdup_every_other_char(const char* s) {

    // if allowed to use string.h
    // int size = (strlen(s) + 1)/2;

    // otherwise, do it myself
    int size = 0;
    int i = 0;
    while(s[i]) {
        size++;
        i++;
    }
    size = (size + 1)/2;

    char* str = (char*) malloc(size);
    for(int i = 0; i < size; ++i){
        str[i] = s[2*i];
    }

    return str;

}
int main()
{

    const char* string = "house";
    char* other_letter = strdup_every_other_char(string);
    printf("s1: %s, s2: %s\n", string, other_letter);

    const char* bits = "101010101010";
    char* bits2 = strdup_every_other_char(bits);
    printf("s1: %s, s2: %s\n", bits, bits2);

    const char* even = "abcd";
    char* even_ol = strdup_every_other_char(even);
    printf("s1: %s, s2: %s\n", even, even_ol);
    free(other_letter);
    free(even_ol);
    return 0;

}
