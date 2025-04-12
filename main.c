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

    while (1) {
        //limpar cmd
        system("cls");

        //menu
        printf("\n==========%s==========", blue("PROJETO_FERIAS"));
        printf("\nMENU PRINCIPAL\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Mostrar tudo\n\t6. Apagar arquivo\n\t7. Salvar num arquivo\n\t8. Sortear uma atividade de treino\n\t9. Sair\nEscolha: ");
        scanf(" %c", &escolha);
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
                prova();
                break;
            case '5':
                mostrar_tudo();
                break;
            case '6':
                apagar();
                break;
            case '7':
                break;
            case '8':
                menuDesafioLinguagem();
                break;
            case '9':
                printf("%s\n", blue("Saindo do programa..."));
                exit(0);
            default:
                printf("%s\n", red("Opção invalida. Tente novamente."));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }

    return 0;
}
