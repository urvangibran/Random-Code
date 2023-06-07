#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int arr[], int num) {
  // to check sum of values against num
  int sum = 0;
  // to track window's leading edge
  int right = 0;
  // to track window's trailing edge
  int left = 0;
  // to track smallest subarray length
  int minLen = INT_MAX;
  int sizeArray = sizeof(arr) / sizeof(arr[0]);

  // while window's trailing edge has NOT reached the end of the array
  while (left < sizeArray) {
    // if window's leading edge has NOT reached the end of the array
    // AND window's values do NOT add up to num, grow window to right 
    if(right < sizeArray && sum < num) {
      // increase sum by the value at window's leading edge
      sum += arr[right];
      // increment window's leading edge to grow window
      right++;
    } else if(sum >= num){
      // if window's values DO add up to AT LEAST num, shrink window from left
      // update smallest subarray length to the lesser of current minLen or window's length
      minLen = min(minLen, right - left);
      // decrease sum by the value at window's trailing edge
      sum -= arr[left];
      // increment window's trailing edge to shrink window
      left++;
    } else {
      // current sum is less than num, BUT window's leading edge HAS reached end of array
      // needed to prevent an infinite loop 
      break;
    }
  }
  // return smallest subarray length found or 0
  // if minLen is never updated, then there is NOT a sum >= num, so return 0
  return (minLen == INT_MAX) ? 0 : minLen;
}

int main () {
    int n, num; cin >> n >> num;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = minSubArrayLen(arr, num);
    cout << ans << endl;
    return 0;
}