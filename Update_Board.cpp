#include "Update_Board.h"
#include "SceneManager.h"
#include "MenuScene.h"
#include "Reset_Board.h"
void Update_Board::update_board(sf::RenderWindow& window) {
	A all;
	textures t;
	On_Button_Click be;
	Reset_Board r;
	// aaaaaaaaa //
	window.clear();
	window.draw(t.chessboard);
	if (A::transformationWhite == 1)
	{
		t.WhiteTransformation.setPosition(A::transformWHITE_x * all.size, A::transformWHITE_y * all.size);
		window.draw(t.WhiteTransformation);
	}
	if (A::transformationBlack == 1)
	{
		t.BlackTransformation.setPosition(A::transformBLACK_x * all.size, A::transformBLACK_y * all.size);
		window.draw(t.BlackTransformation);
	}
	if (A::isMoving == 1)
	{
		t.MoveImages.setPosition(be.pos.x - A::dx, be.pos.y - A::dy);
		window.draw(t.MoveImages);
	}






	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{

			if (A::board[i][j] != 0)
			{
				if (A::board[i][j] == BLACK_PAWN)
				{
					t.BlackPawn.setPosition(j * all.size, i * all.size);
					window.draw(t.BlackPawn);
				}
				if (A::board[i][j] == WHITE_PAWN)
				{
					t.WhitePawn.setPosition(j * all.size, i * all.size);
					window.draw(t.WhitePawn);
				}
				if (A::board[i][j] == BLACK_ROOK)
				{
					t.BlackRook.setPosition(j * all.size, i * all.size);
					window.draw(t.BlackRook);

				}
				if (A::board[i][j] == WHITE_ROOK)
				{
					t.WhiteRook.setPosition(j * all.size, i * all.size);
					window.draw(t.WhiteRook);

				}
				if (A::board[i][j] == WHITE_KNIGHT)
				{
					t.WhiteKnight.setPosition(j * all.size, i * all.size);
					window.draw(t.WhiteKnight);
				}
				if (A::board[i][j] == BLACK_KNIGHT)
				{
					t.BlackKnight.setPosition(j * all.size, i * all.size);
					window.draw(t.BlackKnight);
				}
				if (A::board[i][j] == BLACK_BISHOP)
				{
					t.BlackBishop.setPosition(j * all.size, i * all.size);
					window.draw(t.BlackBishop);
				}
				if (A::board[i][j] == WHITE_BISHOP)
				{
					t.WhiteBishop.setPosition(j * all.size, i * all.size);
					window.draw(t.WhiteBishop);
				}
				if (A::board[i][j] == WHITE_QUEEN)
				{
					t.WhiteQueen.setPosition(j * all.size, i * all.size);
					window.draw(t.WhiteQueen);
				}
				if (A::board[i][j] == BLACK_QUEEN)
				{
					t.BlackQueen.setPosition(j * all.size, i * all.size);
					window.draw(t.BlackQueen);
				}
				if (A::board[i][j] == BLACK_KING)
				{
					t.BlackKing.setPosition(j * all.size, i * all.size);
					window.draw(t.BlackKing);
				}
				if (A::board[i][j] == WHITE_KING)
				{
					t.WhiteKing.setPosition(j * all.size, i * all.size);
					window.draw(t.WhiteKing);
				}
			}
		}
	}

		//from here to white win
		if (A::white_win == 1) {
			// Load whitewin image
			if (!whitewin_tex.loadFromFile("images/whitewin.jpg")) {
				std::cerr << "Error loading  white win image!" << std::endl;
			}
			whitewin_sprite.setTexture(whitewin_tex);
			whitewin_sprite.setPosition(250, 250);
			window.draw(whitewin_sprite);

			pos = Mouse::getPosition(window);
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if ((pos.x > 369 && pos.x < 431) && (pos.y > 480 && pos.y < 540))
					{
						Reset_Board r;
						r.reset_all();
						SceneManager::getInstance().pushScene(std::make_unique<MenuScene>());
					}

				}
			}
		}

		//from here to black win
		if (A::black_win == 1) {
			// Load blackwin image
			if (!blackwin_tex.loadFromFile("images/blackwin.jpg")) {
				std::cerr << "Error loading  black win image!" << std::endl;
			}
			blackwin_sprite.setTexture(blackwin_tex);
			blackwin_sprite.setPosition(250, 250);
			window.draw(blackwin_sprite);

			pos = Mouse::getPosition(window);
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if ((pos.x > 369 && pos.x < 431) && (pos.y > 480 && pos.y < 540))
					{
						std::cout << "ok";
						r.reset_all();
						SceneManager::getInstance().pushScene(std::make_unique<MenuScene>());
					}

				}
			}
		}

		//from here to draw
		if (A::draw_position == 1) {
			// Load whitewin image
			if (!draw_tex.loadFromFile("images/draw.jpg")) {
				std::cerr << "Error loading  draw image!" << std::endl;
			}
			draw_sprite.setTexture(draw_tex);
			draw_sprite.setPosition(250, 250);
			window.draw(draw_sprite);

			pos = Mouse::getPosition(window);
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if ((pos.x > 369 && pos.x < 431) && (pos.y > 480 && pos.y < 540))
					{
						r.reset_all();
						SceneManager::getInstance().pushScene(std::make_unique<MenuScene>());
					}

				}
			}
		}
	}