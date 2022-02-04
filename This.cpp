#include <iostream>
#include <string>

using namespace std;

class Persona { 
private:
	string nombre;
	int edad;
public: 

	Persona (string n, int e): nombre(n), edad(e) {}	
/*
	Persona (string nombre, int edad) {
		this -> nombre = nombre; 
		this -> edad = edad;
		// el primero es el campo de la clase y el segundo es el campo de la función
	}
*/
	Persona &EstablecerNombre (string nombre) {
		this -> nombre = nombre;
		return *this;
	}
	Persona &EstablecerEdad (int edad) {
		this -> edad  = edad;
		return *this;
	}
	~Persona() { 
		cout << "Destructor" << endl;
	}
	void saludar() {
		cout << "Hola, " << nombre << endl;
		cout << "Tienes " << edad << " de edad." << endl;
	}
};

int main() {
	
	Persona *p = new Persona("Yomi", 25);
	p -> EstablecerNombre("Lia").EstablecerEdad(20);
	p-> saludar();
};

