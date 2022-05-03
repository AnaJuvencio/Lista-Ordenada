#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaOrdenada.h"
#define MAXchar 50

typedef struct alunos alunos;
int comp(alunos al, alunos alu);

int main()
{
    setlocale(LC_ALL, "Portuguese"); //define o idioma
    printf("-------------------------LISTA ORDENADA ------------------\n");
    printf("------------%s--------------\n\n", copyright);//autores do código

    //variáveis:
    char opcoes[10], nomeRemover[MAXchar];
    float resultNotas = 0;

    lista li;

    alunos dados;
    inicializar(&li, comp);//inicializar estrutura, enviando a função de comparação

    do{

        printf("DIGITE A OPERAÇÃO QUE DESEJA FAZER:\n");
        scanf("%s", opcoes);
        if((strcmp("sair", opcoes)) == 0){
            break;
        }
        else if((strcmp("inserir", opcoes)) == 0){//opcao de inserir
            printf("DIGITE O NOME DO ALUNO:\n");
            scanf(" %[^\n]", dados.nome);
            printf("DIGITE A NOTA DESSE ALUNO:\n");
            scanf("%f", &dados.nota);
            inserir(&li, dados);
        }
        else if((strcmp("remover", opcoes)) == 0){//opcao remover
            if(listaVazia(&li) == 1){
                printf("Lista vazia.\n");
            }else{
                printf("DIGITE O NOME DO ALUNO QUE DESEJA REMOVER:\n");
                scanf(" %[^\n]", nomeRemover);
                if(remover(&li, nomeRemover, &resultNotas) == 1)
                    printf("Voce removeu: Nome: %s  Nota: %.2f\n", nomeRemover , resultNotas);
                else
                    printf("Esse nome não está na lista.\n");
            }
        }
        else if((strcmp("mostrarL", opcoes)) == 0){
            if(listaVazia(&li) == 1){
                printf("Lista vazia.\n");
            }else{
                imprime_Lista(&li);
            }
        }
        else{
            printf("Operacao invalida\n");
        }
    }while((strcmp("sair", opcoes)) != 0);

    destruir(&li);
    return 0;
}
int comp(alunos al, alunos alu){//comparar para ordenar
    return strcmp(al.nome, alu.nome);
}
