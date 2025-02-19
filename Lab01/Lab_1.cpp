/*Lab 01 Employee Database. Initial Assumption that there will only be
10 employee entries in the database. */

#include <iostream>
#include <string>
using namespace std;

// Employee Class Declaration
class Employee
{
private:
    string name;        // Employee's name
    int idNumber;       // ID number
    string department;  // Department name
    string position;    // Employee's position

public:
    // Constructors
    Employee(string, int, string, string);
    Employee();

    // update methods
    void setName(string n)
    {
        name = n;
    }

    void setIdNumber(int i)
    {
        idNumber = i;
    }

    void setDepartment(string d)
    {
        department = d;
    }

    void setPosition(string p)
    {
        position = p;
    }

    // Accessors
    string getName()
    {
        return name;
    }

    int getIdNumber()
    {
        return idNumber;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }

};

// Constructor #1
Employee::Employee(string n, int i, string d, string p)
{
    name = n;
    idNumber = i;
    department = d;
    position = p;
}

// Constructor #2, default constructor
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}


// Functions
void displayEmployee(Employee);
void displayMenu();
int accessEmployee(int i);
void newEmployee(Employee employees[]);
void deleteEmployee(Employee employees[]);

// Driver program to demonstrate the class
int main()
{
    int accessEmployeeInput;
    
    // Create an Employee object based on the current constructor.
    Employee Albert("Albert Smith", 1, "Executive", "President");
    Employee employees[10];

    //Set Albert obj to index 0, based on employee ID - 1. 
    employees[accessEmployee(Albert.getIdNumber())] = Albert;
    
    //Display Menu and get user choice
    while (true)
    {
        displayMenu();
        int userChoice;

        //User input validation
        while (true)
        {
            cout << "Enter Choice: ";
            cin >> userChoice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid Input. Please enter a valid number. (e.g. 1, 2, 3, 9)." << endl << endl;
                continue;
            }

            
            if (userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 9)
            {
                break;
            }
            else
            {
                cout << "Invalid Number. Please try again. (e.g. 1, 2, 3, 9)." << endl << endl;
            }
        }

        //Access Employee Information
        if (userChoice == 1)
        {
            //validation to check if there are any employees in database
            bool hasEmployee = false;
            for (int i = 0; i < 10; i++)
            {
                if (employees[i].getIdNumber() != 0)
                {
                    hasEmployee = true;
                    break;
                }
            }

            if (!hasEmployee)
            {
                cout << "No Employee exists in the database. Please add a new Employee." << endl << endl;
            }

            // Employee ID validation
            while (hasEmployee) 
            {
                cout << "Enter Employee ID: ";
                cin >> accessEmployeeInput;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid Input. Please enter a valid number. (e.g. 1 - 10)." << endl << endl;
                    continue;
                }

                if (accessEmployeeInput == employees[accessEmployee(accessEmployeeInput)].getIdNumber())
                {
                    displayEmployee(employees[accessEmployee(accessEmployeeInput)]);
                    break;
                }
                else
                {
                    cout << "Employee Does Not Exist. Please enter a valid ID. (e.g. 1 - 10) " << endl << endl;
                }
            }  
        }

        //Add new Employee
        else if (userChoice == 2)
        {
            newEmployee(employees);
        }

        //Delete Existing Employee
        else if (userChoice == 3)
        {
            deleteEmployee(employees);
        }

        //Exit program
        else if (userChoice == 9)
        {
            cout << "Now Exiting" << endl;
            break;
        }
    }

    return 0;
}

//**************************************************
// The displayEmployee function displays the data  *
// in the Employee object passed as an argument.   *
//**************************************************

void displayEmployee(Employee e)
{
    cout << "--------------------------------------------" << endl;
    cout << "     Name: " << e.getName() << endl;
    cout << "     ID Number: " << e.getIdNumber() << endl;
    cout << "     Department: " << e.getDepartment() << endl;
    cout << "     Position: " << e.getPosition() << endl;
    cout << "--------------------------------------------" << endl;
}

//******************************************************
// The displayMenu function displays the menu of       *
// items a user can choose to view/add/delete employee *
//******************************************************

void displayMenu() 
{
    cout << "   -----------------------------------------" << endl;
    cout << "   |             Main Menu                 |" << endl;
    cout << "   |  Enter 1 to Access Employee Record    |" << endl;
    cout << "   |  Enter 2 to Add a New Employee        |" << endl;
    cout << "   |  Enter 3 to Delete an Employee        |" << endl;
    cout << "   |  Enter 9 to Exit                      |" << endl;
    cout << "   -----------------------------------------" << endl;
    cout << endl;
}

//******************************************************
// The accessEmployee function takes integer i and     *
// returns i - 1 for indexing purposes                 *
//******************************************************

int accessEmployee(int i) 
{
    return i - 1;
}

//***********************************************************
// The newEmployee function takes array of objects in order *
// to create a new object employee to add to the array      *
//***********************************************************

void newEmployee(Employee employees[])
{
    //initialize variables
    string name;
    int ID;
    string department;
    string position;

    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, name);
    
    //Employee ID validation and checks if an employee exists
    while (true)
    {
        cout << "Enter Employee ID(e.g. 1 - 10): ";
        cin >> ID;
        if (cin.fail() || ID > 10)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Input. Please enter a valid number. (e.g. 1 - 10)." << endl << endl;
            continue;
        }

        if (ID == employees[accessEmployee(ID)].getIdNumber())
        {
            cout << "Employee ID already exists, enter new Employee ID. " << endl << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    cin.ignore();
    cout << "Enter Employee Department: ";
    getline(cin, department);
    cout << "Enter Employee Position: ";
    getline(cin, position); 

    Employee newEmp(name, ID, department, position);
    employees[accessEmployee(ID)] = newEmp;

    cout << endl << endl;
}

//*************************************************************
// The deleteEmployee function takes array of objects in      *
// order to delete an existing employee object from the array *
//*************************************************************

void deleteEmployee(Employee employees[])
{
    //Employee ID validation
    while (true) 
    {
        cout << "Enter ID number of Employee to delete: ";
        int i;
        cin >> i;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Input. Please enter a valid number. (e.g. 1 - 10)." << endl << endl;
            continue;
        }

        if (i != employees[accessEmployee(i)].getIdNumber())
        {
            cout << "No Employee to delete, enter a valid Employee ID. " << endl << endl;
            continue;
        }
        else
        {
            //storing employee name and ID for letting user know who was deleted
            string name = employees[accessEmployee(i)].getName();
            int ID = employees[accessEmployee(i)].getIdNumber();

            //Resets object at index i to default values
            employees[accessEmployee(i)].setName("");
            employees[accessEmployee(i)].setIdNumber(0);
            employees[accessEmployee(i)].setDepartment("");
            employees[accessEmployee(i)].setPosition("");

            cout << "Employee " << name << " with Employee ID: " << ID << " has been deleted" << endl << endl;
            break;
        }
    }
}