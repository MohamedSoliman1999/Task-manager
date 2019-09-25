#include <iostream>
#include <vector>
#include <string>
#include <Windows.h> /// to use SYSTEMTIME; -> copy computer date
#include <fstream> /// to use ifstream & ofstream; -> save data in files and included in <bits/stdc++.h>
#include <cstdlib> /// to use system("cls"); -> clean the screen and included in <bits/stdc++.h>
#include <stdlib.h> /// to use exit(1); -> close the program and included in <bits/stdc++.h>

using namespace std;


struct Date { int day, month, year; };

struct Task { string title, details;     int priority;     Date due_date; };

int choice; vector<Task>Tasks; vector<Task>Done; vector<Task>Over;

int current_day; int current_month; int current_year;

void view_tasks() {
	for (int i = 0; i<Tasks.size(); i++)         {
		cout << '[' << " " << i + 1 << " " << ']' << endl << "Title: " << Tasks[i].title << '.' << endl;
		cout << "Details: " << Tasks[i].details << '.' << endl;             cout << "Priority: ";
		if (Tasks[i].priority == 1)
			cout << "High. \n";
		else if (Tasks[i].priority == 2)
			cout << "Medium. \n";
		else if (Tasks[i].priority == 3)
			cout << "Low. \n";
		cout << "Due to date: " << Tasks[i].due_date.day << '/' << Tasks[i].due_date.month << '/' << Tasks[i].due_date.year << '.' << endl << endl << endl;
	}
}

void view_done()
{
	for (int i = 0; i<Done.size(); i++)
	{
		cout << '[' << " " << i + 1 << " " << ']' << endl << "Title: " << Done[i].title << '.' << endl;
		cout << "Details: " << Done[i].details << '.' << endl;
		cout << "Priority: ";
		if (Done[i].priority == 1)
			cout << "High. \n";
		else if (Done[i].priority == 2)
			cout << "Medium. \n";
		else if (Done[i].priority == 3)
			cout << "Low. \n";
		cout << "Due to date: " << Done[i].due_date.day << '/' << Done[i].due_date.month << '/' << Done[i].due_date.year << '.' << endl << endl << endl;
	}
}

void over_due()
{
	for (int i = 0; i<Tasks.size(); i++)
	{
		if (Tasks[i].due_date.year<current_year || (Tasks[i].due_date.year == current_year && Tasks[i].due_date.month<current_month) || (Tasks[i].due_date.year == current_year && Tasks[i].due_date.month == current_month && Tasks[i].due_date.day<current_day))
		{
			Over.push_back(Tasks[i]);
			Tasks.erase(Tasks.begin() + i);
		}
	}
}

void add_task() {
	cout << "Type your Task title: ";
	Task to_add;
	getline(cin, to_add.title);
	cout << "Type your Task details: ";
	getline(cin, to_add.details);
	cout << "Enter your Task priority ( 1 -> High , 2 -> Medium , 3 -> Low ): ";
	cin >> to_add.priority;
	cin.ignore();
	while (to_add.priority != 1 && to_add.priority != 2 && to_add.priority != 3)
	{
		cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
		cin >> to_add.priority;
		cin.ignore();
	}     cout << "Enter your Task due to date in format ( DD MM YYYY ): ";     cin >> to_add.due_date.day >> to_add.due_date.month >> to_add.due_date.year;     cin.ignore();     while (to_add.due_date.day>31 || to_add.due_date.day<1 || to_add.due_date.month>12 || to_add.due_date.month<1 || to_add.due_date.year<2018)     { cout << endl << "Wrong Entry." << endl << endl << "Please enter your Task due to date again in format ( DD MM YYYY ) in numbers: ";         cin >> to_add.due_date.day >> to_add.due_date.month >> to_add.due_date.year;         cin.ignore(); }     Tasks.push_back(to_add);     cout << endl << "Task added successfully." << endl << endl;
}

void mark_task() {
	if (Tasks.empty())
		cout << "All Tasks are done." << endl << endl;
	else     {
		view_tasks();
		cout << "Enter the number of the task you want to mark as done: ";
		cin >> choice;
		cin.ignore();
		while (choice>Tasks.size() || choice<1)         {
			cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
			cin >> choice;
			cin.ignore();
		}
		Done.push_back(Tasks[choice - 1]);
		Tasks.erase(Tasks.begin() + choice - 1);
		cout << endl << "Task marked successfully." << endl << endl;
	}
}

