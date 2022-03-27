#include <iostream>
#include <string>
using namespace std;

struct movies {
	string titel;
	int year;
	string genre;
	int duration;
	int price;
};

void showMovie(movies &film);
string expensive(movies &film1, movies &film2, movies &film3);
void updateInfo(movies &film);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	bool m;

	movies bat = { "Batman", 2022, "detective", 130, 150 };
	movies spider = { "Spider-man", 2021, "action", 150, 100};
	movies ben = { "Ben-Hur", 1959, "drama", 212, 60 };

	//Задача 1
	cout << "Задача 1\nВведите номер фильма для просмотра подробной информации:\n1. \"Бэтман\"\n2. \"Человек-паук\"\n3. \"Бен-Гур\"\nВвод -> ";
	do {
		cin >> n;
		switch (n) {
		case 1: showMovie(bat); break;
		case 2: showMovie(spider); break;
		case 3: showMovie(bat); break;
		default: cout << "Ошибка ввода...\n"; break;
		}
		cout << "Хотите посмотреть информацию еще раз(0 - нет, 1 - да): \n";
		cin >> m;
		if (m)
			cout << "Введите номер фильма для просмотра подробной информации:\n1. \"Бэтман\"\n2. \"Человек-паук\"\n3. \"Бен-Гур\"\nВвод -> ";
		else
			cout << "Завершение программы...\n\n";
	} while (m != false);

	//Задача 2
	cout << "Задача 2\nСамая высокая цена за диск у фильма - ";
	cout << expensive(bat, spider, ben) << "\n\n";
	
	//Задача 3
	cout << "Задача 3\nВыберите фильм - 1 \"Бэтман\", 2 \"Человек-паук\", 3 \"Бен-Гур\": ";
	cin >> n;
	if (n == 1)
		updateInfo(bat);
	else
		if (n == 2)
			updateInfo(spider);
		else
			updateInfo(ben);

	return 0;
}

//Задача3
void updateInfo(movies& film) {
	int d;
	string str;
	do {
		showMovie(film);
		cout << "Выберите, какую информацию о фильме вы хотите обновить :\n 1. Название;\n2. Год выхода;\n3. Жанр;\n4. Продолжительность;\n5. Цена за диск\n6. Конец.\nВвод -> ";
		(cin >> d).get();
		if (d == 1) {
			film.titel = "";
			cout << "Введите название фильма: ";
			getline(cin, str);
			film.titel += str;
			cout << "Информация принята\n\n";
		} 
		else
			if (d == 2) {
				cout << "Введите год выхода фильма: ";
				(cin >> d).get();
				film.year = d;
				cout << "Информация принята\n\n";
			}
			else
				if (d == 3) {
					film.genre = "";
					cout << "Введите жанр фильма: ";
					getline(cin, str);
					film.genre += str;
					cout << "Информация принята\n\n";
				}
				else
					if (d == 4) {
						cout << "Введите продолжительность фильма: ";
						(cin >> d).get();
						film.duration = d;
						cout << "Информация принята\n\n";
					}
					else
						if (d == 5) {
							cout << "Введите цену фильма: ";
							(cin >> d).get();
							film.price = d;
							cout << "Информация принята\n\n";
						}
						else
							if (d == 6) {
								cout << "Завершение программы...\n\n";
							}
							else
								cout << "Такой опции нет!\nПопробуйте еще раз.\n\n";

	} while (d != 6);
}
//Задача 2
string expensive(movies &film1, movies &film2, movies &film3) {
	if (film1.price > film2.price && film1.price > film3.price)
		return film1.titel;
	else
		if (film2.price > film1.price && film2.price > film3.price)
			return film2.titel;
	return film3.titel;
}
//Задача 1
void showMovie(movies &film) {
	cout << "Название: " << film.titel << ", год выпуска: " << film.year << ", жанр: " << film.genre;
	cout << ", продолжительность: " << film.duration << ", цена за диск: " << film.price << ".\n";
}