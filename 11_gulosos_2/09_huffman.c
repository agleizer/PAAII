/*
9) Implemente na linguagem C o algoritmo de Huffman apresentando, considere
que o algoritmo tem como entrada uma lista de caracteres e com suas
frequências e como saída a árvore binária de Huffman.
*/

#include <stdio.h>
#include <stdlib.h>

// Definir o nó da árvore de Huffman usando typedef
typedef struct HuffmanNode
{
    char caractere;                         // Caractere armazenado (para folhas)
    int frequencia;                         // Frequência do caractere ou somatório de frequências
    struct HuffmanNode *esquerda, *direita; // Ponteiros para os filhos (esquerda e direita)
} HuffmanNode;

// Função para criar um novo nó da árvore de Huffman
// Este nó pode ser uma folha (com caractere) ou um nó interno (sem caractere)
HuffmanNode *criarNo(char caractere, int frequencia)
{
    HuffmanNode *novoNo = (HuffmanNode *)malloc(sizeof(HuffmanNode)); // Aloca espaço para o nó
    novoNo->caractere = caractere;                                    // Atribui o caractere
    novoNo->frequencia = frequencia;                                  // Atribui a frequência
    novoNo->esquerda = novoNo->direita = NULL;                        // Inicializa os filhos como NULL (não conectados ainda)
    return novoNo;                                                    // Retorna o novo nó criado
}

// Estrutura para uma fila de prioridade (min-heap)
// A fila será usada para encontrar os dois menores nós a cada etapa
typedef struct MinHeap
{
    int tamanho;         // Número de elementos atuais na heap
    int capacidade;      // Capacidade máxima da heap
    HuffmanNode **array; // Array de ponteiros para nós de Huffman
} MinHeap;

// Função para criar a fila de prioridade (min-heap) com uma capacidade especificada
MinHeap *criarMinHeap(int capacidade)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));                                // Aloca a estrutura da heap
    minHeap->tamanho = 0;                                                                 // Inicialmente, a heap está vazia
    minHeap->capacidade = capacidade;                                                     // Define a capacidade máxima da heap
    minHeap->array = (HuffmanNode **)malloc(minHeap->capacidade * sizeof(HuffmanNode *)); // Aloca o array de nós
    return minHeap;                                                                       // Retorna a heap criada
}

// Função para trocar dois nós dentro da fila de prioridade (usado para reorganizar a heap)
void trocarNo(HuffmanNode **a, HuffmanNode **b)
{
    HuffmanNode *temp = *a; // Salva o nó temporariamente
    *a = *b;                // Troca o primeiro nó com o segundo
    *b = temp;              // Completa a troca
}

// Função para reajustar a fila de prioridade (min-heap) após inserção ou remoção
void heapify(MinHeap *minHeap, int idx)
{
    int menor = idx;            // Inicialmente, o menor é o índice passado
    int esquerda = 2 * idx + 1; // Calcula o índice do filho esquerdo
    int direita = 2 * idx + 2;  // Calcula o índice do filho direito

    // Verifica se o filho esquerdo é menor que o nó atual
    if (esquerda < minHeap->tamanho && minHeap->array[esquerda]->frequencia < minHeap->array[menor]->frequencia)
        menor = esquerda;

    // Verifica se o filho direito é menor que o nó menor até agora
    if (direita < minHeap->tamanho && minHeap->array[direita]->frequencia < minHeap->array[menor]->frequencia)
        menor = direita;

    // Se o nó atual não é o menor, trocamos e continuamos o heapify
    if (menor != idx)
    {
        trocarNo(&minHeap->array[menor], &minHeap->array[idx]);
        heapify(minHeap, menor); // Recursivamente chama heapify no nó afetado
    }
}

// Função para extrair o nó de menor frequência da fila de prioridade (min-heap)
HuffmanNode *extrairMin(MinHeap *minHeap)
{
    HuffmanNode *temp = minHeap->array[0];                    // O nó com menor frequência está no topo (índice 0)
    minHeap->array[0] = minHeap->array[minHeap->tamanho - 1]; // Substitui pelo último nó da heap
    --minHeap->tamanho;                                       // Reduz o tamanho da heap
    heapify(minHeap, 0);                                      // Reorganiza a heap para manter a propriedade de min-heap
    return temp;                                              // Retorna o nó de menor frequência
}

