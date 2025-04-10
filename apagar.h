void apagar(){
    //limpar cmd
    system("cls");

    // Variaveis
    char escolha[2];
    char arquivo[20];
    char senha[4];

    printf("%s",blue("Mensagem:\nTudo ja pronto:\n"));
    printf("Para poder ter acesso primeiro digite a senha:\n");
    scanf("%s", senha);

    if (strcmp(senha, "seuburro") == 0) {
        printf("MENU APAGAR\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Sair\nOp��o: ");
        scanf("%1s", escolha);

        // Switch para selecionar a opçãoo
        switch (escolha[0]) {
            case '1':
                if(remove("atividades.txt") == 0){
                    printf("Arquivo apagado com suceso.\ n");
                }else{
                    printf("Erro ao apagar.\n");
                    break;
                }
            case '2':
                if(remove("trabalho.txt") == 0){
                    printf("Arquivo apagado com suceso.\ n");
                }else{
                    printf("Erro ao apagar.\n");
                    break;
                }
            case '3':
                if(remove("projeto.txt") == 0){
                    printf("Arquivo apagado com suceso.\ n");
                }else{
                    printf("Erro ao apagar.\n");
                    break;
                }
            case '4':
                printf("%s\n", blue("Saindo..."));
                return ;
            default:
                printf("%s" ,red("Opçãoo invalida\n"));
                return;
        }

    }else{
        printf("%s\n", red("Senha incorreta:"));
    }
}
