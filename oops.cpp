#include <iostream>
using namespace std;

class A {
    private: // private data members, accessible only by member functions 
        int x=10; 
    public: // public data members, accessible by any function
        void display() { 
            cout << "x = " << x << endl;
        }
};
int main()
{
    // create an object of class A
    A a;
    // call the display() function
    a.display();
    return 0;
}