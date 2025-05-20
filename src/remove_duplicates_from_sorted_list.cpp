#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* nx = nullptr;
        while(cur != nullptr && cur->next != nullptr){
            nx = cur->next;
            if(cur->val == nx->val){
                cur->next = nx->next;
                nx->next = nullptr;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode obj1(1);
    ListNode obj2(5);
    obj1.next = &obj2;
    ListNode obj3(5);
    obj2.next = &obj3;
    ListNode obj4(77);
    obj3.next = &obj4;
    ListNode obj5(77);
    obj4.next = &obj5;
    ListNode obj6(77);
    obj5.next = &obj6;
    ListNode obj7(88);
    obj6.next = &obj7;
    
    ListNode* head = &obj1;
    Solution obj;
    ListNode* res = obj.deleteDuplicates(head);
    
    while(res != nullptr){
        std::cout << res->val << " ";   //1 5 77 88
        res = res->next;
    }
    std::cout << "\n";

    return 0;
}
