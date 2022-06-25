#include "CZelle.h"
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
void CZelle::wertEinfuegen(int wertZelle)
{
	cout << "Spalte: " << endl
		<< "Zeile: " << endl;
	cin >> positionSpalte;
	cin >> positionZeile;
	
	if (checkBelegt() == true)
	{
		cout << "Zelle belegt waehle nochmals!" << endl;
		wertEinfuegen(wertZelle);
	}
	else 
	{
		cout << "Welche Zahl möchten sie eingeben: ";
		cin >> wertZelle;
	}
	
}
bool CZelle::checkBelegt()
{
	if (wertZelle > 0)
		return true;
	else
		return false;
}
