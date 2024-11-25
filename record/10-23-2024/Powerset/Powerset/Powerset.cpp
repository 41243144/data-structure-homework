#include <iostream>
#include<string>

using namespace std;

class Powerset {
public:
    int stop = 1;
    Powerset(string str = "abc") {
        size_t count = str.length();
        while (count) {
            stop *= 2;
            count--;
        }
        cout << "S(" << str << ") = {";
        print_subset(str, 0);
    }
    void print_subset(string str, short int count) {
        if (count == stop) {
            cout << "}\n";
            return;
        }
        cout << '(';
        bool Fg = false;
        for (int i = 0; i < str.length(); i++) {
            if (count & (1 << i)) {
                if (!Fg) {
                    Fg = true;
                }
                else {
                    cout << ',';
                }
                cout << str[i];
            }
        }
        cout << ')';
        if (count + 1 < stop) {
            cout << ",";
        }
        print_subset(str, count + 1);
    }
};

int main()
{
    string user_input_str;
    cout << "請輸入一個集合字串:";
    cin >> user_input_str;
    Powerset run(user_input_str);
    system("pause");
    return 0;
}