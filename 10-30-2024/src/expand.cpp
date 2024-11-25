/*
	file name: expand.cpp
	description:
		初始化費式數列，並根據使用者輸入數字動態變更陣列大小，並輸出fib(0)-fib(n - 1)數列
		
	function:
		-  void expand_array(int*& arr, int array_length, int target_size): 變更陣列大小病填充對應的費式數列
	
	author: 41243144 溫博鈞 
	
	latest edit date: 10-30-2024
			
*/ 

#include <iostream>

// 新增std命名空間 
using namespace std;

void expand_array(int*& arr, int array_length, int target_size) {
	/*
		變更陣列大小並且填入對應費式數列
		
		args:
			int*& arr: 原始陣列位置
			int array_length:原始陣列長度
			int target_size: 變更後陣列大小
		
		return:
			void 
	*/
	
	// 建立一個長度為欲變更陣列大小之陣列 
    int* new_arr = new int[target_size];
    // 複製原始大小元素至新陣列 
    copy(arr, arr + array_length , new_arr);
    // 釋放記憶體空間 
    delete[] arr;

	// 填入對應費式數列 
    for (int i = array_length; i < target_size; i++) {
        new_arr[i] = new_arr[i - 1] + new_arr[i - 2];
    }
	
	// 將 new_arr 指標丟給 arr 
    arr = new_arr;
}

int main()
{
	// 初始化費式數列元素&參數 
    int array_length = 2, current = 2;
    int* arr = new int[2];

    arr[0] = 0;
    arr[1] = 1;

    while (cin >> array_length) {
    	// 若使用者輸入>當前大小則擴充陣列為當前使用者輸入的大小 
        cout << "當前陣列長度為: " << current;
        if (array_length > current) {
            cout << "目前設定長度大於陣列長度，需要擴充陣列" << endl;
            expand_array(arr, current, array_length);
            current = array_length;
            cout << "更新過後陣列內容: " << endl;
        }
        else {
            cout << endl;
            cout << "陣列內容: " << endl;
        }
        
        // 顯示陣列內容 
        
        for (int i = 0; i < array_length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
