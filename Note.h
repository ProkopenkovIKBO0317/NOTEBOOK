// Note.h ����� ��� ���������� �������� ������ � ��������� 
// ����� ���������� ��������� ������� � ��������� ����������� ����������

#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Note							// ����� �������� ������
{
public:
	friend ostream & operator << (ostream & os, const Note & other);// ���������� ��������� ������
	friend istream & operator >> (istream & os, Note & other);		// ���������� ��������� �����		
	void SearchName(char * surname, Note temp);	// ����� ������ �� �������

	Note();							// ����������� ��� ����������
	Note(char name[50],				// �����������, ���������������� ���� ������ Note
		char surname[50],
		char city[50],
		char postcode[10],
		char phone[15],
		char email[50]);
	~Note();								// ���������� ��� ����������
	
public:									// �������� ���� ������ Note
	char name[50];
	char surname[50];
	char city[50];
	char postcode[10];
	char phone[15];
	char email[50];
};

void print_menu ();							// ����� ����������
void show_notes (vector<Note>VecNotes);		// ����� �������
void open_file(ofstream & of);				// �������� �����
void write_in_file(ofstream & of, vector<Note>VecNotes); // ������ � ����
void catch_error(int op);					// ������ �� ������