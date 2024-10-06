/*
3. Suponha que você esteja dirigindo de São Paulo para Curitiba e que, com o tanque cheio,
seu carro consegue andar m quilômetros. Suponha também que você sabe que existem n
postos de combustível na estrada e que a distância deles para a saída de São Paulo seja
d1 < d2 < · · · < dn. Finalmente, assuma que a distância entre dois postos vizinhos seja
de, no máximo, m quilômetros e que você esteja saindo da cidade de tanque cheio. Dadas
essas suposições, determine o menor número de paradas nos postos de combustível que
te permitam chegar ao destino final.
*/

#include <stdio.h>

void printIntArray(int arr[], int size)
{
    // Loop through each element in the array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // Print each element with 2 decimal places
    }
    printf("\n"); // Print a newline at the end
}

// @param postosGasolina[] armazena a distância de cada posto DO PONTO DE ORIGEM e estará ordenado em função dessa distância
// @return a quantidade de paradas
void paradasPostosGasolina(int postosGasolina[], int qtdPostos, int capacidadeTanque, int paradas[], int *qtdParadas)
{
    int ultimaParada = 0;

    for (int i = 1; i < qtdPostos; i++)
    {
        if (postosGasolina[i] - ultimaParada > capacidadeTanque)
        {
            ultimaParada = postosGasolina[i - 1];
            paradas[*qtdParadas] = i - 1;
            (*qtdParadas)++;
        }
    }
}

int main()
{
    int postosGasolina[] = {25, 45, 90, 120, 125, 150};
    int qtdPostos = sizeof(postosGasolina) / sizeof(int);
    int capacidade = 50;
    int paradas[50] = {0};
    int qtdParadas = 0;

    paradasPostosGasolina(postosGasolina, qtdPostos, capacidade, paradas, &qtdParadas);

    printIntArray(paradas, qtdParadas);
    return 0;
}