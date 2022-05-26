#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 背包容量上限
    int weight_limit = 10;
    vector<int> weight{4, 5, 2, 6, 3, 7};
    vector<int> value{6, 7, 5, 12, 5, 18};
    // 物品數目
    int number = weight.size();
    // 宣告 (number + 1) * (weight_limit + 1) 的二維陣列
    vector<vector<int>> DP(
        number + 1,
        vector<int>(weight_limit + 1, 0)
    );
    // 物品重量與價值前插入 0
    weight.insert(weight.begin(), 0);
    value.insert(value.begin(), 0);

    for(int j = 1; j <= weight_limit; j++){
        for(int i = 1; i <= number; i++){
            if(j < weight[i])
                // 背包容量不足，不挑第 i 項物品
                DP[i][j] = DP[i - 1][j];
            else{
                // 不挑第 i 項物品
                int not_take = DP[i - 1][j];
                // 不挑第 i 項物品
                int take = DP[i - 1][j - weight[i]]
                            + value[i]; 
                // 從挑與不挑中選價值大的
                DP[i][j] = not_take > take ?
                            not_take : take;
            }
        }
    }

    for(int i = 0; i <= number; i++){
        for(int j = 0; j <= weight_limit; j++){
            cout << DP[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Maximal value = "
         << DP[number][weight_limit] << endl;
    return 0;
}
