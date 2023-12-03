#include <iostream>
using namespace std;
int main()
{
    int c;
    cin >>c;
    int a;
    int i = 3;
    while (i >0)
    {
        a = c % 10;
        if (a != 0)
        {
            cout << a;
        }

        c = c / 10;
        i--;
    }
}