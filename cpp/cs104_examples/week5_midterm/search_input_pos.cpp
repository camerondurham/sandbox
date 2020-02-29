#include<string>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {}
};

/*
Ex : 1->3->4->7, target = 6
return 3

     1->3->4->6->7, target = 0
return 0

    null , target = 299
return 0

*/

int helper(ListNode* r, int val, int pos)
{
    if(r == nullptr) return 0;
    if(r->val >= val) return pos;
    return helper(r->next, val, pos + 1);
}
int position(ListNode* root, int val){

    return helper(root, val, 0);
}

void insert(ListNode*& root, int val){
    if(root == nullptr)
    {
        root = new ListNode(val);
        return;
    }

    if(root->next == nullptr)
    {
        root->next = new ListNode(val);
        return;
    }

    insert(root->next, val);
}

void printLL(ListNode* root)
{
    ListNode* tmp = root;

    while(tmp!= nullptr){
        printf(" %d ", tmp->val);
        tmp = tmp->next;
    }

    printf("\n");
}

int main() {
    /* ListNode n0(1); ListNode n1(3); ListNode n2(4); ListNode n3(7); */
    /* n0.next = &n1; n1.next = &n2; n2.next = &n3; */
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    /* printf("position(%d) = %d\n", 1, position(&n0, 2)); // 1 */
    /* printf("position(%d) = %d\n", 3, position(&n0, 6)); // 3 */
    /* printf("position(%d) = %d\n", 0, position(nullptr, 8)); // 0 */
    printLL(n0);
    insert(n0, 6);
    printLL(n0);

    ListNode* test = nullptr;
    insert(test, 5);
    printLL(test);

    return 0;
}
