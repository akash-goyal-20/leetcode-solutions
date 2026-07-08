class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;

        for(int i = 0; i < arr.size();i++){
            mp[arr[i]]++;
        }

        vector<pair<int,int>> v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),[](const pair<int,int> a,const pair<int,int> b){
            return a.second > b.second;
        });

        for(int i = 0; i < v.size()-1; i++){
            if(v[i].second == v[i+1].second){
                return false;
            }
        }

        return true;
    }
};