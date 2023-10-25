#include "Patient.h"

Patient::Patient()
{
	checkedInTime;
	priority = 0;
	name = "unknown";
	age = 0;
	gender = 'u';
}

void Patient::setCheckedInTime(unsigned int t)
{
	this->checkedInTime = t;
}

unsigned int Patient::getCheckedInTime() const
{
	return checkedInTime;
}

void Patient::setPriority(int priority)
{
	this->priority = priority;
}

int Patient::getPriority() const
{
	return priority;
}

void Patient::setName(string name)
{
	this->name = name;
}

string Patient::getName() const
{
	return name;
}

void Patient::setAge(int age)
{
	this->age = age;
}

int Patient::getAge() const
{
	return age;
}

void Patient::setGender(char gender)
{
	this->gender = gender;
}

char Patient::getGender() const
{
	return gender;
}

bool operator <(const Patient& P1, const Patient& P2)
{
return P1.priority < P2.priority;
}

string Patient::ER_description[5] = { "Stable, with no resources anticipated or prescriptions", "Stable, with only one type of resource anticipated " ,"Stable, with multiple types of resources needed to investigate or treat", "High risk of deterioration, or signs of a time-critical problem", "Immediate, life-saving intervention required without delay" };

ostream& operator <<(ostream& outs, const Patient& obj)
{
	outs << "ER level: " << obj.getPriority() << " - " << obj.ER_description[obj.getPriority() - 1] << '\n';
	outs << "\t\t\tChecked-In time: " << obj.getCheckedInTime() << '\n';
	outs << "\t\t\tPatient's name: " << obj.getName() << '\n';
	outs << "\t\t\tPatient's age: " << obj.getAge() << '\n';
	outs << "\t\t\tPatient's gender: " << obj.getGender() << '\n';
	return outs;
}

void Patient::option2()
{
    system("cls");
    cout << "\n\t2> Simulation of an emergency room (ER) using priority queue STL\n";
    priority_queue<Patient> pq2;
    vector<Patient> submit;
    do
    {
        cout << "\n\t\t 1> Register a patient";
        cout << "\n\t\t 2> Transfer patient(s) to the designation";
        cout << "\n\t\t 3> Display transferred patients";
        cout << "\n\t\t 0> return\n";
        switch (toupper(inputInteger("\t\t Option: ", 0, 3)))
        {
        case 0: return;
        case 1:
        {
            Patient patient;
            string name;
            cout << "\n\t\tEnter the patient's name: ";
            getline(cin, name);
            patient.setName(name);
            patient.setAge(inputInteger("\t\tEnter the patient's age: ", true));
            patient.setCheckedInTime(time(0));
            patient.setGender(toupper(inputChar("\t\tChoose the patient's gender (F-female or M - male) : ", 'F', 'M')));
                patient.setPriority(inputInteger("\t\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5));
                pq2.push(patient); // enqueue
            cout << "\n\t\tPatient information has been registered.\n";
        }
        break;
        case 2:
        {
            if (!pq2.empty())
            {
                if (pq2.top().getPriority() == 5)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to ICU...\n" ;
                        pq2.pop(); // dequeue
                    break;
                }
                else if (pq2.top().getPriority() == 4)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to surgery room...\n";
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 3)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to emergency room...\n";
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 2)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to xray lab...\n";
                    pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 1)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - examines and gives prescription...\n";
                        pq2.pop();
                    break;
                }
            }
        }
        break;
        case 3:
        {
            if (!submit.empty())
            {
                sort(submit.begin(), submit.end());
                reverse(submit.begin(), submit.end());
                cout << '\n';
                for (int i = 0; i < submit.size(); i++)
                    cout << "\t\t" << i + 1 << " - " << submit[i] << '\n';
            }
            else
                cout << "\n\t\tNo patient has been transferred.\n";
        }
        break;
        }
    } while (true);
}

/*
void Patient::engine()
{
    cout << endl;
    cout << "\t2> Simulation of an emergency room (ER) using priority queue STL";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Register a patient" << endl;
    cout << "\t2> Transfer patient(s) to the designation" << endl;
    cout << "\t3> Display transferred patients" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > Return to Main Menu" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\n\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
        case 0: system("cls"); mainMenu(); break;
        case 1:
        {
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            break;
        }
        }
        system("pause");
        // new line
        cout << "\n";

    } while (true);
}
*/