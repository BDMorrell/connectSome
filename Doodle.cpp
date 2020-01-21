#include <string>
#include <iostream>
using namespace std;

typedef int player_t; // 0 = nobody

struct BoardAttributes {
  int width;
  int height;
  player_t numPlayers;
  int connectLength;
};

class BoardState {
private:
  player_t **board; // the board
  player_t whosTurn;
  BoardAttributes *attributes;
public:
  BoardState(BoardAttributes *setup);
  BoardState(BoardState *other);
  ~BoardState();
  bool canPlace(int column);
  void place(int column);
  string toString();
};

BoardState::BoardState(BoardAttributes *setup) {
  attributes = setup;
  whosTurn = 1;
  board = new player_t*[setup->width];
  int i;
  for (i = 0; i < setup->width; i++) {
    board[i] = new player_t[setup->height];
    int j;
    for (j = 0; j < setup->height; j++) {
      board[i][j] = 0; // initalize to 0
    }
  }
}

BoardState::~BoardState() {
  int i;
  for (int i; i < attributes->width; i++) {
    delete[] board[i];
  }
  delete[] board;
}

bool BoardState::canPlace(int column) {
  if(board[column][attributes->height - 1] == 0){
    return true;
  }
  else{
    return false;
  }
}

int BoardState::getColumnHeight(int column) { // exclusive height
  int i;
  for (i = 0; i < attributes->height && board[column][i] != 0; i++);
  return i;
}

void BoardState::place(int column) { // we're placing based on whosTurn

}
