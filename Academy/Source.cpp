//inheritance
#include <iostream>
#include <fstream>
#include <string>


#define delimeter "\n-----------------------------\n"
using namespace std;

class Human
{
	static const int LAST_NAME_WIDTH = 12;
	static const int FIRST_NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count;

protected:

	string lastName;
	string firstName;
	int age;

public:

	const std::string& getLastName() const
	{
		return lastName;
	}

	const std::string& getFirstName() const
	{
		return firstName;
	}

	int getAge() const
	{
		return age;
	}

	void setLastName(const std::string& lastName)
	{
		this->lastName = lastName;
	}

	void setFirstName(const std::string& firstName)
	{
		this->firstName = firstName;
	}
	
	void setAge(int age)
	{
		this->age = age;
	}

	Human(const std::string& lastName, const std::string& firstName, const int age)
	{
		setLastName(lastName);
		setFirstName(firstName);
		setAge(age);
		count++;
		cout << "H Constructor:\t\t" << this << endl;
	}

	virtual ~Human()
	{
		count--;
		cout << "H Destructor:\t\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& os) const
	{
		os.width(LAST_NAME_WIDTH);
		os << std::left;
		os << lastName;
		os.width(FIRST_NAME_WIDTH);
		os << std::left;
		os << firstName;
		os.width(AGE_WIDTH);
		os << std::left;
		os << age;
		return os;
	}
	
	virtual std::ofstream& print(std::ofstream& ofs) const
	{
		ofs << typeid(*this).name() << ":\t";

		ofs.width(LAST_NAME_WIDTH);
		ofs << std::left;
		ofs << lastName;

		ofs.width(FIRST_NAME_WIDTH);
		ofs << std::left;
		ofs << firstName;

		ofs.width(AGE_WIDTH);
		ofs << age;

		return ofs;
	}

	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> lastName >> firstName >> age;
		return ifs;
	}
};

int Human::count = 0; // Определение или же реализация статической переменной

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	obj.scan(ifs);
	return ifs;
}

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 28;
	static const int GROUP_WIDTH = 10;
	static const int RAITING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;

	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& getSpeciality() const
	{
		return speciality;
	}
	const std::string& getGroup() const
	{
		return group;
	}

	double getRating() const
	{
		return rating;
	}

	double getAttendance() const
	{
		return attendance;
	}

	void setSpeciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void setGroup(const std::string& group) 
	{
		this->group = group;
	}

	void setRating(double rating) 
	{
		this->rating = rating;
	}

	void setAttendance(double attendance)
	{
		this->attendance = attendance;
	}

	Student(const std::string& lastName, const std::string& firstName, const int age, 
		const std::string& speciality, const std::string& group, const double rating, const double attendance
	) :Human(lastName, firstName, age)
	{
		setSpeciality(speciality);
		setGroup(group);
		setRating(rating);
		setAttendance(attendance);
		cout << "SConstructor:\t\t" << this << endl;
	}

	~Student()
	{
		cout << "SDestructor:\t\t" << this << endl;
	}
	std::ostream& print(std::ostream& os) const
	{
		Human::print(os) << " ";
		return os << speciality << " " << group << " " << rating << " " << attendance;
	}

	ofstream& print(std::ofstream& ofs) const
	{
		Human::print(ofs) << " ";
		
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		
		ofs.width(GROUP_WIDTH);
		ofs << group;
		
		ofs.width(RAITING_WIDTH);
		ofs << rating;

		ofs.width(ATTENDANCE_WIDTH);
		ofs << attendance;

		return ofs;
	}

	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char sz_speciality[SPECIALITY_WIDTH + 1] = {};
		ifs.read(sz_speciality, SPECIALITY_WIDTH);
		for (int i = strlen(sz_speciality) - 1; sz_speciality[i] == ' '; i--) sz_speciality[i] = 0;
		while (sz_speciality[0] == ' ')
			for (int i = 0; sz_speciality[i]; i++)
				sz_speciality[i] = sz_speciality[i + 1];
		this->speciality = sz_speciality;
		ifs >> group >> rating >> attendance;
		return ifs;
	}
};

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 28;
	static const int EXPERIENCE_WIDTH = 2;

	std::string speciality;
	int experience;

