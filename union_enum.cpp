#include <iostream>
#include <string>

using namespace std;

int main() {
	union num_let {
		int num;
		char let;
	};
	
	num_let x = {'A'};
	
	cout << "x como num: " << x.num << endl; // ASCII de A
	cout << "x como num: " << (char) x.num << endl; // A
	cout << "x como let: " << x.let << endl; //A
	
	
	enum dias_semana {lunes, martes, miercoles};
	
	dias_semana dia = martes; //declara a dia un tipo de dato dias_semana y se le asigna el valor martes (posición 1 en dias_semana)
	
	cout << dia << endl; 
	
	enum meses {enero = 1, febrero = 2};
	
	meses hoy = febrero; 
	
	cout << hoy; 

}
















