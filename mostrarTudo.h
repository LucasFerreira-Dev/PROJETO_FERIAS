void mostrar_tudo() {
    //limpar cmd
    system("cls");

    //mensagem
    printf("%s", yellow("Manutencao extrema\nVou refazer a logica de tudo aqui do inicio\n"));
    sleep(2);
    
    //variaveis
    char linha[200];
    char deque[3][20] = {"ATIVIDADES","TRABALHOS", "PROJETOS"};
    char tipo[3][20]= {"atividades.txt","trabalho.txt","projeto.txt"};
    int numero = 1;

    for(int i = 0; i <= 3; i++){
        //ponteiro
        FILE *file;
        file = fopen(tipo[i], "r");

        if (file == NULL) {
            printf("Nenhum trabalho encontrada.\n");
            return;
        }

        printf("\n============%s=============\n", deque[i]);
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%d - %s", numero, linha);
            numero++;
        }
        printf("\n==================================\n");

        fclose(file);
    }
}
