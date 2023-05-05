
#include "Functions.h"
#include "Structure.h"
#include "Functions.cpp"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли

//МЕНЮ АДМИНА
void MainAdminMenu() {
	system("cls");
	//добавить список топ студентов и пентагон
	string Menu[] = { "Выставить оценку за экзамен", "Выставить оценку по олимпиаде", "Выставить оценку по лабораторной работе", "Список студентов с оценкой ниже заданной", "Выставить пропуски студентам", "Просмотреть пропуски студентов", "Список топ студентов", "Взлом системы", "Выйти из аккаунта" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 65, y = 20;
		GoToXY(62, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————— Меню администратора —————————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(62, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "———————————————————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch) {
		case ESCAPE:
			return;
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			else {
				active_menu = size(Menu) - 1;
			}
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			else {
				active_menu = 0;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 0:
				if (studentsCount()) break;
				rateExam();
				break;
			case 1:
				if (studentsCount()) break;
				rateOlimp();
				break;
			case 2:
				if (studentsCount()) break;
				rateLaba();
				break;
			case 3:
				if (studentsCount()) break;
				gradesList();
				break;
			case 4:
				if (studentsCount()) break;
				putUpPasses(); //пропуски
				break;
			case 5:
				if (studentsCount()) break;
				outputPasses();
				break;
			case 6:
				if (studentsCount()) break;
				topStudents();
				break;
			case 7: Pentagon();
				break;
			case 8:
				system("cls");
				return;
			}
			break;
		default:
			break;
		}
	}
}

//выставить оценки по экзамену
void rateExam() {
	int y = 5;
	system("cls");
	GoToXY(70, y);
	cout << "Выберите студента:";

	y = choiceTable(y);

	int i = 0;
	for (i; i < CountOfUsers; ++i) {
		y += 2;
		GoToXY(57, y);
		cout << i + 1;
		GoToXY(60, y);
		cout << " | " << clients[i].group;
		GoToXY(70, y);
		cout << "| " << clients[i].name;
		GoToXY(100, y);
		cout << "| " << clients[i].login;
		GoToXY(55, y + 1);
		cout << "——————————————————————————————————————————————————————————————";
	}
	int choice{};
	choice = checkNum(choice, CountOfUsers, i);
	--choice;

	system("cls");

	string Menu[] = { "ОАиП", "ООПиП", "Физика", "Математика", "Английский язык", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(72, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————  Выберите предмет  ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) GoToXY(85, ++y);
			else if (i == 1) GoToXY(84, ++y);
			else if (i == 2) GoToXY(83, ++y);
			else if (i == 3) GoToXY(82, ++y);
			else if (i == 4) GoToXY(x + 3, ++y);
			else GoToXY(84, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(72, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			return;
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			else {
				active_menu = size(Menu) - 1;
			}
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			else {
				active_menu = 0;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 4:	rate_Exam(choice, &clients[choice].englishGradeExam);
				break;
			case 3: rate_Exam(choice, &clients[choice].mathGradeExam);
				break;
			case 0: rate_Exam(choice, &clients[choice].oaipGradeExam);
				break;
			case 1:	rate_Exam(choice, &clients[choice].oopGradeExam);
				break;
			case 2: rate_Exam(choice, &clients[choice].physicsGradeExam);
				break;
			case 5:
				system("cls");
				return;
			}
			break;
		default:
			break;
		}
	}
}

void rateOlimp() {
	int y = 5;
	system("cls");
	GoToXY(70, y);
	cout << "Выберите студента:";

	y = choiceTable(y);

	int i = 0;
	for (i; i < CountOfUsers; ++i) {
		y += 2;
		GoToXY(57, y);
		cout << i + 1;
		GoToXY(60, y);
		cout << " | " << clients[i].group;
		GoToXY(70, y);
		cout << "| " << clients[i].name;
		GoToXY(100, y);
		cout << "| " << clients[i].login;
		GoToXY(55, y + 1);
		cout << "——————————————————————————————————————————————————————————————";
	}
	int choice{};
	choice = checkNum(choice, CountOfUsers, i);
	--choice;

	system("cls");

	string Menu[] = { "ОАиП", "ООПиП", "Физика", "Математика", "Английский язык", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(72, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————  Выберите предмет  ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) GoToXY(85, ++y);
			else if (i == 1) GoToXY(84, ++y);
			else if (i == 2) GoToXY(83, ++y);
			else if (i == 3) GoToXY(82, ++y);
			else if (i == 4) GoToXY(x + 3, ++y);
			else GoToXY(84, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(72, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			return;
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			else {
				active_menu = size(Menu) - 1;
			}
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			else {
				active_menu = 0;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 4:	rate_Olimp(choice, &clients[choice].englishGradeOlimp);
				break;
			case 3: rate_Olimp(choice, &clients[choice].mathGradeOlimp);
				break;
			case 0: rate_Olimp(choice, &clients[choice].oaipGradeOlimp);
				break;
			case 1:	rate_Olimp(choice, &clients[choice].oopGradeOlimp);
				break;
			case 2: rate_Olimp(choice, &clients[choice].physicsGradeOlimp);
				break;
			case 5:
				system("cls");
				return;
			default:
				break;
			}
		}
	}
}

void rateLaba() {
	int y = 5;
	system("cls");
	GoToXY(70, y);
	cout << "Выберите студента:";

	y = choiceTable(y);

	int i = 0;
	for (i; i < CountOfUsers; ++i) {
		y += 2;
		GoToXY(57, y);
		cout << i + 1;
		GoToXY(60, y);
		cout << " | " << clients[i].group;
		GoToXY(70, y);
		cout << "| " << clients[i].name;
		GoToXY(100, y);
		cout << "| " << clients[i].login;
		GoToXY(55, y + 1);
		cout << "——————————————————————————————————————————————————————————————";
	}
	int choice{};
	choice = checkNum(choice, CountOfUsers, i);
	--choice;

	system("cls");

	string Menu[] = { "ОАиП", "ООПиП", "Физика", "Математика", "Английский язык", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(72, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————  Выберите предмет  ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) GoToXY(85, ++y);
			else if (i == 1) GoToXY(84, ++y);
			else if (i == 2) GoToXY(83, ++y);
			else if (i == 3) GoToXY(82, ++y);
			else if (i == 4) GoToXY(x + 3, ++y);
			else GoToXY(84, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(72, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			return;
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			else {
				active_menu = size(Menu) - 1;
			}
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			else {
				active_menu = 0;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 4:	rate_Laba(choice, clients[choice].englishGradeLaba);
				break;
			case 3: rate_Laba(choice, clients[choice].mathGradeLaba);
				break;
			case 0: rate_Laba(choice, clients[choice].oaipGradeLaba);
				break;
			case 1:	rate_Laba(choice, clients[choice].oopGradeLaba);
				break;
			case 2: rate_Laba(choice, clients[choice].physicsGradeLaba);
				break;
			case 5:
				system("cls");
				return;
			default:
				break;
			}
		}

	}
}

//список студентов с оценкой ниже заданной
void gradesList() {

	system("cls");

	string Menu[] = { "ОАиП", "ООПиП", "Физика", "Математика", "Английский язык", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(72, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————  Выберите предмет  ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) GoToXY(85, ++y);
			else if (i == 1) GoToXY(84, ++y);
			else if (i == 2) GoToXY(83, ++y);
			else if (i == 3) GoToXY(82, ++y);
			else if (i == 4) GoToXY(x + 3, ++y);
			else GoToXY(84, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(72, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			return;
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			else {
				active_menu = size(Menu) - 1;
			}
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			else {
				active_menu = 0;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 4:	englishGradesList();
				system("cls");
				break;
			case 3: mathGradesList();
				system("cls");
				break;
			case 0: oaipGradesList();
				system("cls");
				break;
			case 1:	oopGradesList();
				system("cls");
				break;
			case 2: physicsGradesList();
				system("cls");
				break;
			case 5:
				system("cls");
				return;
			default:
				break;
			}
		}

	}
}

void putUpPasses() {
	int y = 5;
	system("cls");
	GoToXY(70, y);
	cout << "Выберите студента:";

	y += 2;
	GoToXY(57, y);
	cout << "№";
	GoToXY(60, y);
	cout << " | Группа";
	GoToXY(70, y);
	cout << "| Ф.И.О.";
	GoToXY(100, y);
	cout << "| Логин";
	GoToXY(55, y + 1);
	cout << "—————————————————————————————————————————————————————————————————";


	int i = 0;
	for (i; i < CountOfUsers; ++i) {
		y += 2;
		GoToXY(57, y);
		cout << i + 1;
		GoToXY(60, y);
		cout << " | " << clients[i].group;
		GoToXY(70, y);
		cout << "| " << clients[i].name;
		GoToXY(100, y);
		cout << "| " << clients[i].login;
		GoToXY(55, y + 1);
		cout << "—————————————————————————————————————————————————————————————————";
	}
	int choice{};
	choice = checkNum(choice, CountOfUsers, i);
	--choice;

	system("cls");

	string Menu[] = { "ОАиП", "ООПиП", "Физика", "Математика", "Английский язык", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(72, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————  Выберите предмет  ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) GoToXY(85, ++y);
			else if (i == 1) GoToXY(84, ++y);
			else if (i == 2) GoToXY(83, ++y);
			else if (i == 3) GoToXY(82, ++y);
			else if (i == 4) GoToXY(x + 3, ++y);
			else GoToXY(84, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(72, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			return;
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			else {
				active_menu = size(Menu) - 1;
			}
			break;
		case DOWN:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			else {
				active_menu = 0;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 4: {
				system("cls");
				GoToXY(65, 20);
				cout << "Введите количество пропусков студента: ";
				int passes{};
				passes = checkNam(passes, 60, 20);
				clients[choice].englishPasses = passes;
				system("cls");
				GoToXY(70, 20);
				cout << "Пропуски выставлены!";
				GoToXY(65, 22);
				pulsar();
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				GoToXY(65, 20);
				cout << "Введите количество пропусков студента: ";
				int passes{};
				passes = checkNam(passes, 60, 20);
				clients[choice].mathPasses = passes;
				system("cls");
				GoToXY(70, 20);
				cout << "Пропуски выставлены!";
				GoToXY(65, 22);
				pulsar();
				system("cls");
				break;
			}
			case 0: {
				system("cls");
				GoToXY(65, 20);
				cout << "Введите количество пропусков студента: ";
				int passes{};
				passes = checkNam(passes, 60, 20);
				clients[choice].oaipPasses = passes;
				system("cls");
				GoToXY(70, 20);
				cout << "Пропуски выставлены!";
				GoToXY(65, 22);
				pulsar();
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				GoToXY(65, 20);
				cout << "Введите количество пропусков студента: ";
				int passes{};
				passes = checkNam(passes, 60, 20);
				clients[choice].oopPasses = passes;
				system("cls");
				GoToXY(70, 20);
				cout << "Пропуски выставлены!";
				GoToXY(65, 22);
				pulsar();
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				GoToXY(65, 20);
				cout << "Введите количество пропусков студента: ";
				int passes{};
				passes = checkNam(passes, 60, 20);
				clients[choice].physicsPasses = passes;
				system("cls");
				GoToXY(70, 20);
				cout << "Пропуски выставлены!";
				GoToXY(65, 22);
				pulsar();
				system("cls");
				break;
			}
			case 5:
				system("cls");
				return;
			default:
				break;
			}
		}

	}

	GoToXY(70, 20);
	cout << "Пропуски выставлены!";
	GoToXY(65, 22);
	pulsar();
	system("cls");
}

void outputPasses() {

	system("cls");
	GoToXY(50, 2);
	cout << "Ф.И.О.";
	GoToXY(77, 2);
	cout << "| Группа";
	GoToXY(87, 2);
	cout << "| Предметы";
	GoToXY(107, 2);
	cout << "| Пропуски";
	GoToXY(48, 3);
	cout << "——————————————————————————————————————————————————————————————————————";

	int y = 4, x = 87, z = 107;

	for (int i = 0; i < CountOfUsers; ++i, y += 10) {
		GoToXY(48, y - 1);
		cout << "——————————————————————————————————————————————————————————————————————";
		GoToXY(50, y + 4);
		cout << clients[i].name;
		GoToXY(79, y + 4);
		cout << clients[i].group;

		for (int t = y; t < y + 10; ++t) {
			GoToXY(77, t);
			cout << "|";
		}

		GoToXY(x, y);
		cout << "| Английский язык";
		GoToXY(x, y + 1);
		cout << "———————————————————————————————";
		GoToXY(x, y + 2);
		cout << "| Математика";
		GoToXY(x, y + 3);
		cout << "———————————————————————————————";
		GoToXY(x, y + 4);
		cout << "| ОАиП";
		GoToXY(x, y + 5);
		cout << "———————————————————————————————";
		GoToXY(x, y + 6);
		cout << "| ООПиП";
		GoToXY(x, y + 7);
		cout << "———————————————————————————————";
		GoToXY(x, y + 8);
		cout << "| Физика";
		GoToXY(x, y + 9);
		cout << "———————————————————————————————";

		GoToXY(z, y);
		cout << "|    " << clients[i].englishPasses;
		GoToXY(z, y + 2);
		cout << "|    " << clients[i].mathPasses;
		GoToXY(z, y + 4);
		cout << "|    " << clients[i].oaipPasses;
		GoToXY(z, y + 6);
		cout << "|    " << clients[i].oopPasses;
		GoToXY(z, y + 8);
		cout << "|    " << clients[i].physicsPasses;
	}

	GoToXY(48, y - 1);
	cout << "——————————————————————————————————————————————————————————————————————";


	GoToXY(65, y + 2);
	system("pause");
	system("cls");
}
