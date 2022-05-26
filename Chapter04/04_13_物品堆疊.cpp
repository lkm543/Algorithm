/*

APCS：物品堆疊 (2017/10/18 P4)

A. 題目

某個自動化系統中以一個存取物品的子系統，該系統將 N 個物品堆在一個垂直的貨架上，每個物品各佔一層。

系統運作的方式如下：每次只會取用一個物品，取用前必須先將在其上方的物品貨架升高，取用後，必須將該物品放回，然後將剛才升起的貨架降回原始位置，才會繼續進行下一個物品的取用。

每一次升高某些物品所需要消耗的能量以這些物品的總重來計算，忽略貨架本身的重量以及其他消耗。

現在有 N 個物品，第 i 個物品的重量是 w(i)，而需要取用的次數為 f(i)，如何擺放這些物品，可以使消耗的能量最小？

舉例來說，若有兩個物品 w(1)=1、w(2)=2、f(1)=3、f(2)=4，代表物品 1 的重量是 1，需取用 3 次，物品 2 的重量是 2，需取用 4 次。

B. 2017/10/18 APCS 實作題 #4 
本題可以到 zerojudge 上提交程式碼，網址為：
https://zerojudge.tw/ShowProblem?problemid=c471

*/

#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

// 自訂的排序函式
// 物品 index 越小代表放在越上面
bool compare(pair<int,int> a, pair<int,int> b){
    return a.first * b.second < a.second * b.first;
}

int main(){
    long long int n, sum = 0;
    // 儲存物品資訊的向量
    // 一個 pair 可以儲存關於該物品的兩個資料
    vector<pair<int,int>> objects;
    long long int total_cost = 0;

    // 取得物品數目並調整向量大小
    cin >> n;
    objects.resize(n);

    // 取得每個物品的重量
    for (int i = 0; i < n; i++){
        cin >> objects[i].first;
    }

    // 取得每個物品的取用次數
    for (int i = 0; i < n; i++){
        cin >> objects[i].second;
    }

    // 利用自訂規則排序
    sort(objects.begin(), objects.end(), compare);

    // 計算總消耗能量
    for (int i = 0; i < n - 1; i++){
        // sum 是上面 i+1 件物品的總重量
        sum += objects[i].first;
        // 上面 i+1 件物品要移動 第 (i+1)+1 件物品的取用次數
        total_cost += sum*objects[i+1].second;
    }

    cout << total_cost << endl;

    return 0;
}
