#include <iostream>
using namespace std;

void digaAlo(string nome, int idade, float salario) {
    cout << "\tInformacoes do funcionario:\n";
    cout << "\tnome: " << nome << "\n";
    cout << "\tidade: " << idade << "\n";
    cout << "\tsalario: " << salario << "\n";
}


int main() {
    string nome;
    int idade;
    float salario;
    
    cout << "Digite o nome da pessoa:";
    cin >> nome;
    cout << "\nIdade:";
    cin >> idade;
    cout << "\nSalario:" << endl;
    cin >> salario;
    
    digaAlo(nome, idade, salario);
    
    return 0;
}

