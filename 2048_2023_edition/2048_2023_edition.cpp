//#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <conio.h>
using namespace std;
//#define BIGSETKA
//#define SMALLSETKA
int SMALL_NET;

enum Direction
{
	Left = 75,
	Right = 77,
	Up = 72,
	Down = 80
};

void primary_filling(int a[16])
{
	int rand_a;
	int rand_b;

	do // рандомизация двух чисел от 0 до 15 включительно
	{
		rand_a = 1 + rand() % 16;
		rand_b = 1 + rand() % 16;
	} while (rand_a == rand_b);

	for (int i = 0; i < 16; i++) //расставляем две двойки в сетку
	{
		if (rand_a == i || rand_b == i) { a[i] = 2; }
		else a[i] = 0;
	}
}

//#ifdef BIGSETKA
void setka(int a[16], int score, int highscore, int moves)
{
	if (SMALL_NET)
	{
		string s[16];

		for (int i = 0; i < 16; i++)
		{
			if (a[i] == 0) s[i] = "    ";
			else if (a[i] == 2) s[i] = "  2 ";
			else if (a[i] == 4) s[i] = "  4 ";
			else if (a[i] == 8) s[i] = "  8 ";
			else if (a[i] == 16) s[i] = " 16 ";
			else if (a[i] == 32) s[i] = " 32 ";
			else if (a[i] == 64) s[i] = " 64 ";
			else if (a[i] == 128) s[i] = " 128";
			else if (a[i] == 256) s[i] = " 256";
			else if (a[i] == 512) s[i] = " 512";
			else if (a[i] == 1024) s[i] = "1024";
			else if (a[i] == 2048) s[i] = "2048";
		}

		cout << "---------------------------------\n";

		cout << "Highscore: " << highscore << "\n";
		cout << "Score: " << score << "\n";
		cout << "Moves: " << moves << "\n";
		cout << " _______________________________\n";
		for (int i = 0; i < 16; i += 4)
		{
			cout << "|       |       |       |       |\n";
			cout << "| " << s[i] << "  | " << s[i + 1] << "  | " << s[i + 2] << "  | " << s[i + 3] << "  |\n";
			cout << "|_______|_______|_______|_______|\n";
		}
		cout << "\n";
		cout << "---------------------------------\n";
	}
	else
	{
		string s[80];

		for (int i = 0; i < 16; i++)
		{
			if (a[i] == 0)
			{
				s[i * 5 + 0] = "                ";
				s[i * 5 + 1] = "                ";
				s[i * 5 + 2] = "                ";
				s[i * 5 + 3] = "                ";
				s[i * 5 + 4] = "                ";
			}

			if (a[i] == 2)
			{
				s[i * 5 + 0] = "      ____      ";
				s[i * 5 + 1] = "          |     ";
				s[i * 5 + 2] = "      ____|     ";
				s[i * 5 + 3] = "     |          ";
				s[i * 5 + 4] = "     |____      ";
			}

			if (a[i] == 4)
			{
				s[i * 5 + 0] = "                ";
				s[i * 5 + 1] = "     |    |     ";
				s[i * 5 + 2] = "     |____|     ";
				s[i * 5 + 3] = "          |     ";
				s[i * 5 + 4] = "          |     ";
			}

			if (a[i] == 8)
			{
				s[i * 5 + 0] = "      ____      ";
				s[i * 5 + 1] = "     |    |     ";
				s[i * 5 + 2] = "     |____|     ";
				s[i * 5 + 3] = "     |    |     ";
				s[i * 5 + 4] = "     |____|     ";
			}

			if (a[i] == 16)
			{
				s[i * 5 + 0] = "         ___    ";
				s[i * 5 + 1] = "    |   |       ";
				s[i * 5 + 2] = "    |   |___    ";
				s[i * 5 + 3] = "    |   |   |   ";
				s[i * 5 + 4] = "    |   |___|   ";
			}

			if (a[i] == 32)
			{
				s[i * 5 + 0] = "   ___    ___   ";
				s[i * 5 + 1] = "      |      |  ";
				s[i * 5 + 2] = "   ___|   ___|  ";
				s[i * 5 + 3] = "      |  |      ";
				s[i * 5 + 4] = "   ___|  |___   ";
			}

			if (a[i] == 64)
			{
				s[i * 5 + 0] = "   ___          ";
				s[i * 5 + 1] = "  |      |   |  ";
				s[i * 5 + 2] = "  |___   |___|  ";
				s[i * 5 + 3] = "  |   |      |  ";
				s[i * 5 + 4] = "  |___|      |  ";
			}

			if (a[i] == 128)
			{
				s[i * 5 + 0] = "     ___   ___  ";
				s[i * 5 + 1] = "  |     | |   | ";
				s[i * 5 + 2] = "  |  ___| |___| ";
				s[i * 5 + 3] = "  | |     |   | ";
				s[i * 5 + 4] = "  | |___  |___| ";
			}

			if (a[i] == 256)
			{
				s[i * 5 + 0] = "  __   __   __  ";
				s[i * 5 + 1] = "    | |    |    ";
				s[i * 5 + 2] = "  __| |__  |__  ";
				s[i * 5 + 3] = " |       | |  | ";
				s[i * 5 + 4] = " |__   __| |__| ";
			}

			if (a[i] == 512)
			{
				s[i * 5 + 0] = "   ___     ___  ";
				s[i * 5 + 1] = "  |     |     | ";
				s[i * 5 + 2] = "  |___  |  ___| ";
				s[i * 5 + 3] = "      | | |     ";
				s[i * 5 + 4] = "   ___| | |___  ";
			}

			if (a[i] == 1024)
			{
				s[i * 5 + 0] = "    __   _      ";
				s[i * 5 + 1] = " | |  |   | | | ";
				s[i * 5 + 2] = " | |  |  _| |_| ";
				s[i * 5 + 3] = " | |  | |     | ";
				s[i * 5 + 4] = " | |__| |_    | ";
			}

			if (a[i] == 2048)
			{
				s[i * 5 + 0] = " _   _       _  ";
				s[i * 5 + 1] = "  | | | | | | | ";
				s[i * 5 + 2] = " _| | | |_| |_| ";
				s[i * 5 + 3] = "|   | |   | | | ";
				s[i * 5 + 4] = "|_  |_|   | |_| ";
			}
		}

		cout << "---------------------------------------------------------------------\n";
		cout << "Highscore: " << highscore << "\n";
		cout << "Score: " << score << "\n";
		cout << "Moves: " << moves << "\n";
		cout << " ________________ ________________ ________________ ________________ \n";
		for (int i = 0; i < 4; i++)
		{
			cout << "|                |                |                |                |\n";
			cout << "|" << s[0 + (i * 20)] << "|" << s[5 + (i * 20)] << "|" << s[10 + (i * 20)] << "|" << s[15 + (i * 20)] << "|\n";
			cout << "|" << s[1 + (i * 20)] << "|" << s[6 + (i * 20)] << "|" << s[11 + (i * 20)] << "|" << s[16 + (i * 20)] << "|\n";
			cout << "|" << s[2 + (i * 20)] << "|" << s[7 + (i * 20)] << "|" << s[12 + (i * 20)] << "|" << s[17 + (i * 20)] << "|\n";
			cout << "|" << s[3 + (i * 20)] << "|" << s[8 + (i * 20)] << "|" << s[13 + (i * 20)] << "|" << s[18 + (i * 20)] << "|\n";
			cout << "|" << s[4 + (i * 20)] << "|" << s[9 + (i * 20)] << "|" << s[14 + (i * 20)] << "|" << s[19 + (i * 20)] << "|\n";
			cout << "|                |                |                |                |\n";
			cout << "|________________|________________|________________|________________|\n";
		}
		cout << "\n";
		cout << "---------------------------------------------------------------------\n";
	}
}
//#endif

