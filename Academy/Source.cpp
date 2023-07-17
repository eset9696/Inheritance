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

	void setDay(int day)
	{
		this->day = day;
	}

	void setMonth(int month)
	{
		this->month = month;
	}

	void setYear(int year)
	{
		this->year = year;
	}

	Date(const int day, const int month, const int year)
	{
		setDay(day);
		setDay(month);
		setDay(year);
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

class Teacher :public Human
{
	std::string speciality;
	int experience;
	double salary;
	//Date dateOfEnployment;
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

	/*Date getDateOfEnployment() const
	{
		return dateOfEnployment;
	}*/

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

	/*void setDateOfEnployment(const Date date)
	{
		dateOfEnployment = date;
	}*/

	Teacher() :Human("", "", 0)
	{
		setSpeciality("");
		setExperience(0);
		setSalary(0);
	}

	Teacher(
		const std::string& lastName, const std::string& firstName, const int age,
		const std::string& speciality, const int experience, const double salary
	) : Human(lastName, firstName, age)
	{
		
		setSpeciality(speciality);
		setExperience(experience);
		setSalary(salary);
		//setDateOfEnployment(date);
		cout << "TConstructor:\t\t" << endl;
	}
	Teacher(const Teacher& other) : Human(other)
	{
		this->speciality = other.speciality;
		this->experience = other.experience;
		this->salary = other.salary;
		//setDateOfEnployment(date);
		cout << "T Copy constructor:\t" << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t\t" << endl;
	}
	void print() const
	{
		Human::print();
		cout << speciality << " " << experience << " " << salary << endl;
	}
};

class Graduate :Student , Teacher
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
		this->diploma;
	}

	void setSupervisor(const Teacher supervisor)
	{
		this->supervisor = supervisor;
	}

	Graduate(const Student student, const std::string& diploma, const Teacher teacher) :Student{ student }, Teacher{ teacher }
	{
		setDiploma(diploma);
		setSupervisor(teacher);
	}
};


void main()
{
	setlocale(LC_ALL, "");

	Human human("Montana", "Antonio", 30);
	human.print();

	Student student("Pinkman", "Jessie", 20, "Chemistry", "PD-212", 4.8, 0.97);
	student.print();

	Teacher teacher("Walter", "White", 45, "Chemistry", 25, 1000);
	teacher.print();


}