/*

LeetCode #1514. 機率最大的路徑 Path with Maximum Probability

A. 題目
給定一無向圖有n個節點，編號從0開始，另外給一陣列edges紀錄邊，其中 edges[i]=[a,b]，代表a、b之間的成功機率，且其成功機率為succProb[i]。

請計算出從start節點到end節點的最大成功機率，要是中間沒有任何路徑請回傳0。

B. 出處
https://leetcode.com/problems/path-with-maximum-probability/

*/

// 每個頂點 vertex 有編號、predecessor 和 prob
typedef struct{
	int index;
	double prob;
}vertex;

// 排序函式，供priority_queue 使用，注意不等號與先前反向
class compare{
    public:
        bool operator()(vertex* v1, vertex* v2){
            return v1->prob < v2->prob;
        }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end){
        priority_queue<vertex*, vector<vertex*>, compare> candidates;
        vector<bool> already_shortest(n, false);
        // 起點至每個點的最大機率
        vector<double> prob(n, 0);

        // 改用鄰接列表儲存資料
        vector<vector<pair<int, double>>> graph(n);
        // pair 中的 first 為邊的終點
        // pair 中的 second 為邊的成功機率
        for (int i = 0; i < edges.size(); i++) {
            auto e = edges[i];
            graph[e[0]].push_back(make_pair(e[1], succProb[i]));
            graph[e[1]].push_back(make_pair(e[0], succProb[i]));
        }

        // 從起點 start 開始
        candidates.push(new vertex{start, 1});
        prob[start] = 1;
        // 不斷取出機率最大的頂點
        while(!candidates.empty()){
            int index = candidates.top()->index;
            candidates.pop();
            // index 已經在最短路徑組中
            if(already_shortest[index]){
                continue;
            }
            // 把 index 加入最短路徑組
            already_shortest[index] = true;
            // 找到終點時的機率
            if(index == end)
                return prob[index];
            // Relax index 的所有出邊
            for(int i = 0; i < graph[index].size(); i++){
                int target = graph[index][i].first;
                double w = graph[index][i].second;
                // 保留機率最大者
                if(prob[target] < prob[index] * w){
                    prob[target] = prob[index] * w;
                    candidates.push(new vertex{target, prob[index] * w});
                }
            }
        }
        return 0;
    }
};
