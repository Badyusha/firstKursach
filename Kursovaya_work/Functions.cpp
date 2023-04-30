
#include "Functions.h"
#include "Structure.h"





HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли

int CountOfUsers = 0; // кол-во студентов
int CountOfProfessors = 0; // кол-во преподов

const string professorKey = "professor123";

const string adminLogin = "admin";
const string adminPassword = "admin123";




void Pentagon() {

	srand(time(NULL));

	int random = 0;
	int border = 0;

	while (border != 30000)
	{
		random = rand() % 21 + 0;
		if (random == 1)
		{
			SetConsoleTextAttribute(hStdOut, 2);
			cout << rand() % 2 + 0;
			cout << "\t";
		}
		if (random == 2)
		{
			SetConsoleTextAttribute(hStdOut, 2);
			cout << rand() % 2 + 0;
			cout << "\t\t\t";
		}
		if (random == 3)
		{
			SetConsoleTextAttribute(hStdOut, 10);
			cout << rand() % 2 + 0;
			cout << "\t";
		}
		if (random == 4)
		{
			SetConsoleTextAttribute(hStdOut, 2);
			cout << rand() % 2 + 0;
			cout << "\t\t";
		}
		if (random == 5)
		{
			SetConsoleTextAttribute(hStdOut, 2);
			cout << rand() % 2 + 0;
			cout << "\t\t";
		}
		if (random == 6)
		{
			SetConsoleTextAttribute(hStdOut, 2);
			cout << rand() % 2 + 0;
			cout << "\t\t";
		}
		SetConsoleTextAttribute(hStdOut, 2);
		cout << rand() % 2 + 0;
		++border;
	}
	
	system("cls");

	Sleep(500);

	GoToXY(78, 20);

	string str = "Текущее местоположение";
	for (int i = 0; i < size(str); ++i) {
		Sleep(100);
		cout << str[i];
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Sleep(100);
			cout << ".";
		}
		Sleep(100);// задержка вывода в консоль
		cout << "\b\b\b ";//вставляет пробел вместо опред. символа
		Sleep(100);
		cout << " ";
		Sleep(100);
		cout << "  ";
		cout << "\b\b\b\b";
	}
	GoToXY(65, 22);
	string ch = "Республика Беларусь, город Минск, Советский район";

	for (int i = 0; i < size(ch); ++i) {
		Sleep(100);
		cout << ch[i];
	}

	
	while (1) {
		SYSTEMTIME deviceTime;
		GetSystemTime(&deviceTime);
		GoToXY(70, 24);
		Sleep(10);
		cout << "                                                                                                     ";
		GoToXY(70, 24);
		if (deviceTime.wHour < 21) {
			cout << "Дата: " << deviceTime.wDay << "." << deviceTime.wMonth << "." << deviceTime.wYear << "\t\tВремя: " << deviceTime.wHour + 3 << ":" << deviceTime.wMinute << ":" << deviceTime.wSecond;
		}
		else
			cout << "Дата: " << deviceTime.wDay << "." << deviceTime.wMonth << "." << deviceTime.wYear << "\t\tВремя: " << deviceTime.wHour - 21 << ":" << deviceTime.wMinute << ":" << deviceTime.wSecond;

		GoToXY(70, 26);
		cout << "Для продолжения нажмите любую клавишу ";
			for (int j = 0; j < 3; ++j) {
				Sleep(50);
				cout << ".";
				if (_kbhit()) {
					_getch();
					system("cls");
					return;
				}
			}
			Sleep(50);// задержка вывода в консоль
			cout << "\b\b\b ";//вставляет пробел вместо опред. символа
			Sleep(50);
			cout << " ";
			Sleep(50);
			cout << "  ";
			cout << "\b\b\b\b";
			if (_kbhit()) {
				_getch();
				system("cls");
				return;
			}
		GoToXY(70, 26);
		cout << "                                              ";
		if (_kbhit()) {
			_getch();
			system("cls");
			return;
		}
	}
}

//главное меню
void RegistrationMenu() {
	setlocale(LC_ALL, "Rus"); // подкл рус яз
	system("chcp 1251"); // два раза подк рус яз потому что при записи в файл кракозябра без систем
	system("cls");
	if (!readStudentFile() || !readProfessorFile()) { // считываем инфу из файла и записываем в структуру
		system("cls");
		exit(0);
	}

	string Menu[] = { "Регистрация", "Авторизация", "Выход"};

	int active_menu = 0; // будем бегать по меню изменяя эту переменную

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(67, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————— Главное меню —————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(67, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			SetConsoleTextAttribute(hStdOut, 7);
			recordLabaGrades();
			exit(0);
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
			case 0: {
				system("CLS");
				int i = 0;
				i = Registration(i);
				if (i == 0) MainStudentMenu(CountOfUsers - 1);
				else if(i == 1) MainProfessorMenu(CountOfProfessors - 1);
				system("CLS");
				break;
			}
			case 1:
				system("CLS");
				
				Autorization();
				
				system("CLS");
				break;
			case 2:
				SetConsoleTextAttribute(hStdOut, 7);
				recordLabaGrades();
				recordProfessors();
				exit(0);
			}
			break;
		default:
			break;
		}
	}
}

//расшифровка пароля
string pressOutFunc(string str) {

	for (int i = 0; i < size(str); ++i) {
		--str[i];
	}
	return str;
}

//запись студентов в файл
void recordLabaGrades() {



	ofstream funcOut;
	funcOut.open("students.txt");

	funcOut << endl;
	for (int i = 0; i < CountOfUsers; ++i) {
		funcOut << clients[i].name << endl;
		funcOut << clients[i].login << endl;

		string password = clients[i].password;
		password = PressmarkFunc(password);
		funcOut << password << endl;

		funcOut << clients[i].group << endl;

		funcOut << clients[i].englishPasses << endl;
		funcOut << clients[i].mathPasses << endl;
		funcOut << clients[i].oaipPasses << endl;
		funcOut << clients[i].oopPasses << endl;
		funcOut << clients[i].physicsPasses << endl;

		funcOut << clients[i].englishGradeExam << endl;
		funcOut << clients[i].englishGradeOlimp << endl;
		funcOut << clients[i].mathGradeExam << endl;
		funcOut << clients[i].mathGradeOlimp << endl;
		funcOut << clients[i].oaipGradeExam << endl;
		funcOut << clients[i].oaipGradeOlimp << endl;
		funcOut << clients[i].oopGradeExam << endl;
		funcOut << clients[i].oopGradeOlimp << endl;
		funcOut << clients[i].physicsGradeExam << endl;
		funcOut << clients[i].physicsGradeOlimp << endl;

		
		// ЕДИНИЦЫ СКОРЕЕ ВСЕГО МОЖНО ЗАМЕНИТЬ НА СТРОКУ
		for (int j = 0; j < 50; ++j) {
			if (clients[i].englishGradeLaba[j] < 1) {
				break;
			}
			funcOut << clients[i].englishGradeLaba[j] << endl;
		}
		funcOut << 11111 << endl;



		for (int j = 0; j < 50; ++j) {
			if (clients[i].mathGradeLaba[j] < 1) {
				break;
			}
			funcOut << clients[i].mathGradeLaba[j] << endl;
		}
		funcOut << 11111 << endl;



		for (int j = 0; j < 50; ++j) {
			if (clients[i].oaipGradeLaba[j] < 1) {
				break;
			}
			funcOut << clients[i].oaipGradeLaba[j] << endl;
		}
		funcOut << 11111 << endl;



		for (int j = 0; j < 50; ++j) {
			if (clients[i].oopGradeLaba[j] < 1) {
				break;
			}
			funcOut << clients[i].oopGradeLaba[j] << endl;
		}
		funcOut << 11111 << endl;



		for (int j = 0; j < 50; ++j) {
			if (clients[i].physicsGradeLaba[j] < 1) {
				break;
			}
			funcOut << clients[i].physicsGradeLaba[j] << endl;
		}
		funcOut << 11111 << endl;



	}
	funcOut << endl;
}

//запись преподов в файл
void recordProfessors() {
	ofstream funcProfessorOut;
	funcProfessorOut.open("professors.txt");
	for (int i = 0; i < CountOfProfessors; ++i) {
		funcProfessorOut << teachers[i].login;
		funcProfessorOut << "\n" << PressmarkFunc(teachers[i].password);
		funcProfessorOut << "\n" << teachers[i].subject;
		funcProfessorOut << "\n" << teachers[i].name << endl;
	}
}

//чтение преподов из файлов
bool readProfessorFile() {
	string path = "professors.txt";
	ifstream funcProfessorIn;
	funcProfessorIn.open(path);

	if (!funcProfessorIn.is_open()) {
		GoToXY(70, 25);
		system("cls");
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "Невозможно открыть файл professors.txt !";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		return funcProfessorIn.is_open();
	}

	while (!funcProfessorIn.eof()) {

		getline(funcProfessorIn, teachers[CountOfProfessors].login);
		string password;
		getline(funcProfessorIn,password);
		for (int i = 0; i < size(password); ++i) {
			password[i] = --password[i];
		}
		teachers[CountOfProfessors].password = password;
		getline(funcProfessorIn, teachers[CountOfProfessors].subject);
		getline(funcProfessorIn, teachers[CountOfProfessors].name);
		++CountOfProfessors;
	}
	funcProfessorIn.close();

	--CountOfProfessors;

	return true;
}

//чтение студентов из файла
bool readStudentFile() {
	string path = "students.txt";
	ifstream funcIn;
	funcIn.open(path);
	if (!funcIn.is_open()) {
		GoToXY(70, 25);
		system("cls");
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "Невозможно открыть файл students.txt !";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		return funcIn.is_open();
	}

	int i = 0;
	while (!funcIn.eof()) {
		getline(funcIn, clients[i].name); // перемещаем курсор потомушо так не работает
		getline(funcIn, clients[i].name);
		getline(funcIn, clients[i].login);

		string password;
		getline(funcIn, password);
		password = pressOutFunc(password);
		clients[i].password = password;

		funcIn >> clients[i].group;

		funcIn >> clients[i].englishPasses;
		funcIn >> clients[i].mathPasses;
		funcIn >> clients[i].oaipPasses;
		funcIn >> clients[i].oopPasses;
		funcIn >> clients[i].physicsPasses;


		funcIn >> clients[i].englishGradeExam;
		funcIn >> clients[i].englishGradeOlimp;
		funcIn >> clients[i].mathGradeExam;
		funcIn >> clients[i].mathGradeOlimp;
		funcIn >> clients[i].oaipGradeExam;
		funcIn >> clients[i].oaipGradeOlimp;
		funcIn >> clients[i].oopGradeExam;
		funcIn >> clients[i].oopGradeOlimp;
		funcIn >> clients[i].physicsGradeExam;
		funcIn >> clients[i].physicsGradeOlimp;



		for (int j = 0; j < 50; ++j) {
			int mark;
			funcIn >> mark;
			if (mark == 11111) break;
			clients[i].englishGradeLaba[j] = mark;
		}



		for (int j = 0; j < 50; ++j) {
			int mark;
			funcIn >> mark;
			if (mark == 11111) break;
			clients[i].mathGradeLaba[j] = mark;
		}



		for (int j = 0; j < 50; ++j) {
			int mark;
			funcIn >> mark;
			if (mark == 11111) break;
			clients[i].oaipGradeLaba[j] = mark;
		}



		for (int j = 0; j < 50; ++j) {
			int mark;
			funcIn >> mark;
			if (mark == 11111) break;
			clients[i].oopGradeLaba[j] = mark;
		}



		for (int j = 0; j < 50; ++j) {
			int mark;
			funcIn >> mark;
			if (mark == 11111) break;
			clients[i].physicsGradeLaba[j] = mark;
		}




		++i;
	}

	CountOfUsers = --i;

	return true;
}





