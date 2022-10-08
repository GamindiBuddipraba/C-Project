
/*Employee And Payroll Management System
       Co-op Food City

       Matara 20.1 batch
Team Members :

    W.C.Sudeshinie(DSE-MA-201-F-058)
    A.V.G.Buddhiprabha(DSE-MA-201-F-011)
    Chamath Sandeepa Kankanamge(DSE-MA-201-F-022)
    J.L.Y.Nethmina(DSE-MA-201-F-051)

*/



#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include<cwchar>
#include<stdlib.h>
//created header file
#include "employee.h"


using namespace std;

void welcome()

{
	system("Color 4E");

	time_t now = time(0);
	char* dt = ctime(&now);
	cout<<" ______________________________________________________________________________________________________________________\n";
	cout<<"|______________________________________________________________________________________________________________________|\n";
	cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
	cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
	cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
	cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
	cout<<"|\t\t\t\t\t    W E L C O M E \t\t\t\t\t\t\t\t|"<<endl;

	cout<<R"(
                      ____    ___     ___    ____    _____               _    ____ _ _
                     / ___|  / _ \   / _ \  |  _ \  |  ___|__   ___   __| |  / ___(_) |_ _   _
                    | |     | | | | | | | | | |_) | | |_ / _ \ / _ \ / _` | | |   | | __| | | |
                    | |___  | |_| | | |_| | |  __/  |  _| (_) | (_) | (_| | | |___| | |_| |_| |
                     \____|  \___/   \___/  |_|     |_|  \___/ \___/ \__,_|  \____|_|\__|\__, |
                                                                                          |___/
)";
	cout<<"|\t\t\t\t\t ******************** \t\t\t\t\t\t\t\t|"<<endl;
	cout<<"|\t\t\t\t\t  \"On the Way Home\"\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"|______________________________________________________________________________________________________________________|\n";
    cout<<" \t\t\t\t\t"<<dt;
	cout<<"|______________________________________________________________________________________________________________________|\n";
	cout<<"\t\t\t\t\t Press any key to continue.........";

    getch();
    system("cls");
}


int main()
{
    //this function have not class
    welcome();
    Admin a1;
    //Call functions in The constructor

    return 0;
}
