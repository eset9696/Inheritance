#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


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
		return os << lastName << " " << firstName << " " << age;
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

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
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
};

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 22;
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
};

void print(Human** group, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
		cout << delimeter << endl;
	}
}

void save(Human** group, const int n, const char filename[])
{
	std::ofstream fout;
	fout.open(filename);
	for(int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	/*std::string command = "start notepad ";
	command += filename;
	system(command.c_str());*/
}

void clear(Human** group, const int size)
{
	for (int i = 0; i < size; i++)
	{
		delete group[i];
	}
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
		fin.clear();
		fin.seekg(0, fin.beg);
		//2) Выделяем память под массив
		group = new Human * [--size] {};
		for(int i = 0; i < size; i++)
		{
			string cl, type;
			fin >> cl >> type;

			if(type == "Student:")
			{
				string last_name, first_name, stud_group, speciality;
				int age;
				double raiting, attendance;

				fin >> last_name >> first_name >> age >> speciality >> stud_group >> raiting >> attendance;
				group[i] = new Student(last_name, first_name, age, speciality, stud_group, raiting, attendance);
			}
			else if(type == "Teacher:")
			{
				string last_name, first_name, speciality;
				int age, experience;
				fin >> last_name >> first_name >> age >> speciality >> experience;
				group[i] = new Teacher(last_name, first_name, age, speciality, experience);
			}
			else if (type == "Graduate:")
			{
				string last_name, first_name, stud_group, speciality, subject;
				int age;
				double raiting, attendance;
				fin >> last_name >> first_name >> age >> speciality >> stud_group >> raiting >> attendance >> subject;
				group[i] = new Graduate(last_name, first_name, age, speciality, stud_group, raiting, attendance, subject);
			}
			
		}
		fin.close();
	}
	else 
	{
		cerr << "File not found!" << endl;
	}
	return group;
}

//#define INHERITANCE

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

	Human* group[] =
	{
		new Student("Ivanov", "Ivan", 22, "Physics", "F-230", 98, 91),
		new Teacher("House", "Gregory", 47, "Medicine", 20),
		new Graduate("Forman", "Eric", 32, "Medicine", "MC-120", 95, 89, "\"Neurophysiology of the brain\""),
	};

	save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	print(group, sizeof(group) / sizeof(group[0]));

	int size = 0;
	Human** group2 = load("group.txt", size);
	print(group2, size);

	clear(group, sizeof(group) / sizeof(group[0]));
	clear(group2, size);
	
}