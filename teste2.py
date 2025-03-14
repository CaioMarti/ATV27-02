import sys

def ler_config(arquivo_config):
    try:
        with open(arquivo_config, "r") as arquivo:
            for linha in arquivo:
                if linha.startswith("num="):
                    return int(linha.strip().split("=")[1])
    except FileNotFoundError:
        print(f"Erro: O arquivo '{arquivo_config}' não foi encontrado.")
        sys.exit(1)
    except ValueError:
        print("Erro: O valor de 'num' no arquivo de configuração não é válido.")
        sys.exit(1)

def main():
    num_esperado = ler_config("config.txt")
    parametros = sys.argv[1:]  

    if len(parametros) != num_esperado:
        print(f"Erro: Esperado {num_esperado} parâmetros, mas recebeu {len(parametros)}.")
        sys.exit(1)

    print(f"Parâmetros recebidos corretamente: {parametros}")

if __name__ == "_main_":
    main()