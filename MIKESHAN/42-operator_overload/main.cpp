#include <iostream>
#include <ostream>

class Vector3f
{
public:
	float x,y,z;
	
	Vector3f(): x(0), y(0), z(0)
	{
	}

	Vector3f(int x, int y, int z): x(x), y(y), z(z)
	{
	}

	Vector3f operator+(const Vector3f& other) const
	{
		Vector3f result;
		result.x = x + other.x;
		result.y = y + other.y;
		result.z = z + other.z;
		return result;
	}	

	Vector3f& operator++()
	{
		x++;
		y++;
		z++;
		return *this;
	}

	bool operator==(const Vector3f& other) const 
	{
		if (x == other.x)
		{
			return false;
		}
		return true;
	
	}

};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj)
{
	os << "x: " << obj.x << " y: " << obj.y << " z: " << obj.z;
	return os;
}

/**
bool operator==(const Vector3f& lv, const Vector3f& rv) 
{
	if (lv.x == rv.x 
	    && lv.y == rv.y
	    &&	lv.z == rv.z)
	{
		return true;
	}
	return false;
}
**/
int main()
{
	Vector3f v1(1, 2, 3);
	Vector3f v2(1, 2 ,3);
	Vector3f v3 = v1 + v2;
	std::cout << "v3: " << "x:" << v3.x << " y:" << v3.y  << " z:" << v3.z << std::endl;

	std::cout << "v1: " << "x:" << v1.x << " y:" << v1.y  << " z:" << v1.z << std::endl;

	std::cout << v1;
	if (v1 == v3)
	{
		std::cout << "v1 == v3 \n";
	}
	else
	{
		std::cout << "v1 != v3 \n";
	}
	return 0;
}
