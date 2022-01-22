# Battle-Ship-Game
Description: This program plays BattelShip game. Each of user and computer has five ships and has to attack opponent's ships.


main.cpp <br />
	// 'srand(time(0))' initialized a random number generator.
	It will ask user whether to start the game or exit the game with explanation of the game.
	If user wants to start the game, it will start game with 'PlayGame()' function of Game class object.

Ship.h <br />
	It contains the defition for the class Ship.

Ship.cpp <br />
	'setEndPts' function will set starting location and end location of each ship.
	Those locations will be used when user or computer attack opponent's grid.

Grid.h <br />
	Contains the definition for the class Grid.

Grid.cpp
	A constructor with a parameter will need a vector with Ship claa objects.
	It will place the ships on the board according to the direction and the starting location of each ship.
	'attackBoard' function will be used when each player attack opponent.
	It will mark the attacked location as 'X'.

ComputerGrid.h
	Contains the definition for the class ComputerGrid.
	It inherits 'Grid' class.

ComputerGrid.cpp
	'setRandomShips' function will place five ships on the conputer's grid without overlapping.

Player.h
	It contains the definition for the class Player.

Player.cpp

Game.h
	Contains the definition for the class Game.
	It has two players in it: user and computer.

Game.cpp
	'PlayGame' function will start a new game.
	It will ask user to attack a location of computer's grid, and computer will attack a random location of user's grid.
	If one of players succeed to attack 5 ships, then the game will ask user whether to play again or exit the game.
	If user wants to play it again, It will recurse 'PlayGame' function. If not, it will exit the game.
	'PattackC' function is used when player attacks computer. It will check if any ship is located on the attacked location.
	If any ship gets attacked, the board will mark 'X's on that ship's locations.
	'CattackP' function is user when computer attacks player. It works the same way as 'PattackC' function, but it will randomly attack a location.
	
Exception.h
	Contains the definition for the class Exception.
	It has three different exceptions.
	1. When the reading file has any overlapped ships, the program will terminate with 'OverLap' exception.
	2. When the reading file has any ships that are out of board, the program will terminate with 'OutofGrid' exception.
	3. When the reading file has any ships that do not match any type of ship, the program will terminate with 'WrongName' exception.

Exception.cpp
