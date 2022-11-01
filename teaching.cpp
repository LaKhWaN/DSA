#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int Sum;
    int sub;
    int mult;
    int div;

    cout<<"enter first number: ";
    cin>>a;
    cout<<"enter second number: ";
    cin>>b;

    Sum=a+b;
    sub=a-b;
    mult=a*b;
    div=a/b;

    cout<<"add them: "<<Sum<<endl;
    cout<<"subtract them: "<<sub<<endl;
    cout<<"multiply them: "<<mult<<endl;
    cout<<"divide them: "<<div;

    return 0;
}