#include <iostream>

using namespace std;

int Partition(int data[], int start, int finish){
    // 選擇區間最右邊的值做為 Pivot
    int pivot = data[finish];
    // 把比 Pivot 小的值依序移動到左側
    int p = start;
    for(int i = start; i < finish; i++){
        if(data[i] < pivot){
            int tmp = data[i];
            data[i] = data[p];
            data[p] = tmp;
            p++;
        }
    }
    int tmp = data[finish];
    data[finish] = data[p];
    data[p] = tmp;
    // 最後回傳 Pivot 所在的 index
    return p;
}


void Quick_Sort(int data[], int start, int finish){
    if (start < finish) {
        // 取出 Pivot 後，會回傳 Pivot 最後所在的 index
        int pivot = Partition(data, start, finish);
        // 對 Pivot 的兩端再進行下一輪的 Quick Sort
        Quick_Sort(data, start, pivot - 1);
        Quick_Sort(data, pivot + 1, finish);
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Quick_Sort(arr, 0, 9);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
