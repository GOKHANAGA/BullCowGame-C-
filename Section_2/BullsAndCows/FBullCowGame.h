#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //const
	void Reset(); //TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);

	//provide a method for counting bulls & cows, and increasing try number(#)


private:
	//see const for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;

};