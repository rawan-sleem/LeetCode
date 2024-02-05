// Time O(n)
// Space O(n) if store all element in the hash table 
// Idea  hash table to store the element and index of it and make compare 
/* Trace => Input = {2, 7, 11, 15}    int target = 9
loop on nums 
nums[0]=2  check if target -nums[i]=7 in exists in the hash table (not found ) store the element and the index of it  hash[2]=0
nums[1]=7  check if target - nums[i]=2 in exist in the hash table (found) return the indices {hash[2],1} ={0,1}

 */
class Solution {
public:
vector <int> twoSum(vector <int>&nums , int target){
// hash table to store in it the key is element and the value is index 
    map<int,int > hash;
    for(int i=0;i<nums.size();i++){
        // check if there exist the comlement in hte hash table if found
        if(hash.find(target-nums[i]) !=hash.end()){
// solution is found 
            return {hash[target-nums[i]],i};//return index that is in hash , i the current index 
        }
        // store the current number and its index in the hash table if not found 
        hash[nums[i]]=i;     
    }
    // if no solutio if found 
    return {-1,-1};
}

};