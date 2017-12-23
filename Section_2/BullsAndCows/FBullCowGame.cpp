#pragma once

#include "FBullCowGame.h"
#include <map>

//to make syntax unreal friendly
#define TMap std::map 

/*-------------GETTERS-----------*/
/*Prevent getters from changing any members of the class with const keyword*/

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame() { Reset(); } //Default const

int32 FBullCowGame::GetMaxTries() const {
	//Change try amount according to hidden word's length
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,7},{5,10},{6,15},{7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";//This must be an isogram

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {//if the guess isn't an isogram 
		return EGuessStatus::Not_Isogram;//return an error TODO Write function
	}
	else if (!IsLowercase(Guess)) {
		//if the guess isn't all lowercase
		return EGuessStatus::Not_Lowercase;
		//return error
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		//if the guess length is wrong
			//return error
		return EGuessStatus::Wrong_Length;
	}
	else {
		//otherwise
			//return OK
		return EGuessStatus::OK;
	}
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength();//assuming that guess and hidden word is same length

	//loop through all letters in hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {

		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			//if they match 
			if (MyHiddenWord[MHWChar] == Guess[GChar]) {
				//if they re in the same place
					//increment bulls 
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					//if they are not
						//increment cow 
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;//setup our map
	for (auto Letter : Word) //for all letters of the word
	{
		Letter = tolower(Letter); //handle mixed text,all should be lowercase
				//if letter exists in map return false
		if (LetterSeen[Letter]) {
			return false;//we do NOT have an isogram
		}
		else {
			//otherwise add the letter to the map.
			LetterSeen[Letter] = true;
		}
	}
	return true; // for example in xases /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word == "/0" || Word == "") { return false; }
	for (auto Letter : Word) {//loop through all letters in the word
		if (!islower(Letter)) {//if there is a letter which is not lowercase
			return false;//return false
		}
	}
	return true;//if there is no uppercase letter return true...
}
