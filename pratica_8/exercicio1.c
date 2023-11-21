#include <stdio.h>
#include <time.h>

#define MAX_M 100
#define MAX_N 100


void create_copy_matriz(int M_origem[][MAX_N], int M_copia[][MAX_N], int m, int n){
    int i, j;
    for (i = 0; i<m; i++){
        for(j=0; j<n; j++){
            M_copia[i][j] = M_origem[i][j];
        }
    }
}

void fill_matriz(int matriz[][MAX_N], int m, int n, int k){
    int line, col;
    for(line=0; line<m; line++){
        for(col=0; col<n; col++){
            matriz[line][col] = 1+rand()%k;
        }
    }
} 


void print_matriz(int matriz[][MAX_N], int m, int n){
    int line, col;
    for(line=0; line<m; line++){
        for(col=0; col<n; col++){
            printf("%d ", matriz[line][col]);
        }
        printf("\n");
    }
}

void fill_zero_on_lines(int matriz[][MAX_N], int line, int col, int count){
    int i;
    
    if (count > 3) matriz[line][col] = 0;
    
    if (count == 3){
        /*
        Val = (1 0 0 2 2 2)
        Pos = (0 1 2 3 4 5)
        */
        for(i=col-2; i<=col; i++){
            matriz[line][i] = 0;   
        }
    }
}

void fill_zero_on_columns(int matriz[][MAX_N], int line, int col, int count){
    int i;
    if (count > 3) matriz[line][col] = 0;
    
    if (count == 3){
        /*
        Val = (2   [0]
               1   [1]
               1   [2]
               1   [3]
               0   [4])
        */
        for(i=line-2; i<=line; i++){
            matriz[i][col] = 0;   
        }
    }
}


void find_sequences_and_fill_zero(int matriz[][MAX_N], int m, int n){
    int line, col, v_matriz = 0, aux_v=0, count=0;
    int new_matriz[MAX_M][MAX_N];
    create_copy_matriz(matriz, new_matriz, m, n);

    // Iterando em cada valor de linha
    for(line =0; line < m; line++){
        aux_v = 0;
        for(col = 0; col < n; col++){
            v_matriz = matriz[line][col];
            
            if(aux_v == v_matriz){
                count++;
                fill_zero_on_lines(matriz, line, col, count);
            } else {
                count=1;
                aux_v = v_matriz;
            }
        }
    }
    
    // Iterando em cada valor de coluna
    for(col=0; col<n; col++){
        aux_v = 0;
        for(line=0; line<m; line++){
            v_matriz = new_matriz[line][col];
    
            if(aux_v == v_matriz){
                count++;
                fill_zero_on_columns(matriz, line, col, count);
            } else {
                count=1;
                aux_v = v_matriz;
            }
        }
    }
    
    
    printf("\nFinalizou! Nova matriz gerada:\n");
    print_matriz(matriz, m, n);
}


void print_count_zeros(int matriz[][MAX_N], int m, int n){
    int line, col, count_zero=0;
    for(line=0; line<m; line++){
        for(col=0; col<n; col++){
            if (matriz[line][col] == 0) count_zero++;
        }
    }
    printf("Quantidade de zeros: %d", count_zero);
}

void main() {
    //--------------------------    
    // 1.1
    //--------------------------
    int m=101, n=101, k, i;
    int matriz[MAX_M][MAX_N];
    
    while (m > 100 || n > 100){
        printf("\nDigite a qtd de linhas, colunas e o valor maximo (m, n < 100): \n");
        scanf("%d %d %d", &m, &n, &k);
    }
    
    srand(time(NULL));
    fill_matriz(matriz, m, n, k);
    print_matriz(matriz, m, n);
    
    
    //--------------------------    
    // 1.2
    //--------------------------
    find_sequences_and_fill_zero(matriz, m, n);
    
    //--------------------------    
    // 1.3
    //--------------------------
    print_count_zeros(matriz, m, n);
    
    //--------------------------    
    // 1.4
    //--------------------------
    put_zero_above_all
}
