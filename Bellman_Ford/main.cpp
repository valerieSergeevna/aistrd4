#include "Bellman_Ford_functions.h"

void main()
{
	map <string> city;
	read_file(&city);
	//find_way(create_graph_matrix(city), city.get_size(), 1, 2);

	create_path(find_way(create_graph_matrix(city), city.get_size(), 1, 3), city);
/*	for (int i = 0; i < city.get_size(); i++)
	{
		for (int j = 0; j < city.get_size(); j++)
			cout << create_graph_matrix(city)[i][j] << ' ';
		cout << '\n';
	}*/

}