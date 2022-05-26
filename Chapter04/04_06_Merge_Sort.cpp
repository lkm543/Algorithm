#include <iostream>
#include <stdlib.h>

using namespace std;

void Merge(int data[], int start, int finish, int middle){
    int size_left = middle - start + 1;
    int size_right = finish - middle;
    // 把資料分成左右半部
    int* left = (int *) malloc(sizeof(int) * (size_left + 1));
    int* right = (int *) malloc(sizeof(int) * (size_right + 1));

    // 把資料搬遷到暫存用的空間
    memcpy(left, data + start, sizeof(int) * (size_left));
    memcpy(right, data + middle + 1, sizeof(int) * (size_right));

    // 在左右兩邊的最末端新增無限大
    // 用整數的最大值代替無限大
    left[size_left] = 2147483647;
    right[size_right] = 2147483647;

    int left_index = 0, right_index = 0;

    // 把 left 與 right 兩陣列融合在一起
    for(int i = start; i <= finish; i++){
        if(left[left_index] <= right[right_index]){
            data[i] = left[left_index];
            left_index++;
        }
        else{
            data[i] = right[right_index];
            right_index++;
        }
    }
    free(left);
    free(right);
}

void Merge_Sort(int data[], int start, int finish){
    if(finish > start){
        int middle = (finish+start) / 2;
        Merge_Sort(data, start, middle);
        Merge_Sort(data, middle + 1, finish);
        Merge(data, start, finish, middle);
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Merge_Sort(arr, 0, 9);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
