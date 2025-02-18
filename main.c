#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

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
        printf("\nMENU PRINCIPAL\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Mostrar tudo\n\t6. Apagar arquivo\n\t7. Salvar num arquivo\n\t8. Sair\nEscolha: ");
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
                projeto();
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
                printf("%s\n", blue("Saindo do programa..."));
                exit(0);
            default:
                printf("%s\n", red("Opção invalida. Tente novamente."));
                break;
        }
    }

    return 0;
}
