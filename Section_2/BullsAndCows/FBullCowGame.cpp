#include "FBullCowGame.h"

/*-------------GETTERS-----------*/
/*Prevent getters from changing any members of the class with const keyword*/
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//Receives a VALID guess,increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//Increment the turn number
	MyCurrentTry++;
	//set up a return variable
	BullCowCount BullCowCount;
	
	//loop through all letters
	//cooperate letters against the hidden word
	
	return BullCowCount();
}
