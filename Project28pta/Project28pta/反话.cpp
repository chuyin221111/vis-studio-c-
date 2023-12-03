#include <iostream>
using namespace std;
#include <cstring>
int main()
{
    string arr[80];
    int a = 0;
    char c;
    while (1)
    {
        cin >> arr[a];
        a++;
        c = getchar();
        if (c == '\n')
            break;
    }
    for (int i = a - 1; i >= 0; i--)
    {
        cout << arr[i];
        cout << " ";
    }
    return 0;
}