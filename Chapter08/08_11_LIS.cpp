#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> L(len);
    for(int i = 0; i < len; i++){
        int max_L = 0;
        for(int j = 0; j < i; j++){
            // 找出所有滿足 nums[j] < nums[i] 的 j 中
            // L[j] 最大者
            if(nums[j] < nums[i]){
                if(L[j] > max_L){
                    max_L = L[j];
                }
            }
        }
        // nums[i] 可接在長度為 max_L 的最大子序列以後
        L[i] = max_L + 1;
    }
    // 找出 L 中的最大值
    int LIS = 0;
    for(int data : L){
        if(data > LIS) LIS = data;
    }
    return LIS;
}

int main()
{
    vector<int> nums = {2, 4, 7, 4, 5, 3, 8, 2, 9};

    cout << "LIS: " << LIS(nums);
    return 0;
}
