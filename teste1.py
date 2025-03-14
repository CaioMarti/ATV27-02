def escrever_no_arquivo(nome_arquivo, *parametros):
    with open(nome_arquivo, "w") as arquivo:
        for parametro in parametros:
            arquivo.write(str(parametro) + "\n")
    print(f"Parâmetros escritos em '{nome_arquivo}' com sucesso!")


nome_arquivo = input("Digite o nome do arquivo: ")
parametros = input("Digite os parâmetros separados por espaço: ").split()

escrever_no_arquivo(nome_arquivo,*parametros)