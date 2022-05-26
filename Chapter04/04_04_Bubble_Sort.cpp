#include<iostream>

using namespace std;

void Bubble_Sort(int data[], int len){
    // 重複 len - 1 輪
    for(int i = 0; i < len - 1; i++){
        // 每多做一輪就可以少做最後一筆資料
        // 因為每一輪中剩下的最大值都會被移到最右邊
        for(int j = 0; j < len - i - 1; j++){
            // 如果左邊 data[j] 大於右邊 data[j+1] 就互換
            if(data[j] > data[j+1]){
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Bubble_Sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
