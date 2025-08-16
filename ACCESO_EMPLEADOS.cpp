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
#define ARCHIVO_EMPLEADOS "datos/empleados.txt"
#define ARCHIVO_HORAS "datos/horas.txt"

using namespace std;

struct EMPLEADO{
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
    char telefono[MAX_TELEFONO];
    char email[MAX_EMAIL];
    int faltas_puntualidad;
    float horas_trabajadas;
};

int registrar_empleado(EMPLEADO empleado[], int num_empleado){
    
    int i, cantidad;

    cout << "\nIngrese el numero de empleados a agregar: ";
    cin >> cantidad;

    for (i = 0; i < cantidad; i++)
    {
        cout << "Ingresar datos de [EMPLEADO " << num_empleado + i + 1 << "]\n";
        cout << "Nombre: ";
        cin >> empleado[num_empleado + i].nombre;
        cout << "Direccion: ";
        cin >> empleado[num_empleado + i].direccion;
        cout << "Telefono: ";
        cin >> empleado[num_empleado + i].telefono;
        cout << "Email: ";
        cin >> empleado[num_empleado + i].email;
        cout << endl;
    }
    return num_empleado + cantidad;
}

int cargar_archivo_empleados(const char *archivoEmpleados, EMPLEADO empleado[]){
    FILE *archivo = fopen(archivoEmpleados, "r");
    if(!archivo){
        cout << "Error al abrir el archivo de empleados." << endl;
        return 0;
    }

    int n = 0;
    char buffer[256];

    if (fgets(buffer, sizeof(buffer), archivo)) {
    }

    while (fgets(buffer, sizeof(buffer), archivo)) {
        buffer[strcspn(buffer, "\n")] = 0;
        sscanf(buffer, "%s %s %s %s",
            empleado[n].nombre,
            empleado[n].direccion,
            empleado[n].telefono,
            empleado[n].email
        );
        n++;
    }
    fclose(archivo);
    return n;
}

void guardar_archivo_empleados(const char *archivoEmpleados, EMPLEADO empleado[], int num_empleado){
    CreateDirectoryA("datos", NULL);

    FILE *archivo = fopen(archivoEmpleados, "w");
    if(!archivo){
        cout << "Error al abrir el archivo para guardar empleados." << endl;
        return;
    }

    fprintf(archivo, "Numero de empleados: %d\n", num_empleado);
    for (int i = 0; i < num_empleado; i++)
    {
        fprintf(archivo, "%s %s %s %s\n",
                empleado[i].nombre,
                empleado[i].direccion,
                empleado[i].telefono,
                empleado[i].email);
    }
    fclose(archivo);
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

int main(){
    int option, n_empleado;
    const char* archivoEmpleado = ARCHIVO_EMPLEADOS;
    EMPLEADO grupo[MAX_EMPLEADOS];

    n_empleado = cargar_archivo_empleados(archivoEmpleado, grupo);
    for (;;){
        system("CLS");
        option = menuPrincipal();

        switch(option)
        {
            case 1: system("CLS");
                    cout << "1. Registrar Empleado";
                    n_empleado = registrar_empleado(grupo, n_empleado);
                    guardar_archivo_empleados(archivoEmpleado, grupo, n_empleado);
                    break;
            
            case 4: cout << "Saliendo del sistema..." << endl;
                    Sleep(1000);
                    exit(0);
                    break;
            default:
                break;
        }
    }
}