typedef struct atvds
{
    int inicio;
    int fim;
} atividade;

void ordenarPorFim(atividade atividades[], int qtdAtividades)
{
    atividade temp;

    for (int i = 0; i < qtdAtividades; i++)
    {
        for (int j = 1; j < qtdAtividades - i; j++)
        {
            if (atividades[j].fim < atividades[j - 1].fim)
            {
                temp = atividades[j - 1];
                atividades[j - 1] = atividades[j];
                atividades[j] = temp;
            }
        }
    }
}

int selecaoAtividades(atividade atividades[], int qtdAtividades, atividade solucao[])
{
    ordenarPorFim(atividades, qtdAtividades);

    solucao[0] = atividades[0];
    int qtdSolucao = 1;

    for (int i = 1; i < qtdAtividades; i++)
    {
        if (atividades[i].inicio > solucao[qtdSolucao - 1].fim)
        {
            solucao[qtdSolucao] = atividades[i];
            qtdSolucao++;
        }
    }

    return qtdSolucao;
}