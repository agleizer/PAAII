/*

*/

#include <stdio.h>
#define MAX 100

// funcao calcula o num-ésimo elemento na sequencia de fibonacci
// abordagem de programação dinâmica SEM recursão
int fibonacciDinIt(int num)
{
    int fib[num + 1]; // vetor para armazenar os resultados já calculados

    // popular o vetor com -1 para sabermos quem já foi calculado
    // esse passo não é necessário na solução iterativa, pois não fazemos checagem
    for (int i = 0; i < num; i++)
        fib[i] = -1;

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= num; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[num];
}

// funcao calcula o num-ésimo elemento na sequencia de fibonacci
// abordagem de programação dinâmica COM recursão
int fibonacciDinRec(int num, int fib[])
{
    // caso base
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    fib[0] = 0;
    fib[1] = 1;

    if (fib[num] != -1)
        return fib[num];
    else
        fib[num] = fibonacciDinRec(num - 1, fib) + fibonacciDinRec(num - 2, fib);

    return fib[num];
}

int main()
{
    // para versao recursiva
    int fib[MAX];
    for (int i = 0; i < MAX; i++)
        fib[i] = -1;
}