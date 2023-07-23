#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void swap(string*& array, int& size, const std::string& filename);
string* file_read(const std::string& filename, int& size);
void dhcpd(const std::string& filename, const string* array, const int& size);

void main()
{
	setlocale(LC_ALL, "");

	int size = 0;

	string* input = file_read("201 RAW.txt", size);

	swap(input, size, "201 ready.txt");
	dhcpd("201 dhcpd.txt", input, size);


	delete[] input;
}

string* file_read(const std::string& filename, int& size)
{
	ifstream fin(filename);

	string* array = nullptr;

	if (fin.is_open())
	{
		size = 0;
		while (!fin.eof())
		{
			string ip, mac;
			fin >> ip >> mac;
			size++;
		}
		size = --size * 2;

		fin.clear();
		fin.seekg(0, fin.beg);

		array = new string[size]{};

		for (int i = 0; i < size; i++)
		{
			fin >> array[i];
		}

		fin.close();
	}
	else
	{
		cerr << "Error! File not found!" << endl;
	}
	return array;
}

void swap(string*& array, int& size, const std::string& filename)
{
	ofstream fout;
	fout.open(filename);

	for (int i = 0; i < size; i += 2)
	{
		fout.width(20);
		fout << std::left;
		fout << array[i + 1];
		fout << array[i] << endl;
	}

	fout.close();

	std::string command = "start notepad ";
	command += filename;
	system(command.c_str());
}

void dhcpd(const std::string& filename, const string* array, const int& size)
{
	ofstream fout;
	fout.open(filename);
	int count = 1;

	int width = 30;

	for (int i = 0; i < size; i += 2, count++)
	{
		fout << "host 201 - " + to_string(count) << "\n{" << endl;
		fout.width(width);
		fout << std::left;
		fout << "\thardware ethernet" << array[i + 1] << ";" << endl;
		fout.width(width);
		fout << std::left;
		fout << "\tfixed - address" << array[i] << ";\n}\n" << endl;
	}

	fout.close();

	std::string command = "start notepad ";
	command += filename;
	system(command.c_str());
}
