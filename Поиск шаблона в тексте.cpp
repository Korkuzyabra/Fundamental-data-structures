#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include<vector>

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
		record[i].room.litera = line[0];
		std::string number = line.erase(0, 1);
		record[i].room.num = stoi(number);
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
		i++;
	}
	file.close();
}

void PutArray(list* record, int size, double time, std::string filename)
{
	std::ofstream(file);
	file.open(filename);
	file << time << std::endl;
	for (int i = 0; i < size; i++)
	{
		file << record[i].room.litera << record[i].room.num << " ";
		file << record[i].name.names << " ";
		file << record[i].time.hour << ":" << record[i].time.mint << " ";
		file << record[i].subject.subj << std::endl;
	}
	file.close();
}

void DirectSearch(std::string str, std::string pattern, int& res, int& m)
{
	int strl = str.length();
	int patl = pattern.length();
	res = -1;
	m = 0;
	for (int i = 0; i < strl - patl + 1; i++)
	{
		for (int j = 0; j < patl; j++)
		{
			if (pattern[j] != str[i + j])
				break;
			else if (j == patl - 1)
			{
				m = m+1;
				res = i;
				break;
			}
		}
	}
}

void DirectTimer(list* record, double& time, std::string pattern, int size, int res1, int res2, int m1, int m2, std::string filename)
{
	std::chrono::time_point<std::chrono::high_resolution_clock>start, end;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++)
	{
		DirectSearch(record[i].name.names, pattern, res1, m1);
		DirectSearch(record[i].subject.subj, pattern, res2, m2);
	}
	end = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<double> elapsedTime(end - start);
	const double seconds(elapsedTime.count());
	time = seconds;
}

void fullSuffixMatch(std::vector <int>& shiftArr, std::vector <int>& borderArr, std::string pattern)
{
	int n = pattern.length();       
	int i = n;
	int j = n + 1;
	borderArr[i] = j;

	while (i > 0) {
		while (j <= n && pattern[i - 1] != pattern[j - 1]) 
		{
			if (shiftArr[j] == 0)
				shiftArr[j] = j - i;     
			j = borderArr[j];      
		}
		i--;
		j--;
		borderArr[i] = j;
	}
}

void partialSuffixMatch(std::vector <int>& shiftArr, std::vector <int>& borderArr, std::string pattern)
{
	int n = pattern.size();    
	int j;
	j = borderArr[0];

	for (int i = 0; i < n; i++) {
		if (shiftArr[i] == 0)
			shiftArr[i] = j;      
		if (i == j)
			j = borderArr[j];    
	}
}

void Table(std::vector <int>& shiftArray, std::vector <int>& borderArray, int patLen, std::string pattern)
{
	for (int i = 0; i <= patLen; i++)
		shiftArray[i] = 0;
	fullSuffixMatch(shiftArray, borderArray, pattern);
	partialSuffixMatch(shiftArray, borderArray, pattern);
}

void BMSearch (std::string str, std::string pattern, std::vector<int>& shiftArray, std::vector<int>& borderArray, int& res, int& m, int patLen)
{
	int strLen = str.length();
	/*int patLen = pattern.length();
	std::vector <int> borderArray(patLen+1);
	std::vector <int> shiftArray(patLen+1);*/
	m = 0;
	res = -1;

	for (int i = 0; i <= patLen; i++) {
		shiftArray[i] = 0;
	}

	fullSuffixMatch(shiftArray, borderArray, pattern);
	partialSuffixMatch(shiftArray, borderArray, pattern);

	int shift = 0;

	while (shift <= (strLen - patLen))
	{
		int j = patLen - 1;
		while (j >= 0 && pattern[j] == str[shift + j])
			j--; 
		if (j < 0) 
		{
			res++;
			str[res] = shift;
			shift += shiftArray[0];
			m = m + 1;
		}
		else
			shift += shiftArray[j + 1];
	}
}

void BMTimer(list* record, double& time, std::string pattern, int size, int res1, int res2, int m1, int m2, int patLen, std::vector<int>& shiftArray, std::vector<int>& borderArray, std::string filename)
{
	std::chrono::time_point<std::chrono::high_resolution_clock>start, end;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++)
	{
		BMSearch(record[i].name.names, pattern, shiftArray, borderArray, res1, m1, patLen);
		BMSearch(record[i].subject.subj, pattern, shiftArray, borderArray, res2, m2, patLen);
	}
	end = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<double> elapsedTime(end - start);
	const double seconds(elapsedTime.count());
	time = seconds;
}

void Direct(list* record, std::string pattern, int size, int k)
{
	int res1 = -1, m1 = 0, res2 = -1, m2 = 0, j = 0;
	double time = 0;
	list* listing1 = new list[size];
	DirectTimer(record, time, pattern, size, res1, res2, m1, m2, "OutputDirect.txt");
	for (int i = 0; i < size; i++)
	{
		DirectSearch(record[i].name.names, pattern, res1, m1);
		DirectSearch(record[i].subject.subj, pattern, res2, m2);
		if ((res1 != -1 && m1 == k) || (res2 != -1 && m2 == k))
		{
			listing1[j] = record[i];
			j++;
		}
	}
	PutArray(listing1, j, time, "OutputDirect.txt");
}

void BM(list* record, std::string pattern, int size, int k)
{
	int res1 = -1, m1 = 0, res2 = -1, m2 = 0, j = 0;
	double time = 0;
	list* listing2 = new list[size];

	int patLen = pattern.length();
	std::vector <int> borderArray(patLen + 1);
	std::vector <int> shiftArray(patLen + 1);
	Table(borderArray, shiftArray, patLen, pattern);

	BMTimer(record, time, pattern, size, res1, res2, m1, m2, patLen, shiftArray, borderArray, "OutputBM.txt");
	for (int i = 0; i < size; i++)
	{
		BMSearch(record[i].name.names, pattern, shiftArray, borderArray, res1, m1, patLen);
		BMSearch(record[i].subject.subj, pattern, shiftArray, borderArray, res2, m2, patLen);
		if ((res1 != -1 && m1 == k) || (res2 != -1 && m2 == k))
		{
			listing2[j] = record[i];
			j++;
		}
	}
	PutArray(listing2, j, time, "OutputBM.txt");
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	std::ifstream file;
	file.open("Input.txt");
	GetSize(size, "Input.txt");
	list* record = new list[size];
	GetArray(record, size, "Input.txt");
	file.close();

	std::string pattern = "ия";
	int k = 1;

	Direct(record, pattern, size, k);
	BM(record, pattern, size, k);

	return 0;
}