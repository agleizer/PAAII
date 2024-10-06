/*
2. Temos n arquivos digitais em um computador, com cada arquivo i tendo tamanho ti
megabytes. Desejamos copiar o maior número de arquivos do computador para um
pendrive de capacidade c megabytes. Formalmente, resolver este problema consiste em
determinar o maior subconjunto X do intervalo discreto 1 . . n que satisfaça a restrição
∑ i∈X ti ≤ c. Escreva um algoritmo guloso que resolva este problema de maneira efi-
ciente, determine a complexidade de tempo de execução. A estratégia gulosa adotada
devolve sempre a solução ótima? Caso negativo apresente um contra-exemplo.
*/

#include <stdio.h>

void printFloatArray(float arr[], int size)
{
    // Loop through each element in the array
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]); // Print each element with 2 decimal places
    }
    printf("\n"); // Print a newline at the end
}

void arquivosPCPendrive(float arquivosPC[], int qtdArquivosPC, float arquivosPendrive[], int *qtdArquivosPendrive, float capacidadePendrive)
{
    if (capacidadePendrive <= 0 || qtdArquivosPC <= 0)
    {
        printf("Valores inválidos.\n");
        return;
    }

    float utilizado = 0;
    int arquivoAtual = 0;
    float tamanhoAtual = arquivosPC[arquivoAtual];

    while (utilizado + tamanhoAtual <= capacidadePendrive && arquivoAtual < qtdArquivosPC)
    {
        tamanhoAtual = arquivosPC[arquivoAtual];
        utilizado += tamanhoAtual;
        arquivosPendrive[arquivoAtual] = tamanhoAtual;
        arquivoAtual++;
    }

    *qtdArquivosPendrive = arquivoAtual;
}

int main()
{
    float arquivosPC[] = {100, 2, 3};
    int qtdArquivosPC = sizeof(arquivosPC) / sizeof(arquivosPC[0]);
    float arquivosPendrive[50] = {0};
    int qtdArquivosPendrive = 0;
    float capacidadePendrive = 10;

    arquivosPCPendrive(arquivosPC, qtdArquivosPC, arquivosPendrive, &qtdArquivosPendrive, capacidadePendrive);
    if (qtdArquivosPendrive == 0)
    {
        printf("Nenhum arquivo coube.\n");
    }
    else
    {
        printFloatArray(arquivosPendrive, qtdArquivosPendrive);
    }

    return 0;
}