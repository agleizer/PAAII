#include <stdio.h>
#include <string.h>

void printFloatArray(float arr[], int size)
{
  // Loop through each element in the array
  for (int i = 0; i < size; i++)
  {
    printf("%.2f ", arr[i]); // Print each element with 2 decimal places
  }
  printf("\n"); // Print a newline at the end
}

void menorNumNotasMoedas(float disponiveis[], float solucao[], int *tamSolucao, float valor)
{
  float soma = 0;

  if (valor <= 0)
  {
    printf("Valor inválido.\n");
    return;
  }

  int i = 0;
  while (soma < valor)
  {
    float notaAtual = disponiveis[i];
    if (soma + notaAtual <= valor)
    {
      soma += notaAtual;
      solucao[(*tamSolucao)++] = notaAtual;
    }
    else
    {
      i++;
    }
  }
}

void formatarResposta(float vetor[], int tamanho)
{
  int quantidade = 1;
  for (int i = 0; i < tamanho; i++)
  {
    float valorAtual = vetor[i];

    // definir se é nota ou moeda
    const char *grandeza = (valorAtual > 1) ? "nota" : "moeda";

    // determinar quantidade
    if (i == tamanho - 1 || valorAtual != vetor[i + 1])
    { // para não tentarmos acessar indice inválido
      printf("%d", quantidade);
      quantidade = 1;
      printf(" %s(s) de R$ ", grandeza);
      printf("%.2f\n", vetor[i]);
    }
    else
    {
      quantidade++;
    }
  }
}

int main()
{
  float notasMoedasDisponiveis[] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.10, 0.05, 0.01};
  float solucao[50] = {0};
  int tamSolucao = 0;
  float valor = 576.73;

  menorNumNotasMoedas(notasMoedasDisponiveis, solucao, &tamSolucao, valor);

  printFloatArray(solucao, tamSolucao);
  formatarResposta(solucao, tamSolucao);
}