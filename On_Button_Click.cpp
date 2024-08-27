#include "On_Button_Click.h"

void On_Button_Click::button_actions(sf::RenderWindow& window) {
	A all;
	textures t;
	On_Button_Click be;
	be.pos = Mouse::getPosition(window);
	A::x = be.pos.x / all.size;
	A::y = be.pos.y / all.size;
	Event e;
	while (window.pollEvent(e))
	{
		//to close the program (X)
		if (e.type == Event::Closed)
		{
			window.close();
		}
		window.clear();
		if (e.type == Event::MouseButtonPressed)
		{
			if (e.key.code == Mouse::Left)
			{
				if (A::transformationWhite == 1)
				{
					if (be.pos.y >= A::transformWHITE_y * all.size && be.pos.y <= (A::transformWHITE_y + 1) * all.size && be.pos.x >= A::transformWHITE_x * all.size && be.pos.x <= (A::transformWHITE_x + 1) * all.size)
					{
						int xx = be.pos.x % 100, yy = be.pos.y % 100;
						//std::cout << "pos.y=" << yy << "\n";
						//std::cout << "pos.x=" << xx << "\n";
						if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
						{
							A::board[A::transformWHITE_y][A::transformWHITE_x] = WHITE_ROOK;
							A::transformationWhite = 0;
						}
						if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
						{
							A::board[A::transformWHITE_y][A::transformWHITE_x] = WHITE_QUEEN;
							A::transformationWhite = 0;
						}
						if (xx > 50 && xx < 100 && yy>50 && yy < 100)
						{
							A::board[A::transformWHITE_y][A::transformWHITE_x] = WHITE_KNIGHT;
							A::transformationWhite = 0;
						}
						if (xx < 50 && xx>0 && yy > 50 && A::y < 100)
						{
							A::board[A::transformWHITE_y][A::transformWHITE_x] = WHITE_BISHOP;
							A::transformationWhite = 0;
						}
						if (A::transformationWhite == 0)
						{
							all.posBlackKing();
							int h = all.BlackKingCheck(A::blackKing_x, A::blackKing_y);
							if (h == 0)
							{
								A::checkBlack = 1;
							}
						}
					}
				}
				if (A::transformationBlack == 1)
				{
					if (be.pos.y >= A::transformBLACK_y * all.size && be.pos.y <= (A::transformBLACK_y + 1) * all.size && be.pos.x >= A::transformBLACK_x * all.size && be.pos.x <= (A::transformBLACK_x + 1) * all.size)
					{
						int xx = be.pos.x % 100, yy = be.pos.y % 100;
						//std::cout << "pos.y=" << yy << "\n";
						//std::cout << "pos.x=" << xx << "\n";
						if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
						{
							A::board[A::transformBLACK_y][A::transformBLACK_x] = BLACK_ROOK;
							A::transformationBlack = 0;
						}
						if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
						{
							A::board[A::transformBLACK_y][A::transformBLACK_x] = BLACK_QUEEN;
							A::transformationBlack = 0;
						}
						if (xx > 50 && xx < 100 && yy>50 && yy < 100)
						{
							A::board[A::transformBLACK_y][A::transformBLACK_x] = BLACK_KNIGHT;
							A::transformationBlack = 0;
						}
						if (xx < 50 && xx>0 && yy > 50 && A::y < 100)
						{
							A::board[A::transformBLACK_y][A::transformBLACK_x] = BLACK_BISHOP;
							A::transformationBlack = 0;
						}
						if (A::transformationBlack == 0)
						{
							all.posWhiteKing();
							int h = all.WhiteKingCheck(A::whiteKing_x, A::whiteKing_y);
							if (h == 0)
							{
								A::checkWhite = 1;
							}
						}
					}
				}
				if (A::board[A::y][A::x] != 0)
				{
					A::dx = be.pos.x - A::x * 100;
					A::dy = be.pos.y - A::y * 100;
					if (A::board[A::y][A::x] == BLACK_PAWN && A::move == 1)	// 1 means black turn
					{
						A::noMovedPiece = BLACK_PAWN;
						t.MoveImages = t.BlackPawn;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == WHITE_PAWN && A::move == 0)
					{
						A::noMovedPiece = WHITE_PAWN;
						t.MoveImages = t.WhitePawn;
						A::board[A::y][A::x] = 0;
						//std::cout << "1";
					}
					if (A::board[A::y][A::x] == BLACK_ROOK && A::move == 1)
					{
						A::noMovedPiece = BLACK_ROOK;
						t.MoveImages = t.BlackRook;
						A::board[A::y][A::x] = 0;

					}
					if (A::board[A::y][A::x] == WHITE_ROOK && A::move == 0)
					{
						A::noMovedPiece = WHITE_ROOK;
						t.MoveImages = t.WhiteRook;
						A::board[A::y][A::x] = 0;

					}
					if (A::board[A::y][A::x] == WHITE_KNIGHT && A::move == 0)
					{
						A::noMovedPiece = WHITE_KNIGHT;
						t.MoveImages = t.WhiteKnight;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == BLACK_KNIGHT && A::move == 1)
					{
						A::noMovedPiece = BLACK_KNIGHT;
						t.MoveImages = t.BlackKnight;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == BLACK_BISHOP && A::move == 1)
					{
						A::noMovedPiece = BLACK_BISHOP;
						t.MoveImages = t.BlackBishop;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == WHITE_BISHOP && A::move == 0)
					{
						A::noMovedPiece = WHITE_BISHOP;
						t.MoveImages = t.WhiteBishop;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == WHITE_QUEEN && A::move == 0)
					{
						A::noMovedPiece = WHITE_QUEEN;
						t.MoveImages = t.WhiteQueen;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == BLACK_QUEEN && A::move == 1)
					{
						A::noMovedPiece = BLACK_QUEEN;
						t.MoveImages = t.BlackQueen;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == BLACK_KING && A::move == 1)
					{
						A::noMovedPiece = BLACK_KING;
						t.MoveImages = t.BlackKing;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == WHITE_KING && A::move == 0)
					{
						A::noMovedPiece = WHITE_KING;
						t.MoveImages = t.WhiteKing;
						A::board[A::y][A::x] = 0;
					}
					if (A::board[A::y][A::x] == 0)//if the selected piece has left its original square to move to next square 
					{
						A::isMoving = 1;
						A::oldPoz_x = A::x;
						A::oldPoz_y = A::y;
					}
				}
			}
		}
		if (e.type == Event::MouseButtonReleased)
		{
			if (e.key.code == Mouse::Left)
			{
				int ok = 2;	//set any thing rather than 0 and 1

				//check if the move is possible
				if (A::noMovedPiece == WHITE_PAWN && A::isMoving == 1)
				{
					ok = all.PawnW(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == BLACK_PAWN && A::isMoving == 1)
				{
					ok = all.PawnB(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == WHITE_ROOK && A::isMoving == 1)
				{
					ok = all.RookW(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
					if (ok == 1 && A::leftWhiteRookM == 0 && A::oldPoz_y == 7 && A::oldPoz_x == 0)
					{
						A::leftWhiteRookM = 1;
					}
					if (ok == 1 && A::rightWhiteRookM == 0 && A::oldPoz_y == 7 && A::oldPoz_x == 7)
					{
						A::rightWhiteRookM = 1;
					}
				}
				if (A::noMovedPiece == BLACK_ROOK && A::isMoving == 1)
				{
					ok = all.RookB(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
					if (ok == 1 && A::rightBlackRookM == 0 && A::oldPoz_y == 0 && A::oldPoz_x == 7)
					{
						A::rightBlackRookM = 1;
					}
					if (ok == 1 && A::leftBlackRookM == 0 && A::oldPoz_y == 0 && A::oldPoz_x == 0)
					{
						A::leftBlackRookM = 1;
					}
				}
				if (A::noMovedPiece == WHITE_BISHOP && A::isMoving == 1)
				{
					ok = all.BishopW(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == BLACK_BISHOP && A::isMoving == 1)
				{
					ok = all.BishopB(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == WHITE_QUEEN && A::isMoving == 1)
				{
					ok = all.QueenW(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == BLACK_QUEEN && A::isMoving == 1)
				{
					ok = all.QueenB(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == WHITE_KNIGHT && A::isMoving == 1)
				{
					ok = all.KnightW(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == BLACK_KNIGHT && A::isMoving == 1)
				{
					ok = all.KnightB(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
				}
				if (A::noMovedPiece == BLACK_KING && A::isMoving == 1)
				{
					ok = all.BlackKING(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
					if (ok == 1 && A::blackKingFirstMove == 0)
					{
						A::blackKingFirstMove = 1; //lose right to castle
					}
				}
				if (A::noMovedPiece == WHITE_KING && A::isMoving == 1)
				{
					ok = all.WhiteKING(A::oldPoz_x, A::oldPoz_y, A::x, A::y);
					if (ok == 1 && A::whiteKingFirstMove == 0)
					{
						A::whiteKingFirstMove = 1;	//lose right to castle
					}
				}
				
				//if move is valid
				if (ok == 1)
				{
					int nr = A::board[A::y][A::x];
					A::board[A::y][A::x] = A::noMovedPiece;

					//promotion for white
					if (A::y == 0 && A::noMovedPiece == WHITE_PAWN)
					{
						A::transformationWhite = 1;
						A::transformWHITE_x = A::x;
						A::transformWHITE_y = A::y;
						A::board[A::y][A::x] = 0;
					}

					//promotion for black
					if (A::y == 7 && A::noMovedPiece == BLACK_PAWN)
					{
						A::transformationBlack = 1;
						A::transformBLACK_x = A::x;
						A::transformBLACK_y = A::y;
						A::board[A::y][A::x] = 0;
					}

					//white turn
					if (A::move == 0)	//white turn
					{
						if (A::checkWhite == 1)
						{
							all.posWhiteKing();
							int s = all.WhiteKingCheck(A::whiteKing_x, A::whiteKing_y);
							if (s == 0)	//move cancel because it failed to stop check
							{
								A::board[A::oldPoz_y][A::oldPoz_x] = A::noMovedPiece;
								A::board[A::y][A::x] = nr;
							}
							else	
							{
								A::checkWhite = 0;
								all.posBlackKing();
								int sah = all.BlackKingCheck(A::blackKing_x, A::blackKing_y);
								if (sah == 0)
								{
									A::checkBlack = 1;
								}
								A::move = 1;
							}
						}
						else
						{
							all.posWhiteKing();
							int sa = all.WhiteKingCheck(A::whiteKing_x, A::whiteKing_y);	//to check for pinned piece returns 0 for pinned piece
							if (sa == 0)
							{
								A::board[A::oldPoz_y][A::oldPoz_x] = A::noMovedPiece;
								A::board[A::y][A::x] = nr;
							}
							else
							{
								all.posBlackKing();
								int sah = all.BlackKingCheck(A::blackKing_x, A::blackKing_y);
								if (sah == 0)
								{
									A::checkBlack = 1;
								}
								A::move = 1;
							}
						}
						if (A::checkBlack == 1) {
							if (all.checkmate(false)) {
								A::white_win = 1;
							}
						}
						//check draw
						if (all.isInsufficientMaterial() || all.isStalemate(true)) {
							A::draw_position = 1;
						}
						
					}

					//blackturn
					else	
					{
						if (A::checkBlack == 1)
						{
							all.posBlackKing();
							int s = all.BlackKingCheck(A::blackKing_x, A::blackKing_y);
							if (s == 0)
							{
								A::board[A::oldPoz_y][A::oldPoz_x] = A::noMovedPiece;
								A::board[A::y][A::x] = nr;
							}
							else
							{
								A::checkBlack = 0;
								all.posWhiteKing();
								int sah = all.WhiteKingCheck(A::whiteKing_x, A::whiteKing_y);
								if (sah == 0)
								{
									A::checkWhite = 1;
								}
								A::move = 0;
							}
						}
						else
						{
							all.posBlackKing();
							int sa = all.BlackKingCheck(A::blackKing_x, A::blackKing_y);
							if (sa == 0)
							{
								A::board[A::oldPoz_y][A::oldPoz_x] = A::noMovedPiece;
								A::board[A::y][A::x] = nr;
							}
							else
							{
								all.posWhiteKing();
								int sah = all.WhiteKingCheck(A::whiteKing_x, A::whiteKing_y);
								if (sah == 0)
								{
									A::checkWhite = 1;
								}
								A::move = 0;
							}
						}
						if (A::checkWhite == 1) {
							if (all.checkmate(true)) {
								A::black_win = 1;
							}
						}
						//check draw
						if (all.isInsufficientMaterial() || all.isStalemate(false)) {
							A::draw_position = 1;
						}
						
					}
				}

				//if the move is invalid
				else if (ok == 0){
					A::board[A::oldPoz_y][A::oldPoz_x] = A::noMovedPiece;
				}
				A::isMoving = 0;
			}
		}
	}
}