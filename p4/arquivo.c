#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct fso{
    int idade;
    char nome[10];
    int nota;
};

int main (){
    struct fso victor = (struct fso){23, "Victor Si", 75};

    int i;
    char *a = &i;

    FILE *meuarquivo;
    meuarquivo = fopen("/tt", "w");

    if(meuarquivo == NULL){
        perror("fopen");
        exit(errno);
    }
    
    fwrite((void *)&i, 1, 4, stdout);
    fclose(meuarquivo);
    i = 0;

    printf("%d eh %s\n", i, a);
    meuarquivo = fopen("/tt", "r");
    fread((void *)&i, 1, 4, meuarquivo);
    printf("%d eh %s\n", i, a);

    return 0;
}