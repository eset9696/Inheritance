#include <iostream>
#include <fstream>

#define delimeter "\n------------------------\n"
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE

	//1) Создаем поток:
	ofstream fout;
	//string path = "C:\\Users\\sherk\\OneDrive\\Рабочий стол\\File.txt";
	// 
	//2) Открываем поток:
	fout.open("File.txt", std::ios_base::app);

	//3) Пишем в поток:
	fout << "Hello Files!" << endl;

	//4) Закрываем поток:
	fout.close();

	//Открываем файл в который записали данные
	system("start notepad File.txt");
#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE
	//1) Создаем поток
	ifstream fin;
	//2) Открываем поток
	fin.open("File.txt");
	//3) Проверяем открылся ли поток
	if (fin.is_open())
	{
		//4) Читаем поток
		while(!fin.eof()) // eof - end of file
		{
			const int SIZE = 10240;
			char sz_buffer[SIZE] = {};
			fin.getline(sz_buffer, SIZE);
			cout << "First read " << sz_buffer << endl;
		}
		//5) Закрываем поток
		fin.close();
	}
	else{

		std::cerr << "Error! File not found!" << endl;;
	}

#endif // READ_FROM_FILE
	ofstream fout_wol("201 ready.txt");
	ofstream fout_dhcpd("201 dhcpd.txt");
	ifstream fin("201 RAW.txt");
	if(fin.is_open())
	{	
		const int MAC_SIZE = 18;
		const int IP_SIZE = 16;

		string mac, ip;

		char sz_mac_buffer[MAC_SIZE]{};
		char sz_ip_buffer[IP_SIZE]{};
		//WOL:
		while(!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			fout_wol << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		
		}
		//DHCPD
		fin.clear();
		fin.seekg(0, fin.beg);

		for (int i = 0; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (strlen(sz_ip_buffer) == 0) continue;
			for (int j = 0; sz_mac_buffer[j]; j++)
			{
				if(sz_mac_buffer[j] == '-'){
					sz_mac_buffer[j] = ':';
				}
			}


			cout << "host - " << i + 1 << endl;
			cout << "{\n";
			cout << "\thardware ethernet:\t" << sz_mac_buffer << ";\n";
			cout << "\tfixed-address:\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n";

			fout_dhcpd << "host -" << i + 1 << endl;
			fout_dhcpd << "{\n";
			fout_dhcpd << "\thardware ethernet:\t" << sz_mac_buffer << ";\n";
			fout_dhcpd << "\tfixed-address:\t\t" << sz_ip_buffer << ";\n";
			fout_dhcpd << "}\n";
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error! File not found!" << endl;
	}

	fout_wol.close();
	fout_dhcpd.close();
	system("start notepad 201 ready.txt");
	system("start notepad 201 dhcpd.txt");
}