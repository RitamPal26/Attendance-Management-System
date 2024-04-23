#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
private:
    string name;
    int id;
    bool present;

public:
    Employee(string name, int id)
    {
        this->name = name;
        this->id = id;
        present = false;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    bool isPresent()
    {
        return present;
    }

    void markPresent()
    {
        present = true;
    }

    void markAbsent()
    {
        present = false;
    }
};

class AttendanceManager
{
private:
    vector<Employee> employees;

public:
    void addEmployee(Employee employee)
    {
        employees.push_back(employee);
    }

    void markAttendance(int id, bool present)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].getId() == id)
            {
                if (present)
                {
                    employees[i].markPresent();
                }
                else
                {
                    employees[i].markAbsent();
                }
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }

    void printAttendance()
    {
        cout << "Attendance Report:" << endl;
        for (int i = 0; i < employees.size(); i++)
        {
            cout << employees[i].getName() << " (ID: " << employees[i].getId() << ") - ";
            if (employees[i].isPresent())
            {
                cout << "Present" << endl;
            }
            else
            {
                cout << "Absent" << endl;
            }
        }
    }
};

int main()
{
    AttendanceManager manager;
    Employee emp1("John Doe", 1001);
    Employee emp2("Jane Smith", 1002);

    manager.addEmployee(emp1);
    manager.addEmployee(emp2);

    manager.markAttendance(1001, true);
    manager.markAttendance(1002, false);
    manager.printAttendance();
    
    return 0;
}