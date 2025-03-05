#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    //lingua
    setlocale(LC_ALL, "portuguese");

    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    // Array com alguns elementos
    char *linguagens[] = {"Python", "C", "HTML + CSS", "JavaScript", "PHP", "Unity", "java", "MySQL"};
    int tamanho = sizeof(linguagens) / sizeof(linguagens[0]);

    //array de nivel
    char *nivel[] = {"Básico", "Médio", "Avançado"};
    int tamanhoNivel = sizeof(nivel) / sizeof(nivel[0]);

    // Sorteia um índice aleatório
    int indice = rand() % tamanho;
    int indiceNivel = rand() % tamanhoNivel;

    // Exibe o item sorteado
    printf("Item sorteado: %s\nNivel: %s\n", linguagens[indice], nivel[indiceNivel]);

    return 0;
}
