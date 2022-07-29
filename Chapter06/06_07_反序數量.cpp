/*
APCS：反序數量 (2018/06 P4)

A. 題目

給定一陣列 p，若 i < j 但 p[i] > p[j]，則稱 (p[i]，p[j]) 為反序對，請試著陣列 p 之反序對數量。

比方說給定陣列 p 為 [5, 6, 2, 1 ,3]，反序對為 (5, 2)、(5, 1)、(5, 3)、(6, 2)、(6, 1)、(6, 3)、(2, 1)，共七個反序。


B. 題目出處

2018/06 APCS 實作題#4
本題可以到一中電腦資訊研究社 Online Judge上提交程式碼
網址為： https://judge.tcirc.tw/ShowProblem?problemid=d064

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> p;

long long int DC(vector<int>& p){
    if(p.size() < 2)
        return 0;
    long long int sum = 0;
    int max = -2147483648;
    int min = 2147483647;
    // 取出陣列最大與最小值
    for(int value : p){
        if(value > max)
            max = value;
        if(value < min)
            min = value;
    }
    if(max == min)
        return 0;

    int medium = min + (max - min) / 2;

    vector<int> smaller;
    vector<int> bigger;
    // 依序取出資料
    for(int value : p){
        if(value <= medium){
            smaller.push_back(value);
            // value 在 bigger 的右側且又比 bigger 小
            // 故 bigger 的大小就是 value 的子序對數目
            sum += bigger.size();
        }
        else
            bigger.push_back(value);
    }
    return sum + DC(smaller) + DC(bigger);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> p(N);

    // 輸入資料
    for (int i = 0; i < N; i++)
        cin >> p[i];
    cout << DC(p) << endl;
    return 0;
}
