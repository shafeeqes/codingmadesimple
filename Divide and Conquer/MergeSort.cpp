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
