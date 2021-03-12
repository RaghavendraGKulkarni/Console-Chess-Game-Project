#include "Chess.h"

/**
Function Name :- delay
Input Arguments :- an integer
Return Value :- null
Description :- It is the function to create a time delay of few seconds. The number of seconds,
               the delay to be created, is passed as the argument to the function.
**/
void delay(int n)
{
    int milli=1000*n;
    clock_t start=clock();
    while(clock() < (start+milli))
        ;
}

/**
Function Name :- setLoc
Input Arguments :- two integers
Return Value :- null
Description :- It is the function which sets the position co-ordinates of the Square object,
               to which the function call belongs to.
**/
void Square::setLoc(int x,int y)
{
    pos.x=x;
    pos.y=y;
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which checks whether the move given by the user to move the King
               is a Valid Move or not, according to the Standard rules of the Game and returns
               True, if it is a valid move and false, if not.
**/
bool King::validMove(Square* src,Square* dest)
{
    if(abs(src->pos.x - dest->pos.x)==1 && abs(src->pos.y - dest->pos.y)==1)
        if((dest->piece)->color!=(src->piece)->color)
            return true;
    return false;
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which checks whether the move given by the user to move the Queen
               is a Valid Move or not, according to the Standard rules of the Game and returns
               True, if it is a valid move and false, if not.
**/
bool Queen::validMove(Square* src,Square* dest)
{
    if((dest->piece)->color==(src->piece)->color)
        return false;
    if(src->pos.x==dest->pos.x && src->pos.y!=dest->pos.y)
    {
        int x,i,y1,y2;
        x=src->pos.x;
        y1=src->pos.y;
        y2=dest->pos.y;
        if(y1<y2)
        {
            for(i=y1+1;i<y2;i++)
            {
                if((B.board[x][i].piece)->type!=EMPTY)
                    return false;
            }
        }
        else
        {
            for(i=y1-1;i>y2;i--)
            {
                if((B.board[x][i].piece)->type!=EMPTY)
                    return false;
            }
        }
        return true;
    }
    else if(src->pos.x!=dest->pos.x && src->pos.y==dest->pos.y)
    {
        int y,i,x1,x2;
        y=src->pos.y;
        x1=src->pos.x;
        x2=dest->pos.x;
        if(x1<x2)
        {
            for(i=x1+1;i<x2;i++)
            {
                if((B.board[i][y].piece)->type!=EMPTY)
                    return false;
            }
        }
        else
        {
            for(i=x1-1;i>x2;i--)
            {
                if((B.board[i][y].piece)->type!=EMPTY)
                    return false;
            }
        }
        return true;
    }
    else if(abs(src->pos.x - dest->pos.x) == abs(src->pos.y - dest->pos.y))
    {
        int y1,y2,i,j,x1,x2;
        x1=src->pos.x;
        x2=dest->pos.x;
        y1=src->pos.y;
        y2=dest->pos.y;
        if(x1<x2 && y1<y2)
        {
            for(i=x1+1,j=y1+1;i<x2 && j<y2;i++,j++)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        else if(x1<x2 && y1>y2)
        {
            for(i=x1+1,j=y1-1;i<x2 && j>y2;i++,j--)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        else if(x1>x2 && y1<y2)
        {
            for(i=x1-1,j=y1+1;i>x2 && j<y2;i--,j++)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        else
        {
            for(i=x1-1,j=y1-1;i>x2 && j>y2;i--,j--)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        return true;
    }
    else
        return false;
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which checks whether the move given by the user to move the Knight
               is a Valid Move or not, according to the Standard rules of the Game and returns
               True, if it is a valid move and false, if not.
**/
bool Knight::validMove(Square* src,Square* dest)
{
    if((dest->piece)->color==(src->piece)->color)
        return false;
    if(abs(src->pos.x - dest->pos.x)==2 && abs(src->pos.y - dest->pos.y)==1)
        if((dest->piece)->color!=(src->piece)->color)
            return true;
    else if(abs(src->pos.x - dest->pos.x)==1 && abs(src->pos.y - dest->pos.y)==2)
        if((dest->piece)->color!=(src->piece)->color)
            return true;
    return false;
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which checks whether the move given by the user to move the Bishop
               is a Valid Move or not, according to the Standard rules of the Game and returns
               True, if it is a valid move and false, if not.
**/
bool Bishop::validMove(Square* src,Square* dest)
{
    if((dest->piece)->color==(src->piece)->color)
        return false;
    if(abs(src->pos.x - dest->pos.x) == abs(src->pos.y - dest->pos.y))
    {
        int y1,y2,i,j,x1,x2;
        x1=src->pos.x;
        x2=dest->pos.x;
        y1=src->pos.y;
        y2=dest->pos.y;
        if(x1<x2 && y1<y2)
        {
            for(i=x1+1,j=y1+1;i<x2 && j<y2;i++,j++)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        else if(x1<x2 && y1>y2)
        {
            for(i=x1+1,j=y1-1;i<x2 && j>y2;i++,j--)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        else if(x1>x2 && y1<y2)
        {
            for(i=x1-1,j=y1+1;i>x2 && j<y2;i--,j++)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        else
        {
            for(i=x1-1,j=y1-1;i>x2 && j>y2;i--,j--)
                if((B.board[i][j].piece)->type!=EMPTY)
                    return false;
        }
        return true;
    }
    else
        return false;
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which checks whether the move given by the user to move the Rook
               is a Valid Move or not, according to the Standard rules of the Game and returns
               True, if it is a valid move and false, if not.
**/
bool Rook::validMove(Square* src,Square* dest)
{
    if((dest->piece)->color==(src->piece)->color)
        return false;
    if(src->pos.x==dest->pos.x && src->pos.y!=dest->pos.y)
    {
        int x,i,y1,y2;
        x=src->pos.x;
        y1=src->pos.y;
        y2=dest->pos.y;
        if(y1<y2)
        {
            for(i=y1+1;i<y2;i++)
            {
                if((B.board[x][i].piece)->type!=EMPTY)
                    return false;
            }
        }
        else
        {
            for(i=y1-1;i>y2;i--)
            {
                if((B.board[x][i].piece)->type!=EMPTY)
                    return false;
            }
        }
        return true;
    }
    else if(src->pos.x!=dest->pos.x && src->pos.y==dest->pos.y)
    {
        int y,i,x1,x2;
        y=src->pos.y;
        x1=src->pos.x;
        x2=dest->pos.x;
        if(x1<x2)
        {
            for(i=x1+1;i<x2;i++)
            {
                if((B.board[i][y].piece)->type!=EMPTY)
                    return false;
            }
        }
        else
        {
            for(i=x1-1;i>x2;i--)
            {
                if((B.board[i][y].piece)->type!=EMPTY)
                    return false;
            }
        }
        return true;
    }
    else
        return false;
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which checks whether the move given by the user to move the Pawn
               is a Valid Move or not, according to the Standard rules of the Game and returns
               True, if it is a valid move and false, if not.
**/
bool Pawn::validMove(Square* src,Square* dest)
{
    int x1,y1,x2,y2;
    x1=src->pos.x;
    x2=dest->pos.x;
    y1=src->pos.y;
    y2=dest->pos.y;
    if((src->piece)->color==BLACK)
    {
        if(y1==y2 && x2-x1==2 && (src->piece)->Steps_taken==0 && (dest->piece)->color==NONE)
            return true;
        if(y1==y2 && x2-x1==1 && (dest->piece)->color==NONE)
            return true;
        else if(abs(y1-y2)==1 && x2-x1==1 && (dest->piece)->color==WHITE)
            return true;
        return false;
    }
    else
    {
        if(y1==y2 && x1-x2==2 && (src->piece)->Steps_taken==0 && (dest->piece)->color==NONE)
            return true;
        if(y1==y2 && x1-x2==1 && (dest->piece)->color==NONE)
            return true;
        else if(abs(y1-y2)==1 && x1-x2==1 && (dest->piece)->color==BLACK)
            return true;
        return false;
    }
}

/**
Function Name :- validMove
Input Arguments :- two pointers of class Square
Return Value :- boolean value
Description :- It is the function which returns the boolean value false, whenever it is invoked,
               indicating that the gamer trying to move an empty piece is Invalid.
**/
bool Empty::validMove(Square *src,Square* dest)
{
    return false;
}

/**
Function Name :- newGame
Input Arguments :- null
Return Value :- null
Description :- It is the function which sets a new Game. It creates all the required pieces on both
               black and white side and places them at their respective positions. It also sets the
               location co-ordinates each square, by calling the appropriate function.
**/
void Board::newGame()
{
    int i,j;
    cout<<"\nLoading New Game\n";
    delay(time_gap);

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            B.board[i][j].setLoc(i,j);

    B.board[7][0].piece=new Rook(WHITE);
    B.board[7][1].piece=new Knight(WHITE);
    B.board[7][2].piece=new Bishop(WHITE);
    B.board[7][3].piece=new Queen(WHITE);
    B.board[7][4].piece=new King(WHITE);
    B.board[7][5].piece=new Bishop(WHITE);
    B.board[7][6].piece=new Knight(WHITE);
    B.board[7][7].piece=new Rook(WHITE);

    B.board[0][0].piece=new Rook(BLACK);
    B.board[0][1].piece=new Knight(BLACK);
    B.board[0][2].piece=new Bishop(BLACK);
    B.board[0][3].piece=new Queen(BLACK);
    B.board[0][4].piece=new King(BLACK);
    B.board[0][5].piece=new Bishop(BLACK);
    B.board[0][6].piece=new Knight(BLACK);
    B.board[0][7].piece=new Rook(BLACK);

    for(i=0;i<8;i++)
    {
        B.board[6][i].piece=new Pawn(WHITE);
        B.board[1][i].piece=new Pawn(BLACK);
    }

    for(i=2;i<6;i++)
        for(j=0;j<8;j++)
            B.board[i][j].piece=new Empty();
}

/**
Function Name :- oldGame
Input Arguments :- null
Return Value :- A value of color enumarated data type
Description :- It is the function which extracts the old Game saved in the Backup file, saved by 
                the Gamer while quiting the game. It extracts all the information and sets the board
               in the exact state where the gamer had left it, saving the game. It returns the color 
               of the pieces of the player who has to start/continue the game.
**/
Color Board::oldGame()
{
    fin.open("SavedGame.txt");
    int i,j,x,y,z;
    char ch;
    string type;
    cout<<"\nExtracting the Saved Game\n";
    delay(time_gap);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            fin>>x>>y;
            B.board[i][j].setLoc(x,y);
            fin>>type;
            if(type=="king")
                B.board[i][j].piece=new King(BLACK);
            else if(type=="KING")
                B.board[i][j].piece=new King(WHITE);
            else if(type=="queen")
                B.board[i][j].piece=new Queen(BLACK);
            else if(type=="QUEEN")
                B.board[i][j].piece=new Queen(WHITE);
            else if(type=="bishop")
                B.board[i][j].piece=new Bishop(BLACK);
            else if(type=="BISHOP")
                B.board[i][j].piece=new Bishop(WHITE);
            else if(type=="knight")
                B.board[i][j].piece=new Knight(BLACK);
            else if(type=="KNIGHT")
                B.board[i][j].piece=new Knight(WHITE);
            else if(type=="rook")
                B.board[i][j].piece=new Rook(BLACK);
            else if(type=="ROOK")
                B.board[i][j].piece=new Rook(WHITE);
            else if(type=="pawn")
                B.board[i][j].piece=new Pawn(BLACK);
            else if(type=="PAWN")
                B.board[i][j].piece=new Pawn(WHITE);
            else
                B.board[i][j].piece=new Empty();
            fin>>z;
            (B.board[i][j].piece)->Steps_taken=z;
        }
    }
    fin>>type;
    fin.close();
    fout.open("SavedGame.txt",ios::out|ios::trunc);
    fout.close();
    if(type=="WHITE")
        return WHITE;
    else
        return BLACK;
}

/**
Function Name :- printBoard
Input Arguments :- null
Return Value :- null
Description :- It is the function which prints the Board in the required format, on the Console.
               It uses various symbols for various types of pieces to differentiate between them,
               like upper case letters for White pieces and lower case letters for Black pieces.
**/
void Board::printBoard()
{
    int i,j;
    Type p;
    Color c;
    system("cls");
    cout<<"\t\t\t\tCHESS GAME\n\n\t";
    for(i=0;i<8;i++)
        cout<<" "<<i+1<<" "<<"\t";
    cout<<"\n\n\n";
    for(i=0;i<8;i++)
    {
        cout<<i+1;
        for(j=0;j<8;j++)
        {
            p=(this->board[i][j].piece)->type;
            c=(this->board[i][j].piece)->color;
            cout<<"\t";
            switch(p)
            {
                case KING:(c==WHITE) ? cout<<" K " : cout<<" k ";
                            break;
                case QUEEN:(c==WHITE) ? cout<<" Q " : cout<<" q ";
                            break;
                case KNIGHT:(c==WHITE) ? cout<<" N " : cout<<" n ";
                            break;
                case BISHOP:(c==WHITE) ? cout<<" B " : cout<<" b ";
                            break;
                case ROOK:(c==WHITE) ? cout<<" R " : cout<<" r ";
                            break;
                case PAWN:(c==WHITE) ? cout<<" P " : cout<<" p ";
                            break;
                default:cout<<" - ";
                        break;
            }
        }
        cout<<"\n\n\n";
    }
}

/**
Function Name :- playGame
Input Arguments :- null
Return Value :- null
Description :- This is the function which runs throughout the Game. This runs a loop which
               starts as the game starts and ends when the one of the player wins or quits
               the game explicitly. It receives input from the user and parses it for errors.
               It uses exception handling for various errors to display appropriate error messages.
               In case of correct input, it calls functions to check the validity of the Move
               and keeps a track of next player turn.
**/
void Board::playGame(Color turn)
{
    bool stop=false,king,move;
    string input,ch;
    int x1,y1,x2,y2;
    vector<char>::iterator ptr;
    Square *src,*dest;
    Piece *t1,*t2;
    t1=new Empty();
    getline(cin,ch);
    while(!stop)
    {
        this->printBoard();

        cout<<"\nWhite Captured : ";
        for(ptr=whiteCaptured.begin();ptr!=whiteCaptured.end();++ptr)
            cout<<*ptr<<' ';

        cout<<"\n\nBlack Captured : ";
        for(ptr=blackCaptured.begin();ptr!=blackCaptured.end();++ptr)
            cout<<*ptr<<' ';

        cout<<"\n\n";

        king=kingSafe(turn);

        move=noMoves(turn);

        if(!king && !move)
            cout<<"Your King is in check.Your next move should remove King from Check\n\n";

        else if(!king && move)
        {
            cout<<"Checkmate.";
            (turn==WHITE) ? cout<<"Black Wins\n" : cout<<"White Wins\n";
            stop=true;
            continue;
        }

        else if(king && move)
        {
            cout<<"Draw by Stalemate.No legal move left for ";
            (turn==WHITE) ? cout<<"White\n" : cout<<"Black\n";
            stop=true;
            continue;
        }

        (turn==WHITE) ? cout<<"White's Turn:" : cout<<"Black's Turn:";

        getline(cin,input);

        if(input=="Quit Game")
        {
            if(saveGame(turn))
            {
                stop=true;
                break;
            }
            continue;
        }

        else if(input=="Castle")
        {
            if(Castle(turn))
            {
                (turn==WHITE) ? turn=BLACK : turn=WHITE;
                delay(time_gap);
                continue;
            }
            else
            {
                cout<<"\nCastling not allowed\n";
                delay(time_gap);
                continue;
            }
        }

        else if(input=="Save Me" && king)
        {
            cout<<"\nYou are not in a Check.Make a Move";
            delay(time_gap+1);
            continue;
        }

        else if(input=="Save Me" && !king)
        {
            cout<<"\nYou can make a move from "<<h1.x<<h1.y<<" to "<<h2.x<<h2.y;
            delay(time_gap+1);
            continue;
        }

        else
        {
            x1=input[0]-49;
            y1=input[1]-49;
            x2=input[3]-49;
            y2=input[4]-49;
            try
            {
                if((x1<0 || x1>7 || y1<0 || y1>7) && (x2<0 || x2>7 || y2<0 || y2>7))
                    throw 'A';
                if(x1<0 || x1>7 || y1<0 || y1>7)
                    throw 1;
                if(x2<0 || x2>7 || y2<0 || y2>7)
                    throw 1.0;
            }
            catch(int x)
            {
                cout<<"\nInvalid Co-ordinates entered for the source\n";
                delay(time_gap);
                continue;
            }
            catch(float x)
            {
                cout<<"\nInvalid Co-ordinates entered for the destination\n";
                delay(time_gap);
                continue;
            }
            catch(char ch)
            {
                cout<<"\nInvalid Co-ordinates entered for both source and destination\n";
                delay(time_gap);
                continue;
            }

            src=&this->board[x1][y1];
            dest=&this->board[x2][y2];

            if((src->piece)->color!=turn)
            {
                cout<<"\nThat's not your piece\n";
                delay(time_gap);
                continue;
            }

            if((src->piece)->validMove(src,dest))
            {
                t2=dest->piece;
                dest->piece=src->piece;
                src->piece=t1;

                if(kingSafe(turn))
                {
                    cout<<"\nValid Move"<<endl;
                    (dest->piece)->Steps_taken++;
                    switch(t2->type)
                    {
                        case QUEEN:(t2->color==WHITE) ? cout<<"\nWhite Queen is captured"<<endl : cout<<"\nBlack Queen is captured"<<endl;
                                    (t2->color==WHITE) ? blackCaptured.push_back('Q') : whiteCaptured.push_back('q');
                            break;
                        case KNIGHT:(t2->color==WHITE) ? cout<<"\nWhite Knight is captured"<<endl : cout<<"\nBlack Knight is captured"<<endl;
                                    (t2->color==WHITE) ? blackCaptured.push_back('N') : whiteCaptured.push_back('n');
                            break;
                        case BISHOP:(t2->color==WHITE) ? cout<<"\nWhite Bishop is captured"<<endl : cout<<"\nBlack Nishop is captured"<<endl;
                                    (t2->color==WHITE) ? blackCaptured.push_back('B') : whiteCaptured.push_back('b');
                            break;
                        case ROOK:(t2->color==WHITE) ? cout<<"\nWhite Rook is captured"<<endl : cout<<"\nBlack Rook is captured"<<endl;
                                    (t2->color==WHITE) ? blackCaptured.push_back('R') : whiteCaptured.push_back('r');
                            break;
                        case PAWN:(t2->color==WHITE) ? cout<<"\nWhite Pawn is captured"<<endl : cout<<"\nBlack Pawn is captured"<<endl;
                                    (t2->color==WHITE) ? blackCaptured.push_back('P') : whiteCaptured.push_back('p');
                            break;
                        default:
                            break;
                    }
                    if((dest->piece)->type==PAWN)
                        checkPawn(dest);
                    delay(time_gap);
                }

                else
                {
                    cout<<"\nThe Move will put your King in check.Invalid Move\n";
                    src->piece=dest->piece;
                    dest->piece=t2;
                    delay(time_gap);
                    continue;
                }
            }

            else
            {
                cout<<"\nInvalid Move"<<endl;
                delay(time_gap);
                continue;
            }
        }

        (turn==WHITE) ? turn=BLACK : turn=WHITE;
    }
    cout<<"\nGame Ends\n\n";
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            delete B.board[i][j].piece;
    system("pause");
}

/**
Function Name :- getKing
Input Arguments :- an argument of type Color
Return Value :- pointer to an object of class Square
Description :- This function searches for the King of the given color. The color is passed
               as an argument to the function. It returns the pointer to the square
               where the King of that color is present, at that stage of the Game.
**/
Square* getKing(Color color)
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if((B.board[i][j].piece)->type==KING && (B.board[i][j].piece)->color==color)
                return &B.board[i][j];
}

/**
Function Name :- kingSafe
Input Arguments :- an argument of type Color
Return Value :- a boolean value
Description :- This function searches for the King of the
**/
bool kingSafe(Color color)
{
    Square *dest;
    dest=getKing(color);
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if((B.board[i][j].piece)->validMove(&B.board[i][j],dest)==true)
                return false;
    return true;
}

/**
Function Name :- aboutGame
Input Arguments :- null
Return Value :- null
Description :- This function displays the instructions of playing the game.
**/
void aboutGame()
{
    string line;
    fin.open("aboutGame.txt");
    system("cls");
    while(fin)
    {
        getline(fin,line);
        cout<<line<<endl;
    }
    fin.close();
    return;
}

/**
Function Name :- aboutChess
Input Arguments :- null
Return Value :- null
Description :- This function displays the Information and Rules of playing Chess.
**/
void aboutChess()
{
    string line;
    fin.open("aboutChess.txt");
    system("cls");
    while(fin)
    {
        getline(fin,line);
        cout<<line<<endl;
    }
    fin.close();
    return;
}

/**
Function Name :- Game
Input Arguments :- null
Return Value :- null
Description :- This function initiates the game by checking for any saved game and invokes the appropriate function call.
**/
void Game()
{
    bool game;
    Color turn;
    fin.open("SavedGame.txt");
    game=(fin.get(),fin.eof());
    fin.close();
    if(game)
    {
        B.newGame();
        turn=WHITE;
    }
    else
    {
        char ch;
        cout<<"\nThere is a Saved Game.Would you like to continue it ? (Y/N):";
        cin>>ch;
        if(ch=='N')
        {
            B.newGame();
            turn=WHITE;
            fout.open("SavedGame.txt",ios::out|ios::trunc);
            fout.close();
        }
        else if(ch=='Y')
            turn=B.oldGame();
        else
        {
            cout<<"\nInvalid Input";
            return;
        }
    }
    cout<<"\nGame to start with";
    (turn==WHITE) ? cout<<" White\n\n" : cout<<" Black\n\n";
    system("pause");
    B.playGame(turn);
    return;
}

/**
Function Name :- noMoves
Input Arguments :- a Color value
Return Value :- boolean Value
Description :- This function checks whether there are any valid Moves available for the player, playing with given color.
                The valid move also checks the safety of the King of that color. If no such moves, it returns True, else False.
**/
bool noMoves(Color c)
{
    int x1,y1,x2,y2;
    Square *src,*dest;
    Piece *t1,*t2;
    t1=new Empty();
    for(x1=0;x1<8;x1++)
    {
        for(y1=0;y1<8;y1++)
        {
            src=&B.board[x1][y1];
            for(x2=0;x2<8;x2++)
            {
                for(y2=0;y2<8;y2++)
                {
                    dest=&B.board[x2][y2];
                    if(src!=dest && (src->piece)->color==c && (src->piece)->validMove(src,dest))
                    {
                        t2=dest->piece;
                        dest->piece=src->piece;
                        src->piece=t1;
                        if(kingSafe(c))
                        {
                            src->piece=dest->piece;
                            dest->piece=t2;
                            h1.x=x1+1;
                            h1.y=y1+1;
                            h2.x=x2+1;
                            h2.y=y2+1;
                            return false;
                        }
                        src->piece=dest->piece;
                        dest->piece=t2;
                    }
                }
            }
        }
    }
    return true;
}

/**
Function Name :- checkPawn
Input Arguments :- a pointer to a Square
Return Value :- null
Description :- This function checks whether the pawn present at the given square has reached the opposite end. If yes, it asks the player to
                replace the pawn with a Rook, or a Knight, or a Bishop, or a Queen. It replaces that pawn with that new piece and returns the control.
                If not reached the opposite end, it returns.
**/
void checkPawn(Square* dest)
{
    if(((dest->piece)->color==WHITE && dest->pos.x==0) || ((dest->piece)->color==BLACK && dest->pos.x==7))
    {
        string type;
        int x;
        cout<<"Pawn reached the opposite end.";
        label:
            {
                cout<<"\nWhat do you want to replace it with ?";
                getline(cin,type);
                x=(dest->piece)->Steps_taken;
                if(type=="Rook")
                    dest->piece=new Rook((dest->piece)->color);
                else if(type=="Bishop")
                    dest->piece=new Bishop((dest->piece)->color);
                else if(type=="Knight")
                    dest->piece=new Knight((dest->piece)->color);
                else if(type=="Queen")
                    dest->piece=new Queen((dest->piece)->color);
                else
                {
                    cout<<"Invalid choice\n";
                    goto label;
                }
                (dest->piece)->Steps_taken=x;
            }
    }
    return;
}

/**
Function Name :- saveGame
Input Arguments :- a Color value
Return Value :- a boolean Value
Description :- This function asks the user whether wants to save the Game which he/she is quitting in between. If the user enters
                clear proper input (like Y or N), the game is saved or discarded accordingly and true is returned, else false is returned.
                It takes the color of the piece which was to be moved next, as input and stores it, so that the game can be continued from
                that stage only.
**/
bool saveGame(Color turn)
{
    char ch;
    cout<<"\nDo you wish to save the Game ? (Y/N):";
    cin>>ch;
    if(ch=='N')
        return true;
    else if(ch=='Y')
    {
        fout.open("SavedGame.txt");
        int i,j;
        Type p;
        Color c;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                fout<<B.board[i][j].pos.x<<" "<<B.board[i][j].pos.y;
                p=(B.board[i][j].piece)->type;
                c=(B.board[i][j].piece)->color;
                switch(p)
                {
                    case KING:(c==WHITE) ? fout<<" KING " : fout<<" king ";
                                break;
                    case QUEEN:(c==WHITE) ? fout<<" QUEEN " : fout<<" queen ";
                                break;
                    case KNIGHT:(c==WHITE) ? fout<<" KNIGHT " : fout<<" knight ";
                                break;
                    case BISHOP:(c==WHITE) ? fout<<" BISHOP " : fout<<" bishop ";
                                break;
                    case ROOK:(c==WHITE) ? fout<<" ROOK " : fout<<" rook ";
                                break;
                    case PAWN:(c==WHITE) ? fout<<" PAWN " : fout<<" pawn ";
                                break;
                    default:fout<<" Empty ";
                            break;
                }
                fout<<(B.board[i][j].piece)->Steps_taken<<"\n";
            }
        }
        (turn==WHITE) ? fout<<" WHITE " : fout<<" BLACK ";
        cout<<"\nGame saved\n";
        fout.close();
        return true;
    }
    else
    {
        cout<<"\nInvalid Input";
        return false;
    }
}

/**
Function Name :- Castle
Input Arguments :- a Color value
Return Value :- a boolean Value
Description :- This function checks all the necessary conditions for castling,castles and returns True if all conditions satisfy else returns false.
                It takes the color of the pieces to be castled as input.
**/
bool Castle(Color turn)
{
    string input;
    int x1,y1,x2,y2,i;
    Square* src,*dest;
    Piece* t;
    if(!kingSafe(turn))
    {
        cout<<"\nKing is in check."<<endl;
        return false;
    }
    src=getKing(turn);
    if((src->piece)->Steps_taken!=0)
    {
        cout<<"\nKing has already made a move."<<endl;
        return false;
    }
    (turn==WHITE) ? x1=7 : x1=0;
    y1=4;
    cout<<"\nEnter the co-ordinates of the Rook:";
    cin>>i;
    getline(cin,input);
    x2=(i/10)-1;
    y2=(i%10)-1;
    dest=&B.board[x2][y2];
    if((dest->piece)->type!=ROOK || (dest->piece)->color!=turn)
    {
        cout<<"\nInvalid co-ordinates entered for Rook."<<endl;
        return false;
    }
    if((dest->piece)->Steps_taken!=0)
    {
        cout<<"\nRook has already made a move."<<endl;
        return false;
    }
    if(y1<y2)
    {
        for(i=y1+1;i<y2;i++)
        {
            if(B.board[x1][i].piece->type!=EMPTY)
            {
                cout<<"\nObstacle in the path\n";
                return false;
            }
        }
        t=B.board[x1][y1+2].piece;
        B.board[x1][y1+2].piece=B.board[x1][y1].piece;
        B.board[x1][y1].piece=t;
        t=B.board[x2][y2-2].piece;
        B.board[x2][y2-2].piece=B.board[x2][y2].piece;
        B.board[x2][y2].piece=t;
        if(kingSafe(turn))
        {
            B.board[x1][y1+2].piece->Steps_taken++;
            return true;
        }
        t=B.board[x1][y1+2].piece;
        B.board[x1][y1+2].piece=B.board[x1][y1].piece;
        B.board[x1][y1].piece=t;
        t=B.board[x2][y2-2].piece;
        B.board[x2][y2-2].piece=B.board[x2][y2].piece;
        B.board[x2][y2].piece=t;
        cout<<"\nThis castling will put your King in check.\n";
        return false;
    }
    else
    {
        for(i=y1-1;i>y2;i--)
        {
            if(B.board[x1][i].piece->type!=EMPTY)
            {
                cout<<"\nObstacle in the path\n";
                return false;
            }
        }
        t=B.board[x1][y1-2].piece;
        B.board[x1][y1-2].piece=B.board[x1][y1].piece;
        B.board[x1][y1].piece=t;
        t=B.board[x2][y2+3].piece;
        B.board[x2][y1+3].piece=B.board[x1][y1].piece;
        B.board[x2][y1].piece=t;
        if(kingSafe(turn))
        {
            B.board[x1][y1-2].piece->Steps_taken++;
            return true;
        }
        t=B.board[x1][y1-2].piece;
        B.board[x1][y1-2].piece=B.board[x1][y1].piece;
        B.board[x1][y1].piece=t;
        t=B.board[x2][y2+3].piece;
        B.board[x2][y2+3].piece=B.board[x2][y2].piece;
        B.board[x2][y2].piece=t;
        cout<<"\nThis castling will put your King in check.\n";
        return false;
    }
}
