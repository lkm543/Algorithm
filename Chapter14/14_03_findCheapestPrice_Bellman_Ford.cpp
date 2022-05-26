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
        // 起點至每個點的最短距離
        vector<int> distance(n, INT_MAX);
        // 把起點的最短距離設成 0
        distance[src] = 0;
        
        // 對所有邊進行 K+1 輪 relax
        for(int i = 0; i <= K; i++) 
        {
            // 用上一輪的 distance 進行 relax
            vector<int> current(distance);
            // 對所有邊進行 relax
            for(auto e : flights){
                int s = e[0];
                int f = e[1];
                int p = e[2];
                // 目前還沒有找到抵達 start 的方式
                if(distance[s] == INT_MAX)
                    continue;
                if(current[f] > distance[s] + p)
                    current[f] = distance[s] + p;
            }
            distance = current;
        }
        // 最後還是到不了 dst
        if (distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};
