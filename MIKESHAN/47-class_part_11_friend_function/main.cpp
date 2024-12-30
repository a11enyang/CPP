#include <iostream>

class UDT
{
public:
	friend void changeNumber(UDT& obj);

	void showNumber() const
	{
		std::cout << "number:" << m_privateNumber << std::endl;
	}
private:
	int m_privateNumber;
};

void changeNumber(UDT& obj)
{
	obj.m_privateNumber = 66;
}

int main()
{
	UDT obj;
 	changeNumber(obj);
	obj.showNumber();	
}
