
//Separate header for base class


#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include<cwchar>
#include<stdlib.h>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

//base class
class Employee
{
    public:
        //construcor
        Employee();

        int choice,back1,no_emp;


        void empdetails();
        void input();
        void Search_emp();
        void employee_menu();
        void go_backemp();
        void remove_emp();
        void update_emp();


        //destructor
        ~Employee();

    protected:
        string emp_id,DOA;
        string sname;
        int age;

    private:


};

//base class Employee
class Admin:public Employee
{
public:

    Admin();



    /*01*/int loging();
    void go_back();
    void change_un();
    void change_pw();
    void admin_menu();
    void main_menu();
    void get_salary_menu();

    ~Admin();

private:
    char passw[10],uname[10],data[10],uname_o[10],data1[10],pass_o[10],data2[10];

};

//base class Employee
class Salary:public Employee
{
    public:
        void salary_menu();
        void salary_details();
        void pay_sheet();
        void get_ps();
        void go_backsal();

    protected:
        float basic,adjustment_allo,C_O_L,insur,loan,net_sal,deduct,earning,ota,ot;
        int year;
        string month;

    private:

};

//base class is Salary
//Hierarchical Inheritance
class Welfare:public Salary
{

public:
    int servicey;
    float welfare_m;
    int reason;

    void requestwelfare();
    void issuewelfare();


};


#endif // EMPLOYEE_H
