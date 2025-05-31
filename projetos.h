//fuções de projetos
void EscreverProjeto() {
    //limpar cmd
    system("cls");

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
    fprintf(file, "Lider: %s. Matéria: %s. Função: %s. Dia da entrega: %s\n", lider, materia, funsao, dia);
    printf("Tudo salvo com sucesso\n");

    //fechar arquivo
    fclose(file);
}

void MostrarProjetos(){
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    //abrir arquivo
    FILE *file = fopen("projeto.txt", "r");

    if (file == NULL){
        printf("Nenhuma projeto encontrada.\n");
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

void MenuProjeto(){
    //limpar cmd
    system("cls");

    char esc;
    while (1) {
        printf("\nMENU\n\t1. Escrever um novo projeto\n\t2. Mostrar todos os projetos\n\t3. Remover projetos finalizados\n\t4. Sair\nOpção: ");
        scanf(" %c", &esc);

        switch (esc) {
            case '1':
                EscreverProjeto();
                break;
            case '2':
                MostrarProjetos();
                break;
            case '3':
                remover_linha("projeto.txt");
                break;
            case '4':
                printf("%s\n", blue("Saindo do programa..."));
                sleep(1);  // pausa de 2 segundos
                return;//sair
            default:
                printf("%s\n", red("Opção invalida. Tente novamente.\n"));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }
}