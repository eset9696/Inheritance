#include <iostream>
#include <fstream>

#define delimeter "\n------------------------\n"
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Files!" << endl;
#ifdef WRITE_TO_FILE

	//1) ������� �����:
	ofstream fout;
	//string path = "C:\\Users\\sherk\\OneDrive\\������� ����\\File.txt";
	// 
	//2) ��������� �����:
	fout.open("File.txt", std::ios_base::app);

	//3) ����� � �����:
	fout << "Hello Files!" << endl;

	//4) ��������� �����:
	fout.close();

	//��������� ���� � ������� �������� ������
	system("start notepad File.txt");
#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE
	//1) ������� �����
	ifstream fin;
	//2) ��������� �����
	fin.open("File.txt");
	//3) ��������� �������� �� �����
	if (fin.is_open())
	{
		//4) ������ �����
		while(!fin.eof()) // eof - end of file
		{
			const int SIZE = 10240;
			char sz_buffer[SIZE] = {};
			fin.getline(sz_buffer, SIZE);
			cout << "First read " << sz_buffer << endl;
		}
		//5) ��������� �����
		fin.close();
	}
	else{

		std::cerr << "Error! File not found!" << endl;;
	}

#endif // READ_FROM_FILE

}