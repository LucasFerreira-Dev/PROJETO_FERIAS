#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//funções cores
const char* red(const char* texto){
    static char color[100];
    snprintf(color, sizeof(color), "\033[31m%s\033[0m",  texto);
    return color;
}

const char* yellow(const char* texto){
    static char color[100];
    snprintf(color, sizeof(color), "\033[33m%s\033[0m",  texto);
    return color;
}

const char* blue(const char* texto){
    static char color[100];
    snprintf(color, sizeof(color), "\033[36m%s\033[0m",  texto);
    return color;
}
//fim das funções cores

// Funções de atividades
void escrever() {
    //limpar cmd
    system("cls");

    //variaveis
    char materia[100];
    char atividade[100];
    char entrega[8];

    printf("Digite a matéria:\n");
    getchar(); // Limpa o buffer antes de leitura
    scanf("%[^\n]", materia);
    getchar(); // Limpa o buffer após leitura
    printf("Digite qual seré a atividade:\n");
    scanf("%[^\n]", atividade);
    getchar(); // Limpa o buffer após leitura
    printf("Digite o dia de entrega:\n");
    scanf("%[^\n]", entrega);
    getchar(); // Limpa o buffer após leitura

    FILE *file;
    file = fopen("atividades.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Matéria: %s Atividade: %s Entrega: %s \n", materia, atividade, entrega);
    fclose(file);
    printf("Atividade salva com sucesso!\n");
}

void tudo() {
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    int numero = 1;

    FILE *file;
    file = fopen("atividades.txt", "r");

    if (file == NULL) {
        printf("Nenhuma atividade encontrada.\n");
        return;
    }

    printf("===== ATIVIDADES =====\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%d - %s", numero, linha);
        numero++;
    }
    printf("======================\n");

    fclose (file);
}

//converter de maiusculo pra minusculo
void minuscula(char *str){
    while(*str){
        *str = tolower(*str);
        str++;
    }
}

const char* remover_linha(const char* local) {
    char controle[100];//variaveis


    if(local == "atividades.txt"){
        strcpy(controle, "ATIVIDADES");
    }else if(local == "projeto.txt"){
        strcpy(controle, "PROJETOS");
    }else if(local == "trabalho.txt"){
        strcpy(controle, "TRABALHOS");
    }

    FILE *file = fopen(local, "r");
    if (file == NULL) {
        printf("Nenhum arquivo encontrada.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w"); // Arquivo temporário
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
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

    //controle so arquivo
    if(linha == NULL){
        //sem funcionar nem adianta
    }else{

    }

    rewind(file); // Volta para o início do arquivo

    // Pergunta ao usuário qual atividade excluir
    printf("Digite o número que você deseja excluir: ");
    scanf("%d", &excluir);

    numero = 1;
    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (numero != excluir) {
            fputs(linha, temp); // Copia todas as linhas, exceto a que será excluída
        }
        numero++;
    }

    fclose(file);
    fclose(temp);

    // Substituir o arquivo original pelo temporário
    remove(local);
    rename("temp.txt", local);

    //converter
    minuscula(controle);

    printf("%s removida com sucesso!\n", controle);
}

void atividade() {
    //limpar cmd
    system("cls");

    char esc;
    while (1) {
        printf("\nMENU\n\t1. Escrever nova atividade\n\t2. Mostrar todas as atividades\n\t3. Remover atividades\n\t4. Sair\nOpção: ");
        scanf(" %c", &esc);

        switch (esc) {
            case '1':
                escrever();
                break;
            case '2':
                tudo();
                break;
            case '3':
                remover_linha("atividades.txt");
                break;
            case '4':
                return;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }
    }
}

