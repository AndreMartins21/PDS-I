#include <stdio.h>
#include <math.h>
#include <string.h>

int MAX_LENGTH_STRING = 10000;

int get_fatorial(int n){
	if(n < 1){
		return 1;
	}
    return n*get_fatorial(n-1);
}	

// Exercício 1: Número de Euler
float get_euler_number(){
    float div, soma = 0.0;
    int i = 0;
    
    while (1){
        div = 1.0/get_fatorial(i);

        if (div < pow(10, -6)) break;
        soma += div;
        i++;
    }
    return soma;
}


//Exercício 2: Calculador de conceito
char get_concept(){
    int score;
    scanf("%d", &score);

    if (score <= 4) return 'F';

    switch(score){
        case 5:
            return 'E';
        case 6:
            return 'D';
        case 7:
            return 'C';
        case 8:
            return 'B';
        default:
            return 'A';
    }
}

// Exercício 3: Triângulo de Floyd
void print_floyd_triangle(int N){
    int line, column, s = 1;

    for(line=1; line<=N; line++){
        for(column=1;column<=line; column++){
            printf("%d ", s);
            s++;
        }
        printf("\n");
    }
}


// Exercicio 3: Desafio
void print_specific_line_floyd_triangle(int N){
    int i, first_value = (((N-1)*N)/2)+1;

    printf("\n");
    for(i=0; i<N;i++){
        printf("%d ", first_value+i);
    }
    printf("\n");
}



// Exercício 4: Tamanho de uma string
int get_len_string(){
    int i;
    char line[MAX_LENGTH_STRING];
    
    printf("Type a line:\n");
    fgets(line, MAX_LENGTH_STRING, stdin);
    
    printf("\n=> Qtd esperada: %zu \n",strlen(line)-1);

    for (i=0;i<=MAX_LENGTH_STRING;i++){
        if(line[i]=='\0'){
            break;
        }
    }

    return i-1;
}


//Exercício 5: Conversão de caixa
void convert_lower_to_upper(){
    char line[MAX_LENGTH_STRING];
    int i;

    printf("Type a line:\n");
    fgets(line, MAX_LENGTH_STRING, stdin);

    for(i=0; i<strlen(line)-1;i++){
        int v = (int)line[i];

        if(v >=97 && v <= 122){
            line[i] = (char)v-32;    
        }
    }
    printf("\nnew_line: %s", line);
}


//Exercício 6: Detector de palíndromos
void remove_space(char *string) {
    int count = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ' ') {
            string[count++] = string[i];
        }
    }
    string[count] = '\0';
}


void convert_lower_to_upper_parameter(char *string){
    int i, length_str = strlen(string);

    for(i=0; i<length_str;i++){
        int v = (int)string[i];

        if(v >=97 && v <= 122){
            string[i] = (char)v-32;    
        }
    }
    string[length_str] = '\0';
}


int is_palindrome(char *string){
    /*
    Ex:
    char string[] = "subi no onibus";
    int string_is_palindrome = is_palindrome(string);
    printf("\nIs palindrome: %d\n", string_is_palindrome);
    */
    remove_space(string);
    convert_lower_to_upper_parameter(string);

    
    int left = 0;
    int right = strlen(string)-1;

    while (left < right){
        if (string[left] != string[right]){
            return 0;
        }
        left ++;
        right --;
    }
    return 1;
}


//Exercício 7: Inversão de string
void get_reverse_string(){
    char texto[1000]; // Supomos que o texto terá no máximo 1000 caracteres
    char caractere;
    int tamanho = 0;

    printf("Digite um texto terminando com um ponto final: ");

    // Lê um caractere por vez até encontrar um ponto final
    do {
        caractere = getc(stdin);
        texto[tamanho] = caractere;
        tamanho++;
    } while (caractere != '.');

    // Imprime o texto invertido
    printf("Texto invertido: ");
    for (int i = tamanho - 2; i >= 0; i--) {
        printf("%c", texto[i]);
    }
    printf("\n");
}


//Exercício 8: Abreviação de nome
void get_name_abbreviation(){
    char caractere, texto[10000];
    int i_text = 0, i_abbrevia = 0;
    char abbreviation[100];

    // 65 ao 90

    do {
        caractere = getc(stdin);

        int c_ascii = caractere;
        if (c_ascii >= 65 && c_ascii <= 90){
            abbreviation[i_abbrevia] = caractere;
            i_abbrevia ++;
        }

        texto[i_text] = caractere;
        i_text++;
    } while(caractere != '.');

    printf("\nString = %s", texto);
    printf("\nAbbreviation = %s\n", abbreviation);
}


void main(){
    // Ex 1
    // printf("\nEuler aproximado: %f\n", get_euler_number());

    // Ex 2:
    // printf("\n%c\n", get_concept());

    // Ex 3:
    // print_specific_line_floyd_triangle(7);
    
    // Ex 4:
    // printf("\nQtd carácteres: %d\n", get_len_string());

    // Ex 5:
    // convert_lower_to_upper();

    // Ex 6:
    // char string[] = "subi no onibus"; 
    // printf("\nIs palindrome: %d\n", is_palindrome(string));

    // Ex 7:
    // get_reverse_string();

    // Ex 8:
    get_name_abbreviation();

}


