#include <iostream>
#include <string>
using namespace std;
struct Clientes
{
    string nombre;
    int DNI;
    string userName;
    char password;
    float saldo = 10000.0;
};

void ingresarCliente()
{
    Clientes clientela;
    FILE *archivo;
    archivo = fopen("clientes.dat", "ab");

    cout << "----------------------------------------------------------------" << endl;
    cout << "Presione cualquier tecla para continuar...." << endl;
    cin.ignore();
    system("cls");
    cout << "Ingrese el nombre del cliente: ";
    cin >> clientela.nombre;
    system("cls");
    cout << "Ingrese el DNI del cliente: ";
    cin >> clientela.DNI;
    system("cls");
    cout << "Ingrese el nombre de usuario: ";
    cin >> clientela.userName;
    system("cls");
    cout << "Ingrese la contraseña: ";
    cin >> clientela.password;
    cout << "Saldo inicial: " << clientela.saldo << endl;
    cin.ignore();
    system("cls");
    fwrite(&clientela, sizeof(Clientes), 1, archivo);
    fclose(archivo);
    cout << "Cliente ingresado con exito" << endl;

}
void mostratClientes(){
    FILE *archivo;
    archivo = fopen("clientes.dat", "rb");
    Clientes clientela;
    while(fread(&clientela, sizeof(Clientes), 1, archivo)){
        cout << "Nombre: " << clientela.nombre << endl;
        cout << "DNI: " << clientela.DNI << endl;
        cout << "Nombre de usuario: " << clientela.userName << endl;
        cout << "Saldo: " << clientela.saldo << endl;
    }
    fclose(archivo);
}

int menu(int option)
{
    cout << "Gestor de clientes" << endl;
    cout << "1. Ingresar clientes" << endl;
    cout << "2. Modificar Clientes" << endl;
    cout << "3. Eliminar Clientes" << endl;
    cout << "4. Mostar Clientes" << endl;
    cout << "5. Salir" << endl;
    cin >> option;
    return option;
}

int main()
{
    int option;
    option = menu(option);
    switch (option)
    {
    case 1:
        cout << "Ingresar clientes" << endl;
        ingresarCliente();
        break;
    case 2:
        cout << "Modificar clientes" << endl;
        mostratClientes();
        break;
    case 3:
        cout << "Eliminar clientes" << endl;
        break;
    case 4:
        cout << "Mostrar clientes" << endl;
        break;
    case 5:
        cout << "Salir" << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    return 0;
}
