# C++ Module 00 - Getting started with C++

This introductory module focuses on the **basics of C++ syntax and structure**. It’s designed to ease your transition from C to C++, introducing essential object-oriented programming concepts like **classes, member functions, constructors, static members**, and more.

---

## 🧠 What I Learned

* Namespaces and the `std` namespace
* Classes and encapsulation
* Member functions and access specifiers
* Constructors and initialization lists
* Static variables and functions
* Constant members (`const`)
* Standard I/O streams in C++
* Basic string formatting

---

## Exercise 00: Megaphone

**Goal**: Create a simple program that turns all command-line input to **uppercase** and prints it.

### Concepts Practiced

* `argc` and `argv` handling in C++
* Standard input/output using `std::cout`
* Character manipulation using `std::toupper`
* Loops and conditionals
* Fallback/default message when no arguments are given

This exercise is about ensuring you're comfortable writing your first C++ program with clean output and basic argument handling.

---

## Exercise 01: My Awesome PhoneBook

**Goal**: Implement a basic CLI phonebook app that stores and displays up to 8 contacts.

### Concepts Practiced

* **Classes**: You implement two – `PhoneBook` and `Contact`
* **Encapsulation**: Keeping class members private/public as appropriate
* **Static arrays**: No dynamic allocation allowed
* **Input/Output formatting**: `std::setw`, right alignment, string truncation
* String handling with `std::string`
* User interaction via command line
* Basic error handling (e.g. invalid index input)

This exercise simulates your first "real" C++ class-based application with a clear separation of concerns between data (`Contact`) and logic (`PhoneBook`).

---

## Exercise 02: The Job Of Your Dreams

**Goal**: Reconstruct the missing implementation file `Account.cpp` based on a given `Account.hpp` and a log file.

### Concepts Practiced

* Working with **class headers and source files**
* Implementing **constructors**, **destructors**, and **static members**
* Using **initialization lists** in constructors
* Tracking object state with **static counters**
* Organizing methods across `.hpp` and `.cpp` files
* Reproducing output format based on logs
* Reverse-engineering logic from test cases

You simulate a real-world task of rebuilding lost source code based on existing declarations and behavior. A good lesson in reading header files, working with static data, and debugging.
