/*
8. Dada uma sequência de números inteiros com n elementos, escreva uma função
na linguagem C determinar um segmento de soma máxima.
Exemplo: Na sequência 5 2 -2 -7 3 14 10 -3 9 -6 4 1, a soma do
segmento é 33.
Qual é complexidade da sua função ?
*/

#include <stdio.h>

int somaElementos(int v[], int tam, int indiceInicial, int indiceFinal) {
    int soma = 0;
    for (int i = indiceInicial; i <= indiceFinal; i++) {
        soma += v[i];
    }
    return soma;
}

void segmentoSomaMaxima(int v[], int tam, int* indiceInicialMax, int* indiceFinalMax, int* somaMax) {
    int maiorSoma = 0;
    int soma;
    int maiorInicio, maiorFim;
    for (int i = 0; i < tam; i++) {
        for (int j = tam - 1; j >= i; j--) {
            soma = somaElementos(v, tam, i, j);
            if (soma > maiorSoma) {
                maiorSoma = soma;
                *somaMax = soma;
                *indiceInicialMax = i;
                *indiceFinalMax = j;
            }
        }
    }

}

int main() {
    int vetor[] = {20, -30, 15, -10, 30, -20, -30, 30};
    int tamanho = sizeof(vetor)/sizeof(int);
    int somaMax, indiceInicialMax, indiceFinalMax;

    segmentoSomaMaxima(vetor, tamanho, &indiceInicialMax, &indiceFinalMax, &somaMax);

    printf("Soma max = %d", somaMax);
    printf("Indice inicial = %d", indiceInicialMax+1);
    printf("Indice final = %d", indiceFinalMax+1);

    return 0;
}