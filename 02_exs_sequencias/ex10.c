/*
Suponha o seguinte problema:
Enumerar todas as sequências possíveis de 3 dígitos, por exemplo se tivermos
os dígitos 1, 2 e 3 teríamos como resultado:
1 1 1, 1 1 2, 1 1 3, 1 2 1, 1 2 2, 1 2 3, 1 3 1, 1 3 2, 1 3 3,
2 1 1, 2 1 2, 2 1 3, 2 2 1, 2 2 2, 2 2 3, 2 3 1, 2 3 2, 2 3 3,
3 1 1, 3 1 2, 3 1 3, 3 2 1, 3 2 2, 3 2 3, 3 3 1, 3 3 2, 3 3 3
Nesse caso teremos 27 (3^3) sequências.
Uma dica é resolver o problema usando uma função recursiva, armazenar os
dígitos no vetor a[1..n] e as sequências geradas no vetor s[1..n], onde n=3.
*/

#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

void enumerarSequencias(int vetor[], int posicaoAtual, int qtdDigitos, int unidadeMax) {
    printf("Chamada da função para posição %d\n", posicaoAtual);
    // caso base: Se alcançamos a última posição, imprimimos o vetor
    if (posicaoAtual == qtdDigitos) {
        printf("Entramos no caso base da posição %d\n", posicaoAtual);
        printArray(vetor, qtdDigitos);
        return;
    }

    // Iterar sobre todos os valores possíveis para a posição atual
    for (int i = 1; i <= unidadeMax; i++) {
        printf("Entramos no for loop da posição %d, com i %d\n", posicaoAtual, i);
        vetor[posicaoAtual] = i;
        // Chamar recursivamente para preencher a próxima posição
        enumerarSequencias(vetor, posicaoAtual + 1, qtdDigitos, unidadeMax);
    }
}

int main() {
    int qtdDigitos = 3;
    int unidadeMax = 3;
    int vetor[qtdDigitos];

    enumerarSequencias(vetor, 0, qtdDigitos, unidadeMax);

    return 0;
}




/* EXPLICAÇÃO

caso base
Quando posicaoAtual atinge qtdDigitos, significa que todos os dígitos da sequência foram atribuídos.
A função imprime a sequência e retorna, finalizando essa ramificação da recursão.

recursão
O loop for atribui o valor i à posição posicaoAtual do vetor.
A função enumerarSequencias é então chamada recursivamente para preencher a próxima posição (posicaoAtual + 1).
Esse processo continua até que posicaoAtual seja igual a qtdDigitos, momento em que a sequência completa é impressa.

fluxo
Primeira Chamada: posicaoAtual começa em 0, e o código tenta todos os valores de 1 até unidadeMax para a primeira posição do vetor.
Segunda Posição: Para cada valor na primeira posição, o código recursivamente preenche a segunda posição com todos os valores de 1 até unidadeMax.
Terceira Posição: Esse processo continua até que todas as posições do vetor estejam preenchidas, e a função alcança o caso base, imprimindo o vetor.
Retroceder e Continuar: Após imprimir uma sequência, a recursão "retrocede" para a última chamada feita e continua tentando outros valores para preencher as posições anteriores. Esse processo garante que todas as combinações possíveis sejam exploradas e impressas.

*/