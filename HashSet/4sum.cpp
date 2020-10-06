/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []
*/


vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
     int N = A.size();
   //mapping sum value to a vector of pair indices
    unordered_map<int, vector<pair<int, int> > > Hash;
    vector<vector<int> >Ans;
 
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            //calculate sum with i and j indices
            int Sum = A[i] + A[j];
            
            //if B- sum is already present in Hash then check for valid indices
            if(Hash.find(B - Sum ) != Hash.end()) 
            {
                //get vector of pair of indices with Hash of B- Sum
                vector<pair<int, int> > vec = Hash[B - Sum];
                
                //check for all pairs with i anf j
                for(int k = 0 ; k < vec.size() ; k++)
                {
                    //we are checking that all the indices are different 
                    if(vec[k].first != i && vec[k].first != j && vec[k].second != i 
                    && vec[k].second != j) 
                    { 
                        //push to vector
                        vector<int> ans;
                        ans.push_back(A[vec[k].first]);
                        ans.push_back(A[vec[k].second]);
                        ans.push_back(A[i]);
                        ans.push_back(A[j]);
                        
                        //sort the vector ans to maintain the expected output
                        sort(ans.begin() , ans.end()) ;
                        //push to final result and avoids duplicates
                        if(find(Ans.begin() , Ans.end() , ans ) == Ans.end())
                        Ans.push_back(ans) ;
                        
                        /*
                        this will slightly improve time
                            sort(ans.begin() , ans.end()) ;
                            string s = to_string(ans[0])+ to_string(ans[1]) + to_string(ans[2]) + to_string(ans[3]);
                            //push to final result and avoids duplicates
                            if(present.find(s) == present.end()){
                                present.insert(s);
                                Ans.push_back(ans);
                        */
                    }
                    
                }    
            }
            Hash[Sum].push_back(make_pair(i,j)) ;
        }
    }
    
    sort(Ans.begin() , Ans.end()) ;
    return Ans;
}
