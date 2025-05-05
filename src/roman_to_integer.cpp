#include <iostream>
#include <string>
#include <map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char, int>::iterator it;
        std::map<char, int>::iterator it2;
        std::map<char, int> map_check = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} 
        };
        int res{0};
        for(size_t i = 0; i < s.length(); ++i){
            char cur = s[i];
            char next = s[i+1];
            if(cur == 'I' && (next == 'V' || next == 'X')){
                it = map_check.find(cur);
                it2 = map_check.find(next);
                res += it2->second - it->second;
                ++i;
            } else if(cur == 'X' && (next == 'L' || next == 'C')){
                it = map_check.find(cur);
                it2 = map_check.find(next);
                res += it2->second - it->second;
                ++i;
            } else if(cur == 'C' && (next == 'D' || next == 'M')){
                it = map_check.find(cur);
                it2 = map_check.find(next);
                res += it2->second - it->second;
                ++i;
            }
            else {
                it = map_check.find(cur);
                res += it->second;
            }
        }

        return res;
    }
};

int main(){
    Solution obj;

    std::string str_1{"III"};
    std::cout << obj.romanToInt(str_1) << "\n";     //result: 3

    std::string str_2{"LVIII"};
    std::cout << obj.romanToInt(str_2) << "\n";     //result: 58

    std::string str_3{"MCMXCIV"};
    std::cout << obj.romanToInt(str_3) << "\n";     //result: 1994

    return 0;
}
