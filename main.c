#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    //lingua
    setlocale(LC_ALL, "Portuguese");

    //variaveis
    char escolha;

    /*
        ora??o contra os males do nosso santo dia:
        
        Pai Nosso que estais no Ceus,
        Santificado seja o Vosso Console,
        Venha a n?s o Vosso Array,
        Seja feita a Vossa vontade
        Assim no backend como no front.

        O c?digo nosso de cada dia nos compile hoje,
        Perdoai nossas exce??es
        Assim como n?s tratamos quem nos deu bug,
        E n?o vos deixei cair em deploy na sexta,
        Mas livrai-nos do rollback.

        A main. ??
    */


    while (1) {
        //limpar cmd
        system("cls");

        printf("Configuração de cores para manuteções:\n");
        printf("%s\n", blue("Tudo certo"));
        printf("%s\n", yellow("Com problemas, precisa de manutenção"));
        printf("%s\n", red("Não pega e precisa refazer"));

        //menu
        printf("\n==========%s==========", blue("PROJETO_FERIAS"));

        printf("\nMENU PRINCIPAL");
        printf("\n\t1. %s", blue("Atividades"));
        printf("\n\t2. %s", blue("Trabalhos"));
        printf("\n\t3. %s", blue("Projetos"));
        printf("\n\t4. %s", blue("Provas"));
        printf("\n\t5. %s", yellow("Mostrar tudo salvo"));
        printf("\n\t6. %s", blue("Apagar arquivo"));
        printf("\n\t7. %s", red("Salvar e recuperar backup"));
        printf("\n\t8. %s", blue("Sortear uma atividade de treino"));
        printf("\n\t9. Sair");
        
        printf("\nEscolha: ");
        scanf(" %c", &escolha);
        fflush(stdin); //limpar buffer

        printf("\n==================================\n");

        switch (escolha) {
            case '1':
                MenuAtividade();
                break;
            case '2':
                menu_trabalho();
                break;
            case '3':
                MenuProjeto();
                break;
            case '4':
                MenuProva();
                break;
            case '5':
                MostrarTudoSalvo();
                break;
            case '6':
                Apagar();
                break;
            case '7':
                printf("%s", red("Simplismente não existe\nCom erro até o talo"));
                sleep(2);
                break;
            case '8':
                MenuDesafioLinguagem();
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