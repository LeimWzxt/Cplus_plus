
#include <iostream>
#include <string>
using namespace std;

int main() {
	int monto = 0, monto_cuenta_=100;
	string letras[] = {"retirar", "depositar"};
	int mult[] = {-1,1};
	bool dep_ret = 0;

	cout << "Coloque el monto a "<< letras[dep_ret] << ": ";
	cin >> monto;
	monto_cuenta_ += monto*mult[dep_ret];

	cout << "Monto disponible: " << monto_cuenta_ << endl;


	dep_ret = 1;

	cout << "Coloque el monto a "<< letras[dep_ret] << ": ";
	cin >> monto;
	monto_cuenta_ += monto*mult[dep_ret];

	cout << "Monto disponible: " << monto_cuenta_ << endl;
}