//МЕНЮ АДМИНА
void MainAdminMenu() {
	system("cls");
	//добавить список топ студентов и пентагон
	string Menu[] = { "Выставить оценку за экзамен", "Выставить оценку по олимпиаде", "Выставить оценку по лабораторной работе", "Список студентов с оценкой ниже заданной", "Выставить пропуски студентам", "Просмотреть пропуски студентов", "Список топ студентов", "Взлом системы", "Выйти из аккаунта"};
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

	string Menu[] = { "ОАиП", "ООПиП", "Физика", "Математика", "Английский язык", "Назад"};
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
				break;
			case 3: mathGradesList();
				break;
			case 0: oaipGradesList();
				break;
			case 1:	oopGradesList();
				break;
			case 2: physicsGradesList();
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
			case 0:{
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






// изменить номер группы
void groupNumber(int count) {
	system("cls");
	int newGroup{};
	GoToXY(65, 20);
	cout << "Введите номер своей группы: ";
	newGroup = checkGroup(newGroup);
	clients[count].group = newGroup;

	Loading();
}

void newLogin(int count, string* login) {
	system("cls");
	string newLogin{};
	do {
		GoToXY(65, 20);
		cout << "Введите новый логин: ";
		getline(cin, newLogin);
		GoToXY(65, 20);
		cout << "                                  ";
	} while (checkLogin(newLogin));
	*login = newLogin;
	Loading();
}

void newPassword(int count, string* password) {
	system("cls");

	string firstPassword, secondPassword;

	do {
		GoToXY(65, 20);
		string currentPassword{};
		cout << "Введите текущий пароль: ";
		currentPassword = passwordEntering();
		if (currentPassword != teachers[count].password) {
			system("cls");
			GoToXY(70, 20);
			cout << "Пароль введен неверно!";
			Sleep(850);
			system("cls");
			return;
		}

		do {
			GoToXY(65, 22);
			cout << "Введите новый пароль: ";
			firstPassword = passwordEntering();
			if (firstPassword == teachers[count].password) {
				GoToXY(70, 24);
				cout << "Пароли должны отличаться!";
				GoToXY(65, 26);
				pulsar();
			}
		} while (checkPassword(firstPassword) || firstPassword == teachers[count].password);

		do {
			GoToXY(65, 24);
			cout << "Повторите новый пароль: ";
			secondPassword = passwordEntering();
		} while (checkPassword(secondPassword));

		if (secondPassword != firstPassword) {
			GoToXY(65, 22);
			cout << "                                             ";

			GoToXY(65, 24);
			cout << "                                             ";

			GoToXY(70, 23);
			cout << "Пароли не совпадают!";
			GoToXY(62, 25);
			pulsar();
		}

	} while (secondPassword != firstPassword);

	*password = secondPassword;

	Loading();
	system("cls");
}

void changeStudentProfileInfo(int count) {
	system("cls");
	string Menu[] = { "Ф.И.О.", "Логин", "Пароль", "Группа", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 65, y = 20;
		GoToXY(76, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "—————— Изменить личную информацию ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(92, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(76, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————————————" << endl;

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
			case 0: {
				system("cls");
				string name;
				do {
					GoToXY(70, 20);
					cout << "Введите своё Ф.И.О. : ";
					getline(cin, name);
				} while (checkName(name));

				Loading();

				clients[count].name = name;
				break;
			}
			case 1:
				newLogin(count, &clients[count].login);
				break;
			case 2:
				newPassword(count, &clients[count].password);
				break;
			case 3:
				groupNumber(count);
				break;
			case 4:
				system("cls");
				return;
			}
			break;
		default:
			break;
		}
	}
}

// МЕНЮ СТУДЕНТА
void MainStudentMenu(int count) {
	system("cls");
	string Menu[] = { "Вывести список топ студентов", "Просмотреть оценки за экзамены", "Просмотреть оценки по предметам", "Просмотреть количество пропусков", "Просмотреть баллы по олимпиадам", "Средняя оценка на контрольной точке", "Изменить личную информацию", "Личный кабинет", "Выйти из аккаунта"};
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 65, y = 20;
		GoToXY(62, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————— Меню студента —————————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(62, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "—————————————————————————————————————————" << endl;

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
			case 0: topStudents();
				break;
			case 1: examGrades(count);
				break;
			case 2: subjectsGrades(count);
				break;
			case 3: studentPasses(count);
				break;
			case 4: olimpGrades(count);
				break;
			case 5: averageGrade();
				outputAverageGrade(count);
				break;
			case 6:changeStudentProfileInfo(count);
				break;
			case 7: personalStudentsCabinet(count);
				break;
			case 8:
				return;
			}
			break;
		default:
			break;
		}
	}
}

void personalStudentsCabinet(int count) {
	system("cls");
	int y = 20, x = 65;
	GoToXY(62, y - 1);
	cout << "——————————————— Личный кабинет ——————————————" << endl;

	GoToXY(x, ++y);
	cout << "Ф.И.О.\t\t" << clients[count].name;
	GoToXY(x, y += 2);
	cout << "Группа\t\t" << clients[count].group;
	GoToXY(x, y += 2);
	cout << "Логин\t\t" << clients[count].login;
	GoToXY(x, y += 2);
	averageGrade(); // сначала узнаем ср оценку
	if (clients[count].averageGrade < 1) {
		cout << "Ср. оценка\t-";
	}
	else {
		cout.precision(3);
		cout << "Ср. оценка\t" << clients[count].averageGrade;
	}

	GoToXY(62, y += 2);
	cout << "—————————————————————————————————————————————" << endl;

	GoToXY(64, y + 2);
	pulsar();
	system("cls");
}


// исправить отметку
void changeExam(int count, int professor) {
	system("cls");
	int newMark{};
	newMark = CheckNumber(newMark);

	if (teachers[professor].subject == "english") {
		clients[count].englishGradeExam = newMark;
	}
	else if (teachers[professor].subject == "math") {
		clients[count].mathGradeExam = newMark;
	}
	else if (teachers[professor].subject == "Oaip") {
		clients[count].oaipGradeExam = newMark;
	}
	else if (teachers[professor].subject == "oop") {
		clients[count].oopGradeExam = newMark;
	}
	else clients[count].physicsGradeExam = newMark;

	system("cls");
	GoToXY(70, 20);
	cout << "Отметка успешно исправлена!";
	GoToXY(65, 22);
	pulsar();

}

void changeOlimp(int count, int professor) {
	system("cls");
	int newMark{};
	newMark = CheckNumber(newMark);

	if (teachers[professor].subject == "english") {
		clients[count].englishGradeOlimp = newMark;
	}
	else if (teachers[professor].subject == "math") {
		clients[count].mathGradeOlimp = newMark;
	}
	else if (teachers[professor].subject == "Oaip") {
		clients[count].oaipGradeOlimp = newMark;
	}
	else if (teachers[professor].subject == "oop") {
		clients[count].oopGradeOlimp = newMark;
	}
	else clients[count].physicsGradeOlimp = newMark;

	system("cls");
	GoToXY(70, 20);
	cout << "Отметка успешно исправлена!";
	GoToXY(65, 22);
	pulsar();

}

void changeLaba(int count, int professor) {
	system("cls");

	GoToXY(55, 18);
	cout << "Оценку по какой лабораторной работе вы желаете исправить?   ";
	int numberOfLaba{};
	while (!(cin >> numberOfLaba) || numberOfLaba <= 0) {
		system("cls");
		cin.clear();
		cin.ignore(1024, '\n');
		GoToXY(65, 20);
		cout << "Неверное значение!";
		SetConsoleTextAttribute(hStdOut, 7);
		GoToXY(65, 22);
		cout << "Попробуйте снова: ";
	}
	--numberOfLaba;

	if (teachers[professor].subject == "english") {
		if (clients[count].englishGradeLaba[0] < 1) {
			system("cls");
			GoToXY(65, 20);
			cout << "У выбранного студента нет ни одной оценки!";
			system("cls");
			return;
		}
		if (clients[count].englishGradeLaba[numberOfLaba] <= 0) {
			GoToXY(60, 20);
			cout << "Оценка за выбранную лабораторную работу не найдена!";
			GoToXY(65, 22);
			pulsar();
			return;
		}
		else {
			int newMark{};
			newMark = CheckNumber(newMark);
			clients[count].englishGradeLaba[numberOfLaba] = newMark;
		}
	}
	else if (teachers[professor].subject == "math") {
		if (clients[count].mathGradeLaba[0] < 1) {
			system("cls");
			GoToXY(65, 20);
			cout << "У выбранного студента нет ни одной оценки!";
			system("cls");
			return;
		}
		if (clients[count].mathGradeLaba[numberOfLaba] <= 0) {
			GoToXY(60, 20);
			cout << "Оценка за выбранную лабораторную работу не найдена!";
			GoToXY(65, 22);
			pulsar();
			return;
		}
		else {
			int newMark{};
			newMark = CheckNumber(newMark);
			clients[count].mathGradeLaba[numberOfLaba] = newMark;
		}
	}
	else if (teachers[professor].subject == "Oaip") {
		if (clients[count].oaipGradeLaba[0] < 1) {
			system("cls");
			GoToXY(65, 20);
			cout << "У выбранного студента нет ни одной оценки!";
			system("cls");
			return;
		}
		if (clients[count].oaipGradeLaba[numberOfLaba] <= 0) {
			GoToXY(60, 20);
			cout << "Оценка за выбранную лабораторную работу не найдена!";
			GoToXY(65, 22);
			pulsar();
			return;
		}
		else {
			int newMark{};
			newMark = CheckNumber(newMark);
			clients[count].oaipGradeLaba[numberOfLaba] = newMark;
		}
	}
	else if (teachers[professor].subject == "oop") {
		if (clients[count].oopGradeLaba[0] < 1) {
			system("cls");
			GoToXY(65, 20);
			cout << "У выбранного студента нет ни одной оценки!";
			system("cls");
			return;
		}
		if (clients[count].oopGradeLaba[numberOfLaba] <= 0) {
			GoToXY(60, 20);
			cout << "Оценка за выбранную лабораторную работу не найдена!";
			GoToXY(65, 22);
			pulsar();
			return;
		}
		else {
			int newMark{};
			newMark = CheckNumber(newMark);
			clients[count].oopGradeLaba[numberOfLaba] = newMark;
		}
	}
	else {
		if (clients[count].physicsGradeLaba[0] < 1) {
			system("cls");
			GoToXY(65, 20);
			cout << "У выбранного студента нет ни одной оценки!";
			system("cls");
			return;
		}
		if (clients[count].physicsGradeLaba[numberOfLaba] <= 0) {
			GoToXY(60, 20);
			cout << "Оценка за выбранную лабораторную работу не найдена!";
			GoToXY(65, 22);
			pulsar();
			return;
		}
		else {
			int newMark{};
			newMark = CheckNumber(newMark);
			clients[count].physicsGradeLaba[numberOfLaba] = newMark;
		}
	}

	system("cls");
	GoToXY(70, 20);
	cout << "Отметка успешно исправлена!";
	GoToXY(65, 22);
	pulsar();
}

void formOfLessonChoice(int count, int professor) {

	system("cls");

	string Menu[] = { "Экзамен", "Олимпиада", "Лабораторная работа", "Назад"};

	int active_menu = 0; // будем бегать по меню изменяя эту переменную

	char ch;
	while (1)
	{
		int x = 77, y = 20;
		GoToXY(67, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————— Выберите пункт —————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) {
				GoToXY(x + 3, ++y);
				cout << Menu[i] << endl;
			}
			else if (i == 1) {
				GoToXY(x + 2, ++y);
				cout << Menu[i] << endl;
			}
			else if (i == 2) {
				GoToXY(x - 2, ++y);
				cout << Menu[i] << endl;
			}
			else {
				GoToXY(x + 4, ++y);
				cout << Menu[i] << endl;
			}
		}

		GoToXY(67, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			SetConsoleTextAttribute(hStdOut, 7);
			recordLabaGrades();
			exit(0);
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
			case 0: {
				changeExam(count, professor);
				return;
			}
			case 1:
				changeOlimp(count, professor);
				return;
			case 2:
				changeLaba(count, professor);
				return;
			case 3:
				return;
			}
			break;
		default:
			break;
		}
	}
}

