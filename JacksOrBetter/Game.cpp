#include "Game.h"
#include"VideoPoker.h"

Deck deck;
Hand hand;
VideoPoker videoPoker;
Game::Game()
{
}

Game::~Game()
{
}

void Game::play_()
{
	char userInput;
	do {

		gamesMenu();
		userInput = getUserInput();

		switch (userInput)
		{
		case 'P':
			dealHand();
			break;
		case 'S':
			showPayTable();
		case 'W':
			welcome();
		default:
			break;
		}
	} while (userInput != 'Q');


}

void Game::gamesMenu() const
{
	system("cls");
	std::cout <<
		"   ***************Jack or Better Poker**************\n" <<
		"   *  (P) - Game                                 ***\n" <<
		"   *  (S) - Show pay table                       ***\n" <<
		"   *  (W) - Welcome and instruction              ***\n" <<
		"   *                                             ***\n" <<
		"   *  (Q) - Quit program                         ***\n" <<
		"   *************************************************\n\n" <<
		"   ";
}

void Game::showPayTable() const
{
	std::cout <<
		"\n" <<
		"************** Pay Table **************\n" <<
		"*                                     *\n" <<
		"*        Royal Flush:      800        *\n" <<
		"*        Strait Flush:     50         *\n" <<
		"*        Four of a Kind:   25         *\n" <<
		"*        Full House:       9          *\n" <<
		"*        Flush:            6          *\n" <<
		"*        Straight:         4          *\n" <<
		"*        Three of a Kind:  3          *\n" <<
		"*        Two Pair:         2          *\n" <<
		"*        One Pair:         1          *\n" <<
		"*        Jack or Better:   1          *\n" <<
		"*                                     *\n" <<
		"***************************************\n" << std::endl;
	system("pause");
}

void Game::welcome() const
{
	std::cout << "\nHi and welcome to Jack or Better poker.\n" <<
		"\nVideo poker is a casino game based on five-card draw poker. "<<
		"\nIt is played on a computerized console similar in size to a slot machine." << std::endl;

	system("pause");
}

void Game::dealHand()
{
	system("cls");

	hand.clear();
	deck.shuffle();

	while (hand.size() < 5)
	{
		hand.addCard(deck.draw());
	}

	std::cout << hand.toString() << std::endl;
	findValueOftheHand();


	system("pause");

}

void Game::findValueOftheHand() const
{
	if (hand.isRoyalFlush() == true)
	{

		std::cout << "Royal Flush You win " << videoPoker.paySheet.at(PokerHand::isRoyalFlush) << " time you bet." << std::endl;
	}
	else if (hand.isStraitFlush() == true)
	{
		std::cout << "Strait Flush You win " << videoPoker.paySheet.at(PokerHand::isStraitFlush) << " time you bet." << std::endl;
	}
	else if (hand.isFourOfaKind() == true)
	{
		std::cout << "Four of a Kind You win " << videoPoker.paySheet.at(PokerHand::isFourOfaKind) << " time you bet." << std::endl;
	}
	else if (hand.isFullHouse() == true)
	{
		std::cout << "Full house You win " << videoPoker.paySheet.at(PokerHand::isFullHouse) << " time you bet." << std::endl;
	}
	else if (hand.isFlush() == true)
	{
		std::cout << "Flush You win " << videoPoker.paySheet.at(PokerHand::isFlush) << " time you bet." << std::endl;
	}
	else if (hand.isStrait() == true)
	{
		std::cout << "Strait You win " << videoPoker.paySheet.at(PokerHand::isStrait) << " time you bet." << std::endl;
	}
	else if (hand.isThreeOfakind() == true)
	{
		std::cout << "Three of a Kind You win " << videoPoker.paySheet.at(PokerHand::isThreeOfakind) << " time you bet." << std::endl;
	}
	else if (hand.isTwoPair() == true)
	{
		std::cout << "Two Pair You win " << videoPoker.paySheet.at(PokerHand::isTwoPair) << " time you bet." << std::endl;
	}
	//not working
	else if (hand.isJacksOrBetter() == true)
	{
		std::cout << "Jacks Or Better You win " << videoPoker.paySheet.at(PokerHand::isJacksOrBetter) << " time you bet." << std::endl;
	}
	else if (hand.isPair() == true)
	{
		std::cout << "One Pair You win " << videoPoker.paySheet.at(PokerHand::isPair) << " time you bet." << std::endl;
	}

	else
		std::cout << "You Lose " << 0 << " time you bet." << std::endl;
}

char Game::getUserInput() const
{
	char userInput;
	std::cin >> userInput;
	userInput = toupper(userInput);

	while (std::cin.fail())
	{

		std::cin.clear();
		std::cout << "Please enter a valid choise\n";
		std::cin >> userInput;
		system("pause");
		std::cin.ignore();
	}


	return userInput;
}