//#ifdef SMALLSETKA
//void setka(int a[16], int score, int highscore, int moves)
//{
//
//}
//#endif

bool rl_matches(int a[16])
{
	for (int i = 0; i < 16; i += 4)
	{
		if (((a[i] == a[i + 1] && a[i + 1] != 0)
			|| (a[i] == a[i + 2] && a[i + 2] != 0 && a[i + 1] == 0)
			|| (a[i] == a[i + 3] && a[i + 3] != 0 && a[i + 1] == 0 && a[i + 2] == 0)
			|| (a[i + 1] == a[i + 2] && a[i + 2] != 0)
			|| (a[i + 1] == a[i + 3] && a[i + 3] != 0 && a[i + 2] == 0)
			|| (a[i + 2] == a[i + 3] && a[i + 3] != 0)))
		{
			return true;
		}
	}
	return false;
}

bool ud_matches(int a[16])
{
	for (int i = 0; i < 4; i++)
	{
		if (((a[i] == a[i + 4] && a[i + 4] != 0)
			|| (a[i] == a[i + 8] && a[i + 8] != 0 && a[i + 4] == 0)
			|| (a[i] == a[i + 12] && a[i + 12] != 0 && a[i + 4] == 0 && a[i + 8] == 0)
			|| (a[i + 4] == a[i + 8] && a[i + 8] != 0)
			|| (a[i + 4] == a[i + 12] && a[i + 12] != 0 && a[i + 8] == 0)
			|| (a[i + 8] == a[i + 12] && a[i + 12] != 0)))
		{
			return true;
		}
	}
	return false;
}

