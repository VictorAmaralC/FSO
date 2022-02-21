#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t p;
    p = fork();
    printf("Ola mundo\n");
    sleep(50);
}