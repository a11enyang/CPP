#include <iostream>
#include <cstring>

class Student
{
public:
	Student(int numGrades): numGrades(numGrades) 
	{
		grades = new int[numGrades];
		std::cout << "构造函数 Called \n";
	}

	//复制构造函数
	Student(const Student& other): numGrades(other.numGrades)
	{
		grades = new int[numGrades];
		std::copy(other.grades, other.grades + numGrades, grades);
		std::cout <<"复制构造函数 Called \n";
	}

	Student& operator=(const Student& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] grades;
		
		numGrades = other.numGrades;
		grades = new int[numGrades];
		std::copy(other.grades, other.grades + numGrades, grades);
		std::cout << "赋值运算符 Called \n";
		return *this;
	}

	~Student()
	{
		delete[] grades;
		std::cout << "析构函数\n";
	}



private:
	int numGrades;
	int* grades;
};



int main()
{
	Student s1(10);
	Student s2 = s1;
	Student s3(20);
        s3 = s1;	

}
