#include <stdio.h>

int romanoParaDecimal(char romano) {
    switch (romano) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

void decimalParaBinario(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binario[10];
    int i = 0;

    // Converte decimal para binário
    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    // Imprime a representação binária
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}

int main() {
    char numeroRomano[13];

    // Lê o número romano da entrada
    scanf("%s", numeroRomano);

    // Converte o número romano para decimal
    int decimal = 0;
    for (int i = 0; numeroRomano[i] != '\0'; i++) {
        if (romanoParaDecimal(numeroRomano[i]) < romanoParaDecimal(numeroRomano[i + 1])) {
            decimal -= romanoParaDecimal(numeroRomano[i]);
        } else {
            decimal += romanoParaDecimal(numeroRomano[i]);
        }
    }

    // Imprime a representação binária
    printf("%s na base 2: ", numeroRomano);
    decimalParaBinario(decimal);
    printf("\n");

    // Imprime a representação decimal
    printf("%s na base 10: %d\n", numeroRomano, decimal);

    // Imprime a representação hexadecimal
    printf("%s na base 16: %x\n", numeroRomano, decimal);

    return 0;
}
