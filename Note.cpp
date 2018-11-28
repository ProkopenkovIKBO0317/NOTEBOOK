//////////////////////////////////////////////////////////////////////
//		                     Note.cpp								//
//    Здесь содержится реализация функций из заголовочного файла    // 
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Note.h"

Note::Note() {}

Note::Note(char name[50], char surname[50], char city[50], char postcode[10], char phone[15], char email[50])
{ // инициализация полей класса
	this->name[50] = *name;
	this->surname[50] = *surname;
	this->city[50] = *city;
	this->postcode[50] = *postcode;
	this->phone[50] = *phone;
	this->email[50] = *email;
} 

Note::~Note()
{

}




ostream & operator << (ostream & os, const Note & other)
{
	os << other.name
		<< " " << other.surname
		<< " " << other.city
		<< " " << other.postcode
		<< " " << other.phone
		<< " " << other.email;
	return os;
}

istream & operator >> (istream & os, Note & other)
{
	os  >> other.name 
		>> other.surname 
		>> other.city 
		>> other.postcode
		>> other.phone 
		>> other.email;
	return os;
}

void write_in_file(ofstream & of, vector<Note>VecNotes)
{
	of.open("output.txt", std::ios_base::app);
	for (int i = 0; i < VecNotes.size(); i++)
	{
		of << VecNotes[i] << endl;
	}
	of.close();
}

void Note::SearchName(char * surname, Note men)
{
	int c = 0;
		if (surname == men.surname)
		{
			cout << men << endl;
			c++;
		}
	if (c == 0)
	{
		cout << "The note with this name does not exist!" << endl;
	}
}

void open_file(ofstream & of)
{
	of.open("output.txt", std::ios_base::app);
	of.close();
}

void print_menu()
{
	cout << "* * * * * * * * * * * * * * * * *" << endl;
	cout << "* 1. To add note about a person *" << endl;
	cout << "* 2. To edit note               *" << endl;
	cout << "* 3. To delete note             *" << endl;
	cout << "* 4. Sort notes                 *" << endl;
	cout << "* 5. Show all notes             *" << endl;
	cout << "* 6. Search by surname          *" << endl;
	cout << "* 7. Exit                       *" << endl;
	cout << "* * * * * * * * * * * * * * * * *" << endl;
}

void show_notes(vector<Note>VecNotes)
{
	for (int i = 0; i < VecNotes.size(); i++)
	{
		cout << VecNotes[i];
		cout << endl;
	}
}

void catch_error(int op)
{
	if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7)
	{
		cout << "Incorrect data entry. Restart the programe..." << endl;
		exit(0);
	}
	else
	{
		
	}

}
