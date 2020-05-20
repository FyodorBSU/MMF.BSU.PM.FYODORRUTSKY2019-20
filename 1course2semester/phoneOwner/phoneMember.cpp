#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "phoneOwner.h"

using namespace std;

phoneOwner::phoneOwner(char* firstName, char* lastName, char* middleName, char* phoneNumber, char* mailIndex, char* country, char* district, char* region, char* city, char* street, int numberOfHouse)
{
	this->SetPhoneOwner(firstName, lastName, middleName, phoneNumber, mailIndex, country, district, region, city, street, numberOfHouse);
}
void phoneOwner::SetFirstName(char* firstName)
{
	strcpy(this->firstName, firstName);
}
void phoneOwner::SetLastName(char* lastName)
{
	strcpy(this->lastName, lastName);
}
void phoneOwner::SetMiddleName(char* middleName)
{
	strcpy(this->middleName, middleName);
}
void phoneOwner::SetPhoneNumber(char* phoneNumber)
{
	strcpy(this->phoneNumber, phoneNumber);
}
void phoneOwner::setMailIndex(char* mailIndex)
{
	strcpy(this->mailIndex, mailIndex);
}
void phoneOwner::setCountry(char* country)
{
	strcpy(this->country, country);
}
void phoneOwner::setDistrict(char* district)
{
	strcpy(this->district, district);
}
void phoneOwner::setRegion(char* region)
{
	strcpy(this->region, region);
}
void phoneOwner::setCity(char* city)
{
	strcpy(this->city, city);
}
void phoneOwner::setStreet(char* street)
{
	strcpy(this->street, street);
}
void phoneOwner::setNumberOfHouse(int numberOfHouse)
{
	this->numberOfHouse = numberOfHouse;
}

char* phoneOwner::GetFirstName()
{
	return this->firstName;
}

char* phoneOwner::GetLastName()
{
	return this->lastName;
}

char* phoneOwner::GetMiddleName()
{
	return this->middleName;
}

char* phoneOwner::GetPhoneNumber()
{
	return this->phoneNumber;
}
int phoneOwner:: GetNumberOfHouse()
{
	return this->numberOfHouse;
}
void phoneOwner::SetPhoneOwner(char* firstName, char* lastName, char* middleName, char* phoneNumber, char* mailIndex, char* country, char* district, char* region, char* city, char* street, int numberOfHouse)
{
	this->SetFirstName(firstName);
	this->SetLastName(lastName);
	this->SetMiddleName(middleName);
	this->SetPhoneNumber(phoneNumber);
	this->setMailIndex(mailIndex);
	this->setCountry(country);
	this->setDistrict(district);
	this->setRegion(region);
	this->setCity(city);
	this->setStreet(street);
	this->setNumberOfHouse(numberOfHouse);
}

void phoneOwner::DisplayPhoneOwner()
{
	cout << endl << this->lastName << " " << this->firstName << " " << this->middleName << ", \t";
	cout.precision(3);
	cout << "Adress" << endl << this->mailIndex << ", " << this->country << ", " << this->district << ", " << this->region << ", " << this->city << ", " << this->street << ", " << this->numberOfHouse<<endl;
	cout << this->phoneNumber << "  \t" << ".";

}

void phoneOwner::EnterPhoneOwner()
{
	const int N = 256;
	char firstName[N] = "", lastName[N] = "", middleName[N] = "", phoneNumber[N] = "", mailIndex[N] = "", country[N] = "", district[N] = "", region[N] = "", city[N] = "", street[N] = "";
	cout << "Enter the first name of student:";
	cin.ignore();
	cin.getline(firstName, N, '\n');
	cout << "Enter the last name of student:";
	cin.getline(lastName, N, '\n');
	cout << "Enter the middle name of student:";
	cin.getline(middleName, N, '\n');
	cout << "Enter the phone number:";
	cin.getline(phoneNumber, N, '\n');
	cout << "Enter mail index:";
	cin.getline(mailIndex, N, '\n');
	cout << "Enter the country:";
	cin.getline(country, N, '\n');
	cout << "Enter the district:";
	cin.getline(district, N, '\n');
	cout << "Enter the region:";
	cin.getline(region, N, '\n');
	cout << "Enter the city:";
	cin.getline(city, N, '\n');
	cout << "Enter the street:";
	cin.getline(street, N, '\n');
	int numberOfHouse = 0;
	cout << "Enter the numbrer of house:" << endl;
	cin >> numberOfHouse;
	this->SetPhoneOwner(firstName, lastName, middleName, phoneNumber, mailIndex, country, district, region, city, street, numberOfHouse);
}
