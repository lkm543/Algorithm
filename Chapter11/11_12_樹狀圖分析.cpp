/*
	APCS：樹狀圖分析 (2017/10 P3)
A. 題目

本題是關於有根樹(rooted tree)。在一棵 n 個節點的有根樹中，每個節點都是以 1~n 的不同數字來編號，描述一棵有根樹必須定義節點與節點之間的親子關係。一棵有根樹恰有一個節點沒有父節點(parent)，此節點被稱為根節點(root)，除了根節點以外的每一個節點都恰有一個父節點，而每個節點被稱為是它父節點的子節點(child)，有些節點沒有子節點，這些節點稱為葉節點(leaf)。在當有根樹只有一個節點時，這個節點既是根節點同時也是葉節點。
 
在圖形表示上，我們將父節點畫在子節點之上，中間畫一條邊(edge)連結。例如，上圖中表示的是一棵 9 個節點的有根樹，其中，節點 1 為節點 6 的父節點，而節點 6 為節點 1 的子節點；又 5、3 與 8 都是 2 的子節點。節點 4 沒有父節點，所以節點 4 是根節點；而 6、9、3 與 8 都是葉節點。 

樹狀圖中的兩個節點 u 和 v 之間的距離 d(u,v)定義為兩節點之間邊的數量。如上圖中，d(7, 5) = 2，而 d(1, 2) = 3。對於樹狀圖中的節點 v，我們以 h(v)代表節點 v 的高度，其定義是節點 v 和節點 v 下面最遠的葉節點之間的距離，而葉節點的高度定義為 0。例如節點 6 的高度為 0，節點 2 的高度為 2，而節點 4 的高度為 4。

此外，我們定義 H(T)為 T 中所有節點的高度總和，也就是說 H(T)=∑_(v∈T)▒〖h(v)〗。給定一個樹狀圖 T，請找出 T 的根節點以及高度總和 H(T)。

B. 題目出處

2017/10 APCS實作題 #3
本題可於 Zerojudge 中測試，網址如下：
https://zerojudge.tw/ShowProblem?problemid=c463

*/

#include <iostream>
#include <vector>

using namespace std;

long long int ans = 0;

// 深度優先搜尋
long long int DFS (
       vector<vector<int>>& adj_list,
       int idx)
{
    long long int h, max = 0;
    // 計算子樹們的高
    for (int node : adj_list[idx])
    {
        h = DFS(adj_list, node);
        if (h > max)
            max = h;
    }
    ans += max;
    max++;
    return max;
}

int main ( ) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, k, child, root;
    cin >> N;
    // 注意編號從 1 開始
    vector<bool> root_candidate(N + 1, true);
    vector<vector<int>> adj_list(N + 1);
    for(int i = 1; i < N + 1; i++){
        cin >> k;
        for(int j = 1; j < k + 1; j++){
            cin >> child;
            adj_list[i].push_back(child);
            // child 不可能為子節點
            root_candidate[child] = false;
        }
    }
    // 首先找出根節點
    for(int i = 1; i < N + 1; i++){
        if(root_candidate[i]){
            root = i;
            break;
        }
    }
    // 從根節點開始深度優先搜尋
    DFS(adj_list, root);
    cout << root << endl << ans;
    return 0;
}
