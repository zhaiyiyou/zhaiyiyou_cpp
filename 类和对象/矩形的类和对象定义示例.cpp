#include <iostream>
using namespace std;

class Rectangle{
    int l;
    int s;
    public:
        int getArea()
        {
            return l*s;
        }
        int getC(){
            return (l+s)*2;
        }
        void init(int a,int b){
            l = a;
            s = b;
        }
};

int main()
{
    Rectangle r;
    int a,b;
    cin >> a >> b;
    r.init(a,b);
    cout << r.getArea() << endl;
    cout << r.getC() << endl;
    return 0;
}