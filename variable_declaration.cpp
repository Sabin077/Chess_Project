#include <sfml/Graphics.hpp>
#include <iostream>

#define LENGTH 8
#define BLACK_PAWN 1
#define WHITE_PAWN -1
#define BLACK_ROOK 2
#define WHITE_ROOK -2
#define BLACK_KNIGHT 3
#define WHITE_KNIGHT -3
#define BLACK_BISHOP 4
#define WHITE_BISHOP -4
#define BLACK_QUEEN 5
#define WHITE_QUEEN -5
#define BLACK_KING 6
#define WHITE_KING -6


class variables {
public:
	struct poz
	{
		int x, y;
	}oldPoz, whiteKing, blackKing, transformWHITE, transformBLACK;


	int  size = 100, isMoving = 0, x, y;

	int board[8][8] =
	{ 2, 3, 4, 5, 6, 4, 3, 2,
	  1, 1, 1, 1, 1, 1, 1, 1,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	 -1,-1,-1,-1,-1,-1,-1,-1,
	 -2,-3,-4,-5,-6,-4,-3,-2, };

	int rightWhiteRookM = 0, leftWhiteRookM = 0, whiteKingFirstMove = 0;
	int rightBlackRookM = 0, leftBlackRookM = 0, blackKingFirstMove = 0;

	int move = 0; // 0 = white is moving , 1 = black is moving

	int checkWhite = 0, checkBlack = 0;

	int transformationWhite = 0, transformationBlack = 0;	//used for promotion

};