/*

LeetCode #621 工作排程 Task Scheduler

A. 題目
給定一個字元陣列 tasks 代表 CPU 需要完成的所有任務，不同的字元代表不同類型的任務，這些任務可以被以任意順序完成。
每個任務需要一個單位時間來完成，而在任一單位時間內，CPU 可以完成某一個工作，或者什麼也不做。
另外考慮一個非負整數 n，代表兩個相同種類（用同一個字元來表示）的任務間最少要間隔多久才能進行，也就是說，同樣的兩個任務間必須至少空出 n 單位的時間。
回傳 CPU 完成所有給定任務最少需要花費的總時間。

B. 出處
https://leetcode.com/problems/task-scheduler/

*/

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n){
        // 最多可能有 26 種字母
        int counts[26] = {0};
        // 記錄每個字母的出現次數
        for (char c:tasks){
            counts[c-'A']++;
        }

        // 找到出現次數最多的字母其出現次數
        int max_frequency = -1;
        for (int i = 0; i < 26; i++){
            if (counts[i] > max_frequency){
                max_frequency = counts[i];
            }
        }

        // 找到與該出現次數相同的字母總數
        // 比如解題邏輯中，A、B 都出現 5 次的情形
        int max_frequency_words = 0;
        for (int i = 0; i < 26; i++){
            if (counts[i]==max_frequency){
                max_frequency_words++;
            }
        }

        // 即解題邏輯中的 taskAmount
        int len = tasks.size();
        // 即 (n+1)(t-1)+counts
        int result = (n + 1) * (max_frequency-1) +
                    max_frequency_words;
        return len > result ? len : result;
    } // end of leastInverval
}; // end of Solution
