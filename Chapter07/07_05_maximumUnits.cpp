/*

LeetCode #1710. 裝載最多單位 Maximum Units on a Truck

A. 題目
本題要把一些盒子放到卡車上，給定一個陣列 boxTypes，
boxTypes[i] = [numberOfBoxes_i,numberOfUnitsPerBox_i]，其中

a. numberOfBoxes_i 是這種盒子的總數
b. numberOfUnitsPerBox_i 是每個這種盒子中裝有的單位數

另外，有一個整數 truckSize 是卡車上最多可以放的盒子數，只要還沒超過這個上限值，可以繼續選擇任一種盒子放到卡車上。

回傳可以放到卡車上的最大「單位」數。

B. 出處
https://leetcode.com/problems/maximum-units-on-a-truck/

*/

// 依照 numberOfUnitsPerBox_i 從大到小排序
bool cmp(vector<int>& box_1, vector<int>& box_2){
	return box_1[1] > box_2[1];
}

class Solution{
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
		sort(boxTypes.begin(), boxTypes.end(), cmp);
		int total = 0;

		// 從內含單位數最多的箱子種類開始處理
		for (vector<int>& box : boxTypes){
			if (truckSize == 0){ break; }
			// 取出目前這種箱子的資料
			int number = box[0];
			int capacity = box[1];

			// 可以把目前這種盒子全拿的情形
			if (truckSize >= number){
				truckSize -= number;
				total += number * capacity;
			}
			// 剩餘空間不夠全拿的情形
			else {
				total += truckSize * capacity;
				truckSize = 0;
			}
		} // end of for
		return total;
	} // end of maximumUnits
}; // end of Solution
