const tabela = [
    //         a   b   c   d
    /* q0 */ [  1,  2, -1,  3 ],
    /* q1 */ [  0,  4, -1, -1 ],
    /* q2 */ [ -1, -1,  5, -1 ],
    /* q3 */ [ -1, -1, -1,  6 ],
    /* q4 */ [ -1, -1,  7, -1 ],
    /* q5 */ [ -1,  8, -1, -1 ],
    /* q6 */ [ -1, -1, -1,  3 ],
    /* q7 */ [ -1,  9, -1,  6 ],
    /* q8 */ [ -1, -1, 10, -1 ],
    /* q9 */ [ -1, -1, 11, -1 ],
    /* q10*/ [ -1,  2, -1,  3 ],
    /* q11*/ [ -1,  4, -1, -1 ]
];


const EF = [
    0,  // q0
    0,  // q1
    0,  // q2
    1,  // q3
    0,  // q4
    0,  // q5
    0,  // q6
    1,  // q7
    0,  // q8
    0,  // q9
    0,  // q10
    0   // q11
];


function analisar()
{
    const entrada =
        document.getElementById("campoA").value;

    const campoB =
        document.getElementById("campoB");


    let saida = "";

    let primeiroValido = false;
    let invalida = false;

    let estado = 0;


    for (let i = 0; i < entrada.length; i++)
    {
        let simbolo = entrada[i];


        if (simbolo === '$')
        {
            break;
        }


        if (
            simbolo === ' '  ||
            simbolo === '\n' ||
            simbolo === '\t' ||
            simbolo === '\r' ||
            simbolo === '\v' ||
            simbolo === '\f'
        )
        {
            if (saida.length > 0)
            {
                if (!primeiroValido)
                {
                    campoB.value +=
                        "ERRO: símbolo(s) inválido(s): "
                        + saida + "\n";
                }

                else if (invalida)
                {
                    campoB.value +=
                        "ERRO: sentença inválida: "
                        + saida + "\n";
                }

                else if (EF[estado] === 1)
                {
                    campoB.value +=
                        "sentença válida: "
                        + saida + "\n";
                }

                else
                {
                    campoB.value +=
                        "ERRO: sentença inválida: "
                        + saida + "\n";
                }

                saida = "";
            }

            estado = 0;
            primeiroValido = false;
            invalida = false;
        }


        else if (
            simbolo === '+' ||
            simbolo === '-' ||
            simbolo === '*' ||
            simbolo === '/'
        )
        {
            if (saida.length > 0)
            {
                if (!primeiroValido)
                {
                    campoB.value +=
                        "ERRO: símbolo(s) inválido(s): "
                        + saida + "\n";
                }

                else if (invalida)
                {
                    campoB.value +=
                        "ERRO: sentença inválida: "
                        + saida + "\n";
                }

                else if (EF[estado] === 1)
                {
                    campoB.value +=
                        "sentença válida: "
                        + saida + "\n";
                }

                else
                {
                    campoB.value +=
                        "ERRO: sentença inválida: "
                        + saida + "\n";
                }

                saida = "";
            }

            estado = 0;
            primeiroValido = false;
            invalida = false;


            campoB.value +=
                "operador aritmético: "
                + simbolo + "\n";
        }


        else if (
            simbolo === 'a' ||
            simbolo === 'b' ||
            simbolo === 'c' ||
            simbolo === 'd'
        )
        {
            if (saida.length === 0)
            {
                primeiroValido = true;
            }


            if (!invalida)
            {
                if (simbolo === 'a')
                    estado = tabela[estado][0];

                else if (simbolo === 'b')
                    estado = tabela[estado][1];

                else if (simbolo === 'c')
                    estado = tabela[estado][2];

                else if (simbolo === 'd')
                    estado = tabela[estado][3];


                if (estado === -1)
                {
                    invalida = true;
                }
            }


            saida += simbolo;
        }


        else
        {
            if (saida.length === 0)
            {
                primeiroValido = false;
            }

            else
            {
                invalida = true;
            }


            saida += simbolo;
        }
    }


    if (saida.length > 0)
    {
        if (!primeiroValido)
        {
            campoB.value +=
                "ERRO: símbolo(s) inválido(s): "
                + saida + "\n";
        }

        else if (invalida)
        {
            campoB.value +=
                "ERRO: sentença inválida: "
                + saida + "\n";
        }

        else if (EF[estado] === 1)
        {
            campoB.value +=
                "sentença válida: "
                + saida + "\n";
        }

        else
        {
            campoB.value +=
                "ERRO: sentença inválida: "
                + saida + "\n";
        }
    }


    campoB.scrollTop = campoB.scrollHeight;
}


function limpar()
{
    document.getElementById("campoA").value = "";

    document.getElementById("campoB").value = "";

    document.getElementById("campoA").focus();
}