#include <iostream>
#include <string>
using namespace std;


class Product {
private:
    int productID;
    string name;
    float price;
    string category;
public:
    Product() : productID(0), name("Unknown"), price(0.0f), category("Uncategorized") {}
    Product(int id, string n, float p, string c) : productID(id), name(n), price(p), category(c) {}
    void inputProduct() {
        cout << "Enter Product ID: "; cin >> productID;
        cout << "Enter Product Name (no spaces): "; cin >> name;
        cout << "Enter Price: "; cin >> price;
        cout << "Enter Category: "; cin >> category;
    }
    void displayProduct() {
        cout << "\nProduct ID: " << productID
             << "\nName: " << name
             << "\nPrice: $" << price
             << "\nCategory: " << category;
        if (price > 1000) cout << "\nNote: This product is expensive!";
        cout << endl;
    }
};


class Business {
private:
    string name;
    double profit;
    int employees;
public:
    Business() : name(""), profit(0.0), employees(0) {}
    Business(string n, double p, int e) : name(n), profit(p), employees(e) {}
    void input() {
        cout << "Enter Business Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Profit ($): "; cin >> profit;
        cout << "Enter Number of Employees: "; cin >> employees;
    }
    void display() {
        cout << "\nBusiness Name: " << name
             << "\nProfit: $" << profit
             << "\nEmployees: " << employees << endl;
    }
    void operator++() { employees++; }
    void operator-() { profit = -profit; }
    Business operator+(const Business &obj) {
        Business temp;
        temp.name = name + " & " + obj.name;
        temp.profit = profit + obj.profit;
        temp.employees = employees + obj.employees;
        return temp;
    }
};


void printInvoice(string title = "Receipt", double amount = 0.0) {
    cout << "\n" << title << endl;
    cout << "Total Amount: $" << amount << endl << endl;
}


class EmployeeBase {
protected:
    string name;
    int empID;
    double salary;
    static int employeeCount;
    static int nextID;

public:
    EmployeeBase() : name(""), empID(++nextID), salary(0.0) { employeeCount++; }
    EmployeeBase(string n, double s) : name(n), empID(++nextID), salary(s) { employeeCount++; }
    void display() {
        cout << "Employee ID: " << empID << ", Name: " << name << ", Salary: $" << salary << endl;
    }
    static int getEmployeeCount() { return employeeCount; }
    static double calculateBonus(double baseSalary) {
        double bonus = 0;
        if (baseSalary < 40000)
            bonus = baseSalary * 0.05;
        else if (baseSalary <= 60000)
            bonus = baseSalary * 0.10;
        else
            bonus = baseSalary * 0.15;
        return bonus;
    }
};

int EmployeeBase::employeeCount = 0; 
int EmployeeBase::nextID = 0;        


class ManagerFriend {
private:
    string name;
    double salary;
public:
    ManagerFriend(string n, double s) : name(n), salary(s) {}
    friend void showManagerBonus(ManagerFriend);
};
void showManagerBonus(ManagerFriend m) {
    double bonus = m.salary * 0.10;
    cout << "Manager Name: " << m.name << endl;
    cout << "Salary: $" << m.salary << endl;
    cout << "Bonus: $" << bonus << endl;
}


class A {
public:
    int x;
    void getx() { cout << "Enter value of x: "; cin >> x; }
};
class B : public A {
public:
    int y;
    void gety() { cout << "Enter value of y: "; cin >> y; }
};
class C : public B {
public:
    void sum() { cout << "Sum = " << x + y << endl; }
};


void displayEmployee(string name, string role, double salary) {
    cout << "\n Full Employee Details \n"
         << "Name   : " << name << endl
         << "Role   : " << role << endl
         << "Salary : $" << salary << endl;
    if (salary >= 60000)
        cout << "Level  : Executive\n";
    else if (salary >= 40000)
        cout << "Level  : Senior\n";
    else
        cout << "Level  : Junior\n";
}
void displayEmployee(string name, double salary = 30000) {
    cout << "\n Basic Employee Info \n"
         << "Name   : " << name << endl
         << "Salary : $" << salary << endl;
    if (salary > 35000)
        cout << "Note   : Above average salary\n";
    else
        cout << "Note   : Standard salary\n";
}