void changeGrade(int count) {
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

	formOfLessonChoice(choice, count);

	system("cls");
}

//МЕНЮ ПРЕПОДА
void MainProfessorMenu(int count) {
	system("cls");
	string Menu[] = { "Выставить оценку за экзамен", "Выставить оценку по олимпиаде", "Выставить оценку по лабораторной работе", "Список студентов с оценкой ниже заданной", "Выставить пропуски студентам", "Просмотреть пропуски студентов", "Исправить выставленную отметку", "Изменить личную информацию", "Личный кабинет", "Выйти из аккаунта"};
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 65, y = 20;
		GoToXY(62, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————— Меню преподавателя —————————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(62, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "——————————————————————————————————————————————" << endl;

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
			case 0: {
				if (studentsCount()) break;
				rateExam(count);
				break;
			}
			case 1:
				if (studentsCount()) break;
				rateOlimp(count);
				break;
			case 2:
				if (studentsCount()) break;
				rateLaba(count);
				break;
			case 3:
				if (studentsCount()) break;
				gradesList(count);
				break;
			case 4: 
				if (studentsCount()) break;
				putUpPasses(count); //пропуски
				break;
			case 5: 
				if (studentsCount()) break;
				outputPasses(count);
				break;
			case 6:
				if (studentsCount()) break;
				changeGrade(count);
				break;
			case 7: changeProfessorProfileInfo(count);
				break;
			case 8: personalProfessorsCabinet(count);
				break;
			case 9:
				return;
			}
			break;
		default:
			break;
		}
	}
}

void personalProfessorsCabinet(int count) {
	system("cls");
	int y = 20, x = 65;
	GoToXY(62, y - 1);
	cout << "——————————————— Личный кабинет ——————————————" << endl;

	GoToXY(x, ++y);
	cout << "Ф.И.О.\t\t" << teachers[count].name;
	GoToXY(x, y += 2);
	cout << "Предмет\t";
	if (teachers[count].subject == "english") cout << "английский язык";
	else if (teachers[count].subject == "math") cout << "математика";
	else if (teachers[count].subject == "oaip") cout << "ОАИП";
	else if (teachers[count].subject == "oop") cout << "ООПиП";
	else cout << "Физика";
	GoToXY(x, y += 2);
	cout << "Логин\t\t" << teachers[count].login;

	GoToXY(62, y += 2);
	cout << "—————————————————————————————————————————————" << endl;

	GoToXY(64, y + 2);
	pulsar();
	system("cls");
}



//предмет препода
void subjects(int count) {
	system("cls");

	string Menu[] = { "Физика", "Английский язык", "Математический анализ", "Основы алгоритмизации и программирования", "Объектно ориентированное проектирование и программирование" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 55, y = 20;
		GoToXY(50, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————— Выберите предмет —————————————————————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) {
				GoToXY(77, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 1) {
				GoToXY(73, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 2) {
				GoToXY(70, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 3) {
				GoToXY(62, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 4) {
				GoToXY(x, ++y);
				cout << Menu[i] << endl;
			}
		}

		GoToXY(50, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————————————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
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
			case 0: {
				teachers[count].subject = "physics";
				return;
			}
			case 1:
				teachers[count].subject = "english";
				return;
			case 2:
				teachers[count].subject = "math";
				return;
			case 3:
				teachers[count].subject = "oaip";
				return;
			case 4:
				teachers[count].subject = "oop";
				return;
			}
			break;
		default:
			break;
		}
	}
}

void changeProfessorProfileInfo(int count) {
	system("cls");
	string Menu[] = { "Ф.И.О.", "Логин", "Пароль", "Преподаваемый предмет", "Назад" };
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 65, y = 20;
		GoToXY(76, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "—————— Изменить личную информацию ——————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0 || i == 2 || i == 4 || i == 1) GoToXY(92, ++y);
			else GoToXY(85, ++y);
			cout << Menu[i] << endl;
		}

		GoToXY(76, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————————————" << endl;

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
			case 0: {
				system("cls");
				string name;
				do {
					GoToXY(70, 20);
					cout << "Введите своё Ф.И.О. : ";
					getline(cin, name);
				} while (checkName(name));

				Loading();

				teachers[count].name = name;
				break;
			}
			case 1:
				newLogin(count, &teachers[count].login);
				break;
			case 2:
				newPassword(count, &teachers[count].password);
				break;
			case 3:
				subjects(count);
				Loading();
				break;
			case 4:
				system("cls");
				return;
			}
			break;
		default:
			break;
		}
	}
}




void olimpGrades(int count) {

	system("cls");

	int y = 10;

	GoToXY(65, y++);
	cout << "Ф.И.О.";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "Группа";
	GoToXY(63, y++);
	cout << "————————————";
	++y;
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "Английский";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "Математика";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "ОАИП";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "ООПиП";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y);
	cout << "Физика";


	y = 10;

	GoToXY(77, y++);
	cout << "| " << clients[count].name;
	GoToXY(75, y++);
	cout << "——————————————————————————————";
	GoToXY(77, y++);
	cout << "| " << clients[count].group;
	GoToXY(75, y++);
	cout << "——————————————————————————————";
	++y;
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].englishGradeOlimp < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].englishGradeOlimp;

	GoToXY(75, y++);
	cout << "——————————————————————————————";
	GoToXY(77, y++);
	if (clients[count].mathGradeOlimp < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].mathGradeOlimp;
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].oaipGradeOlimp < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].oaipGradeOlimp;
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].oopGradeOlimp < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].oopGradeOlimp;
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].physicsGradeOlimp < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].physicsGradeOlimp;

	GoToXY(63, y);
	cout << "——————————————————————————————————————————";

	GoToXY(62, 27);
	pulsar();
	system("cls");
}

void outputAverageGrade(int count) {
	system("cls");

	Users newArray[100];
	for (int i = 0; i < CountOfUsers; ++i) {
		newArray[i] = clients[i];
	}

	// shell
	Users temp;
	int gap;
	for (gap = CountOfUsers / 2; gap > 0; gap /= 2) {
		int i, j, sorted;
		do
		{
			sorted = 0;
			for (i = 0, j = gap; j < CountOfUsers; i++, j++)
				if (newArray[i].averageGrade < newArray[j].averageGrade)
				{
					temp = newArray[i];
					newArray[i] = newArray[j];
					newArray[j] = temp;
					sorted = 1;
				}
		} while (sorted);
	}

	int topNumber = 0;
	while (newArray[topNumber].login != clients[count].login) ++topNumber;

	int y = 7, x = 50;

	GoToXY(x, y);
	cout << "Ф.И.О. : " << clients[count].name;
	GoToXY(100, y);
	cout << "Группа : " << clients[count].group;

	GoToXY(75, 10);
	cout.precision(3);
	cout << "Ваша средняя оценка:   " << clients[count].averageGrade;
	GoToXY(74, 11);
	cout << "——————————————————————————————";
	GoToXY(50, 12);
	cout << "Ваш номер в списке топ студентов:   " << topNumber << "   ( всего человек на потоке:   " << CountOfUsers << "   )";
	GoToXY(49, 13);
	cout << "————————————————————————————————————————————————————————————————————————————————";

	GoToXY(68, 15);
	pulsar();
	system("cls");

}



void examGrades(int count) {

	system("cls");

	int y = 10;

	GoToXY(65, y++);
	cout << "Ф.И.О.";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "Группа";
	GoToXY(63, y++);
	cout << "————————————";
	++y;
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "Английский";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "Математика";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "ОАИП";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y++);
	cout << "ООПиП";
	GoToXY(63, y++);
	cout << "————————————";
	GoToXY(65, y);
	cout << "Физика";


	y = 10;

	GoToXY(77, y++);
	cout << "| " << clients[count].name;
	GoToXY(75, y++);
	cout << "——————————————————————————————";
	GoToXY(77, y++);
	cout << "| " << clients[count].group;
	GoToXY(75, y++);
	cout << "——————————————————————————————";
	++y;
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].englishGradeExam < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].englishGradeExam;

	GoToXY(75, y++);
	cout << "——————————————————————————————";
	GoToXY(77, y++);
	if (clients[count].mathGradeExam < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].mathGradeExam;	
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].oaipGradeExam < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].oaipGradeExam;	
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].oopGradeExam < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].oopGradeExam;	
	GoToXY(75, y++);
	cout << "——————————————————————————————";

	GoToXY(77, y++);
	if (clients[count].physicsGradeExam < 1) {
		cout << "| -";
	}
	else cout << "| " << clients[count].physicsGradeExam;	
	
	GoToXY(63, y);
	cout << "——————————————————————————————————————————";

	GoToXY(62, 27);
	pulsar();
	system("cls");
}

void averageSort() {

	/*
	int engGradesCount{};
	int mathGradesCount{};
	int oaipGradesCount{};
	int oopGradesCount{};
	int physicsGradesCount{};

	
	for (int i = 0; i < CountOfUsers; ++i) {
		if(clients[i].englishGradeExam > 0){
			clients[i].averageEnglish += clients->englishGradeExam;
			++engGradesCount;
		}
		if (clients[i].mathGradeExam > 0) {
			clients[i].averageMath += clients->mathGradeExam;
			++mathGradesCount;
		}
		if (clients[i].oaipGradeExam > 0) {
			clients[i].averageOaip += clients->oaipGradeExam;
			++oaipGradesCount;
		}
		if (clients[i].oopGradeExam > 0) {
			clients[i].averageOop += clients->oopGradeExam;
			++oopGradesCount;
		}
		if (clients[i].physicsGradeExam > 0) {
			clients[i].averagePhysics += clients->physicsGradeExam;
			++physicsGradesCount;
		}



		if (clients[i].englishGradeOlimp > 0) {
			clients[i].averageEnglish += clients->englishGradeOlimp;
			++engGradesCount;
		}
		if (clients[i].mathGradeOlimp > 0) {
			clients[i].averageMath += clients->mathGradeOlimp;
			++mathGradesCount;
		}
		if (clients[i].oaipGradeOlimp > 0) {
			clients[i].averageOaip += clients->oaipGradeOlimp;
			++oaipGradesCount;
		}
		if (clients[i].oopGradeOlimp > 0) {
			clients[i].averageOop += clients->oopGradeOlimp;
			++oopGradesCount;
		}
		if (clients[i].physicsGradeOlimp > 0) {
			clients[i].averagePhysics += clients->physicsGradeOlimp;
			++physicsGradesCount;
		}

		for (int j = 0; j < 50; ++j) {
			if (clients[i].englishGradeLaba[j] > 0) {
				clients[i].averageEnglish += clients[i].englishGradeLaba[j];
				++engGradesCount;
			}
			if (clients[i].mathGradeLaba[j] > 0) {
				clients[i].averageMath += clients[i].mathGradeLaba[j];
				++mathGradesCount;
			}
			if (clients[i].oaipGradeLaba[j] > 0) {
				clients[i].averageOaip += clients[i].oaipGradeLaba[j];
				++oaipGradesCount;
			}
			if (clients[i].oopGradeLaba[j] > 0) {
				clients[i].averageOop += clients[i].oopGradeLaba[j];
				++oopGradesCount;
			}
			if (clients[i].physicsGradeLaba[j] > 0) {
				clients[i].averagePhysics += clients[i].physicsGradeLaba[j];
				++physicsGradesCount;
			}
		}

		clients[i].averageEnglish /= engGradesCount;
		clients[i].averageMath /= mathGradesCount;
		clients[i].averageOaip /= oaipGradesCount;
		clients[i].averageOop /= oopGradesCount;
		clients[i].averagePhysics /= physicsGradesCount;
	}
	*/

}

