#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<tuple>

struct auditorium
{
	char litera;
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

	int FirstHF(std::string line, int t, int m)
	{
		std::vector<std::string> ch;
		for (int i = 0; i < line.length(); i += 2)
		{
			ch.push_back(line.substr(i, 2));
		}
		unsigned long sum = 0;
		for (auto c : ch)
		{
			if (c.length() % 2 == 0)
				sum = sum + abs((int)c[0]) + abs((int)c[1]);
			else
				sum += abs((int)c[0]);
		}
		sum = sum + t + m;
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
			if ((status[tmp] == 1) && std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) == std::tie(items[tmp].name.names, items[tmp].room.litera, items[tmp].room.num, items[tmp].subject.subj, items[tmp].time.hour, items[tmp].time.mint))
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
		while (num < size1)
		{
			num++;
			key = SecondHF(key);
			if ((status[key] == 0) || (status[key] == 2))
			{
				key = -1;
				break;
			}
			else if ((status[key] == 1) && std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) == std::tie(items[key].name.names, items[key].room.litera, items[key].room.num, items[key].subject.subj, items[key].time.hour, items[key].time.mint))
			{
				break;
			}
		}
		return key;
	}

	void Add(list& record)
	{
		if (count < size1)
		{
			int key1 = FirstHF(record.name.names, record.time.hour, record.time.mint);
			record.hash = key1;
			if (status[key1] == 0)
			{
				status[key1] = 1;
				items[key1] = record;
				count++;
			}
			else
			{
				if ((status[key1] == 2) || ((status[key1] == 1) && std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) != std::tie(items[key1].name.names, items[key1].room.litera, items[key1].room.num, items[key1].subject.subj, items[key1].time.hour, items[key1].time.mint)))
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

	bool Search(list record)
	{
		if (count != 0)
		{
			int key1 = FirstHF(record.name.names, record.time.hour, record.time.mint);

			if (status[key1] == 1 && (std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) == std::tie(items[key1].name.names, items[key1].room.litera, items[key1].room.num, items[key1].subject.subj, items[key1].time.hour, items[key1].time.mint)))
			{
				std::cout << "Найдена запись с ключом " << items[key1].hash << " " << items[key1].name.names << " " << items[key1].time.hour << ":" << items[key1].time.mint << std::endl << std::endl;
				return true;
			}
			else
			{
				int key2 = Collision(key1, status, record);
				if ((key2 != -1) && (std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) == std::tie(items[key2].name.names, items[key2].room.litera, items[key2].room.num, items[key2].subject.subj, items[key2].time.hour, items[key2].time.mint)))
				{
					std::cout << "Найдена запись " << items[key2].name.names << " " << items[key2].time.hour << ":" << items[key2].time.mint << std::endl << std::endl;
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

	bool Delete(list record)
	{
		if (count != 0)
		{
			int key1 = FirstHF(record.name.names, record.time.hour, record.time.mint);

			if (status[key1] == 1 && (std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) == std::tie(items[key1].name.names, items[key1].room.litera, items[key1].room.num, items[key1].subject.subj, items[key1].time.hour, items[key1].time.mint)))
			{
				status[key1] = 2;
				count--;
				return true;
			}
			else
			{
				int key2 = Collision(key1, status, record);
				if ((key2 != -1) && (std::tie(record.name.names, record.room.litera, record.room.num, record.subject.subj, record.time.hour, record.time.mint) == std::tie(items[key2].name.names, items[key2].room.litera, items[key2].room.num, items[key2].subject.subj, items[key2].time.hour, items[key2].time.mint)))
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
				std::cout << items[i].hash << " " << items[i].name.names << " " << items[i].time.hour << ":" << items[i].time.mint << std::endl;
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

int main()
{
	setlocale(LC_ALL, "rus");
	int s;
	std::cin >> s;
	HT Table(s);
	list record;
	Table.Search(record);
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 8;
	record.time.mint = 30;
	Table.Add(record);
	Table.Print();
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 8;
	record.time.mint = 30;
	Table.Add(record);
	record.name.names = "Ваяй Михаил Сеевич";
	record.time.hour = 8;
	record.time.mint = 30;
	Table.Add(record);
	Table.Print();
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 18;
	record.time.mint = 20;
	Table.Add(record);
	Table.Print();
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 18;
	record.time.mint = 20;
	Table.Add(record);
	Table.Search(record);
	record.name.names = "Ваяй Мл Сергеевич";
	record.time.hour = 10;
	record.time.mint = 30;
	Table.Add(record);
	Table.Print();
	record.name.names = "Ваяй Михил Сергеевич";
	record.time.hour = 10;
	record.time.mint = 30;
	Table.Add(record);
	Table.Print();
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 8;
	record.time.mint = 30;
	Table.Delete(record);
	Table.Print();
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 8;
	record.time.mint = 30;
	Table.Add(record);
	Table.Print();
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 18;
	record.time.mint = 20;
	Table.Search(record);
	record.name.names = "Ваяй Михаил Сергеевич";
	record.time.hour = 18;
	record.time.mint = 20;
	Table.Delete(record);
	Table.Delete(record);
	Table.Delete(record);
	Table.Print();

	return 0;
}
