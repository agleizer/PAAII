/*
2. Considere uma partida de futebol entre duas equipes A × B, cujo placar final é m × n,
em que m e n são número de gols marcados por A e B, respectivamente. Escreva um
algoritmo recursivo que imprima todas as possíveis sucessões de gols marcados. Por
exemplo, para um placar final de 3 × 1, as possíveis sucessões de gols são “AAAB”,
“AABA”, “ABAA” e “BAAA”.
*/

#include <stdio.h>

void printArray(char array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%c ",array[i]);
    }
    printf("]\n");
}

int contaElementosArray(char vetor[], int tam, char elemento, int indiceMax) { // precisa do parametro indiceMax para fazer a contagem APENAS ató o indice que a função de combinação está trabalhandoi no momento (i atual)....
    int contagem = 0;
    for (int i = 0; i < indiceMax; i++) {
        if (vetor[i] == elemento) contagem++;
    }
    return contagem;
}

void combinacaoGols(char solucoes[], int tamSol, char opcoes[], int tamOp, int golsA, int golsB, int i) {
    if (i == tamSol) printArray(solucoes, tamSol);
    else {
        for (int j = 0; j < tamOp; j++) {
        if ((opcoes[j] == 'A' && contaElementosArray(solucoes, tamSol, opcoes[0], i) < golsA) ||
            (opcoes[j] == 'B' && contaElementosArray(solucoes, tamSol, opcoes[1], i) < golsB)) {
            solucoes[i] = opcoes[j];
            combinacaoGols(solucoes, tamSol, opcoes, tamOp, golsA, golsB, i+1);
        }
    }
    }
}

// explicação condicionais confusos!
/*
Let's break down why the first condition works and the second doesn't.
1. First Condition (Works)
if ((opcoes[j] == 'A' && contaElementosArray(solucoes, tamSol, opcoes[0], i) < golsA) ||
    (opcoes[j] == 'B' && contaElementosArray(solucoes, tamSol, opcoes[1], i) < golsB)) {

    Logic Explanation:
        The first part (opcoes[j] == 'A' && contaElementosArray(solucoes, tamSol, opcoes[0], i) < golsA) checks if the current option opcoes[j] is 'A'. If it is, it further checks if the number of 'A's currently in solucoes is less than golsA. If both conditions are true, it allows 'A' to be added to the sequence.
        Similarly, the second part (opcoes[j] == 'B' && contaElementosArray(solucoes, tamSol, opcoes[1], i) < golsB) does the same for 'B'.
        Key Point: This condition ensures that the check for 'A' or 'B' happens separately depending on which character is being considered for addition. It only checks the count of 'A' when considering adding 'A' and the count of 'B' when considering adding 'B'. This way, the character is added only if its count remains within the allowed limits.

2. Second Condition (Doesn't Work)
if ((contaElementosArray(solucoes, tamSol, opcoes[0], i) < golsA) &&
    (contaElementosArray(solucoes, tamSol, opcoes[1], i) < golsB)) {

    Logic Explanation:
        Here, the condition checks both the count of 'A' and the count of 'B' simultaneously before adding any character (opcoes[j]).
        Problem:
            Let's say j is currently pointing to 'A' (i.e., opcoes[j] == 'A'). Even if the count of 'A' is less than golsA, this condition will also require the count of 'B' to be less than golsB. If the count of 'B' has already reached golsB, the condition fails, and 'A' won't be added, even though it should be allowed.
            Conversely, if j is pointing to 'B', it will still require the count of 'A' to be less than golsA, which isn't necessary.

    Key Point: This condition mistakenly enforces a requirement that both characters' counts be below their respective limits simultaneously, which prevents valid sequences from being generated.
*/

int main() {
    char solucoes[4];
    char opcoes[] = {'A', 'B'};
    int golsA = 3;
    int golsB = 1;
    combinacaoGols(solucoes, 4, opcoes, 2, golsA, golsB, 0);

}