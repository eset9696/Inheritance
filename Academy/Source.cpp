//inheritance
#include <iostream>


#define delimeter "\n-----------------------------\n"
using namespace std;

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

	virtual ~Human()
	{
		cout << "HDestructor:\t\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& os) const
	{
		return os << lastName << " " << firstName << " " << age;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
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
};

class Teacher :public Human
{
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
};

class Graduate : public Student
{
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
};

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
		new Student("Ivanov", "Ivan", 22, "Physics", "F-230", 0.9, 0.78),
		new Teacher("House", "Gregory", 47, "Medicine", 20),
		new Graduate("Forman", "Eric", 32, "Medicine", "MC-120", 0.99, 0.93, "\"Neurophysiology\""),
	};
	for (int i = 0; i <  sizeof(group)/ sizeof(group[0]); i++)
	{
		/*cout << typeid(*group[i]).name() << ":\n";
		group[i]->print();*/
		cout << *group[i] << endl;
		cout << delimeter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimeter << endl;
	}
}