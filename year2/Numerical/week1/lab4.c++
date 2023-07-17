#include<iostream>
#include <iomanip>
#include<cmath>

using namespace std;  
int main() {
    double Xl = 0,Xr = 10,Xm;
    double Fxm,Fxl,Fxr,Error=0.000001;
    while (true)
    {
        Xm = (Xl + Xr) / 2; 
        Fxm = (pow(Xm,2)) - 7;
        Fxl = (pow(Xl,2)) - 7;
        Fxr = (pow(Xr,2)) - 7;
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