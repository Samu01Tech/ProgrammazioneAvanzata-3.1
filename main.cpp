#include <iostream>
using namespace std;

class A{
    int k;
    float h;
    public: 
    //Costruttori (0 e più parametri)
    A(){
        k = 0;
        h = 0.0;
    }
    A(int _k, float _h){
        k = _k;
        h = _h;
    }
    //Costruttore di Copia
    A(const A &cls){
        k = cls.k;
        h = cls.h;
        cout << "Costruttore di copia" << endl;
    }
    //Distruttore
    ~A(){
        cout << "Distruttore A" << endl;
    };
};

int main() {
  cout << "Hello World!\n";
}