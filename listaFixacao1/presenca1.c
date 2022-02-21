#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int controle = 0;

void trata(int s){
    printf("Recebi %d\n", s);
    if(controle == 0 && s == SIGINT) controle++;
    else if (controle == 1 && s == SIGUSR2) controle++;
    else if (controle == 2 && s == SIGTERM){
        controle++;
        printf("Senha acionada\n");
    }
    else if (s==SIGINT) controle =1;
    else if(controle == 3 && s == SIGUSR1){
        printf("Tchau\n");
        exit(0);
    }
    else controle = 0;
}

int main(){
    signal(SIGINT, trata);
    signal(SIGTERM, trata);
    signal(SIGUSR1, trata);
    signal(SIGUSR2, trata);

    while(1)
        pause();   
}