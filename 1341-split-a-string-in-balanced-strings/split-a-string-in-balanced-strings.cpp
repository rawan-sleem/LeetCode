// Time O(n)
// Space O(1)
// Idea count the number of balance string 

class Solution {
public:
    int balancedStringSplit(string s) {
      int r{}, l{}, result{};
      for(char i:s)  {
          r+=      i=='R'? 1 : 0 ;
          l+=      i=='L'? 1 : 0;
          result+= r==l ? 1 : 0; 
      }
      return result;
    }
};