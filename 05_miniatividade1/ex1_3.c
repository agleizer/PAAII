#include <stdio.h>

// Função que encontra o subarray com a soma máxima analisando somente se ganhos[i] é positivo ou negativo
void findMaxSubarraySum(int ganhos[], int n) {
    // Inicializa a soma máxima e a soma corrente com o primeiro elemento do array
    int maxSoma = ganhos[0];
    int somaAtual = ganhos[0];
    
    // Inicializa os índices para o início e fim do subarray com soma máxima
    int inicioMax = 0;   // Índice de início do subarray com soma máxima
    int fimMax = 0;      // Índice de fim do subarray com soma máxima
    int inicioAtual = 0; // Índice de início do subarray corrente

    // Itera sobre o array a partir do segundo elemento
    for (int i = 1; i < n; i++) {
            somaAtual += ganhos[i];

        // Atualiza a soma máxima e os índices do subarray com a soma máxima, se necessário
        if (somaAtual > maxSoma) {
            maxSoma = somaAtual;
            inicioMax = inicioAtual;
            fimMax = i;
        }
    }

    // Imprime a soma máxima acumulada
    printf("A soma máxima acumulada é %d\n", maxSoma);

    // Imprime o período (intervalo) dos dias que corresponde à soma máxima
    // +1 é adicionado para converter de índice baseado em zero para o formato de dia 1, 2, ..., n
    printf("Ela ocorre no período do dia %d ao dia %d\n", inicioMax + 1, fimMax + 1);
}

int main() {
    // Exemplo de ganhos diários
    int ganhos[] = {20, -30, 15, -10, 30, -20, -30, 30};
    // Calcula o número de elementos no array
    int n = sizeof(ganhos) / sizeof(ganhos[0]);
    // Chama a função para encontrar o subarray com a soma máxima
    findMaxSubarraySum(ganhos, n);
    return 0;
}
