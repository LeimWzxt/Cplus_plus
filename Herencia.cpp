#include <iostream>
#include <string>

using namespace std;

class Animal {
//private: //Se cambia por protected que es similar a  
//private, pero puede dar acceso a herencia
protected:
    static int num_animales;
	string alimento = "carne";
public:
    Animal();
    ~Animal();
    static int obtenerNumeroAnimales();
    string obtenerAlimento() {
        return alimento;
    };
    void comer() {
        cout << "Este animal come " << alimento << endl;
    };
};

int Animal::num_animales=0;
Animal::Animal() {
    cout << "Creando nuevo animal" << endl;
    num_animales++;
}
Animal::~Animal(){
    cout << "Borrando animal" << endl;
    num_animales--;    
}
int Animal::obtenerNumeroAnimales(){
    return num_animales;
}

// Herencia
class Herviboro : public Animal{
    public:
    //Con esto, Herviboro puede tener acceso 
    //al constructor de la clase Animal
    //Si hay argumentos, también deben agregarse 
    Herviboro() : Animal(){ 
        this -> alimento = "plantas";
    }
    void pastar(){
        cout << "Pastando... " << endl;
    }
};

int main() {
    Animal *a = new Animal();
    Herviboro *h = new Herviboro();

    cout << "Numero de animales: " << Animal::obtenerNumeroAnimales() << endl;

    a -> comer();
    h -> pastar();

    delete a;
    cout << "Numero de animales: " << Animal::obtenerNumeroAnimales() << endl;
}