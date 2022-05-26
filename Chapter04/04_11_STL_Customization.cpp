#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// 自訂的排序規則的函式
bool compare(int a, int b){
	return a > b;
}

int main()
{
	vector<int> data = {8,-5,-1,4,-3,6,2,-2,3,4};
	
	// 傳入自訂的排序規則
    sort (data.begin(), data.end(), compare);

	// 印出排序後的資料
	for (int i = 0; i < data.size(); i++){
		cout << data[i] << " ";
	}
	return 0;
}
