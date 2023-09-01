
//Stanislaw Dutkiewicz 263509
#ifndef NATOBASE_H
#define NATOBASE_H

#include <string>
#include <vector>
#include "Natobase.h"

class Natobase {
    friend std::ostream &tosave(std::ostream &, const Natobase &);
    friend std::istream &toim(std::istream &, Natobase &);
    friend std::ostream &printnames(std::ostream &, Natobase &);
    friend std::istream &operator>>(std::istream &, Natobase &);

public:
    Natobase() = default;

    Natobase(std::string n, std::string ci, std::string co, int ri, int tan, int pla, int lan); //read-only
    Natobase(std::string init); //initialisation

    const std::string &get_name() const { return this->name; }
    const std::string &get_city() const { return this->city; }
    const std::string &get_country() const { return this->country; }
    const int &get_rifle() const { return this->rifles; }
    const int &get_tanks() const { return this->tanks; }
    const int &get_planes() const { return this->planes; }
    const int &get_launch() const { return this->launcher; }
    const int &get_ID() const { return this->ID; }

private:

    std::string name;
    std::string city;
    std::string country;
    int rifles;
    int tanks;
    int planes;
    int launcher;
    static int counter;
    int ID;
    static int get_counter() {
        counter++;
        return counter;
    };
};

std::ostream &tosave(std::ostream &, const Natobase &); //save data into txt file
std::istream &toim(std::istream &, Natobase &);// to read the data from txt file
std::ostream &printnames(std::ostream &, Natobase &); //used for edit and remove function in Database class
std::ostream &operator<<(std::ostream &, const Natobase &); //input attributes
std::istream &operator>>(std::istream &, Natobase &); //output attributes
////////////////////////
class Database {
public:
    Database() = default;
    void Print_data();
    void Read_data();
    void SaveDB();
    void OpenDB();
    void EditDB();
    void RemoveDB();
    void Printids();
    void Compare();
    void Clear();
private:
    std::vector<Natobase> DbMain;
};


#endif 
