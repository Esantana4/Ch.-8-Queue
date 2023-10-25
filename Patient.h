#pragma once
#include <iostream>
#include <string>
#include<queue>
using namespace std;

void mainMenu();
int inputInteger(string prompt, int startRange, int endRange);
char inputChar(string prompt, char yes, char no);
int inputInteger(string prompt, bool posNeg);

class Patient
{
private:
	int priority;
	unsigned int checkedInTime;
	string name;
	int age;
	char gender;
	unsigned int admittedTime;
	string careUnit;
	static string ER_description[5];
public:

	Patient();

	void setCheckedInTime(unsigned int t);

	unsigned int getCheckedInTime() const;

	void setPriority(int priority);

	int getPriority() const;

	void setName(string name);

	string getName() const;

	void setAge(int age);

	int getAge() const;

	void setGender(char gender);

	char getGender() const;

	friend bool operator <(const Patient& P1, const Patient& P2); //key in priority queue

	friend ostream& operator<<(ostream& outs, const Patient& obj);

	//void engine();
	void option2();
};

//bool operator <(const Patient& P1, const Patient& P2);
//
//string Patient::ER_description[5];
//
//ostream& operator <<(ostream& outs, const Patient& obj);