bool check_for_loss(int a[16])
{

	for (int i = 0; i < 16; i++)
	{
		if (a[i] == 0)
		{
			return false;
		}
	}
	return true;
}

bool foo_again()
{
	cout << "Play again? (0 - no / 1 - yes)" << endl;
	string str_again;
	do
	{
		cin >> str_again;
	} while ((str_again != "0") && (str_again != "1"));
	if (str_again == "0") { return false; }
	else { return true; }
}

string input()
{
	string swipe = "Undefined";
	while (true)
	{
		if (_kbhit())
		{
			int kl = _getch();
			if ((kl == 119) || (kl == Up)) { swipe = "up"; }
			else if ((kl == 97) || (kl == Left)) { swipe = "left"; }
			else if ((kl == 115) || (kl == Down)) { swipe = "down"; }
			else if ((kl == 100) || (kl == Right)) { swipe = "right"; }
			else
			{
				if (kl != 224) { cout << "Use WASD or arrows to move: " << endl; }
				continue;
			}
			break;
		}
	}
	return swipe;
}

string check_for_lock(int a[16], bool rl_swipe, bool ud_swipe, string swipe)
{
	bool pass = false; //проверка на блокировку
	while (true)
	{
		if (swipe == "right")
		{
			if (rl_swipe) { break; }

			for (int g = 0; g < 16; g += 4)
			{
				for (int i = 0; i < 3; i++)
				{
					if ((a[i + g] != 0) && (a[i + g + 1] == 0))
					{
						pass = true;
						break;
					}
				}
				if (pass) { break; }
			}
			if (pass) { break; }
			swipe = input();
		}

		if (swipe == "left")
		{
			if (rl_swipe) { break; }
			for (int g = 0; g < 16; g += 4)
			{
				for (int i = 0; i < 3; i++)
				{
					if ((a[i + g] == 0) && (a[i + g + 1] != 0))
					{
						pass = true;
						break;
					}
				}
				if (pass) { break; }
			}
			if (pass) { break; }
			swipe = input();
		}

		if (swipe == "up")
		{
			if (ud_swipe) { break; }
			for (int g = 0; g < 12; g += 4)
			{
				for (int i = 0; i < 4; i++)
				{
					if ((a[i + g] == 0) && (a[i + g + 4] != 0))
					{
						pass = true;
						break;
					}
				}
				if (pass) { break; }
			}
			if (pass) { break; }
			swipe = input();
		}

		if (swipe == "down")
		{
			if (ud_swipe) { break; }
			for (int g = 0; g < 12; g += 4)
			{
				for (int i = 0; i < 4; i++)
				{
					if ((a[i + g] != 0) && (a[i + g + 4] == 0))
					{
						pass = true;
						break;
					}
				}
				if (pass) { break; }
			}
			if (pass) { break; }
			swipe = input();
		}
	}
	return swipe;
}

