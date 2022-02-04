#include <stdio.h>

int main(void)
{
    int i;
    int c;
    int temp;
    int lista[20];
    int quantProcesso;
    int slice;
    int maior;
    
    printf("Informe o time slice: ");
    scanf("%d", &slice);
    
    printf("Informe a quantidade de processos: ");
    scanf("%d", &quantProcesso);
    
    for (i=1; i <= quantProcesso; i++){
        printf("Informe o tempo de execução do processo P%d: ", i);
        scanf("%d", &lista[i-1]);
    }
    
    printf("\n");
    
    i = i - 1;
    for(c=0; c < i; c++){
        if(c == 0){
            maior = lista[0];
        }
        else{
            if(lista[c] > maior){
                maior = lista[c];
            }
        }
    }
    
    while(maior != 0){
        for(c=0; c < i; c++){
            if(lista[c] > slice){
                printf("P%d, %d; ", c+1, slice);
                lista[c] = lista[c] - slice;
            }
            else{
                if(lista[c] <= slice & lista[c] != 0){
                    printf("P%d, %d*; ", c+1, lista[c]);
                    lista[c] = 0;
                }
            }
        }
        printf("\n");
        maior = maior - slice;
        if(maior < 0){
            maior = 0;
        }
    }
}