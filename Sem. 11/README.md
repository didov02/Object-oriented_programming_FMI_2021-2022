## Наследяване
      
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

## Видове наследяване
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
Във всеки контструктор на класът-наследник, трябва да се оказва кой конструктор да се извика за базовия клас. <br />
Ако не оказано, ще се извика конструктора по подразбиране.

```c++
class B : public A
{
	//some code
public:
	B(...) : A(...) //some constructor of A.
	{
		//some code
	}
}
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
