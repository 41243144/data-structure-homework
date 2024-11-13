#include <iostream>
#include <string>

using namespace std;


// 建立樣板
template<class T1, class T2>


// class 
class Bs {
private:
    // 定義陣列arr
    T1 *arr;

public:
    // 建構子
    Bs(int length) {
        // 初始化陣列
        this->arr = new T1[length];
    }
    // 解構子
    ~Bs() {
        delete[] arr;
    }

    // 傳遞參數
    void update_array(T1 element, int index) {
        arr[index] = element;
    }

    // 二分搜
    int binary_search(int left, int right, T2 target) {
        // cout << left << " " << right << " " << target << endl;

        // 找不到回傳-1
        if (left > right) return -1;
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        else if(arr[mid] < target) {
            return binary_search(mid + 1, right, target);
        }
        else {
            return binary_search(left, mid - 1, target);
        }
    }
};



int main()
{
    char ch;
    int data_number, test_number;
    while (cin >> ch) {
        cin >> data_number >> test_number;

        if (ch == 'i') {

            int element;
            Bs<int, int> run(data_number);

            for (int i = 0; i < data_number; i++) {
                cin >> element;
                run.update_array(element, i);
            }

            int test;

            while (test_number--)
            {
                cin >> test;
                cout << run.binary_search(0, data_number - 1, test) << endl;
            }
        }
        else if (ch == 's') {
            string element;
            Bs<string, string> run(data_number);

            for (int i = 0; i < data_number; i++) {
                cin >> element;
                run.update_array(element, i);
            }

            string test;

            while (test_number--)
            {
                cin >> test;
                cout << run.binary_search(0, data_number - 1, test) << endl;
            }
        }
        cout << endl;
    }
}
