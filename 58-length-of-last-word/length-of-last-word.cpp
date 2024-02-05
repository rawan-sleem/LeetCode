// Time O(n)
// Space  O(1)
// Solution loop 
/* input = "Hello World
Iteration 1: i = 10, character 'd' (last character, not a space), flag = 1, count = 1.
Iteration 2: i = 9, character 'l', flag = 1, count = 2.
Iteration 3: i = 8, character 'r', flag = 1, count = 3.
Iteration 4: i = 7, character 'o', flag = 1, count = 4.
Iteration 5: i = 6, character 'W', flag = 1, count = 5
loop break that it found empty string and flag=1 so  the result =5 now
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size= s.size();
        // count the length of the last word ,
        // flag to indicate if the characters are encountered after the last space
        int count=0,flag=0;
        for(int i=size-1 ; i>=0;i--){
            if(s[i] == ' ' && flag ==1){
                break;
            }
            if(s[i] != ' '){
                flag=1;
                count++;
            }
        }
        return count;


    }
};