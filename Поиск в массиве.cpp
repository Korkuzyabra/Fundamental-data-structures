#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct auditorium
{
	int num;
};

struct fullname
{
	std::string names;
};

struct sub
{
	std::string subj;
};

struct times
{
	int hour;
	int mint;
};

struct list
{
	auditorium room;
	fullname name;
	sub subject;
	times time;
	int str;
};

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
		record[i].room.num = stoi(line);
		getline(file, line, ' ');
		std::string lastname = line;
		getline(file, line, ' ');
		std::string name = line;
		getline(file, line, ' ');
		std::string midlename = line;
		record[i].name.names = lastname + " " + name + " " + midlename;
		getline(file, line, ':');
		record[i].time.hour = stoi(line);
		getline(file, line, ' ');
		record[i].time.mint = stoi(line);
		getline(file, line);
		record[i].subject.subj = line;
		record[i].str = i;
		i++;
	}
	file.close();
}

void PutArray(int step, int pos, std::string filename)
{
	std::ofstream(file);
	file.open(filename);
	file << "Номер строки: " << pos << std::endl << "Количество шагов: " << step << std::endl;
	file.close();
}

void LenearSearch(std::vector<int>& array, int size, int& step, int& pos, int pattern) 
{
	pos = 2;
	step = 1;
	int p = 0;
	for (int i = 1; i < size; i++)
	{
		if (array[i] == pattern)
		{
			p = 1;
		}
	}
	if (p == 1)
	{
		if (array[size - 1] != pattern)
		{
			array[size - 1] = pattern;
			for (; array[pos] != pattern; pos++)
			{
				step++;
			}
			/*if (pos < size)
				std::cout << pos << std::endl<<step;*/
		}
	}
	else
	{
		pos = -1;
		step = -1;
	}
	//else std::cout << size << std::endl << step;
}

void Linear(list*record, int size, int pattern)
{
	int step, pos;
	std::vector <int> array(size);
	for (int i = 1; i < size; i++)
	{
		array[i] = record[i].room.num;
	}
	LenearSearch(array, size, step, pos, pattern);
	PutArray(step, pos, "LinearOutput.txt");
}

void InsertSort(list*& record, int size)
{
	list tmp;
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && record[j - 1].room.num > record[j].room.num; j--)
		{
			tmp = record[j];
			record[j] = record[j - 1];
			record[j - 1] = tmp;
		}
	}
}

void BinarySearch(std::vector<int>& array, int size, int& step, int& pos, int pattern)
{
	int l = 1, r = size;
	step = 0;
	pos = 0;
	int p = 0;
	for (int i = 1; i < size; i++)
	{
		if (array[i] == pattern)
		{
			p = 1;
		}
	}
	if (p == 1)
	{
		while (l <= r)
		{
			step++;
			int m = l + (r - l) / 2;
			if (array[m] == pattern)
			{
				//std::cout << m << std::endl<<step<<std::endl;
				pos = m;
				break;
			}
			else if (array[m] > pattern)
				r = m - 1;
			else
				l = m + 1;
		}
	}
	else
	{
		pos = -1;
		step = -1;
	}
}

void Binary(list* record, int size, int pattern)
{
	int step, pos;
	InsertSort(record, size);
	std::vector <int> array(size);
	for (int i = 1; i < size; i++)
	{
		array[i] = record[i].room.num;
		//std::cout << array[i] << std::endl;
	}
	BinarySearch(array, size, step, pos, pattern);
	if (pos != -1)
	{
		pos = record[pos].str + 1;
	}
	//std::cout << pos<< std::endl;
	PutArray(step, pos, "BinaryOutput.txt");
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	int pattern = 675;
	std::ifstream file;
	file.open("Input.txt");
	GetSize(size, "Input.txt");
	list* record = new list[size];
	GetArray(record, size, "Input.txt");
	Linear(record, size, pattern);
	Binary(record, size, pattern);
	file.close();
	return 0;
}



