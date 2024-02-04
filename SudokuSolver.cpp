#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Board
{
private:
    unsigned int dimension; 
    char** spot;
    unsigned int w; //for print()
public:
    char& operator()(unsigned int i, unsigned int j){return spot[i-1][j-1];}
    void set_dimension(unsigned int i){dimension = i;}
    unsigned int get_dimension() {return dimension;}
    class InvalidInput : public exception{};
    Board();
    void print();
    bool no_zeros();
};

void Board::print()
{
    int d = sqrt(dimension);
    for (unsigned int i=0; i<dimension; i++)
    {
        for (unsigned int j=0; j<dimension; j++)
        {
            if (this->spot[i][j]!='0') cout<<setw(w)<<left<<this->spot[i][j]<<(j==(dimension-1) ? '\n' : ' ');
            else cout<<setw(w)<<left<<"-"<<(j==(dimension-1) ? '\n' : ' ');
            if (j!=0 && j!=dimension-1 && j%d==d-1) cout<<" ";
        }
        if(i!=0 && i!=dimension-1 && i%d==d-1) cout<<endl;
    }
}

bool Board::no_zeros()
{
    for (unsigned int i = 0; i<dimension; i++)
    {
        for (unsigned int j = 0; j<dimension; j++)
        {
            if(spot[i][j]=='0') return false;
        }
    }
    return true;
}

Board::Board()
{
    char choice;
    do
    {
        cout<<"Choose the dimension of the board:\n"<<"  A) 9\n  B) 16\n  C) 25\n >>> ";
        cin>>choice;
        switch(choice)
        {
            case 'A':
            case 'a':
            {
                dimension = 9;
                break;
            }
            case 'B':
            case 'b':
            {
                dimension = 16;
                break;
            }
            case 'C':
            case 'c':
            {
                dimension = 25;
                break;
            }
            default: cout<<"Invalid choice!"<<endl;
        }
    } while(choice!='A' && choice!='a' && choice!='B' && choice!='b' && choice!='C' && choice!='c');
    spot = new char*[dimension];
    for (unsigned int i=0; i<dimension; i++)
    {
        spot[i] = new char[dimension];
    }
    for (unsigned int i=0; i<dimension; i++)
    {
        for (unsigned int j=0; j<dimension; j++) {spot[i][j] = '0';}
    }
    if (dimension<10) w=1;
    else w=2;
    bool inputError;
    do
    {
        inputError = false;
        cout<<"Input the given markings (for blank spots input 0):"<<endl;
        for (unsigned int i=0; i<dimension; i++)
        {
            for(unsigned int j=0; j<dimension; j++)
            {
                try
                {
                    char in;
                    if(dimension==9)
                    {
                        cin>>in;
                        switch(in)
                        {
                        case '0': spot[i][j]='0'; break;
                        case '1': spot[i][j]='1'; break;
                        case '2': spot[i][j]='2'; break;
                        case '3': spot[i][j]='3'; break;
                        case '4': spot[i][j]='4'; break;
                        case '5': spot[i][j]='5'; break;
                        case '6': spot[i][j]='6'; break;
                        case '7': spot[i][j]='7'; break;
                        case '8': spot[i][j]='8'; break;
                        case '9': spot[i][j]='9'; break;
                        default: throw InvalidInput();
                        }
                    }
                    if(dimension==16)
                    {
                        cin>>in;
                        switch(in)
                        {
                        case '0': spot[i][j]='0'; break;
                        case '1': spot[i][j]='1'; break;
                        case '2': spot[i][j]='2'; break;
                        case '3': spot[i][j]='3'; break;
                        case '4': spot[i][j]='4'; break;
                        case '5': spot[i][j]='5'; break;
                        case '6': spot[i][j]='6'; break;
                        case '7': spot[i][j]='7'; break;
                        case '8': spot[i][j]='8'; break;
                        case '9': spot[i][j]='9'; break;
                        case 'a':
                        case 'A': spot[i][j]='A'; break;
                        case 'b':
                        case 'B': spot[i][j]='B'; break;
                        case 'c':
                        case 'C': spot[i][j]='C'; break;
                        case 'd':
                        case 'D': spot[i][j]='D'; break;
                        case 'e':
                        case 'E': spot[i][j]='E'; break;
                        case 'f':
                        case 'F': spot[i][j]='F'; break;
                        case 'g':
                        case 'G': spot[i][j]='G'; break;
                        default: throw InvalidInput();
                        }
                    }
                    if(dimension==25)
                    {
                        cin>>in;
                        switch(in)
                        {
                        case '0': spot[i][j]='0'; break;
                        case '1': spot[i][j]='1'; break;
                        case '2': spot[i][j]='2'; break;
                        case '3': spot[i][j]='3'; break;
                        case '4': spot[i][j]='4'; break;
                        case '5': spot[i][j]='5'; break;
                        case '6': spot[i][j]='6'; break;
                        case '7': spot[i][j]='7'; break;
                        case '8': spot[i][j]='8'; break;
                        case '9': spot[i][j]='9'; break;
                        case 'a':
                        case 'A': spot[i][j]='A'; break;
                        case 'b':
                        case 'B': spot[i][j]='B'; break;
                        case 'c':
                        case 'C': spot[i][j]='C'; break;
                        case 'd':
                        case 'D': spot[i][j]='D'; break;
                        case 'e':
                        case 'E': spot[i][j]='E'; break;
                        case 'f':
                        case 'F': spot[i][j]='F'; break;
                        case 'g':
                        case 'G': spot[i][j]='G'; break;
                        case 'h':
                        case 'H': spot[i][j]='H'; break;
                        case 'i':
                        case 'I': spot[i][j]='I'; break;
                        case 'j':
                        case 'J': spot[i][j]='J'; break;
                        case 'k':
                        case 'K': spot[i][j]='K'; break;
                        case 'l':
                        case 'L': spot[i][j]='L'; break;
                        case 'm':
                        case 'M': spot[i][j]='M'; break;
                        case 'n':
                        case 'N': spot[i][j]='N'; break;
                        case 'o':
                        case 'O': spot[i][j]='O'; break;
                        case 'p':
                        case 'P': spot[i][j]='P'; break;
                        default: throw InvalidInput();
                    }}}
                catch(InvalidInput)
                {
                    cerr<<"invalid input: try again"<<endl;
                    inputError = true;
                    continue;
                }
            }
            cin.sync();
        }
    } while(inputError);
    cout<<"board constructor with dimension "<<dimension<<" done"<<endl;
}

