#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int strtoint(char *charnums)
{
    int number = 0;
    int index = 0;
    while (charnums[index])
    {
        if (('0' <= charnums[index]) && (charnums[index] <= '9'))
        {

            if (!number)
                number = ((int)charnums[index]) - 48;
            else
            {
                number = (number *= 10) + ((int)charnums[index] - 48);
            }
            index++;
        }
        else
        {
            number = -1;
            break;
        }
    }
    return number;
}

int main(int argc, char *argv[])
{

    int mul = 1;
    char s[10] = {'\0'};
    do
    {
        read(3, s, 10);
        strtoint(s) != -1 ? mul *= strtoint(s) : mul;
    } while (strcmp(s, "carp") != 0);

    printf("\nCarpim = %d \n", mul);

    return 0;
}