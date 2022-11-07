#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{

    char s[10];
    printf("topla prog\n");

    do
    {
        read(3, s, 10);
        printf("deger= %s \n", s);
    } while (strcmp(s, "topla") != 0);

    return 0;
}