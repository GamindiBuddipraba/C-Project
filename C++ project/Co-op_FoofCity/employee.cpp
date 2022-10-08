
//Implementation file from header file

#include "employee.h"
#include <iostream>
#include <fstream>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include<cwchar>
#include <stdlib.h>


using namespace std;

Employee::Employee()
{


}

//input Employee details
void Employee::input()
{


  string details[5];

  ofstream myfile ("Employee.txt",ios::app);

  cout<<"\n\n\t\t\t\t--*--Enter Employee Details--*--"<<endl;


  if (myfile.is_open())
  {


      for(int i=1;i<=no_emp;i++)
    {
        cout<< "\t\t\tEnter Employee Id :";
        cin>>details[0];
        cout<< "\t\t\tEnter Employee Name(with initials) :";
        cin>>details[1];
        cout<< "\t\t\tEnter Job Roll:";
        cin>>details[2];
        cout<< "\t\t\tEnter  NIC :";
        cin>>details[3];
        cout<< "\t\t\tEnter Current Resident :";
        cin>>details[4];
        myfile<<details[0]<<" "<<details[1]<<" "<<details[2]<<" "<<details[3]<<" "<<details[4]<<endl;

    }
    myfile.close();

  }
  else cout << "Unable to open file";
}


//For Search Employee Details
void Employee::Search_emp()
 {
	 string line,ID;
	 string details[5];


	 ifstream emplyee("Employee.txt");
	if(!emplyee)
        {
        cout<<"Error opening file. Shutting down...\n";
		exit(EXIT_FAILURE);
        }

    //Employee id(get for temporary)
	cout<<"Please enter Employee ID: ";
	cin>>ID;

	 while (getline(emplyee, line))
    {
        istringstream detail(line);

        //get data from file through the array
        detail>>details[0]>>details[1]>>details[2]>>details[3]>>details[4];
        //details[0] mean by enployee id

        if(details[0] == ID)
        {

            cout<<"\t\tEmployee ID      : "<<details[0]<<endl;
            cout<<"\t\tEmployee Name    : "<<details[1]<<endl;
            cout<<"\t\tJob Roll         : "<<details[2]<<endl;
            cout<<"\t\tNIC              : "<<details[3]<<endl;
            cout<<"\t\tCurrent Resident : "<<details[4]<<endl;

        }


    }

    	emplyee.close();

 }

 //for Delete Employee Details
void Employee::remove_emp()
{
    string line, id;

    cout << "Please Enter the ID of record you want to delete: ";
    cin >> id;

    ifstream myfile;
    myfile.open("Employee.txt");
    ofstream temp;

    //create temporary file as 'temp.txt'
    temp.open("temp.txt");

    while (getline(myfile, line))
    {
        //substr(arg1,arg2) is predefined function. (output new string value)
        if (line.substr(0, id.size()) != id)
        temp << line << endl;
    }

    cout << "\n\n\t\t*The record with the ID " << id << " has been deleted. . .*" << endl;

    myfile.close();
    temp.close();
    remove("Employee.txt");
    rename("temp.txt", "Employee.txt");

        getch();
        system("cls");

    }


//For update Employee Details
void Employee::update_emp()
{
    string line, id;
    no_emp=1;


    cout << "Please Enter the ID of record you want to Update: ";
    cin >> id;

    ifstream myfile;
    myfile.open("Employee.txt");
    ofstream temp;
    temp.open("temp.txt");
        while (getline(myfile, line))
            {
                if (line.substr(0, id.size()) != id)
                temp << line << endl;
            }
    myfile.close();
    temp.close();
    remove("Employee.txt");
    rename("temp.txt", "Employee.txt");


}

