class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
    {
        return "1";
    }
    else
    {
        string a = countAndSay(n - 1);
        string p = "";
        for(int i = 0; i<a.length(); )
        {
            int b = 1;
            char x = a[i];
            for(int j = i+1; j<a.length(); j++)
            {
                char y = a[j];
                if(x == y)
                {
                    b++;
                }
                else
                {
                    break;
                }
            }
            i+=b;
            p+=to_string(b);
            p+=x;

        }
        return p;
    }
        
    }
};