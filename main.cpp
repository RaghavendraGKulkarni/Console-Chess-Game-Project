#include "Chess.cpp"

/**
Function Name :- menu
Input Arguments :- null
Return Value :- null
Description :- The function which displays the menu which allows the user to select any one option
               among Starting a Game , Knowing about the Game and Exit the Application.
**/
void menu()
{
    system("cls");
    cout<<"\tWelcome to PC Console Chess Game\n";
    cout<<"\n1.Start a New Game";
    cout<<"\n2.About the Game";
    cout<<"\n3.How to Play the Game";
    cout<<"\n4.Exit";
    cout<<"\nEnter your choice:";
}

/**
Function Name :- main
Input Arguments :- null
Return Value :- null
Description :- The Driver function which invokes other functions to run the Application.
**/
int main()
{
    int choice;
    cout<<"\n\n\t\tRecommended:- Enlarge the Window for better experience";
    delay(time_gap+1);
    do
    {
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:Game();
                    break;
            case 2:aboutChess();
                    system("pause");
                    break;
            case 3:aboutGame();
                    system("pause");
                    break;
            case 4:cout<<"\nTerminating Application\n";
                    break;
            default:cout<<"\nInvalid Choice\n";
                    delay(time_gap);
                    break;
        }
    }while(choice!=4);
    return 0;
}