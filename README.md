

# PROG1262 Assignment 2 Spring 2020

## Video Poker game (Jacks or Better)

**Objectives:**

- Use scoped enumerations.
- Use classes and objects.
- Create a program menu.
- Write code that is &quot;const-correct.&quot;

You are to write a game of &quot;Five Card Video Poker (see: [http://en.wikipedia.org/wiki/Video\_poker](http://en.wikipedia.org/wiki/Video_poker) )

[Video Example of game](./Jacks%20or%20Better%20Console.mp4) 

**Guidelines** :

- to be submitted via github (push on master branch)
- Menus will work with uppercase and lowercase letters.
- You must follow the structure of the program as shown below.
- The code must meet the class style guide
- The names of variables and functions should be descriptive.

**GamePlay** :

Start by dealing the player a hand of five cards. The player gets one draw, can specify which cards, if any they want to draw. Draw the new cards and display the hand. Tell them what rank their hand is an what the payout is. The player should be able to choose to play again.

**Instructions** :

- You must create Game class to play &quot;Jacks or Better&quot; rules video poker.
  - it must have a play() method that plays one round of poker
  - it must have a showPayTable() method that displays the pay table
  - it must have a welcome() method that prints a welcome message, including a brief introduction to the game.
  - it will have a Deck object and a Hand object as private members that are used to play the game
- your main() program will only use the Game object, the Game object will contain and manage the other classes to play the game.
- Only your Game object will use cin/cout. The Game is the &quot;Controller&quot;.
- You must create a VideoPoker class that represents the game or &quot;Model&quot;
- The VideoPoker class will have Deck, Hand, and any other objects you choose to use.

  - You should use a scoped enum **PokerHand** of the hand types (royal flush, full house, etc).
  - You should have a static map paySheet that maps PokerHand to payout amount for poker hands
  - Your hand class should be able to rank it&#39;s own hand and return it&#39;s value (pair, full house, fush etc)
  - your Hand class **should** have the following state (private members)
    	- std::vector\<Card::CardPtr\> hand; // your hand
    	- std::vector\<bool\> drawCard; // draw or hold flag
  - you must use std algorithms to identify the hand types
  - You should implement the following methods to use in scoring hands
  		- bool isRoyalFlush() const;
    	- bool isStraightFlush() const;
    	- bool isFourOfAKind() const;
    	- bool isFullHouse() const;
    	- bool isFlush() const;
    	- bool isStraight() const;
    	- bool isThreeOfAKind() const;
    	- bool isTwoPair() const;
    	- bool isJacksOrBetter() const;
    	- bool isPair() const;
- You may use the Card and Deck classes from homework.
- Your Deck class may use pointers to Card objects, or solid card objects. If you use pointers you **must** use smart pointers.
- Problems in Card, Deck, and Hand that can not be handled locally should cause a meaningful **exception** to be thrown.

**The definitions of different hands**

- **Pair** : Formed by two cards of the same rank (face value)
- **Jacks or Better** : a pair of jacks or higher ranked cards (J, Q, K, A)
- **Two Pair:** Formed by two pairs
- **Three of a Kind:** Formed by three cards of the same rank (face value)
- **Straight:** Composed of five cards of consecutive rank (face value)
- **Flush** : Composed of five cards of the same suit
- **Four of a Kind** : Formed by four cards of one rank accompanied by any card.
- **Straight Flush** : Composed of five cards of consecutive ranks of the same suit
- **Royal Flush** : a Straight Flush from 10 to Ace.

A hand value is always the highest possible value for that hand. For example even though a **three of a kind** hand contains a **pair** it is not ranked as a **pair** it is ranked as a **three of a kind.**

**Pay Sheet:**

| Hand	        				| Payout|
|---							|:-:	|
| Royal Flush	 				| 800 |
| Straight Flush				| 	50|
| Four of a Kind				| 25|
| Full House	 				| 9|
| Flush 						| 	6|
| Straight 					| 	4|
| Three of a Kind			| 3|
| Two Pair 					| 	2|
| Pair (Jacks or Better) 	| 	1| 
