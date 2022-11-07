#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int pipefd[2];

void topla()
{

    int ev = 0;
    int pf = fork();

    if (pf == 0)
    {
        ev = execv("topla", NULL, NULL);
        perror("");
    }
    else
    {
        char s[10];
        do
        {
            scanf("%s", s);
            write(pipefd[1], s, strlen(s));

        } while (strcmp(s, "topla") != 0);

        wait(&ev);
    }
}

void carp()
{
    int ev = 0;
    int pf = fork();

    if (pf == 0)
    {

        ev = execv("carp", NULL, NULL);
        perror("");
    }
    else
    {
        char s[10];
        do
        {
            scanf("%s", s);
            write(pipefd[1], s, strlen(s));

        } while (strcmp(s, "carp") != 0);

        wait(&ev);
    }
}

void printMenu()
{
    printf("\n---Menu---\n");
    printf("1- Toplama\n");
    printf("2- Carpma\n");
    printf("3- Exit");
}

int main()
{

    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    int secenek = 0;

    while (secenek != 3)
    {
        printMenu();
        printf("\nSecim:");
        scanf("%d", &secenek);

        if (secenek == 1)
        {
            topla();
        }
        if (secenek == 2)
        {
            carp();
        }
        if (secenek == 3)
        {
            exit(1);
        }
    }

    return 0;
}