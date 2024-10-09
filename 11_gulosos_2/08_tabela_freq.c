/*
8) Escreva uma função que tendo como entrada uma sequência de caracteres, o
seu algoritmo gera uma tabela de frequência de caracteres gastando tempo O(n),
onde n é o tamanho da sequência de caracteres.
*/

#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256 // Tamanho máximo da tabela ASCII

// Função para gerar a tabela de frequência de caracteres
void gerarTabelaFrequencia(char *sequencia, int frequencia[])
{
    int tamanho = strlen(sequencia); // Tamanho da sequência de caracteres

    // Inicializa o array de frequência com 0
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        frequencia[i] = 0;
    }

    // Itera sobre a sequência de caracteres e atualiza a frequência
    for (int i = 0; i < tamanho; i++)
    {
        char charAtual = sequencia[i];
        frequencia[charAtual]++;
    }
}

int main()
{
    char *sequencia = "exemplo de texto para calcular frequencia"; // Entrada de exemplo
    int frequencia[ASCII_SIZE];                                    // Array para armazenar a frequência de cada caractere

    gerarTabelaFrequencia(sequencia, frequencia);

    // Imprimir a tabela de frequência
    printf("Tabela de frequência de caracteres:\n");
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (frequencia[i] > 0)
        {
            printf("'%c' : %d\n", i, frequencia[i]);
        }
    }

    return 0;
}
