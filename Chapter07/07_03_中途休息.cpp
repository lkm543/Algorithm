#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

int main(){

	int c, d, n;
	cout << "Please enter c,d,n:" << endl;
	cin >> c >> d >> n;
	vector<int> gas_station(n);
    // 獲取每個加油站的位置
	for (int i = 0; i < n; i++){
		cin >> gas_station[i];
    }
	// 將加油站依預設規則由小到大排序
    sort(gas_station.begin(), gas_station.end());
	// 記錄停靠的加油站數量
	int stops = 0;

	// 在終點（最後一格右邊）放一個加油站
	// 只要檢查是否有到這個加油站，就知道是否有走到終點
	gas_station.push_back(d);

	// 上一個有停靠的加油站是所有加油站中「第幾個」
	int last_stop_index = -1;
	// 上一個有停靠的加油站座標
	int last_stop_position = 0;

	// 尋找「可行範圍內最後面一個加油站」的邏輯是
	// 先找到「超過 c 距離外」，最近的一個加油站
	// 再往回退一個加油站（退回 c 的距離內）

	// 因為在終點處多加了一個加油站，總共要檢查 n+1 次
	for (int i = 0; i < n + 1; i++){
	// 檢查和上次停靠的距離超過 c 後，第一個遇到的加油站
		if (gas_station[i] - last_stop_position > c){
			// 上次停靠的加油站是第 i-1 個（i 的上一個）
			// 那麼 i-1 和 i 兩個相鄰的加油站間距離超過 c
			// 沒有可行解
			if (last_stop_index == i - 1){
				cout << "No solution!" << endl;
				stops = -1;
				break;
			}
			// 如果上次停的加油站和第 i 個加油站間有加油站
			// 就退回這個加油站（可行距離內的最後一個加油站）
			last_stop_index = i - 1;
			last_stop_position = gas_station[i - 1];

            // 停靠的加油站增加一個
			stops++;
			cout << "Stops @" <<
                     last_stop_position << endl;

			// 因為要停第 i - 1 個加油站
            // 停完後重新從第 i 個加油站檢查起
			i--;
		} // end of if
	} // end of for
	cout << "Stops = " << stops << endl;
	return 0;
}
