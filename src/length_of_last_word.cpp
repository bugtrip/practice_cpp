#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int size = s.size()-1;
        int len{0};
        
        for(int i = size; i>=0; --i) {
            if(s[i] != ' ') {
                int j = i;
                while(s[j] != ' ' && j >= 0) {
                    len++;           
                    if(j == 0) {
                        return len;
                    }
                    j--;
                }
                return len;
            }
        }
        return len;
    }
};

int main(){
    Solution obj;
    std::string test1{"Hello World"};
    std::cout << obj.lengthOfLastWord(test1) << std::endl;      //5
    
    std::string test2{"   fly me   to   the moon  "};
    std::cout << obj.lengthOfLastWord(test2) << std::endl;      //4

    std::string test3{"luffy is still joyboy"};
    std::cout << obj.lengthOfLastWord(test3) << std::endl;      //6

    return 0;
}
