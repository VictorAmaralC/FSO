#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void preencheVetor(int *v, int tam);
int compara (const void *a, const void *b);
void ordena (int *v, int tam);
void mesmosElementos (int *v1, int *v2, int tam);


int main(){
    int tam;
    scanf("%d", &tam);
    int *v1 = malloc(sizeof(int)*tam);
    int *v2 = malloc(sizeof(int)*tam);
    preencheVetor(v1, tam);
    preencheVetor(v2, tam);

    ordena(v1, tam);
    ordena(v2, tam);
    mesmosElementos(v1, v2, tam);

    return 0;
}

void preencheVetor(int *v, int tam){
    for(int i = 0; i<tam; i++){
        int x;
        scanf("%d", &x);
        v[i]=x;
    }
}

int compara (const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

void ordena (int *v, int tam){
    qsort(v, tam, sizeof(int), compara);
}

void mesmosElementos (int *v1, int *v2, int tam){
    for(int i = 0; i < tam; i++)
        if(v1[i] != v2[i]){
            printf("Diferentes\n");
            return;
        }

    printf("Mesmos elementos\n");
}