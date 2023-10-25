#pragma once
#include <iostream>
#include <string>
using namespace std;

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
};

bool operator <(const Patient& P1, const Patient& P2);

string Patient::ER_description[5];

ostream& operator <<(ostream& outs, const Patient& obj);

