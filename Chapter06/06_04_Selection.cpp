#include <iostream>
#include <algorithm>

using namespace std;

// 互換函式
void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(int data[], int start, int finish, int pivot){
    int i;
    // 找到 Pivot 的索引值 i
    for (i = start; i <= finish; i++)
        if (data[i] == pivot)
           break;
    // 把 Pivot 移到最後面
    Swap(data[i], data[finish]);
    // 把比 Pivot 小的值依序移動到左側
    int p = start;
    for(int i = start; i < finish; i++){
        if(data[i] < pivot){
            Swap(data[i], data[p]);
            p++;
        }
    }
    Swap(data[finish], data[p]);
    // 最後回傳 Pivot 所在的 index
    return p;
}

// 取中位數：排序後取中間的索引值
int Median(int data[], int len){
    sort(data, data + len);
    return data[len / 2];
}

int k_th_Smallest( int data[], int lower, int upper, int k){
    // 確認 k 在範圍內
    if(k > 0 && k <= upper - lower + 1)
    {
        // 目標陣列的長度
        int len = upper - lower + 1;
        // 五個五個一組，再找其中位數
        int median[(len + 4) / 5];
        int i;
        for(i = 0; i < len / 5; i++)
            median[i] = Median(data + lower + i * 5, 5);
        // 如果最後一組資料不足五個
        if(i * 5 < len)
        {
            median[i] = Median(data + lower + i * 5, len % 5);
            i++;
        }
        int MOM;
        // 如果只有一組資料，則 MOM 只能挑第一筆中位數
        if(i == 1)
            MOM = median[0];
        // 否則從每組資料的中位數陣列裏頭找 MOM
        else
            MOM = k_th_Smallest(median, 0, i - 1, i / 2);

        // 利用 Partition 區分成三組
        // 比 MOM 大、比 MOM 小、跟 MOM 一樣
        // index: 最後 Pivot 的位置
        int index = Partition(data, lower, upper, MOM);
        // index - lower + 1: 比 MOM 小的資料有幾個
        // 第 k 小的資料在比 MOM 小的那組裏頭
        if(index - lower + 1 > k)
            return k_th_Smallest(data, lower, index - 1, k);
        // 第 k 小的資料在跟 MOM 一樣的那組裏頭
        if(index - lower + 1 == k)
            return data[index];
        // 剩下的就是在比 MOM 大的那組裏頭
        // 新的 k: k - (index - lower + 1)
        int new_k = k - (index - lower + 1);
        return k_th_Smallest(data, index + 1, upper, new_k);
    }
    // 不符合規則，回傳 - 1
    return - 1;
}

int main()
{
    int target;
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Please enter the target you would like to search:" << endl;
    cin >> target;

    cout << "kth smallest of " << target << " is " << k_th_Smallest(arr,0,9,target);

    return 0;
}
