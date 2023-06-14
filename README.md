# Especificações de uso

### 1. Compilação
Basta rodar o comando `make` na pasta raiz do projeto. Isso irá gerar o executável `grafo` na raiz do projeto.
Para limpar os arquivos gerados pela compilação, basta rodar o comando `make clean`.

### 2. Execução
Para executar o projeto basta rodar o executável `grafo`. É necessário especificar através da linha de comando qual opção será executada. As opções são:

        |Cod| Operação |
        |0| Número de Enlaces dos vértices|
        |1| Matriz de Adjacência|
        |2| Identificar o menor caminho que conecta os vértices|
        |3| Verificar se o grafo é conexo|
        |4| Identificar o vértice com maior grau|

O arquivo que contém as informações do Grafo é o grafo.csv, é possível modificar o path do arquivo dentro do arquivo Grafo.h.

```
./grafo <opção>
```
O comando acima irá executar o programa com a opção escolhida.
