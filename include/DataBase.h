#pragma once
#include "ZapisBD.h"
#include <vector>
#include <string>

class DataBase {
private:
    std::vector<ZapisBD> records;

public:
    void addRecord(const ZapisBD& record);
    bool removeRecordByID(int id);
    void printAll() const;
    void searchByFamilia(const std::string& fam) const;
    void sortByID();
    void sortByFamilia();
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
};