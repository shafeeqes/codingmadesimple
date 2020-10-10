/*

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> char_map (26,0);
        for( char a : tasks){
            char_map[a - 'A']++;
        }
        
        sort(char_map.begin(),char_map.end(), greater<int>());
        
        int max_value = char_map[0] - 1; //for the last task we dont need idle time
        int idle_time = max_value * n;   //we assume idle time in between all the iterations of the max frequent task, n is not task number it is idle time
        
        for(int i = 1; i < 26; i++){
            //if any other task have same max_value. and we subtracted one from the maximum value
            idle_time -= min(char_map[i] , max_value);
        }
        
        //if we still cant fill all the idle times in between the most frequent task with other tasks,
        // then we return total tasks + those idle times, otherwise there will be no idle time, all the gaps
        //are filled with other tasks so we just return n
        return idle_time > 0 ? idle_time + tasks.size() : tasks.size();
    }
};
