#pragma once
#include "map.cpp"
#include <string>

using namespace std;


void read_file(map<string>*);
int** create_graph_matrix(map<string>);
string find_way(int**,size_t, int , int, int*);
void create_path(string path,  map<string> city);