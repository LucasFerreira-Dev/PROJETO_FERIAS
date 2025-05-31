// Fun��es de atividades
void EscreverAtividade() {
    //limpar cmd
    system("cls");

    //variaveis
    char materia[1000];
    char atividade[1000];
    char entrega[1000];

    printf("Digite a mat�ria:\n");
    fflush(stdin);// geito correto de limpar o buffer
    fgets(materia, sizeof(materia), stdin);
    materia[strcspn(materia, "\n")] = 0; // Remove o '\n'

    printf("Digite qual ser� a atividade:\n");
    fgets(atividade, sizeof(atividade), stdin);
    atividade[strcspn(atividade, "\n")] = 0;

    printf("Digite o dia de entrega:\n");
    fgets(entrega, sizeof(entrega), stdin);
    entrega[strcspn(entrega, "\n")] = 0;

    FILE *file;
    file = fopen("atividades.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Mat�ria: %s. Atividade: %s. Entrega: %s. \n", materia, atividade, entrega);
    fclose(file);
    printf("Atividade salva com sucesso!\n");
}

void MostrarAtividades() {
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    FILE *file;
    file = fopen("atividades.txt", "r");

    if (file == NULL) {
        printf("Nenhuma atividade encontrada.\n");
        return;
    }

    printf("===== ATIVIDADES =====\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("======================\n");

    fclose (file);
}

void MenuAtividade() {
    //limpar cmd
    system("cls");

    char esc;
    while (1) {
        printf("\nMENU\n\t1. Escrever nova atividade\n\t2. Mostrar todas as atividades\n\t3. Remover atividades\n\t4. Sair\nOp��o: ");
        scanf(" %c", &esc);

        switch (esc) {
            case '1':
                EscreverAtividade();
                break;
            case '2':
                MostrarAtividades();
                break;
            case '3':
                remover_linha("atividades.txt");
                break;
            case '4':
                printf("%s\n", blue("Saindo do programa..."));
                sleep(1);  // pausa de 2 segundos
                return;
            default:
                printf("%s\n", red("Op��o invalida. Tente novamente."));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }
}