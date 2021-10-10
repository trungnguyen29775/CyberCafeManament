//this file is used for declaring class Booking

#include "Booking.h"
#include "MemberEntry.h"

vector <Booking> BOOKING_DATA;


Booking::Booking()
{
    memId = "";
    compId = "";
    timerIn.tm_hour = 0;
    timerIn.tm_min = 0;
    timerIn.tm_sec = 0;
    timerIn.tm_year = 0;
    timerIn.tm_mon = 0;
    timerIn.tm_mday = 1;
    timerOut.tm_hour = 0;
    timerOut.tm_min = 0;
    timerOut.tm_sec = 0;
    timerOut.tm_year = 0;
    timerOut.tm_mon = 0;
    timerOut.tm_mday = 1;

}



void Booking::nonMemberLogin()
{
    system("cls");
    cout << "=======NON MEMBER LOGIN=======\n";

    cout << "You are Logging in as a non member so" << endl;
    cout << "1- Give us your required information (so that we can add you into member list )" << endl;
    cout << "2- Set your user name and password" << endl;
    cout << "3- Then enter your user name and password to login" << endl;
    system("pause");

   

    MemberEntry memb;
    memb.AddNewMember();//call the function for adding new member

    cout << "Now you can login.\n";
    memberLogin();//this void use for logging in of a user
}


int Booking::checkUsedComp(string str)// check the id computer whether of its exist or was used by other user
{
    int ret = -1;
    int i = 0;
    for (auto& element : BOOKING_DATA)
    {
        if (element.compId == str)
        {
            int ret = i;
            return ret; //if found, return the position
        }
        i++;
    }
    return ret;
}

int Booking::checkLoginMem(string str)//check whether the user logged in
{
    int ret = -1;
    int i = 0;
    for (auto& element : BOOKING_DATA)
    {
        if (element.memId == str)
        {
            int ret = i;//if found the user logged in, return position
            return ret;
        }
        i++;
    }
    return ret;
}

void Booking::outp(Booking& bookin, ofstream& file)//output in to file to update the changes
{

    file << bookin.memId << std::endl;
    file << bookin.compId << std::endl;
    file << bookin.timerIn.tm_hour << std::endl;
    file << bookin.timerIn.tm_min << std::endl;
    file << bookin.timerIn.tm_sec << std::endl;
    file << bookin.timerIn.tm_year << std::endl;
    file << bookin.timerIn.tm_mon << std::endl;
    file << bookin.timerIn.tm_mday << std::endl;
    file << bookin.timerOut.tm_hour << std::endl;
    file << bookin.timerOut.tm_min << std::endl;
    file << bookin.timerOut.tm_sec << std::endl;
    file << bookin.timerOut.tm_year << std::endl;
    file << bookin.timerOut.tm_mon << std::endl;
    file << bookin.timerOut.tm_mday << std::endl;


}

double Booking::computeTime(Booking& bookin) //calculate the time loggin and out
{
    return difftime(mktime(&bookin.timerOut), mktime(&bookin.timerIn));
}

void Booking::verify(int& index)//check the username and password when logging in
{
    string username, password;
    bool check = false; //create check to check the username and password
    do
    {
        cout << "\nEnter the user name: ";
        cin >> username;
        index = 0;
        for (auto const& element : MEMBER_DATA)
        {
            if (element.getUser() == username)
                //if the username have been store in vector then check=true
            {
                check = true;
                break;
            }
            index++;
        }
        if (!check)
        {
            cout << "This user does not exist! Retry.\n";
        }
    } while (!check); //repeat until the input equal to the username

    check = false;
    do
    {
        cout << "Enter the password: ";
        cin >> password;
        password = md5(password);
        //compare password to the md5 password in file data 

        if (password != MEMBER_DATA[index].getPass())
        {
            cout << "The password is incorrect.\n";
        }
    } while (password != MEMBER_DATA[index].getPass());
    //repeat until password of username is the same
}
void Booking::login()
{
    int index;
    //create index to flag the data position
    verify(index);//call the loggin function

    memId = MEMBER_DATA[index].getId();

    if (checkLoginMem(memId) >= 0)
    //check whether the used have been logged in
    {
        cout << "This member is already logged in.\n";
    }
    else //else, allow the user loggin and update file loggin data
    {
        time_t rawtime;
        time(&rawtime);
        timerIn = *localtime(&rawtime);
        timerOut = timerIn;

        BOOKING_DATA.push_back(*this);

        std::ofstream fileOutput(BOOKING_FILE_PATH, std::ios::app);

        if (fileOutput.fail())
        {
            std::cout << "Cannot open file at " << BOOKING_FILE_PATH << std::endl;
            return;
        }
        else
        {
            outp(*this, fileOutput);

        }


        fileOutput.close();

        cout << "Log in successfully!\n";
    }


    system("pause");
}

void Booking::memberLogin()
{
    system("cls");

    ComputerEntry comp;

    cout << "=========MEMBER LOGIN=========\n";
    cout << "Enter the unique code of computer to search: ";
    cin >> compId;
    int index = comp.CheckId(compId);//search the id of computer in vector
    if (index < 0)//if does not exist
    {
        cout << "This computer does not exist!\n";
        system("pause");

    }
    else
    {
        int usedIndex = checkUsedComp(compId);
        if (usedIndex >= 0 && computeTime(BOOKING_DATA.at(usedIndex)) <= 0)
        //check is there any user already logged in this computer
        {
            cout << "This computer is already in use.\n";
            system("pause");

        }
        else
        {
            cout << COMP_DATA.at(index);
            cout << "\nThe computer you want is found!\n";

            login();//allow user to loggin
        }

    }
}

void Booking::logout()
{
    system("cls");
    cout << "=========== LOGOUT ===========\n";
    int index;
    verify(index);
    //input username and password to logout, then save the position data in index

    bool check = false;
    int i = 0;
    for (auto& element : BOOKING_DATA)
    {
        if (element.getMemId() == MEMBER_DATA[index].getId())
        //check whether the user has logged in
        {
            check = true;
            break;
        }
        i++;
    }

    if (check) //if the user already logged in and want to loggout
    {
        time_t rawtime;
        time(&rawtime);
        BOOKING_DATA[i].timerOut = *localtime(&rawtime);

        std::ofstream fileOutput(BOOKING_FILE_PATH);
        if (fileOutput.fail())
        {
            std::cout << "Cannot open file at " << BOOKING_FILE_PATH << std::endl;
            return;
        }
        else
        {
            fileOutput.clear();
            for (auto& element : BOOKING_DATA)
                outp(element, fileOutput);
        }
        fileOutput.close();

        cout << "\nLogout successfully!\n";
    }
    else //else
    {
        cout << "\nThis member is not logged in.\n";
    }

    system("pause");

}

void Booking::menu() //void menu to solve the Booking's Menu
{
    string choice;
    choice[0] = 0;
    int c = int(choice[0]) - 48;
    do
    {
        system("cls");
        for (auto const& line : lineBooking)//draw the Booking's Menu
        {
            cout << line << '\n';
        }
        do //use do while to check the input choice
        {
            cout << "Your choice: ";
            cin >> ws;
            getline(cin, choice);
            c = int(choice[0]) - 48;
            if (c < 1 || c>4)
            {
                cout << "Invalid number!\n";
            }
        } while (c < 1 || c>4);


        switch (c)
        {
        case 1:
            memberLogin();
            break;
        case 2:
            nonMemberLogin();
            break;
        case 3:
            logout();
            break;
        default:
            break;
        }
    } while (c != 4);
}