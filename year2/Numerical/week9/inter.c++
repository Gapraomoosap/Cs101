#include<iostream>
using namespace std;
void L(int n,double l[5],double Value,double X[5])
{
    double ans =1;
    for(int i =0 ; i< 5 ;i++)
    {
        if(i == n){
        }
        else{
            ans = ans * (X[i]-Value)/(X[i]-X[n]);
        }
    }
    l[n] = ans;
}
int main() 
{
    double X[] = {0,20000,40000,60000,80000};
    double Y[] = {9.81,9.7487,9.6879,9.6879,9.5682};
    double l[5],Fx=0 ;
    double Xn = 42235;
    for(int i = 0 ; i<5;i++)
    {
        L(i,l,Xn,X);
        Fx = Fx + (l[i]*Y[i]);
        cout <<"L[" <<i<<"] ="<< l[i] << endl;
    }
    cout <<"Fx : "<< Fx;

}