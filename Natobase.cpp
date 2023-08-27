
//Stanislaw Dutkiewicz 263509
#include "Natobase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <istream>


using namespace std;
int Natobase::counter = 0;

Natobase::Natobase(string n, string ci, string co, int ri, int tan, int pla, int lan)
        : name(n), city(ci), country(co), rifles(ri), tanks(tan), planes(pla), launcher(lan) {};

Natobase::Natobase(string init) : Natobase("20thDiv", "Kuldiga", "Latvia", 100, 50, 75, 32) {};

std::ostream &tosave(std::ostream &sv, const Natobase &pro) {
    sv << pro.counter << pro.ID << " " << pro.name << " " << pro.city << " " << pro.country << " " << pro.rifles
       << " " << pro.tanks << " " << pro.planes << " " << pro.launcher;
    return sv;
}

std::istream &toim(std::istream &imm, Natobase &pro) {
    imm >> pro.counter >> pro.ID >> pro.name >> pro.city >> pro.country >> pro.rifles >>
        pro.tanks >> pro.planes >> pro.launcher;
    return imm;
}

std::ostream &printnames(std::ostream &pr, Natobase &pro) {
    pr << "\nID:" << pro.ID << "\nName:" << pro.name;
    return pr;
}

std::ostream &operator<<(std::ostream &pr, const Natobase &pro) {
    pr << "ID: " << pro.get_ID() << "\n\n" "Name: " << pro.get_name()
       << "\n" << "City: " << pro.get_city()
       << "\n" << "Country: " << pro.get_country()
       << "\n" << "Number of rifles: " << pro.get_rifle()
       << "\n" << "Number of tanks: " << pro.get_tanks()
       << "\n" << "Number of planes: " << pro.get_planes()
       << "\n" << "Number of launcher: " << pro.get_launch();
    return pr;
}

std::istream &operator>>(std::istream &re, Natobase &product) {
    std::cout << "Enter the name of the base: \n";
    re >> product.name;
    std::cout << "Enter the city where it is located: \n";
    re >> product.city;
    std::cout << "Enter the country where it is located: \n";
    re >> product.country;
    std::cout << "Enter the number of guns held: \n";
    re >> product.rifles;
    std::cout << "Enter the number of tanks stationing: \n";
    re >> product.tanks;
    std::cout << "Enter the number of planes stationing: \n";
    re >> product.planes;
    std::cout << "Enter the number of launchers stationing: \n";
    re >> product.launcher;
    product.get_counter();
    product.ID = product.counter;
    return re;
}

///////////////////////////////////////////////////
void Database::Read_data() {;
    Natobase Nato;
    if (cin >> Nato) {
        DbMain.push_back(Nato);
    } else {
        std::cerr << "Data Error" << std::endl;
    }
}

void Database::Print_data() {
    cout << "The bases are:\n\n";
    for (auto it = std::begin(DbMain); it != std::end(DbMain); ++it) {
        cout << std::endl;
        cout << *it;
    }
}

void Database::SaveDB() {
    std::ofstream file;
    std::string filename = "Database.txt";
    file.open(filename, std::ofstream::trunc);
    for (auto it = std::begin(DbMain); it != std::end(DbMain); ++it) {
        tosave(file, *it) << "\n";
    }
}

void Database::OpenDB() {
    std::ifstream filein("Database.txt");
    Natobase uw;
    if (!filein) {
        cout << "\nAn error has been occurred with the loading Natobases\n";
    } else {
        while (toim(filein, uw)) {
            DbMain.push_back(uw);
        }
        filein.close();
    }
}

void Database::RemoveDB() {
    int det;
    cout << "Enter the ID of the base that you want to remove:\n";
    std::cout << "The bases are:\n";
    Printids();
    cin >> det;
    auto iter = std::find_if(std::begin(DbMain), std::end(DbMain), [&](Natobase &nb) { return nb.get_ID() == det; });
    if (iter != DbMain.end()) {
        DbMain.erase(iter);
    }
}

void Database::EditDB() {
    int editt;
    cout << "Enter the number of the base that you want to change:\n";
    std::cout << "The bases are:\n";
    Printids();
    cin >> editt;
    auto iter = std::find_if(std::begin(DbMain), std::end(DbMain), [&](Natobase &nb) {
        return nb.get_ID() == editt;
    }); //declared an iterator that uses function find_if to match the iterator with the ID of the database
    if (iter != DbMain.end()) {
        cout << "\nPlease enter the input of the base one more time" << endl;
        cin >> *iter;
    }
}

void Database::Printids() {
    for (auto it = std::begin(DbMain); it != std::end(DbMain); ++it) {
        std::cout << std::endl;
        printnames(std::cout, *it) << std::endl;
    }
}

void Database::Compare() {
    int comp;
    cout << "Enter the number of the base that you want to change:\n";
    std::cout << "The bases are:\n";
    Printids();
    cin >> comp;
    auto it = std::find_if(std::begin(DbMain), std::end(DbMain), [&](Natobase &nb) { return nb.get_ID() == comp; });
    if (it != DbMain.end()) {
        int num;
        std::cout << "\nPlease enter the number of Russian divisions attacking the base:\n";
        std::cin >> num;
        int sum = 1 * it->get_rifle() + 0.9 * it->get_tanks() + 2 * it->get_planes() + 3 * it->get_launch();
        int Russian = num * 1300;
        if (Russian < sum) {
            std::cout << "\n\nCongratulations!!The base will survive the attack\n";

        } else if (Russian > sum) {
            std::cout << "\n\nThe base will not survive\n";
        } else {
            std::cout << "\n\nError\n";
        }
    }
}

void Database::Clear() {
    DbMain.clear();
}

