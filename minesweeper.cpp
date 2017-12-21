//
//  *** MINESWEEPER ***
//  -- Concurso Programacion, Ejercicio 2 --
//  By Martín García-Ripoll Muñoz, Lucas Gil Melby, Quico Llinares Llorens & Gonzalo Molina Gallego  (Grupo ARA)
//  Copyright© 2014. All rights reserved!!
//
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

const int RMAX = 10;
const int CMAX = 10;


// modules declaration
void play(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int openmines, int open, int &scoreout, bool &lost);
void verifyRound(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int userR, int userC, bool &lost);
void display(char gameboard2show[RMAX][CMAX]);
void multiplayer(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int openmines, int open, int scores[2], string &winner, string &loser);
void instructions();
void inicialization(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int scores[2], int &open, int &open_mines);


// main program
int main(){
    srand(time(NULL));
    
    string winner, loser;
    bool lost;
    char gameboard[RMAX][CMAX];
    char gameboard2show[RMAX][CMAX];
    int opt;
    int scores[2], i, j, k, l, m, n, o, p, open, open_mines, score;
    
    //Title.
    
    for (i=0; i<60; i++) {
        cout<<endl;
    }
    
    for (j=0; j<19; j++) {
        cout<<" ";
    }
    
    for (k=0; k<13; k++) {
        cout<<"-";
        
    }
    cout<<endl;
    
    for (l=0; l<18; l++) {
        cout<<" ";
    }
    
    cout<<"|";
    for (m=0; m<13; m++) {
        cout<<" ";
    }
    cout<<"|"<<endl;
    
    for (n=0; n<18; n++) {
        cout<<" ";
    }
    
    cout<<"| BUSCAMINAS |"<<endl;
    
    for (o=0; o<18; o++) {
        cout<<" ";
        
    }
    
    cout<<"|";
    for (m=0; m<13; m++) {
        cout<<" ";
    }
    cout<<"|"<<endl;
    
    for (j=0; j<19; j++) {
        cout<<" ";
    }
    
    for (p=0; p<13; p++) {
        cout<<"-";
        
    }
    cout<<endl<<endl<<endl;
    
    // Menu.
    do {
        cout<<"-- Main Menu --"<<endl<<endl;
        cout<<"1. Single Player"<<endl;
        cout<<"2. One on One (Multiplayer)"<<endl;
        cout<<"3. Instructions"<<endl;
        cout<<"4. Exit"<<endl<<endl;
        
        do{
            cout<<"Introduce an option: "<<endl;
            cin>>opt;
            if (opt<1 || opt>4) {
                cout<<"\031[0;" << 31 << "mERROR. Incorrect option.\033[0m"<< " "<<endl;
            }
        }while(opt<1 || opt>4);
        
        switch (opt) {
            case 1:
                inicialization(gameboard, gameboard2show, scores, open, open_mines);
                play(gameboard, gameboard2show, open_mines, open, score, lost);
                cout<<endl<<endl<<endl<<endl;
                if (lost) {
                    cout<<"NI NO NI NO NI NO! Calling the ambulance! You got hit by a mine!!"<<endl;
                    cout<<"Before you got hit you managed to open "<<score<<" box(es)..."<<endl<<endl<<endl<<endl;
                }else{
                    cout<<"Oh my gosh! CONGRATULATIONS!!! You managed to open all the box(es)! "<<score<<" to be more precise!"<<endl<<endl<<endl<<endl;
                }
                
                break;
                
            case 2:
                inicialization(gameboard, gameboard2show, scores, open, open_mines);
                multiplayer(gameboard, gameboard2show, open_mines, open, scores, winner, loser);
                cout<<endl<<endl<<endl<<endl;
                if (scores[0]==scores[1]) {
                    cout<<"What a coincidence!! You guys tied! You both opened "<<scores[0]<<" box(es)!"<<endl<<endl<<endl;
                }else{
                    cout<<"Sorry "<<loser<<", "<<winner<<" opened "<<scores[0]-scores[1]<<" box(es) more than you!"<<endl;
                    cout<<winner<<": "<<scores[0]<<" box(es) opened."<<endl;
                    cout<<loser<<": "<<scores[1]<<" box(es) opened."<<endl;
                    cout<<endl<<endl;
                }
                break;
            case 3:
                instructions();
                break;
            case 4:
                cout<<"Bye! Hope to see you soon!  :)"<<endl<<endl;
                break;
                
            default:
                cout<<"\033[0;" << 31 << "mERROR.\033[0m"<< " "<<endl;
                break;
        }
    }while (opt!=4);
}