int r_mechanisms(int a[16], int score)
{
	for (int i = 0; i < 16; i += 4) //повышаем в 1-4 строчках для правого свайпа
	{
		if (a[i + 2] == a[i + 3] && a[i + 3] != 0)
		{
			a[i + 2] = 0; a[i + 3] *= 2; score += a[i + 3];
		}
		else if (a[i + 1] == a[i + 3] && a[i + 3] != 0 && a[i + 2] == 0)
		{
			a[i + 1] = 0; a[i + 3] *= 2; score += a[i + 3];
		}
		else if (a[i + 1] == a[i + 2] && a[i + 2] != 0)
		{
			a[i + 1] = 0; a[i + 2] *= 2; score += a[i + 2];
		}
		else if (a[i] == a[i + 1] && a[i + 1] != 0)
		{
			a[i] = 0; a[i + 1] *= 2; score += a[i + 1];
		}
		else if (a[i] == a[i + 2] && a[i + 2] != 0 && a[i + 1] == 0)
		{
			a[i] = 0; a[i + 2] *= 2; score += a[i + 2];
		}
		else if (a[i] == a[i + 3] && a[i + 3] != 0 && a[i + 1] == 0 && a[i + 2] == 0)
		{
			a[i] = 0; a[i + 3] *= 2; score += a[i + 3];
		}
		if (a[i] == a[i + 1] && a[i + 1] != 0)
		{
			a[i] = 0; a[i + 1] *= 2; score += a[i + 1];
		}
	}

	for (int b = 0; b < 16; b += 4) //смещаем вправо 1-4 строчки
	{
		int g = 0;
		for (int i = 3 + b; i > -1 + b; i--) //перебираем по типу a[3],a[2],a[1],a[0]
		{
			if (a[i] == 0)
			{
				for (g = 1; g < 1 + (i - b); g++) //поиск ближайшего заполненного поля 3/2/1/0 раз
				{
					if (a[i - g] != 0)
					{
						a[i] = a[i - g];
						a[i - g] = 0;
						break;
					}
				}
				if ((g == 1 + (i - b)) || (g == (i - b))) { break; }
			}
		}
	}

	return score;
}

int l_mechanisms(int a[16], int score)
{
	for (int i = 0; i < 16; i += 4) //повышаем в 1-4 строчках для левого свайпа
	{
		if (a[i] == a[i + 1] && a[i + 1] != 0)
		{
			a[i + 1] = 0; a[i] *= 2; score += a[i];
		}
		else if (a[i] == a[i + 2] && a[i + 2] != 0 && a[i + 1] == 0)
		{
			a[i + 2] = 0; a[i] *= 2; score += a[i];
		}
		else if (a[i + 1] == a[i + 2] && a[i + 2] != 0)
		{
			a[i + 2] = 0; a[i + 1] *= 2; score += a[i + 1];
		}
		else if (a[i + 2] == a[i + 3] && a[i + 3] != 0)
		{
			a[i + 3] = 0; a[i + 2] *= 2; score += a[i + 2];
		}
		else if (a[i] == a[i + 3] && a[i + 3] != 0 && a[i + 1] == 0 && a[i + 2] == 0)
		{
			a[i + 3] = 0; a[i] *= 2; score += a[i];
		}
		else if (a[i + 1] == a[i + 3] && a[i + 3] != 0 && a[i + 2] == 0)
		{
			a[i + 3] = 0; a[i + 1] *= 2; score += a[i + 1];
		}
		if (a[i + 2] == a[i + 3] && a[i + 3] != 0)
		{
			a[i + 3] = 0; a[i + 2] *= 2; score += a[i + 2];
		}
	}

	for (int b = 0; b < 16; b += 4) //смещаем влево 1-4 строчки
	{
		int g = 0;
		for (int i = 0 + b; i < 4 + b; i++) //перебираем по типу a[0],a[1],a[2],a[3]
		{
			if (a[i] == 0)
			{
				for (g = 1; g < 4 - (i - b); g++) //поиск ближайшего заполненного поля 3/2/1/0 раз
				{
					if (a[i + g] != 0)
					{
						a[i] = a[i + g];
						a[i + g] = 0;
						break;
					}
				}
				if ((g == 4 - (i - b)) || (g == 3 - (i - b))) { break; }
			}
		}
	}

	return score;
}

