// Note.h Нужен для реализации главного класса в программе 
// Здесь содержатся прототипы функций и некоторые необходимые библиотеки

#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Note							// Класс записная книжка
{
public:
	friend ostream & operator << (ostream & os, const Note & other);// Перегрузка оператора вывода
	friend istream & operator >> (istream & os, Note & other);		// Перегрузка оператора ввода		
	void SearchName(char * surname, Note temp);	// Поиск записи по фамилии

	Note();							// Конструктор без параметров
	Note(char name[50],				// Конструктор, инициализирующий поля класса Note
		char surname[50],
		char city[50],
		char postcode[10],
		char phone[15],
		char email[50]);
	~Note();								// Деструктор без параметров
	
public:									// Закрытые поля класса Note
	char name[50];
	char surname[50];
	char city[50];
	char postcode[10];
	char phone[15];
	char email[50];
};

void print_menu ();							// Вывод интерфейса
void show_notes (vector<Note>VecNotes);		// Вывод записей
void open_file(ofstream & of);				// Открытие файла
void write_in_file(ofstream & of, vector<Note>VecNotes); // Запись в файл
void catch_error(int op);					// Защита от дурака