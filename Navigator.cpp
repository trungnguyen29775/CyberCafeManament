#include "Navigator.h"

//this Navigator is used to manage the main Menu and another Menu

void login()
{
    cout << "============ LOG IN ============\n\n";
    string username, password;
    bool check = false;
    int index;
    do
    {
        cout << "Enter the admin user name: ";
        cin >> username;
        if (username != AdminUserName) //check the admin username login
            cout << "Incorrect. Please try again!\n";
    } while (username != AdminUserName);
    do
    {
        cout << "Enter the password: ";
        cin >> password;
        if (password != AdminPassword) //check the admin password login
            cout << "Wrong password. Please try again!\n";
    } while (password != AdminPassword);

    cout << "Log in successfully!\n";
    system("pause");
}

void MasterMenu()
{
    string choice;
    MasterEntry* ptr = nullptr; //create an null pointer
    int c;
    do
    {
        system("cls");
        for (auto const& line : lineMasterEntry)
        {
            cout << line << '\n';
        }
        do //use do while to check the user choice
        {
            cout << "Your choice: ";

            cin >> ws;
            getline(cin, choice);
            c = int(choice[0]) - 48;
            if (c < 1 || c>3 || choice.size()!=1)
            {
                cout << "Invalid number!\n";
            }
        } while (c < 1 || c>3 || choice.size()!=1);


        switch (c)
        {
        case 1: //if choice=1 -> Member Entry's Menu
            ptr = new MemberEntry;
            ptr->Menu();
            break;
        case 2: //if choice=2 -> Computer Entry's Menu
            ptr = new ComputerEntry;
            ptr->Menu();
            break;

        default:
            break;
        }
    } while (c != 3);
    delete ptr;

}

void ManageMenu()
{
    //declare the variable of class Booking and class Charde to call and use
    string choice;
    Booking bookin;
    Charge charge;


    int c;
    do
    {
        //clear the screen and draw Menu
        system("cls"); 
        for (auto const& line : lineCafeManagement)
        {
            cout << line << '\n';
        }
        do //use do while to check user's choice
        {
            cout << "Your choice: ";

            cin >> ws;
            getline(cin, choice);
            c = int(choice[0]) - 48;
            if (c < 1 || c>4 || choice.size()!=1)
            {
                cout << "Invalid number!\n";
            }
        } while (c < 1 || c>4 || choice.size()!=1);


        switch (c)
        {
        case 1:
            bookin.menu();
            break;
        case 2:
            charge.menu();
            break;
        case 3:
            //
            break;

        default:
            break; //break when the choice out of Menu
        }
    } while (c != 4);

}

void StartMenu()
{
    string choice;
    int c;
    do
    {
        //clear screen and draw the Menu
        system("cls");
        for (auto const& line : lineMenu)
        {
            cout << line << '\n';
        }
        do
        {
            cout << "Your choice: ";
            cin >> ws;
            getline(cin, choice);
            c = int(choice[0]) - 48;
            if (c < 1 || c>4 || choice.size()!=1)
            {
                cout << "Invalid number!\n";
            }
        } while (c < 1 || c>4 || choice.size()!=1);

        switch (c) //Handle choice
        {
        case 1: //if choice=1 ->Master Menu
            MasterMenu();
            break;
        case 2:
            ManageMenu(); //if choice=2->ManageMenu
            break;

        default:
            break;
        }
    } while (c != 3);
}