void subjectsGrades(int count) {
	system("cls");

	int y = 7, x = 50;

	GoToXY(x, y);
	cout << "Ф.И.О. : " << clients[count].name;
	GoToXY(100, y);
	cout << "Группа : " << clients[count].group;

	y = 10;

	GoToXY(5, y++);
	cout << "Английский (экзамен)";
	GoToXY(3, y++);
	cout << "————————————————————————";
	GoToXY(5, y++);
	cout << "Математика (экзамен)";
	GoToXY(3, y++);
	cout << "————————————————————————";
	GoToXY(5, y++);
	cout << "ОАИП (экзамен)";
	GoToXY(3, y++);
	cout << "————————————————————————";
	GoToXY(5, y++);
	cout << "ООПиП (экзамен)";
	GoToXY(3, y++);
	cout << "————————————————————————";
	GoToXY(5, y);
	cout << "Физика (экзамен)";

	y = 10;

	GoToXY(27, y++);
	if (clients[count].englishGradeExam > 0)
		cout << "|  " << clients[count].englishGradeExam;
	else cout << "|  -";

	GoToXY(26, y++);
	cout << "————————————————————————";

	GoToXY(27, y++);
	if (clients[count].mathGradeExam > 0)
		cout << "|  " << clients[count].mathGradeExam;
	else cout << "|  -";

	GoToXY(26, y++);
	cout << "————————————————————————";

	GoToXY(27, y++);
	if (clients[count].oaipGradeExam > 0)
		cout << "|  " << clients[count].oaipGradeExam;
	else cout << "|  -";

	GoToXY(26, y++);
	cout << "————————————————————————";

	GoToXY(27, y++);
	if (clients[count].oopGradeExam > 0)
		cout << "|  " << clients[count].oopGradeExam;
	else cout << "|  -";

	GoToXY(26, y++);
	cout << "————————————————————————";

	GoToXY(27, y);
	if (clients[count].physicsGradeExam > 0)
		cout << "|  " << clients[count].physicsGradeExam;
	else cout << "|  -";

	y = 10;

	GoToXY(33, y++);
	cout << "| Английский (олимпиада)";
	GoToXY(30, y++);
	cout << "—————————————————————————————————————————————————————————————";
	GoToXY(33, y++);
	cout << "| Математика (олимпиада)";
	GoToXY(30, y++);
	cout << "————————————————————————";
	GoToXY(33, y++);
	cout << "| ОАИП (олимпиада)";
	GoToXY(30, y++);
	cout << "————————————————————————";
	GoToXY(33, y++);
	cout << "| ООПиП (олимпиада)";
	GoToXY(30, y++);
	cout << "————————————————————————";
	GoToXY(33, y);
	cout << "| Физика (олимпиада)";

	y = 10;

	GoToXY(58, y++);
	if (clients[count].englishGradeOlimp > 0)
		cout << "|  " << clients[count].englishGradeOlimp;
	else cout << "|  -";

	GoToXY(50, y++);
	cout << "————————————————————————";

	GoToXY(58, y++);
	if (clients[count].mathGradeOlimp > 0)
		cout << "|  " << clients[count].mathGradeOlimp;
	else cout << "|  -";

	GoToXY(50, y++);
	cout << "————————————————————————";

	GoToXY(58, y++);
	if (clients[count].oaipGradeOlimp > 0)
		cout << "|  " << clients[count].oaipGradeOlimp;
	else cout << "|  -";

	GoToXY(50, y++);
	cout << "————————————————————————";

	GoToXY(58, y++);
	if (clients[count].oopGradeOlimp > 0)
		cout << "|  " << clients[count].oopGradeOlimp;
	else cout << "|  -";

	GoToXY(50, y++);
	cout << "————————————————————————";

	GoToXY(58, y);
	if (clients[count].physicsGradeOlimp > 0)
		cout << "|  " << clients[count].physicsGradeOlimp;
	else cout << "|  -";

	y = 10;

	GoToXY(64, y++);
	cout << "| Английский (лабораторные работы)";
	GoToXY(65, y++);
	cout << "————————————————————————————————————————————————";
	GoToXY(64, y++);
	cout << "| Математика (лабораторные работы)";
	GoToXY(65, y++);
	cout << "————————————————————————————————————————————————";
	GoToXY(64, y++);
	cout << "| ОАИП (лабораторные работы)";
	GoToXY(65, y++);
	cout << "————————————————————————————————————————————————";
	GoToXY(64, y++);
	cout << "| ООПиП (лабораторные работы)";
	GoToXY(65, y++);
	cout << "————————————————————————————————————————————————";
	GoToXY(64, y);
	cout << "| Физика (лабораторные работы)";

	y = 10;
	
	GoToXY(99, y++);
	if (clients[count].englishGradeLaba[0] > 0) {
		cout << "| ";
		int i = 0;
		while (clients[count].englishGradeLaba[i] > 0) {
			cout << clients[count].englishGradeLaba[i];
			if (clients[count].englishGradeLaba[++i] > 0)
				cout << ", ";
		}
	}
	else cout << "| -";

	GoToXY(105, y++);
	cout << "———————————————————————————————————";

	GoToXY(99, y++);
	if (clients[count].mathGradeLaba[0] > 0) {
		cout << "| ";
		int i = 0;
		while (clients[count].mathGradeLaba[i] > 0) {
			cout << clients[count].mathGradeLaba[i];
			if (clients[count].mathGradeLaba[++i] > 0)
				cout << ", ";
		}
	}
	else cout << "| -";

	GoToXY(105, y++);
	cout << "———————————————————————————————————";

	GoToXY(99, y++);
	if (clients[count].oaipGradeLaba[0] > 0) {
		cout << "| ";
		int i = 0;
		while (clients[count].oaipGradeLaba[i] > 0) {
			cout << clients[count].oaipGradeLaba[i];
			if (clients[count].oaipGradeLaba[++i] > 0)
				cout << ", ";
		}
	}
	else cout << "| -";

	GoToXY(105, y++);
	cout << "———————————————————————————————————";

	GoToXY(99, y++);
	if (clients[count].oopGradeLaba[0] > 0) {
		cout << "| ";
		int i = 0;
		while (clients[count].oopGradeLaba[i] > 0) {
			cout << clients[count].oopGradeLaba[i];
			if (clients[count].oopGradeLaba[++i] > 0)
				cout << ", ";
		}
	}
	else cout << "| -";

	GoToXY(105, y++);
	cout << "———————————————————————————————————";

	GoToXY(99, y);
	if (clients[count].physicsGradeLaba[0] > 0) {
		cout << "| ";
		int i = 0;
		while (clients[count].physicsGradeLaba[i] > 0) {
			cout << clients[count].physicsGradeLaba[i];
			if (clients[count].physicsGradeLaba[++i] > 0)
				cout << ", ";
		}
	}
	else cout << "| -";

	GoToXY(3, 19);
	for (int i = 0; i < 137; ++i) {
		cout << "—";
	}

	GoToXY(65, 21);
	pulsar();

	system("cls");
}

void studentPasses(int count) {

	system("cls");

	int y = 7, x = 60;

	GoToXY(x, y);
	cout << "Ф.И.О. : " << clients[count].name;
	GoToXY(100, y);
	cout << "Группа : " << clients[count].group;


	y = 10;

	GoToXY(75, y++);
	cout << "Предмет";
	GoToXY(74, y++);
	cout << "————————————————————————";
	GoToXY(75, y++);
	cout << "Английский";
	GoToXY(74, y++);
	cout << "————————————————————————";
	GoToXY(75, y++);
	cout << "Математика";
	GoToXY(74, y++);
	cout << "————————————————————————";
	GoToXY(75, y++);
	cout << "ОАИП";
	GoToXY(74, y++);
	cout << "————————————————————————";
	GoToXY(75, y++);
	cout << "ООПиП";
	GoToXY(74, y++);
	cout << "————————————————————————";
	GoToXY(75, y++);
	cout << "Физика";
	GoToXY(74, y);
	cout << "————————————————————————";

	y = 10;

	GoToXY(86, y);
	cout << "|  Пропуски";

	GoToXY(86, y+=2);
	cout << "|     " << clients[count].englishPasses;

	GoToXY(86, y+=2);
	cout << "|     " << clients[count].mathPasses;

	GoToXY(86, y+=2);
	cout << "|     " << clients[count].oaipPasses;

	GoToXY(86, y+=2);
	cout << "|     " << clients[count].oopPasses;

	GoToXY(86, y+=2);
	cout << "|     " << clients[count].physicsPasses;

	GoToXY(67, y+=3);
	pulsar();
	system("cls");
}


void outputPasses(int count) {

	if (teachers[count].subject == "english") {
		infoTablePasses();
		int y = 5;
		for (int i = 0; i < CountOfUsers; ++i, y += 2) {
			Passes(clients[i].englishPasses, clients[i].group, clients[i].name, clients[i].login, y, i);
		}
		GoToXY(62, y + 1);
		system("pause");
		system("cls");
	}
	else if (teachers[count].subject == "math") {
		infoTablePasses();
		int y = 5;
		for (int i = 0; i < CountOfUsers; ++i, y += 2) {
			Passes(clients[i].mathPasses, clients[i].group, clients[i].name, clients[i].login, y, i);
		}
		GoToXY(62, y + 1);
		system("pause");
		system("cls");
	}
	else if (teachers[count].subject == "oaip") {
		infoTablePasses();
		int y = 5;
		for (int i = 0; i < CountOfUsers; ++i, y += 2) {
			Passes(clients[i].oaipPasses, clients[i].group, clients[i].name, clients[i].login, y, i);
		}
		GoToXY(62, y + 1);
		system("pause");
		system("cls");
	}
	else if (teachers[count].subject == "oop") {
		infoTablePasses();
		int y = 5;
		for (int i = 0; i < CountOfUsers; ++i, y += 2) {
			Passes(clients[i].oopPasses, clients[i].group, clients[i].name, clients[i].login, y, i);
		}
		GoToXY(62, y + 1);
		system("pause");
		system("cls");
	}
	else {
		infoTablePasses();
		int y = 5;
		for (int i = 0; i < CountOfUsers; ++i, y += 2) {
			Passes(clients[i].physicsPasses, clients[i].group, clients[i].name, clients[i].login, y, i);
		}
		GoToXY(62, y + 1);
		system("pause");
		system("cls");
	}
}

void infoTablePasses() {
	int y = 3;

	system("cls");
	GoToXY(37, y);
	cout << "№";
	GoToXY(40, y);
	cout << " | Группа";
	GoToXY(50, y);
	cout << "| Ф.И.О.";
	GoToXY(80, y);
	cout << "| Логин";
	GoToXY(110, y);
	cout << "| Пропуски";
	GoToXY(35, y + 1);
	cout << "———————————————————————————————————————————————————————————————————————————————————————";
}

void Passes(int passes, int group, string name, string login, int y, int i) {

		GoToXY(37, y);
		cout << i + 1;
		GoToXY(40, y);
		cout << " | " << group;
		GoToXY(50, y);
		cout << "| " << name;
		GoToXY(80, y);
		cout << "| " << login;
		GoToXY(110, y);
		cout << "| " << passes;
		GoToXY(35, y + 1);
		cout << "———————————————————————————————————————————————————————————————————————————————————————";
}



void putUpPasses(int count) {
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
	cout << "——————————————————————————————————————————————————————————————";


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
	GoToXY(65, 20);
	cout << "Введите количество пропусков студента: ";
	int passes{};
	passes = checkNam(passes, 60, 20);
	
	if (teachers[count].subject == "english") {
		clients[choice].englishPasses = passes;
	}
	else if (teachers[count].subject == "math") {
		clients[choice].mathPasses = passes;
	}
	else if (teachers[count].subject == "oaip") {
		clients[choice].oaipPasses = passes;
	}
	else if (teachers[count].subject == "oop") {
		clients[choice].oopPasses = passes;
	}
	else {
		clients[choice].physicsPasses = passes;
	}
	system("cls");

	GoToXY(70, 20);
	cout << "Пропуски выставлены!";
	GoToXY(65, 22);
	pulsar();
	system("cls");
}