void edit_task() {
	if (Tasks.empty())
		cout << "All Tasks are done." << endl << endl;
	else     {
		view_tasks();
		cout << "Enter the number of the task you want to edit: ";
		cin >> choice;
		cin.ignore();
		while (choice>Tasks.size() || choice<1)
		{
			cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
			cin >> choice;
			cin.ignore();
		}
		cout << endl;
		cout << "1 Title. \n" << "2 Details. \n" << "3 Priority. \n" << "4 Due to date." << endl << endl;
		cout << "Enter the number of information you want to edit: ";
		cin >> choice;
		cin.ignore();
		while (choice>4 || choice<1)
		{
			cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
			cin >> choice;
			cin.ignore();
		}
		if (choice == 1)
		{
			cout << endl << "Type your Task new title: ";
			string to_add;
			getline(cin, to_add);
			Tasks[choice - 1].title = to_add;
		}
		else if (choice == 2)         {
			cout << "Type your Task new details: ";
			string to_add;
			getline(cin, to_add);
			Tasks[choice - 1].details = to_add;
		}
		else if (choice == 3)
		{
			cout << "Enter your Task new priority ( 1 -> High , 2 -> Medium , 3 -> Low ): ";
			int temp;
			cin >> temp;
			cin.ignore();
			while (temp != 1 && temp != 2 && temp != 3)
			{
				cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
				cin >> temp;
				cin.ignore();
			}
			Tasks[choice - 1].priority = temp;
		}
		else if (choice == 4)
		{
			cout << "Enter your Task new due to date in format ( DD MM YYYY ): ";
			int temp1, temp2, temp3;
			cin >> temp1 >> temp2 >> temp3;
			cin.ignore();
			while (temp1>31 || temp1<1 || temp2>12 || temp2<1 || temp3<2018)
			{
				cout << endl << "Wrong Entry." << endl << endl << "Please enter your Task new due to date again in format ( DD MM YYYY ) in numbers: ";
				cin >> temp1 >> temp2 >> temp3;
				cin.ignore();
			}
		}
		cout << endl << "Task edited successfully." << endl << endl;
	}
}
//#################################
void delete_task() {
	if (Tasks.empty())         cout << "All Tas are done." << endl << endl;
	else     {

		view_tasks();
		cout << "Enter theks number of the task you want to delete: ";
		cin >> choice;
		cin.ignore();
		while (choice>Tasks.size() || choice<1)
		{
			cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
			cin >> choice;
			cin.ignore();
		}
		Tasks.erase(Tasks.begin() + choice - 1);
		cout << endl << "Task deleted successfully." << endl << endl;
	}
}

void view_over_due()
{
	if (Over.empty())
		cout << "There is no over due Tasks." << endl << endl;
	else
	{
		for (int i = 0; i<Over.size(); i++)
		{
			cout << '[' << " " << i + 1 << " " << ']' << endl << "Title: " << Over[i].title << '.' << endl;
			cout << "Details: " << Over[i].details << '.' << endl;
			cout << "Priority: ";
			if (Over[i].priority == 1)
				cout << "High. \n";
			else if (Over[i].priority == 2)
				cout << "Medium. \n";
			else if (Over[i].priority == 3)
				cout << "Low. \n";
			cout << "Due to date: " << Over[i].due_date.day << '/' << Over[i].due_date.month << '/' << Over[i].due_date.year << '.' << endl << endl << endl;
		}
	}
}

void done_today() {
	int counter = 1;
	bool found = 0;
	for (int i = 0; i<Tasks.size(); i++)
	{
		if (Tasks[i].due_date.year == current_year && Tasks[i].due_date.month == current_month && Tasks[i].due_date.day == current_day)
		{
			found = 1;
			cout << '[' << " " << counter << " " << ']' << endl << "Title: " << Tasks[i].title << '.' << endl;
			cout << "Details: " << Tasks[i].details << '.' << endl;
			cout << "Priority: ";
			if (Tasks[i].priority == 1)
				cout << "High. \n";
			else if (Tasks[i].priority == 2)
				cout << "Medium. \n";
			else if (Tasks[i].priority == 3)
				cout << "Low. \n";
			cout << "Due to date: " << Tasks[i].due_date.day << '/' << Tasks[i].due_date.month << '/' << Tasks[i].due_date.year << '.' << endl << endl << endl;
			counter++;
		}
	}     if (found == 0)
		cout << "There is no Tasks need to be done today. " << endl << endl;
}

