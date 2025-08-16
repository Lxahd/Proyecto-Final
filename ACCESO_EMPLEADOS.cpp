#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <fstream>

#define MAX_NOMBRE [60]
#define MAX_DIRECCION [100]
#define MAX_TELEFONO [9]
#define MAX_EMAIL [20]
#define HORA_LIMITE 7.5
#define ARCHIVO_EMPLEADOS
#define ARCHIVO_HORAS

using namespace std;

struct EMPLEADO{
    char nombre;
    char direccion;
    char telefono[9];
    char email;
    int faltas_puntualidad;
    float horas_trabajadas;
};

int menuPrincipal(){
    int resp;
    cout << "=========MENU PRINCIPAL========="<<
            "\n1. Registrar Empleado"<<
            "\n2. Cargar Horas de Empleado"<<
            "\n3. Imprimir Mejores Empleados"<<
            "\n4. Salir"
            "\nIngrese la opcion: ";

    cin >> resp;

    return resp;
}
int registrar_datos_personales(EMPLEADOS &n){
    cout << "Ingresar nombre: ";
    getline(cin, n.nombre);
}
int carga_horas(){

}

void imprime_mejores_empleador(){
    
}

main(){
    int option;
    EMPLEADOS n;
    option = menuPrincipal();
    switch (option)
    {
        case 1:
            resgistrar_datos_personales(n);
            break;
    
        case 2:
            break;
        
        case 3: 
            break;
        
        case 4: exit(0);
            break;
        default:
            break;
    }
}