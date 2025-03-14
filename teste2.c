#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_config(const char *arquivo_config) {
    FILE *arquivo = fopen(arquivo_config, "r");
    if (arquivo == NULL) {
        printf("Erro: O arquivo '%s' não foi encontrado.\n", arquivo_config);
        exit(1);
    }

    int num_esperado = -1;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "num=", 4) == 0) {
            num_esperado = atoi(linha + 4);
            break;
        }
    }

    fclose(arquivo);

    if (num_esperado == -1) {
        printf("Erro: O arquivo de configuração não contém um valor válido para 'num'.\n");
        exit(1);
    }

    return num_esperado;
}

int main(int argc, char *argv[]) {
    int num_esperado = ler_config("config.txt");

    if (argc - 1 != num_esperado) {
        printf("Erro: Esperado %d parâmetros, mas recebeu %d.\n", num_esperado, argc - 1);
        return 1;
    }

    printf("Parâmetros recebidos corretamente: ");
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}