//граф - неориентированный, взвешенный, внутреннее представление - матрица смежности, обход - в глубину (нерекурсивная реализация), алгоритм - остов (Прима)
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>

class Graph
{
public:
	Graph(int vertices) :vertices(vertices)
	{
		matrix.resize(vertices, std::vector<int>(vertices, 0));
	}

	void addVertex()
	{
		++vertices;
		matrix.resize(vertices, std::vector<int>(vertices, 0));
		for (int i = 0; i < vertices - 1; ++i)
			matrix[i].resize(vertices, 0);
	}

	void removeVirtex(int vertex)
	{
		if (vertex >= 0 && vertex < vertices)
		{
			matrix.erase(matrix.begin() + vertex);
			for (int i = 0; i < vertices - 1; i++)
			{
				matrix[i].erase(matrix[i].begin() + vertex);
			}
			--vertices;
		}
	}

	void addEdge(int scr, int dest, int weight)
	{
		matrix[scr][dest] = weight;
		matrix[dest][scr] = weight;
	}

	void removeEdge(int scr, int dest)
	{
		if (scr > 0 && scr < vertices && dest > 0 && dest < vertices)
		{
			matrix[scr][dest] = 0;
			matrix[dest][scr] = 0;
		}
	}

	void print()
	{
		for (int i = 0; i < vertices; ++i)
		{
			for (int j = 0; j < vertices; ++j)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << '\n';
	}

	void DFS(int startVertex)
	{
		std::stack<int> stack;
		std::vector<bool> visited(vertices, false);
		
		visited[startVertex] = true;
		stack.push(startVertex);

		while (!stack.empty())
		{
			int currVertex = stack.top();
			stack.pop();

			std::cout << currVertex << " ";
			for (int i = 0; i < vertices; ++i)
			{
				if (matrix[currVertex][i] != 0 && !visited[i])
				{
					visited[i] = true;
					stack.push(i);
				}
			}
		}

		std::cout << '\n';
	}

	void primMST()
	{
		std::vector<int> parent(vertices, -1);
		std::vector<int> key(vertices, INT_MAX);
		std::vector<bool> mstSet(vertices, false);

		key[0] = 0;

		for (int count = 0; count < vertices - 1; ++count) {
			int minKey = INT_MAX;
			int minIndex = -1;

			for (int v = 0; v < vertices; ++v) {
				if (!mstSet[v] && key[v] < minKey) {
					minKey = key[v];
					minIndex = v;
				}
			}

			mstSet[minIndex] = true;

			for (int v = 0; v < vertices; ++v) {
				if (matrix[minIndex][v] != 0 && !mstSet[v] && matrix[minIndex][v] < key[v]) {
					parent[v] = minIndex;
					key[v] = matrix[minIndex][v];
				}
			}
		}

		std::cout << "Minimum Spanning Tree:" << std::endl;
		for (int i = 1; i < vertices; ++i) {
			std::cout << parent[i] << " - " << i << " : " << matrix[i][parent[i]] << std::endl;
		}
	}

	void getMatrix(std::string filename)
	{
		std::ifstream(file);
		file.open(filename);
		std::string line;
		std::getline(file, line);
		for (int i = 0; i < vertices; ++i)
		{
			for (int j = 0; j < vertices; ++j)
			{
				file >> matrix[i][j];
			}
		}
		file.close();
	}

	~Graph()
	{
		matrix.clear();
	}

private:
	int vertices;
	std::vector<std::vector<int>> matrix;
};

void getSize(int& size, std::string filename)
{
	std::ifstream(file);
	file.open(filename);
	std::string line;
	std::getline(file, line);
	size = std::stoi(line);
	file.close();
}

int main()
{
	int size;
	getSize(size, "graph.txt");
	Graph graph(size);
	graph.getMatrix("graph.txt");
	graph.print();
	graph.DFS(0);
	graph.primMST();
	/*graph.addVertex();
	graph.print();*/
	/*graph.addEdge(1, 2, 6);
	graph.print();*/
	/*graph.removeEdge(1, 2);
	graph.print();*/
	return 0;
}