//Employee menu
 void Employee::employee_menu()
{
    int option;

     cout<<"\n\n\n\n\n\t\t\t\t***---Employee Details--***"<<endl;
     cout<<"\n\n\t\t\t1.All Employee\n";
     cout<<"\n\n\t\t\t2.Add Employee\n";
     cout<<"\n\n\t\t\t3.Select Employee \n";
     cout<<"\n\n\t\t\t4.Update Employee\n";
     cout<<"\n\n\t\t\t5.Remove Employee";
     cout<<"\n\n\t\t\t6.Exit\n";

     cout<<"\n\n\t\t\t\tEnter option:";
     cin>>option;

     system("cls");

     switch(option)
     {
        case 1:
            {
                empdetails();
                go_backemp();
                break;
            }

        case 2:
            {
                cout<<"\n\n\t\t\tHow many Employees do you want to add?";
                cin>>no_emp;
                input();
                cout<<"\n\t\t\tSuccessfully Added. . ."<<endl;
                go_backemp();
                break;
            }

        case 3:
            {
                Search_emp();
                go_backemp();
                break;
            }
        case 4:
            {
                empdetails();
                update_emp();
                input();
                cout<<"\n\t\t\tSuccessfully Updated. . ."<<endl;
                go_backemp();
                break;
            }
        case 5:
            {
                empdetails();
                remove_emp();
                empdetails();
                go_backemp();
                break;
            }
        case 6:
            {

                 Admin ad;
                ad.main_menu();
                break;
            }

        default:
            {
        cout<<"\t\t\t\t\t Please enter valid inputs"<<endl;
            }


     }
}

//Employee details Display
void Employee::empdetails()
{
    cout<<"\n\n\n\t\t\t\t\t---------Employee Details--------------"<<endl;
    cout<<"\n\t\t\tID       Name         Job_Roll       NIC         Resident"<<endl;

    ifstream infile;
    string data;
    infile.open("Employee.txt");
    while(!infile.eof())
        {
        getline(infile,data);
        cout<<"\n\t\t\t"<<data<<endl;
        }
    infile.close();
}

//back option
void Employee::go_backemp()
{
    cout<<"\n\n\n\t\t\t\t\tPress 0 go back : ";
    cin>>back1;

    switch (back1)
    {
    case 0:
        system("cls");
        employee_menu();
        break;
    default:
        exit(0);

    }
}




//-----------------------------------------------------------------------------------------------

Admin::Admin()
{

   admin_menu();


}

//For logging
int Admin::loging()
{
   int k=0;
   int count1=1;

    do
        {

       string username= "";


    ifstream inputFile("Username.txt");

    if( inputFile.is_open() )
        {
            getline( inputFile, username );

            inputFile.close();
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t---$---System Log---$---\n\n"<<endl ;
            cout << "\t\t\t\t\t\tEnter User name : " ;
            cin >> uname;

            if( uname==username)

            {
                cout << "\n\t\t\t\t\t\tEnter Password :" ;
                while(passw[k-1]!='\r')
                    {
                    passw[k]=_getch();
                    if(passw[k-1]!='\r')
                        {
                        cout<<"*";
                        }
                    k++;
                    }
                passw[k-1]='\0';


               string password= "";


                ifstream inputFile("Password.txt");

                    if( inputFile.is_open() )
                        {
                            getline( inputFile, password );

                            inputFile.close();

                            //cout << "Enter Password :" ;
                            //cin>>passw;
                            //cout << "Password is: " << password << endl;

                            if( passw==password)

                                {
                                cout<<"\n\n\n\n\t\t\t\t\t\tLogging success. . .\n\n\n\n\t\t\t\t\t  ";


                                system("pause");
                                system("cls");
                                main_menu();

                                break;
                                }
                            else
                                {
                                cerr<< "\n\n\n\n\n\t\t\t\t\t\t!!!!Wrong Password!!!!" << endl;
                                getch();
                                system("cls");
                                loging();

                                }
                        }
                else
                {
                   cerr<< "\n\n\n\n\n\t\t\t\t\tProblem in opening the file. . . !";
                   getch();
                   system("cls");
                }
          }

          else
          {
            cerr<< "\n\n\n\n\t\t\t\t\t\t\tTry again";

            cout<<"\n\n\n\t\t\t\t\tPress any key for Try again!"<<endl;
            getch();
            system("cls");
          }


     }
     else
     {
          cerr << "\n\t\t\t\t\tProblem in opening the file" << endl;
          getch();
          system("cls");

     }
     }while(count1<=3);

     return 0;
}

//For Change username
void Admin::change_un()
{


    cout<<"\n\n\n\t\t\t ---Change User Name --- "<<endl;
    cout<<"\n\n\n\t\tEnter your Current user name : ";
    cin>>uname_o;

    fstream ofs;
    string data2 = "";
    ifstream inputFile("Username.txt");
    if( inputFile.is_open() )
        {
        getline( inputFile, data2 );
        inputFile.close();
        if(uname_o==data2)
            {
        ofs.open("Username.txt", ios::out | ios::trunc);
        cout<<"\n\n\n\t\tEnter your new User name : ";
        cin>>data;
        ofs << data << endl;
        ofs.close();
        cout<<"\n\n\n\t\t****Create Successful**** "<<endl;

            }
        else
            {
            cout<<"\n\n\n\n\n\t\t\tWrong User Name"<<endl;
            }
        }
        else
    {
       cout<<"\n\n\n\n\t\t\t\tCan't open file"<<endl;
    }
}


