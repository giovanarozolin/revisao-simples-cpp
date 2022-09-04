#include <iostream>

using namespace std;

int main() {
    // (expressão) ? valor1 : valor2;
    // ? se for verdadeiro executa valor1
	// : se não executa valor2
    int n1, n2, nota;
    string res;

    setlocale(LC_ALL, "Portuguese");

    cout << "Digite a primeira nota: ";
    cin >> n1;
    cout << "Digite a segunda nota: ";
    cin >> n2;

    nota = n1 + n2;

    (nota>=60) ? res="Aprovado" : res="Reprovado";
     
     cout << "\nSituação do aluno: " << res << "\n";


return 0;
}