//GCD, HCF


//O(log(min(a,b)))

// C++ program to find GCD of two numbers
#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}
  
// Driver program to test above function
int main()
{
    int a = 98, b = 56;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
    return 0;
}


/*
The GCD of three or more numbers equals the product of the prime factors common to all the numbers, but it can also be calculated by repeatedly taking the GCDs of pairs of numbers.

gcd(a, b, c) = gcd(a, gcd(b, c)) 
             = gcd(gcd(a, b), c) 
             = gcd(gcd(a, c), b)
For an array of elements, we do the following. We will also check for the result if the result at any step becomes 1 we will just return the 1 as gcd(1,x)=1.
    
    
    */


// C++ program to find GCD of two or 
// more numbers 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

// Function to find gcd of array of 
// numbers 
int findGCD(int arr[], int n) 
{ 
	int result = arr[0]; 
	for (int i = 1; i < n; i++) 
	{ 
		result = gcd(arr[i], result); 

		if(result == 1) 
		{ 
		return 1; 
		} 
	} 
	return result; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 4, 6, 8, 16 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findGCD(arr, n) << endl; 
	return 0; 
} 

    
