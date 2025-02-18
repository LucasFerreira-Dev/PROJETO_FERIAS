//converter de maiusculo pra minusculo
void minuscula(char *str){
    while(*str){
        *str = tolower(*str);
        str++;
    }
}