/*every blank spot is taken as a reference x,y at a time. then you check column, row and square for
every number. if there is only one number, that doesn't show up in any of the checks, the spot if filled with this number.
if no number is found, move on to the next blank spot.*/
bool check_row(Board b, unsigned int x, unsigned int y, char c) //checks columns for a specific number c
{
    for(unsigned int i=1; i<=b.get_dimension(); i++)
    {
        if (i==y) continue;
        else {if(b(x,i)==c) {/*cout<<"row "<<y<<" checked for "<<c<<endl; */return true;}}
    }
    /*cout<<"row "<<y<<" checked for "<<c<<endl;*/
    return false;
}
bool check_column(Board b, unsigned int x, unsigned int y, char c)
{
    for(unsigned int i=1; i<=b.get_dimension(); i++)
    {
        if (i==x) continue;
        else {if(b(i,y)==c) {/*cout<<"column "<<x<<" checked for "<<c<<endl; */return true;}}
    }
    /*cout<<"column "<<x<<" checked for "<<c<<endl;*/
    return false;
}
bool check_square(Board b, unsigned int x, unsigned int y, char c)
{
    switch(b.get_dimension())
    {
    case 9:
        {
            for (unsigned int a = x - (x-1)%3; a<x - (x-1)%3 + 3; a++)
            {
                for (unsigned int d = y - (y-1)%3; d<y - (y-1)%3 + 3; d++)
                {
                    if (x==a && y==d) continue;
                    else {if(b(a,d)==c) return true;}
                }
            }
            return false;
        }
    case 16:
        {
            for (unsigned int a = x - (x-1)%4; a<x - (x-1)%4 + 4; a++)
            {
                for (unsigned int d = y - (y-1)%4; d<y - (y-1)%4 + 4; d++)
                {
                    if (x==a && y==d) continue;
                    else {if(b(a,d)==c) return true;}
                }
            }
            return false;
        }
    case 25:
        {
            for (unsigned int a = x - (x-1)%5; a<x - (x-1)%5 + 5; a++)
            {
                for (unsigned int d = y - (y-1)%5; d<y - (y-1)%5 + 5; d++)
                {
                    if (x==a && y==d) continue;
                    else {if(b(a,d)==c) return true;}
                }
            }
            return false;
        }
    }
}

main()
{
    char markings[25] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    Board board;
    board.print();
    cout<<endl<<"START SOLVING..."<<endl<<endl;
    do
    {
        for (unsigned int i = 1; i<=board.get_dimension(); i++)
        {
            //cout<<"\nAnalysing row "<<i<<endl;
            for (unsigned int j = 1; j<=board.get_dimension(); j++)
            {
                if (board(i,j)=='0')
                {
                    //cout<<"checking ("<<i<<","<<j<<")..."<<endl;
                    unsigned int n = 0; char answer = '0';
                    for (unsigned int c=0; c<board.get_dimension(); c++)
                    {
                        if(!check_column(board, i, j, markings[c]) && !check_row(board, i, j, markings[c]) && !check_square(board, i, j, markings[c]))
                        {
                            n++;
                            answer = markings[c];
                        }
                    }
                    if (n==1)
                    {
                        board(i,j)=answer;
                        cout<<"("<<i<<","<<j<<") is "<<board(i,j)<<endl;
                    }
                    //cout<<"end of if(board(i,j)==0) statement"<<endl;
                }
                if (board.no_zeros()) break;
            }
            if (board.no_zeros()) break;
        }
       // cout<<"end of loop"<<endl;
    } while(!board.no_zeros());
    cout<<endl<<"SOLUTION:"<<endl;
    board.print();
    return 0;
}
