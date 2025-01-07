#include <iostream>

using namespace std;


// 建立ChainNode並根據參數內容作初始化
template<typename T>
struct ChainNode
{
    T val;
    ChainNode* next;

    ChainNode() { val = 0; next = nullptr; }
    ChainNode(const T& data) { val = data; next = nullptr; }
    ChainNode(const T& data, ChainNode<T>* link) { val = data; next = link; }

};

template<class T1>
class Chain {
private:
    // 建立dummy
    ChainNode<T1>* dummy;
    ChainNode<T1>* first = dummy;
    int length;

public:
    Chain() {
        /*
        *   若沒收到參數預設將dummy設定為空指標
        */
        dummy = nullptr;
        length = 0;
    }

    Chain(T1& val) {
        /*
        *   若收到參數預設將dummy->val設定為參數
        */
        dummy->val = val;
        length = 0;
    }

    int index(T1 target) {
        /*
        *   找出target索引直，若迭代器到最後一項時回傳-1
        */
        ChainNode<T1>* iterator = first;
        int index = 0;

        while (iterator != nullptr)
        {
            if (iterator->val == target) return index;
            index++;
            iterator = iterator->next;
        }
        return -1;
    }

    void insert(T1 element) {
        /*
        *   將element插入到連結串列最後一項
        */
        if (dummy == nullptr) {
            /*
            *   若dummy初始化為nullptr，必須給其新的ChainNode並更新first
            */
            dummy = new ChainNode<T1>(element);
            first = dummy;
        }
        else {
            dummy->next = new ChainNode<T1>(element);
            dummy = dummy->next;
        }
        length++;
    }

    void erase() {
        /*
        *   移除最後一項
        */
        ChainNode* left = first;
        ChainNode* right = first;

        if (dummy == left) return;

        while (right != nullptr) {
            if (right == dummy) {
                dummy = left;
                delete right;
                length--;
                return;
            }
            left = right;
            right = right->next;
        }

    }
    void erase(T1 element) {
        /*
            移除指定元素的連結串列
        */
        ChainNode<T1>* left = first;
        ChainNode<T1>* right = first;

        while (right != nullptr) {
            if (right->val == element) {
                left->next = right->next;
                delete right;
                length--;
                return;
            }
            right = right->next;
        }
    }
    int size() {
        return length;
    }

};

int main() {
    Chain<int> test;
    cout << "本程式將0-9放進連結串列中" << endl;

    for (int i = 0; i < 10; i++) {
        test.insert(i);
    }
    cout << "連結串列長度: " << test.size() << endl;
    cout << "3的index為: " << test.index(3) << endl;
    cout << "10的index為: " << test.index(10) << endl;

    cout << "---------------------------------" << endl;
    cout << "將3從連結串列中移除" << endl;
    test.erase(3);
    cout << "連結串列長度: " << test.size() << endl;
    cout << "3的index為: " << test.index(3) << endl;

    return 0;
}