// modules definition

void inicialization(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int scores[2], int &open, int &open_mines){
    
    
   
    
    // Inicialization of Gameboard.
    
    srand(time(0));
    
    int i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, mines=0, r1=0, c1=0, r2=0, c2=0;
    
    for (o=1; o<RMAX-1; o++) {
        for (p=1; p<CMAX-1; p++) {
            gameboard[o][p]=' '; // Writes a ' ' in every position to clean the array.
            
        }
    }
    
    
    while (k<12) {// Places 10 mines in ten diffrent random positions.
        
        r1 = rand()%8+1;
        c1 = rand()%8+1;
        
        if(gameboard[r1][c1]!='*'){
            gameboard[r1][c1]='*';
            k++;
        }
        
    }
    
    
    for (i=1; i<RMAX-1; i++) {   // Computes the number of adjacent mines to each box.
        for (j=1; j<CMAX-1; j++) {
            if (gameboard[i][j]!='*') {
                for (l=i-1; l<=i+1; l++) { // Checks what's around it.
                    for (m=j-1; m<=j+1; m++) {
                        if (gameboard[l][m]=='*') {
                            mines++;
                        }
                    }
                }
            
            
                switch (mines) {
                    case 1:
                        gameboard[i][j]='1';
                        mines=0;
                        break;
                        
                    case 2:
                        gameboard[i][j]='2';
                        mines=0;
                        break;
                   
                    case 3:
                        gameboard[i][j]='3';
                        mines=0;
                        break;
                        
                    case 4:
                        gameboard[i][j]='4';
                        mines=0;
                        break;
                        
                    case 5:
                        gameboard[i][j]='5';
                        mines=0;
                        break;
                        
                    case 6:
                        gameboard[i][j]='6';
                        mines=0;
                        break;
                        
                    case 7:
                        gameboard[i][j]='7';
                        mines=0;
                        break;
                        
                    case 8:
                        gameboard[i][j]='8';
                        mines=0;
                        break;
                        
                    case 0:
                        gameboard[i][j]=' ';
                        mines=0;
                        break;
                        
                    default:
                        cout<<"\033[0;" << 31 << "mERROR.\033[0m"<< " "<<endl;
                        mines=0;
                        
                        break;
                }
            }
            }
            
        }
        
    
    
    // Inicialization of Gameboard2Show.
    for (o=1; o<RMAX-1; o++) {
        for (p=1; p<CMAX-1; p++) {
            gameboard2show[o][p]='-'; // Writes a '-' in every position.
            
        }
    }
    open = rand()%64;
    open_mines=0;
    for (n=0; n<open; n++) { //Opens a random number of boxes.
        r2 = rand()%8+1;
        c2 = rand()%8+1;
        if (gameboard2show[r2][c2]=='-') {
            gameboard2show[r2][c2]=gameboard[r2][c2];
            if (gameboard[r2][c2]=='*') {
                open_mines++; // Counts how many mines are showed when the game starts, this number is used to compute when the user has finished the game.
            }
            }
        else{
            n--;
        }
        
    }
    
    // Inicialization of vector Scores.
    scores[0]=0;
    scores[1]=0;
    
}


// This module checks if the player has lost or not, and opens graphically the selected box (for the display)
void verifyRound(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int userR, int userC, bool &lost){
    gameboard2show[userR][userC] = gameboard[userR][userC];
    if (gameboard[userR][userC]=='*') {

        display(gameboard2show);
    }else{
        lost = false;
    }
}

