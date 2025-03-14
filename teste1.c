#include <stdio.h>

void escrever_no_arquivo(const char *nome_arquivo, int argc, char *argv[]) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 2; i < argc; i++) {
        fprintf(arquivo, "%s\n", argv[i]);
    }

    fclose(arquivo);
    printf("Parâmetros escritos em '%s' com sucesso!\n", nome_arquivo);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <nome_arquivo> <parametro1> <parametro2> ...\n", argv[0]);
        return 1;
    }

    escrever_no_arquivo(argv[1], argc, argv);
    return 0;
}