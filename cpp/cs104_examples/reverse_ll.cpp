#include<iostream>
struct Node {
  int val;
  Node* next;

  Node(int v) : val(v), next(nullptr) {}
  Node() : val(0), next(nullptr) {}
};

Node* reverse (Node* head) {
  	if (head == NULL || head->next == NULL)
		return head;

	/* reverse the rest of the list and put the first element at the end */
	Node* rest = reverse (head->next);
	head->next->next = head;

	head->next = NULL;

	return rest;
}

// Example usage
int main() {
  Node* head = new Node(1);
  head->next = new Node(3);
  head->next->next = new Node(5);

  Node* new_head = reverse(head); // should get 5->3->1
  Node* tmp = new_head;
  while(tmp){
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
}