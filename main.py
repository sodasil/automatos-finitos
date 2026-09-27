import tkinter as tk
from tkinter import font

from reconhecedor import analisar_entrada

def analisar():
    entrada = campoA.get("1.0", tk.END)

    resultados = analisar_entrada(entrada)

    campoB.config(state="normal")
    campoB.delete("1.0", tk.END)

    for resultado in resultados:
        campoB.insert(tk.END, resultado + "\n")

    campoB.config(state="disabled")


def limpar():
    campoA.delete("1.0", tk.END)

    campoB.config(state="normal")
    campoB.delete("1.0", tk.END)
    campoB.config(state="disabled")


janela = tk.Tk()

janela.title("Reconhecedor de Linguagem Regular")

janela.geometry("575x410")

janela.configure(bg="#d6d6d6")

janela.resizable(False, False)

COR_FUNDO = "#d6d6d6"
COR_JANELA = "#d4d0c8"
COR_AZUL = "#000080"
COR_VERDE = "#008000"
COR_VERDE_BORDA = "#004000"
COR_CINZA = "#808080"
COR_ESCURO = "#404040"

fonte_titulo = font.Font(
    family="Arial",
    size=9,
    weight="bold"
)

fonte_campo_a = font.Font(
    family="Courier New",
    size=10
)

fonte_campo_b = font.Font(
    family="Courier New",
    size=9
)

fonte_botao = font.Font(
    family="Arial",
    size=9
)

fonte_tokens = font.Font(
    family="Arial",
    size=9
)

borda_externa = tk.Frame(
    janela,
    bg=COR_JANELA,
    highlightthickness=0,
    bd=0
)

borda_externa.pack(
    fill="both",
    expand=True,
    padx=10,
    pady=10
)

barra_titulo = tk.Frame(
    borda_externa,
    bg=COR_AZUL,
    height=22
)

barra_titulo.pack(
    fill="x"
)

barra_titulo.pack_propagate(False)

icone = tk.Frame(
    barra_titulo,
    width=15,
    height=15,
    bg=COR_VERDE,
    highlightbackground=COR_VERDE_BORDA,
    highlightthickness=1
)

icone.pack(
    side="left",
    padx=(5, 5),
    pady=3
)

icone.pack_propagate(False)


icone_check = tk.Label(
    icone,
    text="✓",
    bg=COR_VERDE,
    fg="yellow",
    font=("Arial", 9, "bold")
)

icone_check.place(
    x=1,
    y=-3
)

texto_titulo = tk.Label(
    barra_titulo,
    text="Reconhecedor de Linguagem Regular",
    bg=COR_AZUL,
    fg="white",
    font=fonte_titulo
)

texto_titulo.pack(
    side="left"
)

conteudo = tk.Frame(
    borda_externa,
    bg=COR_JANELA
)

conteudo.pack(
    fill="both",
    expand=True,
    padx=10,
    pady=10
)

campoA = tk.Text(
    conteudo,
    width=64,
    height=7,

    bg="white",
    fg="black",

    font=fonte_campo_a,

    relief="sunken",
    bd=2,

    padx=4,
    pady=4,

    wrap="none"
)

campoA.pack(
    fill="x"
)

botoes = tk.Frame(
    conteudo,
    bg=COR_JANELA,
    height=38
)

botoes.pack(
    fill="x"
)

botoes.pack_propagate(False)

botao_analisar = tk.Button(
    botoes,

    text="✓  Analisar",

    command=analisar,

    width=9,
    height=1,

    bg=COR_JANELA,
    fg="black",

    font=fonte_botao,

    relief="raised",
    bd=2,

    padx=5,
    pady=0,

    activebackground=COR_JANELA
)

botao_analisar.pack(
    side="right",
    padx=(6, 0),
    pady=7
)

botao_limpar = tk.Button(
    botoes,

    text="🧹  Limpar",

    command=limpar,

    width=9,
    height=1,

    bg=COR_JANELA,
    fg="black",

    font=fonte_botao,

    relief="raised",
    bd=2,

    padx=5,
    pady=0,

    activebackground=COR_JANELA
)

botao_limpar.pack(
    side="right",
    pady=7
)

grupo_tokens = tk.LabelFrame(
    conteudo,

    text="Tokens",

    bg=COR_JANELA,
    fg="black",

    font=fonte_tokens,

    relief="groove",
    bd=1,

    padx=7,
    pady=5
)

grupo_tokens.pack(
    fill="both",
    expand=True
)

campoB = tk.Text(
    grupo_tokens,

    height=5,

    bg="white",
    fg="black",

    font=fonte_campo_b,

    relief="sunken",
    bd=2,

    padx=4,
    pady=4,

    wrap="none"
)

campoB.pack(
    fill="both",
    expand=True
)

campoB.config(
    state="disabled"
)

janela.bind(
    "<Control-Return>",
    lambda event: analisar()
)

janela.bind(
    "<Escape>",
    lambda event: limpar()
)

janela.mainloop()