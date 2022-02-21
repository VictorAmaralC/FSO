#include<stdio.h>
#include<stdlib.h>

int main(void){
    int semente;
    
    printf("Digite a sua semente:\n");
    scanf("%d",&semente);
    
    for(int i=0;i<3;i++)
        printf("%d\n",rand_r(&semente)%256);

}