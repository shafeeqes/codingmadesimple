class Solution {
public:
   
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int> &nums, int start, int end){
        if (start<end){
            int p = partition(nums,start,end);
            quickSort(nums,start,p-1);
            quickSort(nums,p,end);
        }
    }
    
    int partition(vector<int> &A, int start, int end){
        int pivot = A[end];
        //partition index
        int p = start;
        
        for(int i = start; i < end; i++){
            if(A[i] <= pivot){
                swap(A[p],A[i]);
                p++;
            }
        }
        swap(A[end],A[p]);
        return p;
    }
};
