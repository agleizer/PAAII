/*
2. (URI Online Judge | 1055) Soma Permutada Elegante
São disponibilizados a você̂ n inteiros A1A2A3 · · · An. Encontre uma permutação destes n
inteiros de forma que a soma da diferença absoluta entre os elementos adjacentes seja
maximizada.
Supondo n = 4 e que os inteiros fornecidos sejam 4 2 1 5. A permutação 2 5 1 4 permite a
máxima soma. Para esta permutação, teríamos soma = abs(2-5) + abs(5-1) + abs(1-4) = 3+4+3
= 10. De todas as 24 permutações possíveis, você̂ não vai obter qualquer soma cujo valor
exceda 10. Nós iremos chamar este valor 10, de soma permutada elegante.
Escreva uma função, usando Backtracking, que dado n inteiros encontre o valor da permutada
elegante. 
*/

#include <stdio.h>
#include <stdlib.h> // abs()

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

// retorna valor da soma da diferença absoluta entre os elementos adjacentes
int somaDiffAbs(int v[], int tam) {
    int result = 0;
    for (int i = 1; i < tam; i++) {
        result += abs(v[i]-v[i-1]);
    }
    return result;
}

// função para gerar permutações
// uso de um vetor adicional para armazenar de determinado valor já foi utilizado
// o indice é o valor, usado[indice] = 0 se usado, 1 se não usado
// j percorre o vetor de opções (v[]), i percorre o vetor de soluções. i deve comecar em 0.
void mostraSeqPermuta(int opcoes[], int tamOpcoes, int solucoes[], int tamSolucoes, int usados[], int tamUsados, int i, int* somaMax) {
    if (i == tamSolucoes) {
        printArray(solucoes, tamSolucoes);
        int somaAtual = somaDiffAbs(solucoes, tamSolucoes);
        printf("Soma diff = %d\n", somaAtual);
        if (somaAtual > *somaMax) {
            *somaMax = somaAtual;
            printf("Novo máximo! Salvando...\n");
        }
    } else {
        for (int j = 0; j < tamOpcoes; j++) {
            if (!usados[j]) { // checar se elemento foi usado
                solucoes[i] = opcoes[j];
                usados[j] = 1; // marcar como usado
                mostraSeqPermuta(opcoes, tamOpcoes, solucoes, tamSolucoes, usados, tamUsados, i + 1, somaMax);
                usados[j] = 0; // desmarcar como usado para a próxima iteração / permutação
            }
        }
    }
}

int main() {
    int opcoes[] = {4, 2, 1, 5};
    int solucoes[] = {0, 0, 0, 0};
    int used[] = {0, 0, 0, 0}; // vetor de usados começa com tudo não usado
    int somaMax = 0;
    mostraSeqPermuta(opcoes, 4, solucoes, 4, used, 4, 0, &somaMax);
}