int u_mechanisms(int a[16], int score)
{
	for (int i = 0; i < 4; i++) //промоутим в 1-4 столбиках для свайпа вверх
	{
		if (a[i] == a[i + 4] && a[i + 4] != 0)
		{
			a[i + 4] = 0; a[i] *= 2; score += a[i];
		}
		else if (a[i] == a[i + 8] && a[i + 8] != 0 && a[i + 4] == 0)
		{
			a[i + 8] = 0; a[i] *= 2; score += a[i];
		}
		else if (a[i + 4] == a[i + 8] && a[i + 8] != 0)
		{
			a[i + 8] = 0; a[i + 4] *= 2; score += a[i + 4];
		}
		else if (a[i + 8] == a[i + 12] && a[i + 12] != 0)
		{
			a[i + 12] = 0; a[i + 8] *= 2; score += a[i + 8];
		}
		else if (a[i] == a[i + 12] && a[i + 12] != 0 && a[i + 4] == 0 && a[i + 8] == 0)
		{
			a[i + 12] = 0; a[i] *= 2; score += a[i];
		}
		else if (a[i + 4] == a[i + 12] && a[i + 12] != 0 && a[i + 8] == 0)
		{
			a[i + 12] = 0; a[i + 4] *= 2; score += a[i + 4];
		}
		if (a[i + 8] == a[i + 12] && a[i + 12] != 0)
		{
			a[i + 12] = 0; a[i + 8] *= 2; score += a[i + 8];
		}
	}

	for (int b = 0; b < 4; b++) //смещаем вверх 1-4 столбика
	{
		int g = 0;
		for (int i = 0 + b; i < 16 + b; i += 4) //перебираем по типу a[0],a[4],a[8],a[12]
		{
			if (a[i] == 0)
			{
				for (g = 4; g < 16 - (i - b); g += 4) //поиск ближайшего заполненного поля 3/2/1/0 раз
				{
					if (a[i + g] != 0)
					{
						a[i] = a[i + g];
						a[i + g] = 0;
						break;
					}
				}
				if ((g == 16 - (i - b)) || (g == 12 - (i - b))) { break; }
			}
		}
	}

	return score;
}

