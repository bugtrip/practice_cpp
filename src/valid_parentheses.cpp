#include <iostream>
#include <map>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::map<char, char> check_map = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        std::map<char, char>::iterator it1;
        std::stack<char> check_stack;
        int cnt{0};
        size_t size = s.length();
        if(size % 2 != 0){ return 0; }
        
        for(size_t i = 0; i < size; ++i){
            it1 = check_map.find(s[i]);
            cnt++;
            if(s[i] == it1->first){
                check_stack.push(it1->second);
            }

            if(!check_stack.empty()){
                if(s[i] == check_stack.top()){
                    check_stack.pop();
                    cnt-=2;
                }
            }      
        }
        return !cnt;
    }
};

int main(){
    Solution obj;

    std::string str_1{"()"};
    std::cout << obj.isValid(str_1) << "\n";    //result: true

    std::string str_2{"()[]{}"};
    std::cout << obj.isValid(str_2) << "\n";    //result: true
    
    std::string str_3{"(]"};
    std::cout << obj.isValid(str_3) << "\n";    //result: false
    
    std::string str_4{"(([{}(){}]))"};
    std::cout << obj.isValid(str_4) << "\n";    //result: true

    std::string str_5{"[{}}()]"};
    std::cout << obj.isValid(str_5) << "\n";    //result: false

    return 0;
}
