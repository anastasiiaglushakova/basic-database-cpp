#include "DataBase.h"
#include <fstream>
#include <algorithm>
#include <iostream>

void DataBase::addRecord(const ZapisBD& record) {
    records.push_back(record);
}

bool DataBase::removeRecordByID(int id) {
    auto it = std::remove_if(records.begin(), records.end(), [id](const ZapisBD& r) {
        return r.ID == id;
    });
    if (it != records.end()) {
        records.erase(it, records.end());
        return true;
    }
    return false;
}

void DataBase::printAll() const {
    if (records.empty()) {
        std::cout << "Baza dannykh pustaya.\n";
        return;
    }
    for (const auto& r : records) {
        r.print();
    }
}

void DataBase::searchByFamilia(const std::string& fam) const {
    bool found = false;
    for (const auto& r : records) {
        if (r.Familia == fam) {
            r.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Zapisei s familiiei \"" << fam << "\" ne naydeno.\n";
    }
}

void DataBase::sortByID() {
    std::sort(records.begin(), records.end(), [](const ZapisBD& a, const ZapisBD& b) {
        return a.ID < b.ID;
    });
}

void DataBase::sortByFamilia() {
    std::sort(records.begin(), records.end(), [](const ZapisBD& a, const ZapisBD& b) {
        return a.Familia < b.Familia;
    });
}

bool DataBase::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Ne udaloso otkryt' fail dlya chteniya: " << filename << '\n';
        return false;
    }

    records.clear();
    int id, godr;
    std::string fam, im, otch;
    while (fin >> id >> fam >> im >> otch >> godr) {
        records.emplace_back(fam, im, otch, godr, id);
    }

    fin.close();
    return true;
}

bool DataBase::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Ne udaloso otkryt' fail dlya zapisi: " << filename << '\n';
        return false;
    }

    for (const auto& r : records) {
        fout << r.ID << ' ' << r.Familia << ' ' << r.Imya << ' ' << r.Otchestvo << ' ' << r.GodR << '\n';
    }

    fout.close();
    return true;
}