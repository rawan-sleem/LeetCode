// Time 
// Space
/* trace =>
set("foo", "bar", 1): This inserts the key-value pair ("foo", "bar") with timestamp 1 into the mp unordered map.
set("foo", "baz", 2): This inserts the key-value pair ("foo", "baz") with timestamp 2 into the vector associated with the key "foo".
set("foo", "qux", 4): This inserts the key-value pair ("foo", "qux") with timestamp 4 into the vector associated with the key "foo".
get("foo", 3): We want to retrieve the value associated with the key "foo" at timestamp 3.
get("foo", 5): We want to retrieve the value associated with the key "foo" at timestamp 5
set("foo", "bar", 1):

mp["foo"] initially is an empty vector.
After this operation, mp["foo"] becomes [{1, "bar"}].
set("foo", "baz", 2):

Since the key "foo" already exists in mp, we append the new pair to its vector.
After this operation, mp["foo"] becomes [{1, "bar"}, {2, "baz"}].
set("foo", "qux", 4):

Again, we append the new pair to the existing vector for the key "foo".
After this operation, mp["foo"] becomes [{1, "bar"}, {2, "baz"}, {4, "qux"}].
get("foo", 3):

We perform a binary search within the vector associated with the key "foo".
The search finds the greatest timestamp less than or equal to 3, which is 2.
So, the corresponding value returned is "baz".
get("foo", 5):

We perform a binary search again.
This time, the search finds the greatest timestamp less than or equal to 5, which is 4.
So, the corresponding value returned is "qux 
 
 */


class TimeMap {
public:
// key is string and the value is pair 
   unordered_map<string,vector<pair<int,string>>> mp;
    // insert 
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value });
    }
    // make binary search of the timesamp first of the pair 
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){// if the key doesn't exist 
           return "";
        }
        int l=0,r=mp[key].size()-1; // size of the vector of this key  

        while(l<=r){
          int mid=(l+r)/2;
          if(mp[key][mid].first == timestamp ){
              return mp[key][mid].second;
          }else if(mp[key][mid].first > timestamp){
              r=mid-1;
          }else{
              l=mid+1;
          }
        }

        if(r<0){ // if not has the time before it or == timestamp  
            return "";
        }
        // if not, it returns the value associated with the timestamp just before the given timestamp
        return mp[key][r].second;//  the right is the smallest one before it need because it sorted 



    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */