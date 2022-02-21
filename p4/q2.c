#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int compara(FILE * arquivo1, FILE * arquivo2);

int main(int argc, char* argv [])
{

    for (int i = 1; i < argc; i++){
        FILE * arquivo1; 
        arquivo1 = fopen(argv[i], "rb");


        for (int j = i+1; j < argc; j++){
            FILE * arquivo2;
            arquivo2 = fopen(argv[j], "rb");

            if (arquivo1 == NULL || arquivo2 == NULL)
            {
                perror("fopen");
                exit(errno);
            }

            int diff;
            diff = compara(arquivo1, arquivo2);
            if (diff == 0)
            {
                printf("%s %s iguais\n", argv[i], argv[j]);
            } else {
                printf("%s %s diferentes\n", argv[i], argv[j]);
            }

        }
        
    }

    return 0;
}


int compara(FILE * arquivo1, FILE * arquivo2)
{
    char ch1, ch2;

    do
    {
        ch1 = fgetc(arquivo1);
        ch2 = fgetc(arquivo2);
        
        if (ch1 != ch2)
            return -1;

    } while (ch1 != EOF && ch2 != EOF);


    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}