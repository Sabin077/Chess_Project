#include "Reset_Board.h"

void Reset_Board::reset_all() {
	A::board[0][0] = 2;
	A::board[0][1] = 3;
	A::board[0][2] = 4;
	A::board[0][3] = 5;
	A::board[0][4] = 6;
	A::board[0][5] = 4;
	A::board[0][6] = 3;
	A::board[0][7] = 2;

	for (int i = 0; i < 8; i++) {
		A::board[1][i] = 1;
	}

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			A::board[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++) {
		A::board[6][i] = -1;
	}


	A::board[7][0] = -2;
	A::board[7][1] = -3;
	A::board[7][2] = -4;
	A::board[7][3] = -5;
	A::board[7][4] = -6;
	A::board[7][5] = -4;
	A::board[7][6] = -3;
	A::board[7][7] = -2;
	A::x = 0;
	A::isMoving = 0;
	A::y = 0;
	A::rightWhiteRookM = 0;
	A::leftWhiteRookM = 0;
	A::rightBlackRookM = 0;
	A::leftBlackRookM = 0;
	A::whiteKingFirstMove = 0;
	A::blackKingFirstMove = 0;
	A::move = 0;
	A::checkWhite = 0;
	A::checkBlack = 0;
	A::transformationBlack = 0;
	A::transformationWhite = 0;
	A::dx = 0;
	A::dy = 0;
	A::noMovedPiece = 0;
	A::black_win = 0;
	A::white_win = 0;
	A::draw_position = 0;

	A::oldPoz_x = 0;
	A::oldPoz_y = 0;
	A::whiteKing_x = 0;
	A::whiteKing_y = 0;
	A::blackKing_x = 0;
	A::blackKing_y = 0;
	A::transformWHITE_x = 0;
	A::transformWHITE_y = 0;
	A::transformBLACK_x = 0;
	A::transformBLACK_y = 0;

}