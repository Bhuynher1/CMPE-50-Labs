//
//  administrator.hpp
//  CMPE 50 LAB 9
//
//  Created by Blake Huynh on 12/3/20.
//

#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_

#include <iostream>
#include <stdio.h>
#include "salariedemployee.h"

using namespace std;
namespace employeesavitch
{
class Administrator: public SalariedEmployee
{
public:
    Administrator();
    Administrator(string new_name, string new_ssn, double new_salary);
    
    //member functions
    void set_supervisor(string new_supervisor);
    void read_admin_data();
    void print();
    void print_check();
protected:
    //member variables
    string title;
    string responsibility;
    string supervisor;
    double annual_salary;
};
}

#endif /* administrator_h */
