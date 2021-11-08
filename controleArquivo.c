#include "Headers/controleArquivo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define ERROR_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"
#define ERRO_ABRIR_ARQUIVO "\n\tERRO: Erro na abertura do arquivo!\n"

#define MENSSAGE_LENDO_ARQUIVO "\n\tAVISO: Lendo arquivo, por favor aguarde...\n"
#define DIRETORIO_ARQUIVO_ENTRADA "../entrada/aleatorio300000.txt"
#define DIRETORIO_ARQUIVO_SAIDA "./saida/"
#define LINE_MAX_LENGTH 255
#define FILE_NAME_MAX_LENGTH 31
#define DELIMITER ";"

// =-=-=-=-= METODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

aluno *readNextAluno(FILE *fp);

void writeAlunosOnFile(FILE *fp, biTree * root);

// =-=-=-=-= METODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

aluno *readNextAluno(FILE *fp)
{
    aluno *aluno = allocStudant();
    char *line = (char *)malloc((LINE_MAX_LENGTH + 1) * sizeof(char));
    char *ptr;

    fscanf(fp, " %[^\n]%*c", line);
    ptr = strtok(line, DELIMITER);
    aluno->matricula = (int)atof(ptr);

    ptr = strtok(NULL, DELIMITER);
    strcpy(aluno->nome, ptr);

    ptr = strtok(NULL, DELIMITER);
    aluno->nota = (int)atof(ptr);

    free(line);

    return aluno;
}

void writeAlunosOnFile(FILE *fp, biTree * root)
{
    aluno *a;
    for (int index = 0; index < root->height; ++index)
    {
        if (root->height == 1)
        {
            a = root->root->element;
            fprintf(fp, "%d;%d;%s;%d\n", index, a->matricula, a->nome, a->nota);
        }
    }
}

// =-=-=-=-= METODOS PUBLICOS =-=-=-=-=

biTree *readTreeAlunoFromFile(biTree * tree)
{
    FILE *fp = fopen(DIRETORIO_ARQUIVO_ENTRADA, "r");
    int contador = 0;
    int registros;

    if (!fp)
    {
        printf(ERRO_ABRIR_ARQUIVO);
        return NULL;
    }

    printf(MENSSAGE_LENDO_ARQUIVO);
    fscanf(fp, "%d", &registros);
    while (!feof(fp) && contador < registros)
    {
        aluno * a = readNextAluno(fp);
        tree = insertStudant(tree, a);
        contador++;
    }
    fclose(fp);
    return tree;
}

void writeTreeOnFile(biTree * root)
{
    int nomeArquivoSaidaLength = strlen(DIRETORIO_ARQUIVO_SAIDA) + FILE_NAME_MAX_LENGTH + 1;
    char *nomeArquivoSaida = (char *)malloc(nomeArquivoSaidaLength * sizeof(char));
    FILE *fp;

    sprintf(nomeArquivoSaida, "%ssaida-%d.txt", DIRETORIO_ARQUIVO_SAIDA, root->height);
    fp = fopen(nomeArquivoSaida, "w");
    if (!fp)
    {
        printf(ERRO_ABRIR_ARQUIVO);
        return;
    }

    writeAlunosOnFile(fp, root);

    fclose(fp);
}
