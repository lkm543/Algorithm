#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> data = {8, 9, 6, 5, 3, 6, 7, 4, 2, 1};
    // 預設從小排到大
    sort(data.begin(), data.end());

    auto iter_upper = upper_bound(data.begin(), data.end(), 5);
    auto iter_lower = lower_bound(data.begin(), data.end(), 5);

    cout << "Data: ";
    for(int i : data){
        cout << i << " ";
    }

    cout << endl;
    cout << "Upper bound of 5:" << *iter_upper << endl;
    cout << "Lower bound of 5:" << *iter_lower << endl;

    cout << "Index of upper bound: "  << iter_upper - data.begin() << endl;
    cout << "Index of lower bound: " << iter_lower - data.begin() << endl;

    return 0;
}
