#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int x = 0;

void trata(int s){
    if(s==SIGUSR1)
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    else if(s==SIGALRM){
        x++;
        if(x==3){
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        } 
        printf("Ai que sono, quero dormir mais um pouco\n"); 
    }
}

int main(){
    signal(SIGUSR1, trata);
    signal(SIGALRM, trata);

    while(1)
        pause();
}