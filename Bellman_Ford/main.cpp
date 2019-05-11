#include "Bellman_Ford_functions.h"

void main()
{
	setlocale(LC_ALL, "rus");
	map <string> city;
	read_file(&city);
	//find_way(create_graph_matrix(city), city.get_size(), 1, 2);

	for (int i = 0; i < city.get_size(); i++)
	{
		for (int j = 0; j < city.get_size(); j++)
			cout << create_graph_matrix(city)[i][j] << ' ';
		cout << '\n';
	}

	cout << '\n';

	int min;
	create_path(find_way(create_graph_matrix(city), city.get_size(), 1, 3,min), city);

}