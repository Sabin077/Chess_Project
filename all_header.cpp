#include "all_header.h"
#include<iostream>


int A::PawnW(int ox, int oy, int nx, int ny)//old x,y ani new x,y
{
	if (oy == 6)	//pawn can move two squares if its the starting position
	{
		if ((ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0) || (ny == oy - 2 && nx == ox && board[oy - 1][ox] == 0 && board[oy - 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy - 1][ox - 1] > 0)	//for taking with pawn
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy - 1][ox + 1] > 0)
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int A::PawnB(int ox, int oy, int nx, int ny)
{
	if (oy == 1)
	{
		if ((ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0) || (ny == oy + 2 && nx == ox && board[oy + 1][ox] == 0 && board[oy + 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy + 1][ox - 1] < 0)
	{
		if (ny == oy + 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] < 0)
	{
		if (ny == oy + 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int A::RookW(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // to left
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // up
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // to right
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // down
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int A::RookB(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // to left
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // up
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // to right
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // down
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int A::BishopW(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::BishopB(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::QueenW(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // to left
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // up
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // to right
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // down
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // to diagonal up-right
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // to diagonal up-left
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // to diagonal down-right
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // to diagonal down-left
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::QueenB(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // to left
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // up
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // to right
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // down
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // to diagonal up-right
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // to diagonal up-left
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // to diagonal down-right
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // to diagonal down-left
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::KnightW(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; //
	}
	if (oy - 2 >= 0 && ox + 1 < LENGTH && ny == oy - 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < LENGTH && ny == oy - 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < LENGTH && ny == oy + 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox + 1 < LENGTH && ny == oy + 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGTH && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

int A::KnightB(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < LENGTH && ny == oy - 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < LENGTH && ny == oy - 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < LENGTH && ny == oy + 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox + 1 < LENGTH && ny == oy + 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGTH && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}

//returns 1 if it is check only for king

int A::PawnWCheck(int posx, int posy, int kingx, int kingy)
{
	//std::cout << "ox=" << posx << " oy=" << posy << " kingx=" << kingx << " kingy=" << kingy << "\n\n\n";
	if (board[posy - 1][posx - 1] >= 0)
	{
		if (posy - 1 == kingy && posx - 1 == kingx)
		{
			return 1;
		}
	}
	if (board[posy - 1][posx + 1] >= 0)
	{
		if (posy - 1 == kingy && posx + 1 == kingx)
		{
			return 1;
		}
	}
	return 0;
}

int A::RookWCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--) // to left
	{
		if (board[oy][i] >= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // up
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGTH; i++) // to right
	{
		if (board[oy][i] >= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGTH; i++) // down
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int A::BishopWCheck(int ox, int oy, int kingx, int kingy)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::QueenWCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (board[oy][i] >= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGTH; i++)
	{
		if (board[oy][i] >= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGTH; i++)
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LENGTH; i++)
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::KnightWCheck(int ox, int oy, int kingx, int kingy)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && kingy == oy - 2 && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < LENGTH && kingy == oy - 2 && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < LENGTH && kingy == oy - 1 && kingx == ox + 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < LENGTH && kingy == oy + 1 && kingx == ox + 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox + 1 < LENGTH && kingy == oy + 2 && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox - 1 >= 0 && kingy == oy + 2 && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGTH && ox - 2 >= 0 && kingy == oy + 1 && kingx == ox - 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && kingy == oy - 1 && kingx == ox - 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	return 0;
}

int A::KingWCheck(int ox, int oy, int kingx, int kingy)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && kingy == oy - 1 && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && kingx == ox && kingy == oy - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LENGTH && kingx == ox + 1 && kingy == oy - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGTH && kingy == oy && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGTH && oy + 1 < LENGTH && kingy == oy + 1 && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGTH && kingy == oy + 1 && kingx == ox && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LENGTH && kingx == ox - 1 && kingy == oy + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && kingy == oy && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	return 0;
}


int A::PawnBCheck(int ox, int oy, int kingx, int kingy)
{
	if (board[oy + 1][ox - 1] <= 0)
	{
		if (kingy == oy + 1 && kingx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] <= 0)
	{
		if (kingy == oy + 1 && kingx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int A::RookBCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (board[oy][i] <= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGTH; i++)
	{
		if (board[oy][i] <= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGTH; i++)
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int A::BishopBCheck(int ox, int oy, int kingx, int kingy)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::QueenBCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (board[oy][i] <= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGTH; i++)
	{
		if (board[oy][i] <= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGTH; i++)
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LENGTH; i++)
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int A::KnightBCheck(int ox, int oy, int kingx, int kingy)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && kingy == oy - 2 && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < LENGTH && kingy == oy - 2 && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < LENGTH && kingy == oy - 1 && kingx == ox + 2 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < LENGTH && kingy == oy + 1 && kingx == ox + 2 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox + 1 < LENGTH && kingy == oy + 2 && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < LENGTH && ox - 1 >= 0 && kingy == oy + 2 && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGTH && ox - 2 >= 0 && kingy == oy + 1 && kingx == ox - 2 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && kingy == oy - 1 && kingx == ox - 2 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	return 0;
}

int A::KingBCheck(int ox, int oy, int kingx, int kingy)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && kingy == oy - 1 && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && kingx == ox && kingy == oy - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LENGTH && kingx == ox + 1 && kingy == oy - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGTH && kingy == oy && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGTH && oy + 1 < LENGTH && kingy == oy + 1 && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGTH && kingy == oy + 1 && kingx == ox && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LENGTH && kingx == ox - 1 && kingy == oy + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && kingy == oy && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	return 0;
}


//checks if king is in check --- returns 1 if not in check
int A::BlackKingCheck(int poskingx, int poskingy)
{
	int ok = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] < 0)
			{
				if (board[i][j] == WHITE_PAWN)
				{
					ok = PawnWCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == WHITE_ROOK)
				{
					ok = RookWCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == WHITE_KNIGHT)
				{
					ok = KnightWCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == WHITE_BISHOP)
				{
					ok = BishopWCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == WHITE_QUEEN)
				{
					ok = QueenWCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == WHITE_KING)
				{
					ok = KingWCheck(j, i, poskingx, poskingy);
				}
				if (ok == 1)//ok is 1 if king cannot go to that square
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//black king movement return 1 if it can go
int A::BlackKING(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // it can go in up-left
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // can go in up
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LENGTH && nx == ox + 1 && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // can go in up-right
		}
	}
	if (ox + 1 < LENGTH && ny == oy && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // right
		}
	}
	if (ox + 1 < LENGTH && oy + 1 < LENGTH && ny == oy + 1 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // down-right
		}
	}
	if (oy + 1 < LENGTH && ny == oy + 1 && nx == ox && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // down
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LENGTH && nx == ox - 1 && ny == oy + 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // down-left
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = BlackKingCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // left
		}
	}

	// for castle 
	if (rightBlackRookM == 0 && blackKingFirstMove == 0 && board[0][5] == 0 && board[0][6] == 0 && ny == 0 && nx == 6)
	{
		int ok = BlackKingCheck(4, 0);
		if (ok == 1)
		{
			ok = BlackKingCheck(5, 0);
			if (ok == 1)
			{
				ok = BlackKingCheck(6, 0);
				if (ok == 1)
				{
					blackKingFirstMove = 1;
					rightBlackRookM = 1;
					board[0][7] = 0;
					board[0][5] = BLACK_ROOK;
					return 1;
				}
			}
		}
	}
	if (leftBlackRookM == 0 && blackKingFirstMove == 0 && board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = BlackKingCheck(4, 0);
		if (ok == 1)
		{
			ok = BlackKingCheck(3, 0);
			if (ok == 1)
			{
				ok = BlackKingCheck(2, 0);
				if (ok == 1)
				{
					ok = BlackKingCheck(1, 0);
					if (ok == 1)
					{
						blackKingFirstMove = 1;
						leftBlackRookM = 1;
						board[0][0] = 0;
						board[0][3] = BLACK_ROOK;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int A::WhiteKingCheck(int poskingx, int poskingy)	//checks if king is in check 
{
	int ok = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] > 0)
			{
				if (board[i][j] == BLACK_PAWN)
				{
					ok = PawnBCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == BLACK_ROOK)
				{
					ok = RookBCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == BLACK_KNIGHT)
				{
					ok = KnightBCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == BLACK_BISHOP)
				{
					ok = BishopBCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == BLACK_QUEEN)
				{
					ok = QueenBCheck(j, i, poskingx, poskingy);
				}
				if (board[i][j] == BLACK_KING)
				{
					ok = KingBCheck(j, i, poskingx, poskingy);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int A::WhiteKING(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LENGTH && nx == ox + 1 && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (ox + 1 < LENGTH && ny == oy && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (ox + 1 < LENGTH && oy + 1 < LENGTH && ny == oy + 1 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (oy + 1 < LENGTH && ny == oy + 1 && nx == ox && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LENGTH && nx == ox - 1 && ny == oy + 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = WhiteKingCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1;
		}
	}
	// for castling in left side
	if (whiteKingFirstMove == 0 && rightWhiteRookM == 0 && board[7][5] == 0 && board[7][6] == 0 && ny == 7 && nx == 6)
	{
		int ok = 1;
		ok = WhiteKingCheck(4, 7);
		if (ok == 1)
		{
			ok = WhiteKingCheck(5, 7);
			if (ok == 1)
			{
				ok = WhiteKingCheck(6, 7);
				if (ok == 1)
				{
					board[7][7] = 0;
					board[7][5] = WHITE_ROOK;
					whiteKingFirstMove = 1;
					rightWhiteRookM = 1;
					return 1;
				}
			}
		}
	}
	//castling in right side
	if (whiteKingFirstMove == 0 && rightWhiteRookM == 0 && board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = WhiteKingCheck(4, 7);
		if (ok == 1)
		{
			ok = WhiteKingCheck(3, 7);
			if (ok == 1)
			{
				ok = WhiteKingCheck(2, 7);
				if (ok == 1)
				{
					ok = WhiteKingCheck(1, 7);
					if (ok == 1)
					{
						board[7][0] = 0;
						board[7][3] = WHITE_ROOK;
						whiteKingFirstMove = 1;
						leftWhiteRookM = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void A::posWhiteKing()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] == WHITE_KING)
			{
				A::whiteKing_x = j;
				A::whiteKing_y = i;
				break;
			}
		}
	}
}

void A::posBlackKing()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (board[i][j] == BLACK_KING)
			{
				A::blackKing_y = i;
				A::blackKing_x = j;
				break;
			}
		}
	}
}


bool A::checkmate(bool isWhite) {
	int kingX = isWhite ? whiteKing_x : blackKing_x;
	int kingY = isWhite ? whiteKing_y : blackKing_y;

	//cout << "check\n";

	// Check if the king is in check
	if (!isKingInCheck(kingX, kingY, isWhite)) {
		//cout << "1\n";
		return false;
	}

	// Check if the king can escape
	if (!canKingEscapeCheck(kingX, kingY, isWhite)) {
		//cout << "2\n";
		return false;
	}

	// Check if any piece can block the check or capture the checking piece
	if (!canAnyPieceBlockOrCapture(kingX, kingY, isWhite)) {
		//cout << "3\n";
		return false;
	}

	// If none of the above conditions hold, it's checkmate
	return true;
}

bool A::isKingInCheck(int kingX, int kingY, bool isWhite) {
	if (isWhite) {
		return !WhiteKingCheck(kingX, kingY);
	}
	else {
		return !BlackKingCheck(kingX, kingY);
	}
}

bool A::isValidMove(int ox, int oy, int nx, int ny) {
	int piece = board[oy][ox];

	switch (piece) {
	case WHITE_PAWN:
		return PawnW(ox, oy, nx, ny);
	case WHITE_ROOK:
		return RookW(ox, oy, nx, ny);
	case WHITE_KNIGHT:
		return KnightW(ox, oy, nx, ny);
	case WHITE_BISHOP:
		return BishopW(ox, oy, nx, ny);
	case WHITE_QUEEN:
		return QueenW(ox, oy, nx, ny);
	case WHITE_KING:
		//return 0;
		return WhiteKING(ox, oy, nx, ny);	//here
	case BLACK_PAWN:
		return PawnB(ox, oy, nx, ny);
	case BLACK_ROOK:
		return RookB(ox, oy, nx, ny);
	case BLACK_KNIGHT:
		return KnightB(ox, oy, nx, ny);
	case BLACK_BISHOP:
		return BishopB(ox, oy, nx, ny);
	case BLACK_QUEEN:
		return QueenB(ox, oy, nx, ny);
	case BLACK_KING:
		//cout << "1";
		return BlackKING(ox, oy, nx, ny);

		
	default:
		return false;
	}
}

bool A::canKingEscapeCheck(int kingX, int kingY, bool isWhite) {
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx != 0 || dy != 0) {
				int nx = kingX + dx;
				int ny = kingY + dy;
				if (nx >= 0 && nx < LENGTH && ny >= 0 && ny < LENGTH) {
					if (board[ny][nx] == 0 || (isWhite && board[ny][nx] < 0) || (!isWhite && board[ny][nx] > 0)) {
						int originalPiece = board[ny][nx];
						board[ny][nx] = board[kingY][kingX];
						board[kingY][kingX] = 0;
						bool stillInCheck = isKingInCheck(nx, ny, isWhite);
						board[kingY][kingX] = board[ny][nx];
						board[ny][nx] = originalPiece;
						if (!stillInCheck) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool A::canAnyPieceBlockOrCapture(int kingX, int kingY, bool isWhite) {
	bool stillInCheck;
	// lokk through all squares on the board
	for (int y = 0; y < LENGTH; ++y) {
		for (int x = 0; x < LENGTH; ++x) {
			// Check if the piece belongs to the current player
			if ((isWhite && board[y][x] < 0) || (!isWhite && board[y][x] > 0)) {
				// Check if this piece can move to the position of the checking piece
				for (int ty = 0; ty < LENGTH; ++ty) {
					for (int tx = 0; tx < LENGTH; ++tx) {
						if (isValidMove(x, y, tx, ty)) {
							// Temporarily make the move
							int tempPiece = board[ty][tx];
							board[ty][tx] = board[y][x];
							board[y][x] = 0;
							if (!isWhite) {
								posBlackKing();
								// Check if the king is still in check
								stillInCheck = isKingInCheck(blackKing_x, blackKing_y, isWhite);
							}
							else {
								posWhiteKing();
								// Check if the king is still in check
								stillInCheck = isKingInCheck(whiteKing_x, whiteKing_y, isWhite);
							}
							// Undo the move
							board[y][x] = board[ty][tx];
							board[ty][tx] = tempPiece;

							// If the move prevents the check, return false (no checkmate)
							if (!stillInCheck) {
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}



int A::isMoving = 0;
int A::x = 0;
int A::y = 0;
int A::rightWhiteRookM = 0;
int A::leftWhiteRookM = 0;
int A::rightBlackRookM = 0;
int A::leftBlackRookM = 0;
int A::whiteKingFirstMove = 0;
int A::blackKingFirstMove = 0;
int A::move = 0;
int A::checkWhite = 0;
int A::checkBlack = 0;
int A::transformationBlack = 0;
int A::transformationWhite = 0;
float A::dx = 0;
float A::dy = 0;
int A::noMovedPiece = 0;
int A::black_win = 0;
int	A::white_win = 0;
int A::draw_position = 0;

int A::board[][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, };

int A::oldPoz_x = 0;
int A::oldPoz_y = 0;
int A::whiteKing_x = 0;
int A::whiteKing_y = 0;
int A::blackKing_x = 0;
int A::blackKing_y = 0;
int A::transformWHITE_x = 0;
int A::transformWHITE_y = 0;
int A::transformBLACK_x = 0;
int A::transformBLACK_y = 0;


//for draw

bool A::isInsufficientMaterial() {
	int whitePieces = 0, blackPieces = 0;
	int whiteBishops = 0, blackBishops = 0;
	bool whiteKnight = false, blackKnight = false;

	for (int y = 0; y < LENGTH; ++y) {
		for (int x = 0; x < LENGTH; ++x) {
			int piece = board[y][x];
			if (piece > 0) {  // White piece
				whitePieces++;
				if (piece == 3) whiteKnight = true;
				if (piece == 4) whiteBishops++;
			}
			else if (piece < 0) {  // Black piece
				blackPieces++;
				if (piece == -3) blackKnight = true;
				if (piece == -4) blackBishops++;
			}
		}
	}

	// King vs King
	if (whitePieces == 1 && blackPieces == 1) return true;

	// King + Bishop vs King
	if (whitePieces == 2 && whiteBishops == 1 && blackPieces == 1) return true;
	if (blackPieces == 2 && blackBishops == 1 && whitePieces == 1) return true;

	// King + Knight vs King
	if (whitePieces == 2 && whiteKnight && blackPieces == 1) return true;
	if (blackPieces == 2 && blackKnight && whitePieces == 1) return true;

	// King + Bishop vs King + Bishop (same color bishops)
	if (whitePieces == 2 && blackPieces == 2 && whiteBishops == 1 && blackBishops == 1) {
		return true;
	}

	return false;  // Material is sufficient for checkmate
}
bool A::isStalemate(bool isWhite) {
	int kingX = isWhite ? whiteKing_x : blackKing_x;
	int kingY = isWhite ? whiteKing_y : blackKing_y;

	if (isKingInCheck(kingX, kingY, isWhite)) {
		return false;  // Not a stalemate if the king is in check
	}

	// Check if any move is possible
	for (int y = 0; y < LENGTH; ++y) {
		for (int x = 0; x < LENGTH; ++x) {
			if ((isWhite && board[y][x] > 0) || (!isWhite && board[y][x] < 0)) {
				for (int ny = 0; ny < LENGTH; ++ny) {
					for (int nx = 0; nx < LENGTH; ++nx) {
						if (isValidMove(x, y, nx, ny)) {
							// If there's a valid move, it's not stalemate
							return false;
						}
					}
				}
			}
		}
	}
	return true;  // Stalemate if no valid moves
}

