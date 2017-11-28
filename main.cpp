# forward_list-0.0.1

#include <iostream>
#include <sstream>

using namespace std;

struct node_t {
	int value;
	node_t * next;
};

node_t * lastlist(node_t * list) {
	node_t * list_tmp = list;
	for (; list_tmp->next != nullptr; ) {
		list_tmp = list_tmp->next;
	}
	return list_tmp;
}

void addelement(node_t *& list, int & size,int data) {
	if (size == 0) {
		list = new node_t;
		list->next = nullptr;
		list->value = data;
		size++;
	}
	else {
		node_t * first= list;
		list = lastlist(list);
		list->next = new node_t;
		list->next->next = nullptr;
		list->next->value = data;
		list = first;
		size++;
	}

}

void delelement(node_t *& list, int & size) {
	if (list == nullptr) {
		return;
	}
	list = list->next;
	size--;
}

void reverselist(node_t *& list, node_t *& last, int size) {
	if (list == nullptr) {
		return;
	}
	node_t * newlist = last;

	while (last != list) {
		last->next = list;
		node_t *tmp = last->next;

		for (; tmp != last;) {
			last->next = tmp;
			tmp = tmp->next;
		}

		last = last->next;
	}
	list = newlist;

	last->next = nullptr;
}

void output(node_t * list, int size) {
	node_t * list_tmp = list;
	for (int i = 0; i < size; i++) {
		cout << "+---+    ";
	}
	cout << endl;
	for (int i = 0; i < size, list_tmp != nullptr; i++) {
		cout << "| " << list_tmp->value << " |";
		if (list_tmp->next != nullptr) {
			cout << "--->";
		}
		list_tmp = list_tmp->next;
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "+---+    ";
	}
	cout << endl;
}

void clearlist(node_t *& list)
{
	if (list == nullptr) {
		return;
	}
	node_t * tmp = list;
	for (; tmp != nullptr;) {
		tmp = list->next;
		delete(list);
		list = tmp;
	}
}

int main()
{
	int data;
	char oper;
	node_t * list = nullptr;
	int size = 0;

	cin >> oper;
	
	while (oper != 'q') {

		switch (oper)
		{
		case '=':
			output(list, size);
			break;

		case '+':
			cin >> data;
			addelement(list, size, data);
			output(list, size);
			break;

		case '-':
			delelement(list, size);
			output(list, size);
			break;

		case '/':
			node_t * last = lastlist(list);
			reverselist(list,last ,size);
			output(list, size);
			break;
		}

		cin >> oper;
	}

	clearlist(list);

	cin.get();
	cin.get();
	return 0;
}

