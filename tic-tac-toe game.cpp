#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int b[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int choose;
int valuei;
int valuej;
void print();
void player1();
void player2();
void detect();
int check[9]={0,0,0,0,0,0,0,0,0};
int count=0;
int turn;
void who();
void win();
bool over=false;
void play();
void menu();
bool ai;
void aihard();
void ai1();
bool done=false;
void ai2();
void ai3();
void ai4();
void ai5();
void ai4o();
void option();
bool bot=false;
void error();
void help();


void help() 
{
    int choice;
    cout << "             HELP            " << endl;
    cout << "-----------------------------" << endl;
    cout << "1. This is a Tic-Tac-Toe game for 2 players, or 1 player against a bot or AI." << endl;
    cout << "2. The board is represented as a 3x3 grid with numbers 1 to 9:" << endl;
    cout << "   1 | 2 | 3" << endl;
    cout << "  ---+---+---" << endl;
    cout << "   4 | 5 | 6" << endl;
    cout << "  ---+---+---" << endl;
    cout << "   7 | 8 | 9" << endl;
    cout << "3. Players take turns to choose a number representing a grid cell." << endl;
    cout << "4. Player 1 uses 'X', and Player 2 (or the bot/AI) uses 'O'." << endl;
    cout << "5. Game Modes:" << endl;
    cout << "   - 2 Player: Play against another human player." << endl;
    cout << "   - Bot: Play against a basic bot." << endl;
    cout << "   - AI: Play against a challenging AI opponent." << endl;
    cout << "6. Controls:" << endl;
    cout << "   - Enter the number of the cell you want to mark during your turn." << endl;
    cout << "   - If an invalid move is made (e.g., choosing an already occupied cell)," << endl;
    cout << "     you'll be prompted to try again." << endl;
    cout << "---------------------------------" << endl;
    cout << "     Good Luck! Have Fun! 😊   " << endl;
    cout << "   and be carefull with AI! 🤖"<<endl;
    cout << "---------------------------------" << endl;
    cout<<"press 1 to go back : ";
    cin>>choice;
    cout<<"-----------------------------"<<endl;
    if(choice==1)
        menu();
    else
        error();
}


void error()
{
    cout<<"error!"<<endl;
    cout<<"-----------------------------"<<endl;
    menu();
}

void option()
{
    int choice;
    count=0;
    for(int i=0; i<9; i++)
    {
        check[i]=0;
        for(int j=0; j<3; j++)
        {
            a[i][j]=0;
        }
    }
    over=false;
    done=false;
    bot=false;
    turn=1;
    cout<<"1. 2 player"<<endl;
    cout<<"2. bot"<<endl;
    cout<<"3. AI"<<endl;
    cout<<"choose : ";
    cin>>choice;
    cout<<"-----------------------------"<<endl;
    if(choice==1)
    {
        ai=false;
        play();
    }
    else if(choice==2)
    {
        bot=true;
        ai=true;
        play();
    }
    else if(choice == 3)
    {
        cout<<"🤖 : Dare you Win! 😈 "<<endl;
        cout<<"🤖 : lets begin! 😏"<<endl;
        cout<<"-----------------------------"<<endl;
        bot=false;
        ai=true;
        play();
    }
    else
        error();
}

void ai5()
{
    if(done==false)
    {
    do
    {
        choose=rand()%9 + 1;
        detect();
    }
    while(a[valuei][valuej] != 0);
    done=true;
    }
}

void ai4o()
{
    if(a[0][0]==0)
        {
            valuei=0;
            valuej=0;
            done=true;
            return;
        }
        if(a[0][2]==0)
        {
            valuei=0;
            valuej=2;
            done=true;
            return;
        }
        if(a[2][0]==0)
        {
            valuei=2;
            valuej=0;
            done=true;
            return;
        }
        if(a[2][2]==0)
        {
            valuei=2;
            valuej=2;
            done=true;
            return;
        }
}

