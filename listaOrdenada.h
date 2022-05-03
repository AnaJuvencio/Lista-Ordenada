#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED
#define copyright "copyright@ Ana Beatriz Juvencio e Victor Motta"
#define MAXchar 50

typedef char nomes;//renomear o char para nomes
typedef float notas;//renomear float para notas

struct alunos{//dados do aluno
    nomes nome[MAXchar];
    notas nota;
};
//--------------------------------------------------
struct lista{//estrutura
    struct node *sentinela;
    unsigned quantidade;
    int (*comp)(struct alunos al, struct alunos alu);
};
typedef struct lista lista;
//--------------------------------------------------
typedef struct Iterador{//iterador
    struct node *posicao;
    lista *estrutura;
}iterador;
typedef struct Iterador iterador;
//------FUNÇÕES-------------------------------------
void inicializar(lista *li, int(*ord)(struct alunos al, struct alunos alu));//inicializar lista
int listaVazia(lista *li);//verificar se a lista está vazia
void inserir(lista *li, struct alunos al);//inserir de forma ordenada na lista
int remover(lista *li, nomes aluno[MAXchar], notas *resultNotas);//remover da lista
void destruir(lista *li);//desalocar a memória de forma apropriada

//iterador:
iterador ultimo_Lista(lista *li);//retornar o último da lista
int proximo_Lista(iterador *i);//avançar para o próximo da lista
iterador primeiro_Lista(lista *li);//retornar o primeiro da lista
iterador procuraPrimeiro_Lista(lista *li, nomes aluno[MAXchar]);//procura o elemento digitado pelousuário
int acabou_Lista(iterador i);//retornar o sentinela
//imprimir:
void imprime_Lista(lista *li);


#endif // LISTAORDENADA_H_INCLUDED
