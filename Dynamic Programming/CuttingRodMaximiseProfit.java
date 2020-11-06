/*

iven a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod 
is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution. 
 
A naive solution for this problem is to generate all configurations of different pieces and find the highest priced 
configuration. This solution is exponential in term of time complexity. Let us see how this problem possesses both 
important properties of a Dynamic Programming (DP) Problem and can efficiently solved using Dynamic Programming.
1) Optimal Substructure: 
We can get the best price by making a cut at different positions and comparing the values obtained after a cut. We can r
ecursively call the same function for a piece obtained after a cut.
Let cutRod(n) be the required (best possible price) value for a rod of length n. cutRod(n) can be written as following.
cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}
2) Overlapping Subproblems 
Following is simple recursive implementation of the Rod Cutting problem. The implementation simply follows the recursive 
structure mentioned above

*/


package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
 */
public class CuttingRod {

    public int maxValue(int price[]){
        int max[] = new int[price.length+1];
        for(int i=1; i <= price.length; i++){
            for(int j=i; j <= price.length; j++){
                max[j] = Math.max(max[j], max[j-i] + price[i-1]);
            }
        }
        return max[price.length];
    }
    
    public int maxValue1(int price[]){
        int max[] = new int[price.length+1];
        for(int i=1; i <= price.length; i++){
            max[i] = price[i-1];
        }
        for(int i=1 ; i <= price.length; i++){
            for(int j=1; j < i ; j++){
                max[i] = Math.max(max[i], max[i-j] + max[j]);
            }
        }
        return max[price.length];
    }
    
    public int recursiveMaxValue(int price[],int len){
        if(len <= 0){
            return 0;
        }
        int maxValue = 0;
        for(int i=0; i < len;i++){
            int val = price[i] + recursiveMaxValue(price, len-i-1);
            if(maxValue < val){
                maxValue = val;
            }
        }
        return maxValue;
    }
    public static void main(String args[]){
        CuttingRod cr =new CuttingRod();
        int[] price = {3,5,8,9,10,20,22,25};
        long t1 = System.currentTimeMillis();
        int r = cr.recursiveMaxValue(price,8);
        long t2 = System.currentTimeMillis();
        System.out.println(r);
        System.out.println(t2 - t1);
    }
}
