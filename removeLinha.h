//remove linha
const char* remover_linha(const char* local) {
    char controle[100];//variaveis

    if(strcmp(local , "atividades.txt") == 0){
        strcpy(controle, "ATIVIDADES");
    }else if(strcmp(local, "projeto.txt") == 0){
        strcpy(controle, "PROJETOS");
    }else if(strcmp(local, "trabalho.txt") == 0){
        strcpy(controle, "TRABALHOS");
    }else if(strcmp(local, "desafiolinguagem.txt") == 0){
        strcpy(controle, "LINGUAGENS e FERRAMENTAS");
    }

    FILE *file = fopen(local, "r");
    if (file == NULL) {
        printf("Nenhum arquivo encontrada.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w"); // Arquivo temporario
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(file);
        return;
    }

    char linha[200];
    int numero = 1, excluir;

    printf("===== %s =====\n", controle);
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("======================\n");

    //controle de arquivo, saber se ele possui algo para apagar
    if (numero == 1) { // Arquivo está vazio
        printf("O arquivo está vazio, nada para excluir.\n");
        fclose(file);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    rewind(file); // Volta para o inicio do arquivo

    // Pergunta ao usuário qual atividade excluir
    printf("Digite o número que você deseja excluir: ");
    scanf("%d", &excluir);

    numero = 1;
    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (numero != excluir) {
            fputs(linha, temp); // Copia todas as linhas, exceto a que ser� exclu�da
        }
        numero++;
    }

    fclose(file);
    fclose(temp);

    // Substituir o arquivo original pelo tempor�rio
    remove(local);
    rename("temp.txt", local);

    //converter
    minuscula(controle);

    printf("%s removida com sucesso!\n", controle);
}
