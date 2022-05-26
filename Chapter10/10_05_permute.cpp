/*

LeetCode #46. 排列 Permutations

A. 題目
給定一個陣列 nums，當中有一些互不相同的整數。回傳這些整數所有可能的排列，回傳的順序不限。

B. 出處
https://leetcode.com/problems/permutations/

*/

class Solution{
public:
	vector<vector<int>> permute(vector<int>& nums){
		// 取得 nums 的長度
		int len = nums.size();
		// BFS 使用的 queue
		queue<vector<int>> permutation;
		// 要回傳的結果
		vector<vector<int>> final_result;

		// 第一個數字（第一層）可以是 nums 中的每個元素
		for (int i = 0; i < len; i++){
			int number = nums[i];
			// 建立一個長度為 1 的向量 [number]
			vector<int> tmp(1, number);
			// 放到 queue 中
			permutation.push(tmp);
		}
        // 開始 BFS
		while(!permutation.empty()){
			// 取出 Queue 中第一筆元素
			vector<int> current = permutation.front();
			permutation.pop();
			
			// current 長度跟 nums 元素數目相同時為其中一組排列
            // Queue 中已經處理到樹中最下面一層的元素 [1,2,3]
            if (current.size() == len){
				final_result.push_back(current);
			    continue;
			}
			// 要再加入其他數字時
			for (int i = 0; i < len; i++){
				// 繼續從 nums 中取出一個數字接在 current 後面
				int number = nums[i];
				// 檢查 current 裡面是否已經包含 number 了
				// 比如 [1,2] 不可以再接一個 1 在後面
				auto iter = find(current.begin(), current.end(), number);
                // 已經包含了，不能加進該排列裡
				if (iter != current.end()){
					continue;
				}
				else {
				    // 另一向量複製 current，後面再加上新的數字
	                vector<int> current_expand(
                        current.begin(),current.end()
                    );
				    current_expand.push_back(number);
					permutation.push(current_expand);
				}
			} // end of for
		} // end of while
		// 回傳得到的所有排列
		return final_result;
	} // end of permute
}; // end of Solution
