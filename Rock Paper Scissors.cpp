	#include <iostream>
	#include <cstdlib>

	using namespace std;

	//                         Stone , Paper, Scissor

	enum enWeapons { Stone = 1, Paper = 2, Scissor = 3 };

	int ReadNumberInRange(const string msg, const  int From, const  int To)
	{
		int num;
		do
		{
			cout << msg;
			cin >> num;
		} while (num > To || num < From);
		return num;
	}
	int RandomNumberInRange(const int From,const int To)
	{
		return rand() % (To - From + 1) + From;
	}

	string WeaponName(const enWeapons weapon)
	{
		switch (weapon)
		{
		case Paper: return "Paper";

		case Scissor:return "Scissor";

		case Stone:return "Stone";

		default:
			return "Unknown Weapon";
		}
	}
	void ShowWeapons()
	{
		cout << "Available Weapons:\n\n";
		cout << "[1] Stone  [2] Paper  [3] Scissor ";
	}

	void ShowRoundHeader(const int RoundNumber)
	{
		cout << "\nRound [ " << RoundNumber << " ] begins :\n\n";
		ShowWeapons();
	}
	string RoundWinner(const enWeapons PlayerWeapon, const  enWeapons ComputerWeapon)
	{
		if (PlayerWeapon == ComputerWeapon) return "[No Winner]";
		switch (PlayerWeapon)
		{
		case Stone:
			if (ComputerWeapon == enWeapons::Scissor) return "[Player]";
			break;
		case Paper:
			if (ComputerWeapon == enWeapons::Stone) return "[Player]";
			break;
		case Scissor:
			if (ComputerWeapon == enWeapons::Paper) return "[Player]";
			break;
		}
		return "[Computer]";

	}
	void ShowRoundResult(const int RoundNumber, const  enWeapons PlayerWeapon, const  enWeapons ComputerWeapon)
	{
		cout << "-------------------(Round \'" << RoundNumber << "\')----------------- \n";
		cout << "Player Weapon : " << WeaponName(PlayerWeapon) << endl;
		cout << "Computer Weapon : " << WeaponName(ComputerWeapon) << endl;
		cout << "Round Winner : " << RoundWinner(PlayerWeapon, ComputerWeapon) << endl;
		cout << "-------------------------------------------------\n";

	}

	string FinalWinner(const int PlayersWonTimes, const  int ComputerWonTimes)
	{
		if (PlayersWonTimes > ComputerWonTimes)
			return "Player";
		else if (ComputerWonTimes > PlayersWonTimes)
			return "Computer";
		else
			return "no winner";
	}
	void ShowFinalResult(const int GameRounds, const int PlayersWonTimes, const int ComputerWonTimes, const int NoWinner)
	{
		cout << "\t\t--------------------------------------------------------\n";
		cout << "\t\t\t\t+++ G A M E  O V E R +++\n";
		cout << "\t\t--------------------------------------------------------\n";
		cout << "\t\t--------------------[Game Results]----------------------\n";
		cout << "\t\tGame Rounds : " << GameRounds << endl;
		cout << "\t\tPlayers Won Times : " << PlayersWonTimes << endl;
		cout << "\t\tComputer Won Times : " << ComputerWonTimes << endl;
		cout << "\t\tNoWinner : " << NoWinner << endl;
		cout << "\t\tFinal Winner : " << FinalWinner(PlayersWonTimes, ComputerWonTimes) << endl;
		cout << "\t\t-----------------------------------------------------------\n";
	}
	void TimesOfWin(const string Winner, int& PlayersWonTimes, int& ComputerWonTimes, int& NoWinner)
	{
		if (Winner == "[Player]")
			PlayersWonTimes++;
		else if (Winner == "[Computer]")
			ComputerWonTimes++;
		else
			NoWinner++;
	}
	bool ContinuePlaying()
	{
		int result = ReadNumberInRange("Do you want To play again . yes (1) , no (0) : ", 0, 1);
		return result == 1;
	}
	void TheGame(const int NumberOfRounds) // Game Logic
	{
		int PlayersWonTimes = 0, ComputerWonTimes = 0, NoWinner = 0;
		for (int i = 1; i <= NumberOfRounds; i++)
		{
			ShowRoundHeader(i);
			enWeapons PlayerWeapon = (enWeapons)ReadNumberInRange("\nPLease choose your weapon : ", 1, 3);
			enWeapons ComputerWeapon = (enWeapons)RandomNumberInRange(1, 3);
			ShowRoundResult(i, PlayerWeapon, ComputerWeapon);
			TimesOfWin(RoundWinner(PlayerWeapon, ComputerWeapon), PlayersWonTimes, ComputerWonTimes, NoWinner);
		}
		ShowFinalResult(NumberOfRounds, PlayersWonTimes, ComputerWonTimes, NoWinner);

	}
	int main()
	{
		srand((unsigned)time(NULL));
		do
		{
			int NumberOfRounds = ReadNumberInRange("Enter the number of rounds ( 1 : 10 ) : ", 1, 10);
			TheGame(NumberOfRounds);
			cout << "\n\n\n";
		} while (ContinuePlaying());


	}
