// Time O(n)
// Space O(m) m is the store frequency of the first string 
// Idea of solution frequency array 
/* trace => Input: s = "anagram", t = "nagaram"
the length are the same
 mp for s = "anagram" is {'a':3,'n':1, 'g':1, 'r':1 , 'm':1}
 iterates on the second string   t = "nagaram"
'n': Present in mp with frequency 1, so decrement the frequency (mp['n'] = 0).
'a': Present in mp with frequency 3, so decrement the frequency (mp['a'] = 2).
'g': Present in mp with frequency 1, so decrement the frequency (mp['g'] = 0).
'a': Present in mp with frequency 2, so decrement the frequency (mp['a'] = 1).
'r': Present in mp with frequency 1, so decrement the frequency (mp['r'] = 0)
'a': Present in mp with frequency 1, so decrement the frequency (mp['a'] = 0).
'm': Present in mp with frequency 1, so decrement the frequency (mp['m'] = 0)
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        // check if the lengths of the two string are different 
        if(s.size() !=t.size()){
            return false;
        }
        // create the map to store the frequency of characters in the first string
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        // Iterate the through the characters of the second string 
        for(int i=0;i<t.size();i++){
            // check if the characters is present in the map and its frequency is not zero
             if(mp.find(t[i]) != mp.end() && mp[t[i]] != 0){
                 mp[t[i]]--;//decrement the frequency 
             }
             else{
                 return false;// if the character is not found or its frequency is zero
             }

        }
        return true; // if reached here all strings are matched so it anagrams 
    }
};