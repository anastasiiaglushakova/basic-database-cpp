#include <iostream>
#include <limits>
#include "include/DataBase.h"

void showMenu() {
    std::cout << "\n=== Menu ===\n"
              << "1. Dobavit' zapis'\n"
              << "2. Udalit' zapis' po ID\n"
              << "3. Pokazat' vse zapisi\n"
              << "4. Poisk po familii\n"
              << "5. Sortirovat' po ID\n"
              << "6. Sortirovat' po familii\n"
              << "7. Zagruzit' iz faila\n"
              << "8. Sohranit' v fail\n"
              << "0. Vykhod\n"
              << "Vyberite punkt: ";
}

int main() {
    DataBase db;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string fam, im, otch;
                int godr, id;

                std::cout << "Vvedite ID: ";
                std::cin >> id;

                std::cout << "Vvedite familiyu: ";
                std::cin >> fam;

                std::cout << "Vvedite imya: ";
                std::cin >> im;

                std::cout << "Vvedite otchestvo: ";
                std::cin >> otch;

                std::cout << "Vvedite god rozhdeniya: ";
                std::cin >> godr;

                db.addRecord(ZapisBD(fam, im, otch, godr, id));
                std::cout << "Zapis' dobavlena.\n";
                break;
            }
            case 2: {
                int id;
                std::cout << "Vvedite ID dlya udaleniya: ";
                std::cin >> id;
                if (db.removeRecordByID(id)) {
                    std::cout << "Zapis' udalena.\n";
                } else {
                    std::cout << "Zapis' s takim ID ne naydena.\n";
                }
                break;
            }
            case 3:
                db.printAll();
                break;
            case 4: {
                std::string fam;
                std::cout << "Vvedite familiyu dlya poiska: ";
                std::cin >> fam;
                db.searchByFamilia(fam);
                break;
            }
            case 5:
                db.sortByID();
                std::cout << "Otsortirovano po ID.\n";
                break;
            case 6:
                db.sortByFamilia();
                std::cout << "Otsortirovano po familii.\n";
                break;
            case 7: {
                std::string filename;
                std::cout << "Vvedite imya faila dlya zagruzki: ";
                std::cin >> filename;
                if (db.loadFromFile(filename)) {
                    std::cout << "Dannye zagruzheny iz faila.\n";
                }
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Vvedite imya faila dlya sohraneniya: ";
                std::cin >> filename;
                if (db.saveToFile(filename)) {
                    std::cout << "Dannye sohraneny v fail.\n";
                }
                break;
            }
            case 0:
                std::cout << "Vykhod iz programmy.\n";
                break;
            default:
                std::cout << "Nevernyy punkt menu.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);

    return 0;
}