#include "CZelle.h"
#include "Spielfeld.h"
#include <iostream>

using namespace std;

CZelle::CZelle()
{

}

CZelle::CZelle(int wertZelle, bool belegt)
{
	this->wertZelle = wertZelle;
	this->belegt = belegt;
}

CZelle::~CZelle()
{

}

void CZelle::setWertZelle(int wertZelle)
{
	this->wertZelle = wertZelle;
}

void CZelle::setBelegt(bool belegt)
{
	this->belegt = belegt;
}

void CZelle::setPositionSpalte(int positionSpalte)
{
	this->positionSpalte = positionSpalte;
}

void CZelle::setPositionZeile(int positionZeile)
{
	this->positionZeile = positionZeile;
}

int CZelle::getWertZelle()
{
	return wertZelle;
}

int CZelle::getPositionSpalte()
{
	return positionSpalte;
}

int CZelle:: getPositionZeile()
{
	return positionZeile;
}
void CZelle::wertEinfuegen(CZelle feld[9][9])
{
	do
	{
		cout << "Spalte: " << endl;
		cin >> positionSpalte;
		cout << "Zeile: " << endl;
		cin >> positionZeile;

	} while (checkBelegt() == true);

	cout << "Welche Zahl m�chten sie eingeben: ";
	cin >> wertZelle;
	Spielfeld Joke; 
	if (Joke.checkNeunMal(feld, wertZelle) == true)
	{
		feld[positionZeile-1][positionSpalte-1].setWertZelle(wertZelle);	
		cout << feld[positionZeile-1][positionSpalte-1].getWertZelle();
		Joke.ausgabeSpielfeld(feld);
	}
	else
	{
		wertEinfuegen(feld);
	}
}

bool CZelle::checkBelegt()
{
	if (wertZelle > 0)
		return true;
	else
		return false;
}
