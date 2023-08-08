#include <iostream>
#include <cmath>
using namespace std;
double Fx(double X){
    return ((X*X)-7);
}
double Fxd(double X){
    return 2*X;
}
int main(){
    double x = 2.0;
    double F_Value = x -(Fx(x)/Fxd(x));
    double O_Value = 0,C_Value,Error = 0.000001;
    C_Value = F_Value;
    while (abs(C_Value - O_Value) >= Error)
    {
        O_Value = C_Value;
        C_Value = O_Value - (Fx(O_Value)/Fxd(O_Value));
    }
        cout <<"Value : "<< C_Value << endl;
     
}
