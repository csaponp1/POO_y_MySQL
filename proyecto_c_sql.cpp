/*
* UNIVERSIDAD MARIANO GALVEZ
* INGENIERIA EN SISTEMAS
* SECCION A
* PLAN DIARIO, SEDE LA ANTIGUA GUATEMALA
* NOMBRES: CHRISTIAN FERNANDO SAPON PEREZ
* CARNET: 1290-21-16654
*/
#include<stdio.h>
#include <iostream>
#include <mysql.h>
#include "Cliente.h"

using namespace std;
int main() {
        
    string nit, nombre, apellido, direccion, fecha_nacimiento;
    int telefono;

    cout << "Ingrese Nit: " << endl;
    getline(cin, nit);
    cout << "ingrese nombres" << endl;
    getline(cin, nombre);
    cout << "ingrese apellidos" << endl;
    getline(cin, apellido);
    cout << "Ingrese direccion" << endl;
    getline(cin, direccion);
    cout << "ingrese telefono: " << endl;
    cin >> telefono;
    cin.ignore();
    cout << "ingrese fecha de nacimiento" << endl;
    getline(cin, fecha_nacimiento);


    /*if (conectar) {
        string puesto;
        cout << "ingrese puesto " << endl;
        cin >> puesto;
        string insert = "insert into puestos(puesto) values ('" + puesto + "');";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
            cout << "INGRESO EXITOSO !" << endl;
        else
            cout << "Error al insertar !!!!xxx" << endl;

    }
    else {
        cout << "SIN CONEXION!!!!!!" << endl;
    }
    */

    Cliente c = Cliente(nombre,apellido,direccion,telefono,fecha_nacimiento,nit);
    c.crear();
    c.leer();

    
    
    cout << "Hello World!\n";
    system("pause");
}

