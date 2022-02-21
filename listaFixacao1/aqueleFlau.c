#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void trata(int s){
    char buff[20];
    if (scanf(" %s", buff)!= 1) exit(0);

    if(s==SIGUSR1 && !strcmp(buff, "Igor3k"))
        printf("Certo\n");
    else if(s==SIGUSR2 && !strcmp(buff, "Monark"))
        printf("Certo\n"); 
    else if(s==SIGALRM && !strcmp(buff, "Silencio"))
        printf("Certo\n"); 
    else if(s==SIGINT && !strcmp(buff, "Con1"))
        printf("Certo\n"); 
    else if(s==SIGTERM && !strcmp(buff, "Con2"))
        printf("Certo\n");
    else 
        printf("Erro\n"); 
}

int main(){
    signal(SIGINT, trata);
    signal(SIGTERM, trata);
    signal(SIGUSR1, trata);
    signal(SIGUSR2, trata);
    signal(SIGALRM, trata);

    while(1)
        pause();
}