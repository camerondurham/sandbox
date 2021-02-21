#include<iostream>
struct Node {
  int val;
  Node* next;
  Node(int v) : val(v), next(NULL) {}
  Node() : val(0), next(NULL) {}
};

Node* reverse (Node* head) {
  	if (head == NULL || head->next == NULL)
		return head;

	/* reverse the rest of the list and put the first element at the end */
	Node* rest = reverse (head->next);
	head->next->next = head;
	head->next = NULL;
  /*
    Some notes:
    1 -> 3 -> 5
    rest = reverse(3->5)
                rest = reverse(5)
                5 -> 3 -> NULL

    5 -> 3 -> NULL

      1 -> 3 -> NULL
      1 -> 3 -> 1
      1 -> NULL

    5 -> 3 -> 1 -> NULL
  */
	return rest;
}

// Example usage
int main() {
  Node* head = new Node(1);
  head->next = new Node(3);
  head->next->next = new Node(5);
  Node* new_head = reverse(head); // should get 5->3->1
  while(new_head){
    std::cout << new_head->val << " "; new_head = new_head->next;
  }
}