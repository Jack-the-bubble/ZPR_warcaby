#include "Uzytkownik.h"
#include <iostream>
using namespace std;
const int size_ = 8;

Uzytkownik::Uzytkownik(int id)
{
	gracz_id = id;
	zbicie = 0;

}


Uzytkownik::~Uzytkownik()
{

}

//ta funkcja bedzie zastapiona przez wybor poprzez klikniecie i bedzie tylko sprawdzala czy zwrocone wspolrzedne pionka sa dobre
bool Uzytkownik::wybierzPionek()
{
	
	int w, k;
	cout << endl << "Podaj kolumne pionka" << endl;
	cin >> k;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}
	if (k >= 8 || k < 0)
	{
		cout << "bledne" << endl;
		cin >> k;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << endl << "Podaj wiersz pionka" << endl;
	cin >> w;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}

	if (k >= 8 || k < 0)
	{
		cout << "bledne" << endl;
		cin >> k;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	if (boardCopy[w][k] == gracz_id)
	{
		this->k_ = k;
		this->w_ = w;
		this->wybrano = true;
		return wybrano;
	}
	this->wybrano = false;
	return wybrano;
}

bool Uzytkownik::makeMove()
{
	//tymczasowe pobieranie z cin
	int w, k;
	cout << endl << "Podaj kolumne pionka do nast ruchu" << endl;
	cin >> k;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}
	if (k >= 8 || k < 0)
	{
		cout << "bledne" << endl;
		cin >> k;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << endl << "Podaj wiersz pionka do nast ruchu" << endl;
	cin >> w;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}

	if (k >= 8 || k < 0)
	{
		cout << "bledne" << endl;
		cin >> k;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	//koniec pobierania

	//sprawdzenie czy pobrane wspolrzedne moga byc nast ruchem

	for (int i = 0; i < moves_; ++i)
	{
		if (next_k[i] == k && next_w[i] == w)
		{
			prev_k = k_;
			prev_w = w_;
			k_ = k;
			w_ = w;
			return true;
		}
	}
	return false;
}

int Uzytkownik::getID()
{
	return this->gracz_id;
}

int Uzytkownik::getPrevK()
{
	return this->prev_k;
}
int Uzytkownik::getPrevW()
{
	return this->prev_w;
}

/**
Sprawdza ile jest mozliwych ruchow dla pionka
**/
int Uzytkownik::possibleMoves()
{
	int moves = 0;
	zbicie = 0;


	moves = bicie(0, w_, k_);
	   
	if (moves == 0)  //jesli nie ma bicia
	{
		if (k_ > 0)
		{
			if (boardCopy[w_ + gracz_id * 1][k_ - 1] == 0)
			{
				next_w[moves] = w_ + gracz_id * 1;
				next_k[moves] = k_ - 1;
				++moves;
			}
		}
		if (k_ < 7)
		{
			if (boardCopy[w_ + gracz_id * 1][k_ + 1] == 0)
			{
				next_w[moves] = w_ + gracz_id * 1;
				next_k[moves] = k_ + 1;
				++moves;
			}
		}


	}
	
	return moves;
}

/**
Zwraca ilosc mozliwych ustawien po biciu i wpisuje te ustawienia do next_k i next_w
**/
int Uzytkownik::bicie(int moves, int wiersz, int kol)
{
	int old_moves = moves;
	if (kol > 1 && (wiersz + gracz_id * 2) >= 0 && (wiersz + gracz_id * 2) < 8)
	{
		if (boardCopy[wiersz + gracz_id * 1][kol - 1] == -(gracz_id))
		{
			if (boardCopy[wiersz + gracz_id * 2][kol -  2] == 0)
			{
				next_w[moves] = wiersz + gracz_id * 2;
				next_k[moves] = kol -  2;
				++moves;
		//		doZbicia_k[zbicie] = kol - 1;
		//		doZbicia_w[zbicie] = 
		//		++zbicie;

				do
				{
					old_moves = moves;
					moves = bicie(moves, next_w[moves - 1], next_k[moves - 1]);
				} while (moves != old_moves);
			}
		}

	}

	if (kol < 6 && (wiersz + gracz_id*2) >= 0 && (wiersz + gracz_id * 2) < 8)
	{
		if (boardCopy[wiersz + gracz_id * 1][kol + 1] == -(gracz_id))
		{
			if (boardCopy[wiersz + gracz_id * 2][kol + 2] == 0)
			{
				next_w[moves] = wiersz + gracz_id * 2;
				next_k[moves] = kol + 2;
				++moves;
				do
				{
					old_moves = moves;
					moves = bicie(moves, next_w[moves - 1], next_k[moves - 1]);
				} while (moves != old_moves);
			}

		}
	}


	//bicia do tylu
	if (kol > 1 && (wiersz-gracz_id*2) >= 0 && (wiersz - gracz_id * 2) < 8)
	{
		if (boardCopy[wiersz - gracz_id * 1][kol - 1] == -(gracz_id))
		{
			if (boardCopy[wiersz - gracz_id * 2][kol - 2] == 0)
			{
				boardCopy[wiersz - gracz_id * 1][kol - 1] = 0;  //tymczasowe
				next_w[moves] = wiersz - gracz_id * 2;
				next_k[moves] = kol - 2;
				++moves;
				do
				{
					old_moves = moves;
					moves = bicie(moves, next_w[moves - 1], next_k[moves - 1]);
				} while (moves != old_moves);
			}
		}
	}

	if (kol < 6 && (wiersz - gracz_id * 2) >= 0 && (wiersz - gracz_id * 2) < 8)
	{
		if (boardCopy[wiersz - gracz_id * 1][kol + 1] == -(gracz_id))
		{
			if (boardCopy[wiersz - gracz_id * 2][kol + 2] == 0)
			{
				boardCopy[wiersz - gracz_id * 1][kol + 1] = 0; //tymczasowe
				next_w[moves] = wiersz - gracz_id * 2;
				next_k[moves] = kol + 2;
				++moves;
				do
				{
					old_moves = moves;
					moves = bicie(moves, next_w[moves - 1], next_k[moves - 1]);
				} while (moves != old_moves);
			}
		}
	}
	


	return moves;
}

void Uzytkownik::update(const int plansza[8][8])
{
	moves_ = 0;

	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
			boardCopy[i][j] = plansza[i][j];
	}
	do 
	{
		while (wybierzPionek() == false) {}
		this->moves_ = possibleMoves();
	} while (moves_ == 0);

	for (int i = 0; i < moves_;++i)
	{
		cout << "mozliwy ruch k: " << next_k[i] << " w: " << next_w[i] << endl;
	}

	while (makeMove() == false) {}
	return;
	//tutaj juz w tablicach next_w oraz next_k w komorkach od 0 do moves_-1 sa dostepne ruchy
	//teraz powinny sie wyswietlic uzytkownikowi i powinien on moc wybrac 
	// zamiast tego narazie bedzie funkcja zeby podac wspolrzedne nastepne
}

int Uzytkownik::getK()
{
	return  k_;
}
int Uzytkownik::getW()
{
	return  w_;
}
