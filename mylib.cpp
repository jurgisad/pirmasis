#include "header.h"

void ivestis(vector<Studentas>& studentai) {
    while (true) {
        Studentas studentas;

        cout << "Įveskite studento vardą (Vardas): ";
        cin >> studentas.Vardas;

        cout << "Įveskite studento pavardę (Pavardė): ";
        cin >> studentas.Pavarde;

        cout << "Įveskite studento egzamino rezultatą (egz): ";
        cin >> studentas.egz;

        // Pažymių (nd) įvedimas
        studentas.nd.clear(); // Išvalyti esamus pažymius

        while (true) {
            int pazymys;
            cout << "Įveskite pažymį (arba -1, jei norite baigti): ";
            cin >> pazymys;

            if (pazymys == -1) {
                break; // Išeiti iš ciklo, jei įvesta -1
            }

            studentas.nd.push_back(pazymys);
        }

        // Vidurkio (vidurkis) ir medianos (mediana) skaičiavimas pagal įvestį
        double suma = 0;
        for (int pazymys : studentas.nd) {
            suma += pazymys;
        }
        int pazymiuSkaicius = studentas.nd.size();

        if (pazymiuSkaicius > 0) {
            studentas.galutinis = (suma / pazymiuSkaicius)*0.4+studentas.egz;
            // Pažymiai surūšiuojami medianos skaičiavimui
            sort(studentas.nd.begin(), studentas.nd.end());

            if (pazymiuSkaicius % 2 == 0) {
                // Jei yra lyginis pažymių skaičius, imamas dviejų vidurinių pažymių vidurkis
                int vidurinis1 = studentas.nd[pazymiuSkaicius / 2 - 1];
                int vidurinis2 = studentas.nd[pazymiuSkaicius / 2];
                studentas.mediana = (vidurinis1 + vidurinis2) / 2.0;
            } else {
                // Jei yra nelyginis pažymių skaičius, imamas vidurinis pažymys
                studentas.mediana = studentas.nd[pazymiuSkaicius / 2];
            }
        }

        // Pridėti studentą į sąrašą
        studentai.push_back(studentas);

        cout << "Ar norite įvesti kitą studentą? (taip - 1, ne - 0): ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            break; // Baigti įvedimą, jei pasirinkta "ne"
        }
    }}

void spausdinti(vector<Studentas>& studentai){
    // Atvaizduoti studentų duomenis
    for (const Studentas& studentas : studentai) {
        cout << "Vardas: " << studentas.Vardas << endl;
        cout << "Pavardė: " << studentas.Pavarde << endl;
        cout << "Egzamino rezultatas: " << studentas.egz << endl;
        cout << "Pažymiai: ";
        for (int pazymys : studentas.nd) {
            cout << pazymys << " ";
        }
        cout << endl;
        cout << "mediana: " << studentas.mediana << endl;
        cout << "galutinis: " << studentas.galutinis << endl;
        cout << endl;
    }}



