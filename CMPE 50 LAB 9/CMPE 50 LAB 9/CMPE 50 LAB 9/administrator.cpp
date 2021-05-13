//
//  administrator.cpp
//  CMPE 50 LAB 9
//
//  Created by Blake Huynh on 12/3/20.
//
#include <iostream>
#include "administrator.h"

using namespace std;

namespace employeesavitch
{
Administrator::Administrator()
    :SalariedEmployee(),
    title("No title yet"),
    responsibility("No responsibility yet"),
    supervisor("No supervisor yet"),
    annual_salary(0)

{
}
Administrator::Administrator(string new_name, string new_ssn, double weekly_salary)
    :SalariedEmployee(new_name, new_ssn, weekly_salary)
{
    read_admin_data();
}

void Administrator::set_supervisor(string new_supervisor) {
    supervisor = new_supervisor;
}

void Administrator::read_admin_data() {
    cout << "Enter the administrator's title: ";
    getline(cin, title);
    
    cout << "Enter the area of responsibility: ";
    getline(cin, responsibility);
    
    cout << "Enter the immediate supervisor: ";
    getline(cin, supervisor);
    
    cout << "Enter the Administrator's annual salary: ";
    string str;
    getline(cin, str);
    annual_salary = stod(str);
}

void Administrator::print() {
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    set_net_pay(salary);
    
    cout << "Details of the object"<< endl;
    cout << "Employee name: " << get_name() << endl;
    cout << "Employee ssn: " << get_ssn() << endl;
    cout << "Employee net pay: " << get_net_pay() << endl;
    cout << "Employee salary: " << salary << endl;
    cout << "Administrator's title: " << title << endl;
    cout << "Area of responsibility: " << responsibility << endl;
    cout << "Immediate supervisor: " << supervisor << endl;
    cout << "Administrator's annual salary: " << annual_salary << endl;
}

void Administrator::print_check() {
    double monthly_pay = annual_salary/12;
    set_net_pay(monthly_pay);
    cout << "\nPay Check " << endl;
    cout << "________________________________________________________\n";
    cout << "Pay to the order of" << get_name() << endl;
    cout << "The sum of " << get_net_pay() << "Dollars\n";
    cout << "________________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Administrative Employee, Title: " << title << endl;
    cout << "Area of responsibility: " << responsibility << endl;
    cout << "________________________________________________________\n";
}
}
