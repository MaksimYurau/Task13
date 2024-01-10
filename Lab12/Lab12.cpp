#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class ListNode {
public:
	int value;
	ListNode* next;

	ListNode(int val) : value(val), next(nullptr) {}
};

class List {
private:
	ListNode* head;
	ListNode* tail;

public:
	List() : head(nullptr), tail(nullptr) {}

	void Add(int val) {
		ListNode* newNode = new ListNode(val);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void Display() {
		ListNode* current = head;
		while (current != nullptr) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	void Reverse() {
		ListNode* prev = nullptr;
		ListNode* current = head;
		ListNode* next = nullptr;

		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		tail = head;
		head = prev;
	}

	List operator+(const List& other) {
		List newList;

		ListNode* current = head;
		while (current != nullptr) {
			newList.Add(current->value);
			current = current->next;
		}

		current = other.head;
		while (current != nullptr) {
			newList.Add(current->value);
			current = current->next;
		}

		return newList;
	}

	bool operator==(const List& other) {
		ListNode* current1 = head;
		ListNode* current2 = other.head;

		while (current1 != nullptr && current2 != nullptr) {
			if (current1->value != current2->value) {
				return false;
			}

			current1 = current1->next;
			current2 = current2->next;
		}

		return current1 == nullptr && current2 == nullptr;
	}

	void operator<<(const List& other) {
		ListNode* current = other.head;
		while (current != nullptr) {
			Add(current->value);
			current = current->next;
		}
	}

	ListNode* GetHead() const {
		return head;
	}

	ListNode* GetTail() const {
		return tail;
	}
};

// Метод расширения: Усечение строки до заданной длины
string TruncateString(const string& str, int length) {
	if (str.length() <= length) {
		return str;
	}
	else {
		return str.substr(0, length);
	}
}

// Метод расширения: Сумма элементов списка
int SumList(const List& list) {
	int sum = 0;
	ListNode* current = list.GetHead();
	while (current != nullptr) {
		sum += current->value;
		current = current->next;
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "Ru");
	List list1;
	list1.Add(1);
	list1.Add(2);
	list1.Add(3);

	List list2;
	list2.Add(4);
	list2.Add(5);
	list2.Add(6);

	List list3 = list1 + list2;


	cout << "List1: ";
	list1.Display();
	cout << "List2: ";
	list2.Display();
	cout << "List3: ";
	list3.Display();


	if (list1 == list2) {
		cout << "list1 равен list2" << endl;
	}
	else {
		cout << "list1 не равен list2" << endl;
	}


	string str = "Тестирование приложение по сокращению";
	cout << "Строка, которую будем сокращать: " << str;
	string truncated = TruncateString(str, 5);
	cout << "\nСокращаем до 5 символов\t" << truncated << endl;

	List list4;
	list4.Add(10);
	list4.Add(20);
	list4.Add(30);
	cout << "\nList4: ";
	list4.Display();

	int sum = SumList(list4);
	cout << "Сумма всех в list4: " << sum << endl;

	return 0;
}