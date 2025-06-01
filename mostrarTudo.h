void MostrarTudoSalvo() {
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    char deque[5][20] = {"ATIVIDADES","TRABALHOS", "PROJETOS", "PROVAS", "DESAFIOS"};
    char local[5][20] = {"atividades.txt","trabalho.txt","projeto.txt","prova.txt","desafiolinguagem.txt"};
    int numero = 1;

    for(int i = 0; i < 5; i++){
        FILE *file;
        file = fopen(local[i], "r");

        if (file == NULL) {
            printf("Nenhum(a) %s encontrado(a).\n", deque[i]);
            sleep(2);
            continue;
        }

        printf("===== %s =====\n", deque[i]);
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%d - %s", numero, linha);
            numero++;
        }
        printf("======================\n");

        fclose (file);
    }
    
    printf("\nAtividades pendentes %d", numero - 1);
    
    sleep(4);
}