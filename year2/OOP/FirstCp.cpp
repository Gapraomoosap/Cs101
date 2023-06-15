#include <iostream>
using namespace std;
class status{
    virtual void Totalgrade()=0;
};

class CS : status
{
private:
    string Name;
    int No;
    float Grade;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setNo(int no)
    {
        No = no;
    }
    int getNo(){
        return No;
    }

    CS(string name, int no, float grade)
    {
        Name = name;
        No = no;
        Grade = grade;
    }
    void Totalgrade(){
        if(Grade <2.0)
            cout << "Bye bye";
        else
            cout << "still in the hell";
    }
};

int main()
{
    CS Ra = CS("Peerasin", 20, 1.9);
    CS Rb = CS("Smild", 25, 3.5);
   
    Ra.Totalgrade();
    Rb.Totalgrade();

    return 0;
}