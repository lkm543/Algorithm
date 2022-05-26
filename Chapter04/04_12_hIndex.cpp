/*

A. 題目

給定一個整數陣列 citations，其中 citations[i] 代表某個研究者的第 i 篇公開論文被引用的總次數，請回傳該研究者的 H 指數。

根據維基百科，H 指數的定義如下：如果有一個研究者，他的所有 n 篇公開論文中至少有 h 篇個別至少被引用 h 次，且另外 n-h 篇被引用次數都不達 h 次，那這個研究者的 H 指數就是 h。

如果有數個值符合 h 值的定義，H 指數是其中最大的值。

B. 出處
https://leetcode.com/problems/h-index/

*/

class Solution{
public:
	int hIndex(vector<int>& citations){
		// 把 citations 由大到小排
		sort (citations.begin(), citations.end(), greater<int>());

		// 從第一篇，最多 citation 的論文開始檢查
		for (int i = 0; i < citations.size(); i++){
			// i+1 => 高於目前引用數的論文數
			// citations[i] => 目前論文的引用數
			// 根據題述條件，citations[i]>i+1 才要繼續迴圈
			if (i+1 > citations[i]){
				return i;
			}
		}
		// 如果中間都沒有不符合條件而回傳，則回傳論文總篇數
		return citations.size();
	} 
}; 
