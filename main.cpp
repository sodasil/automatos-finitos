#include <iostream>
#include <string>

using namespace std;

int main()
{
    char simbolo;
    int estado;
    int tabela[12][4] =
    {
        //         a   b   c   d
        /*q0*/  {  1,  2, -1,  3 },
        /*q1*/  {  0,  4, -1, -1 },
        /*q2*/  { -1, -1,  5, -1 },
        /*q3*/  { -1, -1, -1,  6 },
        /*q4*/  { -1, -1,  7, -1 },
        /*q5*/  { -1,  8, -1, -1 },
        /*q6*/  { -1, -1, -1,  3 },
        /*q7*/  { -1,  9, -1,  6 },
        /*q8*/  { -1, -1, 10, -1 },
        /*q9*/  { -1, -1, 11, -1 },
        /*q10*/ { -1,  2, -1,  3 },
        /*q11*/ { -1,  4, -1, -1 }
    };

    int EF[12] =
    {
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
    };

    string saida;
    bool iniciouAlfabeto = false;
    bool invalida = false;

    estado = 0;
    cin.get(simbolo);

    while (simbolo != '$')
    {
        if (simbolo == ' '  ||
            simbolo == '\n' ||
            simbolo == '\t' ||
            simbolo == '\r' ||
            simbolo == '\v' ||
            simbolo == '\f')
        {
            if (!saida.empty())
            {
                if (!iniciouAlfabeto)
                {
                    cout << "ERRO: símbolo(s) inválido(s): "
                         << saida << endl;
                }
                else if (invalida)
                {
                    cout << "ERRO: sentença inválida: "
                         << saida << endl;
                }
                else
                {
                    if (EF[estado] == 1)
                    {
                        cout << "sentença válida: "
                             << saida << endl;
                    }
                    else
                    {
                        cout << "ERRO: sentença inválida: "
                             << saida << endl;
                    }
                }

                saida.clear();
            }

            estado = 0;
            iniciouAlfabeto = false;
            invalida = false;
        }

        else if (simbolo == '+' ||
                 simbolo == '-' ||
                 simbolo == '*' ||
                 simbolo == '/')
        {
            if (!saida.empty())
            {
                if (!iniciouAlfabeto)
                {
                    cout << "ERRO: símbolo(s) inválido(s): "
                         << saida << endl;
                }
                else if (invalida)
                {
                    cout << "ERRO: sentença inválida: "
                         << saida << endl;
                }
                else
                {
                    if (EF[estado] == 1)
                    {
                        cout << "sentença válida: "
                             << saida << endl;
                    }
                    else
                    {
                        cout << "ERRO: sentença inválida: "
                             << saida << endl;
                    }
                }

                saida.clear();
            }

            estado = 0;
            iniciouAlfabeto = false;
            invalida = false;

            cout << "operador aritmético: "
                 << simbolo << endl;
        }

        else if (simbolo == 'a' ||
                 simbolo == 'b' ||
                 simbolo == 'c' ||
                 simbolo == 'd')
        {

            if (saida.empty())
            {
                iniciouAlfabeto = true;
            }

            if (!invalida)
            {
                if (simbolo == 'a')
                    estado = tabela[estado][0];

                else if (simbolo == 'b')
                    estado = tabela[estado][1];

                else if (simbolo == 'c')
                    estado = tabela[estado][2];

                else if (simbolo == 'd')
                    estado = tabela[estado][3];

                if (estado == -1)
                {
                    invalida = true;
                }
            }

            saida += simbolo;
        }

        else
        {
            if (saida.empty())
            {
                iniciouAlfabeto = false;
            }

            else
            {
                invalida = true;
            }

            saida += simbolo;
        }

        cin.get(simbolo);
    }

    if (!saida.empty())
    {
        if (!iniciouAlfabeto)
        {
            cout << "ERRO: símbolo(s) inválido(s): "
                 << saida << endl;
        }
        else if (invalida)
        {
            cout << "ERRO: sentença inválida: "
                 << saida << endl;
        }
        else
        {

            if (EF[estado] == 1)
            {
                cout << "sentença válida: "
                     << saida << endl;
            }
            else
            {
                cout << "ERRO: sentença inválida: "
                     << saida << endl;
            }
        }
    }

    return 0;
}
