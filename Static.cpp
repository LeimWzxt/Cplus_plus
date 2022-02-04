#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
	string nombre;
	int edad;
public:
	static int num_personas;
	~Persona() {
	cout << "Destructor" << endl;
	}
	Persona (string nombre, int edad); 
	Persona &EstablecerNombre (string nombre) {
	this -> nombre = nombre;
	return *this;
	}
	Persona &EstablecerEdad (int edad) {
	this -> edad  = edad;
	return *this;
	}
	void saludar();
};

int Persona::num_personas = 0; //Forma para trabajar con variables estáticas públicas
//Para las que no son estáticas, es opcional hacerlo así
void Persona::saludar() {
	cout << "Hola, " << nombre << endl;
	cout << "Tienes " << edad << " de edad." << endl;
}
Persona::Persona (string nombre, int edad) {
	this->nombre = nombre;
	this->edad = edad;
	num_personas++;
}

int main() {
	Persona *p = new Persona("Yomi", 25);
	Persona *p1 = new Persona("Lia", 25);
	
    //Muestra en pantalla el valor actual de num_personas
	cout << Persona::num_personas << endl; 
	
	p -> EstablecerNombre("Lia").EstablecerEdad(20);
	p-> saludar();
};