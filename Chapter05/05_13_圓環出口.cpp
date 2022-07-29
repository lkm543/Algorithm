/*
APCS：基地台 (2017/03/04 P4)

A. 題目

給定 N 個房間排成一個環，其中編號 i 的房間可以走到編號 (i +1) mod N 的房間，i 的編號為 0 ~ N - 1，並且路徑為單向，且每次進入編號 i 的房
間可以獲得 pi 個點數，同時最一開始待的房間也可以獲得點數。

另外有 M 個任務，第 i 個任務需要蒐集到 qi 個點數，若一開始在編號 0 的房間，當點數達到 qi 時就可以完成第 i 個任務後並清空所有點數，清空
點數後會進到下一個房間，當收集完 M 把鑰匙時，最後會停在哪個編號的房間？

B. 題目出處

2020/07/04 APCS 實作題#3
本題可以到 zerojudge 上提交程式碼，網址為：
https://zerojudge.tw/ShowProblem?problemid=f581

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    // 輸入並計算前綴和
    vector<int> p(N), prefix_sum(N, 0);
    for (int i = 0; i < N; i++){
        cin >> p[i];
        prefix_sum[i] += p[i];
        if (i != 0)
            prefix_sum[i] += prefix_sum[i - 1];
    }

    // 依序接受任務
    int q, last_room = -1;
    for (int i = 0; i < M; i++){
        cin >> q;
        // last_room: 上次停留的房間
        // 本次目標為 q + prefix_sum[last_room]
        if (last_room != -1)
            q += prefix_sum[last_room];
        // 若超出範圍則扣掉所有房間之總和
        if (q > prefix_sum[N - 1])
            q -= prefix_sum[N - 1];
        // 利用 lower_bound 找出可達成需求之最小索引值的房間
        last_room = lower_bound(prefix_sum.begin(), prefix_sum.end(), q) - prefix_sum.begin();
    }
    cout << (last_room + 1) % N << endl;
    return 0;
}
