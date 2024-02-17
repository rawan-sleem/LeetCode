/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int first =0, last=n;
        while(first<=last){
            int mid=first + (last - first)/2;
            if(guess(mid) == -1){
                last =mid -1;
            }
            else if(guess(mid) == 1){
                first=mid+1;
            }
            else if(guess(mid) == 0){
                return mid;
            }
        }
        // the number is not found in the range 
        return -1;
    }
};