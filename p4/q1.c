#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int quadros, pf;
} pageFault;

int verifica(int *v, int quadros, int tamVet){
    int *r = malloc(quadros*sizeof(int));

    for(int i = 0; i < quadros; i++)
        r[i] = -1;

    int contador = 0, init = 0, anomalia, aux;

    for (int i = 0; i < tamVet; i++){
        aux = v[i];
        anomalia = 0;
        for(int j = 0; j < quadros; j++){
            if(aux == r[j]){
                anomalia = 1;
                break;
            }
        }
        if(anomalia == 0){
            if(init < quadros){
                r[init] = aux;
                init++;
            }
            else if(init == quadros){
                r[0] = aux;
                init = 1;
            }
            contador ++;
        }
    }

    printf("%d %d\n", quadros, contador);
    return contador;
}

int main(){
    int n, paginas, quadros, belady = 0;

    scanf("%d", &n);
    int *v = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &paginas);
        v[i] = paginas;
    }

    pageFault pf[n];
    int i = 0, j = 0;
    int menorQuadro, menorQuadroPF, atualPF;

    while (scanf("%d", &quadros) != EOF){
        atualPF = verifica(v, quadros, n);

        pf[j].pf = atualPF;
        pf[j].quadros = quadros;
        j++;

        if(i == 0) {
            menorQuadro = quadros;
            menorQuadroPF = atualPF;
            i++;
        }
        
        if (i != 0 && quadros < menorQuadro){
            menorQuadro = quadros;
            menorQuadroPF = atualPF;
        }
    }    

    for(int x = 0; x < j; x++){
        if(pf[x].quadros > menorQuadro && pf[x].pf > menorQuadroPF){
            belady = 1;
            break;
        }
    }
    
    
    if(belady == 0)
        printf("Sem anomalia\n");
    else 
        printf("Belady detectado\n");

    return 0;
}