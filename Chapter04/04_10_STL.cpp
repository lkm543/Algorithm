#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

int main()
{
	vector<int> data = {8,-5,-1,4,-3,6,2,-2,3,4};
	
	// 預設由小到大排
    sort (data.begin(), data.end());

	// 印出排序後的資料
	for (int i=0 ; i < data.size(); i++){
		cout << data[i] << " ";
    }

	return 0;
}
