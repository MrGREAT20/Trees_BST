class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>s;
        string p = "abcdefghijklmnopqrstuvwxyz";
        for(char c : sentence){
            s.insert(c);
        }
        string a = "";
        for(char c : s){
            a += c;
        }
        if(a == p){
            return true;
        }
        return false;
    }
};