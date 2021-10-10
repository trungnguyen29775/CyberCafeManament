#ifndef MEMBER_ENTRY_H_
#define MEMBER_ENTRY_H_

#include "MasterEntry.h"


class MemberEntry : public MasterEntry
{
private:
	string id, name, address, phone, email, username, password;
public:
	MemberEntry();
	~MemberEntry() { ; }


	friend void InitializeMember();
	friend void login();
	string getUser() const { return username; }
	string getPass() { return password; }
	string getId() { return id; }

	void setId(string st) { id = st; }
	void setName(string n) { name = n; }
	void setAddress(string add) { address = add; }
	void setPhone(string p) { phone = p; }
	void setEmail(string e) { email = e; }
	void setUsername(string us) { username = us; }
	void setPassword(string pw) { password = pw; }



	void AddNewMember();
	void ShowMember();
	void UpdateRecord();
	void DeleteRecord();
	void SearchRecord();
	int CheckId(string str);
	friend ostream& operator<<(ostream& os, MemberEntry& member);
	void outp(MemberEntry& member, ofstream& file);
	void Menu();

};

extern vector <MemberEntry> MEMBER_DATA;


#endif // !MEMBER_ENTRY_H_
