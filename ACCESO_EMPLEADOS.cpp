#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <fstream>

#define MAX_EMPLEADOS 300
#define MAX_NOMBRE 60
#define MAX_DIRECCION 100
#define MAX_TELEFONO 9
#define MAX_EMAIL 20
#define HORA_LIMITE 7.5
#define ARCHIVO_EMPLEADOS "empleados.txt"
#define ARCHIVO_HORAS "horas.txt"

using namespace std;

struct EMPLEADO{
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
    char telefono[MAX_TELEFONO];
    char email[MAX_EMAIL];
    int faltas_puntualidad;
    float horas_trabajadas;
};

int registrar_empleado(EMPLEADO empleado[], int num_empleados){
    
    int i, cantidad;

    cout << "Ingrese el numero de empleados a agregar: ";
    cin >> cantidad;

    for (i = 0; i < cantidad; i++)
    {
        cout << "Ingresar datos de ";
        cout << "[EMPLEADO " << num_empleados + i + 1 << "]\n";
        cout << "Nombre: ";
        cin >> empleado[num_empleados + i].nombre;
        cout << "Direccion: ";
        cin >> empleado[num_empleados + i].direccion;
        cout << "Telefono: ";
        cin >> empleado[num_empleados + i].telefono;
        cout << "Email: ";
        cin >> empleado[num_empleados + i].email;
        cout << endl;
    }
    return num_empleados + cantidad;
}

int menuPrincipal(){
    int resp;
    cout << "=======================================\n" <<
            "    SISTEMA DE CONTROL DE EMPLEADOS\n" <<
            "=======================================" <<
            "\n1. Registrar Empleado" <<
            "\n2. Cargar Horas de Empleado" <<
            "\n3. Imprimir Mejores Empleados" <<
            "\n4. Salir" 
            "\nIngrese la opcion: ";

    cin >> resp;

    return resp;
}

main(){
    int option, n_empleado;
    EMPLEADO grupo[MAX_EMPLEADOS];

    n_empleado = 0;
    option = menuPrincipal();
    switch (option)
    {
        case 1: system("CLS");
                cout << "1. Registrar Empleado";
                registrar_empleado(grupo, n_empleado);
            break;
        case 4: exit(0);
            break;
        default:
            break;
    }
}