void Apagar(){
    //limpar cmd
    system("cls");

    // Variaveis
    char escolha[2];
    char senha[20];

    printf("Para poder ter acesso primeiro digite a senha:\n");
    scanf("%19s", senha);

    if (strcmp(senha, "seuburro") == 0) {
        printf("MENU APAGAR\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Sair\nOpção: ");
        scanf("%1s", escolha);

        // Switch para selecionar a opção
        switch (escolha[0]) {
            case '1':
                if(remove("atividades.txt") == 0){
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 1 segundos
                break;
            case '2':
                if(remove("trabalho.txt") == 0) {
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 1 segundos
                break;
            case '3':
                if(remove("projeto.txt") == 0){
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 1 segundos
                break;
            case '4':
                if(remove("prova.txt") == 0){
                    printf("Arquivo apagado com suceso.\n");
                } else {
                    printf("Erro ao apagar.\n");
                }
                //controle
                sleep(1);  // pausa de 1 segundos
                break;
            case '5':
                printf("%s\n", blue("Saindo..."));
                sleep(1);  // pausa de 1 segundos
                return ;
            default:
                printf("%s" ,red("Opção invalida\n"));
                sleep(1);  // pausa de 1 segundos
                return;
        }
    } else {
        printf("%s\n", red("Senha incorreta"));
        sleep(1);
    }
}