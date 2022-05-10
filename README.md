# Lista Ordenada
Criando uma estrutura "Lista" em linguagem C, com inserção Ordenada.

## Estrutura de Dados:
* Lista ✅

## Aplicação:
O programa foi desenvolvido para receber os nomes dos alunos e suas respectivas notas de uma prova. o usuário poderá digitar esses dados na ordem que desejar, o programa será responsável por ordenar essas informações em ordem alfabética.

## Lista:
A Estrutura do tipo `Lista`, é uma sequência de elementos do mesmo tipo, podemos dizer também, que essa estrutura é uma sequência de structs, que são os nós da lista ligados entre si. Nós nunca temos acesso imediato aos dados, acessamos através de ponteiros, no qual cada nó possui. Pode ser um ponteiro somente para o sucessor, como em uma lista simplesmente encadeada.

<img src="https://github.com/anabias/Lista-Ordenada/blob/main/listaSimple.jpg" alt="Lista simplesmente encadeada" width="500"/>

Ou um ponteiro para o sucessor e o antecessor, como uma lista duplamente encadeada.

<img src="https://github.com/anabias/Lista-Ordenada/blob/main/listaDupla.jpg" alt="Lista duplamente encadeada" width="500"/>

## Iterador:
O `iterador` é um mecanismo criado para percorrer a estrutura (todos os elementos), porém ele não exibe sua representação (estrutura do iterador) interna para o usuário.
(Utilizado na função de remover da lista)
