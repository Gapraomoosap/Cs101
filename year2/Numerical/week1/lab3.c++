#include<iostream>
#include <iomanip>

using namespace std;  
int main() {
    double Xl = 0.02,Xr = 0.03,Xm;
    double Fxm,Fxl,Fxr,Error=0.000001;
    while (true)
    {
        Xm = (Xl + Xr) / 2; 
        Fxm = (43*Xm) - 1;
        Fxl = (43*Xl) - 1;
        Fxr = (43*Xr) - 1;
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