void ai4()
{
    if(done==false)
    {
        if(a[1][1]==1)
        {
        if(a[0][0]==0)
        {
            valuei=0;
            valuej=0;
            done=true;
            return;
        }
        if(a[0][2]==0)
        {
            valuei=0;
            valuej=2;
            done=true;
            return;
        }
        if(a[2][0]==0)
        {
            valuei=2;
            valuej=0;
            done=true;
            return;
        }
        if(a[2][2]==0)
        {
            valuei=2;
            valuej=2;
            done=true;
            return;
        }
        }
        else
        {
            if(a[0][1]!=1&&a[2][1]==0)
            {
                valuei=2;
                valuej=1;
                done=true;
                return;
            }
            if(a[0][1]==0&&a[2][1]!=1)
            {
                valuei=0;
                valuej=1;
                done=true;
                return;
            }
            if(a[1][0]==0&&a[1][2]!=1)
            {
                valuei=1;
                valuej=0;
                done=true;
                return;
            }
            if(a[1][0]!=1&&a[1][2]==0)
            {
                valuei=1;
                valuej=2;
                done=true;
                return;
            }
            else
                ai4o();
        }
    }
}

void ai3()
{
    if(done==false)
    {
        if(a[1][1]==0)
        {
        if(a[0][1]==1 || a[1][0]==1 || a[1][2]==1 || a[2][1]==1 )
        {
            if(count==1)
            {
                return;
            }
        }
        else
        {
            valuei=1;
            valuej=1;
            done=true;
            return;
         
        }
        }
    }
}

void ai2()
{
    if(done==false)
    {
        for(int i=0; i<3; i++)
        {
            if(a[0][i]==1&&a[1][i]==1&&a[2][i]==0)
            {
                valuei=2;
                valuej=i;
                done=true;
                return;
            }
            if(a[0][i]==1&&a[1][i]==0&&a[2][i]==1)
            {
                valuei=1;
                valuej=i;
                done=true;
                return;
            }
            if(a[0][i]==0&&a[1][i]==1&&a[2][i]==1)
            {
                valuei=0;
                valuej=i;
                done=true;
                return;
            }
            //rows
            if(a[i][0]==1&&a[i][1]==1&&a[i][2]==0)
            {
                valuei=i;
                valuej=2;
                done=true;
                return;
            }
            if(a[i][0]==1&&a[i][1]==0&&a[i][2]==1)
            {
                valuei=i;
                valuej=1;
                done=true;
                return;
            }
            if(a[i][0]==0&&a[i][1]==1&&a[i][2]==1)
            {
                valuei=i;
                valuej=0;
                done=true;
                return;
            }
        }
        if(a[0][0]==1&&a[1][1]==1&&a[2][2]==0)
        {
            valuei=2;
            valuej=2;
            done=true;
            return;
        }
        if(a[0][0]==1&&a[1][1]==0&&a[2][2]==1)
        {
            valuei=1;
            valuej=1;
            done=true;
            return;
        }
        if(a[0][0]==0&&a[1][1]==1&&a[2][2]==1)
        {
            valuei=0;
            valuej=0;
            done=true;
            return;
        }
        ////////////////////////////
        if(a[0][2]==1&&a[1][1]==1&&a[2][0]==0)
        {
            valuei=2;
            valuej=0;
            done=true;
            return;
        }
        if(a[0][2]==1&&a[1][1]==0&&a[2][0]==1)
        {
            valuei=1;
            valuej=1;
            done=true;
            return;
        }
        if(a[0][2]==0&&a[1][1]==1&&a[2][0]==1)
        {
            valuei=0;
            valuej=2;
            done=true;
            return;
        }
    }
}