// this module just displays the mine field on the screen
void display(char gameboard2show[RMAX][CMAX]){
    int i, j, k;
    for (k=0; k<60; k++) {
        cout<<endl;
    }
    cout<<"  1 2 3 4 5 6 7 8"<<endl;
    for (i=1; i<9; i++) {
        cout<<i<<" ";
        for (j=1; j<9; j++) {
            if(gameboard2show[i][j] == '*'){
                cout<<"\033[1;" << 31 << "m*\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '1'){
                cout<<"\033[0;" << 36 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '2'){
                cout<<"\033[0;" << 32 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '3'){
                cout<<"\033[0;" << 35 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '4'){
                cout<<"\033[0;" << 31 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '5'){
                cout<<"\033[0;" << 34 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '6'){
                cout<<"\033[0;" << 33 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '7'){
                cout<<"\033[1;" << 34 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == '8'){
                cout<<"\033[1;" << 31 << "m"<< gameboard2show[i][j] <<"\033[0m"<< " ";
            }else if(gameboard2show[i][j] == ' '){
                cout<<"  ";
            }else{
                cout<<gameboard2show[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

//this module is the one used for each turn, which controls whats happens and when it happens.
void play(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int openmines, int open, int &scoreout, bool &lost){
    int userR=0, userC=0;
    lost = false;
    
    for (scoreout=0; lost==false && 64!=scoreout+open+(10-openmines); scoreout++) {
        display(gameboard2show);
        cout<<endl;
        
        do{
        do{
            cout<<"Select a row: ";
            cin>>userR;
            if (userR<1 || userR>8) {
                cout<<"\033[0;" << 31 << "mERROR. The minimum row is 1 and the maximum is 8. Try again.\033[0m"<< " ";
                cout<<endl;
            }
        }while(userR<1 || userR>8);
        do{
            cout<<"Select a column: ";
            cin>>userC;
            if (userC<1 || userC>8) {
                cout<<"\033[0;" << 31 << "mERROR. The minimum column is 1 and the maximum is 8. Try again.\033[0m"<< " ";
                cout<<endl;
            }
        }while(userC<1 || userC>8);
            if (gameboard2show[userR][userC]!='-') {
                cout<<"Oups! That box is already open. Please, select another one!"<<endl;
            }
            
        }while(gameboard2show[userR][userC]!='-');
        
        verifyRound(gameboard, gameboard2show, userR, userC, lost);
        
    }
}

//this module is an extra implementation to allow two player to compite.
void multiplayer(char gameboard[RMAX][CMAX], char gameboard2show[RMAX][CMAX], int openmines, int open, int scores[2], string &winner, string &loser){
    bool lost;
    char opt;
    string player1, player2;
    int scorep1, scorep2;
    cout<<"What's the name of Player 1? ";
    cin >> player1;
    cout<<"What's the name of Player 2? ";
    cin >> player2;
    do{
    cout<<player1<<", are you ready to play? [y/n] ";
    cin>>opt;
    }while(opt!='y' && opt!='Y');
    //player 1 turn
    play(gameboard,gameboard2show, openmines, open, scorep1, lost);
    if (lost==true) {
        cout<<"NI NO NI NO NI NO! Calling the ambulance! You got hit by a mine!!"<<endl;
    }else{
        cout<<"Well done!"<<endl;
    }
    opt='a';
    do{
        cout<<endl<<player2<<", are you ready to play? [y/n] ";
        cin>>opt;
    }while(opt!='y' && opt!='Y');
    //player 2 turn
    inicialization(gameboard, gameboard2show, scores, open, openmines);
    play(gameboard,gameboard2show, openmines, open, scorep2, lost);
    if (lost==true) {
        cout<<"NI NO NI NO NI NO! Calling the ambulance! You got hit by a mine!!"<<endl;
    }else{
        cout<<"Well done!"<<endl;
    }
    cout<<endl;
    
    // organising the information for returning to main
    if (scorep1>scorep2) {
        scores[0]=scorep1;
        scores[1]=scorep2;
        winner = player1;
        loser = player2;
    }else{
        scores[0]=scorep2;
        scores[1]=scorep1;
        winner = player2;
        loser = player1;
    }
}

// instructions of the game. Just displays the instructions
void instructions(){
    int i;
    for (i=0; i<60; i++) {
        cout<<endl;
    }
    cout<<"INSTRUCTIONS"<<endl<<endl;
    cout<<"The game consists in opening all the boxes avoiding the mines."<<endl;
    cout<<"First you will see the mine-field, with some boxes opened and some other closed (-)."<<endl;
    cout<<"Some of the opened boxes will have a number (between 1 and 8) which indicates the number of mines that"<<endl;
    cout<<"are contained in the boxes which are in contact with that box (including the diagonal ones)."<<endl;
    cout<<"The mine symbol is '*' and the best you can do is avoid them. If you open a box and a mine was inside"<<endl;
    cout<<"you will lose. The goal is to open as many boxes as possible. Keep in mind that there are 10 mines."<<endl;
    cout<<"The game will end either when you open all the boxes not including the ones that contain a mine, or "<<endl;
    cout<<"when you open a box which contains a mine."<<endl;
    cout<<"Good luck!"<<endl<<endl<<endl;
}
