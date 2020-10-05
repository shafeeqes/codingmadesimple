/*
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.
 

Note: 
Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.

 

Example 1:

Input:
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(12, 32, 10) (10, 12, 32) (6, 7, 4) (5, 6, 4)
(4, 5, 6) (2, 3, 1) (1, 2, 3)
Hence, the total height of this stack is
10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a height
greater than this.

â€‹Example 2:

Input:
n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
Output: 15
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxHeight()
which takes three arrays height[], width[], length[], and N as a number of boxes and returns the highest possible stack height which could be formed.


Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N)
*/


package com.interview.dynamic;

import java.util.Arrays;

/**
 * Date 05/09/2015
 * @author tusroy
 * 
 * Given different dimensions and unlimited supply of boxes for each dimension, stack boxes
 * on top of each other such that it has maximum height but with caveat that length and width
 * of box on top should be strictly less than length and width of box under it. You can
 * rotate boxes as you like.
 * 
 * 1) Create all rotations of boxes such that length is always greater or equal to width
 * 2) Sort boxes by base area in non increasing order (length * width). This is because box
 * with more area will never ever go on top of box with less area.
 * 3) Take T[] and result[] array of same size as total boxes after all rotations are done
 * 4) Apply longest increasing subsequence type of algorithm to get max height.
 * 
 * If n number of dimensions are given total boxes after rotation will be 3n.
 * So space complexity is O(n)
 * Time complexity - O(nlogn) to sort boxes. O(n^2) to apply DP on it So really O(n^2)
 *
 * References
 * http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem/
 * http://people.cs.clemson.edu/~bcdean/dp_practice/
 */
public class BoxStacking {

    public int maxHeight(Dimension[] input) {
        //get all rotations of box dimension.
        //e.g if dimension is 1,2,3 rotations will be 2,1,3  3,2,1  3,1,2  . Here length is always greater
        //or equal to width and we can do that without loss of generality.
        Dimension[] allRotationInput = new Dimension[input.length * 3];
        createAllRotation(input, allRotationInput);
        
        //sort these boxes in non increasing order by their base area.(length X width)
        Arrays.sort(allRotationInput);

        //apply longest increasing subsequence kind of algorithm on these sorted boxes.
        int T[] = new int[allRotationInput.length];
        int result[] = new int[allRotationInput.length];

        for (int i = 0; i < T.length; i++) {
            T[i] = allRotationInput[i].height;
            result[i] = i;
        }

        for (int i = 1; i < T.length; i++) {
            for (int j = 0; j < i; j++) {
                if (allRotationInput[i].length < allRotationInput[j].length
                        && allRotationInput[i].width < allRotationInput[j].width) {
                    if( T[j] + allRotationInput[i].height > T[i]){
                        T[i] = T[j] + allRotationInput[i].height;
                        result[i] = j;
                    }
                }
            }
        }
       
        //find max in T[] and that will be our max height.
        //Result can also be found using result[] array.
        int max = Integer.MIN_VALUE;
        for(int i=0; i < T.length; i++){
            if(T[i] > max){
                max = T[i];
            }
        }
        
        return max;
    }

    //create all rotations of boxes, always keeping length greater or equal to width
    private void createAllRotation(Dimension[] input,
            Dimension[] allRotationInput) {
        int index = 0;
        for (int i = 0; i < input.length; i++) {
            allRotationInput[index++] = Dimension.createDimension(
                    input[i].height, input[i].length, input[i].width);
            allRotationInput[index++] = Dimension.createDimension(
                    input[i].length, input[i].height, input[i].width);
            allRotationInput[index++] = Dimension.createDimension(
                    input[i].width, input[i].length, input[i].height);

        }
    }

    public static void main(String args[]) {
        BoxStacking bs = new BoxStacking();
        Dimension input[] = { new Dimension(3, 2, 5), new Dimension(1, 2, 4) };
        int maxHeight = bs.maxHeight(input);
        System.out.println("Max height is " + maxHeight);
        assert 11 == maxHeight;
    }
}

/**
 * Utility class to hold dimensions
 * @author tusroy
 *
 */
class Dimension implements Comparable<Dimension> {
    int height;
    int length;
    int width;

    Dimension(int height, int length, int width) {
        this.height = height;
        this.length = length;
        this.width = width;
    }

    Dimension() {
    }

    static Dimension createDimension(int height, int side1, int side2) {
        Dimension d = new Dimension();
        d.height = height;
        if (side1 >= side2) {
            d.length = side1;
            d.width = side2;
        } else {
            d.length = side2;
            d.width = side1;
        }
        return d;
    }

    /**
     * Sorts by base area(length X width)
     */
    @Override
    public int compareTo(Dimension d) {
        if (this.length * this.width >= d.length * d.width) {
            return -1;
        } else {
            return 1;
        }
    }

    @Override
    public String toString() {
        return "Dimension [height=" + height + ", length=" + length
                + ", width=" + width + "]";
    }
}
