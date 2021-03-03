#include <iostream>
using namespace std;


int main() {
    // p5
    // int x, y, z;
    // cout << "address of variable x: ";
    // cout << &x << endl;

    // cout << "address of variable y: ";
    // cout << &y << endl;

    // cout << "address of variable z: ";
    // cout << &z << endl;

    // p8
    // int a, b, c;
    // int *ptra, *ptrb, *ptrc;
    // ptra = &a;
    // ptrb = &b;
    // ptrc = &c;

    // while(cin >> a >> b){
    //     c = a + b;
    //     cout << "address of variable a: ";
    //     cout << &a << endl;

    //     cout << "address of variable b: ";
    //     cout << &b << endl;

    //     cout << "address of variable c: ";
    //     cout << &c << endl;

    //     cout << "address value of " << ptra <<": ";
    //     cout << *ptra << endl;

    //     cout << "address value of " << ptrb <<": ";
    //     cout << *ptrb << endl;

    //     cout << "address value of " << ptrc <<": ";
    //     cout << *ptrc << endl;

    // }

    // p10
    // int a;
    // int *p;
    // cout << "address of variable a: ";
    // cout << &a << endl;

    // cout << "address of variable *p: ";
    // cout << &p << endl;

    // p = &a;
    // cout << "After doing p = &a;" << endl;
    // cout << "address of variable a: ";
    // cout << &a << endl;

    // cout << "address of variable *p: ";
    // cout << &p << endl;

    // cout << "The content of address "<< &a <<": ";
    // cout << a << endl;

    // cout << "The content of address "<< &p <<": ";
    // cout << p << endl;

    // p11
    // int a = 10;
    // int &r = a;
    // cout << "address of variable a: ";
    // cout << &a << endl;

    // cout << "address of variable r: ";
    // cout << &r << endl;

    // int b = 20;
    // r = b;
    // cout << "After doing int b = 20; r = b;" << endl;
    // cout << "address of variable a: ";
    // cout << &a << endl;

    // cout << "address of variable b: ";
    // cout << &b << endl;

    // cout << "address of variable r: ";
    // cout << &r << endl;
    
    // cout << "The content of address "<< &a <<": ";
    // cout << a << endl;

    // cout << "The content of address "<< &b <<": ";
    // cout << b << endl;

    // cout << "The content of address "<< &r <<": ";
    // cout << r << endl;

    //p14
    class Person{
    public:
        double height;
        double weight;
        double lenght;
    };
    Person x, y, z;
    cout << sizeof(x) << endl;
    cout << "address of variable x: ";
    cout << &x << endl;

    cout << "address of variable y: ";
    cout << &y << endl;

    cout << "address of variable z: ";
    cout << &z << endl;

    int *a1 = new int;
    int *a2 = new int;
    Person *c1 = new Person;
    Person *c2 = new Person;
    Person *c3 = new Person;

    cout << "address of variable *a1: ";
    cout << &a1 << endl;

    cout << "address of variable *a2: ";
    cout << &a2 << endl;

    cout << "address of variable *c1: ";
    cout << &c1 << endl;

    cout << "address of variable *c2: ";
    cout << &c2 << endl;

    cout << "address of variable *c3: ";
    cout << &c3 << endl;



    return 0;
}