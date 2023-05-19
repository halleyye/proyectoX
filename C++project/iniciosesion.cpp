#include <iostream>
#include <string>

using namespace std;

void loginup()
{
    string usuario, password;
    cout << "ingrese el usuario" << endl;
    cin >> usuario;
    cout << "ingrese el password\n";
    cin >> password;
    if (usuario == "empleado_universal1768")
    {
        cout << "el usuario es correcto\n";
    }
    else
    {
        cout << "usuario o password incorrecto" << endl;
        system("pause");
        return;
    }
    if (password == "caballo123")
    {
        cout << "usuario y password correctos\n"
             << "ha obtenido acceso al sistema\n";
    }
    else
    {
        cout << "usuario o password incorrecto\n";
        system("pause");
        return;
    }
}