void find_task() {
	if (Tasks.empty())
		cout << "There is no Tasks." << endl << endl;
	else
	{
		cout << "1 Title. \n";
		cout << "2 Number. \n";
		cout << "3 Timing. \n";
		cout << "Enter the number of the method you want to search by: ";
		cin >> choice;
		cin.ignore();
		while (choice != 1 && choice != 2 && choice != 3)
		{
			cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";
			cin >> choice;
			cin.ignore();
		}
		if (choice == 1)
		{
			cout << endl << "Type the title of Task: ";
			string to_find;
			getline(cin, to_find);
			cout << endl;
			bool found = 0;
			for (int i = 0; i<Tasks.size(); i++)
			{
				if (Tasks[i].title == to_find)
				{
					found = 1;
					cout << "Found!" << endl << endl;
					cout << "Title: " << Tasks[i].title << '.' << endl;
					cout << "Details: " << Tasks[i].details << '.' << endl;
					cout << "Priority: ";
					if (Tasks[i].priority == 1)
						cout << "High. \n";
					else if (Tasks[i].priority == 2)
						cout << "Medium. \n";
					else if (Tasks[i].priority == 3)
						cout << "Low. \n";
					cout << "Due to date: " << Tasks[i].due_date.day << '/' << Tasks[i].due_date.month << '/' << Tasks[i].due_date.year << '.' << endl << endl << endl;
				}
			}
			if (found == 0)
				cout << "Not Found!" << endl << endl;
		}
		else if (choice == 2)         {
			cout << endl << "Enter the number of Task: ";
			cin >> choice;
			cin.ignore();
			cout << endl;
			if (choice>Tasks.size() || choice<1)
				cout << "Not Found!" << endl << endl;
			else
			{
				cout << "Title: " << Tasks[choice - 1].title << '.' << endl;
				cout << "Details: " << Tasks[choice - 1].details << '.' << endl;
				cout << "Priority: ";
				if (Tasks[choice - 1].priority == 1)
					cout << "High. \n";
				else if (Tasks[choice - 1].priority == 2)
					cout << "Medium. \n";
				else if (Tasks[choice - 1].priority == 3)
					cout << "Low. \n";
				cout << "Due to date: " << Tasks[choice - 1].due_date.day << '/' << Tasks[choice - 1].due_date.month << '/' << Tasks[choice - 1].due_date.year << '.' << endl << endl;
			}
		}
		else if (choice == 3)
		{
			cout << endl << "Enter the due to date of the Task in format ( DD MM YYYY ): ";
			int temp1, temp2, temp3;
			cin >> temp1 >> temp2 >> temp3;
			cin.ignore();
			bool found = 0;
			for (int i = 0; i<Tasks.size(); i++)
			{
				if (Tasks[i].due_date.year == current_year && Tasks[i].due_date.month == current_month && Tasks[i].due_date.day == current_day)
				{
					cout << "Title: " << Tasks[i].title << '.' << endl;
					cout << "Details: " << Tasks[i].details << '.' << endl;
					cout << "Priority: ";
					if (Tasks[i].priority == 1)
						cout << "High. \n";
					else if (Tasks[i].priority == 2)
						cout << "Medium. \n";
					else if (Tasks[i].priority == 3)
						cout << "Low. \n";
					cout << "Due to date: " << Tasks[i].due_date.day << '/' << Tasks[i].due_date.month << '/' << Tasks[i].due_date.year << '.' << endl << endl;
				}
			}
		}
	}
}

void write_files() {
	ofstream out_file1, out_file2, out_file3, sizes;

	out_file1.open("Tasks.txt");     out_file2.open("Done.txt");     out_file3.open("Over.txt");

	for (int i = 0; i<Tasks.size(); i++)     { out_file1 << Tasks[i].title << endl;         out_file1 << Tasks[i].details << endl;         out_file1 << Tasks[i].priority << endl;         out_file1 << Tasks[i].due_date.day << endl;         out_file1 << Tasks[i].due_date.month << endl;         out_file1 << Tasks[i].due_date.year << endl; }

	for (int i = 0; i<Done.size(); i++)     { out_file2 << Done[i].title << endl;         out_file2 << Done[i].details << endl;         out_file2 << Done[i].priority << endl;         out_file2 << Done[i].due_date.day << endl;         out_file2 << Done[i].due_date.month << endl;         out_file2 << Done[i].due_date.year << endl; }

	for (int i = 0; i<Over.size(); i++)     { out_file3 << Over[i].title << endl;         out_file3 << Over[i].details << endl;         out_file3 << Over[i].priority << endl;         out_file3 << Over[i].due_date.day << endl;         out_file3 << Over[i].due_date.month << endl;         out_file3 << Over[i].due_date.year << endl; }

	out_file1.close();     out_file2.close();     out_file3.close();

	sizes.open("Vector Sizes.txt");     sizes << Tasks.size() << endl << Done.size() << endl << Over.size();     sizes.close();
}

