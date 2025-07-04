void salvar() {
    //limpar cmd
    system("cls");

    //variaveis
    bool mensagem = true;
    char linha[1000];
    char deque[5][20] = {"ATIVIDADES","TRABALHOS", "PROJETOS", "PROVAS", "DESAFIOS"};

    //controle do arquivo
    char local[5][22] = {"atividades.txt","trabalho.txt","projeto.txt","prova.txt","desafiolinguagem.txt"};
    char local_novo[5][40] = {
        "output/atividades.txt",
        "output/trabalho.txt",
        "output/projeto.txt",
        "output/prova.txt",
        "output/desafiolinguagem.txt"
    };

    //controle do arquivo
        char tipo[] = "r";
        bool erro = false; //controle em que array de char ele esta
        int numero = 1;

    for(int i = 0; i < 5; i++){
        //variaveis de controle de arquivo
        char conteudo[1000] = ""; // para juntar tudo
        char localCopy[1000] = "copy_";

        FILE *file;
        
        file = fopen(local[i], tipo);

        if(file == NULL) {
            erro = true;
            file = fopen(local_novo[i], tipo);

            if (file == NULL) {
                printf("Nenhum(a) %s encontrado(a).\n", deque[i]);
                sleep(2);
                continue;
            }
        }

        if(mensagem){
            printf("Salvando as informações\n");
            mensagem = false;
        }

        printf("\n===== %s =====\n", deque[i]);
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%d - %s", numero, linha);
            strcat(conteudo, linha); // adiciona ao buffer final
            numero++;
        }
        printf("======================\n");
        
        fclose(file);//fechar ponteiro antes de reabrir

        // Corrige: pega só o nome do arquivo, sem caminho
        const char *filename = strrchr(local[i], '/');
        if (!filename) filename = strrchr(local[i], '\\');
        filename = filename ? filename + 1 : local[i];
        strcat(localCopy, filename);

        file = fopen(localCopy, "w");
	
        if(file == NULL){
            printf("Erro ao abrir o arquivo.\n");
            continue;
        }
        
        fprintf(file,"%s",conteudo); //salvar no arquivo

        //fechar ponteiro
        fclose (file);
    }
}

void recuperar() {
    char pergunta;
    char arquivo[100] = "";
    char arquivoRecupera[100] = "";
    char linha[100];
    char deque[100] = "";
    int numero = 1;
    char conteudo[1000] = ""; // para juntar tudo

    //pergunta
    printf("Escolha o arquivo que você deseja recuperar:\n");
    printf("\nArquivos\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Arquivo do sorteio atividade\n\t6. Voltar\nEscolha: ");
    
    scanf(" %c", &pergunta);  //entrada

    switch (pergunta) { //controle
        case '1':
        strcat(deque, "ATIVIDADES");
            strcat(arquivo, "copy_atividades.txt");
            strcat(arquivoRecupera, "atividades.txt");
            break;
        case '2':
            strcat(deque, "TRABALHOS");
            strcat(arquivo, "copy_trabalho.txt");
            strcat(arquivoRecupera, "trabalho.txt");
            break;
        case '3':
            strcat(deque, "PROJETOS");
            strcat(arquivo, "copy_projeto.txt");
            strcat(arquivoRecupera, "projeto.txt");
            break;
        case '4':
            strcat(deque, "PROVAS");
            strcat(arquivo, "copy_prova.txt");
            strcat(arquivoRecupera, "prova.txt");
            break;
        case '5':
            strcat(deque, "DESAFIOS");
            strcat(arquivo, "copy_desafiolinguagem.txt");
            strcat(arquivoRecupera, "desafiolinguagem.txt");
            break;
        case '6':
            return;
            break;
        default:
            printf("Opção inválida\n");
            return;
    }

    //abrir ponteiro
    FILE *file = fopen(arquivo, "r");

    if (file == NULL) { //verficação
        printf("Erro ao abrir arquivo, ou arquivo inexistente\n");
        exit(1);
    }

    //vai pergar o que tiver e mostrar
    printf("\n===== %s =====\n", deque);
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        strcat(conteudo, linha); // adiciona ao buffer final
        numero++;
    }
    printf("======================\n");
        
    fclose(file);//fechar ponteiro antes de reabrir


    file = fopen(arquivoRecupera, "w");
	
    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
        
    fprintf(file,"%s",conteudo); //salvar no arquivo

    if (ferror(file)) {
        printf("Erro ao escrever no arquivo!\n");
    } else {
        printf("Arquivo recuperado e salvo com sucesso!\n");
    }

    //fechar ponteiro
    fclose (file);
}