class Company {
protected:
    string companyName;
public:
    void setCompany(string cname) { companyName = cname; }
    void displayCompany() { cout << "Company: " << companyName << endl; }
};
class Employee : virtual public Company {
protected:
    int empID;
    string name;
public:
    void setEmployeeDetails(int id, string n) { empID = id; name = n; }
    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Name: " << name << endl;
    }
};
class Department : virtual public Company {
protected:
    string deptName;
public:
    void setDepartment(string d) { deptName = d; }
    void displayDepartment() { cout << "Department: " << deptName << endl; }
};
class Manager : public Employee, public Department {
    string project;
public:
    void setProject(string p) { project = p; }
    void displayManager() {
        cout << "\n--- Manager Details ---\n";
        displayCompany();
        displayEmployee();
        displayDepartment();
        cout << "Project: " << project << endl;
    }
};

int main() {
    int choice;
    do {
        cout << "\n===== Business Management Menu =====\n";
        cout << "1. Product Operations\n";
        cout << "2. Business Operations\n";
        cout << "3. Print Invoice\n";
        cout << "4. EmployeeBase Operations & Bonus\n";
        cout << "5. Show Manager (Friend Function)\n";
        cout << "6. Multiple Inheritance Sum (C:A,B)\n";
        cout << "7. Overloaded Employee Display\n";
        cout << "8. Company Structure (Virtual Inheritance)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Product p1;
            cout << "\nInput new product:\n";
            p1.inputProduct();
            Product p2(101, "Smartphone", 699.99f, "Electronics");
            Product p3(102, "Laptop", 1200.50f, "Electronics");
            cout << "\nEntered Product:";
            p1.displayProduct();
            cout << "\nPredefined Products:";
            p2.displayProduct();
            p3.displayProduct();
            break;
        }
        case 2: {
            Business b1, b2, merged;
            cout << "\nEnter details of First Business:\n"; b1.input();
            cout << "\nEnter details of Second Business:\n"; b2.input();
            cout << "\n--- First Business ---"; b1.display();
            cout << "\n--- Second Business ---"; b2.display();
            merged = b1 + b2;
            cout << "\n--- After Merging ---"; merged.display();
            ++b1;
            cout << "\nAfter Hiring (++):"; b1.display();
            -b1;
            cout << "\nAfter Market Crash (-):"; b1.display();
            break;
        }
        case 3: {
            double total = 999.99;
            printInvoice();
            printInvoice("Invoice");
            printInvoice("Final Bill", total);
            break;
        }
        case 4: {
            EmployeeBase e1("ram", 35000);
            EmployeeBase e2("riya", 55000);
            EmployeeBase e3("Charlie", 80000);
            e1.display(); e2.display(); e3.display();
            cout << "\nTotal Employees: " << EmployeeBase::getEmployeeCount() << endl;
            cout << "Bonus for $35000 salary: $" << EmployeeBase::calculateBonus(35000) << endl;
            cout << "Bonus for $55000 salary: $" << EmployeeBase::calculateBonus(55000) << endl;
            cout << "Bonus for $80000 salary: $" << EmployeeBase::calculateBonus(80000) << endl;
            break;
        }
        case 5: {
            ManagerFriend m1("Alice", 75000);
            showManagerBonus(m1);
            break;
        }
        case 6: {
            C obj1;
            obj1.getx();
            obj1.gety();
            obj1.sum();
            break;
        }
        case 7: {
            displayEmployee("Alice");
            displayEmployee("Bob", 45000);
            displayEmployee("Charlie", "Manager", 75000);
            break;
        }
        case 8: {
            Manager m1;
            m1.setCompany("TechVision Pvt. Ltd.");
            m1.setEmployeeDetails(101, "Rahul Sharma");
            m1.setDepartment("Business Development");
            m1.setProject("Market Expansion");
            m1.displayManager();
            break;
        }
        case 9:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);
    return 0;
}


