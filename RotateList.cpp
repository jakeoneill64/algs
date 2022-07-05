//
// Created by Jake M O'Neill on 03/07/2022.
//


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head) return head;
        ListNode* end{head};
        int size{1};
        while(end->next){
            size++;
            end = end->next;
        }
        end->next = head;
        int numberToTraverse = size - (k % size);
        for(int x = 0; x < numberToTraverse; x++){end=end->next;}
        head = end->next;
        end->next= nullptr;
        return head;
    }
};

int main(){
    ListNode third{2};
    ListNode second{1, &third};
    ListNode head{0, &second};
    Solution sol{};
    ListNode* result = sol.rotateRight(&head, 3);
    return 0;
}

