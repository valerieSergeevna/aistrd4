#include "Bellman_Ford_functions.h"
#include <fstream>


void read_file(map<string>*city)
{
	fstream fin;
	fin.open("input.txt", ios::in);
	string buf;
	int id = 0;
	do
	{
		int counter = 0;
		getline(fin,buf);
		while (counter != 2)
		{
			size_t found = buf.find(';');
			if (city->insert(buf.substr(0,found), id))
				id++;
			buf.erase(0,found+1);
			counter++;
		}
		
	} while (!fin.eof());

	fin.close();
}

int **create_graph_matrix(map<string> city)
{
	int **matrix = new int*[city.get_size()];
	for (int i = 0; i < city.get_size(); i++)
		matrix[i] = new int [city.get_size()];
	for (int i = 0; i < city.get_size(); i++)
		matrix[i][i] = -1;
	fstream fin;
	fin.open("input.txt", ios::in);
	string buf;
	do
	{
		int counter = 0;
		getline(fin, buf);
		size_t found = buf.find(';');
		int column = city.find_id(buf.substr(0, found));
		buf.erase(0, found + 1);
		int row = city.find_id(buf.substr(0, buf.find(';')));
		found = buf.find(';');
		buf.erase(0, found + 1);
		found = buf.find(';');
		if (buf.substr(0, found) != "N/A")
			matrix[row][column] = stoi(buf.substr(0, found));
		else matrix[row][column] = -1;
		buf.erase(0, found + 1);
		if (buf.substr(0, buf.length()) != "N/A")
			matrix[column][row] = stoi(buf.substr(0, buf.length()));
		else matrix[column][row] = -1;
	} while (!fin.eof());

	fin.close();
	return matrix;
}

string find_way(int **graph_table, size_t size, int from , int to,int *min)
{
	int inf = 2000000;
	int *path = new int[size];
	string* ways = new string[size];
	for (int i = 0; i < size; i++)
	{
		path[i] = 2000000;
		//ways[i] = nullptr;
	}
	path[from] = 0;
	for (size_t k = 1; k < size; k++)
		for (size_t i = 0; i < size; i++)
			for (size_t j = 0; j < size; j++)
				if ((path[i] + graph_table[j][i] < path[j])&&(graph_table[j][i]>0))
				{
					path[j] = path[i] + graph_table[j][i];
					ways[j] = ways[i] + '_' + to_string(j);
				}
//	*length = path[to];

	cout << "min path " << path[to] << '\n';
	string way;
	way += ways[from];
	way += ways[to];

	return way;
}

void create_path(string path,  map<string> city)
{
	size_t found = path.find('_');
	path.erase(0,found+1);
	while (true)
	{
		found = path.find('_');
		if (path.length()!=1)
			cout << city.find_city(stoi(path.substr(0, found))) << " -> ";
		else
		{
			cout << city.find_city(stoi(path.substr(0, found)));
			break;
		}
		path.erase(0, found + 1);
	}

}