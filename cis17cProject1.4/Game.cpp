/* 
 * File:   Game.cpp
 * Author: Jason
 *
 * Created on April 17, 2021, 9:04 PM
 * 
 * Game.cpp will contain the games main loop and all the games functions
 */

#include "Card.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"


ofstream scoreB ("scoreBoard.txt");

  /****************************************************************************\
  * displayWelcom                                                              *
  * This function will simply display the welcome screen and message           *  
  \****************************************************************************/
void displayWelcome()
{
    cout << string(50, '\n');
    cout <<"`7MMF'     A     `7MF'     `7MM                            "
        "                      mm                 \n";
    cout <<"  `MA     ,MA     ,V         MM                            "
        "                      MM                 \n";
    cout <<"   VM:   ,VVM:   ,V .gP\"Ya   MM  ,p6\"bo   ,pW\"Wq.`7MMpMM"
        "Mb.pMMMb.  .gP\"Ya      mmMMmm ,pW\"Wq.  \n"; 
    cout <<"    MM.  M' MM.  M',M'   Yb  MM 6M'  OO  6W'   `Wb MM    MM"
        "    MM ,M'   Yb       MM  6W'   `Wb      \n";
    cout <<"    `MM A'  `MM A' 8M''''''  MM 8M       8M     M8 MM    MM"
        "    MM 8M''''''       MM  8M     M8      \n";
    cout <<"     :MM;    :MM;  YM.    ,  MM YM.    , YA.   ,A9 MM    MM"
        "    MM YM.    ,       MM  YA.   ,A9      \n";
    cout <<"      VF      VF    `Mbmmd'.JMML.YMbmd'   `Ybmd9'.JMML  JMM"
        "L  JMML.`Mbmmd'       `Mbmo`Ybmd9'       \n";
    this_thread::sleep_for (std::chrono::seconds(1));
    cout << string(100, '\n');

    cout << "\t`7MMF'     A     `7MF' db      `7MM''''Mq.  \n";
    cout << "\t  `MA     ,MA     ,V  ;MM:       MM   `MM.  \n";
    cout << "\t   VM:   ,VVM:   ,V  ,V^MM.      MM   ,M9   \n";
    cout << "\t    MM.  M' MM.  M' ,M  `MM      MMmmdM9    \n";
    cout << "\t    `MM A'  `MM A'  AbmmmqMA     MM  YM.    \n";
    cout << "\t     :MM;    :MM;  A'     VML    MM   `Mb.  \n";
    cout << "\t      VF      VF .AMA.   .AMMA..JMML. .JMM. \n\n";
    this_thread::sleep_for (std::chrono::seconds(1));
    cout << string(100, '\n');

    cout << "\t  mm   `7MM                  \n";
    cout << "\t  MM     MM                  \n";
    cout << "\tmmMMmm   MMpMMMb.  .gP\"Ya   \n";
    cout << "\t  MM     MM    MM ,M'   Yb   \n";
    cout << "\t  MM     MM    MM 8M''''''   \n";
    cout << "\t  MM     MM    MM YM.    ,   \n";
    cout << "\t  `Mbmo.JMML  JMML.`Mbmmd'   \n\n";

    cout << "\t   .g8'''bgd                      `7MM      .g8'''bgd       \n";
    cout << "\t .dP'     `M                        MM    .dP'     `M       \n";
    cout << "\t dM'       ` ,6'Yb.  `7Mb,od8  ,M''bMM    dM'       `  ,6\"Yb."
            "  `7MMpMMMb.pMMMb.  .gP\"Ya \n";
    cout << "\t MM         8)   MM    MM' \"',AP    MM    MM          8)   MM"
            "    MM    MM    MM ,M'   Yb \n";
    cout << "\t MM.         ,pm9MM    MM    8MI    MM    MM.    `7MMF',pm9MM"
            "    MM    MM    MM 8M''''''  \n";
    cout << "\t `Mb.     ,'8M   MM    MM    `Mb    MM    `Mb.     MM 8M   MM"
            "    MM    MM    MM YM.    ,  \n";
    cout << "\t   `''bmmmd' `Moo9^Yo..JMML.   `Wbmd'MML. `''bmmmdPY  `Moo9^Yo"
            "..JMML  JMML  JMML.`Mbmmd'  \n\n";
    this_thread::sleep_for (std::chrono::seconds(1));
    cout << string(100, '\n');
}
  /****************************************************************************\
  * mainMenu                                                                   *
  * This function will display the welcome screen and message and give the     * 
  * user options.                                                              *
  * Variables: userChoice holds the users menu choice userName holds the user  *
  * name for high scores.                                                      *
  \****************************************************************************/
