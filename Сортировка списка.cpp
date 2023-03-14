#include <iostream>
#include <fstream>
#include<string>
#include<tuple>
#include<chrono>

struct auditorium
{
	char litera;
	int num;
};

struct fullname
{
	std::string lastname;
	std::string firstname;
	std::string secondname;
};

struct times
{
	int hour;
	int minute;
};

struct list
{
	auditorium room;
	fullname name;
	times time;
};

struct Node
{
	Node* next;
	Node* prev;
	list data;
};

Node* head = nullptr;
Node* tail = nullptr;

void GetSize(int& size, std::string filename)
{
	std::ifstream(file);
	file.open(filename);
	std::string line;
	std::getline(file, line);
	size = std::stoi(line);
	file.close();
}

void GetArray(list*& record, int size, std::string filename)
{
	std::ifstream(file);
	file.open(filename);
	std::string line;
	getline(file, line);
	int i = 0;
	while (i != size)
	{
		getline(file, line, ' ');
		record[i].room.litera = line[0];
		std::string number = line.erase(0, 1);
		record[i].room.num = stoi(number);
		getline(file, line, ' ');
		record[i].name.lastname = line;
		getline(file, line, ' ');
		record[i].name.firstname = line;
		getline(file, line, ' ');
		record[i].name.secondname = line;
		getline(file, line, ':');
		record[i].time.hour = stoi(line);
		getline(file, line);
		record[i].time.minute = stoi(line);
		i++;
	}
	file.close();
}

void PutArray(Node*head, Node*tail, std::string filename, double time)
{
	std::ofstream(file);
	file.open(filename);
	Node* carrent;
	file << "time: " << time << std::endl;
	if (head != nullptr)
	{
		carrent = head;
		while (carrent != nullptr)
		{
			file << "<-" << carrent->data.room.litera << carrent->data.room.num << " ";;
			file<< carrent->data.name.lastname << " " << carrent->data.name.firstname << " " << carrent->data.name.secondname << " ";
			file << carrent->data.time.hour << ":" << carrent->data.time.minute << "<-" << std::endl;
			carrent = carrent->next;
		}
		std::cout << std::endl;
	}
	file.close();
}

void InsertSort(Node*&head, Node*&tail)
{
	Node* unsortedhead = head->next;
	while (unsortedhead != nullptr) 
	{
		Node* carrent = unsortedhead->prev;
		Node* TMP = unsortedhead;
		TMP->prev->next = TMP->next;
		if (TMP->next != nullptr) 
			TMP->next->prev = TMP->prev;
		TMP->next = nullptr;
		TMP->prev = nullptr;
		unsortedhead = unsortedhead->next;
		while ((carrent != nullptr)&&((std::tie(TMP->data.name.lastname, TMP->data.name.firstname, TMP->data.name.secondname) >= (std::tie(carrent->data.name.lastname, carrent->data.name.firstname, carrent->data.name.secondname)))))
		{
			carrent = carrent->prev;
		}
		if (carrent == nullptr) 
		{
			TMP->next = head;
			head->prev = TMP;
			head = TMP;
		}
		else 
		{
			TMP->next = carrent->next;
			if (TMP->next != nullptr) 
				TMP->next->prev = TMP;
			carrent->next = TMP;
			TMP->prev = carrent;
		}
	}
}

void Timer(double& time, Node*&head, Node*&tail, int size)
{
	std::chrono::time_point<std::chrono::high_resolution_clock>start, end;
	start = std::chrono::high_resolution_clock::now();
	InsertSort(head, tail);
	end = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<double> elapsedTime(end - start);
	const double seconds(elapsedTime.count());
	time = seconds;
}

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

void AddElem(Node*& head, Node*& tail, list record)
{
	Node* carrent;
	Node* TMP;
	TMP = new Node;
	TMP->data = record;
	TMP->next = nullptr;
	TMP->prev = nullptr;
	if (tail == nullptr)
	{
		head = TMP;
		tail = TMP;
	}
	else
	{
		carrent = tail;
		while ((carrent->prev != nullptr) && ((std::tie(carrent->data.room.litera, carrent->data.room.num) < std::tie(record.room.litera, record.room.num))))
		{
			carrent = carrent->prev;
		}
		if ((std::tie(carrent->data.room.litera, carrent->data.room.num) >= std::tie(record.room.litera, record.room.num)))
		{
			TMP->next = carrent->next;
			if (carrent->next != nullptr) carrent->next->prev = TMP;
			TMP->prev = carrent;
			carrent->next = TMP;
		}
		else 
		{
			TMP->prev = carrent->prev;
			carrent->prev = TMP;
			TMP->next = carrent;
			if (TMP->prev == nullptr) head = TMP;
			else TMP->prev->next = TMP;
		}
	}
}

void DelElem(Node*& head, Node*& tail, std::string Name)
{
	Node* elem;
	Node* carrent;
	carrent = head;
	if (head != nullptr)
	{
		if ((head->data.name.firstname == Name) && (carrent->next != nullptr))
		{
			elem = head;
			head->next->prev = nullptr;
			head = head->next;
			delete(elem);
		}
		else if (head->data.name.firstname != Name)
		{
			while ((carrent->data.name.firstname != Name) && (carrent->next != nullptr))
			{
				carrent = carrent->next;
			}
			if ((carrent->data.name.firstname == Name) && (carrent->next != nullptr))
			{
				carrent->next->prev = carrent->prev;
				carrent->prev->next = carrent->next;
				delete(carrent);
			}
			else if ((carrent->data.name.firstname == Name) && (carrent->next == nullptr))
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

bool Serch(Node*& head, Node* tail, std::string Name)
{
	bool f = 0;
	Node* carrent;
	if (head != nullptr)
	{
		carrent = head;
		while (carrent != nullptr)
		{
			if (carrent->data.name.firstname == Name)
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

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* P_begin = nullptr;
	Node* P_end = nullptr;
	int size;
	double time = 0;
	std::ifstream file;
	file.open("Input.txt");
	GetSize(size, "Input.txt");
	list* record = new list[size];
	GetArray(record, size, "Input.txt");
	for (int i = 0; i < size; i++)
	{
		AddElem(P_begin, P_end, record[i]);
	}
	PutArray(P_begin, P_end, "Output.txt", time);
	Timer(time, P_begin, P_end, size);
	PutArray(P_begin, P_end, "OutputSort.txt", time);
	file.close();
	return 0;
}
