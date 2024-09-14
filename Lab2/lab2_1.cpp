/*In the given code snippet, there is an error that prevents the program from compiling
successfully. 
    Identify the error 
    Provide the correction required to print the name of the student using the get_name() member function. 
    
    Additionally, assume there is a Student class with a constructor 
        that takes a std::string parameter for the name 
        and a get_name() member function
        that returns the name as a std::string. 
    
    Write a complete program that includes the necessary
        headers, 
        main() function, 
        Student class definition, 
        and any other required code to demonstrate the corrected code. 
    
    Please provide the corrected code snippet below.
        Student* student1 = new Student(name);
        cout << *student1.get_name();
*/

#include <iostream>

class Student {
public:
    Student(const std::string& name) : name_(name) {}

    const std::string& get_name() const {
        return name_;
    }

private:
    std::string name_;
};

typedef Student* studentPtr; //previously wasn't here

int main() {
    std::string name = "John Doe";

    // previously: 
    // Student* student1 = new Student(name);
    // std::cout << *student1.get_name() << std::endl;
    studentPtr student1 = new Student(name);
    std::cout << student1->get_name() << std::endl;

    delete student1; // Deallocate the dynamically allocated memory

    return 0;
}

