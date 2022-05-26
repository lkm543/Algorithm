#include<iostream>

using namespace std;

void Selection_Sort(int data[], int len)
{
    for (int i = 0; i < len - 1; i++) {
        // 找到 data[i] ~ data[len-1] 中的最小值
        int minimal_index = i;
        for (int j = i + 1; j < len; j++) {
            if (data[j] < data[minimal_index]) {
                minimal_index = j;
            }
        }
        // 把最小值跟 data[i] 互換
        int temp = data[minimal_index];
        data[minimal_index] = data[i];
        data[i] = temp;
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Selection_Sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
