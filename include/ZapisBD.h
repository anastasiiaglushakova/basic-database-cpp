#pragma once
#include <string>
#include <iostream>

struct ZapisBD {
    std::string Familia;
    std::string Imya;
    std::string Otchestvo;
    int GodR = 0;
    int ID = 0;

    ZapisBD(const std::string& f, const std::string& i, const std::string& o, int g, int id)
        : Familia(f), Imya(i), Otchestvo(o), GodR(g), ID(id) {}

    void print() const {
        std::cout << "ID: " << ID << ", " << Familia << " " << Imya << " " << Otchestvo << ", " << GodR << '\n';
    }
};