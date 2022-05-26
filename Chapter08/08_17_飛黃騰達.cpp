/*

APCS：飛黃騰達 (2021/01/09 P4)

A. 題目
二維平面上的第一象限裡有許多點，意即 x,y≥0。請試著任選一個點出發，並且試著任選一個點出發，並嘗試走訪越多的點越好，但規定走訪的過程中只能從往x正向與y正向的方向走，比方說如果你從 〖(x〗_1,y_i) 走到 〖(x〗_2,y_2) ，即代表 x_2-x_1≥0 而且 y_2-y_1≥0，請找出在這個規則之下，你最多能夠走訪幾個點。

B. 題目出處
2021/01/09 APCS實作題 #4
本題可於 Zerojudge 中測試，網址如下：
https://zerojudge.tw/ShowProblem?problemid=f608

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    int x, y;
} Point;

bool cmp(Point* a, Point* b){
    // 根據 x 座標由小到大排
    // 如果 x 座標相同，則根據 y 座標由小到大排
    // 注意這裡傳入資料為指標
    if((a->x) != (b->x))
        return (a->x) < (b->x);
    else
        return (a->y) < (b->y);
}

int main(){
    int len;
    cin >> len;
    // 把 data 長度初始化成 len
    vector<Point*> data(len);
    // 輸入資料
    for(int i = 0; i < len; i++){
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        data[i] = new Point{tmp_x, tmp_y};
    }
    
    // 把資料按照題目要求加以排序
    // 排序後的資料才能進行二分搜尋
    sort(data.begin(), data.end(), cmp);
    // DP[i] 表示長度為 i 的路徑中最小的 y 為多少
    vector<int> DP(len + 1, 2147483647);
    DP[0] = -2147483648;

    // 按照 x 由小到大取出所有資料
    // 取出過程中的 y 值只能遞增，並盡可能選越多點
    // 為最長遞增子數列的搜尋
    for(auto point : data){
        // 利用二分搜尋法找出 y 的 upper bound
        // 不須嚴格遞增，所以找的是 upper bound
        auto iter= upper_bound(DP.begin(), DP.end(), point->y);
        *iter = point->y;
    }
    auto result = lower_bound(DP.begin(), DP.end(), 2147483647);
    // 該位置跟 vector 的起點距離再 - 1即是所求
    cout << result - DP.begin() - 1;
    return 0;
}
