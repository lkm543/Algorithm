/*

APCS：勇者修煉 (2020/10 P3)

A. 題目
一開始有 M×N 的二維陣列 E，陣列內的資料為 -100 ~ +100，代表勇者落腳在該處會得到的經驗值，一開始勇者可以從第一列的任意位置開始，且每一步可以向左、向右、向下走，但不能回頭走過去已經走過的路，請算出勇者走到最後一列後，最多可以得到多少經驗值。

B. 題目出處
2020/10 APCS實作題 #3
本題可於 Zerojudge 中測試，網址如下：
https://zerojudge.tw/ShowProblem?problemid=f314

*/

#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    // E[j]:(i,j) 的經驗值
    // L[j]:從左邊至 i 的最大值
    // R[j]:從右邊至 i 的最大值
    // DP[i][j]:至(i,j)的最大值
    vector<int> E(N + 1, 0);
    vector<int> L(N + 2, 0);
    vector<int> R(N + 2, 0);
    // 宣告 (M + 1)*(N + 2) 的二維陣列
    vector<vector<int>> DP((M + 1), vector<int>(N + 2, 0));

    // 左右為 INT_MIN
    L[0] = L[N + 1] = -2147483648;
    R[0] = R[N + 1] = -2147483648;

    // 逐行輸入並計算 DP
    for (int i = 1; i <= M; i++) {
        // 輸入資料
        for (int j = 1; j <= N; j++)
            cin >> E[j];

        // 從左到右計算
        for (int j = 1; j <= N; j++)
            L[j] = max(L[j - 1], DP[i - 1][j]) + E[j];

        // 從右到左計算
        for (int j = N; j > 0; j--)
            R[j] = max(R[j + 1], DP[i - 1][j]) + E [j];

        // 計算 DP[i][j]
        for (int j = 1; j <= N; j++)
            DP[i][j] = max(L[j], R[j]);
    }

    // 找出最大值
    long long int ans = 0;
    for (int j = 1; j <= N; j++)
        if (DP[M][j] > ans)
            ans = DP[M][j];
    cout << ans << endl;
    return 0;
}