int checkNam(int num, int count, int y) {
	while (!(cin >> num) || num > count || num < 1) {
		cin.clear();
		cin.ignore(1024, '\n');
		GoToXY(65, y);
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "                                                                                    ";
		GoToXY(65, y);
		cout << "Неверное значение!";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		GoToXY(65, y);
		cout << "                                                                                    ";
		GoToXY(65, y);
		cout << "Введите количество пропусков студента: ";
	}
	return num;
}

int checkNum(int num, int count, int i) {
	GoToXY(89, 5);
	while (!(cin >> num) || num > count || num > i || num < 1) {
		string space = "                                        ";
		cin.clear();
		cin.ignore(1024, '\n');
		GoToXY(70, 5);
		SetConsoleTextAttribute(hStdOut, 4);
		cout << space;
		GoToXY(70, 5);
		cout << "Неверное значение! ";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		GoToXY(70, 5);
		cout << space;
		GoToXY(70, 5);
		cout << "Выберите студента:";
	}
	return num;
}

void gradesList(int count) {
	if (teachers[count].subject == "english") {
		englishGradesList();
	}
	else if (teachers[count].subject == "math") {
		mathGradesList();
	}
	else if (teachers[count].subject == "oaip") {
		oaipGradesList();
	}
	else if (teachers[count].subject == "oop") {
		oopGradesList();
	}
	else {
		physicsGradesList();
	}
}

void box() {
	system("cls");
	GoToXY(5, 14);
	cout << "| Группа";
	GoToXY(15, 14);
	cout << "| Ф.И.О.";
	GoToXY(50, 14);
	cout << "| Логин";
	GoToXY(75, 14);
	cout << "| Оценка за экзамен";
	GoToXY(100, 14);
	cout << "| Оценка за олимпиаду";
	GoToXY(125, 14);
	cout << "| Оценки за лабораторные работы";
	GoToXY(5, 15);
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————";
}



int recordEnglishStudentGrades(int count , int mark2, int mark1, int y) {
	if (!((clients[count].englishGradeExam >= mark1 && clients[count].englishGradeExam <= mark2) || ( clients[count].englishGradeOlimp >= mark1 && clients[count].englishGradeOlimp <= mark2 ) || (clients[count].englishGradeLaba[0] >= mark1 && clients[count].englishGradeLaba[0] <= mark2))) return 1;
	GoToXY(5, y);
	cout << "| " << clients[count].group;
	GoToXY(15, y);
	cout << "| " << clients[count].name;
	GoToXY(50, y);
	cout << "| " << clients[count].login;

	GoToXY(75, y);
	cout << "| ";
	if ((clients[count].englishGradeExam <= mark2 && clients[count].englishGradeExam >= mark1) && clients[count].englishGradeExam > 0) {
		cout << clients[count].englishGradeExam;
	}
	else {
		cout << "-";
	}

	GoToXY(100, y);
	cout << "|";
	if ((clients[count].englishGradeOlimp <= mark2 && clients[count].englishGradeOlimp >= mark1) && clients[count].englishGradeOlimp > 0) {
		cout << clients[count].englishGradeOlimp;
	}
	else {
		cout << "-";
	}

	GoToXY(125, y);
	cout << "| ";
	int x = 125;
	for (int i = 0; i < 50; ++i) {
		if (clients[count].englishGradeLaba[i] < 1) {
			cout << "-";
			break;
		}
		if (clients[count].englishGradeLaba[i] <= mark2 && clients[count].englishGradeLaba[i] >= mark1) {
			cout << clients[count].englishGradeLaba[i] << "  ";
		}
		else {
			cout << "-";
		}
	}
	GoToXY(5, ++y);
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————";
	return 0;
}

int checkRange(int range) {
	while (!(cin >> range) || range < 1 || range > 9) {
		cin.clear();
		cin.ignore(1024, '\n');
		GoToXY(70, 20);
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "Неверное значение!             ";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		GoToXY(70, 20);
		cout << "Введите левую границу: ";
	}
	return range;
}

int check_Range(int range) {
	while (!(cin >> range) || range < 2 || range > 10) {
		cin.clear();
		cin.ignore(1024, '\n');
		GoToXY(70, 22);
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "Неверное значение!             ";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		GoToXY(70, 22);
		cout << "Введите правую границу: ";
	}
	return range;
}

void englishGradesList() {
	system("cls");
	int firstRange{}, secondRange{};
	GoToXY(70, 20);
	cout << "Введите левую границу: ";
	firstRange = checkRange(firstRange);
	GoToXY(70, 22);
	cout << "Введите правую границу: ";
	secondRange = check_Range(secondRange);
	box();
	int countHighGrades = 0;
	int y = 16;
	for (int i = 0; i < CountOfUsers; ++i) {
		if (!recordEnglishStudentGrades(i, secondRange, firstRange, y)) {
			y += 2;
			++countHighGrades;
		}
	}
	if (!countHighGrades) {
		system("cls");
		GoToXY(65, 20);
		cout << "Студентов с оценками ниже заданной не обнаружено!";
	}
	GoToXY(66, 24);
	pulsar();
	system("cls");
}



int recordMathStudentGrades(int count, int mark2, int mark1, int y) {
	if (!((clients[count].mathGradeExam >= mark1 && clients[count].mathGradeExam <= mark2) || (clients[count].mathGradeOlimp >= mark1 && clients[count].mathGradeOlimp <= mark2) || (clients[count].mathGradeLaba[0] >= mark1 && clients[count].mathGradeLaba[0] <= mark2))) return 1;
	GoToXY(5, y);
	cout << "| " << clients[count].group;
	GoToXY(15, y);
	cout << "| " << clients[count].name;
	GoToXY(50, y);
	cout << "| " << clients[count].login;

	GoToXY(75, y);
	cout << "| ";
	if ((clients[count].mathGradeExam <= mark2 && clients[count].mathGradeExam >= mark1) && clients[count].mathGradeExam > 0) {
		cout << clients[count].mathGradeExam;
	}
	else if (clients[count].mathGradeExam < 1) {
		cout << "-";
	}

	GoToXY(100, y);
	cout << "|";
	if ((clients[count].mathGradeOlimp <= mark2 && clients[count].mathGradeOlimp >= mark1) && clients[count].mathGradeOlimp > 0) {
		cout << clients[count].mathGradeOlimp;
	}
	else if (clients[count].mathGradeOlimp < 1) {
		cout << "-";
	}

	GoToXY(125, y);
	cout << "| ";
	int x = 125;
	for (int i = 0; i < 50; ++i) {
		if (clients[count].mathGradeLaba[i] < 1) {
			cout << "-";
			break;
		}
		if (clients[count].mathGradeLaba[i] <= mark2 && clients[count].mathGradeLaba[i] >= mark1) {
			cout << clients[count].mathGradeLaba[i] << "  ";
		}
		else {
			cout << "-";
		}
	}
	GoToXY(5, ++y);
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————";
	return 0;
}

void mathGradesList() {
	system("cls");
	int firstRange{}, secondRange{};
	GoToXY(70, 20);
	cout << "Введите левую границу: ";
	firstRange = checkRange(firstRange);
	GoToXY(70, 22);
	cout << "Введите правую границу: ";
	secondRange = check_Range(secondRange);
	box();
	int countHighGrades = 0;
	int y = 16;
	for (int i = 0; i < CountOfUsers; ++i) {
		if (!recordMathStudentGrades(i, secondRange, firstRange, y)) {
			y += 2;
			++countHighGrades;
		}
	}
	if (!countHighGrades) {
		system("cls");
		GoToXY(65, 20);
		cout << "Студентов с оценками ниже заданной не обнаружено!";
	}
	GoToXY(66, 24);
	pulsar();
	system("cls");
}



int recordOaipStudentGrades(int count, int mark2, int mark1, int y) {
	if (!((clients[count].oaipGradeExam >= mark1 && clients[count].oaipGradeExam <= mark2) || (clients[count].oaipGradeOlimp >= mark1 && clients[count].oaipGradeOlimp <= mark2) || (clients[count].oaipGradeLaba[0] >= mark1 && clients[count].oaipGradeLaba[0] <= mark2))) return 1;
	GoToXY(5, y);
	cout << "| " << clients[count].group;
	GoToXY(15, y);
	cout << "| " << clients[count].name;
	GoToXY(50, y);
	cout << "| " << clients[count].login;

	GoToXY(75, y);
	cout << "| ";
	if ((clients[count].oaipGradeExam <= mark2 && clients[count].oaipGradeExam >= mark1) && clients[count].oaipGradeExam > 0) {
		cout << clients[count].oaipGradeExam;
	}
	else if (clients[count].oaipGradeExam < 1) {
		cout << "-";
	}

	GoToXY(100, y);
	cout << "|";
	if ((clients[count].oaipGradeOlimp <= mark2 && clients[count].oaipGradeOlimp >= mark1) && clients[count].oaipGradeOlimp > 0) {
		cout << clients[count].oaipGradeOlimp;
	}
	else if (clients[count].oaipGradeOlimp < 1) {
		cout << "-";
	}

	GoToXY(125, y);
	cout << "| ";
	int x = 125;
	for (int i = 0; i < 50; ++i) {
		if (clients[count].oaipGradeLaba[i] < 1) {
			cout << "-";
			break;
		}
		if (clients[count].oaipGradeLaba[i] <= mark2 && clients[count].oaipGradeLaba[i] >= mark1) {
			cout << clients[count].oaipGradeLaba[i] << "  ";
		}
		else {
			cout << "-";
		}
	}
	GoToXY(5, ++y);
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————";
	return 0;
}

void oaipGradesList() {
	system("cls");
	int firstRange{}, secondRange{};
	GoToXY(70, 20);
	cout << "Введите левую границу: ";
	firstRange = checkRange(firstRange);
	GoToXY(70, 22);
	cout << "Введите правую границу: ";
	secondRange = check_Range(secondRange);
	box();
	int countHighGrades = 0;
	int y = 16;
	for (int i = 0; i < CountOfUsers; ++i) {
		if (!recordOaipStudentGrades(i, secondRange, firstRange, y)) {
			y += 2;
			++countHighGrades;
		}
	}
	if (!countHighGrades) {
		system("cls");
		GoToXY(65, 20);
		cout << "Студентов с оценками ниже заданной не обнаружено!";
	}
	GoToXY(66, 24);
	pulsar();
	system("cls");
}



int recordOopStudentGrades(int count, int mark2, int mark1, int y) {
	if (!((clients[count].oopGradeExam >= mark1 && clients[count].oopGradeExam <= mark2) || (clients[count].oopGradeOlimp >= mark1 && clients[count].oopGradeOlimp <= mark2) || (clients[count].oopGradeLaba[0] >= mark1 && clients[count].oopGradeLaba[0] <= mark2))) return 1;
	GoToXY(5, y);
	cout << "| " << clients[count].group;
	GoToXY(15, y);
	cout << "| " << clients[count].name;
	GoToXY(50, y);
	cout << "| " << clients[count].login;

	GoToXY(75, y);
	cout << "| ";
	if ((clients[count].oopGradeExam <= mark2 && clients[count].oopGradeExam >= mark1) && clients[count].oopGradeExam > 0) {
		cout << clients[count].oopGradeExam;
	}
	else if (clients[count].oopGradeExam < 1) {
		cout << "-";
	}

	GoToXY(100, y);
	cout << "|";
	if ((clients[count].oopGradeOlimp <= mark2 && clients[count].oopGradeOlimp >= mark1) && clients[count].oopGradeOlimp > 0) {
		cout << clients[count].oopGradeOlimp;
	}
	else if (clients[count].oopGradeOlimp < 1) {
		cout << "-";
	}

	GoToXY(125, y);
	cout << "| ";
	int x = 125;
	for (int i = 0; i < 50; ++i) {
		if (clients[count].oopGradeLaba[i] < 1) {
			cout << "-";
			break;
		}
		if (clients[count].oopGradeLaba[i] <= mark2 && clients[count].oopGradeLaba[i] >= mark1) {
			cout << clients[count].oopGradeLaba[i] << "  ";
		}
		else {
			cout << "-";
		}
	}
	GoToXY(5, ++y);
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————";
	return 0;
}

