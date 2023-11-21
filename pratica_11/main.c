#include <stdio.h>


void swap_values(int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}


void print_seq(int *v){
    int i;
    for(i = 0; i<6; i++){
        printf("%d ", v[i]);
    }
}

void bubble_sort(int *v, int n){
    int i, j;
    
    for(i=0; i < n-1; i++){   
        for(j=0; j < n-i; j++){
            if (v[j] > v[j+1]){
                swap_values(&v[j], &v[j+1]);
            }
        }
    }
}

void check_count_ok(int seq[], int *count_4, int *count_5, int *count_6, int count_seq){
    int i, j, count_ok = 0;
    int seq_winner[6] = {6, 9, 22, 23, 48, 52};
    
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if(seq[i] == seq_winner[j]){
                count_ok++;
        }
        }
    }
    if (count_ok < 4) return;
        
    switch (count_ok){
        case 4:
            (*count_4)++;
            break;
        case 5:
            (*count_5)++;
            break;
        case 6:
            (*count_6)++;
            break;
    }
}

int check_is_lost(int seq[], int count_seq){
    int i, count_ok = 0;
    int seq_winner[6] = {4, 8, 15, 16, 23, 42};

    for(i=0; i<6; i++){
        if(seq[i] == seq_winner[i]){
            count_ok++;
        }
    }
    
    if(count_ok == 6){
        // printf("\nJogador n° %d apostou no seriado Lost!", count_seq);
        return 1;
    }
    return 0;
}


void main(){
    FILE *f;

    f = fopen("cartelas.txt", "r");

    int n, i, count_seq = 1, seq[6];
    int count_winners_6 = 0, count_winners_5 = 0, count_winners_4 = 0, count_lost = 0;
    
    // feof(f) => Check whether the file pointer to a stream is pointing to the of the "cartelas.txt"
    while(!(feof(f))){
        
        for(i=0; i<6; i++){
            fscanf(f, "%d", &n);
            seq[i] = n;
        }
        bubble_sort(seq, 6);

        check_count_ok(seq, &count_winners_4, &count_winners_5, &count_winners_6, count_seq);

        count_lost += check_is_lost(seq, count_seq);
        
        count_seq++;
    }

    printf("\n\nTotal de ganhadores (6 números) => %d", count_winners_6);
    printf("\n\nTotal de ganhadores (5 números) => %d", count_winners_5);
    printf("\n\nTotal de ganhadores (4 números) => %d", count_winners_4);
    printf("\n\nTotal de Lost => %d\n", count_lost);

    fclose(f);
}
