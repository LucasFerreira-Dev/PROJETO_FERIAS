//bibliotecas
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//chamar arquivos
#include "maiusculoMinusculo.h"
#include "cores.h"
#include "removeLinha.h"
#include "atividades.h"
#include "trabalhos.h"
#include "projetos.h"
#include "prova.h"
#include "mostrarTudo.h"
#include "apagar.h"
#include "desafioLinguagem.h"
#include "salvarRecuperar.h"

int main() {
    //lingua
    setlocale(LC_ALL, "Portuguese");

    //variaveis
    char escolha;

    /*
        Oração contra os males do nosso santo dia:
        
        Pai Nosso que estais no Ceus,
        Santificado seja o Vosso Console,
        Venha a nós o Vosso Array,
        Seja feita a Vossa vontade
        Assim no backend como no front.

        O código nosso de cada dia nos compile hoje,
        Perdoai nossas exceções
        Assim como n?s tratamos quem nos deu bug,
        E não vos deixei cair em deploy na sexta,
        Mas livrai-nos do rollback.

        A main.
    */


    while (1) {
        //limpar cmd
        system("cls");

        //menu
        printf("\n==========%s==========", blue("PROJETO_FERIAS"));
        
        printf("\nMENU PRINCIPAL");
        printf("\n\t1. Atividades");
        printf("\n\t2. Trabalhos");
        printf("\n\t3. Projetos");
        printf("\n\t4. Provas");
        printf("\n\t5. Mostrar tudo salvo");
        printf("\n\t6. Apagar arquivo");
        printf("\n\t7. Salvar e recuperar backup");
        printf("\n\t8. Sortear uma atividade de treino");
        printf("\n\t9. Sair");
        
        printf("\nEscolha: ");
        scanf(" %c", &escolha);
        fflush(stdin); //limpar buffer

        printf("\n==================================\n");

        switch (escolha) {
            case '1':
                MenuAtividade();
                salvar(); //faz o salvamento de dados
                break;
            case '2':
                menu_trabalho();
                salvar(); //faz o salvamento de dados
                break;
            case '3':
                MenuProjeto();
                salvar(); //faz o salvamento de dados
                break;
            case '4':
                MenuProva();
                salvar(); //faz o salvamento de dados
                break;
            case '5':
                MostrarTudoSalvo();
                break;
            case '6':
                Apagar();
                break;
            case '7':
                recuperar();
                sleep(2);
                break;
            case '8':
                MenuDesafioLinguagem();
                salvar(); //faz o salvamento de dados
                break;
            case '9':
                printf("%s\n", blue("Saindo do programa..."));
                sleep(1);  // pausa de 2 segundos
                exit(0);
            default:
                printf("%s\n", red("Opção invalida. Tente novamente."));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }

    return 0;
}