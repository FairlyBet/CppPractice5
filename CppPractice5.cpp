#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

const unsigned short SIZE = 5;
unsigned short counter = 0;

const string RANK = "lieutenant";

const string STRUCTURES_PATH = "C:\\Users\\User\\Desktop\\Structures.txt";
const string LIEUTENANT_PATH = "C:\\Users\\User\\Desktop\\Lieutenants.txt";

string toString(long value)
{
	ostringstream oss;
	oss << value;
	return oss.str();
}

struct BornDate
{
	unsigned short day = 0;

	unsigned short month = 0;

	unsigned short year = 0;

	bool isCorrect()
	{
		bool result = false;

		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}
		default:
			result = false;
		}

		return result;
	}

	void randDate()
	{
		do
		{
			day = rand() % 31 + 1;
			month = rand() % 12 + 1;
			year = rand() % 51 + 1950;
		} while (!isCorrect());
	}
};

struct Serviceman
{
	string fullName;

	string homeAddress;

	string nationality;

	string position = "serviceman";

	string rank;

	BornDate bornDate;

	unsigned int zipCode = 11111;

	string getFullInf()
	{
		string inf = "Fullname: " + fullName + "\n" + "Borndate: " + toString(bornDate.day) + "." + toString(bornDate.month) + "." +
			toString(bornDate.year) + "\n" + "Nationality: " + nationality + "\n" + "Homeaddress: " +
			homeAddress + "\n" + "Zipcode: " + toString(zipCode) + "\n" + "Position: " + position + "\n" + "Rank: " + rank + "\n\n";
		return inf;
	}
};

Serviceman servicemen[SIZE];

void randInf()
{
	const unsigned short SIZE_OF_NAME_ARR = 10;
	const unsigned short SIZE_OF_NATIONALITIES = 5;

	string names[SIZE_OF_NAME_ARR] = { "William", "Michael", "James", "Daniel", "Samuel","Joshua", "Lucas", "Benjamin", "Sebastian", "Chistopher" };
	string lastnames[SIZE_OF_NAME_ARR] = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Taylor", "Jackson" };
	string nationalities[SIZE_OF_NATIONALITIES] = { "greek", "frenchman", "german", "byelorussian", "tajik" };

	for (size_t i = 0 % SIZE; i < SIZE; i++)
	{
		if (rand() % 10 + 1 <= 6)
			(servicemen + i)->rank = RANK;
		else (servicemen + i)->rank = "common soldier";

		(servicemen + i)->fullName += (names[rand() % SIZE_OF_NAME_ARR] + " " + names[rand() % SIZE_OF_NAME_ARR] + " ");
		(servicemen + i)->fullName += (lastnames[rand() % SIZE_OF_NAME_ARR]);

		(servicemen + i)->nationality = nationalities[rand() % SIZE_OF_NATIONALITIES];

		(servicemen + i)->bornDate.randDate();
	}
}

Serviceman* countLieutenants()
{
	counter = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		if ((servicemen + i)->rank == RANK)
			counter++;
	}

	Serviceman* lieutenants = new Serviceman[counter];

	counter = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		if ((servicemen + i)->rank == RANK)
			lieutenants[counter++] = servicemen[i];
	}

	return lieutenants;
}

void writeInf(string path, Serviceman* arr, unsigned short arrSize)
{
	ofstream out(path);

	if (out.is_open())
	{
		for (size_t i = 0; i < arrSize; i++)
		{
			out << (arr + i)->getFullInf();
		}

		out.close();
	}
}

void printInf(string path)
{
	ifstream in(path);
	if (in.is_open())
	{
		string currentLine;

		while (getline(in, currentLine) && cout << currentLine << "\n");

		in.close();
	}
}

