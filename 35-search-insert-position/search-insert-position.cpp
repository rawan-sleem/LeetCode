// Time O(log n)
// Space O(1)
// Solution: Idea is binary search 
  /* nums = [1, 3, 5, 6], target = 2 if not found lets trace this case 
Initial: l = 0, r = 3.
First iteration: mid = (0 + 3) / 2 = 1, nums[mid] = 3 (greater than 2), so update r = mid - 1 = 0.
Second iteration: mid = (0 + 0) / 2 = 0, nums[mid] = 1 (less than 2), so update l = mid + 1 = 1.
Third iteration: l > r, exit the loop.
Return r + 1 = 0 + 1 = 1.
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if (nums[mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        // If the target is not found during the binary search, 
       //   return the position where the target should be inserted.
        return r+1;
    }
};