#ifndef HEADER_H
#define HEADER_H
#include <sfml/Graphics.hpp>

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

using namespace std;

class A
{
public:

	static int oldPoz_x, oldPoz_y, whiteKing_x, whiteKing_y, blackKing_x, blackKing_y;
	static int transformWHITE_x, transformWHITE_y, transformBLACK_x, transformBLACK_y;

	static int isMoving, x, y;
	int  size = 100;

	static  int board[8][8];

	static int rightWhiteRookM , leftWhiteRookM , whiteKingFirstMove ;
	static int rightBlackRookM , leftBlackRookM , blackKingFirstMove ;

	static int move ; // 0 = white is moving , 1 = black is moving

	static int checkWhite , checkBlack ;	//1 is it is in check position
	static int black_win, white_win, draw_position;

	static int transformationWhite , transformationBlack ;	//used for promotion
	static float dx , dy ;
	static int noMovedPiece ;

	int PawnW(int ox, int oy, int nx, int ny);
	int PawnB(int ox, int oy, int nx, int ny);
	int RookW(int ox, int oy, int nx, int ny);
	int RookB(int ox, int oy, int nx, int ny);
	int BishopW(int ox, int oy, int nx, int ny);
	int BishopB(int ox, int oy, int nx, int ny);
	int QueenW(int ox, int oy, int nx, int ny);
	int QueenB(int ox, int oy, int nx, int ny);
	int KnightW(int ox, int oy, int nx, int ny); 
	int KnightB(int ox, int oy, int nx, int ny);
	int PawnWCheck(int posx, int posy, int kingx, int kingy);
	int RookWCheck(int ox, int oy, int kingx, int kingy);
	int BishopWCheck(int ox, int oy, int kingx, int kingy);
	int QueenWCheck(int ox, int oy, int kingx, int kingy);
	int KnightWCheck(int ox, int oy, int kingx, int kingy);
	int KingWCheck(int ox, int oy, int kingx, int kingy);
	int PawnBCheck(int ox, int oy, int kingx, int kingy);
	int RookBCheck(int ox, int oy, int kingx, int kingy);
	int BishopBCheck(int ox, int oy, int kingx, int kingy);
	int QueenBCheck(int ox, int oy, int kingx, int kingy);
	int KnightBCheck(int ox, int oy, int kingx, int kingy);
	int KingBCheck(int ox, int oy, int kingx, int kingy);
	int BlackKingCheck(int poskingx, int poskingy);
	int BlackKING(int ox, int oy, int nx, int ny);
	int WhiteKingCheck(int poskingx, int poskingy);
	int WhiteKING(int ox, int oy, int nx, int ny);
	void posWhiteKing();
	void posBlackKing();

	/*void CheckMateBlack();
	void CheckMateWhite();
	void StaleMate_Black();*/

	bool checkmate(bool isWhite);
	bool isKingInCheck(int kingX, int kingY, bool isWhite);
	bool isValidMove(int ox, int oy, int nx, int ny);
	bool canKingEscapeCheck(int kingX, int kingY, bool isWhite);
	bool canAnyPieceBlockOrCapture(int kingX, int kingY, bool isWhite);

	//for draw
	bool isStalemate(bool isWhite);
	bool isInsufficientMaterial();
	
};


#endif