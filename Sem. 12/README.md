## Статично и динамично свързване. Виртуални функции. Полиморфизъм. Абстрактни класове.

### Статично и динамично свързване.

```c++
#include <iostream>
using namespace std;

struct A
{ 
    void f() const 
    {
	std::cout << "A::f()" << std::endl;
    }	
};

struct B : public A
{
    void f() const 
    {
	std::cout << "B::f()" << std::endl;
    }	
};

int main()
{
	B* bPtr = new B();

	A* aPtr = bPtr;
	
	bPtr->f(); // A::f()
	aPtr->f(); // A::f()
}
 ```

 - **Статично** свързване(Static binding/Early binding) - изборът на функцията, която трябва да се изпълни става **по време на компилация(Compile time)**
 - **Динамично** свързване(Dynamic binding/Late binding) – изборът на функцията, която трябва да се изпълни става **по време на изпълнение на програмата(Run time)**.

```c++
#include <iostream>
using namespace std;

struct A
{
    virtual void f() const 
    {
	std::cout << "A::f()" << std::endl;
    }	
};

struct B : public A
{
    void f() const 
    {
       std::cout << "B::f()" << std::endl;
    }	
};

int main()
{
	А* ptrs[2];
	ptrs[0] = new A();
	ptrs[1] = new B();
	
	ptrs[0]->f(); // A::f()
	ptrs[1]->f(); // B::f()
}
 ```
 
### Virtual functions(Виртуални функции)

Член-функция, която е декларирана в основен клас(Base class) и е предефинирана от производен клас(Derived class). <br />
Гарантират, че правилната функция ще се извика за даден обект, независимо от типа reference/pointer(типа препратка), <br />
използван за извикване на функцията. Те се използват главно за постигане на Runtime polymorphism. <br />

#### Правила за виртуални функции
  - **не могат** да бъдат static.
  - може да бъде приятелска функция на друг клас.
  - Прототипът на виртуалните функции трябва да бъде един и същ както в базовия, така и в производния клас.ю
  - Винаги се дефинират в базовия клас, като се предефинират в производния. Не е задължително производния клас да заменя или предефинира виртуалната функция, в такъв случай се използва версията на базовия клас.
  - Достъпът до виртуалните функции трябва да се осъществява използвайки reference/pointer към базовия клас, за да се осъществи Runtime polymorphism.
  - **Класът може да има виртуален деструктор, но не може да има виртуален конструктор.**

#### Virtual pointer(vPtr) | Virtual table(vTable)

![alt text](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI_2021-2022/blob/main/Sem.%2012/img/vtable-1.png)

### Полиморфизъм
Едни и същи действия се реализират по различен начин, в зависимост от обектите, върху които се прилагат. <br />
An entity(object or function) behaves differently in different scenarios. <br />
 - Действията се наричат **полиморфни**.
 - Реализира се чрез виртуални функции.
 - Класовете, върху които ще се прилага, трябва да имат общ родител или прародител, **да са наследници на един и същ клас**.
 - В класа се дефинира виртуален метод, съответстващ на полиморфното действие.
 - Всеки клас предефинира или не виртуалния метод.
 - "Активирането" става чрез указател към базов клас, на който може да се присвоят адресите на обекти на който и да е от базовите класове от йерархията.

#### Compile time polymorphism vs Runtime polymorphism
- Compile time - дадена функция се извиква по време на компилация на програмата(function overload/operator overload).
- Runtime - функциите се извикват в момента на изпълнение на програмата (Dynamic binding/Late binding).

**Важно!** При полиморфна йерархия ще изтриваме обектите чрез указатели от базовия клас. За да се извикват правилните деструкори задължително **деструкторът на базовият клас** трябва е деклариран като виртуален!
```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const
	{
		std::cout << "Hello, I am a random animal" << std::endl;
	}

	virtual ~Animal(){} //!!!
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
};

int main()
{
	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a random animal!

	delete animals[0], animals[1], animals[2];
	delete[] animals;
}

 ```
 #### Абстрактен клас
 

 - Чисто виртуална функция (**pure virtual function**) - виртуална функция без тяло.
 - Клас е **абстрактен**, ако в него има поне една **чисто виртуална функция**.

Тогава класът е предназначен единствено за наследяване и няма да може да създаваме обекти от него.
Така във всеки наследник ще трябва да се разпише имплементация на функцията. Ако някой наследник няма собствена имплементация, то и той става абстрактен клас.

```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const = 0;


	virtual ~Animal(){} //!!!
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a mouse!" << std::endl;
	}
};

struct PrehistoricAnimal : public Animal
{};

int main()
{
	// Animal* pa1 = new Animal(); No! Animal is an abstract class!
	// Animal* pa2 = new PrehistoricAnimal(); No! PrehistoricAnimal is also an abstract class!

	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a random animal!

	delete animals[0], animals[1], animals[2];
	delete[] animals;
}

 ```
