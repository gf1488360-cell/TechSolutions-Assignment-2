#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    // Declaring Data members
    string name;                
    int id;                   
    double salary;          
    static const string companyName;  
    static int employeeCount;  

public:
    // Constructor with initializer list
    Employee(const string& empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {
        employeeCount++;  
    }

    // Copy constructor (deep copy is automatic with string)
    Employee(const Employee& other)
        : name(other.name), id(other.id), salary(other.salary) {
        employeeCount++;  // Increment count for new employee
    }

    // Destructor
    ~Employee() {
        employeeCount--;  // Decrement count when object is destroyed
    }

    // Const function to display employee data (doesn't modify object)
    void display() const {
        cout << "Company: " << companyName << endl;
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->id << endl;
        cout << "Salary: PKR " << this->salary << endl;
        cout << "------------------------------------" << endl;
    }

    // Static function to show total employees
    static void showTotalEmployees() {
        cout << "Total Employees in " << companyName << ": " << employeeCount << endl;
    }

    // Function to modify name
    void setName(const string& newName) {
        this->name = newName;
    }

    // Getter functions
    string getName() const { return this->name; }
    int getId() const { return this->id; }
    double getSalary() const { return this->salary; }
};

// Initialize static members
const string Employee::companyName = "TechSolutions";
int Employee::employeeCount = 0;

// Function that takes object as argument (by value triggers copy constructor)
void displayEmployeeInfo(Employee emp) {
    cout << "Employee Info (passed by value):" << endl;
    emp.display();
}

// Function that returns an object
Employee createEmployee(const string& name, int id, double salary) {
    Employee newEmp(name, id, salary);
    return newEmp;  // Return object (may use copy constructor)
}

// Function to demonstrate the copy behavior
void demonstrateCopyBehavior() {
    cout << "=== DEMONSTRATING COPY BEHAVIOR ===" << endl;

    // Create original employee
    Employee* emp1 = new Employee("Yousaf Noman", 101, 50000.0);
    cout << "Original Employee:" << endl;
    emp1->display();

    // Create copy using copy constructor
    Employee emp2 = *emp1;  // This uses our copy constructor

    cout << "Copy before modification:" << endl;
    emp2.display();

    // Modify original
    emp1->setName("Yousuf Shujah");

    cout << "After modifying original:" << endl;
    cout << "Original: " << emp1->getName() << endl;
    cout << "Copy: " << emp2.getName() << endl;

    // With proper copy, they should be different
    cout << "With proper copying, the copy remains unchanged!" << endl;

    delete emp1;  // Clean up dynamic memory
}

int main() {
    cout << "=== TECH SOLUTIONS EMPLOYEE MANAGEMENT SYSTEM ===" << endl << endl;

    // Demonstrate static member and function
    Employee::showTotalEmployees();
    cout << endl;

    // Create regular objects
    Employee emp1("Ahmad Ali", 1001, 75000.0);
    Employee emp2("Saqlain Haider", 1002, 95000.0);

    cout << "Regular Objects Created:" << endl;
    emp1.display();
    emp2.display();

    Employee::showTotalEmployees();
    cout << endl;

    // Dynamic object allocation using pointers
    cout << "=== DYNAMIC OBJECT ALLOCATION ===" << endl;
    Employee* dynamicEmp = new Employee("Awais Badar", 1003, 80000.0);
    dynamicEmp->display();
    Employee::showTotalEmployees();
    cout << endl;

    // Passing object as function argument
    cout << "=== PASSING OBJECT TO FUNCTION ===" << endl;
    displayEmployeeInfo(emp1);
    cout << endl;

    // Returning object from function
    cout << "=== RETURNING OBJECT FROM FUNCTION ===" << endl;
    Employee returnedEmp = createEmployee("Shayan Ahmad", 1004, 90000.0);
    returnedEmp.display();
    Employee::showTotalEmployees();
    cout << endl;

    // Demonstrate copy behavior
    demonstrateCopyBehavior();
    cout << endl;

    // Clean up dynamic memory
    delete dynamicEmp;

    cout << "Final Employee Count: ";
    Employee::showTotalEmployees();
    cout << "\n------------------------------------" << endl;

    return 0;
}
