#include"MemberEntry.h"

vector<MemberEntry>MEMBER_DATA;

MemberEntry::MemberEntry()
{
    id = "";
    name = "";
    address = "";
    phone = "";
    email = "";
    username = "";
    password = "";
}

void MemberEntry::outp(MemberEntry& member, ofstream& file)
{

    file << member.id << std::endl;
    file << member.name << std::endl;
    file << member.address << std::endl;
    file << member.phone << std::endl;
    file << member.email << std::endl;
    file << member.username << std::endl;
    file << member.password << std::endl;

}


void MemberEntry::AddNewMember()
{
    system("cls");
    cout << "=====ENTER NEW MEMBER DATA=====\n";
    do
    {
        cout << "Enter ID of member: ";
        cin >> id;
        if (CheckId(id) >= 0)
        {
            cout << "This ID already exist. Try another one!\n";
        }
    } while (CheckId(id) >= 0);
    cout << "Enter name of member: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter email of member: ";
    cin >> email;
    cout << "Enter address of member: ";
    cin >> ws;
    getline(cin, address);
    cout << "Enter phone of member: ";
    cin >> phone;
    do {
        cout << "Enter username of member: ";
        cin >> ws;
        getline(cin, username);
        if (username == AdminUserName)
        {
            cout << "You cant add username as admin. Try again.\n";
        }
    } while (username == AdminUserName);
    cout << "Enter password of member: ";
    cin >> password;
    password = md5(password);

    MEMBER_DATA.push_back(*this);

    std::ofstream fileOutput(MEMBER_FILE_PATH, std::ios::app);

    if (fileOutput.fail())
    {
        std::cout << "Cannot open file at " << MEMBER_FILE_PATH << std::endl;
        return;
    }
    else
    {
        outp(*this, fileOutput);

    }


    fileOutput.close();
    cout << "The data has been stored.\n";
    system("pause");


}
void MemberEntry::DeleteRecord()
{
    system("cls");
    cout << "======DELETE MEMBER DATA======\n";
    cout << "Enter member id to delete: ";
    cin >> id;
    const int index = CheckId(id);
    if (index < 0)
    {
        cout << "This ID does not exist!\n";
    }
    else
    {
        cout << MEMBER_DATA.at(index) << '\n';
        cout << "==>Do you want to delete this member? (Y/N)" << endl;
        string yn;
        cin >> ws;
        getline(cin, yn);
        while (yn != "Y" && yn != "y" && yn != "N" && yn != "n")
        {
            cout << "You can type only Y/y(Yes) or N/n(No)." << endl;
            cout << "Please type again." << endl;
            cin >> ws;
            getline(cin, yn);
        }
        if (yn == "Y" || yn == "y")
        {
            MEMBER_DATA.erase(MEMBER_DATA.begin() + index);
            MEMBER_DATA.shrink_to_fit();
            std::ofstream fileOutput(MEMBER_FILE_PATH);
            if (fileOutput.fail())
            {
                std::cout << "Cannot open file at " << MEMBER_FILE_PATH << std::endl;
                return;
            }
            else
            {
                fileOutput.clear();
                for (auto element : MEMBER_DATA)
                    outp(element, fileOutput);
                cout << "This record has been deleted.\n";

            }
            fileOutput.close();
        }
        else
            cout << "This record has not been deleted.\n";
    }
    system("pause");

}

int MemberEntry::CheckId(string str)
{
    int ret = -1;
    int i = 0;
    for (const auto& element : MEMBER_DATA)
    {
        if (element.id == str)
        {
            int ret = i;
            return ret;
        }
        i++;
    }
    return ret;
}

ostream& operator<<(ostream& os, MemberEntry& member) {
    os << "\nID: " << member.id;
    os << "\nName: " << member.name;
    os << "\nAddress: " << member.address;
    os << "\nPhone: " << member.phone;
    os << "\nEmail: " << member.email;
    os << "\nUsername: " << member.username << '\n';
    return os;
}

void MemberEntry::SearchRecord()
{
    system("cls");
    cout << "======SEARCH MEMBER DATA======\n";
    cout << "Enter ID to search: ";
    cin >> id;
    int index = CheckId(id);
    if (index < 0)
    {
        cout << "This ID does not exist!\n";
    }
    else
    {
        cout << "--------SEARCHED MEMBER--------";
        cout << MEMBER_DATA.at(index);
    }
    system("pause");

}

void MemberEntry::ShowMember()
{
    system("cls");
    cout << "=========SHOW MEMBER=========" << endl;
    for (int i = 0; i < MEMBER_DATA.size(); i++)
        cout << MEMBER_DATA[i];
    system("pause");
}

void MemberEntry::UpdateRecord()
{
    system("cls");
    cout << "=======UPDATE MEMBER DATA=======" << endl;
    cout << "Enter member id to update: ";
    cin >> id;
    const int index = CheckId(id);
    if (index < 0)
    {
        cout << "This ID does not exist!\n";
    }
    else
    {
        cout << MEMBER_DATA.at(index) << '\n';
        cout << "==>Do you want to update this member? (Y/N)" << endl;
        cin >> ws;
        string yn;
        getline(cin, yn);
        while (yn != "Y" && yn != "y" && yn != "N" && yn != "n")
        {
            cout << "You can type only Y/y(Yes) or N/n(No)." << endl;
            cout << "Please type again." << endl;
            cin >> ws;
            getline(cin, yn);
        }
        if (yn == "Y" || yn == "y")
        {
            do
            {
                cout << "Enter ID of member: ";
                cin >> id;
                if (CheckId(id) >= 0 && CheckId(id) != index)
                {
                    cout << "This ID already exist. Try another one!\n";
                }
            } while (CheckId(id) >= 0 && CheckId(id) != index);
            cout << "Enter name of member: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter email of member: ";
            cin >> email;
            cout << "Enter address of member: ";
            cin >> ws;
            getline(cin, address);
            cout << "Enter phone of member: ";
            cin >> phone;
            cout << "Enter username of member: ";
            cin >> username;
            cout << "Enter password of member: ";
            cin >> password;
            password = md5(password);

            MEMBER_DATA[index] = *this;
            std::ofstream fileOutput(MEMBER_FILE_PATH);
            if (fileOutput.fail())
            {
                std::cout << "Cannot open file at " << MEMBER_FILE_PATH << std::endl;
                return;
            }
            else
            {
                fileOutput.clear();
                for (auto element : MEMBER_DATA)
                    outp(element, fileOutput);
                cout << "This record has been updated.\n";

            }
            fileOutput.close();
        }
        else
            cout << "This record has not been updated.\n";
    }
    system("pause");
}

void MemberEntry::Menu()
{
    string choice;
    choice[0] = 0;
    int c = int(choice[0]) - 48;
    do
    {
        system("cls");
        for (auto const& line : lineMemberEntry)
        {
            cout << line << '\n';
        }
        do
        {
            cout << "Your choice: ";
            cin >> ws;
            getline(cin, choice);
            c = int(choice[0]) - 48;
            if (c < 1 || c>6 || choice.size()!=1)
            {
                cout << "Invalid number!\n";
            }
        } while (c < 1 || c>6 || choice.size()!=1);

        switch (c)
        {
        case 1:
            AddNewMember();
            break;
        case 2:
            ShowMember();
            break;
        case 3:
            UpdateRecord();
            break;
        case 4:
            DeleteRecord();
            break;
        case 5:
            SearchRecord();
            break;

        default:
            break;
        }
    } while (c != 6);

}