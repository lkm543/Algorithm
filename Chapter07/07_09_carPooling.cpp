/*

LeetCode #1094. 共享乘車 Car Pooling

A. 題目
有一輛共可搭載 capacity 位乘客的車，這輛車只會往東邊開（不會轉彎，也不往西邊開）。
給定一個陣列 trips，其中 
	trips[i] = [num_passengers,start_location,end_location] 

代表第 i 個接駁處有幾位乘客搭車，以及這幾位乘客的上下車地點。地點是以距離出發地東邊的公里數表示。只有在可以成功搭載所有乘客並讓他們在目的地下車時，回傳 true。

B. 出處
https://leetcode.com/problems/car-pooling/

*/

class Solution{
public:
	bool carPooling(vector<vector<int>>& trips, int capacity){
		// 記錄每個座標位置的乘客「變動數」
		// 1001 是 LeetCode 給的測資限制
		vector<int> passenger_change(1001,0);

		// 從每筆 trip 資料中，找到乘客會變動的座標
		// 乘客上車時，用正數標記該點乘客會「增加」幾人
		// 乘客下車時，用負數標記
		for (vector<int>& trip : trips){
			int num_passengers = trip[0];
			int start_location = trip[1];
			int end_location = trip[2];
			passenger_change[start_location] +=
                num_passengers;
			passenger_change[end_location] -= 
                num_passengers;
		}

		// 透過 passenger_change 向量
        // 檢查過程中是否超過車的座位數 capacity
		for (int num : passenger_change){
			// num 為正數（乘客上車），capacity 減少
			// num為負數時（乘客下車），capacity 增加
			capacity -= num;
			// 座位不夠時，回傳 false
			if (capacity < 0){
				return false;
            }
		}
		return true;
	} // end of carPooling
}; // end of Solution
