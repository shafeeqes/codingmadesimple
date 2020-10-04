// O(nlogn)
// O(n) space

class Solution {
public:
    void merge(vector<int>& nums, int l,int mid, int r){
        int i=l, j=mid+1;
        vector<int> temp;
        while(i<=mid &&j<=r){
            if(nums[i]<=nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=r) temp.push_back(nums[j++]);
        for(int i=l;i<=r;i++) nums[i] = temp[i-l];
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums, l,mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};



class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
    
    vector<int> mergeSort(vector<int> &A){
        int n = A.size();
        if(n <= 1){
            return A;
        }
        int mid = (n + 1)/2;
        vector<int> left, right;
        
        for(int i = 0; i < mid; i++){
            left.push_back(A[i]);
        }
        
        for(int i = mid; i < n; i++){
            right.push_back(A[i]);
        }
        
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left,right);
        
    }
    
    vector<int> merge(vector<int> &A, vector<int> &B ){
        
        vector<int> C;
        int i = 0, j = 0;
        int n = A.size(), m = B.size();
    
        while(i < n and j < m){
            if(A[i] <= B[j]){
                C.push_back(A[i]);
                i++;
            }
            else{
                C.push_back(B[j]);
                j++;
            }
        }
        while(i < n){
            C.push_back(A[i]);
            i++;
        }
        while(j < m){
            C.push_back(B[j]);
            j++;
        }
        return C; 
    }
};
