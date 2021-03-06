#pragma once
#include "checkers_pieces.h"

template <typename T>
inline void copyArray(T* dest, const T* source,int size)
{
	for (int i = 0; i < size; i++)
		dest[i] = source[i];
}

typedef list<move_with_piece> list_moves_with_piece;
class Ai
{
private:
	//list<move> all_moves_;
	Board board_;
	

	int ai_player_;
	CheckersPieceWithState white_player_[12];
	CheckersPieceWithState black_player_[12];
	int white_player_size_, black_player_size_;

	move best_move_for_ai_;

	int number_nodes_ = 0;
	
	// iter to piece that can beat multiple times
	// if ther is no piece - iter_piece_beat_multiple_ == -1
	int iter_piece_beat_multiple_ = -1;
	
	list<move> generateAllMoves(int player);

	void makeMove(int player, move& move_to_make);
	void unmakeMove(int player, move& move_to_unmake);

	int evaluatePlayerPosition(int player) const;
	int evaluatePosition() const;

	int alphaBeta(int color, int depth, int max_white = INT_MIN, int min_black = INT_MAX);
	

	vector<BoardIndex> getPossibleMoves(const CheckersPiece& piece_to_check) const;

	vector<move_with_piece> getPossibleBeatMoves(const CheckersPiece& piece_to_check) const;

	int checkForPieces(BoardIndex position_to_check, const CheckersPieceWithState *pieces, int pieces_size) const;

	CheckersPieceWithState* getCurrentPlayer(int player);
	CheckersPieceWithState* getAnotherPlayer(int player);
	const CheckersPieceWithState* getCurrentPlayer(int player) const;
	const CheckersPieceWithState* getAnotherPlayer(int player) const;
	int getCurrentPlayerSize(int player) const;
	int getAnotherPlayerSize(int player) const;
public: 
	void updatePositions(const CheckersPieceWithState* white, const CheckersPieceWithState* black, const Board& b)
	{
		copyArray(white_player_, white, 12);
		copyArray(black_player_, black, 12);
		white_player_size_ = 12;
		black_player_size_ = 12;
		board_ = b;
	}
	list<move> findBestMove(int depth,int color);
};