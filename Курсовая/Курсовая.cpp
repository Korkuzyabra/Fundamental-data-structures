#include<iostream>
#include<vector>
#include<string>
#include"Table.h"
#include"Tree.h"

void getArray(std::vector<list>& record, std::string filename)
{
	std::ifstream(file);
	file.open(filename);
	std::string line;
	int i = 0;
	while (!file.eof())
	{
		getline(file, line, ' ');
		record[i].plate = line;
		getline(file, line, ' ');
		record[i].label = line;
		getline(file, line, ' ');
		record[i].model = line;
		getline(file, line);
		record[i].color = line;
		record[i].num = i;
		i++;
	}
	file.close();
}

int getSize(std::string filename)
{
	std::ifstream(file);
	file.open("Автомобили.txt");
	int i = 0;
	std::string line;
	while (!file.eof())
	{
		getline(file, line);
		i++;
	}
	file.close();
	return i;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int s, size;
	size = getSize("Автомобили.txt");
	std::vector<list> record(size);
	getArray(record, "Автомобили.txt");
	std::cout << "Введите размер хеш-таблицы: " << std::endl;
	std::cin >> s;
	HT Table(s);
	for (auto i : record)
	{
		Table.Add(i);
	}
	Table.Print();
	for (auto i : record)
	{
		Table.Delete(i);
	}
	Table.Print();
	for (auto i : record)
	{
		Table.Add(i);
	}
	Table.Print();

	Table.Delete(record[2]);
	Table.Print();
	Table.Add(record[2]);
	Table.Print();

	/*tree* branch = nullptr;
	Add(record[3].label, record[3].num, branch);
	Add(record[6].label, record[6].num, branch);
	Add(record[1].label, record[1].num, branch);
	Add(record[2].label, record[2].num, branch);
	Add(record[4].label, record[4].num, branch);
	Add(record[5].label, record[5].num, branch);
	Add(record[0].label, record[0].num, branch);
	Add(record[7].label, record[7].num, branch);
	Add(record[9].label, record[9].num, branch);
	Add(record[8].label, record[8].num, branch);
	branch=deleteNode(record[7].label, record[7].num, branch);
	print(branch);
	std::cout << '\n';
	branch = nullptr;
	for (auto i : record)
	{
		Add(i.model, i.num, branch);
	}
	print(branch);
	std::cout << '\n';
	branch = nullptr;
	for (auto i : record)
	{
		Add(i.color, i.num, branch);
	}
	print(branch);
	std::cout << search(record[1].color, branch) << std::endl;*/

	return 0;
}