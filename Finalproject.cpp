#include <iostream>
#include <fstream>
#include "clui.h"
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
int playernum = 0;
int slotnum = 0;
struct Game
{
    int boardlength;
    int boardwidth;
    int mines;
    char** play;
    int** bomb;
    string name;
    int PlayerNum;
    long int point;
}players[11];

struct leaderboard
{
    long int point;
    string name;
}Leaderboard[11];

struct LoadGame
{
    int boardlength;
    int boardwidth;
    int mines;
    char** play;
    int** bomb;
    string name;
    int PlayerNum;
    long int point;
}saveslot[4];

void swapnum(long int &a, long int &b)
{
    int temp=b;
    b=a;
    a=temp;
}
void swapstring(string &s1, string &s2)
{
    string temp=s1;
    s1=s2;
    s2=temp;
}

void BubbleSort(leaderboard Leaderboard[])
{
    for(int i=1; i<10; i++){
        for(int j=i+1; j<11; j++){
            if(Leaderboard[j].point > Leaderboard[i].point){
                swapnum(Leaderboard[j].point,Leaderboard[i].point);
                swapstring(Leaderboard[j].name,Leaderboard[i].name);}}}
}

void Title(long int &score, Game players[], int playernum)
{
    change_color_rgb(252, 252, 124);
    cout << "\n                        Wellcome To Mine Sweeper                               \n";
    cout << "___________________________________________________________________________\n";
    cout << "---------------------------------------------------------------------------\n";
    change_color_rgb(216, 167, 252);
    cout << "Hi Dear ";
    change_color_rgb(134, 235, 252);
    cout << players[playernum].name << ".\n";
    change_color_rgb(216, 167, 252);
    cout << "Your Score is : ";
    change_color_rgb(250, 5, 168);
    cout << score << "\n";
    change_color_rgb(216, 167, 252);
    cout << "Enter O to save your game and Q for home page during the game.\n";
    change_color_rgb(252, 252, 124);
    cout << "---------------------------------------------------------------------------\n\n";
    reset_color();

}
void PrintMenu1()
{
    change_color_rgb(71, 255, 163);
    cout << "-Menu-\n\n";
    reset_color();
    cout << "1. New Game\n";
    cout << "2. Load Game (Not Done)\n";
    cout << "3. Change Name\n";
    cout << "4. LeaderBoard\n";
    cout << "5. Quit\n\n";
    change_color_rgb(71, 255, 163);
    cout << ">  Select: ";
    reset_color();
}
void PrintMenu2()
{
    change_color_rgb(71, 255, 163);
    cout << "Please Choose the level:\n\n";
    reset_color();
    cout << "1. Easy (5x5 & 4 mines)\n";
    cout << "2. Medium (12x12 & 28 mines)\n";
    cout << "3. Hard (20x20 & 96 mines)\n";
    cout << "4. Manual adjustment.\n";
    cout << "5. Go back to Home page.\n\n";
    change_color_rgb(71, 255, 163);
    cout << ">  Select: ";
    reset_color();

}

void print(int boardlength ,int boardwidth ,char** &play)
{
    change_color_rgb(243, 252, 141);
    printf("\t   1");
    for (int i = 1; i < boardwidth; i++){
    if(i < 10)
    printf("  %d", i + 1);
    else
    printf(" %d", i + 1);}
    printf("\n\t1 ");
    for (int i = 1; i <= boardlength; i++){
        for (int j = 1; j <= boardwidth ;j++){
            if(i < 10 && j <= 10){
            cout << " ";
            if(play[i][j]=='B')
            {
                change_color_rgb(250, 52, 69);
            }
            else if(play[i][j]=='F')
            {
                change_color_rgb(46, 255, 168);
            }
            else
            {
                reset_color();
            }
            cout << play[i][j] << " ";
            reset_color();}
            else{
            if(play[i][j]=='B')
            {
                change_color_rgb(250, 52, 69);
            }
            else if(play[i][j]=='F')
            {
                change_color_rgb(46, 255, 168);
            }
            else
            {
                reset_color();
            }
            cout << play[i][j] << "  ";
            reset_color();}
    if(i < 10 && j == 10){cout << " ";}}
    change_color_rgb(243, 252, 141);
    if (i != boardlength)
    printf("\n\t%d ", i + 1);}
    reset_color();
}
int Count(int** &bomb, int &crdx, int &crdy)
{
    int count=0;
    if(bomb[crdx-1][crdy]==1){count++;}
    if(bomb[crdx+1][crdy]==1){count++;}
    if(bomb[crdx][crdy+1]==1){count++;}
    if(bomb[crdx][crdy-1]==1){count++;}
    if(bomb[crdx-1][crdy+1]==1){count++;}
    if(bomb[crdx-1][crdy-1]==1){count++;}
    if(bomb[crdx+1][crdy+1]==1){count++;}
    if(bomb[crdx+1][crdy-1]==1){count++;}
    return count;
}

