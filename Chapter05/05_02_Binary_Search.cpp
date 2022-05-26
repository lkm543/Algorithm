#include <iostream>

using namespace std;

int Binary_Search(int data[], int lower, int upper, int target){
    if(upper < lower)
        return -1;
    int middle = (lower + upper) / 2;
    // 中位數 == target
    if(data[middle] == target)
        return middle;
    // 中位數 > target，搜尋左側
    else if(data[middle] > target)
        return Binary_Search(data, lower, middle - 1, target);
    // 中位數 < target，搜尋右側
    else if(data[middle] < target)
        return Binary_Search(data, middle + 1, upper, target);
}

int main()
{
    int target;
    int arr[10] = {12,27,35,36,47,52,52,52,68,74};
    cout << "Please enter the target you would like to search:" << endl;
    cin >> target;

    cout << "Index of " << target << " is " << Binary_Search(arr,0,9,target);

    return 0;
}