void ai1()
{
    if(done==false)
    {
        for(int i=0; i<3; i++)
        {
            if(a[0][i]==2&&a[1][i]==2&&a[2][i]==0)
            {
                valuei=2;
                valuej=i;
                done=true;
                return;
            }
            if(a[0][i]==2&&a[1][i]==0&&a[2][i]==2)
            {
                valuei=1;
                valuej=i;
                done=true;
                return;
            }
            if(a[0][i]==0&&a[1][i]==2&&a[2][i]==2)
            {
                valuei=0;
                valuej=i;
                done=true;
                return;
            }
            //rows
            if(a[i][0]==2&&a[i][1]==2&&a[i][2]==0)
            {
                valuei=i;
                valuej=2;
                done=true;
                return;
            }
            if(a[i][0]==2&&a[i][1]==0&&a[i][2]==2)
            {
                valuei=i;
                valuej=1;
                done=true;
                return;
            }
            if(a[i][0]==0&&a[i][1]==2&&a[i][2]==2)
            {
                valuei=i;
                valuej=0;
                done=true;
                return;
            }
        }
        if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
        {
            valuei=2;
            valuej=2;
            done=true;
            return;
        }
        if(a[0][0]==2&&a[1][1]==0&&a[2][2]==2)
        {
            valuei=1;
            valuej=1;
            done=true;
            return;
        }
        if(a[0][0]==0&&a[1][1]==2&&a[2][2]==2)
        {
            valuei=0;
            valuej=0;
            done=true;
            return;
        }
        ////////////////////////////
        if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
        {
            valuei=2;
            valuej=0;
            done=true;
            return;
        }
        if(a[0][2]==2&&a[1][1]==0&&a[2][0]==2)
        {
            valuei=1;
            valuej=1;
            done=true;
            return;
        }
        if(a[0][2]==0&&a[1][1]==2&&a[2][0]==2)
        {
            valuei=0;
            valuej=2;
            done=true;
            return;
        }
    }
}

void aihard()
{
    int choice;
    cout<<"-----------------------------"<<endl;
    if(bot==false)
        cout<<"🤖 AI's turn : "<<endl;
    else
        cout<<"Bot's turn : "<<endl;
//////////////////////
            done=false;
            if(bot==false)
            {
                ai1();
                ai2();
                ai3();
                ai4();
                ai5();
            }
            else
            {
                ai1();
                ai2();
                ai5();
            }
            cout<<"-----------------------------"<<endl;
            a[valuei][valuej]=2;
            choose=b[valuei][valuej];
            check[choose-1]=choose;
            count++;
            turn=1;
            print();
            win();
            if(!over)
                who();
            else
            {
                cout<<"-----------------------------"<<endl;
                cout<<"1. play again"<<endl;
                cout<<"2. menu"<<endl;
                cin>>choice;
                cout<<"-----------------------------"<<endl;
                if(choice==1)
                {
                    option();
                }
                else if(choice==2)
                {
                    menu();
                }
                else
                    error();
            }
}


void menu()
{
    int choice;
    cout<<"1. play"<<endl;
    cout<<"2. help"<<endl;
    cout<<"3. exit"<<endl;
    cin>>choice;
    cout<<"-----------------------------"<<endl;
    if(choice==1)
    {
        option();
    }
    else if(choice==2)
    {
        help();
    }
    else if(choice==3)
    {
        cout<<"thank you for playing the game"<<endl;
        cout<<"-----------------------------"<<endl;
    }
    else
        error();
    
}

void win()
{
    for(int i=0; i<3; i++)
    {
        if(a[0][i]==1&&a[1][i]==1&&a[2][i]==1 || a[i][0]==1&&a[i][1]==1&&a[i][2]==1)
        {
            cout<<"-----------------------------"<<endl;
            cout<<"player 1 wins"<<endl;
            over=true;
            break;
        }
        else if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1 || a[0][2]==1&&a[1][1]==1&&a[2][0]==1)
        {
            cout<<"-----------------------------"<<endl;
            cout<<"player 1 wins"<<endl;
            over=true;
            break;
        }
        else if(a[0][i]==2&&a[1][i]==2&&a[2][i]==2 || a[i][0]==2&&a[i][1]==2&&a[i][2]==2)
        {
            if(ai==true)
            {
                if(bot==true)
                {
                    cout<<"-----------------------------"<<endl;
                    cout<<"bot wins!"<<endl;
                }
                else
                {
                    cout<<"-----------------------------"<<endl;
                    cout<<"AI wins!😆 "<<endl;
                    cout<<"better luck next time! 🤡"<<endl;
                }
                over=true;
                break;
            }
            else
            {
                cout<<"-----------------------------"<<endl;
                cout<<"player 2 wins"<<endl;
            }
            over=true;
            break;
        }
        else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==2 || a[0][2]==2&&a[1][1]==2&&a[2][0]==2)
        {
            if(ai==true)
            {
                if(bot==true)
                {
                    cout<<"-----------------------------"<<endl;
                    cout<<"bot wins!"<<endl;
                }
                else
                {
                    cout<<"-----------------------------"<<endl;
                    cout<<"AI wins! 😎 "<<endl;
                    cout<<"better luck next time! 🥱"<<endl;
                }
                over=true;
                break;
            }
            else
            {
                cout<<"-----------------------------"<<endl;
                cout<<"player 2 wins"<<endl;
            }
            over=true;
            break;
        }
    }
}


