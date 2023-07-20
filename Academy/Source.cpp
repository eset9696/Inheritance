//inheritance
#include <iostream>

#define delimeter "\n------------------------\n"

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

		cout << "Date constructor: \t" << this << endl;
	}

	Date(const Date& other)
	{
		setDay(other.day);
		setMonth(other.month);
		setYear(other.year);

		cout << "Date constructor: \t" << this << endl;
	}

	~Date()
	{
		cout << "Date Destructor: \t" << this << endl;
	}
	
	Date& operator=(const Date& other)
	{
		setDay(other.day);
		setMonth(other.month);
		setYear(other.year);

		cout << "Copy assignment: \t" << this << endl;
		return *this;
	}

	void print()
	{
		cout << delimeter << endl;
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
		
		cout << "HConstructor:\t\t" << this << endl;
	}

	Human(const Human& other)
	{
		setLastName(other.lastName);
		setFirstName(other.firstName);
		setAge(other.age);

		cout << "H Copy constructor:\t" << this << endl;
	}

	~Human()
	{
		
		cout << "HDestructor:\t\t" << this << endl;
	}

	void print() const 
	{
		cout << delimeter << endl;
		cout << "Name: " << lastName << " " << firstName << ". Age: " << age << endl;
	}
};

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

		cout << "SConstructor:\t\t" << this << endl;
	}

	Student(const Student& other) :Human(other)
	{
		setSpeciality(other.speciality);
		setGroup(other.group);
		setRating(other.rating);
		setAttendance(other.attendance);

		cout << "S copy constructor:\t" << this << endl;
	}

	~Student()
	{
		
		cout << "SDestructor:\t\t" << this << endl;
	}
	void print() const
	{
		cout << delimeter << endl;
		Human::print();
		cout << "Speciality: " << speciality << ". Study group: " << group << ". Average score: " << rating <<
			". Attendance: " << attendance << endl;
	}
};

class Teacher :public Human
{
	std::string speciality;
	int experience;
	double salary;
	Date dateOfEmployment;

public:
	const std::string& getSpeciality() const
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

	const Date& getDateOfEmployment() const
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
		setSpeciality(speciality);
		setExperience(experience);
		setSalary(salary);
		setDateOfEmployment(date);

		
		cout << "TConstructor:\t\t" << this << endl;
	}

	Teacher(const Teacher& other) : Human(other)
	{
		setSpeciality(other.speciality);
		setExperience(other.experience);
		setSalary(other.salary);
		setDateOfEmployment(other.dateOfEmployment);
		
		cout << "T Copy constructor:\t" << this << endl;
	}

	~Teacher()
	{
		
		cout << "TDestructor:\t\t" << endl;
	}

	void print() const
	{
		cout << delimeter << endl;
		Human::print();
		cout << "Speciality: " << speciality << ". Work experience: " << experience << ". Salary: " << salary <<
			"$. Date of employment: " << dateOfEmployment << endl;
	}
};

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

		
		cout << "G Constructor:\t\t" << this << endl;
	}
	~Graduate()
	{
		
		cout << "G Destructor:\t\t" << this << endl;
	}
	void print() const
	{
		cout << delimeter << endl;
		Student::print();
		cout << "Diploma theme: " << diploma << ". Diploma supervisor: " << supervisor.getLastName() << " " << supervisor.getFirstName() << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Human human("Montana", "Antonio", 30);
	human.print();


	Student student("Pinkman", "Jessie", 20, "Chemistry", "PD-212", 4.8, 0.97);
	student.print();

	Teacher teacher("Walter", "White", 45, "Chemistry", 25, 1000, Date(2, 10, 1998));
	teacher.print();

	Graduate graduate(student, "\"Methamfetamine production\"", teacher);
	graduate.print();
}