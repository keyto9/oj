class Solution {
public:
    string intToRoman(int num) {
        string si[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string sx[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string sc[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string sd[4] = {"","M","MM","MMM"};
        int ni, nx, nc, nd; string ret;
        nd = num / 1000; num %= 1000; ret += sd[nd];
        nc = num / 100;  num %= 100;  ret += sc[nc];
        nx = num / 10;   num %= 10;   ret += sx[nx];
        ni = num / 1;    num %= 1;    ret += si[ni];
        return ret;
    }
};
