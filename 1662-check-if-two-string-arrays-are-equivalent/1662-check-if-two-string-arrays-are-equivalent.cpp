class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for(auto s : word1){
            a += s;
        }
        for(auto s : word2){
            b += s;
        }
        if(a == b){
            return true;
        }
        return false;
    }
};