//For Change password
void Admin::change_pw()
{


    cout<<"\n\n\n\t\t\t ---Change Password --- "<<endl;

    cout<<"\n\n\n\t\tEnter your Current Password : ";
    cin>>pass_o;

    fstream ofs;
    string data1 = "";
    ifstream inputFile("Password.txt");
    if( inputFile.is_open() )
        {
        getline( inputFile, data1 );
        inputFile.close();
        if(pass_o==data1)
            {
        ofs.open("Password.txt", ios::out | ios::trunc);
        cout<<"\n\n\t\tEnter Your New Password : ";
        cin>>data;
        ofs << data << endl;
        ofs.close();
        cout<<"\n\n\t\tCreate Successful. . . "<<endl;


            }
        else
            {
            cout<<"\n\n\n\t\t\t***Wrong Password*** "<<endl;
            }
        }
        else
    {
       cout<<"\n\n\n\t\t\t\t***Cant open file***"<<endl;
    }
}

//Admin  menu
void Admin::admin_menu()
{
    cout<< "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcome to Co-oP Food City"<<endl;

    cout<< "\n\n\t\t\t\t\t\t1.Logging";
    cout<< "\n\t\t\t\t\t\t2.Change User name";
    cout<< "\n\t\t\t\t\t\t3.Change Password ";

    cout<< "\n\n\t\t\t\t\tEnter choice : ";
    cin>>choice;

    system("cls");

    switch (choice)
    {
    case 1:
        {
            loging();
            break;
        }
    case 2:
        {
          change_un();
          go_back();
          break;
        }

    case 3:
        {
            change_pw();
            go_back();
            break;
        }
    default:
        cout << "\n\n\n\t\t\t\tWrong Option "<<endl;
    }


}

//For access to get Salary menu from salary class
void Admin::get_salary_menu()
{
    Salary sal;
    sal.salary_menu();
}

//Main menu
void Admin::main_menu()
{
    int option;

    cout<<"\n\n\n\n\n\n\n\n\t\t\t--*--Follow the link below for Informations--*--"<<endl;

    cout<<"\n\n\t\t\t\t1.Employee Details "<<endl;
    cout<<"\n\n\t\t\t\t2.Salary Details "<<endl;

    cout<<"\n\n\t\t\t\tEnter Link Number : ";
    cin>>option;

    system("cls");
    switch(option)
    {
    case 1:
        {
        employee_menu();
        break;
        }
    case 2:
        {
        get_salary_menu();
        }

    default:
        {
            cout<<"Enter valid Inputs "<<endl;
        }

    }
}



//back option
void Admin::go_back()
{
    cout<<"\n\n\n\t\t\t\t\t\tPress 0 go back :";
    cin>>back1;

    switch (back1)
    {
    case 0:
        getch();
        system("cls");
        admin_menu();

        break;
    default:
        exit(0);

    }
}


Admin::~Admin()
{

}

//--------------------------------------------------------------------


//salary menu
void Salary::salary_menu()
{
     int option;

     Welfare wel;

     cout<<"\n\n\n\n\n\t\t\t\t\t---*$*---Salary Section--*$*---"<<endl;
     cout<<"\n\t\t\t\t1.Input Salary Details"<<endl;
     cout<<"\n\t\t\t\t2.Issue Salary Slip"<<endl;
     cout<<"\n\t\t\t\t3.Requesting to join Welfare"<<endl;
     cout<<"\n\t\t\t\t4.Issue Welfare Slip"<<endl;
     cout<<"\n\t\t\t\t5.Exit"<<endl;

     cout<<"\n\n\t\t\t\t  Enter option:";
     cin>>option;

     getch();
     system("cls");


     switch(option)
     {
        case 1:
            {
            salary_details();
            break;
            }

        case 2:
            {
            system ("Color f0");

            get_ps();
            break;
            }

        case 3:
            {
            wel.requestwelfare();
            go_backsal();
                break;
            }
        case 4:
            {
            wel.issuewelfare();
            go_backsal();
                break;
            }
        case 5:
            {
                exit(0);
            }
        default:
            {
                cout<<"Please enter valid Inputs"<<endl;
            }

    }
}


