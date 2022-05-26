#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>

using namespace std;

int LCS(string& S1, string& S2){
    int n1 = S1.length();
    int n2 = S2.length();
    // 宣告一個大小為 (n1 + 1) x (n2 + 1) 的陣列
    // 並初始化為 0   
    vector<vector<int>> DP(
        n1 + 1,
        vector<int> (n2 + 1, 0)
    );
    // 記錄方向用
    vector<vector<int>> Direction(
        n1 + 1,
        vector<int> (n2 + 1, 0)
    );
    // 依序填表
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            // 最後一個字元相同
            if(S1[i - 1] == S2[j - 1]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
                // 從左上來的
                Direction[i][j] = 1;
            }
            // 最後一個字元不相同
            else{
                if(DP[i - 1][j] > DP[i][j - 1]){
                    // 從上方來
                    DP[i][j] = DP[i - 1][j];
                    Direction[i][j] = 2;
                }
                else{
                    // 從左方來
                    DP[i][j] = DP[i][j - 1];
                    Direction[i][j] = 3;
                }
            }
        }
    }
    // 印出表格
    cout << "DP Table:" << endl;
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            // 以寬度 3 輸出每一筆資料
            cout << setw(3) << DP[i][j] << " ";
            // 印出方向
            if(Direction[i][j] == 1)
                cout << "↖";
            else if(Direction[i][j] == 2)
                cout << "↑";
            else
                cout << "←";
        }
        cout << endl;
    }
    // 因為順序相反，最先新增的字元最後輸出
    // 故把路徑存在 stack 中便可以反向印出
    stack<char> LCS;
    int x = n1, y = n2;
    while(DP[x][y]){
        // 左上
        if(Direction[x][y] == 1){
            LCS.push(S1[x - 1]);
            x--;
            y--;
        }
        // 上
        else if(Direction[x][y] == 2)
            x--;
        // 左
        else
            y--;
    }
    cout << endl;
    // 印出 stack 的資料
    cout << "LCS: ";
    while(!LCS.empty()){
        cout << LCS.top();
        LCS.pop();
    }
    cout << endl;
    // 答案在 DP[n1][n2]
    return DP[n1][n2];
}
int main(){
    string s1 = "ACGACTGGT";
    string s2 = "CAGTCAACT";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout<<"Length of LCS: "<< LCS(s1, s2);
    return 0;
}
