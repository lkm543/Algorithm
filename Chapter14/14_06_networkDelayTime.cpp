/*

LeetCode #743. 網路的延遲時間 Network Delay Time

A. 題目

網路中有 n 個節點，編號從 1 到 n，另外 times 代表網路中節點跟節點之間的訊號延遲時間，其中 times[i] = (u_i,v_i,w_i)，u_i 代表訊號起點、v_i 代表訊號終點、w_i 代表訊號的延遲時間，請問網路中所有節點收到訊號至少需要多少時間？如果無法讓全網路都收到訊號則回傳 -1。

B. 出處
https://leetcode.com/problems/network-delay-time/

*/

// 每個頂點 vertex 有編號、predecessor 和 distance
typedef struct{
	int index;
	int distance;
}vertex;

// 排序函式，供priority_queue 使用
class compare{
    public:
        bool operator()(vertex* v1, vertex* v2){
            return v1->distance > v2->distance;
        }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,  int n, int k){
        priority_queue<vertex*, vector<vertex*>, compare> candidates;
        vector<bool> already_shortest(n + 1, false);
        // 起點至每個點的最短距離
        vector<int> distance(n + 1, INT_MAX);
        int result = 0;

        // 改用鄰接列表儲存資料
        vector<vector<pair<int, int>>> edges(n + 1);
        // pair 中的 first 為連線的終點
        // pair 中的 second 為連線的費用
        for (auto e : times) 
            edges[e[0]].push_back(make_pair(e[1], e[2]));
        
        // 從起點 k 開始
        candidates.push(new vertex{k, 0});
        distance[k] = 0;
        // 不斷取出距離最近的頂點
        while(!candidates.empty()){
            int index = candidates.top()->index;
            candidates.pop();
            // index 已經在最短路徑組中
            if(already_shortest[index]){
                continue;
            }
            // 把 index 加入最短路徑組
            already_shortest[index] = true;
            // 記錄下最後找到最短路徑時的距離
            result = distance[index];
            // Relax index 的所有出邊
            for(int i = 0; i < edges[index].size(); i++){
                int target = edges[index][i].first;
                int w = edges[index][i].second;
                if(distance[target] > distance[index] + w){
                    distance[target] = distance[index] + w;
                    candidates.push(new vertex{target, distance[index] + w});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(!already_shortest[i]){
                return -1;
            }
        }
        // 全部的頂點都有找到最短路徑
        return result;
    }
};
