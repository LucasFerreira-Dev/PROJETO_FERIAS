void EscreverProva() {
    //limpar cmd
    system("cls");

    //lingua
    setlocale(LC_ALL, "portuguese");

    //variaveis
    char materia[100];
    char local[100];
    char entrega[100];
    char tipoProva[100];
    int quantidade;

    //abrir o arquivo
    FILE *file = fopen("prova.txt","a");

    //verificação
    if (file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    //logica
    printf("Quantas provas serão adicionadas: ");
    while(scanf("%d", &quantidade) != 1){
        printf("Quantas provas serão adicionadas: ");
        while(getchar() != '\n'); //limpar buffer
    }

    fflush(stdin); //limpar buffer

    for(int i = 0; i < quantidade; i++){
        //limpar cmd
        system("cls");

        printf("Anotações da %d prova\n", i + 1);
        printf("Digite o tipo de prova: ");
        fgets(tipoProva, sizeof(tipoProva), stdin);
        tipoProva[strcspn(tipoProva, "\n")] = 0; // Remove o '\n'

        printf("Digite a materia da sua prova: ");
        fgets(materia, sizeof(materia), stdin);
        materia[strcspn(materia, "\n")] = 0; // Remove o '\n'

        printf("Digite o local:\tExemplo: online, presencial:\n");
        fgets(local, sizeof(local), stdin);
        local[strcspn(local, "\n")] = 0; // Remove o '\n'

        printf("Digite o dia que será a prova: ");
        fgets(entrega, sizeof(entrega), stdin);
        entrega[strcspn(entrega, "\n")] = 0; // Remove o '\n'

        //salvar no arquivo
        fprintf(file, "Tipo: %s. Materia: %s. Local: %s. Dia: %s\n", tipoProva, materia, local, entrega);
    }  

    //fechar o arquivo
    fclose(file);
    printf("Provas salva com sucesso!\n");
}

void MostrarProva() {
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    FILE *file;
    file = fopen("prova.txt", "r");

    if (file == NULL) {
        printf("Nenhuma prova encontrada.\n");
        return;
    }

    printf("===== Provas =====\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("======================\n");

    fclose (file);
}

void MenuProva() {
    //limpar cmd
    system("cls");

    char esc;
    while (1) {
        printf("%s",blue("Mensagem:\nTudo ja pronto:\n"));
        printf("\nMENU\n\t1. Escrever nova prova\n\t2. Mostrar todas as provas\n\t3. Remover provas já feitas\n\t4. Sair\nOpção: ");
        scanf(" %c", &esc);

        switch (esc) {
            case '1':
                EscreverProva();
                break;
            case '2':
                MostrarProva();
                break;
            case '3':
                remover_linha("prova.txt");
                break;
            case '4':
                printf("%s\n", blue("Saindo do programa..."));
                sleep(1);  // pausa de 2 segundos
                return;//sair
            default:
                printf("%s\n", red("Opção invalida. Tente novamente."));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }
}
