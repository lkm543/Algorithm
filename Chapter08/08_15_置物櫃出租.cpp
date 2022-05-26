/*

APCS：置物櫃出租 (2018/10 P4)

A. 題目
李老闆有 M 個置物櫃，目前已經租給 N 個客戶，已知第 i 個客戶租了 C(i) 個櫃子，但現在李老闆自己需要使用 T 個櫃子，如果剩下的空櫃不夠，他需要把部分櫃子從客戶那清空，而且每個客戶只能選擇全退或全不退，已知第 i 個客戶的利潤與客戶所租的櫃數 C(i) 相同，請計算李老闆的最小損失。

B. 題目出處
2018/10 APCS實作題 #4
本題可於 一中電腦資訊研究社 Online Judge中測試，網址如下： 
https://judge.tcirc.tw/ShowProblem?problemid=d075

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N, T;
    cin >> N >> M >> T;
    vector<int> space(N);
    for(int i = 0; i < N; i++)
        cin >> space[i];

    // 宣告 (N + 1) * (M - T + 1) 的二維陣列
    vector<vector<int>> DP(N + 1, vector<int>(M - T + 1, 0));
    // 客戶的空間前插入 0
    space.insert(space.begin(), 0);

    for(int j = 1; j <= M - T; j++){
        for(int i = 1; i <= N; i++){
            if(j < space[i])
                // 櫃子不足，不挑第 i 個客戶
                DP[i][j] = DP[i - 1][j];
            else{
                // 不挑第 i 個客戶
                int not_take = DP[i - 1][j];
                // 挑第 i 項物品
                int take = DP[i - 1][j - space[i]] + space[i];
                // 從挑與不挑中選價值大的
                DP[i][j] = not_take > take ? not_take : take;
            }
        }
    }

    int sum = 0;
    // 所有客戶的利潤加總
    for(int value : space)
        sum += value;

    cout << sum - DP[N][M - T];

    return 0;
}
