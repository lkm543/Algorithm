/*

LeetCode #435. 不重疊的區間 Non-overlapping Intervals

A. 題目
給定一個含有多個區間的陣列 intervals，其中 intervals[i] = [start_i,end_i]，回傳至少需要移除多少個區間，才能使剩下的區間不互相重疊。

B. 出處
https://leetcode.com/problems/non-overlapping-intervals/

*/

/*
// 排序根據活動的「開始時間」
// 不過預設排序方式正好與此相同，因此可以不特別加上此函式
bool cmp(vector<int>& interval_1, vector<int>& interval_2){
	return interval_1[0] < interval_2[0];
}
*/

class Solution{
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals){
		// 依照活動的開始時間排序活動，可以用預設方式排序即可
        // sort(intervals.begin(), intervals.end(), cmp);
        sort(intervals.begin(), intervals.end());

		// 紀錄刪除了多少個區間
		int delete_number = 0;
		// 把結束時間 finish 初始化成第一個活動的結束時間
		int finish = intervals[0][1];

		for(vector<int>& interval:intervals){
			int next_start = interval[0];
			int next_finish = interval[1];
			// 兩相鄰活動沒有重疊，不需刪除活動
			if(next_start >= finish){
				// 更新 finish 為目前檢查活動的結束時間
				finish = next_finish;
			}
			// 兩相鄰活動有重疊
			else{
				// 一定需要刪除其中一個活動
				delete_number++;
                // 只保留兩者中「較早結束的活動」
				// 所以finish 更新為該活動的結束時間
				// 即 finish = min(finish, next_finish)
				finish = finish < next_finish ? finish : next_finish;
			}
		}
        // 迴圈第一次執行時，第一個活動會和自己比較到
        // 所以多計算了一次刪除，需要扣掉
        return --delete_number;
	} // end of eraseOverlapIntervals
}; // end of Solution
