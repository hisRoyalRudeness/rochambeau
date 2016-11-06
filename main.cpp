//rock paper scissors game

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int winner (string comp, string human);
string lost (string human);
string won (string human);
int main ()
{   srand((unsigned int)time(0));
    
    int compSelect = rand()%100;
    string compChoice;
    int whoWon = 0;
    string humanChoice;
    int compScore=0;
    int humanScore=0;
    
    cout << "Welcome to rock paper scissors! Remember to only use lowercase. First to 7 wins!";
    
    int count = 50;
    while (count > 0)
    {
        cout << "*";
        count--;
    }
    if (compSelect < 34)
        compChoice = "rock";
    else if (compSelect < 67)
        compChoice = "paper";
    else
        compChoice = "scissors";
    
    while (compScore < 7 && humanScore < 7)
    {   cout << "\nrock...\npaper...\nscissors...\nshoot!\n-->";
        cin >> humanChoice;
        cout << compChoice;
        whoWon = winner(compChoice, humanChoice);
        
        if (whoWon == 1)
            compChoice = lost(humanChoice);
        else if (whoWon == 2)
            compChoice = won(compChoice);
        else
            compChoice = lost(compChoice);
        
        if (whoWon == 1)
        {
            cout<< "\n\nHuman wins!";
            humanScore++;
        }
        else if (whoWon == 2)
        {
            cout<< "\n\nComputer wins!";
            compScore++;
        }
        else
            cout << "\n\nTie...";

        cout << "HUMAN: " << humanScore << "\tMACHINE: " << compScore << endl;
        
        count = 50;
        while (count > 0)
        {
            cout << "*";
            count--;
        }
    }
    if (compScore > humanScore)
        cout << "\nMwwwwahahahaha....\n\n\n";
    else
        cout << "\n...good job, mortal";
    return 0;
}

int winner (string comp, string human)
{
    string compChoice = comp;
    string humanChoice = human;
    //1 means human wins, 2 means computer wins
    if (compChoice == humanChoice)
        return 0;
    else if (compChoice == "rock" && humanChoice == "paper")
        return 1;
    else if (compChoice == "rock" && humanChoice == "scissors")
        return 2;
    else if (compChoice == "paper" && humanChoice == "rock")
        return 2;
    else if (compChoice == "paper" && humanChoice == "scissors")
        return 1;
    else if (compChoice == "scissors" && humanChoice == "rock")
        return 1;
    else if (compChoice == "scissors" && humanChoice == "paper")
        return 2;
    else
        return 0;
    
}

string lost (string human)
{
    string testCase = human;
    int compSelect = rand()%100;
    string compChoice;
    if (testCase == "rock")
    {
        if (compSelect < 50)
            compChoice = "rock";
        else if (compSelect < 75)
            compChoice = "paper";
        else
            compChoice = "scissors";
    }
    else if (testCase == "paper")
    {
        if (compSelect < 50)
            compChoice = "paper";
        else if (compSelect < 75)
            compChoice = "rock";
        else
            compChoice = "scissors";
    }
    else if (testCase == "scissors")
    {
        if (compSelect < 50)
            compChoice = "scissors";
        else if (compSelect < 75)
            compChoice = "paper";
        else
            compChoice = "rock";
    }
    
    return compChoice;
}

string won (string comp)
{
    string testCase = comp;
    int compSelect = rand()%100;
    string compChoice;
    
    if (testCase == "rock")
    {
        if (compSelect < 60)
            compChoice = "scissors";
        else if (compSelect < 80)
            compChoice = "paper";
        else
            compChoice = "rock";
    }
    else if (testCase == "paper")
    {
        if (compSelect < 60)
            compChoice = "rock";
        else if (compSelect < 80)
            compChoice = "paper";
        else
            compChoice = "scissors";
    }
    else if (testCase == "scissors")
    {
        if (compSelect < 60)
            compChoice = "paper";
        else if (compSelect < 80)
            compChoice = "scissors";
        else
            compChoice = "rock";
    }
    return compChoice;
}