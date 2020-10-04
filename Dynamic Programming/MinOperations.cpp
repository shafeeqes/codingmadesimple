/*
Input: 
N = 7
Output: 5
Explanation: 0 + 1 = 1, 1 + 1 = 2,
1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7

Your Task:
You don't need to read input or print anything. Your task is to complete the function minOperation() which accepts an integer N and return number of minimum operations required to reach N from 0.
*/

class Solution
{
  public:
    int minOperation(int n)
    {
        int count = 0;
        if(n <=2 ){
            return n;
        }
        while(n > 2){
            if(n&1){
                n = n -1;
            }
            else{
                n /= 2;
            }
            count ++;
        }
        return count + 2;
    }
};
