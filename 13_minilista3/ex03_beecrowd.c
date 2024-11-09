/*
3. (BEECROWD 2463) Bruninho tem que entrar em um corredor, percorrer algumas salas e
depois sair do corredor. Ele pode entrar apenas uma vez, e passar por cada sala apenas
uma vez. Ao passar por uma sala ele ganha um certo número de vidas (que pode ser
negativo!). O objetivo é passar pelo corredor coletando a maior quantidade possível de
vidas.

a)
   1   2   3   4   5   6   7
[ -2   5  -1   8 -11   7   3 ]


b)
       |
       v
   1   2   3   4    5   6   7
[ -2   5  -1   8  -11   7   3 ]
        ------->
[ -2   5  -1   8  -11   7   3 ]
               |
               v

No exemplo acima, o personagem de Bruninho pode ganhar, no máximo, 12 vidas, por
exemplo, entrando pela sala 2 e saindo pela sala 4, como mostrado na parte (b) da fi-
gura. Nesta tarefa, você deve escrever um programa que, dados os números de vidas
correspondentes a cada sala do corredor, calcule a quantidade máxima de vidas que será
possível ganhar.
Entrada
7
-2 5 -1 8 -11 7 3

Saída
12
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// OBS: varição da sublista contínua de elementos que produz a soma máxima

#include <stdio.h>

int maximoVidas(int vidas[], int n)
{
   int maxSomaAtual = vidas[0]; // Armazena a soma máxima que estamos calculando
   int maxSomaTotal = vidas[0]; // Armazena a maior soma encontrada até agora

   // Itera sobre as salas a partir da segunda
   for (int i = 1; i < n; i++)
   {
      // Calcula a soma máxima até a sala atual
      // ou reinicia com o valor atual se for maior
      if (maxSomaAtual + vidas[i] > vidas[i])
      {
         maxSomaAtual += vidas[i];
      }
      else
      {
         maxSomaAtual = vidas[i];
      }

      // Atualiza a maior soma total se a soma atual for maior
      if (maxSomaAtual > maxSomaTotal)
      {
         maxSomaTotal = maxSomaAtual;
      }
   }

   return maxSomaTotal;
}

int main()
{
   int n;

   // Lê o número de salas
   printf("Digite o número de salas: ");
   scanf("%d", &n);

   int vidas[n];

   // Lê as vidas em cada sala
   printf("Digite as vidas para cada sala:\n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &vidas[i]);
   }

   // Calcula e imprime a quantidade máxima de vidas que podem ser ganhas
   int resultado = maximoVidas(vidas, n);
   printf("Máximo de vidas possíveis: %d\n", resultado);

   return 0;
}