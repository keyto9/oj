class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> hash; vector<int> ret(2);
        for (int i = 0; i < numbers.size(); ++i) {
            int x = numbers[i], y = target - x;
            if (hash.find(y) == hash.end()) {
                hash[x] = i; continue;
            }
            ret[0] = hash[y]; ret[1] = i; break;
        }
        return ret;
    }
};
