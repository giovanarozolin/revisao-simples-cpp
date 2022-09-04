#include <iostream>
using namespace std;

int main() {
    int contador = 0;

    while(contador < 3) {
        contador++;
        
        cout << "\nContador = " << contador;

        if (contador > 20)
             break;
         if (contador > 10) {
             continue;
         }
    }
    cout << "\n\nValor final: Contador = " << contador;

    return 0;
}