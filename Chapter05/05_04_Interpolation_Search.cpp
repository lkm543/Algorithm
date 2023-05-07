#include <iostream>

using namespace std;

int Interpolation_Search(int data[], int lower, int upper, int target){
    // 邊界條件：區間內沒有資料
    if(upper < lower)
        return -1;
    int upper_data = data[upper];
    int lower_data = data[lower];

    if(upper >= lower && target >= lower_data && target <= upper_data){
        // 透過公式算出目標最可能在的索引值 index
        int index = lower + (target - lower_data) * (upper - lower) / (upper_data - lower_data);
        // 與二分搜尋法一樣分成三種情況處理
        // data[index] 正好就是目標
        if(data[index] == target)
            return index;
        // data[index] 比目標的值大
        // 尋找左側區間
        else if(data[index] > target)
            return Interpolation_Search(data, lower, index - 1, target);
        // data[index] 比目標的值小
        // 尋找右側區間
        else if(data[index] < target)
            return Interpolation_Search(data, index + 1, upper, target);
    }
    return -1;
}

int main()
{
    int target;
    int arr[10] = {12,27,35,36,47,52,52,52,68,74};
    cout << "Please enter the target you would like to search:" << endl;
    cin >> target;

    cout << "Index of " << target << " is " << Interpolation_Search(arr,0,9,target);

    return 0;
}
