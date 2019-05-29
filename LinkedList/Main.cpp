#include <iostream>

struct Node {
	int value;
	Node* next;
};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:

	LinkedList()
		: head(NULL), tail(NULL)
	{}

	void AddBegin(int const);
	void AddEnd(int const);
	void AddBetween(int const);
	void PrintList();
	void DeleteFirst();
	void DeleteLast();
	void DeleteSpecific(int);
	void DeleteAll();

};
void LinkedList::AddBegin(int value) {
	Node* tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->next = head;
		head = tmp;
	}
}
void LinkedList::AddEnd(int value) {
	Node* tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
		tail->next = NULL;
	}

}
void LinkedList::AddBetween(int value) {
	Node* cur = head;
	Node* ahead = cur->next;
	Node* tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	
	while (cur) {
		if (ahead->value > tmp->value) {
			cur->next = tmp;
			tmp->next = ahead;
			return;
		}
		
		cur = cur->next;
		ahead = ahead->next;
	}

}
void LinkedList::PrintList() {
	Node* tmp = head;
	while (tmp) {
		std::cout << "[" << tmp->value << "] ->";
		tmp = tmp->next;
	}
	std::cout << "NULL" << std::endl;
}
void LinkedList::DeleteFirst() {
	Node* tmp = head;
	head = head->next;
	delete tmp;
}
void LinkedList::DeleteLast() {
	Node* tmp = tail;
	Node* curptr = head;
	Node* nextptr = curptr->next;
	while (nextptr) {
		if (nextptr->next == NULL) {
			
			curptr->next = nextptr->next;
			delete nextptr;
			return;
		}
		curptr = curptr->next;
		nextptr = nextptr->next;
	}
}
void LinkedList::DeleteSpecific(int value)
{
	//Node* tmp = head;
	Node* curptr = head;
	Node* nextptr = curptr->next;
	if (head->value == value) {
		DeleteFirst();
		return;
	}
	while (nextptr) {
		if (nextptr->value == value) {
			curptr->next = nextptr->next;
			delete nextptr;
			return;
		}
		curptr = curptr->next;
		nextptr = nextptr->next;
	}
	
}
void LinkedList::DeleteAll()
{
	Node* cur = head;
	Node* tmp;
	while (cur) {
		tmp = cur;
		cur = cur->next;
		head = head->next;
		delete tmp;
	}
}


int main() {

	LinkedList link;
	link.AddBegin(7);
	link.AddBegin(6);
	link.AddBegin(5);
	

	link.PrintList();
	
	link.AddEnd(10);
	link.AddEnd(13);

	link.PrintList();

	link.AddBegin(2);
	link.PrintList();

	link.AddBetween(3);
	link.PrintList();

	link.DeleteFirst();
	link.PrintList();
	link.DeleteFirst();
	link.PrintList();
	
	std::cout << "Deletion last" << std::endl;
	link.DeleteLast();
	link.PrintList();

	//std::cout << "Deletion all" << std::endl;
	//link.DeleteAll();
	//link.PrintList();
	std::cout << "Delete Specific" << std::endl;
	link.DeleteSpecific(11);
	link.PrintList();

	std::cin.get();
}