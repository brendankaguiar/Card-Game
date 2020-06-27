#include <iostream>
#include "Bag.h"

#define first_place 6
#define second_place 7
#define third_place 8

static int count = 0;

void scoreCounter();
void ranking();

int main()
{
	std::string clubs[]={ "Joker","Ace", "Two",
	"Three", "Four", "Five", "Six", "Seven", "Eight",
	"Nine", "Ten", "Jack", "Queen", "King"};
	// Creates the bag
	
	 ArrayBag<std::string> grabBag;
	 
	// Place six cards in the bag
	grabBag.add(clubs[1]);
	grabBag.add(clubs[2]);
	grabBag.add(clubs[4]);
	grabBag.add(clubs[8]);
	grabBag.add(clubs[10]);
	grabBag.add(clubs[11]);
	
	// Get guess and check it
	int guess = 0;

	while(!grabBag.isEmpty())
	{
		std::cout << "What is your guess? (1 for Ace to 13 for King): ";
		std::cin >> guess;
		// Is card in the Bag
		if (grabBag.contains(clubs[guess]))
		{
			// Good Guess - remove card from bag
			std::cout << "You got the right card!\n";
			grabBag.remove(clubs[guess]);
			scoreCounter();
		}
		else
		{
			std::cout<< "Card not in bag.\n";
			scoreCounter();
		} // end if
	} // end while
	std::cout << "No more cards in the bag.\n";
	ranking();
	system("pause");
	return 0;
} // end main

#include "Bag.cpp" //included for the template <typename ItemType>

void scoreCounter()
{
	count++;
} // end scoreCounter

void ranking()
{
	if (count == first_place)
		std::cout << "Congrats you got first place. You must be a coder.\n";
	else if (count == second_place)
		std::cout << "Congrats you got second place. You must be a clairvoyant.\n";
	else if (count == third_place)
		std::cout << "Congrats you got third place. You must be a magician.\n";
	else
		std::cout << "You did not place in the ranking system. Better luck next time.\n";
} // end ranking