#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Структура "Человек"
struct Person {
    string surname;
    string name;
    char gender;
    int height;
    int weight;
    struct {
        int day;
        int month;
        int year;
    } birthDate;
    string phoneNumber;
    struct {
        int index;
        string country;
        string region;
        string city;
        string street;
        int house;
        int apartment;
    } address;
};

// Функция для добавления новой структуры в файл
void addPerson(const Person& person) {
    ofstream outFile("people.txt", ios::app);
    if (outFile.is_open()) {
        outFile << person.surname << "\t"
            << person.name << "\t"
            << person.gender << "\t"
            << person.height << "\t"
            << person.weight << "\t"
            << person.birthDate.day << "\t"
            << person.birthDate.month << "\t"
            << person.birthDate.year << "\t"
            << person.phoneNumber << "\t"
            << person.address.index << "\t"
            << person.address.country << "\t"
            << person.address.region << "\t"
            << person.address.city << "\t"
            << person.address.street << "\t"
            << person.address.house << "\t"
            << person.address.apartment << "\n";
        outFile.close();
        cout << "Структура успешно добавлена в файл." << endl;
    }
    else {
        cerr << "Ошибка открытия файла." << endl;
    }
}

// Функция для поиска структуры по заданному значению элемента
void searchPerson(const string& fieldName, const string& value) {
    ifstream inFile("people.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string field;
            getline(iss, field, '\t'); // Читаем первое поле
            if (field == fieldName) {
                cout << "Структура найдена: " << line << endl;
                inFile.close();
                return;
            }
        }
        cout << "Структура с указанным значением не найдена." << endl;
        inFile.close();
    }
    else {
        cerr << "Ошибка открытия файла." << endl;
    }
}

// Функция для вывода на экран содержимого файла
void displayPeople() {
    ifstream inFile("people.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cerr << "Ошибка открытия файла." << endl;
    }
}

int main() {
    // Пример заполнения структуры
    Person person1;
    person1.surname = "Иванов";
    person1.name = "Иван";
    person1.gender = 'М';
    person1.height = 180;
    person1.weight = 75;
    person1.birthDate.day = 15;
    person1.birthDate.month = 6;
    person1.birthDate.year = 1990;
    person1.phoneNumber = "123456789";
    person1.address.index = 12345;
    person1.address.country = "Россия";
    person1.address.region = "Московская область";
    person1.address.city = "Москва";
    person1.address.street = "Ленина";
    person1.address.house = 10;
    person1.address.apartment = 5;

    // Добавление структуры в файл
    addPerson(person1);

    // Пример поиска структуры по заданному значению элемента
    searchPerson("surname", "Иванов");

    // Пример вывода на экран содержимого файла
    cout << "Содержимое файла:" << endl;
    displayPeople();

    return 0;
}
