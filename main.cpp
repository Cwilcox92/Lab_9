//Carlton Wilcox
// 12-3-2018
//Lab_09
// I worked on this lab with Brandon Endsley, Will Kirkpatrick and James Schuchardt

#include <cstdlib>

#include<vector>

#include <iostream>
#include<string>
#include<fstream>
#include <algorithm>
#include <map>;

using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::sort;





void ReadData(vector<string>& data, ifstream& in)
{
	if (in.is_open())
	{
		string temp;
		in >> temp;
		do
		{
			data.push_back(temp);
			in >> temp;

		} while (!(in.eof()));
	}
}

void writeto(map<string, int> data)
{
	string filename;

	ofstream outputfile;

	cout << "Enter the name of the file you would like to write to: ";
	cin >> filename;
	outputfile.open(filename);

	map<string, int>::iterator turn = data.begin();
	while (turn != data.end())
	{
		for (int i = 0; i < turn->second; i++)
		{
			outputfile << turn->first << " ";
		}
		++turn;
	}

	outputfile.close();
}



void WriteToMap(map<string, int>& map, vector<string> in)
{
	for (int i = 0; i < in.size(); i++)
	{
		++map[in.at(i)];
	}
}

int main()
{
	string filename;
	vector<string> data;
	map<string, int> map;
	ifstream inputfile;

	cout << "Enter the name of the file to read: ";
	cin >> filename;

	inputfile.open(filename);
	ReadData(data, inputfile);
	WriteToMap(map, data);
	writeto(map);








	system("pause");
	return 0;

}