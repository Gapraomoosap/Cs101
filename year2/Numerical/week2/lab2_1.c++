#include <iostream>
#include <cmath>

using namespace std;
double Fx(double Xn)
{
    return pow(Xn,4)-13;
}
int main() {
    double XL=1.5,XR=2.0;
    double X1;
    double Fxr,Fxl,Fx1;
    while(1)
    {
        Fxl = Fx(XL);
        Fxr = Fx(XR);
        X1 = ((XL * Fxr) - (XR * Fxl)) / (Fxr - Fxl);
        Fx1 = Fx(X1);
        if(Fx1 * Fxr > 0){XR = X1;}
        else{XL = X1;}
        if(abs(Fx1) < 0.00001){break;}
    }
    printf("Value is: %f",X1 );
}