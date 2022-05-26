#include<iostream>

using namespace std;

void Shaker_Sort(int data[], int len){
    // left, right 紀錄左右兩端的位置
    int left = 0, right = len - 1, shift = 1;

    while(left < right) {
        // 對 left 到 right 的範圍從左到右進行冒泡排序法
        for(int i = left; i < right; i++) {
            // 左邊比右邊大，互換
            if(data[i] > data[i + 1]) {
                int tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                // 記錄下最後互換的位置
                shift = i;
            }
        }
        right = shift;
        // 對 left 到 right 的範圍從右到左進行冒泡排序法
        for(int i = right - 1; i >= left; i--) {
            if(data[i] > data[i+1]) {
                int tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                // 記錄下最後互換的位置
                shift = i + 1;
            }
        }
        left = shift;
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Shaker_Sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}