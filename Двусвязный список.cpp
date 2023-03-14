#include <iostream>

struct Node 
{
	Node* next;
	Node* prev;
	int data;
};

Node* head = nullptr;
Node* tail = nullptr;
Node* stare = nullptr;
Node* temp = nullptr;
Node* tmp = nullptr;
Node* tmpend = nullptr;

void Kill(Node*& head, Node*& tail)
{
	if (head != nullptr)
	{
		Node* carrent;
		carrent = head;
		while (carrent->next != nullptr)
		{
			carrent = carrent->next;
			delete(head);
			head = carrent;
		}
		head = tail;
		delete(head);
		head = nullptr;
		tail = nullptr;
	}
}

void AddElem(Node*& head, Node*& tail, int n)
{
	Node* carrent;
	Node* TMP;
	TMP = new Node;
	TMP->data = n;
	TMP->next = nullptr;
	TMP->prev = nullptr;
	if (head == nullptr)
	{
		head = TMP;
		tail = TMP;
	}
	else
	{
		carrent = head;
			if ((head->data > n)&&(head->data!=n))
			{
				TMP->next = head;
				TMP->prev = nullptr;
				head->prev = TMP;
				head = TMP;
			}
			else
			{
				while ((carrent->next != nullptr) && (carrent->data < n))
				{
						carrent = carrent->next;
				}
				if ((carrent->data > n) && (carrent->data != n))
				{
					TMP->prev = carrent->prev;
					carrent->prev->next = TMP;
					TMP->next = carrent;
					carrent->prev = TMP;
				}
				else if ((carrent->data < n) && (carrent->data != n))
				{
					carrent->next = TMP;
					TMP->next = nullptr;
					TMP->prev = carrent;
					tail = TMP;
				}
			}
	}
}

void DelElem(Node*& head, Node*& tail, int dm)
{
	Node* elem;
	Node* carrent;
	carrent = head;
	if (head != nullptr)
	{
		if ((head->data == dm) && (carrent->next != nullptr))
		{
			elem = head;
			head->next->prev = nullptr;
			head = head->next;
			delete(elem);
		}
		else if (head->data != dm)
		{
			while ((carrent->data != dm) && (carrent->next != nullptr))
			{
				carrent = carrent->next;
			}
			if ((carrent->data == dm) && (carrent->next != nullptr))
			{
				carrent->next->prev = carrent->prev;
				carrent->prev->next = carrent->next;
				delete(carrent);
			}
			else if ((carrent->data == dm) && (carrent->next == nullptr))
			{
				tail = carrent->prev;
				carrent->prev->next = nullptr;
				delete(carrent);
			}
		}
		else if ((head->prev == nullptr) && (head->next == nullptr))
		{
			tail = head;
			delete(head);
			head = nullptr;
			tail = nullptr;
		}
	}
}

bool Serch(Node*& head, Node* tail, int dm)
{
	bool f = 0;
	Node* carrent;
	if (head != nullptr)
	{
		carrent = head;
		while (carrent != nullptr)
		{
			if (carrent->data == dm)
			{
				f = 1;
				return true;
			}
			carrent = carrent->next;
		}
		if (f == 0)
			return false;
	}
}

void PrintList(Node* head, Node* tail)
{
	Node* carrent;
	if (head != nullptr) 
	{
		carrent = head;
		while (carrent != nullptr)
		{
			std::cout << carrent->data << " ";
			carrent = carrent->next;
		}
		std::cout << std::endl;
	}
}

 void AddLists(Node*& stare, Node* temp, Node* head, Node*tail, Node* tmp, Node* tmpend)
{
	 while (head != nullptr)
	 {
		 AddElem(stare, temp, head->data);
		 head = head->next;
	 }
	 while (tmp != nullptr)
	 {
		 AddElem (stare, temp, tmp->data);
		 tmp = tmp->next;
	 }
}

int main()
{
	int dm;
	setlocale(LC_ALL, "Russian");
	Node* P_begin = nullptr;
	Node* P_end = nullptr;
	Node* P_result = nullptr;
	Node* P_begin1 = nullptr;
	Node* P_end1 = nullptr;
	Node* P_result1 = nullptr;
	Kill(P_begin, P_begin1);
	DelElem(P_begin, P_begin1, 1);
	PrintList(P_begin, P_begin1);
	AddElem(P_begin, P_begin1, 10);
	AddElem(P_begin, P_begin1, 5);
	AddElem(P_begin, P_begin1, 15);
	AddElem(P_begin, P_begin1, 7);
	AddElem(P_begin, P_begin1, 5);
	AddElem(P_begin, P_begin1, 15);
	PrintList(P_begin, P_begin1);
	DelElem(P_begin, P_begin1, 7);
	std::cout << Serch(P_begin, P_begin1, 20) << std::endl;
	PrintList(P_begin, P_begin1);
	AddElem(P_end, P_end1, 10);
	AddElem(P_end, P_end1, 5);
	AddElem(P_end, P_end1, 15);
	AddElem(P_end, P_end1, 7);
	AddElem(P_end, P_end1, 5);
	AddElem(P_end, P_end1, 15);
	AddLists(P_result, P_result1, P_begin, P_begin1, P_end, P_end1);
	PrintList(P_result, P_result1);
	Kill(P_result, P_result1);
	return 0;
}
