# Implementação de Autômatos Finitos

### Executar

O programa abre uma janela gráfica. O executável precisa ser gerado para o mesmo sistema operacional em que será usado.

Linux: na raiz do projeto, execute:

```bash
chmod +x dist/reconhecedor
./dist/reconhecedor
```

Windows: execute `dist\reconhecedor.exe` com duplo clique ou pelo PowerShell:

```powershell
.\dist\reconhecedor.exe
```

O projeto contém o executável Linux em `dist/reconhecedor`. Para gerar o executável no Windows, instale o Python e o PyInstaller e rode na raiz do projeto:

```powershell
python -m pip install pyinstaller
python -m PyInstaller --onefile --name reconhecedor main.py
```

No Linux, para gerar novamente o executável:

```bash
python3 -m pip install pyinstaller
python3 -m PyInstaller --onefile --name reconhecedor main.py
```

### Diagrama de transição que representa matriz *tabela* e vetor *EF*:


![AFDM](./docs/diagrama.png)
*Construído em [Flap.js](https://flapjs.github.io/FLAPJS-WebApp/)

A lógica do programa foi construída em *reconhecedor.py* e aplicada na interface em *main.py*.