#include<iostream>
#include<vector>


//Problem: Given two non-empty linked lists, created a third linked list representing the sum of each node. 
//The data of the linked list will be stored in reverse order. 

//For this problem, I have not considered using a brute force approach. So far, the solution I have seems to be the best iteration.
//This will need to be tested and confirmed with said future tests.
//But as for the solution, I created a third linked list and store the data as I add, this allows for a single swoop of performance.
//I would say that the time complexity of my solution is O((m or n), depending on which linked list the most nodes. 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode* dummy = new ListNode();
            int carry = 0;
            ListNode* cur = dummy;
            while(l1 || l2 || carry){
                int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                carry = s / 10;
                cur->next = new ListNode(s % 10);
                cur = cur->next;
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }
            return dummy->next;
        }
};

//Utility function to create a linked list from a vector
ListNode* createList(const std::vector<int>& vals){
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for(int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

//Utility function to print a linked list
void printList(ListNode* head) {
    while (head){
        std::cout << head->val;
        if(head->next) std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(){
    

    return 0;
}