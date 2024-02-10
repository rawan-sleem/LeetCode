// Time O(n log n )
// Space O(1)
/*  trace [[5,8],[3,9],[5,12],[16,5]]
 mp={5:1}
 mp={3:2, 5:1}
 mp={3:1, 5:2}
 mp={3:1, 5:3}
 return largest key in the map 

 */
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        // To store in it key the min  value repeation 
      map<int, int> mp;
    //   loop the input 
      for(auto i: rectangles){//O(n)
        mp[min(i[0],i[1])]++;//O(log n )
      }
    //   return the value of the largest key 
      return mp.rbegin()->second;
    }
};