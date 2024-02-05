// Time 
// Space
// Idea
/* trace => Input: nums = [1,1,1,2,2,3], k = 2
mp{1:3, 2:2, 3:1}
v{{3,1},{2,2},{1,3}}
ans{1,2} taking top 2 
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
// create map to store the frequency of each number 
   map<int ,int > mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        // create vector of pairs to store frequency and number 
        vector<pair<int,int>> v;
        for(auto i:mp){
     v.push_back({i.second,i.first});
        }
        // sorting the vector based on frequency in desc 
        sort(v.rbegin(),v.rend());
        // craete vector to store the top k frequency numbers 
        vector<int>ans;
        for(int i=0;i<k;i++){
        ans.push_back(v[i].second);
        }
        return ans;
    }
};