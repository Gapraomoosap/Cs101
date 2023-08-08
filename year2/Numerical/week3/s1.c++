#include <iostream>
#include <cmath>
using namespace std;
double Fx(double X){
    return ((2*X+1)/4);
}
int main(){
    double F_Value = 0.0;
    double O_Value = F_Value,C_Value,Error = 0.0000001;
    C_Value = Fx(F_Value);//First value X1
    while (abs(C_Value - O_Value) >= Error)
    {
        O_Value = C_Value; //Set old value = curent value
        C_Value = Fx(O_Value); //update new value
    }
    cout << "Value : "<< C_Value<<endl ;
}