// funcoes de trabalhos
void trabalho() {
    //limpar cmd
    system("cls");

    //variaveis
    char trabalho_materia[100];
    char trabalho_tipo[100];
    char trabalho[100];
    char dia[100];

    //entradas
    printf("Digite a matéria do seu trabalho:\n");
    getchar();
    scanf("%[^\n]", trabalho_materia);
    getchar();

    printf("Digite o tipo de trabalho:\n");
    getchar();
    scanf("%[^\n]", trabalho_tipo);
    getchar();

    printf("Digite qual é o assunto do seu trabalho:\n");
    scanf("%[^\n]", trabalho);
    getchar();

    printf("Digite a data do seu trabalho:\n");
    scanf("%[^\n]", dia);
    getchar();

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

void projeto() {
    //limpar cmd
    system("cls");

    printf("%s", yellow("Ainda com erros.\n"));

    //variaveis
    char materia[100];
    char funsao[100];
    char dia[100];

    //entada
    printf("Digite qual é a materia do projeto:\n");
    getchar();//limpar buffe
    scanf("%[ˆ\n]", materia);
    getchar();//limpar buffe
    printf("Digite sua função no projeto:\n");
    scanf("%[ˆ\n]", funsao);
    getchar();//limpar buffe
    printf("Digite o dia de entrega:\n");
    scanf("%[ˆ\n]",dia);
    getchar();//limpar buffe

    //ponteiro
    FILE *file;
    file = fopen("projeto.txt","a");

    //teste
    if(file == NULL){
        printf("Deu zebra\n");
        return;
    }

    //salvar arquivo
   fprintf(file, "Materia %s. Função %s. Dia da entrega: %s\n", materia, funsao, dia);
   printf("Tudo salvo com sucesso\n");

   //fechar arquivo
   fclose(file);
}

void prova() {
    //limpar cmd
    system("cls");

    printf("Função de provas.\n");
}

void mostrar_tudo() {
    //limpar cmd
    system("cls");

    //variaveis
    char linha[200];
    char deque[3][20] = {"ATIVIDADES","TRABALHOS", "PROJETOS"};
    char tipo[3][20]= {"atividades.txt","trabalho.txt","projeto.txt"};
    int numero = 1;

    for(int i = 0; i <= 3; i++){
        //ponteiro
        FILE *file;
        file = fopen(tipo[i], "r");

        if (file == NULL) {
            printf("Nenhum trabalho encontrada.\n");
            return;
        }

        printf("\n============%s=============\n", deque[i]);
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%d - %s", numero, linha);
            numero++;
        }
        printf("\n==================================\n");

        fclose(file);
    }
}

void apagar(){
    //limpar cmd
    system("cls");

    // Variáveis
    char escolha[2];
    char arquivo[20];
    char senha[4];

    printf("Para poder ter acesso primeiro digite a senha:\n");
    scanf("%s", senha);

    if (strcmp(senha, "seuburro") == 0) {
        printf("MENU APAGAR\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Sair\nOpção: ");
        scanf("%1s", escolha);

        // Switch para selecionar a opção
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
                printf("%s" ,red("Opção inválida\n"));
                return;
        }

    }else{
        printf("%s\n", red("Senha incorreta:"));
    }
}

int main() {
    //lingua
    setlocale(LC_ALL, "Portuguese");

    //variaveis
    char escolha;

    while (1) {
        //limpar cmd
        system("cls");

        //menu
        printf("\n==========%s==========", blue("PROJETO_FERIAS"));
        printf("\nMENU PRINCIPAL\n\t1. Atividades\n\t2. Trabalhos\n\t3. Projetos\n\t4. Provas\n\t5. Mostrar tudo\n\t6. Apagar arquivo\n\t7. Salvar num arquivo\n\t8. Sair\nEscolha: ");
        scanf(" %c", &escolha);
        printf("\n==================================\n");

        switch (escolha) {
            case '1':
                atividade();
                break;
            case '2':
                menu_trabalho();
                break;
            case '3':
                projeto();
                break;
            case '4':
                prova();
                break;
            case '5':
                mostrar_tudo();
                break;
            case '6':
                apagar();
                break;
            case '7':
                break;
            case '8':
                printf("%s\n", blue("Saindo do programa..."));
                exit(0);
            default:
                printf("%s\n", red("Opção invalida. Tente novamente."));
                break;
        }
    }

    return 0;
}
