/*
    project name: Ackermann Function

    author: 41243144 温博鈞

    description: 藉由遞迴及非遞迴方式算出阿克曼函式(Ackermann Function)的解

    function:
        - main(): 主程式執行，包含呼叫ackmann_function()及非遞迴程式
        - ackmann_function(): 利用遞迴方式計算阿克曼函式，並限制遞迴深度防止過度遞迴

    global variable:
        - MAX_DEAPH: 指定最大遞迴深度
        - recurse_deaph: 紀錄目前遞迴深度
        - max_n: print出在不同m值下，n的最大可計算值

    latest edit date: 10-17-2024
*/

#include <iostream>

using namespace std;


static int recurse_deaph = 0;
int MAX_DEAPH = 3000;

// 初始化函式
int ackmann_function(int, int);

int main()
{
    // 初始化m n
    int m, n;
    int max_arr[5] = { 0 };
    // print m = 0 - 3 and n = 0 - 10000之間每個 m 遞迴極限
    cout << "在m: " << 0 << "n最大值: " << 2147483646 << endl;
    max_arr[0] = 2147483646;
    for (int i = 1; i < 4; i++) {
        int max_n = 0;

        for (int j = 0; j < 10000; j++) {
            recurse_deaph = 0;
            ackmann_function(i, j);
            if (recurse_deaph < MAX_DEAPH)
                max_n = j;
            else {
                break;
            }
        }
        cout << "在m: " << i << "n最大值: " << max_n << endl;
        max_arr[i] = max_n;
    }

    // 不斷執行直到m = 0 and n = 0退出
    while (true) {
        recurse_deaph = 0;

        cout << "請輸入m n(結束請輸入0 0): ";
        cin >> m >> n;

        if (m == 0 && n == 0)
            break;
        if (m > 4) {
            cout << "m超出範圍" << endl;
            continue;
        }else if (max_arr[m] < n) {
            cout << "n超出範圍" << endl;
            continue;
        }

        // 呼叫遞迴
        cout << "使用遞迴解法: ";
        int recurse_result = ackmann_function(m, n);
        if (recurse_result == -1) {
            cout << "遞迴超過" << MAX_DEAPH << "次，放棄計算" << endl;
        }
        else {
            cout << recurse_result << endl;
        }

        // 非遞迴寫法

        /*
            利用阿克曼函式特性，當
            1. m = 0: n + 1
            2. m = 1: n + 2
            3. m = 2: 2 x (n + 3) - 3
            4. m = 3: 2 ^ (n + 3) - 3
            5. m = 4: n最大到1，超出的話無法表示
        */

        cout << "使用非遞迴解法: ";
        switch (m)
        {
        case 0:
            cout << n + 1 << endl;
            break;
        case 1:
            cout << n + 2 << endl;
            break;
        case 2:
            cout << 2 * (n + 3) - 3 << endl;
            break;
        case 3:
            cout << static_cast<long long>(pow(2, n + 3)) - 3 << endl;
            break;
        case 4:
            if (n == 0)
                cout << 13 << endl;
            else if (n == 1)
                cout << 65533 << endl;
            break;
        default:
            break;
        }
    }


    return 0;
}

int ackmann_function(int m, int n)
{
    /*
        每次堆疊+1，當堆疊超過指定最大堆疊時，返回-1
        args:
            - m : 對應Ack(m, n) 中的 m
            - n : 對應Ack(m, n) 中的 n
        return:
            m = 0: return n + 1
            n = 0: return ackmann_function(m - 1, 1)
            m > 0 and n > 0: return ackmann_function(m - 1, ackmann_function(m, n - 1))
    */
    recurse_deaph++;
    if (recurse_deaph >= MAX_DEAPH) {
        return -1;
    }

    int result;
    if (m == 0) {
        result = n + 1;
    }
    else if (n == 0) {
        result = ackmann_function(m - 1, 1);
        if (result == -1) return -1;
    }
    else {
        int a = ackmann_function(m, n - 1);
        if (a == -1) return -1;
        result = ackmann_function(m - 1, a);
        if (result == -1) return -1;
    }

    return result;
}
