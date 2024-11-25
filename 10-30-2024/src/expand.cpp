/*
	file name: expand.cpp
	description:
		��l�ƶO���ƦC�A�îھڨϥΪ̿�J�Ʀr�ʺA�ܧ�}�C�j�p�A�ÿ�Xfib(0)-fib(n - 1)�ƦC
		
	function:
		-  void expand_array(int*& arr, int array_length, int target_size): �ܧ�}�C�j�p�f��R�������O���ƦC
	
	author: 41243144 �ųնv 
	
	latest edit date: 10-30-2024
			
*/ 

#include <iostream>

// �s�Wstd�R�W�Ŷ� 
using namespace std;

void expand_array(int*& arr, int array_length, int target_size) {
	/*
		�ܧ�}�C�j�p�åB��J�����O���ƦC
		
		args:
			int*& arr: ��l�}�C��m
			int array_length:��l�}�C����
			int target_size: �ܧ��}�C�j�p
		
		return:
			void 
	*/
	
	// �إߤ@�Ӫ��׬����ܧ�}�C�j�p���}�C 
    int* new_arr = new int[target_size];
    // �ƻs��l�j�p�����ܷs�}�C 
    copy(arr, arr + array_length , new_arr);
    // ����O����Ŷ� 
    delete[] arr;

	// ��J�����O���ƦC 
    for (int i = array_length; i < target_size; i++) {
        new_arr[i] = new_arr[i - 1] + new_arr[i - 2];
    }
	
	// �N new_arr ���Хᵹ arr 
    arr = new_arr;
}

int main()
{
	// ��l�ƶO���ƦC����&�Ѽ� 
    int array_length = 2, current = 2;
    int* arr = new int[2];

    arr[0] = 0;
    arr[1] = 1;

    while (cin >> array_length) {
    	// �Y�ϥΪ̿�J>��e�j�p�h�X�R�}�C����e�ϥΪ̿�J���j�p 
        cout << "��e�}�C���׬�: " << current;
        if (array_length > current) {
            cout << "�ثe�]�w���פj��}�C���סA�ݭn�X�R�}�C" << endl;
            expand_array(arr, current, array_length);
            current = array_length;
            cout << "��s�L��}�C���e: " << endl;
        }
        else {
            cout << endl;
            cout << "�}�C���e: " << endl;
        }
        
        // ��ܰ}�C���e 
        
        for (int i = 0; i < array_length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
