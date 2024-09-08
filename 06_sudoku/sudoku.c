/*
Escreva um programa em linguagem C, que resolva o sudoku
simples. Suponha que a tabela do sudoku já tenha algumas
posições preenchidas.
Como a tabela utilizada no exemplo:
*/

#include <stdio.h>
#include <stdlib.h>

// Prints a two-dimensional array
void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);  // Print each element of the row
        }
        printf("|\n");  // Newline after printing each row
    }
    printf("\n");
}


// retorna 0 se o numeroTeste já aparece na linha, 1 se não aparece
int validaNumLinha(int** v, int tam, int linha, int numeroTeste) {
    for (int i = 0; i < tam; i++) {
        if (numeroTeste == v[linha][i]) return 0;
    }
    return 1;
}
// retorna 0 se o numeroTeste já aparece na coluna, 1 se não aparece
int validaNumColuna(int** v, int tam, int coluna, int numeroTeste) {
    for (int i = 0; i < tam; i++) {
        if (numeroTeste == v[i][coluna]) return 0;
    }
    return 1;
}

int validaNumCelula(int** v, int tam, int linha, int coluna, int numeroTeste) {
    print2DArray(v, tam, tam);
    int validacao = validaNumLinha(v, tam, linha, numeroTeste) && validaNumColuna(v, tam, coluna, numeroTeste);
    if (validacao) printf("Válido!\n");
    else printf("Inválido!\n");
    return validacao;
}

void zeraVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        v[i] = 0;
    }
}

// verifica se um sudoku está corretamente preenchido, retorna 1 se sim, 0 se não
// sudoku precisa ser quadrado...

// acabei a fuunção mas.. para backtracking, talvez seja mais interessante alterar os parametros para que a função receba um numero e verifique se,
// até o indice que está sendo trabalhado, o numero é valido dou não. 
int sudokuValido(int** v, int tam) {
    int validacao = 1;
    int valida[tam+1];

    // checar as linhas
    for (int linha = 0; linha < tam; linha++) {
        zeraVetor(valida, tam+1);
        for (int coluna = 0; coluna < tam; coluna++) {
            int atual = v[linha][coluna];
            if (atual < 1 || atual > tam || valida[atual] == 1) return 0;
            valida[atual] = 1;
        }
    }

    // checar as colunas
    for (int coluna = 0; coluna < tam; coluna++) {
        zeraVetor(valida, tam+1);
        for (int linha = 0; linha < tam; linha++) {
            int atual = v[linha][coluna];
            if (atual < 1 || atual > tam || valida[atual] == 1) return 0;
            valida[atual] = 1;
        }
    }    

    return validacao;
}

// tentativa um
/*
int resolverSudoku(int** v, int tamV, int linha, int coluna, int opcoes[], int tamOpcoes) {
    //printf("chamada de mostraSeq com i = %d\n", i);
    if (sudokuValido(v, tamV)) {
        print2DArray(v, tamV, tamV);
    }
    else {
        for (int i = 0; i < tamV; i++) {
            for (int j = 0; j < tamV; j++){
                if (validaNumLinha(v, tamV, i, opcoes[j]) && validaNumColuna(v, tamV, j, opcoes[j]) && v[i][j] == 0) {
                    resolverSudoku(v, tamV, i, j, opcoes, tamOpcoes);
                }
            }
        }
    }
}
*/


// Backtracking solver function
int resolverSudoku(int** v, int tam, int linha, int coluna) {
    // se chegamos no tamanho, então completamos a linha
    if (linha == tam) {
        // print2DArray(v, tam, tam);
        return 1; // e podemos passar para a próxima
    }

    if (v[linha][coluna] != 0) {
        // se o valor não for zero, a célula iniciou com valor e não pode ser alterada
        if (coluna == tam - 1) {
            // se a célula fixa está na última posição, vamos para a próxima linha
            if (resolverSudoku(v, tam, linha + 1, 0)) return 1;
        } else {
            // se não, vamos para a próxima ocluna da linha
            if (resolverSudoku(v, tam, linha, coluna + 1)) return 1;
        }
        return 0; // backtrack
    }

    // testar todos os números de 1 a tamanho
    for (int num = 1; num <= tam; num++) {
        if (validaNumCelula(v, tam, linha, coluna, num)) {
            v[linha][coluna] = num;
            //print2DArray(v, tam, tam);
            if (resolverSudoku(v, tam, linha, coluna)) return 1;
            v[linha][coluna] = 0; // backtrack
            printf("backtrack...\n");
            //print2DArray(v, tam, tam);
        }
    }

    return 0; // nenhum numero válido foi encontrado
}

int main() {
    //int** sudoku = (int**) malloc(4*sizeof(int));

    int rows = 4;
    int cols = 4;

    int** sudoku = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        sudoku[i] = (int*) malloc(cols * sizeof(int));
    }
    
    int initial_values[4][4] = {
        {0, 2, 4, 0},
        {1, 0, 0, 3},
        {4, 0, 0, 2},
        {0, 1, 3, 0}
    };
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sudoku[i][j] = initial_values[i][j];
        }
    }
    
                       
    int v[] = {1,2,3,4};
    int s[] = {}; // 99 só p ter ctz que o codespaces estava limpando a memoria
    //resolverSudoku(sudoku, 4, 0, 0, v, 4);

    // Solve the Sudoku
    if (resolverSudoku(sudoku, rows, 0, 0)) {
        printf("Sudoku solved successfully!\n");
        print2DArray(sudoku, rows, cols);
    } else {
        printf("No solution exists.\n");
    }

    for (int i = 0; i < rows; i++) {
        free(sudoku[i]);
    }
    free(sudoku);

}