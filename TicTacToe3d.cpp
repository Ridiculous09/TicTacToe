#include<iostream>
#include<curses.h>

using namespace std;

int c;

class board
{
        char l[3][3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',};
    public:
        int lno,rno,cno;
        bool cha=0;
        void show();
        void chance(int);
        void change(char);
        void chkwin();
}play;

void board::chance(int e)
{ 
  if(e%2==0)
  {
    change('x');
  }
  else
  {
    change('o');
  }
  chkwin();
}

void board::change(char d)
{
  re:
    cout<<"Enter layer no. : ";
    cin>>lno;
    cout<<"Enter row no. : ";
    cin>>rno;
    cout<<"Enter column no. : ";
    cin>>cno;
  if(l[lno-1][rno-1][cno-1]!='x'&l[lno-1][rno-1][cno-1]!='o')
  l[lno-1][rno-1][cno-1]=d;
  else
  goto re;
}

void board::show()
{
  cout<<"LAYER 1 :: \n\n";
  cout<<" "<<l[0][0][0]<<" "<<"|"<<" "<<l[0][0][1]<<" "<<"|"<<" "<<l[0][0][2];
  cout<<endl;
  cout<<"-----------";
  cout<<endl;
  cout<<" "<<l[0][1][0]<<" "<<"|"<<" "<<l[0][1][1]<<" "<<"|"<<" "<<l[0][1][2];
  cout<<endl;
  cout<<"-----------";
  cout<<endl;
  cout<<" "<<l[0][2][0]<<" "<<"|"<<" "<<l[0][2][1]<<" "<<"|"<<" "<<l[0][2][2];
  cout<<endl;
  cout<<"\n\n";

  cout<<"LAYER 2 :: \n\n";
  cout<<" "<<l[1][0][0]<<" "<<"|"<<" "<<l[1][0][1]<<" "<<"|"<<" "<<l[1][0][2];
  cout<<endl;
  cout<<"-----------";
  cout<<endl;
  cout<<" "<<l[1][1][0]<<" "<<"|"<<" "<<l[1][1][1]<<" "<<"|"<<" "<<l[1][1][2];
  cout<<endl;
  cout<<"-----------";
  cout<<endl;
  cout<<" "<<l[1][2][0]<<" "<<"|"<<" "<<l[1][2][1]<<" "<<"|"<<" "<<l[1][2][2];
  cout<<endl;
  cout<<"\n\n";

  cout<<"LAYER 3 :: \n\n";
  cout<<" "<<l[2][0][0]<<" "<<"|"<<" "<<l[2][0][1]<<" "<<"|"<<" "<<l[2][0][2];
  cout<<endl;
  cout<<"-----------";
  cout<<endl;
  cout<<" "<<l[2][1][0]<<" "<<"|"<<" "<<l[2][1][1]<<" "<<"|"<<" "<<l[2][1][2];
  cout<<endl;
  cout<<"-----------";
  cout<<endl;
  cout<<" "<<l[2][2][0]<<" "<<"|"<<" "<<l[2][2][1]<<" "<<"|"<<" "<<l[2][2][2];
  cout<<endl;
  cout<<"\n\n";
}

void board::chkwin()
{
  int l1,l2,l3;
  for(l1=0;l1<=3;l1++)
  {
    for(l2=0;l2<=3;l2++)
    {
      if(l[l1][l2][0]==l[l1][l2][1]&&l[l1][l2][1]==l[l1][l2][2])
      {
        if(l[l1][l2][0]=='x')
        {
            cout<<"X wins";
            getchar(); getchar();
            exit(0);
        }
        if(l[l1][l2][0]=='o')
        {
            cout<<"O wins";
            getchar(); getchar();
            exit(0);
        }
      }
    }
  }
  for(l1=0;l1<=3;l1++)
  {
    for(l2=0;l2<=3;l2++)
    {
      if(l[l1][0][l2]==l[l1][1][l2]&&l[l1][1][l2]==l[l1][2][l2])
      {
        if(l[l1][0][l2]=='x')
        {
            cout<<"X wins";
            getchar(); getchar();
            exit(0);
        }
        if(l[l1][0][l2]=='o')
        {
            cout<<"O wins";
            getchar(); getchar();
            exit(0);
        }
      }
    }
  }
  for(l1=0;l1<=3;l1++)
  {
    for(l2=0;l2<=3;l2++)
    {
        if(l[0][l1][l2]==l[1][l1][l2]&&l[1][l1][l2]==l[2][l1][l2])
        {
            if(l[0][l1][l2]=='x')
            {
            cout<<"X wins";
            getchar(); getchar();
            exit(0);
        }
        if(l[0][l1][l2]=='o')
        {
            cout<<"O wins";
            getchar(); getchar();
            exit(0);
        }
      }
    }
  }
  for(l1=0;l1<=3;l1++)
  {
    if(l[l1][0][0]==l[l1][1][1]&&l[l1][1][1]==l[l1][2][2])
    {
    if(l[l1][0][0]=='x')
    {
    cout<<"X wins";
    getchar(); getchar();
    exit(0);}
    if(l[l1][0][0]=='o')
    {cout<<"O wins";
    getchar(); getchar();
    exit(0);
    }
    }
    if(l[0][l1][0]==l[1][l1][1]&&l[1][l1][1]==l[2][l1][2])
    {
    if(l[0][l1][0]=='x')
    {
    cout<<"X wins";
    getchar(); getchar();
    exit(0);}
    if(l[0][l1][0]=='o')
    {cout<<"O wins";
    getchar(); getchar();
    exit(0);
    }
    }
    if(l[0][0][l1]==l[1][1][l1]&&l[1][1][l1]==l[2][2][l1])
    {
    if(l[0][0][l1]=='x')
    {
    cout<<"X wins";
    getchar(); getchar();
    exit(0);}
    if(l[0][0][l1]=='o')
    {cout<<"O wins";
    getchar(); getchar();
    exit(0);
    }
    }
  }
  if(l[0][0][0]==l[1][1][1]&&l[1][1][1]==l[2][2][2])
  {
  if(l[0][0][0]=='x')
  {
  cout<<"X wins";
  getchar(); getchar();
  exit(0);
  }
  if(l[0][0][0]=='o')
  {
  cout<<"O wins";
  getchar(); getchar();
  exit(0);
  }
  }
  if(l[0][0][2]==l[1][1][1]&&l[1][1][1]==l[2][2][0])
  {
  if(l[0][0][2]=='x')
  {
  cout<<"X wins";
  getchar(); getchar();
  exit(0);
  }
  if(l[0][0][2]=='o')
  {
  cout<<"O wins";
  getchar(); getchar();
  exit(0);
  }
  }
  if(l[0][2][2]==l[1][1][1]&&l[1][1][1]==l[2][0][0])
  {
  if(l[0][2][2]=='x')
  {
  cout<<"X wins";
  getchar(); getchar();
  exit(0);
  }
  if(l[0][2][2]=='o')
  {
  cout<<"O wins";
  getchar(); getchar();
  exit(0);
  }
  }
  if(l[0][2][0]==l[1][1][1]&&l[1][1][1]==l[2][0][2])
  {
          
 if(l[0][2][0]=='x')
  {
  cout<<"X wins";
  getchar(); getchar();
  exit(0);
  }

  if(l[0][2][0]=='o')
  {
  cout<<"O wins";
  getchar(); getchar();
  exit(0);
  }        
          
  }
}
int main()
{
     for(c=0;;c++)
     {
       play.show();
       play.chance(c);
       system("clear");
     }
}
