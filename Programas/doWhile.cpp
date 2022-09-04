//Recomendado quando eu quero garantir que o bloco da estrutura de repetição seja executado pelo menos uma vez.
#include <iostream>
using namespace std;

int main() {
    int contador = 11;
    do {
        contador++;
        cout << "\nContador = " << contador;
    } while(contador < 10);
    cout << "\n\nValor final: Contador = " << contador;
    return 0;
}