/*

LeetCode #787. K次轉機內的最便宜航班 Cheapest Flights Within K Stops

A. 題目
有 n 個城市中間由航班連接，給定一組資料 flights，其中 flights[i]=[〖from〗_i,〖to〗_i,〖price〗_i]，分別代表該航班的起點、終點、價格。

今天另外給一個出發城市src與目的地城市dst，請找出一條航線最多經過 K 次轉機，且該條航線是所有可行航線中價格最便宜的，如果存在這麼一條航線就回傳該航線的價格，若否則回傳 -1。

B. 出處
https://leetcode.com/problems/cheapest-flights-within-k-stops/

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){
        // 用鄰接列表的方式儲存邊
        vector<vector<pair<int, int>>> edges(n);
        
        // pair 中的 first 為航線的終點
        // pair 中的 second 為航線的費用
        for(auto e : flights){
            edges[e[0]].push_back(make_pair(e[1], e[2]));
        }
        
        // 起點至每個點的最短距離
        vector<int> distance(n, INT_MAX);
        // 把起點的最短距離設成 0
        distance[src] = 0;
        queue<int> BFS;
        // 從起點開始
        BFS.push(src);
        
        // 往外 K + 1 輪
        for(int i = 0; i <= K; i++){
            // 此輪開始前，Queue 中有幾個點
            int v = BFS.size();
            // 上一輪的基礎
            vector<int> tmp(distance);
            // 處理該輪的所有頂點
            for(int j = 0; j < v; j++){
                int current = BFS.front();
                BFS.pop();
                for (auto e : edges[current]) {
                    int new_dist = 
                        distance[current] + e.second;
                    if (new_dist < distance[e.first] &&
                        new_dist < tmp[e.first])
                    {
                        // 只有更新的點需要進行下一輪 relax
                        tmp[e.first] = new_dist;
                        BFS.push(e.first);
                    }
                }
            }
            distance = tmp;
        }
        
        // 最後還是到不了 dst
        if (distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};
