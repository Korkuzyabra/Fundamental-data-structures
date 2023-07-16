#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<tuple>

struct list
{
	std::string plate;
	std::string label;
	std::string model;
	std::string color;
	int num;
	int hash;
};

class HT
{
public:

	HT(int size)
	{
		size1 = size;
		items = new list[size];
		status.resize(size);
	};

	int FirstHF(std::string line, int n)
	{
		int sum, temp;
		unsigned char ch1 = line[0], ch2 = line[1], ch3 = line[2];
		sum = (int)ch1 + (int)ch2 + (int)ch3;
		sum = sum + n;
		temp = sum % 100;
		sum = sum / 100;
		sum = temp + sum;
		return sum % size1;
	}

	int SecondHF(int key)
	{
		return (key + 1) % size1;
	}

	int CollisionAdd(int key, std::vector<int>status, list record)
	{

		int num = 1, tmp = key;
		bool zero = false, same = false;
		while ((status[tmp] != 0) && (num < size1))
		{
			tmp = SecondHF(tmp);
			if ((status[tmp] == 1) && (record.plate == items[tmp].plate))
			{
				same = true;
			}
			num++;
		}
		if (!same)
		{
			if (status[tmp] == 0)
			{
				zero = true;
			}
			if (!zero)
			{
				tmp = key;
				num = 1;
				while ((status[tmp] != 2) && (num < size1))
				{
					tmp = SecondHF(tmp);
					num++;
				}
			}
			key = tmp;
			return key;
		}
		else
			return key = -1;

	}

	int Collision(int key, std::vector<int>status, list record)
	{
		int num = 1;
		bool k = false;
		while (num < size1)
		{
			num++;
			key = SecondHF(key);
			if ((status[key] == 0) || (status[key] == 2))
			{
				k = true;
			}
			if ((status[key] == 1) && (record.plate == items[key].plate))
			{
				k = false;
				break;
			}
		}
		if (k == false)
		{
			return key;
		}
		else
		{
			return key = -1;
		}
	}

	void Add(list& record)
	{
		if (count < size1)
		{
			std::string line;
			int number;
			line = record.plate.substr(0, 1);
			line = line + record.plate[4]+record.plate[5];
			number = std::stoi(record.plate.substr(1, 3));
			int key1 = FirstHF(line, number);
			record.hash = key1;
			if (status[key1] == 0)
			{
				status[key1] = 1;
				items[key1] = record;
				count++;
			}
			else
			{
				if ((status[key1] == 2) || ((status[key1] == 1) && (record.plate != items[key1].plate)))
				{
					int key2 = CollisionAdd(key1, status, record);
					if (key2 != -1)
					{
						status[key2] = 1;
						items[key2] = record;
						count++;
					}
				}
			}
		}
		else
			std::cout << "Таблица заполнена!\n" << std::endl;
	}

	int Search(list record)
	{
		if (count != 0)
		{
			std::string line;
			int number;
			line = record.plate.substr(0, 1);
			line = line + record.plate[4] + record.plate[5];
			number = std::stoi(record.plate.substr(1, 3));
			int key1 = FirstHF(line, number);

			if (status[key1] == 1 && (record.plate == items[key1].plate))
			{
				std::cout << "Найдена запись с ключом " << items[key1].hash << " " << items[key1].plate << " " << items[key1].label << " " << items[key1].model << " " << items[key1].color << std::endl << std::endl;
				return items[key1].num;
			}
			else
			{
				int key2 = Collision(key1, status, record);
				if ((key2 != -1) && (record.plate == items[key2].plate))
				{
					std::cout << "Найдена запись " << items[key2].hash << " " << items[key2].plate << " " << items[key2].label << " " << items[key2].model << " " << items[key2].color << std::endl << std::endl;
					return items[key2].num;
				}
				else
					return -1;
			}

		}
		else
		{
			std::cout << "Таблица пуста!\n" << std::endl;
			return -1;
		}
	}

	bool Delete(list& record)
	{
		if (count != 0)
		{
			std::string line;
			int number;
			line = record.plate.substr(0, 1);
			line = line + record.plate[4] + record.plate[5];
			number = std::stoi(record.plate.substr(1, 3));
			int key1 = FirstHF(line, number);

			if (status[key1] == 1 && (record.plate == items[key1].plate))
			{
				status[key1] = 2;
				count--;
				return true;
			}
			else
			{
				int key2 = Collision(key1, status, record);
				if ((key2 != -1) && (record.plate == items[key2].plate))
				{
					status[key2] = 2;
					count--;
					return true;
				}
				else
					return false;
			}
		}
		else
		{
			std::cout << "Таблица пуста!\n" << std::endl;
			return false;
		}
	}

	void Print()
	{
		for (int i = 0; i < size1; i++)
		{
			std::cout << "[" << i << "]" << " ";
			if (status[i] == 1)
				std::cout << items[i].hash << " " << items[i].plate << " " << items[i].label << " " << items[i].model << " " << items[i].color << std::endl;
			else
				std::cout << "-" << std::endl;
		}
		std::cout << '\n';
	}

	~HT() = default;

private:
	list* items;
	std::vector<int>status;
	int size1;
	int count = 0;
};

