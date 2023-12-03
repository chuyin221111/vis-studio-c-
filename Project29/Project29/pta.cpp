#include <iostream>
using namespace std;
int main()
{
    char A[3];
    int i;
    for (i = 0; i <= 2; i++)
    {
        cin >> A[i];
        
    }
    for (i=2; i >= 0; i--)
    {
        if (A[i] != '0') break;
    }
    for (; i >= 0; i--)
    {
        cout << A[i];
    }
}