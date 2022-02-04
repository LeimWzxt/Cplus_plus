#include <iostream>
#include <string>
using namespace std;

class Cuenta { 
	protected:
		static int total_cuentas; //numero total de cuentas creadas
	public: 
		string propietario; //dueño de la cuenta	
		int num_cuenta = 0; //número random de 5 cifras
		string tipo; //0: débito, 1: crédito
		int monto_cuenta; //dinero disponible en la cuenta
		
		Cuenta(string p, string t, int m): propietario(p), tipo(t), monto_cuenta(m) {
			num_cuenta = 58962 + total_cuentas; //numero random de 5 cifras

			cout << "Se ha creado con exito la siguiente cuenta: " << endl << endl;
			datos_cuenta(num_cuenta, propietario, tipo, monto_cuenta);
			
			total_cuentas++;
		}
		~Cuenta() {}
		
		static int obtener_total_cuentas();
		int depositar() {
			monto_cuenta = saldo(1, monto_cuenta); //1: deposito
			datos_cuenta(num_cuenta, propietario, tipo, monto_cuenta);
		}
		int retirar() {
			monto_cuenta = saldo(0, monto_cuenta); //0: retiro
			datos_cuenta(num_cuenta, propietario, tipo, monto_cuenta);
		}
		void datos_cuenta(int num_cuenta, string propietario, string tipo, int monto) {
			cout << " ====================================================" << endl;
			cout << "Numero de cuenta: " << num_cuenta << endl;
			cout << "Propietario de la cuenta: " << propietario << endl;
			cout << "Tipo de cuenta: " << tipo << endl; 
			cout << "Monto disponible en la cuenta: $ " << monto << endl;
			cout << " ====================================================" << endl << endl;
		}
		int saldo(bool dep_ret, int monto_cuenta_) { //0 retiro, 1 deposito
			int monto = 0;
			string letras[] = {"retirar", "depositar"};
			int mult[] = {-1,1};
			
			cout << "Coloque el monto a "<< letras[dep_ret] << ": ";
			cin >> monto;
			monto_cuenta_ += monto*mult[dep_ret];

			cout << "Monto disponible: " << monto_cuenta_ << endl << endl;
			return monto_cuenta_;
		}

};

int Cuenta::total_cuentas = 0;
int Cuenta::obtener_total_cuentas() {
	return total_cuentas;
}

int menu() { 
	int op_ = 0;

	cout << "1. Crear cuenta" << endl;
	cout << "2. Modificar cuenta" << endl;
	cout << "3. Retirar monto de una cuenta" << endl;
	cout << "4. Depositar monto a una cuenta" << endl;
	cout << "5. Eliminar una cuenta" << endl;
	cout << "6. Total de cuentas" << endl;
	cout << "7. Buscar cuenta por propietario" << endl;
	cout << "8. Buscar cuenta por numero de cuenta" << endl;
	cout << "9. Salir" << endl << endl;
	
	cout << ">> Coloque la opcion a elegir: ";
	cin >> op_;

	return op_;
}


int main() {
	bool fin = 1; //detiene el while

	while(fin) {
		int op = 0;
		op = menu();

		string prop;
		bool tipo_cuenta = 0; //0: débito, 1: crédito
		string tipo_ = "Debito";
		int monto = 0;

		Cuenta *account;

		if (op == 1) { //Crear cuenta
			cout << "Coloque el nombre del propietario: ";
			cin >> prop; //propietario de la cuenta

			cout << "0: Debito" << endl;
			cout << "1: Credito" << endl;
			cout << ">> Coloque la opcion de tipo de cuenta a abrir: ";
			cin >> tipo_cuenta;

			if (tipo_cuenta){
				tipo_ = "Credito";
				monto = 1000;
			}

			account = new Cuenta(prop, tipo_, monto);
		} 
		else if (op == 3) { //Retirar dinero
			account -> retirar();
		} 
		else if (op == 4) { //Depositar dinero
			account -> depositar();
		}
		else if (op == 6) { //Total de cuentas
			cout << " ====================================================" << endl;
			cout << "Numero de cuentas: " << Cuenta::obtener_total_cuentas() << endl;
			cout << " ====================================================" << endl << endl;
		}
		else { //Salir
			fin = 0;
		} 

	}
};

