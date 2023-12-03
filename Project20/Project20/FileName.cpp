//设计算法，利用栈来判断一个算术表达式中的圆括号是否正确配对。
//提示：每次扫描到“(”，就将其进栈，每次扫描到“)”，就将当前栈顶的“(”出栈（如果此时栈中无元素可出，则输出“配对不正确”）；
//如果全扫描完后，栈为空，则表明正确配对，反之如果栈中还有元素，则匹配不成功。
#include <iostream>
using  namespace std;
#define maxsize 100

typedef struct {
    char optr[maxsize];
    int top;
} OPTR;

void initstack(OPTR& s) {
    s.top = -1;
}

bool push(OPTR& s, char c) {
    if (s.top == maxsize - 1)
        return false;
    s.top += 1;
    s.optr[s.top] = c;
    return true;
}

bool pop(OPTR& s, char& c1) {
    if (s.top == -1)
        return false;
    c1 = s.optr[s.top];
    s.top -= 1;
    return true;
}

bool gettop(OPTR s, char& c2) {
    if (s.top == -1)
        return false;
    c2 = s.optr[s.top];
    return true;
}

int main() {
    OPTR s;
    char a, b;
    initstack(s);
    while (a = getchar()) {
        switch (a) {
        case '(':
            push(s, a);
            break;
        case ')':
            if (!pop(s, b) || b != '(') {
                cout << "不匹配" << endl;
                return 0;
            }
        break;        case '\n':
            if (s.top == -1) {
                cout << "匹配" << endl;
                return 0;
            }
            else {
                cout << "不匹配" << endl;
                return 0;
            }
            break;
        }
    }
    return 0;
}

