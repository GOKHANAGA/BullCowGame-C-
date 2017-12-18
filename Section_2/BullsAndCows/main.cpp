/*
This is the console executable, that makes use of the BullCow class
this acts as the view in a MVC Pattern, and is responsible for aþþ
user intereaction.For game logic see the FBullCowGame class
*/
#include<iostream>
#include<string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; //instantiate a new game

//The entry point for our application
int main() {

	do {
		PrintIntro();
		PlayGame();
		//TODO add a game summary
	} while (AskToPlayAgain());

	return 0;
}


void PlayGame()
{
	BCGame.Reset();
	//Loop for the number of turns asking for gueeses
		//TODO change from For to while loop once we are validating tries
	for (int32 i = 0; i < BCGame.GetMaxTries(); i++) {
		//repeat the guess back to them
		std::cout << "Your guess was :" << GetGuess() << std::endl; //TODO make loop checking valid guess
		//Submit valid guess to the game
		//Print number of bull and cows
		std::cout << std::endl;
	}

	//TODO sumarise game
}

//int32roduce the game

FText GetGuess() {

	//get a guess from the player
	std::cout << "Try" << BCGame.GetCurrentTry() << ".Enter your guess: ";
	FText Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintIntro() {

	constexpr int32 WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows,a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letters of isogram i'm thinking of?\n";

	return;
}
