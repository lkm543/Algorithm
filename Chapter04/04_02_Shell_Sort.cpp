#include<iostream>

using namespace std;

void Shell_Sort(int data[], int len)
{
    // gap 從 len / 2 開始
    for (int gap = len/2; gap > 0; gap /= 2)
    {
        // 對各組組內進行插入排序法
        for (int i = gap; i < len; i += 1)
        {
            int value = data[i];
            int j;
            for (j = i;
                j >= gap && data[j - gap] > value;
                j -= gap)
                data[j] = data[j - gap];

            data[j] = value;
        }
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Shell_Sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
