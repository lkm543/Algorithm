/*

APCS：血緣關係 (2016/03/05 P4)

A. 題目
小宇有一個大家族。有一天，他發現記錄整個家族成員和成員間血緣關係的家族族譜。小宇對於最遠的血緣關係 (我們稱之為"血緣距離") 有多遠感到很好奇。
 
上圖為家族的關係圖。0是7的孩子，1、2和3是0的孩子，4和5 是1的孩子，6是3的孩子。我們可以輕易的發現最遠的親戚關係為4(或 5)和6，他們的"血緣距離"是4 (4~1，1~0，0~3，3~6)。

給予任一家族的關係圖，請找出最遠的「血緣距離」。你可以假設只有一個人是整個家族成員的祖先，而且沒有兩個成員有同樣的小孩。

B. 出處
APCS 2016/03/05，實作題第4題
本題可以在 zerojudge 上繳交，注意需改成在同一程式內直接處理多筆測資。
https://zerojudge.tw/ShowProblem?problemid=b967

*/

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int>& distance, vector<vector<int>>& relationship, int current){
    // 跑遍 current 的所有相鄰頂點
    for(int neighbor : relationship[current]){
        // distance[neighbor] = -1 代表還沒走過
        if(distance[neighbor] != -1)
            continue;
        distance[neighbor] = distance[current] + 1;
        DFS(distance, relationship, neighbor);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    while(cin >> N){
        vector<vector<int>> relationship(N);
        vector<int> distance(N, -1);
        // 輸入每個人的孩子編號
        for(int i = 0; i < N - 1; i++){
            int parent, child;
            cin >> parent >> child;
            // 無向圖，A->B = B->A
            relationship[parent].push_back(child);
            relationship[child].push_back(parent);
        }

        // 從節點 0 出發作深度優先搜尋
        distance[0] = 0;
        DFS(distance, relationship, 0);
        int index_max = 0, max_distance = 0;
        // 找出最遠距離的頂點
        for(int i = 0; i < N; i++){
            if(distance[i] > max_distance){
                index_max = i;
                max_distance = distance[i];
            }
        }
        // 重設距離
        fill(distance.begin(), distance.end(), -1);
        distance[index_max] = 0;
        // 從 index_max 出發作深度優先搜尋
        DFS(distance, relationship, index_max);
        max_distance = 0;
        // 找出最遠距離的頂點
        for(int i = 0; i < N; i++){
            if(distance[i] > max_distance){
                max_distance = distance[i];
            }
        }
        cout << max_distance << endl;
    }
    return 0;
}
