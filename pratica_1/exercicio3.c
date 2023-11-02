#include <stdio.h>

int main() {
    // Saldo inicial
    float saldo = 789.54;
    
    // Taxa de juros mensal
    float taxa_juros = 0.56 / 100;

    // Depósito no segundo mês
    saldo += 303.20;

    // Retirada no terceiro mês
    saldo -= 58.25;

    // Calcula o saldo no quarto mês com os juros
    saldo *= (1 + taxa_juros);  // Mês 1
    saldo *= (1 + taxa_juros);  // Mês 2
    saldo *= (1 + taxa_juros);  // Mês 3
    saldo *= (1 + taxa_juros);  // Mês 4

    printf("Saldo no quarto mês: R$%.2f\n", saldo);

    return 0;
}
