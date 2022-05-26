/*

LeetCode #841. 鑰匙與房間 Keys and Rooms

A.	題目
總共有 N 個上鎖的房間，而你從編號 0 的房間 room_0 內出發（只有編號 0 沒有上鎖）。房間被依序編號為 0,1,2,...,N-1，且每個房間中有若干把鑰匙可以用來進入其他房間。

每間房間 i 會有一個 rooms[i]，這是一個陣列，當中的每個元素 rooms[i][j] 值都是 [0,1,...,N-1] 中的某個整數，當 rooms[i][j] = v 時，代表該鑰匙可以把房間 v 打開。

打開其他房間並進入之後，隨時可以回到之前進入過的房間。只有在能夠進入全部 N 個房間時，回傳 true。

B. 出處
https://leetcode.com/problems/keys-and-rooms/

*/

class Solution{	
	void visit(
        vector<vector<int>>& rooms, //每間房間裡的鑰匙
        vector<bool>& visited, //房間是否走過
        int current //現在進入的房間
    ){
		// 進入 current 這間時把 visited 設為 true
		visited[current] = true;

		// 從這間房間進入其他房間後
		// 依序處理從這間房間可以進入的所有房間
		for (auto key : rooms[current]){
			// 已經進入過這把鑰匙可以進入的房間了
			if (visited[key]){
				continue;
			}
			// 進入這把鑰匙可以進入的房間
            else {
				visit(rooms, visited, key);
			}
		}
	}

public:
	bool canVisitAllRooms(vector<vector<int>>& rooms){
		int len = rooms.size();
		// 用布林陣列記錄每個房間是否進去過
		// 初始化為 false，代表還未進去過
		vector<bool> visited(len, false);
        // 從房間 0 出發
		visit(rooms, visited, 0);

		// 因為上面 visit 函式傳入的是參考
		// visited 已經在 visit 函式執行中被改寫
        // 記錄了幾間房間進入過
		int counts = 0;
		for (int i = 0; i < len; i++){
            // cout << visited[i] << endl;
			if (visited[i]){
				counts++;
			}
		}
        
		// 如果全部的房間都進去過回傳 true
        // 否則回傳 false
        return counts == len;
	} // end of canVisitAllRooms
}; //end of Solution
