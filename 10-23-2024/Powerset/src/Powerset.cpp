/*
    project name: Powerset

    author: 41243144 温博鈞

    description: 給定一個字串集合，輸出該字串的子集合

    function:
        - main(): 主程式執行，輸入字串集合後呼叫 class Powerset()
        - Powerset(string): 建構子，當Powerset被建立時構建stop = 
        2 ^ 字串長度

        - print_subset(string, int): 傳入字串並且書出該字串子集合，當每次

    global variable:
        - MAX_DEAPH: 指定最大遞迴深度
        - recurse_deaph: 紀錄目前遞迴深度
        - max_n: print出在不同m值下，n的最大可計算值

    latest edit date: 10-17-2024
*/

#include <iostream>
#include<string>

using namespace std;

class Powerset {
public:
    // 初始化停止條件
    int stop = 1;

    Powerset(string str = "abc") {
        // 計算字串長度
        size_t count = str.length();
        // 停止條件設定為2^length
        while (count) {
            stop *= 2;
            count--;
        }
        cout << "S(" << str << ") = {";
        print_subset(str, 0);
    }

    void print_subset(string str, short int count) {
        /*
            輸出string的所有子集合
            args:
                - str: 字串集合
                - count: 計數器
        */
       // 若計數器 = 停止條件時輸出又括號後返回
        if (count == stop) {
            cout << "}\n";
            return;
        }

        cout << '(';
        bool Fg = false;

        // 執行(字串長度)次，每次將i右移2位元
        for (int i = 0; i < str.length(); i++) {
            if (count & (1 << i)) {
                // 第一次不用,
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
    // 使用者輸入
    string user_input_str;
    cout << "請輸入一個集合字串:";
    cin >> user_input_str;

    Powerset run(user_input_str);
    
    system("pause");
    return 0;
}