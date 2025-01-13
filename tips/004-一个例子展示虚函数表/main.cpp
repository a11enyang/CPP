#include <iostream>

class Visual
{
public:
	virtual ~Visual()
	{
	
	}

	virtual void Draw()
	{
		std::cout << "Visual Draw \n";
	}
};

class Entity
{
public:
	virtual ~Entity()
	{
	}

	virtual void Move()
	{
		std::cout<< "Entity Draw\n";
	}
};


// Npc 是一个多继承的类，
// Npc对象的内存布局大概如下：
/**
+-------------------+
| Visual subobject  |  // 包含虚函数表指针（指向 Visual 的虚函数表）
+-------------------+
| Entity subobject  |  // 包含虚函数表指针（指向 Entity 的虚函数表）
+-------------------+
| Npc-specific data |
+-------------------+

 +-------------------+
| Visual vtable ptr |  --> [0]: Visual::~Visual()
|                   |      [1]: Visual::Draw()
+-------------------+
| Entity vtable ptr |  --> [0]: Entity::~Entity()
|                   |      [1]: Entity::Move()
+-------------------+
| Npc-specific data |
+-------------------+
 
 **/

class Npc: public Visual, Entity
{
public:
	Npc() {}
};

int main()
{
	Npc *npc = new Npc();
	Visual *visual = static_cast<Visual*> (npc);//子类 is-a 父类，子类对象可以向父类对象进行转换
	visual->Draw();

	Entity* entity = reinterpret_cast<Entity*>(visual);// reinterpret_cast指针是一种非常低级的类型转换，不会调整指针的值，不会检查类型是否兼容，
	entity->Move();

	delete npc;
	return 0;
}
