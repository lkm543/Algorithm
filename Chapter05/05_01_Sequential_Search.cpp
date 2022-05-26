#include <iostream>

using namespace std;

// 傳入引數中，data[]是資料結構
// len 是資料筆數、target 是要找的目標
int Sequential_Search(int data[], int len, int target){
	for (int i = 0; i < len; i++){
		// 目前檢查的資料是目標資料時，回傳索引值
		if (data[i] == target)
			return i;
		// 找到陣列結尾仍然沒有找到時，回傳 -1
		else if (i == len-1)
			return -1;
	}
}

int main()
{
    int target;
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Please enter the target you would like to search:" << endl;
    cin >> target;

    cout << "Index of " << target << " is " << Sequential_Search(arr, 10, target);

    return 0;
}
