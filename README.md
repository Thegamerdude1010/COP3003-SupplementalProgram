# Simple Text-Based RPG
This is a simple text based RPG provided as a supplement to the main project listed below. Its purpose is to demonstrate the various requirements that cannot be demonstrated in the original project.

## Demonstration

## Documentation

## Diagrams
![Class Diagram](docs/ClassDiagramPic.png)

## Getting Started
To run the program, download the .zip file, unzip it, and open the .sln file in Visual Studio. Once it is open, press F5 to run with the debugger or ctrl+F5 to run without the debugger.

## Built With
The app was created using C++ in Visual Studio 2019.

## Author
Jacob Holmes

## License
The code in this project is licensed under the MIT License. [License](LICENSE)

## Acknowledgements
Professor Scott Vanselow.
<br /> https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable

## Comparing the Procedural and Object-Oriented Approaches
Procedural programming uses functions that can be called at any time, which are used to manipulate data called variables. In procedural programming, functions are not easily reused or modified. Object-Oriented programming (OOP) uses classes and objects, which allows the code to be reused or modified without significant effort using inheritance. Inheritance allows subclasses to inherit members and functions of a base class. Since any function can be used to modify data, there is a lack of security when using procedural programming. Procedural programming uses scope to define where data and variables can be used, but there is no way to explicitly protect data from functions. On the other hand, OOP uses encapsulation and access specifiers to control access to data, allowing the programmer to restrict access to data. In OOP, a programmer can restrict access to variables so only the methods of the same class or its subclasses can be used to modify the data. Object-oriented programming allows for polymorphism, where methods can be redefined in subclasses so the programmer does not have to rewrite it in the base class. In procedural programming, functions can only be defined once, which means it must be modified everytime features need to be added. Even though OOP seems to be better, procedural programming is still used in conjuction with OOP.

## Key Programming Concepts Utilized
This program integrates the concepts of object oriented programming, such as inheritance and encapsulation. Inheritance allows the user to reuse code in other places without having to rewrite it.
<br /> Polymorphism and Dynamic dispatch is briefly used to demonstrate the concept. Polymorphism allows programmers to override functions in a base class within a subclass. Dynamic dispatch allows for selecting which version of a method is called at runtime.

## Original Project
The original project is a game created from a tutorial. See details in the repository found here: https://github.com/Thegamerdude1010/RubysAdventure-COP3003Project
