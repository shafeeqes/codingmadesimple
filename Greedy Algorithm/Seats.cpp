/*

There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement
    
    */
    
    
    
    

int Solution::seats(string s) {
    
    int count = 0;
    vector<int> positions;
    for(int i = 0; i< s.size(); i++){
        if(s[i] == 'x')
            positions.push_back(i);
    }
    int n = positions.size();
    if(n == 0)  
        return 0;
    int jumps = 0;
    int midindex = positions[n/2];
    
    //first person will be seated n/2 seats before the middle person
    //and last person n/2 after the middle person
    int curr_position = midindex - n/2 ;
    for(int i = 0 ; i < n; i++){
        
        //when positions reaches midindex, skip
        if(positions[i]==midindex) 
            continue;
        jumps = (jumps + abs(positions[i] - curr_position) % 10000003) % 10000003;
        curr_position ++;
        // when curr position reaches mid element position, skip
        if(curr_position == midindex)
            curr_position ++;
    }
    return jumps;
}




//Alternate solution


int Solution::seats(string A) {
        vector<int> arr;
        for(int i = 0 ; i<A.length();i++){
            if(A[i]=='x'){
                arr.push_back(i);
            }
        }
        int ans = 0 ;
        int mid = arr.size()/2;
        int start = 0;
        int end = 0;
        for(int i = 0 ; i<arr.size();i++){
            start = arr[i];
            end =  arr[mid]-mid + i;
            ans= (ans+abs(end-start))%10000003;
        }
        return ans%10000003;
}