void oopGradesList() {
	system("cls");
	int firstRange{}, secondRange{};
	GoToXY(70, 20);
	cout << "Введите левую границу: ";
	firstRange = checkRange(firstRange);
	GoToXY(70, 22);
	cout << "Введите правую границу: ";
	secondRange = check_Range(secondRange);
	box();
	int countHighGrades = 0;
	int y = 16;
	for (int i = 0; i < CountOfUsers; ++i) {
		if (!recordOopStudentGrades(i, secondRange, firstRange, y)) {
			y += 2;
			++countHighGrades;
		}
	}
	if (!countHighGrades) {
		system("cls");
		GoToXY(65, 20);
		cout << "Студентов с оценками ниже заданной не обнаружено!";
	}
	GoToXY(66, 24);
	pulsar();
	system("cls");
}


int recordPhysicsStudentGrades(int count, int mark2, int mark1, int y) {
	if (!((clients[count].physicsGradeExam >= mark1 && clients[count].physicsGradeExam <= mark2) || (clients[count].physicsGradeOlimp >= mark1 && clients[count].physicsGradeOlimp <= mark2) || (clients[count].physicsGradeLaba[0] >= mark1 && clients[count].physicsGradeLaba[0] <= mark2))) return 1;
	GoToXY(5, y);
	cout << "| " << clients[count].group;
	GoToXY(15, y);
	cout << "| " << clients[count].name;
	GoToXY(50, y);
	cout << "| " << clients[count].login;

	GoToXY(75, y);
	cout << "| ";
	if ((clients[count].physicsGradeExam <= mark2 && clients[count].physicsGradeExam >= mark1) && clients[count].physicsGradeExam > 0) {
		cout << clients[count].physicsGradeExam;
	}
	else if (clients[count].physicsGradeExam < 1) {
		cout << "-";
	}

	GoToXY(100, y);
	cout << "|";
	if ((clients[count].physicsGradeOlimp <= mark2 && clients[count].physicsGradeOlimp >= mark1) && clients[count].physicsGradeOlimp > 0) {
		cout << clients[count].physicsGradeOlimp;
	}
	else if (clients[count].physicsGradeOlimp < 1) {
		cout << "-";
	}

	GoToXY(125, y);
	cout << "| ";
	int x = 125;
	for (int i = 0; i < 50; ++i) {
		if (clients[count].physicsGradeLaba[i] < 1) {
			cout << "-";
			break;
		}
		if (clients[count].physicsGradeLaba[i] <= mark2 && clients[count].physicsGradeLaba[i] >= mark1) {
			cout << clients[count].physicsGradeLaba[i] << "  ";
		}
		else {
			cout << "-";
		}
	}
	GoToXY(5, ++y);
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————";
	return 0;
}

void physicsGradesList() {
	system("cls");
	int firstRange{}, secondRange{};
	GoToXY(70, 20);
	cout << "Введите левую границу: ";
	firstRange = checkRange(firstRange);
	GoToXY(70, 22);
	cout << "Введите правую границу: ";
	secondRange = check_Range(secondRange);
	box();
	int countHighGrades = 0;
	int y = 16;
	for (int i = 0; i < CountOfUsers; ++i) {
		if (!recordPhysicsStudentGrades(i, secondRange, firstRange, y)) {
			y += 2;
			++countHighGrades;
		}
	}
	if (!countHighGrades) {
		system("cls");
		GoToXY(65, 20);
		cout << "Студентов с оценками ниже заданной не обнаружено!";
	}
	GoToXY(66, 24);
	pulsar();
	system("cls");
}



int choiceTable(int y) {
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
	cout << "——————————————————————————————————————————————————————————————";
	return y;
}

void rateExam(int count) {
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

	if (teachers[count].subject == "english") {
		rate_Exam(choice, &clients[choice].englishGradeExam);
	}
	else if (teachers[count].subject == "math") {
		rate_Exam(choice, &clients[choice].mathGradeExam);
	}
	else if (teachers[count].subject == "oaip") {
		rate_Exam(choice, &clients[choice].oaipGradeExam);
	}
	else if (teachers[count].subject == "oop") {
		rate_Exam(choice, &clients[choice].oopGradeExam);
	}
	else {
		rate_Exam(choice, &clients[choice].physicsGradeExam);
	}

}

void rate_Exam(int count, int *grade) {
	system("cls");
	if (*grade <= 10 && *grade >= 1) {
		GoToXY(70, 20);
		cout << "Оценка данному студенту уже выставлена!";
		GoToXY(65, 22);
		pulsar();
		system("cls");
		return;
	}
	int mark{};
	mark = CheckNumber(mark);
	*grade = mark;
	GoToXY(70, 22);
	cout << "Отметка выставлена!";

	GoToXY(62, 24);
	pulsar();
	system("cls");
}



void rateOlimp(int count) {
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

	if (teachers[count].subject == "english") {
		rate_Olimp(choice, &clients[choice].englishGradeOlimp);
	}
	else if (teachers[count].subject == "math") {
		rate_Olimp(choice, &clients[choice].mathGradeOlimp);
	}
	else if (teachers[count].subject == "oaip") {
		rate_Olimp(choice, &clients[choice].oaipGradeOlimp);
	}
	else if (teachers[count].subject == "oop") {
		rate_Olimp(choice, &clients[choice].oopGradeOlimp);
	}
	else {
		rate_Olimp(choice, &clients[choice].physicsGradeOlimp);
	}

}

void rate_Olimp(int count, int *grade) {
	system("cls");
	if (*grade <= 10 && *grade >= 1) {
		GoToXY(70, 20);
		cout << "Оценка данному студенту уже выставлена!";
		GoToXY(65, 22);
		pulsar();
		system("cls");
		return;
	}
	int mark{};
	mark = CheckNumber(mark);
	*grade = mark;
	GoToXY(70, 22);
	cout << "Отметка выставлена!";

	GoToXY(62, 24);
	pulsar();
	system("cls");
}




void rateLaba(int count) {
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

	if (teachers[count].subject == "english") {
		rate_Laba(choice, clients[choice].englishGradeLaba);
	}
	else if (teachers[count].subject == "math") {
		rate_Laba(choice, clients[choice].mathGradeLaba);
	}
	else if (teachers[count].subject == "oaip") {
		rate_Laba(choice, clients[choice].oaipGradeLaba);
	}
	else if (teachers[count].subject == "oop") {
		rate_Laba(choice, clients[choice].oopGradeLaba);
	}
	else {
		rate_Laba(choice, clients[choice].physicsGradeLaba);
	}

}

void rate_Laba(int count, int *grade) {
	system("cls");

	int i = 0;
	for (i; i < 50; ++i) {
		if (grade[i] < 1) {
			break;
		}
	}


	string Menu[] = { "Выставить отметку", "Назад" };

	int active_menu = 0;// будем бегать по меню изменяя эту переменную

	int mark{};
	mark = CheckNumber(mark);

	while (1)
	{

		if (i >= 45) {
			GoToXY(65, 20);
			cout << "Превышен лимит количества оценок по лабораторным работам!";
			GoToXY(70, 22);
			pulsar();
			system("cls");
			return;
		}

		int x = 67, y = 22;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, y);
			cout << Menu[i] << endl;
			x += 20;
		}

		char ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			return;
		case LEFT:
			if (active_menu > 0) {
				--active_menu;
			}
			break;
		case RIGHT:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 0: 
				system("cls");
				grade[i] = mark;
				GoToXY(70, 22);
				cout << "Отметка выставлена!";
				++i;
				GoToXY(65, 22);
				pulsar();
				system("cls");
				rate_Laba(i, grade);
				return;
			case 1:
				system("cls");
				return;
			}
			break;
		default:
			break;
		}
	}
}



bool checkAccounts(string login) {
	for (int i = 0; i < CountOfProfessors; ++i) {
		if (login == teachers[i].login) {
			system("cls");
			GoToXY(70, 20);
			cout << "Пользователь с таким логином уже зарегистрирован!";
			_getch();
			system("cls");
			return true;
		}
	}
	for (int i = 0; i < CountOfUsers; ++i) {
		if (login == clients[i].login) {
			system("cls");
			GoToXY(70, 20);
			cout << "Пользователь с таким логином уже зарегистрирован!";
			_getch();
			system("cls");
			return true;
		}
	}
	return false;
}

int Registration(int i) {

	string login, password;
	bool check{}, check1{}, check2{};
	do {
		GoToXY(70, 19);
		cout << "———————————————————— Регистрация ————————————————————" << endl;

		GoToXY(70, 26);
		cout << "—————————————————————————————————————————————————————" << endl;

		GoToXY(75, 21);// определяем курсор в точку х, у (центр экрана примерно)
		cout << "Введите логин: ";


		getline(cin, login); // ПРОВЕРКА
		check = checkLogin(login);
		if (!check) {
			check1 = checkAccounts(login);
		}

		if (!check && !check1) {
			GoToXY(75, 22);
			cout << "Введите пароль: ";
			password = passwordEntering();
			check2 = checkPassword(password);
		}
	} while (check || check1 || check2);



	string Menu[] = { "Зарегистрироваться", "Ввести ключ", "Назад" };

	int active_menu = 0;// будем бегать по меню изменяя эту переменную

	while (1)
	{
		int x = 75, y = 24;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, y);
			if (i == 0) {
				cout << Menu[i] << endl;
				x += 21;
			}
			if (i == 1) {
				cout << Menu[i] << endl;
				x += 14;
			}
			if (i == 2) {
				cout << Menu[i] << endl;
			}
		}

		char ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			SetConsoleTextAttribute(hStdOut, 7);
			return 2;
		case LEFT:
			if (active_menu > 0) {
				--active_menu;
			}
			break;
		case RIGHT:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 0:
				regStudent(login, password);
				return i;
			case 1: {
				system("cls");
				GoToXY(70, 20);
				cout << "Введите ключ: ";
				string key;
				key = passwordEntering();
					if (key == professorKey) {
					++i;
					regProfessor(login, password);
				}
				else {
					system("cls");
					GoToXY(75, 22);
					cout << "Ключи не совпадают!";
					i = 2;
					_getch();
				}
				return i;
			}
			case 2:
				return x;
			}
			break;
		default:
			break;
		}
	}
}

string passwordEntering() {

	char ch{};
	int j = 0;
	char asciiChar[50]{};

	while (ch != 13) {
		ch = _getch();
		if (ch == 8 && j == 0) {
			//ниче не делаем
		}
		else if (ch == 13) {
			break;
		}
		else if (ch == 8 && j > 0) {
			cout << "\b\b ";
			--j;
			asciiChar[j] = '\0';
		}
		else if (j >= 0) {
			cout << "\b* ";
			int asciiVal = ch;
			asciiChar[j] = static_cast<char>(asciiVal); // получаем символ из кода символа
			++j;
		}

	}
	string password(asciiChar);
	return password;
}

void regStudent(string login, string password) {
	system("cls");
	string name;
	do {
		GoToXY(70, 20);
		cout << "Введите своё Ф.И.О. : ";
		getline(cin, name);
	} while (checkName(name));

	int group{};
	GoToXY(70, 22);
	cout << "Введите номер своей группы: ";
	group = checkGroup(group);

	//ofstream funcUserOut;
	//funcUserOut.open("students.txt", ios::app);
	system("cls");
	Loading();
	system("cls");
	GoToXY(75, 20);
	cout << "Вы успешно зарегистрированы!";
	clients[CountOfUsers].login = login;
	clients[CountOfUsers].password = password;
	clients[CountOfUsers].group = group;
	clients[CountOfUsers].name = name;
	++CountOfUsers;
	Sleep(800);
}

