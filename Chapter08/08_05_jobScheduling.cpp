/*

LeetCode #1235. 最大收益的工作排程 Maximum Profit in Job Scheduling

A. 題目
給定 n 項工作，每個工作開始時間與結束時間分別為 startTime[i] 到 endTime[i]，收益為 profit[i]。
給定三個陣列 startTime、endTime 與 profit，回傳工作間佔用時間不重疊的前提下，能夠達到的最大收益。
如果一個工作結束時間是 X，允許同時選擇一個開始時間是 X 的工作。

B. 出處
https://leetcode.com/problems/maximum-profit-in-job-scheduling/

*/

// 存放工作資訊的結構
typedef struct{
	int start;
	int finish;
	int profit;
} job;

// 根據工作的結束時間排序，早結束的在前面
bool cmp(job* a, job* b){
	return a->finish < b->finish;
}

class Solution{
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime,  vector<int>& profit){
		int len = startTime.size();
		// 存放工作資訊的向量，使用指標，排序時會較快
		vector<job*> jobs(len);

		// 把工作資訊存放入向量中
		for (int i = 0; i < len; i++){
			jobs[i] = new job{startTime[i], endTime[i], profit[i]};
		}

		// 把工作根據結束時間排序
		sort(jobs.begin(), jobs.end(), cmp);
		// 到每一次工作為止的最大利潤，有 len 個活動
		vector<int> max_profit(len + 1, 0);

		for (int i = 1; i <= len; i++){
			// 取出當前這筆工作的資料
			int start = jobs[i - 1]->start;
			int finish = jobs[i - 1]->finish;
			int profit = jobs[i - 1]->profit;
            
            // 第一個活動的特例
            if(i == 1){
                max_profit[i] = profit;
                continue;
            }
            
			// 若選擇當前這個工作可得的收益
            // 需往前找到上一個可行的工作
            int choose = profit;
            for(int j = i - 2; j >= 0; j--){
                if(jobs[j]->finish <= start){
                    choose += max_profit[j + 1];
                    break;
                }
            }
            
			// 若不選擇當前這個工作可得的為上一個的收益
			int not_choose = max_profit[i - 1];

			// 先比較選與不選兩個選項
			int max_choose = choose > not_choose ? choose : not_choose;
			
			// 再來要比較同一時間結束的不同工作中有較大收益者
            max_profit[i] = max_profit[i] > max_choose ? max_profit[i] : max_choose;
		}
		// 回傳最後一個工作結束時間的 max_profit
		return max_profit.back();
	}; // end of jobScheduling
}; // end of Solution
