#include <stdio.h>

float get_imc_value(float altura, int peso) {
    return peso / (altura * altura);
}

int main() {
    char *names[] = {"Brutus", "Olivia"};
    float alturas[2] = {1.84, 1.76};
    int pesos[2] = {122, 45};
    
    for (int i = 0; i < 2; i++) {
        printf("IMC de %s: %.2f\n", names[i], get_imc_value(alturas[i], pesos[i]));
    }

    return 0;
}
