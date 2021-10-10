#ifndef MASTER_ENTRY_H_
#define MASTER_ENTRY_H_

#include "BaseFunc.h"


class MasterEntry
{
public:
	virtual void AddNewMember();
	virtual void ShowMember();
	virtual void UpdateRecord();
	virtual void DeleteRecord();
	virtual void SearchRecord();
	virtual void Menu();
};
#endif // !MASTER_ENTRY_H_
