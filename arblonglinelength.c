#include <stdio.h>
#define MAXLINE 10

/*
The most absurd thing:
when MAXLINE between 1 and 15 inclusive,
entering a string with length equal to MAXLINE + 4
results in max being set to 0.

When a char array is declared + instantiated between len and max,
this does not happen. What on earth?

I FIGURED IT OUT:

I was setting s[i] = '\0'; at around line 64. This was outside any
array size checks. It seems that memory is only allocated when the variable
is given a value (which kinda makes sense).

So line[] was given space in memory first, then len later. So when we 
overstepped line's bounds, we affected the value of len.
*/


int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

void main()
{
    printf("size of int: %d\n", sizeof(int));
    printf("size of char: %d\n", sizeof(char));
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    printf("MAX SET TO 0\n");

    while((len = getline_custom(line, MAXLINE)) > 0) {
        printf("\nlen outer: %d\n", len);
        printf("max outer: %d\n\n", max);
        if (len > max) {
            max = len;
            copy(longest, line);
            printf("\nlen: %d\n", len);
            printf("max: %d\n", max);
        }
    }
    if (max > 0)
        printf("LENGTH: %d ... %s", max, longest);
}

int getline_custom(char s[], int lim)
{
    printf("\nLIM: %d\n", lim);
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        printf("i: %d, c: %i ", i, c);
        if (i < lim - 2)
            s[i] = c;
    }
   
    if (c == '\n') {
        if (i < lim - 1) {
            s[i] = c;
            ++i;
            s[i] = '\0';
        }
   
        printf("i: %d, ", i);
    }

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

