#include <iostream> // BIBLIOTECA DE ENTRADA E SAIDA
#include <cstdlib> // SRAND E RAND
#include <vector> // VECTOR 
using namespace std;

/*
</utilidade_pública> </algoritmo_cpf>
n1 = número aleatório (0 até 9)
n2 = número aleatório (0 até 9)
n3 = número aleatório (0 até 9)
n4 = número aleatório (0 até 9)
n5 = número aleatório (0 até 9)
n6 = número aleatório (0 até 9)
n7 = número aleatório (0 até 9)
n8 = número aleatório (0 até 9)
n9 = número aleatório (0 até 9)
d1 = n9 * 2 + n8 * 3 + n7 * 4 + n6 * 5 + n5 * 6 + n4 * 7 + n3 * 8 + n2 * 9 + n1 * 10;
d1 = 11 - (d1 % 11);
Se d1 for maior ou igual a 10, então ele se torna 0(d1 = 0)
d2 = d1 * 2 + n9 * 3 + n8 * 4 + n7 * 5 + n6 * 6 + n5 * 7 + n4 * 8 + n3 * 9 + n2 * 10 + n1 * 11;
d2 = 11 - (d2 % 11);
Se d2 for maior ou igual a 10, então ele se torna 0(d2 = 0)
	CPF = "n1n2n3.n4n5n6.n7n8n9-d1d2"
*/

int rand_number(){ // GERA UM NUMERO DE 0 A 9
	return rand()%10;
}

int set_firstNumber(vector <int> n){ // COM BASE EM CALCULOS SIMPLES TEMOS O PRIMEIRO NUMERO DO CPF DEPOIS DO "-"
	int aux;

	aux = (n[9] * 2) + (n[8] * 3) + (n[7] * 4) + (n[6] * 5) + (n[5] * 6) + (n[4] * 7) + (n[3] * 8) + (n[2] * 9) + (n[1] * 10);
	aux = 11 - (aux % 11);

	if(aux >= 10) aux = 0;

	return aux;
}

int set_lastNumber(vector <int> n, int d1){ // COM BASE EM CALCULOS SIMPLES TEMOS O ULTIMO NUMERO DO CPF DEPOIS DO "-"
	int aux;

	aux = (d1 * 2) + (n[9] * 3) + (n[8] * 4) + (n[7] * 5) + (n[6] * 6) + (n[5] * 7) + (n[4] * 8) + (n[3] * 9) + (n[2] * 10) + (n[1] * 11);
	aux = 11 - (aux % 11);

	if(aux >= 10) aux = 0;

	return aux;
}

void show_numbers(vector <int> vec){ // FUNCAO UTILIZADA APENAS PARA DEBUG NA GERACAO DOS NUMEROS
	for(int i = 0; i < 10; i++)
		cout << vec[i] << endl;
}

void show_cpf(vector <int> n, int d1, int d2){ // MOSTRA O CPF COM A MASCARA
	cout << n[1] << n[2] << n[3] << "." << n[4] << n[5] << n[6] << "." << n[7] << n[8] << n[9] << "-" << d1 << d2 << endl; 
}

int main(int argc, char** argv){
	int d1, d2;
	vector <int> v;

	srand(time(NULL));

	if(argc < 2) { // TESTA OS ARGUMENTOS
		cout << "Faltam Argumentos!" << endl << "Uso: " << argv[0] << " <Qtd_de_CPF>" << endl;
		exit(1);
	}

	for(int i = 0; i < atoi(argv[1]); i++){ // GERA A QUANTIDADE DE CPFS INDICADAS
		cout << "Gerando o cpf numero " << i+1 << "..." << endl;

		for(int i = 0; i < 10; i++)
			v.push_back(rand_number());

		d1 = set_firstNumber(v);
		d2 = set_lastNumber(v, d1);

		show_cpf(v, d1, d2);

		cout << endl;

		v.clear();
	}

	//show_numbers(v);

	return 0;

}