// Jeżeli program nie działš
//Jeżeli kompilujesz z konsoli  g++ -std=c++17 -Wpedantic -Wall -Wextra -O3  plik.cpp -o main
//Jeżeli codebloxie w settings -> compiller settings zaznaczasz Have g++

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>

using namespace std;

string nazwa_p;
string wszyscy;
string linia;
int wybor;
double stawka;
time_t czas;
fstream wszyscyy;

void menu()
{
    cout << "                            ____________________________________________________________________    "                            <<endl;
    cout << "                           |                                                                    |   "                            <<endl;
    cout << "                           |        Co chcialbys wybrac ? :                                     |   "                            <<endl;
    cout << "                           |        1.Dodaj pracownika                                          |   "                            <<endl;
    cout << "                           |        2.Zwolnij pracownika                                        |   "                            <<endl;
    cout << "                           |        3.Dodaj godziny dla pracownika                              |   "                            <<endl;
    cout << "                           |        4.Pokaz godziny pracownika                                  |   "                            <<endl;
    cout << "                           |        5.Pokaz wyplate pracownika                                  |   "                            <<endl;
    cout << "                           |        Wybor za pomoca 1-5 ponumerowane tak jak w menu.            |   "                            <<endl;
    cout << "                           |____________________________________________________________________|   "                            <<endl;
    cout << "Wybierz: ";
    cin >> wybor;
}
void wybory()
{

    if (wybor == 1)

    {
    cout << "Podaj imie pracownika ktorego chcesz dodac : " << endl;
    cin >> nazwa_p;
    cout << "Jesli pracownik ma stawke z przecinkiem to zamiast ',' wstaw kropke '.' np 10.5 \n" ;
    cout << "Jaka stawke ma " << nazwa_p << " ? :"<< endl;
    cin >> stawka;
    wszyscy+="pracownicy.txt";
    wszyscyy.open(wszyscy, ios::out | ios::app);
    wszyscyy << nazwa_p << endl;
    nazwa_p+=".txt";
    fstream hajs;
    hajs.open(nazwa_p,ios::out | ios::app);
    hajs << stawka << endl;
    hajs.close();
    nazwa_p=nazwa_p+="_w.txt";
    fstream wyplata;
    wyplata.open(nazwa_p,ios::out | ios::app);
    wyplata << stawka << endl;
    wyplata.close();
    }

    else if (wybor == 2)

    {
        cout << "Podaj imie pracownika ktorego chcesz zwolnic : " << endl;
        cin >> nazwa_p;
        nazwa_p+=".txt";
        DeleteFile(nazwa_p.c_str());
        nazwa_p=nazwa_p+="_w.txt";
        DeleteFile(nazwa_p.c_str());


    }

    else if (wybor == 3)

    {
        float godziny;
        cout << "Podaj imie pracownika ktoremu chcesz dodac godziny : " << endl;
        cout << "Jesli chcesz dodac godziny z przecinkiem to zamiast ',' wstaw kropke '.' np 10.5 \n" ;
        cin >> nazwa_p;
        cout << "Ile godzin chcesz dodac dla " << nazwa_p << " ? : " << endl;
        cin >> godziny;
        nazwa_p+=".txt";
        fstream pracownikk;
        pracownikk.open(nazwa_p,ios::in | ios::app);
        pracownikk << godziny << endl;
        nazwa_p=nazwa_p+="_w.txt";
        pracownikk.close();
        fstream dodano;
        dodano.open(nazwa_p,ios::in | ios::app);
        time(&czas);
        dodano << godziny << " Dodano " << ctime(&czas) << endl;
        dodano.close();


    }

    else if (wybor == 5)

    {
        string stawka_h;
        cout << "Wyplate ktorego pracownika chcesz zobaczyc ? : " << endl;
        cin >> nazwa_p;
        cout << "Wyplata pracownika " << nazwa_p << " wynosi : ";
        nazwa_p+=".txt";

  std::ifstream ifs(nazwa_p);

float hourlyWage, hours, sum = 0;

if (ifs >> hourlyWage) {
    while (ifs >> hours) {
        sum += hours;
    }

    std::cout << sum * hourlyWage << '\n';
}

    }

    else if (wybor == 4)

    {
        cout << "Godziny ktorego pracownika chcesz zobaczyc ? : "<< endl;
        cin >> nazwa_p;
        nazwa_p+=".txt";
        nazwa_p=nazwa_p+="_w.txt";

        fstream plik;
        plik.open(nazwa_p, ios::in);

        getline (plik,linia);

        while(!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
        }

        plik.close();

    }
}


int main()
{
    for (;;)
    {
        system("title Pracodawca - Kuba Prajwocki");
        cout << "AUTOR: Jakub Prajwocki \n";
        menu();
        wybory();
        system("PAUSE");
        system ("cls");
    }
}
  
