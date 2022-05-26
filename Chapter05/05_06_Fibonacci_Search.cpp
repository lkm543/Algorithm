#include <iostream>

using namespace std;

int Fibonacci_Search(int data[], int len, int target)
{
    int fibo_1 = 0;
    int fibo_2 = 1;
    int fibo_3 = fibo_1 + fibo_2;

    // 先找大於等於陣列長度 len 的最小費氏數
     while (fibo_3 < len) {
        fibo_1 = fibo_2;
        fibo_2 = fibo_3;
        fibo_3 = fibo_1 + fibo_2;
    }

    // 目前所在的索引值
    int current = fibo_1 - 1;
    current = current >= 0 ? current : 0;

    // 目標在 fibo_1 - 1右側，須加上 m
    if (data[current] < target) {
        current = len - fibo_2;
    }

    while (fibo_3 > 0) {
        current = current >= 0 ? current : 0;
        current = current < len ? current : len - 1;
        // 找到目標，回傳索引值 current
        if(data[current] == target)
            return current;
        // 目標資料在 current 的右側
        // current 往右移動 fibo_1
        else if (data[current] < target) {
            fibo_3 = fibo_2;
            fibo_2 = fibo_1;
            fibo_1 = fibo_3 - fibo_2;
            current += fibo_1;
        }
        // 目標資料在 current的左側
        // current 往左移動 fibo_1
        else if (data[current] > target) {
            fibo_3 = fibo_2;
            fibo_2 = fibo_1;
            fibo_1 = fibo_3 - fibo_2;
            current -= fibo_1;
        }
    }
    // 找不到資料，回傳 -1
    return -1;
}


int main()
{
    int target;
    int arr[10] = {12,27,35,36,47,52,52,52,68,74};
    cout << "Please enter the target you would like to search:" << endl;
    cin >> target;

    cout << "Index of " << target << " is " << Fibonacci_Search(arr, 10, target);

    return 0;
}
