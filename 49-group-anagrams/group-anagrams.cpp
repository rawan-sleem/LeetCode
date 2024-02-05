// Time O(n*nlogn +m*n)
// Space  O(n*m) n number of string and m max group size 
// Idea of solution  : use unordered map to group anagrams by sort the characters of each string 
//    associating them with the same key , forming groups based on the sorted reperestations
/* trace =>  strs = {"eat", "tea", "tan", "ate", "nat", "bat"}
After sorted character aet  aet ant aet ant abt
ump key: aet Indices of it :[0,1,3] 
    key: ant Indices of it :[2,4]
    key: abt Indices of it :[5]
the result vector ans 
Group 1: ["eat", "tea", "ate"]
Group 2: ["tan", "nat"]
Group 3: ["bat"]

 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // result vector to store grouped anagrams
           vector<vector<string>> ans ;
        //    Hash map to store sorted strings and their indices 
        unordered_map<string,vector<int>> ump;
        // Iterate through the input strings 
        for(int i=0;i<strs.size();i++){// //O(n*nlog n)
            string s=strs[i];
            sort(s.begin(),s.end()); // sorted the characters of the strings // //O(nlog n)
            ump[s].push_back(i);//store the sorted string and its index in the hash map 
        }
        // Iterate through the hash map 
        for(auto it: ump){
            // to store the grouped anagrams 
            vector<string>v;
            // Iterate through the indices of the strings with the same sorted characters
            for(int i=0;i<it.second.size();i++){////O(n*m) => m max of strings 
                v.push_back(strs[it.second[i]]);//Add the original string to the result vector 
                 
            }ans.push_back(v);// add the vector of the anagrams to the result 
        }return ans;
        
    }
};