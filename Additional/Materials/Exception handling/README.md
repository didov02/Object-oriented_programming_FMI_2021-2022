## Exception handling

Обработката на изключения са аномалии по време на изпълнение или необичайни условия, които програмата среща по време на своето изпълнение. <br />
Има два дива:
- синхронни(Synchronous)
- асинхронни(Asynchronous) - (Напр.: които са извън контрола на програмата, повреда на диска и т.н.)

### Ключови думи(Key words)
- try - представлява блок от код, който може да изведе изключение.
- throw - използва се за хвърляне на изключение. Също така се използва за изброяване на изключенията, които дадена функция хвърля, но не се справя сама.
- catch - представлява блок от код, който се изпълнява, когато се хвърли конкретно изключение.

### Предимства/Advantages
- Разделяне на кода за обработка на грешки от нормален код. <br />
В традиционните кодове за обработка на грешки винаги има условия за обработка на грешки. <br />
Тези условия и кодът за обработка на грешки се смесват с нормалния поток.Това прави кода по-трудно четим и по-труден за поддръжка(less readable and maintainable). <br />
С блоковете try catch кодът за обработка на грешки става отделен от нормалния поток.

- Функциите/Методите могат да обработват всякакви изключения. <br />
Функцията може да хвърля много изключения, но може да избере да обработва само някои от тях. <br />
Другите изключения, които се хвърлят, но не са уловени, могат да се обработват от caller-a(повикващия) <br />
Ако повикващият избере да не ги хване, тогава изключенията се обработват от извикващия на дадения повикващ(caller of the caller). <br />
В C++, функция може да посочи изключенията, които хвърля, използвайки ключовата дума **throw** <br />
Извикващият на тази функция трябва да обработва изключението по някакъв начин - или като го посочи отново, или като го хване.

- Групиране на типове грешки    
В C++ както основни типове, така и обекти могат да бъдат хвърлени като изключение. <br />
Можем да създадем йерархия от обекти на изключения, да групираме изключения в пространства от имена или класове, да ги категоризираме според типове.

### Пример
```c++
#include <iostream>
using namespace std;
 
int main()
{
   int x = -1;

   cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught \n";
   }
 
   cout << "After catch (Will be executed) \n";
   return 0;
}
```

```c++
//Изход
Before try
Inside try
Exception Caught
After catch (Will be executed)
```

### Catch all - **catch(...)**
```c++

#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 10;
    }
    catch (char *excp)  {
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
```

```
Default Exception
```

###  Implicit type conversion
Имплицитното преобразуване на типове не се случва за примитивни типове. <br />
В случая char не се преобразува имплицитно към int. <br />

```c++
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (int x)  {
        cout << "Caught " << x;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
```

```
Default Exception
```

### Exception thrown but not caught (throw with not catch)

```c++
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (int x)  {
        cout << "Caught ";
    }
    return 0;
}
```

```
terminate called after throwing an instance of 'char'

This application has requested the Runtime to terminate it in an  unusual way.
Please contact the application's support team for more information.
```

### Nested try-catch
```c++
#include <iostream>
using namespace std;
 
int main()
{
    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially ";
            throw; // Re-throwing an exception
        }
    }
    catch (int n) {
        cout << "Handle remaining ";
    }
    return 0;
}
```

```
Handle Partially Handle remaining
```

### Objects in try-catch
Когато се хвърли изключение, всички обекти, създадени вътре в **try** се унищожават преди да бъде прехвърлена към **catch**
```c++
#include <iostream>
using namespace std;
 
class Test {
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};
 
int main()
{
    try {
        Test t1;
        throw 10;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }
}
```

```
Constructor of Test
Destructor of Test
Caught 10
```
