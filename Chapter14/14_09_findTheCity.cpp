/*

LeetCode #1334. 閾值距離內鄰居最少的城市 Find the City With the Smallest Number of Neighbors at a Threshold Distance

A. 題目
圖上有有 n 個城市，城市的編號從0到n - 1，另外給一個edges陣列，其中 edges[i] = [from_i,to_i,weight_i]，分別代表 from_i 城市與 to_i 城市間的最短
距離 weight_i。

若給定另外一整數distanceThreshold，定義若兩城市間的最短距離落在distanceThreshold內（包含distanceThreshold），則代表這兩個城市互為「鄰居」，現在請試著找出有最少的「鄰居」的城市，如果有超過一個城市符合，則回傳其中編號最大者。

B. 出處
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        // n x n 的最短距離陣列
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto e: edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        // 自身到自身的距離為 0
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        // Floyd Warshall
        // 採納第 k 個頂點為中繼頂點
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j)
                        continue;
                    if(dist[i][k] == INT_MAX)
                        continue;
                    if(dist[k][j] == INT_MAX)
                        continue;
                    int new_dist = dist[i][k] + dist[k][j];
                    if(dist[i][j] > new_dist) 
                        dist[i][j] = new_dist;
                }
            }
        }
        
        int min_neighbor = INT_MAX;
        int min_city = -1;
        // 計算每個城市的鄰居個數
        for(int i = 0; i < n; i++){
            int neighbors = 0;
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                 if(dist[i][j] <= distanceThreshold)
                     neighbors++;
            }
            // 記錄下最少的鄰居
            if(min_neighbor >= neighbors){
                min_neighbor = neighbors;
                min_city = i;
            }
        }
        
        return min_city; 
    }
};
