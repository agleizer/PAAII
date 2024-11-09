/*
2. (RESTAURANTE) Um restaurante recebe n (n ≤ 105) pedidos de reserva. Cada pedido
ocupa o restaurante por um período contíguo de li até ri, por exemplo, das 9 às 10 horas.
Com a restrição de que duas reservas não podem ter interseção, qual o maior número de
pedidos que podemos aceitar?
Entrada:
5
1 2
2 3
3 4
4 5
5 6
Saída : 3
*/

#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

typedef struct
{
    int inicio;
    int fim;
} Reserva;

// Função para ordenar as reservas pelo horário de término usando Selection Sort
void ordenarPorFim(Reserva reservas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (reservas[j].fim < reservas[minIndex].fim)
            {
                minIndex = j;
            }
        }
        // Troca a reserva atual com a reserva de menor término encontrado
        Reserva temp = reservas[i];
        reservas[i] = reservas[minIndex];
        reservas[minIndex] = temp;
    }
}

// Função gulosa para selecionar o maior número de reservas compatíveis
int selecionaAtividades(Reserva reservas[], int n)
{
    // Ordena as reservas pelo horário de término
    ordenarPorFim(reservas, n);

    int totalReservas = 1; // Começa com a primeira reserva (A ← {1})
    int j = 0;             // Última reserva aceita, começa com a primeira

    // Itera sobre as reservas a partir da segunda
    for (int i = 1; i < n; i++)
    {
        // Verifica se a reserva atual é compatível com a última aceita
        // Ela só é compatível se seu início for > fim da última aceita
        if (reservas[i].inicio > reservas[j].fim)
        {
            totalReservas++; // Inclui a reserva atual
            j = i;           // Atualiza a última reserva aceita para a atual
        }
    }

    return totalReservas; // Retorna o número máximo de reservas aceitas
}

int main()
{
    int n;

    // Lê o número de pedidos de reserva
    printf("Digite o número de reservas: ");
    scanf("%d", &n);

    // Declara um array para armazenar as reservas
    Reserva reservas[n];

    // Lê os horários de cada reserva
    printf("Digite o horário de início e fim de cada reserva:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &reservas[i].inicio, &reservas[i].fim);
    }

    // Calcula e imprime o número máximo de reservas que podem ser aceitas
    int resultado = selecionaAtividades(reservas, n);
    printf("Máximo de reservas que podem ser aceitas: %d\n", resultado);

    return 0;
}