public:

	const std::string& getSpeciality() const
	{
		return speciality;
	}

	int getExperience() const
	{
		return experience;
	}


	void setSpeciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}

	void setExperience(const int experience)
	{
		this->experience = experience;
	}

	Teacher(
		const std::string& lastName, const std::string& firstName, const int age,
		const std::string& speciality, const int experience
	) : Human(lastName, firstName, age)
	{
		setSpeciality(speciality);
		setExperience(experience);

		cout << "TConstructor:\t\t" << this << endl;
	}
	Teacher(const Teacher& other) : Human(other)
	{
		this->speciality = other.speciality;
		this->experience = other.experience;
		cout << "T Copy constructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t\t" << this << endl;
	}
	std::ostream& print(std::ostream& os) const
	{
		Human::print(os) << " ";
		return os << speciality << " " << experience;
	}

	std::ofstream& print(std::ofstream& ofs) const
	{
		Human::print(ofs) << " ";

		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;

		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;

		return ofs;
	}

	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char sz_speciality[SPECIALITY_WIDTH + 1] = {};
		ifs.read(sz_speciality, SPECIALITY_WIDTH);
		for (int i = strlen(sz_speciality) - 1; sz_speciality[i] == ' '; i--) sz_speciality[i] = 0;
		while (sz_speciality[0] == ' ')
			for (int i = 0; sz_speciality[i]; i++)
				sz_speciality[i] = sz_speciality[i + 1];
		this->speciality = sz_speciality;
		ifs >> experience;
		return ifs;
	}
};

class Graduate : public Student
{
	static const int SUBJECT_WIDTH = 30;

	std::string subject;

public:

	const std::string& getSubject() const
	{
		return subject;
	}

	void setSubject(const std::string& subject)
	{
		this->subject = subject;
	}

	Graduate(
		const std::string& lastName, const std::string& firstName, const int age,
		const std::string& speciality, const std::string& group, const double rating, const double attendance,
		const std::string& subject
	) :Student(lastName, firstName, age, speciality, group, rating, attendance)
	{
		setSubject(subject);

		cout << "G Constructor:\t\t" << this << endl;
	}

	~Graduate()
	{
		cout << "G Destructor:\t\t" << this << endl;
	}

	std::ostream& print(std::ostream& os) const
	{
		Student::print(os) << " ";
		return os << subject << endl;
	}

	std::ofstream& print(std::ofstream& ofs) const
	{
		Student::print(ofs) << " ";

		ofs.width(SUBJECT_WIDTH);
		ofs << subject;
		
		return ofs; 
	}

	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

void print(Human** group, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (group[i])
		{
			cout << *group[i] << endl;
			cout << delimeter << endl;
		}
	}
}

void save(Human** group, const int n, const char filename[])
{
	std::ofstream fout;
	fout.open(filename);
	for(int i = 0; i < n; i++)
	{
		if(group[i]) fout << *group[i] << endl;
	}
	fout.close();
	/*std::string command = "start notepad ";
	command += filename;
	system(command.c_str());*/
}

Human* HumanFactory(const std::string& type)
{
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
	//return new Human("", "", 0);
	return nullptr;
}

Human** load(const std:: string& filename, int& size)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{	//1) Определяем размер массива
		for (size = 0;!fin.eof(); size++)
		{
			std::string buffer;
			std::getline(fin, buffer);
		}
		//2) Выделяем память под массив
		group = new Human * [--size] {};
		//3) Возвращаемся в начало файла
		fin.clear();
		fin.seekg(0);
		//4) Создаем и читаем объекты
		for(int i = 0; i < size; i++)
		{
			std::string type;
			std::getline(fin, type, ':');
			fin.ignore();
			group[i] = HumanFactory(type);
			if(group[i]) fin >> *group[i];
		}
		fin.close();
	}
	else 
	{
		cerr << "File not found!" << endl;
	}
	//print(group, sizeof(group) / sizeof(group[0]));
	return group;
}

//#define INHERITANCE
//#define STORE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 30);
	human.print();

	Student student("Pinkman", "Jessie", 20, "Chemistry", "PD-212", 4.8, 0.97);
	student.print();

	Teacher teacher("White", "Walter", 45, "Chemistry", 25);
	teacher.print();

	Graduate graduate("Pinkman", "Jessie", 20, "Chemistry", "PD-212", 4.8, 0.97, "\"Methamphetamine production\"");
	graduate.print();
#endif // INHERITANCE
#ifdef STORE_TO_FILE

	Human* group[] =
	{
		new Student("Ivanov", "Ivan", 22, "Physics", "F-230", 98, 91),
		new Teacher("House", "Gregory", 47, "Medicine", 20),
		new Graduate("Forman", "Eric", 32, "Medicine", "MC-120", 95, 89, "\"Neurophysiology of the brain\""),
		new Teacher("Diaz", "Ricardo", 40, "Weapons destribution", 20)
	};
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	print(group, sizeof(group) / sizeof(group[0]));
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimeter << endl;
	}
#endif // STORE_TO_FILE
#ifdef READ_FROM_FILE
	int size = 0;
	Human** group = load("group.txt", size);
	print(group, size);

	for (int i = 0; i < size; i++)
	{
		delete group[i];
		cout << delimeter << endl;
	}
#endif // READ_FROM_FILE

	
}