bool checkName(string name) {

	if (size(name) < 3) {
		system("cls");
		GoToXY(70, 20);
		cout << "Слишком короткое имя!";
		GoToXY(65, 22);
		pulsar();
		system("cls");
		return true;
	}

	for (int i = 0; i < size(name); ++i) {
		if (name[i] == '0' || name[i] == '1' || name[i] == '2' || name[i] == '3' || name[i] == '4'
			|| name[i] == '5' || name[i] == '6' || name[i] == '7' || name[i] == '8' || name[i] == '9'
			|| name[i] == '0' || name[i] == '1' || name[i] == '0' || name[i] == '1' || name[i] == '0'
			|| name[i] == '~' || name[i] == '!' || name[i] == '@' || name[i] == '#' || name[i] == '$'
			|| name[i] == '(' || name[i] == '*' || name[i] == '&' || name[i] == '^' || name[i] == '%'
			|| name[i] == ')' || name[i] == '=' || name[i] == '+' || name[i] == '-' || name[i] == '?'
			|| name[i] == '>' || name[i] == '<' || name[i] == '№' || name[i] == '\"' || name[i] == '\''
			|| name[i] == ']' || name[i] == '[' || name[i] == '}' || name[i] == '{' || name[i] == ','
			|| name[i] == '.' || name[i] == '/' || name[i] == '`' || name[i] == 'q' ||  name[i] == 'w'
			|| name[i] == 'e' || name[i] == 'r' || name[i] == 't' || name[i] == 'y' || name[i] == 'u'
			|| name[i] == 'i' || name[i] == 'o' || name[i] == 'p' || name[i] == 'a' || name[i] == 's'
			|| name[i] == 'd' || name[i] == 'f' || name[i] == 'g' || name[i] == 'h' || name[i] == 'j'
			|| name[i] == 'k' || name[i] == 'l' || name[i] == 'z' || name[i] == 'x' || name[i] == 'c'
			|| name[i] == 'v' || name[i] == 'b' || name[i] == 'n' || name[i] == 'm' || size(name) < 3 || size(name) > 25)  {
			system("cls");
			GoToXY(70, 20);
			cout << "Недопустимые символы!";
			GoToXY(65, 22);
			pulsar();
			system("cls");
			return true;
		}
	}

	if (name[0] == 'а' || name[0] == 'й'
		|| name[0] == 'ц' || name[0] == 'х' || name[0] == 'ъ' || name[0] == 'y' || name[0] == 'u'
		|| name[0] == 'у' || name[0] == 'з' || name[0] == 'ф' || name[0] == 'ы' || name[0] == 'в'
		|| name[0] == 'к' || name[0] == 'щ' || name[0] == 'д' || name[0] == 'л' || name[0] == 'п'
		|| name[0] == 'е' || name[0] == 'ш' || name[0] == 'ж' || name[0] == 'о' || name[0] == 'р'
		|| name[0] == 'н' || name[0] == 'г' || name[0] == 'э' || name[0] == 'я' || name[0] == 'ч'
		|| name[0] == 'с' || name[0] == 'м' || name[0] == 'ю' || name[0] == 'б' || name[0] == 'ь'
		|| name[0] == 'т' || name[0] == 'и' || name[0] == 'ё') {
		system("cls");
		GoToXY(65, 20);
		cout << "Ф.И.О. должно начинаться с больших букв (лишние пробелы не допустимы)!";
		GoToXY(65, 22);
		pulsar();
		system("cls");
		return true;
	}

	int capsLetters = 0, spaces = 0;
	for (int i = 0; i < size(name); ++i) {
		if (name[i] == 'А' || name[i] == 'Й'
			|| name[i] == 'Ц' || name[i] == 'Х' || name[i] == 'Ъ' || name[i] == 'У'
			|| name[i] == 'У' || name[i] == 'З' || name[i] == 'Ф' || name[i] == 'Ы' || name[i] == 'В'
			|| name[i] == 'К' || name[i] == 'Щ' || name[i] == 'Д' || name[i] == 'Л' || name[i] == 'П'
			|| name[i] == 'Е' || name[i] == 'Ш' || name[i] == 'Ж' || name[i] == 'О' || name[i] == 'Р'
			|| name[i] == 'Н' || name[i] == 'Г' || name[i] == 'Э' || name[i] == 'Я' || name[i] == 'Ч'
			|| name[i] == 'С' || name[i] == 'М' || name[i] == 'Ю' || name[i] == 'Б' || name[i] == 'Ь'
			|| name[i] == 'Т' || name[i] == 'И' || name[i] == 'Ё') {
			++capsLetters;
		}
		if (name[i] == ' ') {
			++spaces;
		}
	}

	if (capsLetters != spaces + 1 && name[size(name) - 1] != ' ') {
		system("cls");
		GoToXY(65, 20);
		cout << "В Ф.И.О. не должно быть заглавных букв, где это не требуется!";
		GoToXY(70, 22);
		pulsar();
		system("cls");
		return true;
	}

	for (int i = 0; i < size(name); ++i) {
		if (name[i++] == ' ') {
			if (name[i] == 'а' || name[i] == 'й'
				|| name[i] == 'ц' || name[i] == 'х' || name[i] == 'ъ' || name[i] == 'y'
				|| name[i] == 'у' || name[i] == 'з' || name[i] == 'ф' || name[i] == 'ы' || name[i] == 'в'
				|| name[i] == 'к' || name[i] == 'щ' || name[i] == 'д' || name[i] == 'л' || name[i] == 'п'
				|| name[i] == 'е' || name[i] == 'ш' || name[i] == 'ж' || name[i] == 'о' || name[i] == 'р'
				|| name[i] == 'н' || name[i] == 'г' || name[i] == 'э' || name[i] == 'я' || name[i] == 'ч'
				|| name[i] == 'с' || name[i] == 'м' || name[i] == 'ю' || name[i] == 'б' || name[i] == 'ь'
				|| name[i] == 'т' || name[i] == 'и' || name[i] == 'ё') {
				system("cls");
				GoToXY(65, 20);
				cout << "Ф.И.О. должно начинаться с больших букв!";
				GoToXY(65, 22);
				pulsar();				system("cls");
				return true;
			}
		}
	}
	return false;
}

void regProfessor(string login, string password) {
	system("cls");
	GoToXY(75, 20);
	cout << "Ключ введен успешно!";
	Sleep(800);



	system("cls");
	string name;
	do {
		GoToXY(70, 20);
		cout << "Введите своё Ф.И.О. : ";
		getline(cin, name);
	} while (checkName(name));

	teachers[CountOfProfessors].name = name;

	teachers[CountOfProfessors].login = login;
	teachers[CountOfProfessors].password = password;

	system("cls");

	string Menu[] = { "Физика", "Английский язык", "Математический анализ", "Основы алгоритмизации и программирования", "Объектно ориентированное проектирование и программирование"};
	int active_menu = 0;

	char ch;
	while (1)
	{
		int x = 55, y = 20;
		GoToXY(50, y - 1);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————— Выберите предмет —————————————————————————" << endl;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			if (i == 0) {
				GoToXY(77, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 1) {
				GoToXY(73, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 2) {
				GoToXY(70, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 3) {
				GoToXY(62, ++y);
				cout << Menu[i] << endl;
			}
			if (i == 4) {
				GoToXY(x, ++y);
				cout << Menu[i] << endl;
			}
		}

		GoToXY(50, y + 2);
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "————————————————————————————————————————————————————————————————————" << endl;

		ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
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
			case 0: {
				teachers[CountOfProfessors].subject = "physics";
				recordData();
				return;
			}
			case 1:
				teachers[CountOfProfessors].subject = "english";
				recordData();
				return;
			case 2:
				teachers[CountOfProfessors].subject = "math";
				recordData();
				return;
			case 3:
				teachers[CountOfProfessors].subject = "oaip";
				recordData();
				return;
			case 4:
				teachers[CountOfProfessors].subject = "oop";
				recordData();
				return;
			}
			break;
		default:
			break;
		}
	}

}

void recordData() {

	++CountOfProfessors;
	Loading();
	system("cls");
	GoToXY(75, 20);
	cout << "Вы успешно зарегистрированы!";
	Sleep(800);
}

bool CheckUsers(string login, string password) { // ПЕРЕДЕЛАТЬ
		system("cls");
		string adminLogin = "admin", adminPassword = "admin123";
		if (login == adminLogin && password == adminPassword) {
			//
		}
		GoToXY(50, 20);
		cout << "Вы являетесь первым пользователем, вам будут предоставлены права администратора!";
		GoToXY(65, 20);
		
		string path = "admins.txt";
		ofstream funcAdminOut;
		funcAdminOut.open(path);
		_getch();
		system("cls");
		return login == adminLogin && password == adminPassword;
}

string PressmarkFunc(string str) {
	for (int i = 0; i < size(str); ++i) {
		++str[i];
	}
	return str;
}


void Autorization() {

	string login;// ПРОВЕРКА +

	int check = 1;
	GoToXY(70, 20);
	cout << "—————————————— Авторизация ——————————————" << endl;

	GoToXY(70, 27);
	cout << "—————————————————————————————————————————" << endl;
	GoToXY(75, 22);

	cout << "Введите логин: ";
	string temp;
	getline(cin, temp);
	if (temp == "") getline(cin, login); // ПРОВЕРКА +
	else login = temp;

	GoToXY(75, 23);// определяем курсор в точку х, у (центр экрана примерно)
	cout << "Введите пароль: ";
	string password = passwordEntering();

	AutorizationKursor(login, password);

}

bool checkLogin(string login) {
	if (size(login) < 5 || size(login) > 20) {
		system("cls");
		GoToXY(70, 20);
		cout << "Логин должен состоять минимум из 5 и максимум из 20 символов!";
		_getch();
		system("cls");
		return true;
	}
	for (int i = 0; i < size(login); ++i) {
		if (login[i] == '~' || login[i] == '!' || login[i] == '@' || login[i] == '#' || login[i] == '$' || login[i] == '%' ||
			login[i] == '^' || login[i] == '&' || login[i] == '*' || login[i] == '(' || login[i] == ')' || login[i] == '-' ||
			login[i] == '+' || login[i] == '=' || login[i] == '>' || login[i] == '<' || login[i] == '/' || login[i] == '|' ||
			login[i] == ',' || login[i] == '\'' || login[i] == '[' || login[i] == ']' || login[i] == '{' || login[i] == '}' ||
			login[i] == ':' || login[i] == ';' || login[i] == '\\' || login[i] == '?' || login[i] == ' ') {
			system("cls");
			GoToXY(55, 20);
			cout << "Доступны только следующие спец. символы: _ (нижнее подчеркивание)  . (точка)";
			GoToXY(70, 22);
			pulsar();
			system("cls");
			return true;
		}
		if (login[i] == 'а' || login[i] == 'й'
			|| login[i] == 'ц' || login[i] == 'х' || login[i] == 'ъ'
			|| login[i] == 'у' || login[i] == 'з' || login[i] == 'ф' || login[i] == 'ы' || login[i] == 'в'
			|| login[i] == 'к' || login[i] == 'щ' || login[i] == 'д' || login[i] == 'л' || login[i] == 'п'
			|| login[i] == 'е' || login[i] == 'ш' || login[i] == 'ж' || login[i] == 'о' || login[i] == 'р'
			|| login[i] == 'н' || login[i] == 'г' || login[i] == 'э' || login[i] == 'я' || login[i] == 'ч'
			|| login[i] == 'с' || login[i] == 'м' || login[i] == 'ю' || login[i] == 'б' || login[i] == 'ь'
			|| login[i] == 'т' || login[i] == 'и' || login[i] == 'ё') {
			system("cls");
			GoToXY(70, 20);
			cout << "Логин не должен состоять из букв русского алфавита!";
			GoToXY(75, 22);
			pulsar();
			system("cls");
			return true;
		}
	}
	return false;
}

