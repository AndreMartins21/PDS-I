#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>


#define MAX_TAM 100


// Aux functions:
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n');
}


void replaceString(char *str, char *target, char *replacement) {
    char *pos = strstr(str, target);

    // Check if the target substring is found in the string
    if (pos != NULL) {
        size_t targetLen = strlen(target);
        size_t replacementLen = strlen(replacement);

        // Shift the remaining characters to make room for the replacement
        memmove(pos + replacementLen, pos + targetLen, strlen(pos + targetLen) + 1);

        // Copy the replacement string into the position of the target substring
        memcpy(pos, replacement, replacementLen);
    }
}


void modificarNotas(char nome_arquivo[]) {
	int num=-1, num_edit;
	char* nome;
	char buf[MAX_TAM];	
	float nota1, nota2;
	FILE *arq, *temp;
	int achei=0;

	//abrir arquivo nome_arquivo para leitura o colocando na variavel arq:
	arq = fopen(nome_arquivo, "r");
	
	//verificar se arquivo foi aberto corretamente e retornar (return) caso negativo:
	if(arq == NULL){
		printf("\nArquivo %s não encontrado!", nome_arquivo);
		return;
	}
	
	
	printf("\nDigite o numero do aluno a modificar: ");
	scanf("%d", &num_edit);
	
	printf("\nProcurando...");
	
	//abrir um arquivo temporario "temp" (ex: temp.txt) para escrita o colocando na variavel temp:
	temp = fopen("temp.txt", "a");
	
	fgets(buf, MAX_TAM, arq);
	while(!feof(arq)) {
		//ler os quatro campos do arquivo: "num", "nome", "nota1", "nota2":
		num = atoi(strtok(buf, ","));
		nome = strtok(NULL, ",");
		nota1 = atof(strtok(NULL, ","));
		nota2 = atof(strtok(NULL, ","));
		
		//verificar se "num" eh igual a "num_edit":
		if(num == num_edit){
			//se for igual, ler as novas notas (nota1 e nota2) do aluno e marcar que achou o aluno ("achei = 1"):
			achei = 1;
			printf("\nNova Nota1: ");
			scanf("%f", &nota1);
			printf("\nNova Nota2: ");
			scanf("%f", &nota2);	
		}
			
		//escrever os dados lidos do arquivo "nome_arquivo" no arquivo temporario
		fprintf(temp, "%d,%s,%4.1f,%4.1f\n", num, nome, nota1, nota2);
		
		//ler uma nova linha do arquivo nome_arquivo:
		fgets(buf, MAX_TAM, arq);
	}
	
	fclose(arq);
	fclose(temp);
	
	if(achei == 0)
		printf("\nAluno nao encontrado!");
	else{ 
		//remove o arquivo antigo
		remove(nome_arquivo);
		//renomeia o arquivo temporario
		rename("temp.txt", nome_arquivo);
	}
}

void leAluno(char nome_arquivo[], int num_alunos) {
	int num, i;
	char nome[100];
	float nota1, nota2;
	FILE *arq;
	arq = fopen(nome_arquivo,"a");
	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!");
		getch();
		return;
	}

	for(i=0; i<num_alunos; i++){
		printf("\nDigite os dados do novo aluno");
		printf("\nNum: ");
		scanf("%d", &num);
		
		printf("\nNome: ");
		clean_stdin();
		fgets(nome, MAX_TAM, stdin); 
		replaceString(nome, "\n", "");

		printf("\nNota1: ");
		scanf("%f", &nota1);
		printf("\nNota2: ");
		scanf("%f", &nota2);	
		
		fprintf(arq, "%d,%s,%4.1f,%4.1f\n", num, nome, nota1, nota2);
	}

	fclose(arq);
	
}

/*
imprime as notas dos alunos que estao gravados no arquivo
"nome_arquivo" (ex: GAAL.txt):
*/

void imprimeNotas(char nome_arquivo[]) {
	float notas,media;
	char buf[MAX_TAM];
	int num;
	char *nome;
	float nota1, nota2;
	FILE *arq;
	
	arq = fopen(nome_arquivo,"r");
	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!");
		getch();
	return;
	}
	printf("\nmatricula\t nome\t\t nota1\t nota2\t");

	notas=0;
	media=0;
	fgets(buf, MAX_TAM, arq);
	
	while(!feof(arq)) {
		num = atoi(strtok(buf, ","));
		nome = strtok(NULL, ",");
		nota1 = atof(strtok(NULL, ","));
		nota2 = atof(strtok(NULL, ","));
		printf("\n%d \t %20s \t %4.1f \t %4.1f", num, nome, nota1, nota2);
		notas = notas + 2;
		media = media + nota1 + nota2;
		fgets(buf, MAX_TAM, arq);
	}
	printf("\nmedia = %f",media/notas);
	fclose(arq);
}

int main(int argc, char *argv[]) {

	int i;
	char nome_arquivo[10] = "GAAL.txt";
	char exibe_media='N';
	char edita_aluno = 'N';
	int le_alunos = 0;
	
	/*
	-d: indicar a disciplina
 
	-m: mostrar ou não a média das notas
	 
	-l: ler a informação de n alunos
	 
	-e: para editar a nota de um aluno
	*/
	
	for(i=0; i<argc; i++) {
		//verifica se ha o parametro -d na lista de parametros:
		if(strcmp(argv[i], "-d") == 0) {
			//caso positivo, coloca o parametro seguinte na variavel nome_arquivo e acrescenta a extensao .txt:
			strcpy(nome_arquivo, argv[i+1]);
			strcat(nome_arquivo, ".txt");
			printf("\nNome arquivo que será lido: %s", nome_arquivo);
		}
		//verificar se tem o parametro -m na lista:
		else if(strcmp(argv[i], "-m") == 0) {
			exibe_media = argv[i+1][0];
		}
		
		//verifica se tem o parametro -e na lista:
		else if(strcmp(argv[i], "-e") == 0){
			edita_aluno = 'S';
		}
			
		//verifica se tem o parametro -l na lista:
		else if(strcmp(argv[i], "-l") == 0){
			// atoi(char *str) -> Convert str to an integer
			le_alunos = atoi(argv[i+1]);
		}
			
		//para exibir a ajuda
		else if(argc == 1 || strcmp(argv[i], "-help") == 0 || argv[i][0] == '?') {
			printf("\nParametros do programa:");
			printf("\n-d [XXX] ..... Sigla da disciplina. Ex: -d AEDS1");
			printf("\n-m [S ou N] ..... Exibir media. Ex: -m S");
			printf("\n-l [#] ..... Le informacao sobre # alunos. Ex: -l 4");				
			printf("\n-e ..... Modifica nota de aluno.");			
			getch();
			return 1;		
		}
	}
	
	//Chamar os metodos dependendo dos parametros
	if(le_alunos > 0)
		leAluno(nome_arquivo, le_alunos);

	//se "edita_aluno" for 'S', chama o metodo para modificar notas:
	if(edita_aluno=='S'){
		modificarNotas(nome_arquivo);
	}

	if(exibe_media=='S'){
		imprimeNotas(nome_arquivo);
	}

	
getch(); 
return 0;
}
