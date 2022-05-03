#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaOrdenada.h"
#define MAXchar 50

typedef char nomes;
typedef float notas;

typedef struct node{
    struct node *ant;
    struct alunos dados;
    struct node *prox;
}no;

void inicializar(lista *li, int(*ord)(struct alunos al , struct alunos alu)){
    no *n = (no*) malloc(sizeof(no));
    n->prox = n->ant = li->sentinela = n;
    li->quantidade = 0;
    li->comp = ord;//funcao ordenar
}

void inserir(lista *li, struct alunos al){
    no *n = (no*) malloc(sizeof(no));

    n->dados = al;
    //strcpy(n->dados.nome, al.nome);
    //n->dados.nota = al.nota;

    no *elementoAnt = li->sentinela;
    no *percorrer = li->sentinela->prox; //percorre o vetor

    while(percorrer != li->sentinela && li->comp(percorrer->dados, al) < 0){
        elementoAnt = percorrer; //guarda o elemento anterior
        percorrer = percorrer->prox;
    }
    if(listaVazia(li) == 1){//insere no início
        n->prox = li->sentinela;
        n->ant = li->sentinela;
        li->sentinela->prox = n;
        li->sentinela->ant = n;
    }else{
        n->prox = elementoAnt->prox;
        n->ant = elementoAnt;
        elementoAnt->prox->ant = n;//proximo elemento anterior
        elementoAnt->prox = n;
    }
    li->quantidade++;
}
int remover(lista *li, nomes aluno[MAXchar], notas *resultNotas){
    iterador primeiro = primeiro_Lista(li);//retonando o primeiro da lista
    iterador ultimo = ultimo_Lista(li);//retornando o último da lista

    iterador result = procuraPrimeiro_Lista(li, aluno);//procura o aluno

    *resultNotas = result.posicao->dados.nota;//guarda a nota para exibir na main

    if(acabou_Lista(result) == 1){
        return 0;
    }else{
        if(strcmp(result.posicao->dados.nome, aluno) == 0){
            result.posicao->prox->ant = result.posicao->ant;
            result.posicao->ant->prox = result.posicao->prox;
                        //INICIO
            if(result.posicao == primeiro.posicao){
                primeiro.posicao = result.posicao->prox;
            }
                        //FINAL
            else if(result.posicao == ultimo.posicao){
                ultimo.posicao = result.posicao->ant;
            }
            no *excluir;
            excluir = result.posicao;
            result.posicao = result.posicao->prox;
            li->quantidade--;
            free(excluir);
        }
        return 1;
    }
}
int listaVazia(lista *li){
    return li->sentinela->prox == li->sentinela;
}

void destruir(lista *li){
   no *n;
    while(n != li->sentinela){
        n = li->sentinela;
        li->sentinela = li->sentinela->prox;
        free(n);
    }
    free(li);
}

//--------------iterador:------------------------------------


iterador ultimo_Lista(lista *li) {
    iterador i;
    i.posicao = li->sentinela->ant;
    i.estrutura = li;
    return i;
}

int proximo_Lista(iterador *i) {
    if(!acabou_Lista(*i) && i != NULL){
        i->posicao = i->posicao->prox;
        return 1;
    }
    return 0;
}

int anterior_Lista(iterador *i) {
    if(!acabou_Lista(*i) && i != NULL){
        i->posicao = i->posicao->ant;
        return 1;
    }
    return 0;
}
iterador primeiro_Lista(lista *li) {
    iterador i;
    i.posicao = li->sentinela->prox;
    i.estrutura = li;
    return i;
}

iterador procuraPrimeiro_Lista(lista *li, nomes aluno[MAXchar]){
    iterador iteradorId = primeiro_Lista(li);
    while((strcmp(iteradorId.posicao->dados.nome, aluno)) != 0){
            if(acabou_Lista(iteradorId) == 1)
                return iteradorId;//se não encontrar retorna iterador pra o sentinela
            proximo_Lista(&iteradorId);
    }
    return iteradorId; //quando encontrar retorna o iterador para esse elemento
}

int acabou_Lista(iterador i) {
    return i.posicao == i.estrutura->sentinela;
}
//imprimir lista:
void imprime_Lista(lista *li){
    no *n = li->sentinela->prox;
    while(n != li->sentinela){
        printf("Nome: %s  -  ", n->dados.nome);
        printf("Nota: %.2f\n", n->dados.nota);
        printf("-------------------------------------\n");
        n = n->prox;
    }
}
