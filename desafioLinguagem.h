void EscreverDesafioLinguagem() {
    //limpar cmd
    system("cls");

    //lingua
    setlocale(LC_ALL, "portuguese");

    //vaviaveis
    char linguagens[100];
    int quantidade;

    //abrir o arquivo
    FILE *file = fopen("desafiolinguagem.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //logica
    printf("Quantas linguagens de programa��o e ferramentas ser�o adicionadas: ");
    while(scanf("%d", &quantidade) != 1){
        printf("Quantas linguagens de programa��o e ferramentas ser�o adicionadas: ");
        while(getchar() != '\n'); //limpar buffer
    }

    fflush(stdin); //limpar buffer

    for(int i = 0; i < quantidade; i++){
        printf("Digite a linguagem %d: ", i + 1);
        fgets(linguagens, sizeof(linguagens), stdin);
        linguagens[strcspn(linguagens, "\n")] = 0; // Remove o '\n'

        //salvar no arquivo
        fprintf(file, "%s\n", linguagens);
    }  

    //fechar o arquivo
    fclose(file);
    printf("Linguagens salva com sucesso!\n");
}

void MostrarDesafioLinguagem(){
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    //arquivo
    FILE *file = fopen("desafiolinguagem.txt", "r");

    //teste
    if (file == NULL) {
        printf("Nenhuma atividade encontrada.\n");
        return;
    }

    printf("===== Linguagens e Ferramentas =====\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("====================================\n");

    fclose (file);
}

void SortearDesafioLinguagem(){
    setlocale(LC_ALL, "Portuguese");

    //variaveis
    char *linguagens[100];
    char linha[100];
    int contador = 0;

    srand(time(NULL));

    // Niveis pr�-definidos
    char *nivel[] = {"B�sico", "M�dio", "Avan�ado"};
    int tamanhoNivel = sizeof(nivel) / sizeof(nivel[0]);

    // Abrir o arquivo com as linguagens
    FILE *arquivo = fopen("desafiolinguagem.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo 'desafiolinguagem.txt'.\n");
        return;
    }

    // Ler o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Remover o '\n' do final
        linha[strcspn(linha, "\n")] = '\0';

        // Alocar mem�ria e copiar a linha para o array
        linguagens[contador] = malloc(strlen(linha) + 1);
        strcpy(linguagens[contador], linha);
        contador++;

        if (contador >= linguagens) break;
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("Nenhuma linguagem foi encontrada no arquivo.\n");
        return;
    }

    // Sorteio
    int indice = rand() % contador;
    int indiceNivel = rand() % tamanhoNivel;

    printf("Item sorteado: %s\nN�vel: %s\n", linguagens[indice], nivel[indiceNivel]);

    // Liberar mem�ria
    for (int i = 0; i < contador; i++) {
        free(linguagens[i]);
    }
}

void MenuDesafioLinguagem(){
    //limpar cmd
    system("cls");

    char esc;
    while (1) {
        printf("\nMENU\n\t1. Escrever novas linguagens\n\t2. Mostrar todas as linguagens e ferramentas\n\t3. Remover linguagem\n\t4. Sortear atividade\n\t5. Sair\nOp��o: ");
        scanf(" %c", &esc);

        switch (esc) {
            case '1':
                EscreverDesafioLinguagem();
                break;
            case '2':
                MostrarDesafioLinguagem();
                break;
            case '3':
                remover_linha("desafiolinguagem.txt");
                break;
            case '4':
                SortearDesafioLinguagem();
                break;
            case '5':
                printf("%s\n", blue("Saindo do programa..."));
                sleep(1);  // pausa de 2 segundos
                return;//sair
            default:
                printf("%s\n", red("Op��o invalida. Tente novamente."));
                sleep(1);  // pausa de 2 segundos
                break;
        }
    }
}