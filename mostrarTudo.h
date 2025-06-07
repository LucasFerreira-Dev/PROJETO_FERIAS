void MostrarTudoSalvo() {
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    char deque[5][20] = {"ATIVIDADES","TRABALHOS", "PROJETOS", "PROVAS", "DESAFIOS"};
    char local[5][40] = {
        "output/atividades.txt",
        "output/trabalho.txt",
        "output/projeto.txt",
        "output/prova.txt",
        "output/desafiolinguagem.txt"
    };
    
    int numero = 1;

    for(int i = 0; i < 5; i++){
        FILE *file;
        file = fopen(local[i], "r");

        if (file == NULL) {
            printf("Nenhum(a) %s encontrado(a).\n", deque[i]);
            sleep(2);
            continue;
        }

        printf("\n===== %s =====\n", deque[i]);
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%d - %s", numero, linha);
            numero++;
        }
        printf("======================\n");

        if(i == 2){
                printf("\nAtividades pendentes %d\n", numero - 1);
        }

        fclose (file);
    }
    
    
    
    sleep(4);
}