#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(const std::string& filename_in, const std::string& filename_out)
{
	ifstream fin(filename_in);

	if (fin.is_open())
	{
		ofstream fout;
		fout.open(filename_out);

		while (!fin.eof())
		{
			string MAC, IP;

			fin >> IP >> MAC;

			fout.width(30);
			fout << std::left;
			fout << MAC << IP << endl;

		}
		fout.close();

		fin.close();
	}
	else
	{
		cerr << "Error! File not found!" << endl;
	}
	std::string command = "start notepad ";
	command += filename_out;
	system(command.c_str());
}

//host 201 - 1
//{
//	hardware ethernet	00:19 : 99 : b4 : c2 : ae;
//	fixed - address		192.168.100.21;
//}
void dhcpd(const std::string& filename_in, const std::string& filename_out)
{
	ifstream fin(filename_in);

	if(fin.is_open())
	{
		ofstream fout;
		fout.open(filename_out);
		int count = 1;
		while(!fin.eof())
		{
			string ip, mac;
			fin >> ip >> mac;
			if(ip != "")
			{
				int width = 30;
				fout << "host 201 - " + to_string(count) << "\n{\n";
				fout.width(width);
				fout << std::left;
				fout << "\thardware ethernet" << mac << ";\n";
				fout.width(width);
				fout << std::left;
				fout << "\tfixed - address" << ip << ";\n}\n" << endl;

				count++;
			}
			
		}
		fout.close();
		fin.close();
	}
	else
	{
		cerr << "Error! File not found!" << endl;
	}
	std::string command = "start notepad ";
	command += filename_out;
	system(command.c_str());
}

void main()
{
	setlocale(LC_ALL, "");

	swap("201 RAW.txt", "201 ready.txt");
	dhcpd("201 RAW.txt", "201 dhcpd.txt");

}