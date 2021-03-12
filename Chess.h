#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

/** Including all the Header Files **/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;

/** Defining Macros **/
#define time_gap 2

/** Defining required structures and enumerations **/
enum Type {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN,EMPTY};
enum Color {WHITE,BLACK,NONE};
struct Location
{
    int x;
    int y;
};
typedef struct Location Loc;

/** Declaring and defining the required classes **/
class Piece;
class Square
{
    public:
        Piece *piece;
        Loc pos;
        void setLoc(int x,int y);
};
class Piece
{
    public:
        Type type;
        Color color;
        int Steps_taken;
        Piece(Type t,Color c)
        {
            type=t;
            color=c;
            Steps_taken=0;
        }
        virtual bool validMove(Square* src,Square* dest)=0;
        ~Piece() { }
};
class King:public Piece
{
    public:
        King(Color c):Piece(KING,c)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~King() { }
};
class Queen:public Piece
{
    public:
        Queen(Color c):Piece(QUEEN,c)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~Queen() { }
};
class Knight:public Piece
{
    public:
        Knight(Color c):Piece(KNIGHT,c)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~Knight() { }
};
class Bishop:public Piece
{
    public:
        Bishop(Color c):Piece(BISHOP,c)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~Bishop() { }
};
class Rook:public Piece
{
    public:
        Rook(Color c):Piece(ROOK,c)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~Rook() { }
};
class Pawn:public Piece
{
    public:
        Pawn(Color c):Piece(PAWN,c)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~Pawn() { }
};
class Empty:public Piece
{
    public:
        Empty():Piece(EMPTY,NONE)
        {

        }
        bool validMove(Square* src,Square* dest);
        ~Empty() { }
};
class Board
{
    public:
        Square board[8][8];
        void newGame();
        Color oldGame();
        void playGame(Color turn);
        void printBoard();
}B;

/** Declaring the Global Variables **/
Loc h1,h2;
ifstream fin;
ofstream fout;
vector<char> whiteCaptured;
vector<char> blackCaptured;

/** Declaring the User Defined Functions **/
void Game();
void aboutChess();
void aboutGame();
void delay(int n);
bool saveGame(Color turn);
bool kingSafe(Color color);
Square* getKing(Color color);
bool noMoves(Color c);
bool Castle(Color turn);
void checkPawn(Square* dest);

#endif // CHESS_H_INCLUDED
