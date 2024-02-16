// Time O(nlogn)
// space O(1)
// Idea is two binary search 
/* trace =>Input: nums = [5,7,7,8,8,10], target = 8 Output: [3,4]
iteration one:: l=0 , r=5 , mid= 2 so nums[2] =7 7<8 update l=mid+1 l=3
iteration two:: l=3 , r=5 mid= 4 so nums[4]=8  8==8 so ans[0]=4 , r=3
iteration three:: l=3 , r=3 mid =3 so nums[3]=8 8==8 so ans[0]=mid=3 , r=2
iteration four:: l=3, r=2 break the loop 
RESET l=0, r=5 
second loop 
iteration one:: l=0 , r=5 , mid= 2 so nums[2] =7 7<8 update l=mid+1 l=3
iteration two:: l=3 , r=5 mid= 4 so nums[4]=8  8==8 so ans[1]=4 , l=5
iteration three:: l=5 , r=5 mid =5 so nums[3]=8 10>8 so ans[1]=mid=3 , r=4
iteration four:: l=5, r=4 break the loop


 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};  // Initialize the result vector with default values

        int l = 0, r = nums.size() - 1;  // Initialize left and right pointers for binary search

        // Binary search to find the leftmost index of target
        while (l <= r) {
            int mid = (l+r) / 2;  // Calculate the middle index

            if (nums[mid] == target) {  // If target found at mid
                ans[0] = mid;  // Update the leftmost index of target in result vector
                r = mid - 1;  // Continue searching towards left for more occurrences
            } else if (nums[mid] < target) {  // If target is greater than mid
                l = mid + 1;  // Adjust left pointer to search in the right half
            } else {  // If target is smaller than mid
                r = mid - 1;  // Adjust right pointer to search in the left half
            }
        }

        // Reset l and r for binary search towards right
        l = 0, r = nums.size() - 1;

        // Binary search to find the rightmost index of target
        while (l <= r) {
            int mid = l + (r - l) / 2;  // Calculate the middle index

            if (nums[mid] == target) {  // If target found at mid
                ans[1] = mid;  // Update the rightmost index of target in result vector
                l = mid + 1;  // Continue searching towards right for more occurrences
            } else if (nums[mid] < target) {  // If target is greater than mid
                l = mid + 1;  // Adjust left pointer to search in the right half
            } else {  // If target is smaller than mid
                r = mid - 1;  // Adjust right pointer to search in the left half
            }
        }

        return ans;  // Return the final result vector containing the range of target occurrences
    }
};