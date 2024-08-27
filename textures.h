#ifndef TEXTURE_H
#define TEXTURE_H
#include <sfml/Graphics.hpp>
#include<iostream>

using namespace sf;

class textures{
public:
		Texture CB, BP, WP, BR, WR, BK, WK, BB, WB, BQ, WQ, BKING, WKING,BT, WT;
		sf::Sprite chessboard;
		sf::Sprite BlackPawn;
		sf::Sprite WhitePawn;
		sf::Sprite BlackRook;
		sf::Sprite WhiteRook;
		sf::Sprite WhiteKnight;
		sf::Sprite BlackKnight;
		sf::Sprite BlackBishop;
		sf::Sprite WhiteBishop;
		sf::Sprite WhiteQueen;
		sf::Sprite BlackQueen;
		sf::Sprite BlackKing;
		sf::Sprite WhiteKing;
		sf::Sprite MoveImages;
		sf::Sprite WhiteTransformation;
		sf::Sprite BlackTransformation;
		textures() {
			//to load images
			CB.loadFromFile("images/board.png");
			BP.loadFromFile("images/BlackPawn.png");
			WP.loadFromFile("images/WhitePawn.png");
			BR.loadFromFile("images/BlackRook.png");
			WR.loadFromFile("images/WhiteRook.png");
			WK.loadFromFile("images/WhiteKnight.png");
			BK.loadFromFile("images/BlackKnight.png");
			BB.loadFromFile("images/BlackBishop.png");
			WB.loadFromFile("images/WhiteBishop.png");
			WQ.loadFromFile("images/WhiteQueen.png");
			BQ.loadFromFile("images/BlackQueen.png");
			BKING.loadFromFile("images/BlackKing.png");
			WKING.loadFromFile("images/WhiteKing.png");
			WT.loadFromFile("images/TransformationWhite.png");
			BT.loadFromFile("images/TransformationBlack.png");

			chessboard.setTexture(CB);
			BlackPawn.setTexture(BP);
			WhitePawn.setTexture(WP);
			BlackRook.setTexture(BR);
			WhiteRook.setTexture(WR);
			BlackBishop.setTexture(BB);
			WhiteBishop.setTexture(WB);
			BlackKnight.setTexture(BK);
			WhiteKnight.setTexture(WK);
			BlackQueen.setTexture(BQ);
			WhiteQueen.setTexture(WQ);
			BlackKing.setTexture(BKING);
			WhiteKing.setTexture(WKING);
			WhiteTransformation.setTexture(WT);
			BlackTransformation.setTexture(BT);
		}
			
};

#endif