bool checkPassword(string str) {
	for (int i = 0; i < size(str); ++i) {
		if (str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == '&'
			|| str[i] == '?' || str[i] == '%' || str[i] == '?' || str[i] == '%'
			|| str[i] == '@' || str[i] == '#' || str[i] == '№' || str[i] == '$'
			|| str[i] == '\\' || str[i] == '/') {
			system("cls");
			GoToXY(68, 22);
			cout << "Вы ввели запрещенный символ!";
			_getch();
			system("cls");
			return true;
		}
		if (str[i] == 'а' || str[i] == 'й'
			|| str[i] == 'ц' || str[i] == 'х' || str[i] == 'ъ'
			|| str[i] == 'у' || str[i] == 'з' || str[i] == 'ф' || str[i] == 'ы' || str[i] == 'в'
			|| str[i] == 'к' || str[i] == 'щ' || str[i] == 'д' || str[i] == 'л' || str[i] == 'п'
			|| str[i] == 'е' || str[i] == 'ш' || str[i] == 'ж' || str[i] == 'о' || str[i] == 'р'
			|| str[i] == 'н' || str[i] == 'г' || str[i] == 'э' || str[i] == 'я' || str[i] == 'ч'
			|| str[i] == 'с' || str[i] == 'м' || str[i] == 'ю' || str[i] == 'б' || str[i] == 'ь'
			|| str[i] == 'т' || str[i] == 'и' || str[i] == 'ё') {
			system("cls");
			GoToXY(70, 20);
			cout << "Пароль не должен состоять из букв русского алфавита!";
			GoToXY(75, 22);
			pulsar();
			system("cls");
			return true;
		}
	}
	if (size(str) < 5) {
		system("cls");
		GoToXY(68, 22);
		cout << "Вы ввели слишком короткий пароль!";
		_getch();
		system("cls");
		return true;
	}
	return false;
}

void AutorizationKursor(string login, string password) {
	string Menu[] = { "Авторизоваться", "Назад" };

	int active_menu = 0;// будем бегать по меню изменяя эту переменную

	while (1)
	{
		int x = 75, y = 25;

		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active_menu) 	SetConsoleTextAttribute(hStdOut, 6);
			else 	SetConsoleTextAttribute(hStdOut, 7);

			GoToXY(x, y);
			cout << Menu[i] << endl;
			x += 20;
		}

		char ch = _getch(); //код нажатой клавиши
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки (2 байтовые)
		switch (ch)
		{
		case ESCAPE:
			SetConsoleTextAttribute(hStdOut, 7);
			return;
		case LEFT:
			if (active_menu > 0) {
				--active_menu;
			}
			break;
		case RIGHT:
			if (active_menu < size(Menu) - 1) {
				++active_menu;
			}
			break;
		case SPACE:
			switch (active_menu)
			{
			case 0:
				if (!CheckAutorization(login, password)) {
					system("cls");
					GoToXY(75, 20);
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "В системе нет такого пользователя!";
					SetConsoleTextAttribute(hStdOut, 7);
					_getch();
				}
				return;
			case 1:
				return;
			}
			break;
		default:
			break;
		}
	}
}

bool CheckAutorization(string login, string password) {

	//проверяем логин и пароль студента
	for (int i = 0; i <= CountOfUsers; ++i) {
		if (login == clients[i].login && password == clients[i].password) {
			system("cls");
			GoToXY(75, 20);
			cout << "Добро пожаловать, " << clients[i].name << "!";
			Sleep(1050);
			MainStudentMenu(i);
			return true;
		}
		if (login == clients[i].login && password != clients[i].password) {
			system("cls");
			GoToXY(75, 20);
			cout << "Пароль введен неверно!";
			GoToXY(67, 22);
			pulsar();
			return true;
		}
	}

	// проверяем логин и пароль препода
	for (int i = 0; i <= CountOfProfessors; ++i) {
		if (login == teachers[i].login && password == teachers[i].password) {
			system("cls");
			GoToXY(75, 20);
			cout << "Добро пожаловать, " << teachers[i].name << "!";
			_getch();
			MainProfessorMenu(i);
			return true;
		}
		if (login == teachers[i].login && password != teachers[i].password) {
			system("cls");
			GoToXY(75, 20);
			cout << "Пароль введен неверно!";
			_getch();
			system("cls");
			return true;
		}
	}

	//проверяем логин и пароль админа
	if (login == adminLogin && password == adminPassword) {
		system("cls");
		GoToXY(75, 20);
		cout << "Добро пожаловать, администратор!";
		_getch();
		MainAdminMenu();
		return true;
	}

	return false;
}


void GoToXY(short x, short y){
	SetConsoleCursorPosition(hStdOut, { x, y });
}

int CheckNumber(int text) {
	GoToXY(70, 20);
	cout << "Введите отметку: ";
	while (!(cin >> text) || text < 1 || text > 10) {
		cin.clear();
		cin.ignore(1024, '\n');
		system("cls");
		GoToXY(75, 20);
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "Неверное значение!";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		system("cls");
		GoToXY(70, 20);
		cout << "Введите отметку: ";
	}
	return text;
}

void Loading() {
	system("cls");
	GoToXY(80, 20);

	cout << "Загрузка";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Sleep(100);
			cout << ".";
		}
		Sleep(100);// задержка вывода в консоль
		cout << "\b\b\b ";//вставляет пробел вместо опред. символа
		Sleep(100);
		cout << " ";
		Sleep(100);
		cout << "  ";
		cout << "\b\b\b\b";
	}

	system("cls");
	GoToXY(80, 20);
	string a = "Успешно!";

	for (int i = 0; a[i] != '\0'; ++i) {
		cout << a[i];
		Sleep(100);
	}

	Sleep(800);
	system("cls");
}

int checkGroup(int group) {
	while (!(cin >> group) || group > 999999 || group < 100000) {
		cin.clear();
		cin.ignore(1024, '\n');
		GoToXY(70, 22);
		SetConsoleTextAttribute(hStdOut, 4);
		cout << "Номер группы должен состоять из 6 цифр!";
		SetConsoleTextAttribute(hStdOut, 7);
		_getch();
		GoToXY(70, 22);
		cout << "                                        ";
		GoToXY(70, 22);
		cout << "Введите номер своей группы: ";
	}
	return group;
}

void sortNoutput() {
	system("cls");

	Users newArray[100];
	for (int i = 0; i < CountOfUsers; ++i) {
		newArray[i] = clients[i];
	}

	// shell
	Users temp;
	int gap;
	for (gap = CountOfUsers / 2; gap > 0; gap /= 2) {
		int i, j, sorted;
		do
		{
			sorted = 0;
			for (i = 0, j = gap; j < CountOfUsers; i++, j++)
				if (newArray[i].averageGrade < newArray[j].averageGrade)
				{
					temp = newArray[i];
					newArray[i] = newArray[j];
					newArray[j] = temp;
					sorted = 1;
				}
		} while (sorted);
	}

	int y = 6;
	GoToXY(45, y);
	cout << "| Топ";
	GoToXY(52, y);
	cout << "| Группа";
	GoToXY(62, y);
	cout << "| Ф.И.О.";
	GoToXY(92, y);
	cout << "| Логин";
	GoToXY(117, y);
	cout << "| Средняя отметка";
	GoToXY(45, y + 1);
	cout << "——————————————————————————————————————————————————————————————————————————————————————————";

	y = 8;
	for (int i = 0; i < 10 && newArray[i].group > 100000 && newArray[i].group < 999999 && newArray[i].averageGrade > 0; ++i, y += 2) {
		GoToXY(45, y);
		cout << "| " << i + 1;
		GoToXY(52, y);
		cout << "| " << newArray[i].group;
		GoToXY(62, y);
		cout << "| " << newArray[i].name;
		GoToXY(92, y);
		cout << "| " << newArray[i].login;
		GoToXY(117, y);
		cout.precision(3);
		cout << "| " << newArray[i].averageGrade;
		GoToXY(45, y + 1);
		cout << "——————————————————————————————————————————————————————————————————————————————————————————";
	}

	GoToXY(70, y + 1);
	system("pause");
	system("cls");
}

void topStudents() {
	averageGrade();
	sortNoutput();
}

void averageGrade() {
	for (int i = 0; i < CountOfUsers; ++i) {
		clients[i].averageGrade = 0;

		int marksCount = 0;
		if (clients[i].englishGradeExam != 0) {
			clients[i].averageGrade += clients[i].englishGradeExam;
			++marksCount;
		}
		if (clients[i].englishGradeOlimp != 0) {
			clients[i].averageGrade += clients[i].englishGradeOlimp;
			++marksCount;
		}
		if (clients[i].mathGradeExam != 0) {
			clients[i].averageGrade += clients[i].mathGradeExam;
			++marksCount;
		}
		if (clients[i].mathGradeOlimp != 0) {
			clients[i].averageGrade += clients[i].mathGradeOlimp;
			++marksCount;
		}
		if (clients[i].oaipGradeExam != 0) {
			clients[i].averageGrade += clients[i].oaipGradeExam;
			++marksCount;
		}
		if (clients[i].oaipGradeOlimp != 0) {
			clients[i].averageGrade += clients[i].oaipGradeOlimp;
			++marksCount;
		}
		if (clients[i].oopGradeExam != 0) {
			clients[i].averageGrade += clients[i].oopGradeExam;
			++marksCount;
		}
		if (clients[i].oopGradeOlimp != 0) {
			clients[i].averageGrade += clients[i].oopGradeOlimp;
			++marksCount;
		}
		if (clients[i].physicsGradeExam != 0) {
			clients[i].averageGrade += clients[i].physicsGradeExam;
			++marksCount;
		}
		if (clients[i].physicsGradeOlimp != 0) {
			clients[i].averageGrade += clients[i].physicsGradeOlimp;
			++marksCount;
		}
		int j = 0;
		while (clients[i].englishGradeLaba[j] != 0) {
			clients[i].averageGrade += clients[i].englishGradeLaba[j];
			++j;
			++marksCount;
		}
		j = 0;
		while (clients[i].mathGradeLaba[j] != 0) {
			clients[i].averageGrade += clients[i].mathGradeLaba[j];
			++j;
			++marksCount;
		}
		j = 0;
		while (clients[i].oaipGradeLaba[j] != 0) {
			clients[i].averageGrade += clients[i].oaipGradeLaba[j];
			++j;
			++marksCount;
		}
		j = 0;
		while (clients[i].oopGradeLaba[j] != 0) {
			clients[i].averageGrade += clients[i].oopGradeLaba[j];
			++j;
			++marksCount;
		}
		j = 0;
		while (clients[i].physicsGradeLaba[j] != 0) {
			clients[i].averageGrade += clients[i].physicsGradeLaba[j];
			++j;
			++marksCount;
		}
		if (marksCount == 0) clients[i].averageGrade = 0;
		else clients[i].averageGrade /= marksCount;
	}
}

void pulsar() {
	SetConsoleTextAttribute(hStdOut, 8);
	cout << "Для продолжения нажмите любую клавишу ";
	while (1) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				Sleep(200);
				cout << ".";
				if (_kbhit()) {
					SetConsoleTextAttribute(hStdOut, 7);
					_getch();
					system("cls");
					return;
				}
			}
			Sleep(200);// задержка вывода в консоль
			cout << "\b\b\b ";//вставляет пробел вместо опред. символа
			Sleep(200);
			cout << " ";
			Sleep(200);
			cout << "  ";
			cout << "\b\b\b\b";
			if (_kbhit()) {
				SetConsoleTextAttribute(hStdOut, 7);
				_getch();
				system("cls");
				return;
			}
		}
		if (_kbhit()) {
			SetConsoleTextAttribute(hStdOut, 7);
			_getch();
			system("cls");
			return;
		}
	}
}

bool studentsCount() {
	if (CountOfUsers == 0) {
		system("cls");
		GoToXY(65, 20);
		cout << "В системе не обнаружено ни одного пользователя";
		GoToXY(75, 22);
		cout << "Операция невозможна!";
		GoToXY(70, 24);
		pulsar();
		system("cls");
	}
	return CountOfUsers == 0;
}
