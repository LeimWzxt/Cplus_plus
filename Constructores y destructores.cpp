#include <iostream>
#include <string>

using namespace std;

//por defecto son privados; pero, si se coloca public, se puede acceder desde afuera
class Persona { 
public: 
	string nombre;
	int edad;
	Persona (string n, int e) { //Se realiza la declaración de constructor como función del tipo de dato
		nombre = n;
		edad = e;
	}
	~Persona() { //Definición del destructor
		// Contenido para liberar memoria cuando se usan punteros al interior de este objeto
		cout << "Destructor" << endl;
	}
	void saludar() {
		cout << "Hola, " << nombre << endl;
		cout << "Tienes " << edad << " de edad."<<endl;
	}
};

int main() {
	
	Persona *p = new Persona("Yomi", 25);
	Persona *p1 = new Persona("Susan", 20);	
	
	//delete p1; //Invocación manual que elimina todo el contenido de p1
	
	p -> saludar();
	p1 -> saludar();
};

