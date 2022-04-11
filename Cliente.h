#pragma once
#include "Persona.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include<string>

using namespace std;
class Cliente : Persona{

private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel,string fn, string n) : Persona(nom, ape, dir, tel,fn) {
		nit = n;
	}

	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombre(string nom) { nombres = nom; }
	void setApellido(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	// metodo select
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "------------ Datos de Clientes ------------" << endl;
			cout << " id " <<" | "<<"nit"<< " | " << "nombres" << " | " << "apellidos" << " | " << "direccion" << " | " << "telefono" << " | " << "fecha nacimiento" << endl;

			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 6; i++) {
						cout << fila[i] << "  ,  " ;
					}
					cout << "\n";
				}
			}
			else {
				cout << "xxxError al ingresar la informacion !!! xxx" << endl;
			}
			
		}
		else {
			cout << "ERROR AL CONECTAR ...! xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string t = to_string(telefono);
			

				string insert = "insert into clientes(nit,nombres, apellidos, direccion, telefono, fecha_nacimiento) values ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "','" +t+ "','" + fecha_nacimiento + "');";
				const char* i = insert.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << " INGRESO EXITOSO !" << endl;
					}
				else {
					cout << " xxxERROR AL INGRESAR LA INFORMACION!!!xxx" << endl;
				}

			}
		
		
		else {
			cout << "ERROR AL CONECTAR ...! xxx" << endl;
		}
		cn.cerrar_conexion();
	}
};	

