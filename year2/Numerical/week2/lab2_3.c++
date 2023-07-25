#include <iostream>
#include <cmath>
using namespace std;
double Fx(double X){
    return ((sqrt(7)+X)/2);
}

int main(){
    double array[1000];
    double F_Value = 0;
    double X = F_Value,Error = 0.000001;
    array[0] = F_Value;
    for(int i = 1 ; true ; i++)
    {
        array[i] = Fx(X);
        X = array[i];
        if(abs(array[i]) - abs(array[i-1]) < Error){
            cout << array[i]<< endl;
            break;
        }
    }
}