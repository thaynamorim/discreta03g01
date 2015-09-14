## Matemática Discreta - Exercício 3

Exercício 3 da disciplina de Matemática Discreta da Escola Politécnica de Pernambuco - UPE

#Autores

Hugo Albuquerque de Fonsêca
<hugoalbuquerque0@gmail.com>

Lucas Canejo Jurema
<lucasbrgol2010@hotmail.com>

Mateus Lenier Rezende
<mateuslenier@gmail.com>

Paulo Vitor Alves Patriota
<paulovitorpatriota@gmail.com>

Thayna Maria Morim de Barros Barreto
<tmorimbarreto@gmail.com>

#Objetivo

Este exercicio tem como objetivo simular uma Rede de Petri, dado um arquivo de entrada. Inicialmente, serao utilizados conceitos simples como vetores e aleatoriedade para alcancar o resultado desejado. Mais futuramente, em versoes mais avancadas do programa, conceitos como alocacao dinamica e programacao em paralelo deverao ser adicionados, de maneira que este programa se torne um aprendizado continuo de linguagem C avancada.

#Entrada

Para simular a Rede de Petri utilizando este codigo, necessita-se alimenta-lo com um arquivo de entrada. O arquivo nao deve conter nenhum texto, e deve ser formatado _exatamente_ como proposto na tabela abaixo:

Linha          | Descricao
-------------- | --------------------------------------------
1              | Quantidade de Lugares
2              | Quantidade de Transicoes
3              | Quantidade de Lugares com pelo menos um Token
4              | Quantidade de Arcos Lugar -> Transicao
5              | Quantidade de Arcos Transicao -> Lugar
6,...,x        | Descricao Lugar/Token
x+1,...,y      | Descricao do arco Lugar/Quantidade/Transicao
y+1,...,z      | Descricao do arco Transicao/Quantidade/Lugar

Exemplo de input:
```
2
2
1
2
2
0 4
0 1 0
1 2 1
0 1 1
1 1 0
```
Isso gera uma Rede de Petri com o seguinte formato:


![Exemplo](http://puu.sh/kb7DZ/6fd3f2e906.png "Exemplo - Rede de Petri")
