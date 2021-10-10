#include"ComputerEntry.h"

vector <ComputerEntry> COMP_DATA;

ComputerEntry::ComputerEntry() {
    id = "";
    typeCPU = "";
    memory = "";
}

void ComputerEntry::outp(ComputerEntry& member, ofstream& file)
{

    file << member.id << std::endl;
    file << member.typeCPU << std::endl;
    file << member.memory << std::endl;
}


void ComputerEntry::AddNewMember()
{
    system("cls");
    cout << "=====ENTER NEW COMPUTER DATA=====\n";
    do
    {
        cout << "Enter ID of computer: ";
        cin >> id;
        if (CheckId(id) >= 0)
        {
            cout << "This ID already exist. Try another one!\n";
        }
    } while (CheckId(id) >= 0);
    cout << "Enter type of CPU: ";
    cin >> typeCPU;
    cout << "Enter memory: ";
    cin >> memory;
    COMP_DATA.push_back(*this);

    std::ofstream fileOutput(COMP_FILE_PATH, std::ios::app);

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
void ComputerEntry::DeleteRecord()
{
    system("cls");
    cout << "======DELETE COMPUTER DATA======\n";
    cout << "Enter ID to delete: ";
    cin >> id;
    const int index = CheckId(id);
    if (index < 0)
    {
        cout << "This ID does not exist!\n";
    }
    else
    {
        cout << COMP_DATA.at(index) << '\n';
        cout << "==>Do you want to delete this computer? (Y/N)" << endl;
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
            COMP_DATA.erase(COMP_DATA.begin() + index);
            COMP_DATA.shrink_to_fit();
            std::ofstream fileOutput(COMP_FILE_PATH);
            if (fileOutput.fail())
            {
                std::cout << "Cannot open file at " << COMP_FILE_PATH << std::endl;
                return;
            }
            else
            {
                fileOutput.clear();
                for (auto& element : COMP_DATA)
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

int ComputerEntry::CheckId(string str)
{
    int ret = -1;
    int i = 0;
    for (const auto& element : COMP_DATA)
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

ostream& operator<<(ostream& os, ComputerEntry& member) {
    os << "\nID: " << member.id;
    os << "\nName: " << member.typeCPU;
    os << "\nMemory: " << member.memory << '\n';
    return os;
}

void ComputerEntry::SearchRecord()
{
    system("cls");
    cout << "======SEARCH COMPUTER DATA======\n";
    cout << "Enter ID to search: ";
    cin >> id;
    int index = CheckId(id);
    if (index < 0)
    {
        cout << "This ID does not exist!\n";
    }
    else
    {
        cout << "--------SEARCHED COMPUTER--------";
        cout << COMP_DATA.at(index);
    }
    system("pause");

}

void ComputerEntry::ShowMember()
{
    system("cls");
    cout << "=========SHOW COMPUTER=========" << endl;
    for (int i = 0; i < COMP_DATA.size(); i++)
        cout << COMP_DATA[i];
    system("pause");
}

void ComputerEntry::UpdateRecord()
{
    system("cls");
    cout << "=======UPDATE COMPUTER DATA=======" << endl;
    cout << "Enter ID to update: ";
    cin >> id;
    const int index = CheckId(id);
    if (index < 0)
    {
        cout << "This ID does not exist!\n";
    }
    else
    {
        cout << COMP_DATA.at(index) << '\n';
        cout << "==>Do you want to update this computer? (Y/N)" << endl;
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
            do
            {
                cout << "Enter ID of computer: ";
                cin >> id;
                if (CheckId(id) >= 0 && CheckId(id) != index)
                {
                    cout << "This ID already exist. Try another one!\n";
                }
            } while (CheckId(id) >= 0 && CheckId(id) != index);
            cout << "Enter name of computer: ";
            cin >> typeCPU;
            cout << "Enter memory of computer: ";
            cin >> memory;

            COMP_DATA[index] = *this;
            std::ofstream fileOutput(COMP_FILE_PATH);
            if (fileOutput.fail())
            {
                std::cout << "Cannot open file at " << COMP_FILE_PATH << std::endl;
                return;
            }
            else
            {
                fileOutput.clear();
                for (auto& element : COMP_DATA)
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

void ComputerEntry::Menu()
{
    string choice;
    choice[0] = 0;
    int c = int(choice[0]) - 48;
    do
    {
        system("cls");
        for (auto const& line : lineComputerEntry)
        {
            cout << line << '\n';
        }
        do
        {
            cout << "Your choice: ";
            cin >> ws;
            getline(cin, choice);
            c = int(choice[0]) - 48;
            if (c < 1 || c>6)
            {
                cout << "Invalid number!\n";
            }
        } while (c < 1 || c>6);


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