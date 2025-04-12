//fuções de projetos
void escreverProjeto() {
    //limpar cmd
    system("cls");

    printf("%s", yellow("Ainda com erros.\nFalta fazer o mostrar menu\nApagar projeto\n"));

    //variaveis
    char lider[1000];
    char materia[1000];
    char funsao[1000];
    char dia[1000];

    //entada
    printf("Digite o lider do projeto:\n");
    fflush(stdin);
    fgets(lider, sizeof(lider), stdin);
    lider[strcspn(lider, "\n")] = 0; //remove o \n

    printf("Digite qual é a materia do projeto:\n");
    fgets(materia, sizeof(materia), stdin);
    materia[strcspn(materia, "\n")] = 0; //remove o \n

    printf("Digite sua função no projeto:\n");
    fgets(funsao, sizeof(funsao), stdin);
    funsao[strcspn(funsao, "\n")] = 0; //remove o \n

    printf("Digite o dia de entrega:\n");
    fgets(dia, sizeof(dia), stdin);
    dia[strcspn(dia, "\n")] = 0; //remove o \n

    //ponteiro
    FILE *file;
    file = fopen("projeto.txt","a");

    //teste
    if(file == NULL){
        printf("Deu zebra\n");
        return;
    }

    //salvar arquivo
    fprintf(file, "Lider %s. Materia %s. Função %s. Dia da entrega: %s\n", lider, materia, funsao, dia);
    printf("Tudo salvo com sucesso\n");

    //fechar arquivo
    fclose(file);
}

void mostrarProjetos(){
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    //abrir arquivo
    FILE *file = fopen("projeto.txt", "r");

    if (file == NULL){
        printf("Nenhuma atividade encontrada.\n");
        return;
    }

    printf("======= Projetos =====\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("======================\n");

    fclose (file);
}

void menuProjeto(){
    //limpar cmd
    system("cls");

    char esc;
    while (1) {
        printf("%s",blue("Mensagem:\nTudo ja pronto:\n"));
        printf("\nMENU\n\t1. Escrever um novo projeto\n\t2. Mostrar todos os projetos\n\t3. Remover projetos finalizados\n\t4. Sair\nOpção: ");
        scanf(" %c", &esc);

        switch (esc) {
            case '1':
                escreverProjeto();
                break;
            case '2':
                mostrarProjetos();
                break;
            case '3':
                remover_linha("projeto.txt");
                break;
            case '4':
                return;//sair
            default:
                printf("%s\n", red("Opção invalida. Tente novamente.\n"));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }
}