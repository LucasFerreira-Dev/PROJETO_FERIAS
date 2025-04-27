void apagar(){
    //limpar cmd
    system("cls");

    //mensagem
    printf("%s", yellow("Irei fazer uma manutencao preventiva\n"));

    // Variaveis
    char escolha[2];
    char arquivo[20];
    char senha[4];

    printf("%s",blue("Mensagem:\nTudo ja pronto:\n"));
    printf("Para poder ter acesso primeiro digite a senha:\n");
    scanf("%s", senha);

    if (strcmp(senha, "seuburro") == 0) {
        printf("MENU APAGAR\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Sair\nOpção: ");
        scanf("%1s", escolha);

        // Switch para selecionar a opçãoo
        switch (escolha[0]) {
            case '1':
                if(remove("atividades.txt") == 0){
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 2 segundos
                break;
            case '2':
                if(remove("trabalho.txt") == 0) {
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 2 segundos
                break;
            case '3':
                if(remove("projeto.txt") == 0){
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 2 segundos
                break;
            case '4':
                if(remove("prova.txt") == 0){
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 2 segundos
                break;
            case '5':
                printf("%s\n", blue("Saindo..."));
                sleep(1);  // pausa de 2 segundos
                return ;
            default:
                printf("%s" ,red("Opção invalida\n"));
                sleep(1);  // pausa de 2 segundos
                return;
        }
    }else{
        printf("%s\n", red("Senha incorreta:"));
    }
}
