tabela = [
    [1,  2, -1,  3],
    [0,  4, -1, -1],
    [-1, -1, 5, -1],
    [-1, -1, -1, 6],
    [-1, -1, 7, -1],
    [-1, 8, -1, -1],
    [-1, -1, -1, 3],
    [-1, 9, -1, 6],
    [-1, -1, 10, -1],
    [-1, -1, 11, -1],
    [-1, 2, -1, 3],
    [-1, 4, -1, -1]
]

EF = [
    0, 0, 0, 1,
    0, 0, 0, 1,
    0, 0, 0, 0
]


def analisar_entrada(entrada):
    resultados = []

    saida = ""
    primeiroValido = False
    invalida = False
    estado = 0

    for simbolo in entrada:

        if simbolo == '$':
            break

        if (
            simbolo == ' ' or
            simbolo == '\n' or
            simbolo == '\t' or
            simbolo == '\r' or
            simbolo == '\v' or
            simbolo == '\f'
        ):
            if saida != "":
                if not primeiroValido:
                    resultados.append(
                        "ERRO: símbolo(s) inválido(s): " + saida
                    )
                elif invalida:
                    resultados.append(
                        "ERRO: sentença inválida: " + saida
                    )
                elif EF[estado] == 1:
                    resultados.append(
                        "sentença válida: " + saida
                    )
                else:
                    resultados.append(
                        "ERRO: sentença inválida: " + saida
                    )

                saida = ""

            estado = 0
            primeiroValido = False
            invalida = False

        elif (
            simbolo == '+' or
            simbolo == '-' or
            simbolo == '*' or
            simbolo == '/'
        ):
            if saida != "":
                if not primeiroValido:
                    resultados.append(
                        "ERRO: símbolo(s) inválido(s): " + saida
                    )
                elif invalida:
                    resultados.append(
                        "ERRO: sentença inválida: " + saida
                    )
                elif EF[estado] == 1:
                    resultados.append(
                        "sentença válida: " + saida
                    )
                else:
                    resultados.append(
                        "ERRO: sentença inválida: " + saida
                    )

                saida = ""

            estado = 0
            primeiroValido = False
            invalida = False

            resultados.append(
                "operador aritmético: " + simbolo
            )

        elif (
            simbolo == 'a' or
            simbolo == 'b' or
            simbolo == 'c' or
            simbolo == 'd'
        ):
            if saida == "":
                primeiroValido = True

            if not invalida:
                if simbolo == 'a':
                    estado = tabela[estado][0]
                elif simbolo == 'b':
                    estado = tabela[estado][1]
                elif simbolo == 'c':
                    estado = tabela[estado][2]
                elif simbolo == 'd':
                    estado = tabela[estado][3]

                if estado == -1:
                    invalida = True

            saida += simbolo

        else:
            if saida == "":
                primeiroValido = False
            else:
                invalida = True

            saida += simbolo

    if saida != "":
        if not primeiroValido:
            resultados.append(
                "ERRO: símbolo(s) inválido(s): " + saida
            )
        elif invalida:
            resultados.append(
                "ERRO: sentença inválida: " + saida
            )
        elif EF[estado] == 1:
            resultados.append(
                "sentença válida: " + saida
            )
        else:
            resultados.append(
                "ERRO: sentença inválida: " + saida
            )

    return resultados