#include <iostream>
using namespace std;

class A{
    private:
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
    //Funzioni friend
    friend ostream& operator <<(ostream& os, const A& a);
};
//Re: cout
ostream& operator <<(ostream& os, const A& a){
    return os << a.k << "-" << a.h;
}

int main() {
    A a1, a2(1, 3.14);
    cout << "a1=" << a1 << endl;
    cout << "a2=" << a2 << endl;
    a1 = a2;
    cout << "a1=" << a1 << endl;
    return 0;
}