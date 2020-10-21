//Bridges in a graph

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    vector<int> x = A ,y = B;
    if(B.size()<A.size())
    {
        x = B;
        y = A;
    }
  
    int m = x.size(), n =y.size();
    int start = 0, end = m, partitionX, partitionY;
    int maxleftX, maxleftY, minrightX, minrightY;
    
    if(m==0)
        return 1&n ? y[(n-1)/2]: (double)(y[(n-1)/2]+y[n/2])/2;
    
    while(start<=end)
    {
        partitionX = (start+end)/2;
        partitionY = (m+n+1)/2- partitionX;
        
        maxleftX = (partitionX == 0) ? INT_MIN : x[partitionX - 1];
        maxleftY = (partitionY == 0) ? INT_MIN : y[partitionY - 1];
        minrightX = (partitionX == m) ? INT_MAX : x[partitionX];
        minrightY = (partitionY == n) ? INT_MAX : y[partitionY];
        
        if(maxleftX<=minrightY && maxleftY<=minrightX)
        {
            if(1&(m+n))
                return (double)max(maxleftX,maxleftY);
            else
                return (double)(max(maxleftX,maxleftY) + min(minrightX,minrightY))/2;
                
        }
        if(maxleftX>minrightY)
            end = partitionX-1;
        else
            start = partitionX+1;
    }
}


