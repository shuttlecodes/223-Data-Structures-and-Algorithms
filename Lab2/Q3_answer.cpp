#include <iostream>
#include <string>

class Student {
public:
    Student(const std::string& name, int id, int age)
        : name_(name), id_(id), age_(age) {}

    const std::string& get_name() const {
        return name_;
    }

    int get_id() const {
        return id_;
    }

    int get_age() const {
        return age_;
    }

private:
    std::string name_;
    int id_;
    int age_;
};

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    // Dynamically allocate memory for the 2D array of Student pointers
    Student*** students = new Student**[numStudents];
    for (int i = 0; i < numStudents; i++) {
        students[i] = new Student*[3]; // Each row has 3 columns for name, id, and age
    }

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int id, age;

        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::getline(std::cin, name);

        std::cout << "Enter the ID of student " << i + 1 << ": ";
        std::cin >> id;

        std::cout << "Enter the age of student " << i + 1 << ": ";
        std::cin >> age;

        std::cin.ignore(); // Ignore the newline character left in the input buffer

        students[i][0] = new Student(name, id, age);
    }

    std::cout << "Student information:" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        std::cout << "Student " << i+1 << " information : ";
        std::cout << "Name: " << students[i][0]->get_name() << ", ";
        std::cout << "ID: " << students[i][0]->get_id() << ", ";
        std::cout << "Age: " << students[i][0]->get_age() << std::endl;
    }

    // Deallocate the dynamically allocated memory
    for (int i = 0; i < numStudents; i++) {
        delete students[i][0];
        delete[] students[i];
    }
    delete[] students;

    return 0;
}
