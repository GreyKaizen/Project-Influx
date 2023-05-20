# Buying and Selling Terminal Application

This is a C++ project that uses Object-Oriented Programming (OOP) to create a terminal-based application for buying and selling products. The application stores all data in text files and uses file handling to read and write data to these files. The main classes used in the project are Buyer, Seller, Product, Inventory, Person, Admin, Guest, Session.

## Project Overview

The project has the following functionalities:

- Users can create accounts as either buyers or sellers.
- Buyers can browse available products and purchase them.
- Sellers can add new products, update existing products, and view their sales.
- An inventory class keeps track of all available products.
- Admins can view all users, products, and sales.
- Guests can browse products but cannot make purchases or add new products.
- User sessions are managed so that users can log in and out.

## Object-Oriented Design

The project uses OOP concepts effectively to create an organized and modular codebase. Here are some examples of how OOP concepts are used:

- Inheritance: The Buyer, Seller, Admin, and Guest classes all inherit from the Person class, which contains common attributes like name and email.
- Polymorphism: The Session class is polymorphic, meaning it can hold either a Buyer,Seller, or Guest object, depending on the current user's status.
- Encapsulation: Each class has its own set of private and public members, which are encapsulated within the class to prevent outside access and ensure data integrity.
- Abstraction: The Product class is an example of abstraction, as it represents a real-world object (a product) and abstracts away its implementation details from the rest of the program.

## File Handling

The project effectively uses file handling to read and write data to text files. Each user, product, and sale is stored in a separate text file, and the program reads and writes to these files as needed. This allows the program to persist data between sessions and ensures that data is not lost if the program crashes.

## Getting Started

To compile the project, run the following command in the terminal:
`g++ -c .\FriendFunction.cpp .\Session.cpp .\Person.cpp .\Admin.cpp .\Guest.cpp .\Seller.cpp .\Buyer.cpp .\Inventory.cpp .\Product.cpp .\main.cpp`

To create the executable file, run the following command:
`g++ .\FriendFunction.o .\Session.o .\Person.o .\Admin.o .\Guest.o .\Seller.o .\Buyer.o .\Inventory.o .\Product.o .\main.o -o main`

To run the program, use the following command:
`.\main.exe .\main.out`

Make sure to replace `main` with the name of your executable file if you have named it differently. Also, note that the `.out` file extension is not necessary for the `.\main.exe` command.

## License

This project is licensed under the GPL3.0 License. See the [LICENSE](LICENSE) file for details.

## Conclusion

This project is an excellent example of how OOP concepts and file handling can be used to create a well-organized and modular codebase. With its extensive set of features, this application can be extended to support additional functionality or adapted to fit specific use cases.
