#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para converter placa para minúsculas
char* toLowerCasePlaca(char placa[]) {
    for (int i = 0; i < strlen(placa); i++) {
        placa[i] = tolower(placa[i]);
    }
    return placa;
}

int main() {
    char placa[10];
    char dia[20];

    // Leitura da placa e do dia da semana
    scanf("%s %s", placa, dia);

    // Convertendo a placa para minúsculas

    // Verificação do formato da placa
    int formatoInvalido = 0;
    if (strlen(placa) == 8) {
        if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2]) || placa[3]!='-' || !isdigit(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6]) || !isdigit(placa[7])) {
            formatoInvalido = 1;
        }
    } else if (strlen(placa) == 7) {
        if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2]) || !isdigit(placa[3]) || !isalpha(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6])) {
            formatoInvalido = 1;
        }
    } else {
        formatoInvalido = 1;
    }

    // Verificação do formato do dia da semana
    int diaInvalido = 0;
    if (strcmp(dia, "SEGUNDA-FEIRA") != 0 && strcmp(dia, "TERCA-FEIRA") != 0 && strcmp(dia, "QUARTA-FEIRA") != 0 && strcmp(dia, "QUINTA-FEIRA") != 0 && strcmp(dia, "SEXTA-FEIRA") != 0 && strcmp(dia, "SABADO") != 0 && strcmp(dia, "DOMINGO") != 0) {
        diaInvalido = 1;
    }

    // Verificação e saída conforme as regras
    if (formatoInvalido) {
        printf("Placa invalida\n");
    } if (diaInvalido) {
        printf("Dia da semana invalido\n");
    } 
    if(!formatoInvalido && !diaInvalido) {
        int ultimoDigito = placa[strlen(placa) - 1] - '0';

        if ((strcmp(dia, "SEGUNDA-FEIRA") == 0 && (ultimoDigito == 0 || ultimoDigito == 1)) ||
            (strcmp(dia, "TERCA-FEIRA") == 0 && (ultimoDigito == 2 || ultimoDigito == 3)) ||
            (strcmp(dia, "QUARTA-FEIRA") == 0 && (ultimoDigito == 4 || ultimoDigito == 5)) ||
            (strcmp(dia, "QUINTA-FEIRA") == 0 && (ultimoDigito == 6 || ultimoDigito == 7)) ||
            (strcmp(dia, "SEXTA-FEIRA") == 0 && (ultimoDigito == 8 || ultimoDigito == 9))) {
            printf("%s nao pode circular %s\n", placa, toLowerCasePlaca(dia));
        } else if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0) {
            printf("Nao ha proibicao no fim de semana\n");
        } else {
            printf("%s pode circular %s\n", placa, toLowerCasePlaca(dia));
        }
    }

    return 0; 
}
