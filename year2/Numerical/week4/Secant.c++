#include <iostream>
#include <cmath>
using namespace std;
double Fx(double X){
    return (X*X-7);
}
double DFx(double X0,double X1) {
    return X1 - (Fx(X1)*(X1-X0))/(Fx(X1)-Fx(X0));
}
int main(){
    double F_Value = 1.0,Assume_Value = 0;
    double O_Value = F_Value,O2_Value,C_Value,Error = 0.0000001;
    C_Value = DFx(F_Value,Assume_Value);//First value X2
    while (abs(C_Value - O_Value) >= Error)
    {
        O2_Value = O_Value;//Set Xn-2 = Xn-1
        O_Value = C_Value; //Set Xn-1 = Xn
        C_Value = DFx(O2_Value,O_Value); //update new value
    }
    cout << "Value : "<< C_Value<<endl ;
}