int interface()
{
	unsigned short choice;

	while (true)
	{
		cout << "1)Print all structures	 2)Print and write lieutenants    Else)Exit\n";

		cin >> choice;

		system("cls");

		if (choice == 1)
		{
			printInf(STRUCTURES_PATH);
		}
		else if (choice == 2)
		{
			writeInf(LIEUTENANT_PATH, countLieutenants(), counter);
			printInf(LIEUTENANT_PATH);
		}
		else return 0;
	}
}

void lowLevel()
{
	randInf();

	writeInf(STRUCTURES_PATH, servicemen, SIZE);

	interface();
}

void mediumLevel()
{
	ifstream in("C:\\Users\\User\\Desktop\\Numbers.txt");
	double num1, num2;

	if (in.is_open())
	{
		in >> num1;

		cout << "First Number 1 = " << num1 << "\tLast Number 2 = ";

		while (in >> num2);

		cout << num2 << "\nDifference = "<< num1 - num2 << endl;

		in.close();
	}
}

const int LINES = 6;
const int COLUMNS = 7;

void generateVal(int(*matrix)[COLUMNS])
{
	for (size_t i = 0; i < LINES; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			matrix[i][j] = rand() % 30 + 1;
		}
	}
}

void inputValues(ofstream& out, int(*matrix)[COLUMNS], int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		generateVal(matrix);

		for (size_t j = 0; j < LINES; j++)
		{
			for (size_t k = 0; k < COLUMNS; k++)
			{
				cout << matrix[j][k] << " ";
				out << matrix[j][k] << " ";
			}
			out << endl;
			cout << endl;
		}
		out << endl;
		cout << endl;
	}
	cout << endl;
}

void swapMatrix(string path1, string path2, int amount)
{
	ifstream file1(path1), file2(path2);

	int** arrayInFile1 = new int* [LINES * amount];
	int** arrayInFile2 = new int* [LINES * amount];

	for (size_t i = 0; i < LINES * amount; i++)
	{
		arrayInFile1[i] = new int[COLUMNS];
		arrayInFile2[i] = new int[COLUMNS];
	}

	for (size_t i = 0; i < LINES * amount; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			file1 >> (arrayInFile1[i])[j];
			file2 >> (arrayInFile2[i])[j];
		}
	}

	file1.close();
	file2.close();

	ofstream out1(path1, ios::trunc), out2(path2, ios::trunc);

	int actualAmount = (amount % 2 == 0 ? amount - 1 : amount);

	for (size_t counter = 0; counter < actualAmount / 2; counter += 2)
	{
		for (size_t i = 0; i < LINES; i++)
		{
			swap(arrayInFile1[counter * LINES + i], arrayInFile1[(actualAmount - counter - 1) * LINES + i]);
			swap(arrayInFile2[counter * LINES + i], arrayInFile2[(actualAmount - counter - 1) * LINES + i]);
		}
	}

	for (size_t i = 0; i < LINES * amount; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			out1 << (arrayInFile1[i])[j] << " ";
			out2 << (arrayInFile2[i])[j] << " ";
		}

		if ((i + 1) % LINES == 0)
		{
			out1 << endl;
			out2 << endl;
		}

		out1 << endl;
		out2 << endl;
	}

	out1.close();
	out2.close();
}

void highLevel()
{
	string f1Path = "C:\\Users\\User\\Desktop\\Matrix1.cpp", f2Path = "C:\\Users\\User\\Desktop\\Matrix2.cpp";

	int matrix[LINES][COLUMNS]{}, amount1, amount2;

	cout << "Input amount of matrix in file 1 then in file 2" << endl;
	cin >> amount1 >> amount2;

	ofstream file1(f1Path), file2(f2Path);

	if (file1.is_open() && file2.is_open())
	{
		inputValues(file1, matrix, amount1);
		inputValues(file2, matrix, amount2);

		file1.close();
		file2.close();

		swapMatrix(f1Path, f2Path, (amount1 > amount2 ? amount2 : amount1));
	}
}

int main()
{
	srand(time(0));

	lowLevel();
	mediumLevel();
	system("cls");
	highLevel();
}