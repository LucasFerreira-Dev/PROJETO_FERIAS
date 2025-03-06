#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void gerarAtividade() {
    //lingua
    setlocale(LC_ALL, "portuguese");

    // Inicializa a semente do gerador de n�meros aleat�rios
    srand(time(NULL));

    // Array com alguns elementos
    char *linguagens[] = {"Python", "C", "HTML + CSS", "JavaScript", "PHP", "Unity", "java", "MySQL"};
    int tamanho = sizeof(linguagens) / sizeof(linguagens[0]);

    //array de nivel
    char *nivel[] = {"B�sico", "M�dio", "Avan�ado"};
    int tamanhoNivel = sizeof(nivel) / sizeof(nivel[0]);

    // Sorteia um �ndice aleat�rio
    int indice = rand() % tamanho;
    int indiceNivel = rand() % tamanhoNivel;

    // Exibe o item sorteado
    printf("Item sorteado: %s\nNivel: %s\n", linguagens[indice], nivel[indiceNivel]);

    return 0;
}
