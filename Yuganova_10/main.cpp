#include <iostream>
#include <fstream>
using namespace std;

int Q, N;
int** prices;
int** calories;


void readData()
{
	string caloriesFileName;
	string pricesFileName;

	cout << "Введите данные:\n"
		<< "N (количество ланчей) = ";
	cin >> N;
	cout << "Q (число блюд в каждом) = ";
	cin >> Q;

	cout << "Введите имя файла с информацией о калорийности: ";
	cin >> caloriesFileName;

	cout << "Введите имя файла с ценами: ";
	cin >> pricesFileName;

	// Открыть файлы
	ifstream caloriesFile(caloriesFileName);
	ifstream pricesFile(pricesFileName);

	// Создать и проинициализировать массив калорийности
	calories = new int*[N];
	for (int i = 0; i < N; i++)
	{
		calories[i] = new int[Q];
		for (int j = 0; j < Q; j++)
			caloriesFile >> calories[i][j];
	}

	// Создать и проинициализировать массив цен
	prices = new int*[N];
	for (int i = 0; i < N; i++)
	{
		prices[i] = new int[Q];
		for (int j = 0; j < Q; j++)
			pricesFile >> prices[i][j];
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	readData();

	// посчитать стоимость каждого ланча
	int* lunchCosts = new int[N];
	cout << "\nСтоимости ланчей: \n";
	for (int i = 0; i < N; i++)
	{
		lunchCosts[i] = 0;
		for (int j = 0; j < Q; j++)
			lunchCosts[i] += prices[i][j];
		cout << lunchCosts[i] << " ";
	}

	// посчитать калорийность каждого ланча
	int* lunchCals = new int[N];
	cout << "\nКалорийности ланчей: \n";
	for (int i = 0; i < N; i++)
	{
		lunchCals[i] = 0;
		for (int j = 0; j < Q; j++)
			lunchCals[i] += calories[i][j];
		cout << lunchCals[i] << " ";
	}

	cout << "\n\nВведите значение калорийности для отбора: ";
	int selectedCal;
	cin >> selectedCal;

	cout << "\nСтоимости ланчей, калорийность которых меньше указанного значения:\n";
	for (int i = 0; i < N; i++)
		if (lunchCals[i] < selectedCal)
			cout << lunchCosts[i] << " ";
	cout << "\n";

	cout << "\nВведите значение стоимости для отбора: ";
	int selectedCost;
	cin >> selectedCost;

	cout << "\nКалорийности ланчей, стоимость которых меньше указанного значения:\n";
	for (int i = 0; i < N; i++)
		if (lunchCosts[i] < selectedCost)
			cout << lunchCals[i] << " ";
	cout << "\n\n";
	system("pause");
}
