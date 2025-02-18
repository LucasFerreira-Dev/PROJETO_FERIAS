//fuções de projetos
void projeto() {
    //limpar cmd
    system("cls");

    printf("%s", yellow("Ainda com erros.\nFalta fazer o mostrar menu\nApagar projeto\n"));

    //variaveis
    char lider[100];
    char materia[100];
    char funsao[100];
    char dia[100];

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
