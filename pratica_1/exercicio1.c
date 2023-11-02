#include <stdio.h>

void convert_char_to_ascii(char char_to_convert[]){
    printf("Código ASCII para o nome %s: \n", char_to_convert);

    for(int i = 0; char_to_convert[i] != '\0'; i++){
        printf("%d ", char_to_convert[i]);
    }
    printf("\n");
}


void main(){
	char first_name[] = "Andre";

    convert_char_to_ascii(first_name);
    
}