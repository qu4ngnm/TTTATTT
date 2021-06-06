#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
int main()
{
    int a, b;
    cout<<"Nhap a: ";cin>>a;
    cout<<"Nhap b: ";cin>>b;
    cout<<"UCLN cua 2 so a va b la: "<<gcd(a,b);
}