char* namecheck(Game players[], int playernum)
{
        int count=0,check=1;
        string name;
        while(check==1){
        check=0;
        cin >> name;
        int counter=0;
        while(name[counter] != '\0'){
            count++;
            counter++;}
        for(int i=1; i<11; i++){
            int counter2=0;
            if(check==1){break;}
        for(int j=0; j<count; j++){
            if(name[j] == players[i].name[j]){counter2++;}
            if(counter2==count){check=1;}}}

        if(check==1)
            {cout << "\nThis name is already Taken. Please Choose another name: ";}
        else
            {cout << "\nYour name is now: ";
            change_color_rgb(134, 235, 252);
            cout << name << "." << endl;
            reset_color();
            players[playernum].name=name;}}
}

int main()
{
    init_clui();
    Game players[11];
    Game SaveSlot[4];
    for(int i=0; i<11; i++){
    players[i].point=0;}
    players[0].name="player";
    start:
    players[playernum].PlayerNum = playernum;
    Title(players[playernum].point,players,playernum);
    PrintMenu1();
    int menu1;
    cin >> menu1;

    if (menu1 == 1)
    {
        clear_screen();
        Title(players[0].point,players,0);
        cout << "Please Enter Your name : ";
        playernum++;
        namecheck(players,playernum);
        clear_screen();
        Title(players[playernum].point,players,playernum);
        PrintMenu2();
        int menu2;
        cin >> menu2;
        players[playernum].mines = 0, players[playernum].boardlength = 0,players[playernum].boardwidth = 0;
        if (menu2 == 1){players[playernum].mines = 4, players[playernum].boardlength = 5, players[playernum].boardwidth=5;}
        else if (menu2 == 2){players[playernum].mines = 28, players[playernum].boardlength = 12, players[playernum].boardwidth=12;}
        else if (menu2 == 3){players[playernum].mines = 96, players[playernum].boardlength = 20, players[playernum].boardwidth=20;}
        else if (menu2 == 4){
            cout << "Enter Mines count (mines >= 4):";
            cin >> players[playernum].mines;
            cout << "Enter board row [5,20]:";
            cin >> players[playernum].boardlength;
            cout << "Enter board colomn [5,20]:";
            cin >> players[playernum].boardwidth;}
        else if(menu2 == 5)
        {
            clear_screen();
            goto start;
        }

        clear_screen();
        Title(players[playernum].point,players,playernum);

        players[playernum].bomb = new int *[players[playernum].boardlength + 2];
        for (int i = 0; i < players[playernum].boardlength + 2; i++){
            players[playernum].bomb[i] = new int[players[playernum].boardwidth+ 2];}

        for (int i = 0; i < players[playernum].boardlength + 2; i++){
            for (int j = 0; j < players[playernum].boardwidth + 2; j++){
                players[playernum].bomb[i][j] = 0;}}

        players[playernum].play = new char *[players[playernum].boardlength + 2];
        for (int i = 0; i < players[playernum].boardlength +2 ; i++){
            players[playernum].play[i] = new char[players[playernum].boardwidth+ 2];}

        for (int i = 1; i < players[playernum].boardlength + 1; i++){
            for (int j = 1; j < players[playernum].boardwidth + 1; j++){
                players[playernum].play[i][j] = '#';}}

        srand(time(0));
        int maked_bombs = 0;
        while (maked_bombs < players[playernum].mines){
            int temp = rand() % (players[playernum].boardwidth * players[playernum].boardlength);
            if (players[playernum].bomb[temp % players[playernum].boardlength + 1][temp / players[playernum].boardwidth + 1] == 0){
                maked_bombs++;
            players[playernum].bomb[temp % players[playernum].boardlength + 1][temp / players[playernum].boardwidth + 1] = 1;}}

        int x2,y2,crdx=1,crdy=1;
        x2=get_cursor_x();
        y2=get_cursor_y();
        y2+=11;
        x2++;
        print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
        int flag=0,count2;
        while(flag==0 && count2 < (players[playernum].boardlength*players[playernum].boardwidth - players[playernum].mines)){
        cursor_to_pos(x2,y2);
        char Move=getch();
        if(Move == 'A' || Move == 'a')
        {
            y2-=3;
            crdy--;
            clear_screen();
            Title(players[playernum].point,players,playernum);
            print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
        }
        else if(Move == 'D' || Move == 'd')
        {
            y2+=3;
            crdy++;
            clear_screen();
            Title(players[playernum].point,players,playernum);
            print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
        }
        else if(Move == 'W' || Move == 'w')
        {
            x2--;
            crdx--;
            clear_screen();
            Title(players[playernum].point,players,playernum);
            print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
        }
        else if(Move == 'S' || Move == 's')
        {
            x2++;
            crdx++;
            clear_screen();
            Title(players[playernum].point,players,playernum);
            print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
        }
        else if(Move == 'F' || Move == 'f')
        {
            if(players[playernum].play[crdx][crdy]=='F'){players[playernum].play[crdx][crdy]='#';}
            else
            players[playernum].play[crdx][crdy]='F';
            clear_screen();
            Title(players[playernum].point,players,playernum);
            print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
        }
        else if(Move == ' ' || Move == ' ')
        {

            if(players[playernum].bomb[crdx][crdy]==1){
                    for(int i=0; i<players[playernum].boardwidth + 2; i++){
                        for(int j=0; j<players[playernum].boardlength + 2; j++){
                            if(players[playernum].bomb[i][j]==1){players[playernum].play[i][j]='B';}}}
                    clear_screen();
                    Title(players[playernum].point,players,playernum);
                    print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
                    flag=1;}
            else{
                players[playernum].play[crdx][crdy] = 48 + Count(players[playernum].bomb,crdx,crdy);
                players[playernum].point+=10;
                if(players[playernum].play[crdx][crdy] == '0'){players[playernum].play[crdx][crdy]=' ';}
                clear_screen();
                Title(players[playernum].point,players,playernum);
                print(players[playernum].boardlength ,players[playernum].boardwidth ,players[playernum].play);
                count2=0;
                for(int i=1; i<players[playernum].boardwidth+1; i++){
                    for(int j=1; j<players[playernum].boardlength+1; j++){
                        if(players[playernum].play[i][j]!='B' && players[playernum].play[i][j]!='#' && players[playernum].play[i][j]!='F'){count2++;}}}
        }}
        else if(Move == 'O' || Move == 'o')
        {

            clear_screen();
            goto start;
        }
        else if(Move == 'Q' || Move == 'q')
        {
            clear_screen();
            goto start;
        }
        }
        if(flag==1)
        {
            change_color_rgb(250, 52, 69);
            cout << "\n\nI'm Sorry, You Lost :( Better luck next time.";
            reset_color();
        }

        if(count2 == (players[playernum].boardwidth*players[playernum].boardlength - players[playernum].mines))
        {
            change_color_rgb(46, 255, 168);
            cout << "\n\nCongragulations, You Won  \\(^_^)/";
            reset_color();
        }
    }

    else if(menu1 == 2)
    {
        clear_screen();
        Title(players[playernum].point,players,playernum);
        change_color_rgb(71, 255, 163);
        cout << "Select slot to load:\n";
        reset_color();
        cout << "--> 1\n";
        cout << "--> 2\n";
        cout << "--> 3\n";
        cout << "--> 4\n\n";
        change_color_rgb(71, 255, 163);
        cout << ">  Select: ";
        reset_color();
        int num;
        cin >> num;
    }

    else if(menu1 == 3)
    {
        clear_screen();
        Title(players[playernum].point,players,playernum);
        if(playernum==0){cout << "You should first start a new game.";}
        else{
        cout << "Your name is now: ";
        change_color_rgb(134, 235, 252);
        cout << players[playernum].name << "." << endl;
        reset_color();
        cout << "Please Enter Your new name : ";
        namecheck(players,playernum);}
        char c=getch();
        if(c=='Q' || c=='q')
        {
            clear_screen();
            goto start;
        }
    }

    else if(menu1 == 4)
    {
        clear_screen();
        Title(players[playernum].point,players,playernum);
        change_color_rgb(255, 182, 79);
        cout << "\n-LeaderBoard-\n--> Top 5 Scores:\n";
        cout << "________________\n";
        cout << "----------------\n";
        reset_color();
        for(int i=1; i<11; i++)
        {
            Leaderboard[i].point=players[i].point;
            Leaderboard[i].name=players[i].name;
        }
        BubbleSort(Leaderboard);
        int tillhere;
            if(playernum>=5){tillhere=5;}
            else{tillhere=playernum;}
            for(int j=1; j<=tillhere; j++)
                cout << "--> " << j << ". " << Leaderboard[j].name << "\t" << Leaderboard[j].point << endl;
        char c=getch();
        if(c=='Q' || c=='q'){
                clear_screen();
                goto start;
        }
    }

    else if(menu1 == 5)
    {
        clear_screen();
        quit();
    }

    cout << "\npress esc to quit and Q to go to the home page.";
        char c=getch();
        if (c == 27){
        printf("\nSee you next time. BYE :) \n");
        delay(1000);
        quit();}
        else if(c=='Q' || c=='q')
        {
            clear_screen();
            goto start;
        }
}
