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

	//������ 1
	cout << "������ 1\n������� ����� ������ ��� ��������� ��������� ����������:\n1. \"������\"\n2. \"�������-����\"\n3. \"���-���\"\n���� -> ";
	do {
		cin >> n;
		switch (n) {
		case 1: showMovie(bat); break;
		case 2: showMovie(spider); break;
		case 3: showMovie(bat); break;
		default: cout << "������ �����...\n"; break;
		}
		cout << "������ ���������� ���������� ��� ���(0 - ���, 1 - ��): \n";
		cin >> m;
		if (m)
			cout << "������� ����� ������ ��� ��������� ��������� ����������:\n1. \"������\"\n2. \"�������-����\"\n3. \"���-���\"\n���� -> ";
		else
			cout << "���������� ���������...\n\n";
	} while (m != false);

	//������ 2
	cout << "������ 2\n����� ������� ���� �� ���� � ������ - ";
	cout << expensive(bat, spider, ben) << "\n\n";
	
	//������ 3
	cout << "������ 3\n�������� ����� - 1 \"������\", 2 \"�������-����\", 3 \"���-���\": ";
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

//������3
void updateInfo(movies& film) {
	int d;
	string str;
	do {
		showMovie(film);
		cout << "��������, ����� ���������� � ������ �� ������ �������� :\n 1. ��������;\n2. ��� ������;\n3. ����;\n4. �����������������;\n5. ���� �� ����\n6. �����.\n���� -> ";
		(cin >> d).get();
		if (d == 1) {
			film.titel = "";
			cout << "������� �������� ������: ";
			getline(cin, str);
			film.titel += str;
			cout << "���������� �������\n\n";
		} 
		else
			if (d == 2) {
				cout << "������� ��� ������ ������: ";
				(cin >> d).get();
				film.year = d;
				cout << "���������� �������\n\n";
			}
			else
				if (d == 3) {
					film.genre = "";
					cout << "������� ���� ������: ";
					getline(cin, str);
					film.genre += str;
					cout << "���������� �������\n\n";
				}
				else
					if (d == 4) {
						cout << "������� ����������������� ������: ";
						(cin >> d).get();
						film.duration = d;
						cout << "���������� �������\n\n";
					}
					else
						if (d == 5) {
							cout << "������� ���� ������: ";
							(cin >> d).get();
							film.price = d;
							cout << "���������� �������\n\n";
						}
						else
							if (d == 6) {
								cout << "���������� ���������...\n\n";
							}
							else
								cout << "����� ����� ���!\n���������� ��� ���.\n\n";

	} while (d != 6);
}
//������ 2
string expensive(movies &film1, movies &film2, movies &film3) {
	if (film1.price > film2.price && film1.price > film3.price)
		return film1.titel;
	else
		if (film2.price > film1.price && film2.price > film3.price)
			return film2.titel;
	return film3.titel;
}
//������ 1
void showMovie(movies &film) {
	cout << "��������: " << film.titel << ", ��� �������: " << film.year << ", ����: " << film.genre;
	cout << ", �����������������: " << film.duration << ", ���� �� ����: " << film.price << ".\n";
}