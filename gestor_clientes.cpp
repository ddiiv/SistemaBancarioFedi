#include <iostream>

using namespace std;    

int main() {
    struct Clientes {
        string nombre;
        int DNI;
        string userName[20];
        char password;  
        float saldo = 10000.0;
        
    };

    cout << "Gestor de clientes" << endl;



    return 0;
}