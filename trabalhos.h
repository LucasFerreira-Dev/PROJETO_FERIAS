// funcoes de trabalhos
void trabalho() {
    //limpar cmd
    system("cls");

    //variaveis
    char trabalho_materia[1000];
    char trabalho_tipo[1000];
    char trabalho[1000];
    char dia[1000];

    //entradas
    printf("Digite a matéria do seu trabalho:\n");
    fflush(stdin);//limpar buffer
    fgets(trabalho_materia, sizeof(trabalho_materia), stdin);
    trabalho_materia[strcspn(trabalho_materia, "\n")] = 0; //remove o \n

    printf("Digite o tipo de trabalho:\n");
    fgets(trabalho_tipo, sizeof(trabalho_tipo), stdin);
    trabalho_tipo[strcspn(trabalho_tipo, "\n")] = 0; //remove o \n

    printf("Digite qual é o assunto do seu trabalho:\n");
    fgets(trabalho, sizeof(trabalho), stdin);
    trabalho[strcspn(trabalho, "\n")] = 0; //remove o \n

    printf("Digite a data do seu trabalho:\n");
    fgets(dia, sizeof(dia), stdin);
    dia[strcspn(dia, "\n")] = 0; //remove o \name

    //ponteiro
    FILE *file;
    file = fopen("trabalho.txt", "a");

    //teste
    if(file == NULL){
        printf("Deu zebra");
        return;
    }

    //salvar no arquivo
    fprintf(file, "Materia: %s. Tipo: %s. Assunto: %s. Data de entrega: %s\n",trabalho_materia, trabalho_tipo, trabalho, dia);

    //fechar arquivo
    fclose(file);
}

void mostrar_trabalho(){
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    FILE *file;
    file = fopen("trabalho.txt", "r");

    if (file == NULL) {
        printf("Nenhum trabalho encontrada.\n");
        return;
    }

    printf("\n============TRABALHOS=============\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("\n==================================\n");

    fclose(file);
}

void menu_trabalho(){
    //limpar cmd
    system("cls");

    //lingua
    setlocale(0, "portuguese");

    //variaveis
    char esc;

    while (1) {
        printf("%s",blue("Mensagem:\nTudo ja pronto:\n"));
    	printf("\n==========MENU DO TRABALHO==========");
        printf("\nMENU\n\t1. Escrever novo trabalho\n\t2. Mostrar todos os trabalhos\n\t3. Remover trabalho\n\t4. Sair\nOpção: ");
        scanf(" %c", &esc);
        printf("\n====================================\n");

        switch (esc) {
            case '1':
                trabalho();
                break;
            case '2':
                mostrar_trabalho();
                break;
            case '3':
                remover_linha("trabalho.txt");
                break;
            case '4':
                return;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }
    }
}