//Salary details
void Salary::salary_details()
{
    //string details[9];

int i;

cout<<"Enter Number of Employees :";
cin>>i;

//file opening in the appending mode
ofstream salfile ("Employee_Salary.txt",ios::app);


if (salfile.is_open())
  {

  for(int k=1;k<=i;k++)
    {
    cout<<"*-----------------------------------------*"<<endl;
    cout<<"*\tABC Book Shop - Matara "<<endl;
    cout<<"\n\tEnter Employee ID : ";
    cin>>emp_id;

    cout<<"\tEnter Month : ";
    cin>>month;
    cout<<"\tEnter Year : ";
    cin>>year;

    cout<<"\tEnter Basic Salary : ";
    cin>>basic;

    cout<<"\tEnter Adjustment Allowance : ";
    cin>>adjustment_allo;

    cout<<"\tEnter Cost Of Living allowance : ";
    cin>>C_O_L;

    cout<<"\tEnter Over Time Hours : ";
    cin>>ot;


    ota=(ot*250.00);

    earning=basic+adjustment_allo+C_O_L+ota;

    cout<<"\tEnter Cost Of Insurance : ";
    cin>>insur;

    cout<<"\tEnter Loan Amount(private) : ";
    cin>>loan;

    deduct=insur+loan;

    net_sal=earning-deduct;


    cout<<"\tNet Salary : "<< net_sal<<endl;

    //store data through the variables
    salfile<<emp_id<<" "<<month<<" "<<year<<" "<<basic<<" "<<adjustment_allo<<" "<<C_O_L<<" "<<ota<<" "<<earning<<" "<<insur<<" "<<loan<<" "<<deduct<<" "<<net_sal<<endl;

    }

    salfile.close();

    }

  else cout << "\n\n\t\tUnable to open file!!!";

    go_backsal();

}

//Pay sheet
void Salary::pay_sheet()
{


    time_t now = time(0);
	char* dt = ctime(&now);
    cout<<"*------------------------------------------------*"<<endl;
    cout<<"*\t   Co-oP Food City - Matara"<<endl;
    cout<<"*\tPay Report - "<<month<<" "<<year<<endl;
    cout<<"\t"<<dt;
    cout<<"\tEmployee ID         : "<<emp_id<<endl;
    cout<<"*------------------------------------------------*"<<endl;
    cout<<" E A R N I N G S "<<endl;
    cout<<"\tBasic Salary             : "<<setw(9)<<fixed<<setprecision(2)<<basic<<endl;
    cout<<"\tAdjustment Allowance     : "<<setw(9)<<fixed<<setprecision(2)<<adjustment_allo<<endl;
    cout<<"\tCost Of Living allowance : "<<setw(9)<<fixed<<setprecision(2)<<C_O_L<<endl;
    cout<<"\tO-t Amount               : "<<setw(9)<<fixed<<setprecision(2)<<ota<<endl;
    cout<<"\tSub Total                : "<<setw(9)<<fixed<<setprecision(2)<<earning<<endl;
    cout<<"*------------------------------------------------*"<<endl;
    cout<<"\tGross pay                : "<<setw(9)<<fixed<<setprecision(2)<<earning<<endl;
    cout<<"*------------------------------------------------*"<<endl;
    cout<<" D E D U C T I O N S "   <<endl;
    cout<<"\tCost Of Insurance        : "<<setw(9)<<fixed<<setprecision(2)<<insur<<endl;
    cout<<"\tLoan Amount(private)     : "<<setw(9)<<fixed<<setprecision(2)<<loan<<endl;
    cout<<"\tTotal Deductions         : "<<setw(9)<<fixed<<setprecision(2)<<deduct<<endl;
    cout<<"*------------------------------------------------*"<<endl;
    cout<<"\tNet Salary               : "<<setw(9)<<fixed<<setprecision(2)<<net_sal<<endl;
    cout<<"*------------------------------------------------*"<<endl;
    cout<<"*\t\tThank You!"<<endl;
    cout<<"*------------------------------------------------*"<<endl;

    system("pause");

    system ("cls");

    salary_menu();



}

