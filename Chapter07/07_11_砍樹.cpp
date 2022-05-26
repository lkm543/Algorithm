/*

APCS：砍樹 (2020/01 P3)

A.	題目
目前有 N 棵樹種在一排，砍樹可以選擇向左或向右倒下，但倒下皆不能超過林場的左右範圍，也不能壓到其它尚未砍除的樹木，若 p[i] 代表第 i 棵樹的位置，h[i] 代表數高，因此倒下的範圍是： p[i]±h[i]，若此範圍內有樹則不能砍，但若尚未砍除的樹木剛好在端點則不算壓到，請不斷找到能滿足砍除條件的樹木，直到沒有樹木可以砍為止。

B.	題目出處
2020/01 APCS 實作題 #3
本題可以到 zerojudge 上提交程式碼，網址為：
https://zerojudge.tw/ShowProblem?problemid=h028

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    // 為處理邊界條件
    // 在 0、L 各插入一棵無限高的樹
    vector<int> p(N + 2, 0);
    p[N + 1] = L;
    vector<int> h(N + 2, 2147483647);

    // 輸入資料
    for (int i = 1; i < N + 1; i++)
        cin >> p[i];
    for (int i = 1; i < N + 1; i++)
        cin >> h[i];

    int sum = 0, max = 0;
    // 前一棵樹的索引值
    stack<int> tree;
    tree.push(0);

    for(int i = 1; i < N + 1; i++){
        // 可以往右倒
        if(p[i] + h[i] <= p[i + 1] ||
            // 可以往左倒
           p[i] - h[i] >= p[tree.top()])
        {
            sum++;
            max = max > h[i] ? max : h[i];
            // 不斷往前檢查
            while(!tree.empty()){
                int last = tree.top();
                // 可以往右倒
                if(p[last] + h[last] <= p[i + 1]){
                    sum++;
                    max = max > h[last] ?
                            max : h[last];
                    tree.pop();
                }
                else
                    break;
            }
        }
        else
            tree.push(i);
    }
    cout << sum << endl;
    cout << max << endl;
    return 0;
}
