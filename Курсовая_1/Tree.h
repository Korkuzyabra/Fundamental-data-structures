#include <iostream>
#include <tuple>
#include <string>

int tabs = 0;
int kol_vo = 0;

struct node
{
	std::string data;
	int index;
	node* next;
	node* prev;
};

struct crown
{
	node* head;
	node* tail;
};

struct tree
{
	crown* crown;
	tree* left;
	tree* right;
};

std::string PrintList(crown* list)
{
	std::string result = "";
	node* carrent;
	if (list->head != nullptr)
	{
		carrent = list->head;
		while (carrent != nullptr)
		{
			result += carrent->data + " [" + std::to_string(carrent->index) + "] <-> ";
			carrent = carrent->next;
		}
		result += "\n";
	}
	return result;
}

void delTree(tree*& branch)
{
	if (!branch)
		return;
	delTree(branch->left);
	delTree(branch->right);
	delete branch;
	branch = nullptr;
	return;
}

void Add(std::string val, int num, crown*& list)
{
	node* temp;
	node* carrent = new node;
	carrent->data = val;
	carrent->index = num;
	carrent->next = nullptr;
	carrent->prev = nullptr;
	if (list == nullptr)
	{
		list = new crown;
		list->head = new node;
		list->tail = new node;
		list->head->next = nullptr;
		list->head->prev = nullptr;
		list->tail->next = nullptr;
		list->tail->prev = nullptr;
		list->head = carrent;
		list->tail = carrent;
	}
	else
	{
		temp = list->head;
		if ((list->head->index > num) && (list->head->index != num))
		{
			carrent->next = list->head;
			carrent->prev = nullptr;
			list->head->prev = carrent;
			list->head = carrent;
		}
		else
		{
			while ((temp->next != nullptr) && (temp->index < num))
			{
				temp = temp->next;
			}
			if ((temp->index > num) && (temp->index != num))
			{
				carrent->prev = temp->prev;
				temp->prev->next = carrent;
				carrent->next = temp;
				temp->prev = carrent;
			}
			else if ((temp->index < num) && (temp->index != num))
			{
				temp->next = carrent;
				carrent->next = nullptr;
				carrent->prev = temp;
				list->tail = carrent;
			}
		}
	}
}

void Add(std::string val, int num, tree*& branch)
{
	if (!branch)
	{
		branch = new tree;
		branch->crown = new crown;
		branch->crown = nullptr;
		Add(val, num, branch->crown);
		branch->left = 0;
		branch->right = 0;
	}
	else
		if (branch->crown->head->data != val)
		{
			if (branch->crown->head->data > val)
			{
				Add(val, num, branch->left);
			}
			else
			{
				Add(val, num, branch->right);
			}
		}
		else
			Add(val, num, branch->crown);
}

void Delcrown(int num, crown*& list)
{
	node* carrent;
	node* elem;
	carrent = list->head;
	if (list->head != list->tail)
	{
		if ((list->head->index == num) && (carrent->next != nullptr))
		{
			elem = carrent;
			list->head->next->prev = nullptr;
			list->head = list->head->next;
			delete(elem);
		}
		else if (list->head->index != num)
		{
			while ((carrent->index != num) && (carrent->next != nullptr))
			{
				carrent = carrent->next;
			}
			if ((carrent->index == num) && (carrent->next != nullptr))
			{
				carrent->next->prev = carrent->prev;
				carrent->prev->next = carrent->next;
				delete(carrent);
			}
			else if ((carrent->index == num) && (carrent->next == nullptr))
			{
				list->tail = carrent->prev;
				carrent->prev->next = nullptr;
				delete(carrent);
			}
		}
	}
	else
	{
		list->head = nullptr;
		list->tail = nullptr;
	}
}

tree* deleteNode(std::string val, int num, tree*& branch)
{
	if (branch == nullptr)
		return branch;
	if (branch->crown->head->data == val)
	{
		if (branch->crown->head->next == nullptr)
		{
			tree* tmp;
			if (branch->right == nullptr)
				tmp = branch->left;
			else
			{
				tree* ptr = branch->right;
				if (ptr->left == nullptr)
				{
					ptr->left = branch->left;
					tmp = ptr;
				}
				else
				{
					tree* pmin = ptr->left;
					while (pmin->left != nullptr)
					{
						ptr = pmin;
						pmin = ptr->left;
					}
					ptr->left = pmin->right;
					pmin->left = branch->left;
					pmin->right = branch->right;
					tmp = pmin;
				}
			}
			delete branch;
			return tmp;
		}
		else
			Delcrown(num, branch->crown);
	}
	else
		if (branch->crown->head->data > val)
			branch->left = deleteNode(val, num, branch->left);
		else
			branch->right = deleteNode(val, num, branch->right);
	return branch;
}

void searchList(std::string val, crown* list, std::vector<int>* result)
{
	node* carrent = list->head;
	while (carrent != nullptr)
	{
		if (carrent->data == val)
			result->push_back(carrent->index);
		carrent = carrent->next;
	}
}

 void search(std::string val, tree* branch, std::vector<int>* result)
{
	if (branch != nullptr)
	{
		if (branch->crown->head->data == val)
			return (searchList(val, branch->crown, result));
		else
		if (branch->crown->head->data > val)
				return search(val, branch->left, result);
			else
				return search(val, branch->right, result);
	}
}

 void changeIndexL(std::string val, crown* list, int from, int to)
 {
	 node* carrent = list->head;
	 while (carrent != nullptr)
	 {
		 if (carrent->index == from)
			 carrent->index = to;
		 carrent = carrent->next;
	 }
 }

 void changeIndex(std::string val, tree* branch, int from, int to)
 {
	 if (branch != nullptr)
	 {
		 if (branch->crown->head->data == val)
			 return (changeIndexL(val, branch->crown, from, to));
		 else
			 if (branch->crown->head->data > val)
				 return changeIndex(val, branch->left, from, to);
			 else
				 return changeIndex(val, branch->right, from, to);
	 }
 }

std::string print(tree* branch)
{
	std::string result = "";
	if (!branch)
		return "";
	tabs += 5;
	result += print(branch->right);
	for (int i = 0; i < tabs; i++)
		result += " ";
	result += PrintList(branch->crown);
	result += print(branch->left);
	tabs -= 5;
	return result;
}