//Request Pay sheeet
void Salary::get_ps()
{

    ifstream inputFile("Employee_Salary.txt");
    string line;

     string ID,mon;
     int year1;

	if(!inputFile)

    {
		cout<<"Error opening file. Shutting down...\n";
		exit(EXIT_FAILURE);
	}


    cout<<"\n\n\t\t\t***Employee Salary Section***"<<endl;
	cout<<"\n\n\n\t\t\t\tEnter Employee Id :";
	cin>>ID;

	cout<<"\n\n\n\t\t\t\tEnter Month :";
	cin>>mon;

	cout<<"\n\n\n\t\t\t\tEnter year :";
	cin>>year1;

    system("cls");

    while (getline(inputFile, line))
    {
        istringstream ss(line);


        //get data through the variables for display
        ss >>emp_id>>month>>year>>basic>>adjustment_allo>>C_O_L>>ota>>earning>>insur>>loan>>deduct>>net_sal;

        if(emp_id  == ID && month == mon && year == year1 )
        {
            pay_sheet();

        }


    }
}


//back option for salary
void Salary::go_backsal()
{
    int back1;

    cout<<"\n\n\n\t\t\t\t\t\tPress 0 go back :";
    cin>>back1;

    switch (back1)
    {
    case 0:
        getch();
        system("cls");
        salary_menu();

        break;
    default:
        exit(0);

    }
}

//----------------------------------------------------------------------------------

//for request welfare
void Welfare::requestwelfare()
{


    cout<<"\n\n\n\t\t\t\t\t--Welfare Form-- "<<endl;

    cout<<"\n\n\t\t\t\tEnter Employee ID       : ";
    cin>>emp_id;

    cout<<"\n\n\t\t\t\tEnter Employee age      : ";
    cin>>age;

    cout<<"\n\n\t\t\t\tDate of Arrival at work : ";
    cin>>DOA;

    cout<<"\n\n\t\t\t\tEnter Basic Salary      : ";
    cin>>basic;

    cout<<"\n\n\t\t\t\tEnter Spouse' name      : ";
    cin>>sname;

    ofstream welfile ("Welfare.txt",ios::app);

    if (welfile.is_open())
  {

    welfile<<emp_id<<" "<<age<<" "<<DOA<<" "<<basic<<" "<<sname<<endl;

    cout<<"\n\n\n\t\t\t\t*Successfully Registered*"<<endl;

    welfile.close();


  }
  else cout << "Unable to open file";

}

//For issue welfare
void Welfare::issuewelfare()
{
    cout<<"\n\n\n\t\t\t--Welfare Form-- "<<endl;

    cout<<"\n\n\t\tEnter Employee ID : ";
    cin>>emp_id;

    cout<<"\n\n\t\tEnter Service Year : ";
    cin>>servicey;

    cout<<"\n\n\t\tEnter Basic Salary : ";
    cin>>basic;

    cout<<"\n\n\t\tPlease Enter any key for confirm :  ";
    getch();
    system("cls");

    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t1.Wedding "<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t2.Funeral "<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t3.Special  "<<endl;

    cout<<"\n\n\t\t\t\t\t\tEnter Reason Number : ";
    cin>>reason;


    switch(reason)
    {
    case 1:
        {
            if(servicey>10)
        {
            welfare_m=20000.00;
            cout<<"\n\n\n\t\t\t\t\t\tWelfare Money  : "<<welfare_m<<endl;
        }
        else
        {
            welfare_m=10000.00;
             cout<<"\n\n\n\t\t\t\t\t\tWelfare Money  : "<<welfare_m<<endl;
        }
        break;
        }
    case 2:
        {
            if(servicey>10)
        {
            welfare_m=25000.00;
             cout<<"\n\n\n\t\t\t\t\t\tWelfare Money  : "<<welfare_m<<endl;
        }
        else
        {
            welfare_m=15000.00;
             cout<<"\n\n\n\t\t\t\t\t\tWelfare Money  : "<<welfare_m<<endl;
        }

        break;
        }
    case 3:
        {
            if(servicey>10)
        {
            welfare_m=10000.00;
             cout<<"\n\n\n\t\t\t\t\t\tWelfare Money  : "<<welfare_m<<endl;
        }
        else
        {
            welfare_m=5000.00;
             cout<<"\n\n\n\t\t\t\t\t\tWelfare Money  : "<<welfare_m<<endl;
        }
        break;

        }
    default:
        {
            cout<<"\n\n\n\t\t\\t\t\t\tEnter Valid Inputs "<<endl;
        }
    }

}




//-------------------------------------------------------------------


Employee::~Employee()
{
    //dtor
}
