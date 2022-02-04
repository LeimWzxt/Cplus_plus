#include <iostream>
#include <string>

using namespace std;

//por defecto son privados; pero, si se coloca public, se puede acceder desde afuera
class Persona { 
public: 
	string nombre ="Yomi";
	int edad = 25;
	void saludar() {
		cout << "Hola, " << nombre <<endl;
	}
};

int main() {
	// sin punteros
	Persona p = Persona();
	cout << p.nombre << endl; //muestra en pantalla el contenido de p.nombre
	p.saludar();
	
	//con punteros 
	Persona *q = new Persona();
	cout << q -> nombre << endl; //muestra en pantalla el contenido de p -> nombre
	q -> saludar();

	Persona *q2 = new Persona();
	q2 -> nombre = "Susan";
	q2 -> edad = 20;
	cout << q2 -> nombre << endl;
	q2 -> saludar();
};




