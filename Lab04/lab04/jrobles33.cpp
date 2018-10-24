#include <limits.h> 
#include <iostream>

using namespace std;

int maxCrossingSubArray(int arr[], int low, int mid, int high) 
{ 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = mid; i >= low; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
  
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = mid+1; i <= high; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    return left_sum + right_sum; 
} 
  

int FindMaximumSubArray(int arr[], int low, int high) 
{ 

   if (low == high){
     return arr[low]; 
  }

   int mid = (low + high)/2; 
   if (FindMaximumSubArray(arr, low, mid) >= FindMaximumSubArray(arr, mid+1, high) && FindMaximumSubArray(arr, low, mid) >= maxCrossingSubArray(arr, low, mid, high)){
   return FindMaximumSubArray(arr, low, mid);
}
   if (FindMaximumSubArray(arr, low, mid) <= FindMaximumSubArray(arr, mid+1, high) && FindMaximumSubArray(arr, mid+1, high) >= maxCrossingSubArray(arr, low, mid, high)){
   return FindMaximumSubArray(arr, mid+1, high);
}
   if (maxCrossingSubArray(arr, low, mid, high) >= FindMaximumSubArray(arr, mid+1, high) && FindMaximumSubArray(arr, low, mid) <= maxCrossingSubArray(arr, low, mid, high)){
   return maxCrossingSubArray(arr, low, mid, high);
 }
return 0;
}


int main() { 
int size;
cin >> size;
    
int arr[size];
    
for (int i = 0; i < size; i++) {
	cin >> arr[i];
	}
   int max_sum = FindMaximumSubArray(arr, 0, size-1); 
   cout<< max_sum; 
   return max_sum; 

}
