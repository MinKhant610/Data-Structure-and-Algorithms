#include <iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
};

void dt_print (Node* node) {
	while (node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
}

void push (Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void append (Node** head_ref, int new_data){
	Node* new_node = new Node();
	Node* last = (*head_ref);
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL){
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL){
		last = last->next;
	}

	last->next = new_node;
}

void insertAfter(Node* insert_data, int new_data){
	if (insert_data == NULL){
		cout << "nedd insetr_data " << endl;
	}

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = insert_data->next;
	insert_data->next = new_node;

}

bool search(Node* head_ref, int key){
	Node* current_node = head_ref ;
	while (current_node != NULL){
		if (current_node->data == key){
			return true;
		}
		current_node = current_node->next;
	}
	return false;
}

void deleteNode(Node** head_ref, int key){
	Node* prev = NULL;
	Node* temp = (*head_ref);

	if (temp != NULL && temp->data == key){
		*head_ref = temp->next;
		delete temp;
		return ;
	}else {
		while (temp != NULL && temp->data != key){
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			return;

		prev->next = temp->next;
		delete temp;
	}
}

int main (){
	Node* head   = NULL;
	Node* second = NULL;
	Node* third  = NULL;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	dt_print (head);

	push(&head, 11);
	cout << " " << endl;
	cout << "After push"<< endl;
	dt_print(head);

	append(&head, 22);
	cout << " " << endl;
	cout << "After append"<< endl;
	dt_print(head);

	insertAfter(second->next, 44);
	cout << " " << endl;
	cout << "After insert data "<< endl;
	dt_print(head);

	cout << " " << endl;
	bool check = search (head, 44);
	if (check == true ){
		cout << "We found data" <<endl;
	}else {
		cout << "data not found" << endl;
	}

	int delete_key = 3;
	deleteNode(&head, delete_key);

	cout << "After delete "<< endl;
	dt_print(head);

	return 0;
}
