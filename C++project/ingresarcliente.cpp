#include <iostream>
#define MAX 50
#include <string.h>
#include <limits>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;

int registro = 0;

struct cliente
{
    char nombre[MAX];
    char apellidos[MAX];
    char cedula[16];
    char numcelular[MAX];
    char servicio[MAX];
    char cantpersonas[20];
    char fechareserva[MAX], horareserva[MAX];
} p[1];

void limpiarBuffer()//uno de los tantos errores que me esta dando es que me esta pidiento presionar enter para continuar con el codigo, intenta repararlo y me mandas mensaje mientras lo haces
{
    cin.ignore(1000, '\n');
}

void addcliente()
{
    // Bienvenida
    cout << "Bienvenido al sistema de Reservas La Colombina\n";
    // nombre completo del cluente
    cout << "Ingresa los primeros nombres del cliente:\n";
    cin.getline(p[registro].nombre, MAX);
    limpiarBuffer();
    cout << "Ingresa los apellidos:\n";
    cin.getline(p[registro].apellidos, MAX);
    limpiarBuffer();
}

void ingcedula() // numero de cedula
{

    cout << "Numero de cedula: ";
    cin.getline(p[registro].cedula, MAX);
    limpiarBuffer();
}
int calcEdad() // verificar mayoria de edad
{
    char num1 = p[registro].cedula[8]; // Primer numero de la cedula
    char num2 = p[registro].cedula[9]; // Segundo numero de la cedula
    int year;

    if (atoi(&num1) < 2)
    {
        year = 2000 + ((atoi(&num1) * 10)) + (atoi(&num2) / 10);
    }
    else if (atoi(&num1) > 3)
    {
        year = 1900 + (atoi(&num1) * 10) + (atoi(&num2) / 10);
    }

    if (year < 2005)
    {
        cout << "El cliente es mayor de edad." << endl;
    }
    else
    {
        cout << "El cliente no cumple con la mayoria de edad." << endl;
        cout << "Acceso denegado." << endl;
        system("pause");
        exit(0);
    }
}

void numcel()
{
    cin.ignore();
    cout << "ingresa el numero de celular del cliente:\n";
    cin.getline(p[registro].numcelular, MAX);
    limpiarBuffer();
}

void tiposervicio()
{
    cout << "¿Que tipo de servicio desea contratar?\n";
    cout << "1. VIP\n";
    cout << "2. Estandar\n";
    cout << "Por favor, seleccione el numero correspondiente al tipo de servicio: \n";
    cin.getline(p[registro].servicio, MAX);
    limpiarBuffer();
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        strcpy(p[registro].servicio, "VIP\n");
        cout << "costo: 120$" << endl;
        break;
    case 2:
        strcpy(p[registro].servicio, "Estandar\n");
        cout << "costo 90$\n";
        break;
    default:
        cout << "Opcion invalida. Seleccionando servicio Estandar por defecto.\n";
        strcpy(p[registro].servicio, "Estandar\n");
    }
}

// fecha de la reservacion
void fechayhorareserva()
{
    cout << "Fecha en la que desea reservar: \n";
    cin.getline(p[registro].fechareserva, MAX);
    limpiarBuffer();
    cout << "Hora en la que desea su reserva: \n";
    cin.getline(p[registro].horareserva, MAX);
    limpiarBuffer();
}
// numero maximo de personas a llegar

void cantidadpersonas()
{
    cout << "Cantidad de personas a llegar: " << endl;
    cin.getline(p[registro].cantpersonas, 20);
    limpiarBuffer();
}
// verificacion de la cantidad maxima de personas
bool calcMAXpersonas()
{
    int cantmaxima = atoi(p[registro].cantpersonas);
    while (cantmaxima > 20)
    {
        cout << "Excede el limite de acceso de clientes disponible.\n";
        cout << "Por favor, vuelva a intentarlo con otro numero.";
        cin.getline(p[registro].cantpersonas, 20, '\n');
        cantmaxima = atoi(p[registro].cantpersonas);
    }
    return true;
}

// ejecucion final del codigo
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    addcliente();
    ingcedula();
    calcEdad();
    numcel();
    tiposervicio();
    cantidadpersonas();
    calcMAXpersonas();
    fechayhorareserva();
    cout << "El cliente " << p[registro].nombre << " " << p[registro].apellidos << endl;
    cout << "Numero de cedula: " << p[registro].cedula << endl;
    cout << "Numero de celular: " << p[registro].numcelular << endl;
    cout << "Contrato el servicio " << p[registro].servicio << endl;
    cout << "arribando con " << p[registro].cantpersonas << "personas" << endl;
    cout << "El dia " << p[registro].fechareserva << " ";
    cout << "a las " << p[registro].horareserva << endl;

    return 0;
}