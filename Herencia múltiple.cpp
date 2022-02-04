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
class Hervivoro : public Animal{
    public:
    //Con esto, Herviboro puede tener acceso 
    //al constructor de la clase Animal
    //Si hay argumentos, también deben agregarse 
    Hervivoro() : Animal(){ 
        this -> alimento = "plantas";
    }
    void pastar(){
        cout << "Pastando... " << endl;
    }
};
class Carnivoro : public Animal{
    public:
    Carnivoro() : Animal(){ 
        this -> alimento = "carne";
    }
    void cazar(){
        cout << "Cazando... " << endl;
    }
};

//Herencia múltiple
class Omnivoro : public Hervivoro, public Carnivoro{
    public:
    Omnivoro() : Hervivoro(), Carnivoro() {}
    /* 
    //Quita la ambigüedad de la función comer 
    //para la clase omnivoro
    void comer() {
        cout << "Este animal come lo que sea" << endl;
    }
    */
};


int main() {
    Animal *a = new Animal();
    Hervivoro *h = new Hervivoro();
    Carnivoro *c = new Carnivoro();
    Omnivoro *o = new Omnivoro();

    cout << "Numero de animales: " << Animal::obtenerNumeroAnimales() << endl;

    a -> comer();

    h -> pastar();
    h -> comer();

    c -> cazar();
    c -> comer();

    //o -> comer(); //No se debe colocar de esta forma
    //Se debe indicar de qué padre va a mostrar
    o -> Hervivoro::comer(); //Quira la ambigüedad de la clase

    delete a;
    cout << "Numero de animales: " << Animal::obtenerNumeroAnimales() << endl;
}