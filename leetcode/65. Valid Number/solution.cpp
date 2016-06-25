class Solution {
public:
    bool isNumber(string s) {
        s = strip(s); s = drops(s);
        if (isInteger(s)) return true;
        if (isFloat(s)) return true;
        if (isScience(s)) return true;
        return false;
    }
private:
    bool isInteger(string &s) {
        if ("" == s) return false;
        for (auto x : s) if (!isdigit(x)) {
            return false;
        }
        return true;
    }
    bool isFloat(string &s) {
        pair<string,string> r = split(s, '.');
        string first=r.first, second=r.second;
        if (""==first && ""==second) return false;
        if (""==first && isInteger(second)) return true;
        if (""==second && isInteger(first)) return true;
        if (isInteger(first) && isInteger(second)) return true;
        return false;
    }
    bool isScience(string &s) {
        pair<string,string> r = split(s, 'e');
        string first=r.first, second=r.second;
        second = drops(second);
        if (""==first && ""==second) return false;
        if (isInteger(first) && isInteger(second)) return true;
        if (isFloat(first) && isInteger(second)) return true;
        return false;
    }
    
    pair<string,string> split(string &s, char p) {
        string a = "", b = "";
        int i = 0, n = s.length();
        while (i < n && s[i] != p) {
            a.push_back(s[i]); ++i;
        }
        ++i;
        while (i < n) {
            b.push_back(s[i]); ++i;
        }
        return make_pair(a, b);
    }
    string strip(const string &s) {
        string ret = "";
        int i = 0, j = s.length() - 1;
        while (i <= j && s[i]==' ') ++i;
        while (i <= j && s[j]==' ') --j;
        for (; i <= j; ++i) ret += s[i];
        return ret;
    }
    string drops(string s) {
        int n = s.length();
        if (!n || (s[0]!='+'
            && s[0]!='-')) return s;
        return s.substr(1);
    }
};