int d_mechanisms(int a[16], int score)
{
	for (int i = 0; i < 4; i++) //промоутим в 1-4 столбиках для свайпа вниз
	{
		if (a[i + 8] == a[i + 12] && a[i + 12] != 0)
		{
			a[i + 8] = 0; a[i + 12] *= 2; score += a[i + 12];
		}
		else if (a[i + 4] == a[i + 12] && a[i + 12] != 0 && a[i + 8] == 0)
		{
			a[i + 4] = 0; a[i + 12] *= 2; score += a[i + 12];
		}
		else if (a[i + 4] == a[i + 8] && a[i + 8] != 0)
		{
			a[i + 4] = 0; a[i + 8] *= 2; score += a[i + 8];
		}
		else if (a[i] == a[i + 4] && a[i + 4] != 0)
		{
			a[i] = 0; a[i + 4] *= 2; score += a[i + 4];
		}
		else if (a[i] == a[i + 8] && a[i + 8] != 0 && a[i + 4] == 0)
		{
			a[i] = 0; a[i + 8] *= 2; score += a[i + 8];
		}
		else if (a[i] == a[i + 12] && a[i + 12] != 0 && a[i + 4] == 0 && a[i + 8] == 0)
		{
			a[i] = 0; a[i + 12] *= 2; score += a[i + 12];
		}
		if (a[i] == a[i + 4] && a[i + 4] != 0)
		{
			a[i] = 0; a[i + 4] *= 2; score += a[i + 4];
		}
	}

	for (int b = 0; b < 4; b++) //смещаем вниз 1-4 столбика
	{
		int g = 0;
		for (int i = 12 + b; i > -1 + b; i -= 4) //перебираем по типу a[12],a[8],a[4],a[0]
		{
			if (a[i] == 0)
			{
				for (g = 4; g < 4 + (i - b); g += 4) //поиск ближайшего заполненного поля 3/2/1/0 раз
				{
					if (a[i - g] != 0)
					{
						a[i] = a[i - g];
						a[i - g] = 0;
						break;
					}
				}
				if ((g == 4 + (i - b)) || (g == (i - b))) { break; }
			}
		}
	}

	return score;
}

int add_and_show(int a[16], int score, int highscore, int moves)
{
	moves++;
	//setka(a, score, highscore, moves); // ЗАЧЕМ???????????
	//Sleep(170);  // время задержки добавления плитки // ЗАЧЕМ???????????

	//рандомизация поля от 0 до 15 включительно и шанса 10% на выпадение 4-ки
	int rand_c;
	do
	{
		rand_c = 0 + rand() % 16;
	} while (a[rand_c] != 0);

	int chance = 1 + rand() % 10;
	if (chance != 1) { a[rand_c] = 2; }
	else { a[rand_c] = 4; }

	setka(a, score, highscore, moves);
	return moves;
}

bool check_for_win(int a[16])
{
	for (int i = 0; i < 16; i++)
	{
		if (a[i] == 2048)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	srand(time(NULL));
	bool again;
	int highscore = 0;
	for (int i = 0; i < 285; i++) { cout << endl; } //чтобы не дёргалась сетка
	cout << "Hello and welcome to the game." << endl;
	cout << "Use WASD or arrows to move." << endl;

	do
	{
		cout << "Input the net size (0 - big, 1 - small): ";
		cin >> SMALL_NET;

		int moves = 0;
		int score = 0;
		int a[16];

		primary_filling(a);

		setka(a, score, highscore, moves);

		while (true)
		{
			int rl_swipe = rl_matches(a); //есть ли совпадение в строчках (для проверки на проигрыш и на блокировку)
			int ud_swipe = ud_matches(a); //есть ли совпадение в столбиках

			if ((!rl_swipe) && (!ud_swipe))
			{
				bool loss = check_for_loss(a); //проверка на проигрыш
				if (loss)
				{
					cout << "You died" << endl;
					again = foo_again();
					break;
				}
			}

			string swipe = input();

			swipe = check_for_lock(a, rl_swipe, ud_swipe, swipe); //проверка на блокировку

			if (swipe == "right") { score = r_mechanisms(a, score); }
			else if (swipe == "left") { score = l_mechanisms(a, score); }
			else if (swipe == "up") { score = u_mechanisms(a, score); }
			else if (swipe == "down") { score = d_mechanisms(a, score); }

			if (score >= highscore) { highscore = score; }

			moves = add_and_show(a, score, highscore, moves);

			bool win = check_for_win(a); //проверка на выигрыш
			if (win)
			{
				cout << "Hooray! You won! \n";
				again = foo_again();
				break;
			}
		}
	} while (again);

	return 0;
}