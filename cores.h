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
