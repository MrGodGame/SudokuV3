#include "Spielfeld.h"
#include "CZelle.h"
#include <iostream>
using namespace std;
    
Spielfeld::Spielfeld()
{

}

Spielfeld::~Spielfeld()
{

}

Spielfeld::Spielfeld(int zeile, int spalte)
{
    this->zeile = zeile;
    this->spalte = spalte;
}

void Spielfeld::setZeile()
{
    this->zeile = zeile;
}

void Spielfeld::setSpalte()
{
    this->spalte = spalte;
}

bool Spielfeld::checkWin(CZelle* feld[9][9], int zeile, int zahl)
{
    int summe = 0;
    for (int z = 0; z < 9; z++)
    {
        for (int s = 0; s < 9; s++)
        {
            summe = summe + feld[z][s]->getWertZelle();
        }
    }

    if (summe == 405)
    {
        return true;
    }

    return false;
}

bool Spielfeld::checkZeile(CZelle* feld[9][9], int zeile, int zahl)
{
    for (int i = 0; i < 9; i++)
    {
        if (zahl == feld[i][zeile]->getWertZelle())
        {
            return false;
        }
    }
    return true;
}

bool Spielfeld::checkSpalte(CZelle* feld[9][9], int spalte, int zahl)
{
    for (int i = 0; i < 9; i++)
    {
        if (zahl == feld[spalte][i]->getWertZelle())
        {
            return false;
        }
    }
    return true;
}

bool Spielfeld::checkNeunMal(CZelle* feld[9][9], int zahl)
{
    int summe = 0;
    for (int z = 0; z < 9; z++)
    {
        for (int s = 0; s < 9; s++)
        {
            if (zahl == feld[z][s]->getWertZelle())
            {
                summe++;
            }
        }
    }
    if (summe == 9)
    {
        return false;
    }

    if (summe < 9)
    {
        return true;
    }

}

void Spielfeld::ausgabeSpielfeld()
{
    system("cls");

    CZelle feld[9][9];

    for (int z = 0; z < 9; z++)
    {
        for (int s = 0; s < 9; s++)
        {
            //(feld[z][s]).setWertZelle(0);
            cout << feld[z][s].getWertZelle();
        }
        cout << endl;
    }
    CZelle Wert;
    Wert.wertEinfuegen(feld[9][9]);
}

void Spielfeld::neustarten()
{

    system("cls");

}

void Spielfeld::auslesen()
{
    FILE* datei;
    int z = 0, s = 0;
    if ((fopen_s(&datei, "Null.csv", "r")) != NULL)
    {
        fprintf_s(stderr, "Datei konnte nicht geoeffnet werden!\n");
    }

    while ((fscanf_s(datei, "%i\n", feld[z][s])) != EOF)
    {
        s++;
        if (s == 8)
        {
            z++;
            s = 0;
        }
        (feld[z][s])->setWertZelle(0);
    }

    fclose(datei);
}