void mainMenu()
{
    int userChoice = 5;
    string userName;
    
    while(userChoice != 0) 
    {

        cout << "---------------------------\n";
        cout << "|        Main Menu        |\n";
        cout << "---------------------------\n";
        cout << "1) Play WAR\n";
        cout << "2) Rules\n";
        cout << "3) Score Board\n";
        cout << "4) Exit Game ";
        cout << string(10, '\n');       
        
        cin >> userChoice;

        switch (userChoice)
        {
            case 1:
                cout << "Lets play WAR!\n";
//                cout << "Enter your Name:";
//                cin >> userName;
                gameLoop();
                  
                break;

            case 2:
                rules();
                break;

            case 3:
                cout << "Score Board";
                break;
            case 4:
                cout << "Thank you for playing!\n";
                userChoice = 0;
        }
    }
}
void gameLoop()
{
    Deck game;
    Player p1;
    Player cpu;
    cout << "Dealing Cards...\n";
    
    game.dealCards(p1);
    game.dealCards(cpu);
    
    do
    {
        cout << "The Battle Begins!\n";
        
        Card p1Top = p1.currHand.top();
        Card cpuTop = cpu.currHand.top();
        
        cout << "Your Card:\n";
        p1.displayTopCard();
        cout << "Computers Card:\n";
        cpu.displayTopCard();
//        if (p1Top.cPower > cpuTop.cPower)
//        {
//            
//        }
        
        
        
    }
    while ((p1.currHand.size() + p1.wonCards.size()) != 52 &&
            (cpu.currHand.size() + cpu.wonCards.size()) !=52);
}
  /****************************************************************************\
  * rules                                                                      *
  * This function will display the rules of the game                           *                                                                           *  
  \****************************************************************************/
void rules()
{
    cout << "The goal is to be the first player to win all 52 cards\n\n"
    "----------------------------THE DEAL----------------------------\n"
    "The deck is divided evenly, with each player receiving 26 cards,\n"
    "dealt one at a time, face down. Anyone may deal first. Each\n"
    "player places their stack of cards face down, in front of\n"
    "them.\n\n"
    "----------------------------THE PLAY----------------------------\n"
    "Each player turns up a card at the same time and the player\n"
    "with the higher card takes both cards and puts them, face down,\n"
    "on the bottom of his stack.\n\n"
    "If the cards are the same rank, it is War. Each player turns up\n"
    "one card face down and one card face up. The player with the\n"
    "higher cards takes both piles (six cards). If the turned-up\n"
    "cards are again the same rank, each player places another card\n"
    "face down and turns another card face up. The player with the\n"
    "higher card takes all 10 cards, and so on.\n\n"
    "-----------------------HOW TO KEEP SCORE-----------------------\n"
    "The game ends when one player has won all the cards.\n\n"
    "Press any key to return to Main Menu\n\n";

}

void scoreBoard()
{
    string line;
    ifstream scoreB ("scoreBoard.txt");
    if (scoreB.is_open())
    {
        while ( getline (scoreB,line) )
        {
        cout << line << '\n';
        }
        scoreB.close();
    }

    else cout << "Unable to open file";
}