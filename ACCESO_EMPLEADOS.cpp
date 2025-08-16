#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <fstream>

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
    int option;
    option = menuPrincipal();
    switch (option)
    {
        case 1:
            break;
        case 4: exit(0);
            break;
        default:
            break;
    }
}