void read_files() {

	try{
		ifstream in_file1, in_file2, in_file3, sizes;

		sizes.open("Vector Sizes.txt");     int size1, size2, size3;     sizes >> size1 >> size2 >> size3;     Tasks.resize(size1);     Done.resize(size2);     Over.resize(size3);     sizes.close();

		in_file1.open("Tasks.txt");     in_file2.open("Done.txt");     in_file3.open("Over.txt");

		if (in_file1.fail() || in_file2.fail() || in_file3.fail() || sizes.fail())     { cout << "Error found in files." << endl;         cout << endl << "Please contact the Administrator of the program" << endl;         cout << endl << "Thanks for using our Program. :D \n";         exit(0); }

		for (int i = 0; i < Tasks.size(); i++)     { getline(in_file1, Tasks[i].title);         getline(in_file1, Tasks[i].details);         in_file1 >> Tasks[i].priority;         in_file1 >> Tasks[i].due_date.day;         in_file1 >> Tasks[i].due_date.month;         in_file1 >> Tasks[i].due_date.year;         in_file1.ignore(); }

		for (int i = 0; i < Done.size(); i++)     { getline(in_file2, Done[i].title);         getline(in_file2, Done[i].details);         in_file2 >> Done[i].priority;         in_file2 >> Done[i].due_date.day;         in_file2 >> Done[i].due_date.month;         in_file2 >> Done[i].due_date.year;         in_file2.ignore(); }

		for (int i = 0; i < Over.size(); i++)     { getline(in_file3, Over[i].title);         getline(in_file3, Over[i].details);         in_file3 >> Over[i].priority;         in_file3 >> Over[i].due_date.day;         in_file3 >> Over[i].due_date.month;         in_file3 >> Over[i].due_date.year;         in_file3.ignore(); }

		in_file3.close();     in_file3.close();     in_file3.close();
	}
	catch (exception e){}

}

void main_menu() {
	cout << "1 Add a new Task. \n";     cout << "2 Mark a Task as done. \n";     cout << "3 Edit a specific Task. \n";     cout << "4 Delete a specific Task. \n";     cout << "5 Display all Tasks. \n";     cout << "6 Display all done Tasks. \n";     cout << "7 Display all the overdue Tasks. \n";     cout << "8 Display all the Tasks that need to be done today. \n";     cout << "9 Search for specific Task by its title or number or timing. \n";     cout << "10 Exit. \n\n";     cout << "Your choice: ";

	cin >> choice;     cin.ignore();

	while (choice>10 || choice<1)     { cout << endl << "Wrong Entry." << endl << endl << "Please enter your choice again: ";         cin >> choice;         cin.ignore(); }

	over_due();     system("cls");

	if (choice == 1)         add_task();

	else if (choice == 2)         mark_task();

	else if (choice == 3)         edit_task();

	else if (choice == 4)         delete_task();

	else if (choice == 5)     { if (Tasks.empty())             cout << "There is no Tasks." << endl << endl;         else             view_tasks(); }

	else if (choice == 6)     { if (Done.empty())             cout << "There is no done Tasks." << endl << endl;         else             view_done(); }

	else if (choice == 7)         view_over_due();

	else if (choice == 8)         done_today();

	else if (choice == 9)         find_task();

	else if (choice == 10)     { cout << "Thanks for using our Program. :D \n\n";         write_files();         exit(0); }
}


void press_enter() { cout << "-> Press Enter key to go to the Main Menu...";     string welcome;     getline(cin, welcome);     system("cls"); }



int main() { // Current PC time.

	SYSTEMTIME current_time;
	GetLocalTime(&current_time);
	current_day = current_time.wDay;
	current_month = current_time.wMonth;
	current_year = current_time.wYear;
	//read_files();

	if (Tasks.size() == 0 && Done.size() == 0 && Over.size() == 0)     { cout << "Designed by: \" Mark Nabil , Mohamed Ismail , Mark Talaat , Martin Ashraf , Micheal Ahdy \". \n";         cout << "Faculty of Computer and Information Science Ain Shams University. \n";         cout << "Directed by: \" Dr.Sally Saad \". \n";         cout << "\n \t\t\t\t\t\t\t\t \t \t  Welcome :D \n \n";         cout << "This Program will help you to make your ( TO DO LIST ). \n\n"; }

	else         cout << "Welcome Back :D" << endl << endl;

	while (true)     {
		press_enter();

		main_menu();
	}
}
