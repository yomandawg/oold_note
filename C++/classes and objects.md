# C++ Classes and Objects



## Object

> Object Oriented Programming is a programming style that is intended to make thinking about programming closer to thinking about the real world
>
> objects are independent units, and each has its own identity, just as objects in the real world
>
> it is possible to have two mugs that look identical, but they are still separate, unique objects
>
> object might contain other objects but they're still different objects
>
> three dimensions for OOP: identity, attributes, behavior

* object *characteristics* == **attributes** - describes the current *state* of an object

* in programming, an object is *self-contained*, with its own *identity*. It is separate from other objects
* each object has its own *attributes*, which describe its current state. Each exhibits its own *behavior*, which demonstrates what they can do



## Class

* objects are created using classes, which are the focal point of OOP

* the **class** describes what the object will be, but is separate from the object itself

  * object's blueprint, description, definition

* **methods** is the term for the class behavior - function that belongs to a class

  * methods are similar to functions - they are blocks of code that are called, and they can also perform actions and return values

  ```
  name: BankAccount
  attributes: accountNumber, balance, dateOpened
  behavior: open(), close(), deposit()
  ```

* each object is called an **instance** of a class.

  * creating an object == *instantiation*

```c++
class BankAccount {
    public:
        void sayHi() {
            cout << "Hi" << endl;
        }
}; // class definition must be followed by a semicolon

int main()
{
    BankAccount test; // define an object with all members of the class defined
    test.sayHi(); // dot separator is used to acceses and call the method of the object
}
```

#### abstraction

* fundamental of the OOP
* concept of providing only *essential information* to the outside world
  * an idea or concept that is completely separate from any specific *instance*
* process of representing essential features *without including implementation details*
  * ex) *book*: you don't know the exact specifics, but you understand the *idea of a book*(abstraction)
* `cout << "Hello!" << endl;`: you're using `cout` object of the class `ostream`: this streams data to result in std output
  * there is no need to understand how `cout` works

#### encapsulation

* surrounding the entity, not just to keep what's inside together, but also protect it
  * in OOP, restricting access to the inner workings of that class
  * only reveals what the other application components require to effectively run the app. else is kept out of view: *data hiding*
* ex) we do not want some other part of our program to reach in `BankAccount` class and change the `balance` of any object, without going through `deposit()` or `withdraw()`
  * should hide that attribute, control access to it, so it is accessible only by the object itself = *black boxing*
    * closing the inner working zones of the object, except of the pieces that go public
* summary: **encapsulation**
  * *control* the way data is accessed or modified - *access specifiers*
  * code is more *flexible* and easy to change with new requirements
  * *change* one part of code without affecting other part of code

#### Access Specifiers

* used to set access levels 
* **public**, **protected**, **private**

```c++
#include <iostream>
#include <string>
using namespace std;

class myClass {
    public: // access modifiers only need to be declared once
    	string name; // public can be accessed and modified from outside the code
};

int main() {
    myClass myObj;
    myObjname = "learner";
    cout << myObj.name; // "learner"
    return 0;
}
```

```c++
#include <iostream>
#include <string>
using namespace std;

class myClass {
    public:
        void setName(string x) { // public setName() method is used to set the private name attribute
            name=x; // public member function may be used to access the private members
        }
   	private: // private members cannot be accessed or viewed from outside the class, it can be accessed only from within the class
    	string name; // name attribute is private and not accessible from the outside
};

int main() {
    myClass myObj;
    myObj.setName("John"); // public member function may be used to access the private members
    return 0;
}
```

* if no access specifier is defined, all members of a class are set to private by default

```c++
// can add another public method in order to get the value of the attribute
class myClass {
    public:
        void setName(string x) {
            name = x;
        }
        string getName() { // getName() method returns the value of the private name attribute
            return name;
        }
    private:
    	string name;
};
```

```c++
#include <iostream>
#include <string>
using namespace std;

class MyClass {
    // access specifiers
    public:
    void setName(string x) {
        name = x;
    }
    string getName() {
        return name; // accessing hidden attribute
    }
    private:
    string name; // encapsulation hide name
};

int main() {
    myClass myObj;
    myObj.setName("john");
    cout << myObj.getName(); // john
    return 0;
}
```



#### Constructors

* class **constructors** are executed whenever new objects are created within that class

```c++
class myClass {
    public:
    myClass() { // constructor's name is identical to that of the class, no return type
        cout << "hey"; // executed automatically upon creation
    }
    void setName(string x) {
        name = x;
    }
    string getName() {
        return name;
    }
    private:
    string name;
};

int main() {
    myClass myObj; // outputs "hey"
    return 0;
}
```

* can be useful for setting initial values for certain member variables
* default constructor has no parameters, can assign an object when it's created

```c++
class myClass {
    public:
    myClass(string nm) { // defined a constructor that takes one parameter and assigns to the nm attribute
        setName(nm);
    }
    void setName(string x) {
        name = x;
    }
    string getName() {
        return name;
    }
    private:
    string name;
};

int main() {
    myClass ob1("david"); // you now need to pass the constructor's parameter
    myClass ob2("amy");
    cout << ob1.getName(); // "david"
}
// possible to have multiple construcros that take different numbers of parameters
```



