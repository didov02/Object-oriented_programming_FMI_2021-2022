## Наследяване

### Какво е наследяване?
Метод за създаване на нови класове от съществуващи класове (механизъм за повторно използване). <br />
Новият клас съдържа данни и поведение на съществуващия клас. <br />
     
Видове наследяване:
- **Single(единично):** нов клас се създава от друг единичен клас.
- **Multiple(множествено):** нов клас се създава от два (или повече) други класа.

### Терминология
- Base class(parent class)
  - Класът се разширява или наследява.
- Derived class (child class)
  - Класът се създава от базовия клас
  - Наследява атрибути и методи от базовия клас
- Is-a relationship (circle is a shape)            
           
        
- Generalization(обобщение):
  - Kомбиниране на подобни класове в един, по-общ клас, базиран на общи атрибути           
- Specialization(специализация):        
  - Създаване на нови класове от съществуващи класове, осигуряващи по-специализирани атрибути.        
- Class Hierarchy(йерархия на класовете):            
  - Организация на отношенията при наследяване.           
<br />
       
![alt text](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI_2021-2022/blob/main/Sem.%2011/img/class_hierarchy.png)
    
### Inheritance vs Composition
| Наследяване   | Композиция     |
| :---:   | :---: |
| is-a | has-a |
| функционалността, чрез която един обект придобива характеристиките на един или повече други обекти | Използването на обект вътре в друг обект |
| дефиниран по време на компилиране - Compile time | дефиниран по време на изпълнение - Runtime |
| "разкрива" public & protected данни на базовия клас| вътрешните данни не са разкрити/достъпни, а взаимодействат чрез публичен интерфейс(public interface) |
| Access control/Visibility | Access control/Visibility |

### Пример за наследяване
При създаване на нов клас, който има общи компоненти и поведение с вече дефиниран клас, вместо да дефинира повторно тези компоненти и поведение, можем да го обявим за наследник на вече дефинирания.

```c++
class A
{
	//some code
public:
     void f()
	{
		//some code
	}
	//some code
};
class B : public A
{
	//some code
}

int main()
{
	B obj;
	obj.f(); // OK!
}
 ```
 При наследяването:
 - Наследяват се член-данните и методите на основните класове
 - Получава се достъп до **някои** от наследените компоненти на основните класове

В нашия пример класът **В е наследник на класа А.** Обекти от класовете изглеждат така:

![alt text](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI_2021-2022/blob/main/Sem.%2011/img/inher-img1.PNG)

След като  В е наследник на класа А, то при създаване на обект от тип В се създава обект от тип А, **който е част от обекта** от тип В.

### Видове наследяване
Някои типове наследяване в c++:

 - private (по подразбиране)
 - protected
 - public

![alt text](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI_2021-2022/blob/main/Sem.%2011/img/visibility.png)

Примери:
```c++
class A 
{
public:
    int x;
protected:
	int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
 ```

### Подаване като параметри на функции.
Класове-наследници могат да бъдат подавани като параметри на функции, които приемат обекти от базовия клас. <br />
Може да се използва функционалността само от базовия клас.

```c++
class A
{
	int a;
}
class B : public A
{
public:
	int b;
}
void f(A& obj)
{
	obj.a++;
}

int main()
{
	A obj1;
	B obj2;
	
	f(obj1); //OK!
	f(obj2); //OK!
}
 ```

### Конструктури и деструктори при наследяване.

```c++
Q: How can we control exactly which Base class constructor is used during initialization?
A: We can invoke whichever Base class constructor we wish in the initialization list of the Derived class.
```
Във всеки контструктор на класът-наследник, трябва да се оказва кой конструктор да се извика за базовия клас. <br />
Ако не оказано, ще се извика конструктора по подразбиране.

```c++
class Derived : public Base
{
.
.
.
public:
Derived(...) : Base(...)
	{
		.
		.
		.
	}
}
```
 
```c++
class Base
{
private:
	int value;
public:
	Base() : value(0)
	{
		std::cout << "Base default constructor called\n"  << std::endl;
	}
	Base(int x) : value(x)
	{
		std::cout << "Base (int) constructor called\n"  << std::endl;
	}
	~Base()
	{
		std::cout << "Base destructor called\n" << std::endl;
	}
};

class Derived : public Base
{
private:
	int doubledValue;
public:
	Derived() : Base(0), doubledValue(0)
	{
		std::cout << "Derived default constructor called\n" << std::endl;
	}
	Derived(int x) : Base(x), doubledValue(2*x)
	{
		std::cout << "Derived (int) constructor called\n" << std::endl;
	}
	~Derived()
	{
		std::cout << "Derived destructor called\n" << std::endl;
	}
};
```
Деструкторът на наследния клас извиква деструктора на базовия клас.


### Копиране при наследяване
При разписване на конструктора за копиране и оператора за присовяване на клас-наследник, трябва експлицитно да извикваме копиране и за базовия клас.
 ```c++
B::B(const B& other) : A(other) // (copy constructor of A (base class)
{
	copyFrom(other);
}

B& B::operator=(const B& other)
{

	if (this != &other)
	{
		A::operator=(other); //operator= of A (base class)
		free();
		copyFrom(other);
	}
	return *this;
}
 ```
