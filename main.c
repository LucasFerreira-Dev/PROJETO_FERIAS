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
        oração contra os males do nosso santo dia:
        
        Pai Nosso que estais no Ceus,
        Santificado seja o Vosso Console,
        Venha a nós o Vosso Array,
        Seja feita a Vossa vontade
        Assim no backend como no front.

        O código nosso de cada dia nos compile hoje,
        Perdoai nossas exceções
        Assim como nós tratamos quem nos deu bug,
        E não vos deixei cair em deploy na sexta,
        Mas livrai-nos do rollback.

        A main. 🙏💻
    */


    while (1) {
        //limpar cmd
        system("cls");

        //menu
        printf("\n==========%s==========", blue("PROJETO_FERIAS"));
        printf("\nMENU PRINCIPAL\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Vou reorganizar ou refazer\n\t6. Apagar arquivo\n\t7. Salvar e recuperar backup\n\t8. Sortear uma atividade de treino\n\t9. Sair\nEscolha: ");
        scanf(" %c", &escolha);
        fflush(stdin); //limpar buffer

        printf("\n==================================\n");

        switch (escolha) {
            case '1':
                atividade();
                break;
            case '2':
                menu_trabalho();
                break;
            case '3':
                menuProjeto();
                break;
            case '4':
                menuProva();
                break;
            case '5':
                mostrar_tudo();
                break;
            case '6':
                apagar();
                break;
            case '7':
                printf("%s", red("Simplismente nao existe\nCom erro ate o talo"));
                break;
            case '8':
                menuDesafioLinguagem();
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