void detect()
{
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if(b[i][j]==choose)
            {
                valuei=i;
                valuej=j;
            }
        }
    }
}

void player2()
{
    if(ai==false)
    {
    int choice;
    cout<<"-----------------------------"<<endl;
    cout<<"player 2 turn : ";
    cin>>choose;
        if(choose!=check[choose-1]&&choose>0&&choose<10)
        {
            detect();
            a[valuei][valuej]=2;
            cout<<"-----------------------------"<<endl;
            check[choose-1]=choose;
            count++;
            turn=1;
            print();
            win();
            if(!over)
                who();
            else
            {
                cout<<"-----------------------------"<<endl;
                cout<<"1. play again"<<endl;
                cout<<"2. menu"<<endl;
                cin>>choice;
                cout<<"-----------------------------"<<endl;
                if(choice==1)
                {
                    option();
                }
                else if(choice==2)
                {
                    menu();
                }
                else
                    error();
            }
            
        }
        else
        {
            cout<<"wrong answer "<<endl;
            player2();
        }
    }
    else if(ai==true)
    {
        aihard();
    }
    
}
/////////////////////////////////////////////////////////ai
void player1()
{
    int choice;
    cout<<"-----------------------------"<<endl;
    cout<<"player 1 turn : ";
    cin>>choose;
     if(choose!=check[choose-1]&&choose>0&&choose<10)
        {
            detect();
            a[valuei][valuej]=1;
            cout<<"-----------------------------"<<endl;
            check[choose-1]=choose;
            count++;
            turn=2;
            print();
            win();
            if(!over)
                who();
            else
            {
                cout<<"-----------------------------"<<endl;
                cout<<"1. play again"<<endl;
                cout<<"2. menu"<<endl;
                cin>>choice;
                cout<<"-----------------------------"<<endl;
                if(choice==1)
                {
                    option();
                }
                else if(choice==2)
                {
                    menu();
                }
                else
                    error();
            }
            
            
            
        }
        else
        {
            cout<<"wrong answer "<<endl;
            player1();
        }    
}

void print()
{
    cout<<" "<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i][j]==0)
            {
                cout<<" ";
            }
            else if(a[i][j]==1)
            {
                cout<<"X";
            }
            else if (a[i][j]==2)
            {
                cout<<"O";
            }
            if(j<2)
                cout<<"  ⋮  ";
        }
        cout<<endl;
        if(i<2)
            cout<<"············"<<endl;
    }
    cout<<" "<<endl;

}

void who()
{
    if(count<9)
    {
        if(turn==1)
        {
            player1();
        }
        else if(turn==2)
        {
            player2();
        }
    }
    else
    {
        int choice;
        cout<<"-----------------------------"<<endl;
        if(ai==true&&bot==false)
        {
            cout<<"draw!"<<endl;
            cout<<"🤖 : well played! 👏 "<<endl;
            cout<<"🤖 : but! luck doesn't tag along.🤭"<<endl;
        }
        else
        {
            cout<<"draw!"<<endl;
        }
        cout<<"-----------------------------"<<endl;
        cout<<"1. play again"<<endl;
        cout<<"2. menu"<<endl;
        cout<<"choice : ";
        cin>>choice;
        if(choice==1)
        {
            option();
        }
        else if(choice==2)
        {
            menu();
        }
    }
}

void play()
{
    print();
    turn=1;
    who();
}

int main() {
    srand(time(0));
    menu();
    return 0;
}
