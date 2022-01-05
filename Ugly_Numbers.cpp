/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:
Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#
*/

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) 
	{
	    ull arr[n];
	    arr[0] = 1;
	    ull i2 = 0, i3 = 0, i5 = 0;
	    ull two = 2, three = 3, five = 5;
	    ull ans = 1;
	    
	    for (int i = 1; i < n; i++)
	    {
	        ans = min(two, min(three, five));
	        arr[i] = ans;
	        if (ans == two)
	        {
	            i2++;
	            two = arr[i2] * 2;
	        }
	        
	        if (ans == three)
	        {
	            i3++;
	            three = arr[i3] * 3;
	        }
	        
	        if (ans == five)
	        {
	            i5++;
	            five = arr[i5] * 5;
	        }
	    }
	    return ans;
	}
};