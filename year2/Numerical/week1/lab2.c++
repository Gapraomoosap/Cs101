#include<iostream>
#include <iomanip>
#include<cmath>

using namespace std;  
int main() {
    double Xl = 1.5,Xr = 2.0,Xm;
    double Fxm,Fxl,Fxr,Error=0.000001;
    while (true)
    {
        Xm = (Xl + Xr) / 2; 
        Fxm = (pow(Xm,4)) - 13;
        Fxl = (pow(Xl,4)) - 13;
        Fxr = (pow(Xr,4)) - 13;
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
    cout << "Value : " << Xm;
}