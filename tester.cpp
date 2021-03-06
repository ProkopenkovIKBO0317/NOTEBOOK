// main.cpp: определяет точку входа для консольного приложения.
// поддержание записной книжки в актуальном состоянии.
#include "stdafx.h"
#include "Note.h"

int main()
{
	vector<Note> VecNotes;
	char		 surname[50];
	int			 kol = 0;
	int			 c = 0;
	int			 op = 0;
	int			 del = 0;
	int			 index;
	Note		 men;
	ofstream	 of;
	ifstream	 fin("output.txt");


	open_file(of);
	print_menu();
		while (!fin.eof())
		{
			fin >> men;
			VecNotes.push_back(men);
		}
		VecNotes.erase(VecNotes.end() - 1);
		fin.close();

	while (true)
	{
		cout << "\nAmount of notes " <<	VecNotes.size() << endl;
		cin >> op;
		catch_error(op);
		switch (op)
		{
		case 1 : // Добавить запись в массив
			cout << "Enter information about a person" << endl;
			cout << "Name Surname City Postcode Telephone Email" << endl;
			cin >> men;
			cout << "Note is added! ";
			VecNotes.push_back(men);
			break;

		case 2 : // Редактировать запись
			for (int i = 0; i < VecNotes.size(); i++)
			{
				cout << VecNotes[i] << " (" << i + 1 << ")" << endl;
			}

			cout << "Enter the number of the note you want to overwrite " << endl;
			cin >> index;
			cout << "Name Surname City Postcode Telephone Email" << endl;
			cin >> men;

			for (int i = 0; i < 1; i++)
			{
				VecNotes[index - 1] = men;
			}
			cout << "The note was overwritten!" << endl;
			break;

		case 3 : // Удалить запись
			for (int i = 0; i < VecNotes.size(); i++)
			{
				cout << VecNotes[i] << " (" << i + 1 << ")" << endl;
			}

			cout << "Select a note: "; cin >> del;
			VecNotes.erase(VecNotes.begin() + del-1);
			cout << "The note was deleted!" << endl;
			break;

		case 4 :
			
			break;

		case 5 : // Вывод всех записей
			show_notes(VecNotes);
			break;

		case 6 : // Поиск записи по фамилии
			cout << "Enter surname: "; cin >> surname;
			men.SearchName(surname, men);
			break;

		case 7 : // выход из программы
			of.open("output.txt", std::ios_base::trunc);
			of.close();
			write_in_file(of, VecNotes);
			exit(0);
			break;

		default:
			cout << "Symbol is not supported!" << endl;
			break;

		}
		op = 0;
	}
	
	system("pause");
	return 0;
}

