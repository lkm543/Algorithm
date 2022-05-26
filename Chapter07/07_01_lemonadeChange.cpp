/*

LeetCode #860 檸檬水找零 Lemonade Change

A. 題目
有個賣檸檬水的攤位，每杯檸檬水賣 5 元。有一些顧客排隊來買，而他們一次都只會點「一杯」。每個顧客點了他們的一杯檸檬水後，會用一枚面額 5 元、10 元或 20 元的硬幣來結帳。你必須正確找零，使得找零後的結果是每個顧客總共只付給你 5 元（顧客付 10 元時找 5 元，付 20 元時找 15 元）。

注意一開始手上並沒有任何零錢，所以有時會遇到無法找零的情形。只有在從頭到尾都能正確找零給每個顧客時，回傳 true。

B. 出處
https://leetcode.com/problems/lemonade-change/

*/

class Solution{
public:
	bool lemonadeChange(vector<int>& bills){
	    // 紀錄手上的不同硬幣個數
	    // 開始時每種硬幣個數都是 0
	    int five = 0;
	    int ten = 0;
	    int twenty = 0;
	    int len = bills.size();
	
	    // 依序處理每位顧客的找錢流程
	    for (int i = 0; i < len; i++){
		    // 第 i 個顧客使用的硬幣
		    int coin = bills[i];
		    // 顧客使用 5 元時，手上增加一枚 5 元
		    if (coin == 5){
			    five++;
            }
		    // 顧客使用 10 元時
		    else if (coin == 10){
			    // 手上有 5 元硬幣，能夠成功找錢
			    if (five){
				    five--;  // 找給顧客一枚 5 元
				    ten++;  // 手上增加一枚 10 元
                }
			    // 不能成功找錢
			    else {
				    return false;
			    }
            }
		    // 顧客使用 20 元時
		    else if (coin == 20){
			    // 5 元比較珍貴，優先把 10 元找掉
			    // 但也要同時至少有一枚 5 元才能找
			    if (ten && five){
				    ten--;
				    five--;
				    twenty++;
                }
			    // 沒有 10 元時，才試著用 3 枚 5 元找錢
			    else if (five >= 3){
				    five -= 3;
				    twenty++;
                }
			    // 不能成功找錢
			    else {
				    return false;
			    }
		    } // end of outer if
		} // end of for
        return true;
	} // end of lemonadeChange
}; // end of Solution
