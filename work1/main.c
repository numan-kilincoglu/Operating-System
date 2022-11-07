#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int pipefd[2];

void topla(){

    printf("topla\n");
    int ev = 0;
    int pf = fork();

    if(pf == 0){

        ev = execv("topla", NULL, NULL);
        perror("");

    }else{

        char s[10];
        read(pipefd[1], s, strlen(s));
        while(strcmp(s, "topla") != 0){
            read(pipefd[1], s, strlen(s));
            print("%s ", s);
        }

        wait[&ev];

    }
}


void carp() {



}

int main(){
    char s[10];
    printf("topla prog\n");
    read(3, s, 10);

    printf("deger= %s \n", s);

    return 0;
}