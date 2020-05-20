#pragma once

const int N = 50;


class phoneOwner
{
public:
	phoneOwner() {}
	phoneOwner(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*, int);
	~phoneOwner() {}
	void SetFirstName(char*);
	void SetLastName(char*);
	void SetMiddleName(char*);
	void SetPhoneNumber(char*);
	void setMailIndex(char*);
	void setCountry(char*);
	void setDistrict(char*);
	void setRegion(char*);
	void setCity(char*);
	void setStreet(char*);
	void setNumberOfHouse(int);
	void SetPhoneOwner(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*, int);
	char* GetFirstName();
	char* GetLastName();
	char* GetMiddleName();
	char* GetPhoneNumber();
	int GetNumberOfHouse();
	void EnterPhoneOwner();
	void DisplayPhoneOwner();
private:
	char firstName[N], lastName[N], middleName[N], phoneNumber[N], mailIndex[N], country[N], district[N], region[N], city[N], street[N];
	int numberOfHouse;
};
