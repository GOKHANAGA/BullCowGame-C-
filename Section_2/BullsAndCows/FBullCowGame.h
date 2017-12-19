#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls=0;
	int32 Cows=0;
};

class FBullCowGame {
public:
	FBullCowGame(); //const
	void Reset(); //TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);

	//counts bulls & cows, and increases try number(#) assuming valid guess
	BullCowCount SubmitGuess(FString);


private:
	//see const for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;

};
