#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;
int main() {
    double n,x;
    double Xl = 0,Xr = 1000000,Xm;
    double Fxm,Fxl,Fxr,Error=0.000001;
    cin >> x >> n;
    while(true)
    {
        Xm = (Xl + Xr) / 2; 
        Fxm = (pow(Xm,n)) - x;
        Fxl = (pow(Xl,n)) - x;
        Fxr = (pow(Xr,n)) - x;
        if(Fxm * Fxl > 0)
        {
            Xl = Xm;
        }
        else{
            Xr = Xm;
        }
        if(Fxm < Error && Fxm > -Error)
        { break;}
    }
    cout << fixed << setprecision(6);
    cout  << Xm << endl;

}