#include <stdio.h>
#include <math.h>

float paraMetrosPorSegundo(float v){return v / 3.6;};


float areaCirculo(float raio) {return M_PI*raio*raio;};

int maior3(int n1, int n2, int n3){	
	if(n2 >= n1 && n2 >= n3){
		return n2;
	} else if (n1 >= n2 && n1 >= n3){
		return n1;
	} else {
		return n3;
	}
};

int ehPar(int n){
	return !(n & (unsigned int) 1);
};

int ehDivisivelPor3ou5(int n){
	int div_por_5 = n % 5 == 0;
	int div_por_3 = n % 3 == 0;
	
	return (div_por_5 || div_por_3) && !(div_por_5 && div_por_3);
};

float pesoIdeal(float h, char sexo){
	return (sexo=='M') ? 72.7*h-58 : 62.1*h-44.7;
};

void get_infos_from_peso_ideal(){
	char sexo;
	float altura, peso; 

	printf("Informe o seu sexo-altura-peso:\n");
	scanf("%c-%f-%f", &sexo, &altura, &peso);  

	float peso_ideal = pesoIdeal(altura, sexo);


	printf("Você tem que ter %.2f kilos!\n", peso_ideal-peso);
}

int somaImpares(int N){
	int soma=0, i = 0;
	
	for (i;i<=N;i++){
		if (i % 2 != 0){
			soma += i;
		}
	}
	printf("\n\n%d\n", soma);
	return soma;
};

double fatorial(int N){
	// 4 => 4*3*2*1
	if(N <= 1){
		return 1;
	}
	return N*fatorial(N-1);
};

int somaNumerosDiv3ou5(int N){
	int i = 0, soma = 0;
	for (i; i<=N;i++){
		if(ehDivisivelPor3ou5(i)){
			soma += i;
		}
	}
	return soma;
};

float calculaMedia(int x, int y, int z, int operacao){
	switch (operacao){
	case 1:
		return x*y*z;
	case 2:
		return (x+2*y +3*z)/6.0;
	case 3:
		return 3/((1/x)+(1/y)+(1/z));
	default:
		return (x+y+z)/3;
	}
	
};

int numeroDivisores(int N){
	int i, count = 0;
	
	for (i = 1; i<=N; i++){
		if (N % i==0){
			count += 1;
		}
	}
	return count;
};

int enesimoFibonacci(int N){
	int i, n1 = 0, n2 = 1, n3 = 0;
	
	for (i = 1; i <= N; i++){
		// printf("\n\n%d - %d\n\n", n1, n2);
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n2-n1;
};

int mmc(unsigned int x, unsigned int y);


void main(){
	printf("\n");
	printf("enesimoFibonacci: %d", enesimoFibonacci(9));
	// get_infos_from_peso_ideal();
	printf("\n\n");
}
