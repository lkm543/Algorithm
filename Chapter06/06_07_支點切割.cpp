#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, sum = 0;
vector<long long int> pre_torque, suf_torque;
vector<int> p;

int cut(int depth, int left, int right) {
    // 遞迴深度超過
    if(depth >= K)
        return 0;

    int len = right - left + 1;
    // 陣列長度不足 3
    if(len < 3)
        return 0;

    // 計算左力矩
    long long int prefix = 0;
    pre_torque[left] = 0;
    for (int i = left + 1; i <= right; i++){
        prefix += p[i - 1];
        pre_torque[i] = pre_torque[i - 1] + prefix;

    }
    // 計算右力矩
    long long int suffix = 0;
    suf_torque[right] = 0;
    for (int i = right - 1; i >= left; i--){
        suffix += p[i + 1];
        suf_torque[i] = suf_torque[i + 1] + suffix;
    }
    // 找到最小力矩的點
    long long int minimum = 2e18;
    int min_index = -1;
    for (int i = left + 1; i < right; i++){
        long long int total = 
            abs(pre_torque[i] - suf_torque[i]);
        if(total < minimum){
            min_index = i;
            minimum = total;
        }
    }
    return p[min_index] +
            // 左邊
            cut(depth + 1, left, min_index - 1) +
            // 右邊
            cut(depth + 1, min_index + 1, right);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    p.resize(N);

    // 輸入資料
    for (int i = 0; i < N; i++)
        cin >> p[i];

    pre_torque.resize(N);
    suf_torque.resize(N);

    cout << cut(0, 0, N - 1) << endl;
    return 0;
}
