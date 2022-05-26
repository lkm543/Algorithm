/*

LeetCode #1221. 分割出平衡字串 Split a String in Balanced Strings

A. 題目
平衡字串是指字串當中 'L' 和 'R' 出現次數相同者。給定一個平衡字串 s，把它切割為若干個平衡子字串，使得切割出的子字串個數最多。回傳該切割出的個數。

B. 出處
https://leetcode.com/problems/split-a-string-in-balanced-strings/

*/

class Solution{
public:
	int balancedStringSplit(string s){
		int L = 0;
		int R = 0;
		int counts = 0;  // 平衡字串的數目

		// 逐一檢查 s 中的字元
		for (char c : s){
			if (c == 'L'){
				L++;
			}
            else{
				R++;
            }
			// 目前 L 與 R 個數相同時，counts 加一
			if (L == R && L){
				L = R = 0;
				counts++;
			}
		}
		return counts;
	} // end of balancedStringSplit
}; // end of Solution
