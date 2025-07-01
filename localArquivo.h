const char* Procurar_Arquivo(const char* arquivo, const char* nome_arquivo) {
    //variaveis
    static char arquivo_procura[200];  // precisa ser static para não sumir após a função retornar

    //iniciar ponteiro file
    FILE *file = fopen(arquivo, "r");

    //se o arquivo existir retorna o arquivo
    if (file != NULL) {
        fclose(file);
        return arquivo;
    }

    //resalvar em outra variavel
    snprintf(arquivo_procura, sizeof(arquivo_procura), "output/%s", arquivo);

    //iniciar ponteiro file
    file = fopen(arquivo_procura, "r");

    //se arquivo_procura for null mostrar que nao existe
    if (file == NULL) {
        printf("Nenhum(a) %s encontrado(a).\n", nome_arquivo);
        sleep(2);
        return NULL;
    }

    //fechar ponteiro
    fclose(file);

    //retorna arquivo_procura
    return arquivo_procura;
}