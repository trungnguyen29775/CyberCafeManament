#ifndef COMPUTER_ENTRY_H_
#define COMPUTER_ENTRY_H_

#include"MasterEntry.h"

class ComputerEntry :public MasterEntry
{
private:
	string id, typeCPU, memory;
public:
	ComputerEntry();
	~ComputerEntry() { ; }
	string getId() { return id; }
	friend void InitializeComputer();
	void AddNewMember();
	void ShowMember();
	void UpdateRecord();
	void DeleteRecord();
	void SearchRecord();
	int CheckId(string str);
	void Menu();
	void outp(ComputerEntry& member, ofstream& file);
	friend ostream& operator<<(ostream&, ComputerEntry&);
};

extern vector<ComputerEntry> COMP_DATA;

#endif // !COMPUTER_ENTRY_H_

