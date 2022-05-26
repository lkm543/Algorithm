#include <iostream>
#include <vector>

using namespace std;

void Matrix_Chain(vector<int> dimension) {
    int len = dimension.size();
    // 宣告 len * len 的二維陣列
    // DP[i][j] 代表 M(i,j)
    // M(i,j) = 從 i 到 j 運算最少的次數
    vector<vector<int>> DP(len, vector<int> (len, 0));

    // 第 k 輪
    for (int k = 1; k < len; k++){
        // 第 i, j 筆資料
        for (int i = 1; i < len - k; i++){
            int j = i + k;
            // 計算 DP[i][j]，因需取最小值
            // 故初始化成 INT_MAX，替代無限大
            DP[i][j] = 2147483647;
            // i ~ j - 1, 計算最小值
            for (int k = i; k <= j-1; k++)
            {
                int tmp_1 = dimension[i - 1] * dimension[k] * dimension[j];
                int tmp_2 = DP[i][k] + DP[k + 1][j] + tmp_1;
                if (tmp_2 < DP[i][j]){
                    DP[i][j] = tmp_2;
                }
            }
        }
    }
    // 印出動態規劃的二維陣列
    for(int i = 1; i < len; i++){
        for(int j = 1; j < len; j++){
            cout << DP[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Result: " << DP[1][len - 1];
}

int main()
{
    vector<int> dimension = {8, 3, 1, 9, 4, 3, 6, 10, 2};
    // 印出所有維度
    cout << "Dimensions: ";
    for(int data : dimension)
        cout << data << " ";
    cout << endl;
    cout << "DP Table:" << endl;
    Matrix_Chain(dimension);
    return 0;
}
