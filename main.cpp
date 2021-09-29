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
    //Re: =
    A& operator =(const A& a){
        k = a.k; h = a.h;
        cout << "operator Assegnazione =" << endl;
        return *this; //ritorna istanza classe
    };
    A& operator =(int i){
        k = i;
        cout << "operator Assegnazione = int" << endl;
        return *this;
    };
    //Re: +
    A operator +(const A& a) const{
        A newa;
        newa.k = k + a.k;
        newa.h = h + a.h;
        cout << "operator Più +" << endl;
        return newa;
    }
    //Re: +=
    A& operator +=(const A& a){
        k += a.k;
        (*this).h += a.h;//uguale a h += a.h
        cout << "operator PiùUguale +=" << endl;
        return *this;
    }
    //Re: == (k only)
    bool operator ==(const A& a) const{
        return k == a.k;
    }
    //Re: != (k only)
    /*
    bool operator !=(const A& a) const{
        return k != a.k;
    }
    */
    //Re: != (k only) versione migliore
    bool operator !=(const A& a) const{
        return !((*this) == a);
    }
    //Re: ++a
    A& operator ++(){
        k++;
        return (*this);
    }
    //Funzioni friend
    friend ostream& operator <<(ostream& os, const A& a);
};
//Re: cout
ostream& operator <<(ostream& os, const A& a){
    return os << a.k << "-" << a.h;
}

//Confronto Float
//(h<a.h+EPSILON && h>a.h-EPSILON)

int main() {
    A a1, a2(1, 3.14), a3;
    cout << "a1=" << a1 << endl;
    cout << "a2=" << a2 << endl;
    a1 = a2;
    cout << "a1=" << a1 << endl;
    a1 = 8;
    cout << "a1=" << a1 << endl;
    a3 = a1 + a2;
    cout << "a3=" << a3 << endl;
    a3 += a2; // a3 = a3 + a2
    cout << "a3=" << a3 << endl;
    if(a1 == a2){
        cout << "a1 uguale a2" << endl;
    } else {
        cout << "NO UGUALE" << endl;
    }
    if(a1 != a2){
        cout << "a1 diverso a2" << endl;
    } else {
        cout << "NO DIVERSO" << endl;
    }

    cout << "PRE(++a) a1=" << a1 << endl;
    ++a1;
    cout << "POST(++a) a1=" << a1 << endl;

    return 0;
}