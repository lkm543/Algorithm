/*

APCS：線段覆蓋長度 (2016/03/05 P3)

A.	題目
給定一維座標上一些線段，求這些線段所覆蓋的長度，注意，重疊的部分只能算一次。例如給定四個線段，(5, 6)、(1, 2)、(4, 8)、和 (7, 9)。如下圖，線段覆蓋長度為6。
 
B.	題目出處
2016/03/05 APCS 實作題 #3
本題可以到 zerojudge 上提交程式碼，網址為：
https://zerojudge.tw/ShowProblem?problemid=b966

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int L, R;
};

// 依照線段的起始座標排序
bool cmp(Segment &a, Segment &b){
    return a.L < b.L;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    // 依序輸入資料
    vector<Segment> data(N);
    for (int i = 0; i < N; i++){
        int L, R;
        cin >> L >> R;
        data[i].L = L;
        data[i].R = R;
    }
    // 依照線段的起始座標排序
    sort(data.begin(), data.end(), cmp);
    // last_R: 上一個線段的結束座標
    int ans = 0, last_R = -1;
    for (int i = 0; i < N; i++) {
        // 如果現在的結束座標在上一個線段的結束座標前面
        // 則不需要處理目前的線段
        // L<-------------->R
        //     L<---->R
        if (data[i].R < last_R)
            continue;
        // 如果現在的結束座標在上一個線段的結束座標後面
        // 則需要加上：
        // 現在結束座標 - max(上一個結束座標, 現在開始座標)
        // L<-------------->R
        //          L<------->R
        // L<-------------->R
        //                    L<---->R
        ans += data[i].R -
            ((last_R > data[i].L) ? last_R : data[i].L);
        last_R = data[i].R;
    }
    cout << ans << endl;
    return 0;
}
