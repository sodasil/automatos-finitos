#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>

#include <string>

using namespace std;

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

Fl_Multiline_Input* campoA;
Fl_Text_Display* campoB;
Fl_Text_Buffer* bufferB;

void processarSentenca(
    const string& saida,
    int estado,
    bool iniciouAlfabeto,
    bool invalida,
    string& resultado
)
{
    if (saida.empty())
        return;

    if (!iniciouAlfabeto)
    {
        resultado += "ERRO: símbolo(s) inválido(s): ";
        resultado += saida;
        resultado += "\n";
    }
    else if (invalida)
    {
        resultado += "ERRO: sentença inválida: ";
        resultado += saida;
        resultado += "\n";
    }
    else
    {
        if (EF[estado] == 1)
        {
            resultado += "sentença válida: ";
            resultado += saida;
            resultado += "\n";
        }
        else
        {
            resultado += "ERRO: sentença inválida: ";
            resultado += saida;
            resultado += "\n";
        }
    }
}

string reconhecer(const string& entrada)
{
    char simbolo;
    int estado;
    string saida;
    string resultado;
    bool iniciouAlfabeto = false;
    bool invalida = false;
    size_t posicao = 0;
    estado = 0;

    if (posicao < entrada.size())
        simbolo = entrada[posicao++];
    else
        simbolo = '$';
        
    while (simbolo != '$')
    {
        if (simbolo == ' ' || simbolo == '\n' || simbolo == '\t' ||
            simbolo == '\r' || simbolo == '\v' || simbolo == '\f')
        {
            processarSentenca(
                saida,
                estado,
                iniciouAlfabeto,
                invalida,
                resultado
            );
            saida.clear();
            estado = 0;
            iniciouAlfabeto = false;
            invalida = false;
        }

        else if (simbolo == '+' || simbolo == '-' ||
                 simbolo == '*' || simbolo == '/')
        {
            processarSentenca(
                saida,
                estado,
                iniciouAlfabeto,
                invalida,
                resultado
            );
            saida.clear();
            estado = 0;
            iniciouAlfabeto = false;
            invalida = false;
            resultado += "operador aritmético: ";
            resultado += simbolo;
            resultado += "\n";
        }

        else if (simbolo == 'a' || simbolo == 'b' ||
                 simbolo == 'c' || simbolo == 'd')
        {
            if (saida.empty())
                iniciouAlfabeto = true;
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
                    invalida = true;
            }

            saida += simbolo;
        }

        else
        {
            if (saida.empty())
                iniciouAlfabeto = false;
            else
                invalida = true;
            saida += simbolo;
        }

        if (posicao < entrada.size())
            simbolo = entrada[posicao++];
        else
            simbolo = '$';
    }

    processarSentenca(
        saida,
        estado,
        iniciouAlfabeto,
        invalida,
        resultado
    );

    return resultado;
}

void analisarCallback(Fl_Widget*, void*)
{
    string entrada = campoA->value();

    string resultado = reconhecer(entrada);

    bufferB->text(resultado.c_str());
}

void limparCallback(Fl_Widget*, void*)
{
    campoA->value("");
    bufferB->text("");
}


int main()
{
    Fl_Window janela(
        555,
        390,
        "Reconhecedor de Linguagem Regular"
    );

    janela.color(fl_rgb_color(214, 214, 214));

    Fl_Box titulo(
        0,
        0,
        555,
        25,
        "✓  Reconhecedor de Linguagem Regular"
    );

    titulo.box(FL_FLAT_BOX);
    titulo.color(fl_rgb_color(0, 0, 128));
    titulo.labelcolor(FL_WHITE);
    titulo.labelfont(FL_BOLD);
    titulo.labelsize(12);
    titulo.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    campoA = new Fl_Multiline_Input(
        10,
        40,
        535,
        145
    );

    campoA->box(FL_DOWN_BOX);
    campoA->textfont(FL_COURIER);
    campoA->textsize(14);
    campoA->color(FL_WHITE);

    Fl_Button analisarBotao(
        355,
        195,
        90,
        28,
        "✓ Analisar"
    );

    analisarBotao.callback(analisarCallback);

    Fl_Button limparBotao(
        450,
        195,
        95,
        28,
        "Limpar"
    );

    limparBotao.callback(limparCallback);

    Fl_Box tokensTitulo(
        10,
        235,
        535,
        25,
        "Tokens"
    );

    tokensTitulo.box(FL_ENGRAVED_BOX);
    tokensTitulo.align(
        FL_ALIGN_LEFT |
        FL_ALIGN_INSIDE
    );
    tokensTitulo.labelfont(FL_BOLD);
    tokensTitulo.labelsize(12);

    campoB = new Fl_Text_Display(
        10,
        260,
        535,
        110
    );

    campoB->box(FL_DOWN_BOX);
    campoB->textfont(FL_COURIER);
    campoB->textsize(13);
    campoB->color(FL_WHITE);

    bufferB = new Fl_Text_Buffer();
    campoB->buffer(bufferB);
    janela.end();
    janela.show();

    return Fl::run();
}