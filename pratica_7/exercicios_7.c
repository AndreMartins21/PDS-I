#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define len(x)  (sizeof(x) / sizeof((x)[0]))

int get_random_int(int n_max){
    return rand()%(n_max+1);
}

void get_random_int_vector(int V[], int n){
    int i;
    for(i=0; i< n; i++){
        V[i] = get_random_int(365);
    }
}

float get_dot_product(float u[], float v[], int n){
    int i, sum_dot_product = 0;
    for (i=0; i<n; i++){
        sum_dot_product += u[i]*v[i];
    }
    return sum_dot_product;
}

void run_exercicio_1(){
    float u[] = {1.0, 2.0};
    float v[] = {3.0, 2.0};
    printf("\nget_dot_product: %f", get_dot_product(u, v, 2));
}

long double get_fib_seq(int n){
    long double fib[1000];
    int i;    
    fib[0] = 1;
    fib[1] = 1;
    
    for(i=2; i<n;i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    return fib[n-1];
}

void run_exercicio_2(){
    int number;
    
    while (1){
        printf("\nDigite um número entre 0 e 1000 (Ou neg pra sair): ");
        scanf("%d", &number);
        
        if(number < 0 || number > 1000){
            printf("\nExecução finalizada!");
          break;  
        } 
        
        printf("\nfib(%d) -> %Lf", number, get_fib_seq(number));
    }
}

float get_avg(float vector[], int n){
    int i, sum_values=0;
    for (i=0; i<n; i++){
        sum_values += vector[i];
    }
    return sum_values / n;
}

void run_exercicio_3(){
    float notas[5] = {1, 2, 3, 4, 5};
    printf("avg_notas => %lf", get_avg(notas, 5));
}

void merge_vectors(int X[], int Y[], int Z[]){
    int i;
    for (i = 0; i < 10; i++) {
        Z[2 * i] = X[i];      // Par
        Z[2 * i + 1] = Y[i];  // Impar
    }
}

void run_exercicio_4(){
    int i, X[10], Y[10], Z[20];
    for(i=0; i<10; i++){
        X[i] = get_random_int(100);
        Y[i] = get_random_int(100);
    }

    merge_vectors(X, Y, &Z);
    
    printf("\nValores de Z:");
    for (i = 0; i < 20; i++) {
        printf("%d ", Z[i]);
    }
}

void get_inverse_vector(int X[], int INV_X[], int tam_x){
    int i;
    tam_x --;
    
    for(i = tam_x; i >=0; i--){
        INV_X[tam_x - i] = X[i];
    }
}


void run_exercicio_5(){
    int V[15], INV_V[15], i;
    
    get_random_int_vector(&V, len(V));
    // printf("LEN(V): %d", len(V));
    get_inverse_vector(V, &INV_V, len(V));   
    
    printf("\nVETOR V: ");
    for(i=0; i<15; i++){
        printf("%d ", V[i]);
    }
    
    printf("\nVETOR INV_V: ");
    for(i=0; i<15; i++){
        printf("%d ", INV_V[i]);
    }
}

void run_exercicio_6(){
    int v1[60], v2[60], union_v[120], i;
    get_random_int_vector(v1, 60);
    get_random_int_vector(v2, 60);
    
    for(i = 0; i<60; i++){
        union_v[i] = v1[i];
        union_v[i+60] = v2[i];
    }
    
    printf("\nVetores juntos: ");
    for(i = 0; i<120; i++){
        printf("%d, ", union_v[i]);
    }
}

float get_desvio_padrao(int freq_v[]){
    float mean = get_avg(freq_v, 1000), sum = 0;
    float variancia, desvio;
    int i;
    
    for(i=0; i<1000; i++){
        sum += pow((freq_v[i] - mean), 2);
    }
    variancia = sum / 1000;
    desvio = sqrt(variancia);
    printf("\nVariância: %lf \nDesvio Padrão: %lf", variancia, desvio);
    return desvio;
}

void run_exercicio_7(){
    int vetor_freq[1000] = {0}, QTD = 5000000;
    int i, random_n;
    
    for(i=0; i<QTD; i++){
        random_n = get_random_int(1000); 
        // printf("%d, ", random_n);
        vetor_freq[random_n]++;
    }
    
    printf("\nFrequência: \n");
    int qtd, idx_max, idx_min, max = 0, min = QTD;
    
    for(i=0; i<1000; i++){
        // printf("%i -> %d \n", i, qtd_vezes[i]);
        qtd = vetor_freq[i];
        if (qtd > max){
            idx_max = i; 
            max = qtd;
        }
        if (qtd < min){
            idx_min = i;
            min = qtd;
        }
    }
    printf("\nMÁXIMO: (%d) => %d", idx_max, max);
    printf("\nMÍNIMO: (%d) => %d", idx_min, min);
    get_desvio_padrao(vetor_freq);
}



void main() {
    srand(time(NULL));
    
    // run_exercicio_1();
    // run_exercicio_2();
    // run_exercicio_3();
    // run_exercicio_4();
    // run_exercicio_5();
    // run_exercicio_6();
    run_exercicio_7();
}