// Função para inserir um novo nó na fila de prioridade (min-heap)
void inserirMinHeap(MinHeap *minHeap, HuffmanNode *no)
{
    ++minHeap->tamanho;           // Aumenta o tamanho da heap
    int i = minHeap->tamanho - 1; // Índice do novo nó inserido

    // Move o novo nó para sua posição correta (subindo na heap se necessário)
    while (i && no->frequencia < minHeap->array[(i - 1) / 2]->frequencia)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; // Move o nó pai para baixo
        i = (i - 1) / 2;                                 // Sobe para o próximo nível
    }
    minHeap->array[i] = no; // Insere o novo nó na posição correta
}

// Função para construir a fila de prioridade inicial com os nós folha
MinHeap *construirMinHeap(char caracteres[], int frequencias[], int tamanho)
{
    MinHeap *minHeap = criarMinHeap(tamanho); // Cria a fila de prioridade com a capacidade do número de caracteres
    for (int i = 0; i < tamanho; ++i)
        minHeap->array[i] = criarNo(caracteres[i], frequencias[i]); // Adiciona cada caractere e frequência à heap
    minHeap->tamanho = tamanho;                                     // Define o tamanho da heap
    for (int i = (minHeap->tamanho - 1) / 2; i >= 0; --i)
        heapify(minHeap, i); // Reorganiza a heap para garantir a propriedade de min-heap
    return minHeap;          // Retorna a heap construída
}

// Função para construir a árvore de Huffman
HuffmanNode *construirHuffmanTree(char caracteres[], int frequencias[], int tamanho)
{
    HuffmanNode *esquerda, *direita, *topo;

    // Passo 1: Construir uma fila de prioridade (min-heap)
    MinHeap *minHeap = construirMinHeap(caracteres, frequencias, tamanho);

    // Passo 2: Iterar até restar apenas um nó na fila de prioridade
    while (minHeap->tamanho != 1)
    {
        // Extrair os dois nós com as menores frequências
        esquerda = extrairMin(minHeap);
        direita = extrairMin(minHeap);

        // Criar um novo nó interno com a soma das frequências dos dois nós
        topo = criarNo('$', esquerda->frequencia + direita->frequencia);
        topo->esquerda = esquerda; // Atribui o nó da esquerda
        topo->direita = direita;   // Atribui o nó da direita

        // Inserir o novo nó na fila de prioridade
        inserirMinHeap(minHeap, topo);
    }

    // O nó restante é a raiz da árvore de Huffman
    return extrairMin(minHeap);
}

// Função para imprimir os códigos de Huffman (esquerda = 0, direita = 1)
void imprimirCodigos(HuffmanNode *raiz, int arr[], int topo)
{
    // Se existir um filho à esquerda, adicionamos 0 e continuamos
    if (raiz->esquerda)
    {
        arr[topo] = 0;
        imprimirCodigos(raiz->esquerda, arr, topo + 1);
    }

    // Se existir um filho à direita, adicionamos 1 e continuamos
    if (raiz->direita)
    {
        arr[topo] = 1;
        imprimirCodigos(raiz->direita, arr, topo + 1);
    }

    // Se o nó atual for uma folha (não tem filhos), imprimimos o caractere e seu código
    if (!(raiz->esquerda) && !(raiz->direita))
    {
        printf("%c: ", raiz->caractere); // Imprime o caractere
        for (int i = 0; i < topo; ++i)
            printf("%d", arr[i]); // Imprime o código de Huffman (sequência de 0s e 1s)
        printf("\n");
    }
}

// Função principal para construir a árvore de Huffman e imprimir os códigos
void huffman(char caracteres[], int frequencias[], int tamanho)
{
    // Construir a árvore de Huffman
    HuffmanNode *raiz = construirHuffmanTree(caracteres, frequencias, tamanho);

    // Array temporário para armazenar os códigos
    int arr[100], topo = 0;

    // Imprimir os códigos de Huffman
    imprimirCodigos(raiz, arr, topo);
}

int main()
{
    char caracteres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int frequencias[] = {7, 5, 10, 21, 90, 11, 7, 2};
    int tamanho = sizeof(caracteres) / sizeof(caracteres[0]);

    // Gerar e imprimir a árvore de Huffman e os códigos
    huffman(caracteres, frequencias, tamanho);

    return 0;
}