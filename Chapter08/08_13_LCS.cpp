#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int LCS(string& S1, string& S2){
    int n1 = S1.length();
    int n2 = S2.length();
    // 宣告一個大小為 (n1 + 1) x (n2 + 1) 的陣列
    // 並初始化為 0
    vector<vector<int>> DP(n1 + 1, vector<int> (n2 + 1, 0));
    // 依序填表
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            // 最後一個字元相同
            if(S1[i - 1] == S2[j - 1]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            // 最後一個字元不相同
            else{
                DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
            }
        }
    }
    // 印出表格
    cout << "DP Table:" << endl;
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            // 以寬度 3 輸出每一筆資料
            cout << setw(3) << DP[i][j];
        }
        cout << endl;
    }
    // 答案在 DP[n1][n2]
    return DP[n1][n2];
}

int main()
{
    string s1 = "GRADUATE";
    string s2 = "GUAVA";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout<<"Length of LCS: "<< LCS(s1, s2);

    return 0;
}
