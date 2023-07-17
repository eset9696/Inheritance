//inheritance
#include <iostream>

using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	int getDay() const
	{
		return day;
	}

	int getMonth() const
	{
		return month;
	}

	int getYear() const
	{
		return year;
	}

	void setDay(const int day)
	{
		this->day = day;
	}

	void setMonth(const int month)
	{
		this->month = month;
	}

	void setYear(const int year)
	{
		this->year = year;
	}
	
	Date(int day = 1, int month = 1, int year = 1)
	{
		setDay(day);
		setMonth(month);
		setYear(year);
		cout << "Date constructor: \t\t" << endl;
	}
	~Date()
	{
		cout << "Date Destructor: \t\t" << endl;
	}
	
	void print()
	{
		cout << day << "-" << month << "-" << year << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Date& date)
{
	cout << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
	return os;
}

class Human
{
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
		cout << "HConstructor:\t\t" << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t\t" << endl;
	}

	void print() const 
	{
		cout << lastName << " " << firstName << " " << age << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Human& human)
{
	cout << human.getLastName() << " " << human.getFirstName() << " " << human.getAge();
	return os;
}
class Student :public Human
{
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
		cout << "SConstructor:\t\t" << endl;
	}

	~Student()
	{
		cout << "SDestructor:\t\t" << endl;
	}
	void print() const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Student& student) 
{
	cout << student.getLastName() << " " << student.getFirstName() << " " <<
		student.getAge() << " " << student.getSpeciality() << " " << student.getGroup() <<
		" " << student.getRating() << " " << student.getAttendance();
	return os;
}
class Teacher :public Human
{
	std::string speciality;
	int experience;
	double salary;
	Date dateOfEmployment;
public:
	const std::string getSpeciality() const
	{
		return speciality;
	}

	int getExperience() const
	{
		return experience;
	}

	double getSalary() const
	{
		return salary;
	}

	Date getDateOfEmployment() const
	{
		return dateOfEmployment;
	}

	void setSpeciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}

	void setExperience(const int experience)
	{
		this->experience = experience;
	}

	void setSalary(const double salary)
	{
		this->salary = salary;
	}

	void setDateOfEmployment(const Date& date)
	{
		dateOfEmployment = date;
	}

	Teacher() :Human("", "", 0)
	{
		setSpeciality("");
		setExperience(0);
		setSalary(0);
	}

	Teacher(
		const std::string& lastName, const std::string& firstName, const int age,
		const std::string& speciality, const int experience, const double salary, const Date& date
	) : Human(lastName, firstName, age)
	{
		cout << date << endl;
		setSpeciality(speciality);
		setExperience(experience);
		setSalary(salary);
		setDateOfEmployment(date);
		cout << "TConstructor:\t\t" << endl;
	}

	Teacher(const Teacher& other) : Human(other)
	{
		this->speciality = other.speciality;
		this->experience = other.experience;
		this->salary = other.salary;
		this->dateOfEmployment = other.dateOfEmployment;
		cout << "T Copy constructor:\t" << endl;
	}

	~Teacher()
	{
		cout << "TDestructor:\t\t" << endl;
	}

	void print() const
	{
		Human::print();
		cout << speciality << " " << experience << " " << salary << " " << dateOfEmployment << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Teacher& teacher)
{
	cout << teacher.getLastName() << " " << teacher.getFirstName() << " " <<
		teacher.getAge() << " " << teacher.getSpeciality() << " " << teacher.getSalary() <<
		" " << teacher.getDateOfEmployment();
	return os;
}

class Graduate :public Student
{
	std::string diploma;
	Teacher supervisor;
public:
	const std::string& getDiploma() const
	{
		return diploma;
	}

	const Teacher getSupervisor() const
	{
		return supervisor;
	}

	void setDiploma(const std::string& diploma)
	{
		this->diploma = diploma;
	}

	void setSupervisor(const Teacher supervisor)
	{
		this->supervisor = supervisor;
	}

	Graduate(const Student& student, const std::string& diploma, const Teacher& teacher) :Student{ student }
	{
		setDiploma(diploma);
		setSupervisor(teacher);
		cout << "G Constructor:\t\t" << endl;
	}
	~Graduate()
	{
		cout << "G Destructor:\t\t" << endl;
	}
	void print() const
	{
		Student::print();
		cout << diploma << " " << supervisor.getLastName() << " " << supervisor.getFirstName() << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Graduate& graduate)
{
	cout << graduate.getLastName() << " " << graduate.getFirstName() << " " <<
		graduate.getAge() << " " << graduate.getSpeciality() << " " << graduate.getGroup() << " " << 
		graduate.getRating() << " " << graduate.getAttendance() << graduate.getDiploma() << graduate.getSupervisor();
	return os;
}

void main()
{
	setlocale(LC_ALL, "");

	Human human("Montana", "Antonio", 30);
	human.print();
	cout << human << endl;


	Student student("Pinkman", "Jessie", 20, "Chemistry", "PD-212", 4.8, 0.97);
	student.print();
	cout << student << endl;

	Teacher teacher("Walter", "White", 45, "Chemistry", 25, 1000, Date(2, 10, 1998));
	teacher.print();

	Graduate graduate(student, "Methamfetamine production", teacher);
	graduate.print();
}