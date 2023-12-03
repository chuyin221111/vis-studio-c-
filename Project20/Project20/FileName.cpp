//����㷨������ջ���ж�һ���������ʽ�е�Բ�����Ƿ���ȷ��ԡ�
//��ʾ��ÿ��ɨ�赽��(�����ͽ����ջ��ÿ��ɨ�赽��)�����ͽ���ǰջ���ġ�(����ջ�������ʱջ����Ԫ�ؿɳ������������Բ���ȷ������
//���ȫɨ�����ջΪ�գ��������ȷ��ԣ���֮���ջ�л���Ԫ�أ���ƥ�䲻�ɹ���
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
                cout << "��ƥ��" << endl;
                return 0;
            }
        break;        case '\n':
            if (s.top == -1) {
                cout << "ƥ��" << endl;
                return 0;
            }
            else {
                cout << "��ƥ��" << endl;
                return 0;
            }
            break;
        }
    }
    return 0;
}

