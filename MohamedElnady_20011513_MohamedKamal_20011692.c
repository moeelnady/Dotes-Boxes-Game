#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void print_grid(int n , int m ,int A[n][m] ,char name_1[],int scoure_1,int moves_1 ,char name_2[] , int scoure_2 ,int moves_2,int num_of_moves){
 int i , j;

    for(i=0;i<n;i++) /////print the grid
    {  printf("\t\t\t");
       for(j=0;j<m;j++)
       {  if(i%4==0&&j%4==0)
          {   SetColor(15);
              printf("%c",A[i][j]);}

          else{   SetColor(1);
                  printf("%c",A[i][j]);}
        }
                  printf("\n");
    }
      SetColor(5);
      printf("\n\tplayer1 name : %s\n",name_1);
      printf("\tMoves played by %s =%d\n",name_1,moves_1);
      SetColor(12);
      printf("\t\t\t\t\tplayer2 name : %s\n",name_2);
    printf("\n\t\t\t\t\tMoves played by %s =%d \n",name_2,moves_2);
      SetColor(5);
      printf("\n\t%s score : %d",name_1,scoure_1);
      SetColor(12);
      printf("\t\t\t%s score : %d",name_2,scoure_2);
      SetColor(25);
      printf("\n\n\n\t\t\t\t number of available moves :%d\n",num_of_moves);
      SetColor(15);
      printf("to  save the game enter points <40,40>\n");
      printf("to go to main menu enter <50,50>\n");

      }

int check_up_down(int point1_row ,int point1_col,int n,int m,int A[n][m]){
        int k=0;
        if(A[point1_row-4][point1_col+1]==205&&A[point1_row-1][point1_col]==186&&A[point1_row-1][point1_col+4]==186&&
           A[point1_row+4][point1_col+1]==205&&A[point1_row+1][point1_col]==186&&A[point1_row+1][point1_col+4]==186){k=1;}
           return k;
           }

int check_up(int point1_row ,int point1_col,int n,int m,int A[n][m]){
        int k=0;
        if(A[point1_row-4][point1_col+1]==205&&A[point1_row-1][point1_col]==186&&A[point1_row-1][point1_col+4]==186){k=1;}
           return k;
           }

int check_down(int point1_row ,int point1_col,int n,int m,int A[n][m]){
        int k=0;
        if(A[point1_row+4][point1_col+1]==205&&A[point1_row+1][point1_col]==186&&A[point1_row+1][point1_col+4]==186){k=1;}
           return k;
           }

int check_left_right(int point1_row ,int point1_col,int n,int m,int A[n][m]){
        int k=0;
        if(A[point1_row+1][point1_col+4]==186&&A[point1_row][point1_col+1]==205&&A[point1_row+4][point1_col+1]==205&&
           A[point1_row+1][point1_col-4]==186&&A[point1_row][point1_col-1]==205&A[point1_row+4][point1_col-1]==205){k=1;}
           return k;
           }

int check_right(int point1_row ,int point1_col,int n,int m,int A[n][m]){
    int k=0;
        if(A[point1_row+1][point1_col+4]==186&&A[point1_row][point1_col+1]==205&&A[point1_row+4][point1_col+1]==205){k=1;}
           return k;
           }

int check_left(int point1_row ,int point1_col,int n,int m,int A[n][m]){
    int k=0;
        if(A[point1_row+1][point1_col-4]==186&&A[point1_row][point1_col-1]==205&A[point1_row+4][point1_col-1]==205){k=1;}
           return k;
           }
           void save(int file, int n , int A[n][n],char  name1[],int score1 ,int moves_1, char name2[], int score2,int moves_2 ,int noOfmoves)
{ int i,j;
    FILE*SAVE;
if(file==1){
    SAVE=fopen("savedgame1.txt","w");}
   else if(file==2){
    SAVE=fopen("savedgame2.txt","w");}
   else if(file==3){
    SAVE=fopen("savedgame3.txt","w");}
    fprintf(SAVE,"%s\n",name1);
    fprintf(SAVE,"%d\n",score1);
    fprintf(SAVE,"%d\n",moves_1);
    fprintf(SAVE,"%s\n",name2);
    fprintf(SAVE,"%d\n",score2);
    fprintf(SAVE,"%d\n",moves_2);
    fprintf(SAVE,"%d\n",noOfmoves);
    for(i=0;i<9;i++) /////print the grid
    { for(j=0;j<9;j++)
       {  if(i%4==0&&j%4==0)
          {   SetColor(15);
              fprintf(SAVE,"%c",A[i][j]);}

          else{   SetColor(1);
                  fprintf(SAVE,"%c",A[i][j]);}
        }
                  fprintf(SAVE,"\n");
    }
    fclose(SAVE);
}
void Load(int file,int n,int A[n][n],char name1[],int score1,int moves_1,char name2[],int score2,int moves_2,int noofmoves)
{ int i ,j;
    FILE*SAVE;
    if(file==1){
    SAVE=fopen("savedgame1.txt","r");}
   else if(file==2){
    SAVE=fopen("savedgame2.txt","r");}
   else if(file==3){
    SAVE=fopen("savedgame3.txt","r");}
    fscanf(SAVE,"%s",name1);
    fscanf(SAVE,"%d",&score1);
    fscanf(SAVE,"%d",&moves_1);
    fscanf(SAVE,"%s",name2);
    fscanf(SAVE,"%d",&score2);
    fscanf(SAVE,"%d",&moves_2);
    fscanf(SAVE,"%d",&noofmoves);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(SAVE,"%c",&A[i][j]);
        }
    }
    fclose(SAVE);
}

int main () {


     int i,j,grid[9][9],grid2[21][21],point1,point2,score1=0,score2=0,compscore=0,moves_1=0,moves_2=0;
     int game_dif , game_mode,file;
char x=254;
Label1:
    system("cls");
    score1=0,score2=0,compscore=0,moves_1=0,moves_2=0;
    for(i=0;i<9;i++) ///////intializing grid2x2
    {
        for(j=0;j<9;j++)
        {
            if(i%4==0 &&j%4==0)
            {
                grid[i][j]=x;
            }
            else grid[i][j]=' ';
        }
    }

    for(i=0;i<21;i++)/////////intializing grid5x5
    {
        for(j=0;j<21;j++)
        {
            if(i%4==0 &&j%4==0)
            {
                grid2[i][j]=x;
            }
            else grid2[i][j]=' ';
        }
    }

SetColor(34);
    printf("\t\t\t WELCOME TO OUR GAME!! \n\n");
    printf("\t\t\t MAIN MENU \n\n");
    printf("for new game enter 1\n");
    printf("for load game enter 2\n");
    printf("for TOP 10 enter 3\n");
    printf("Quit game enter 4\n");
    printf("your choice :");
    int choice;
    char name1[25],name2[25],compname[15]="Computer";
    scanf("%d",&choice);
    system("cls");
    SetColor(9);
 if (choice==4)
    {
        return 0;
    }
    else if(choice==1)
    {
        printf("\n\n1-Beginer\n\n2-Expert\n");
        scanf("%d",&game_dif);
        system("cls");


        printf("1-One player\n\n2-Two players");
        scanf("%d",&game_mode);
        system("cls");

        if (game_mode==2){
        printf("\n\n Enter name of player1\n");
       scanf("%s",name1);
        printf("Enter name of player2 \n");
       scanf("%s",name2);}
        else {printf("\n\n Enter name of player1\n");
       scanf("%s",name1);}

    }

  system("cls");
  SetColor(15);

  ////grid 2x2
  if(game_dif==1 && game_mode==2){ /////////Beginnerand2players
      int nuOfmoves=12;
      print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
while(nuOfmoves>0)
{
    while(1) //////////////player one loop
    {if(nuOfmoves<=0)
    {
        break;
    }
         SetColor(5);
    printf("Player's one turn\n");
    SetColor(14);
    printf("enter 1st point:");
    scanf("%d",&point1);
    printf("enter 2nd point:");
    scanf("%d",&point2);
if((point1==1 &&point2==2)||(point1==2 &&point2==1))
        { if(grid[0][1]!= ' '){continue;}///check if played before

         else{grid[0][1]=205; grid[0][2]=205; grid[0][3]=205;
           if(check_down(0,0,9,9,grid)) /////checkthebox
           {  grid[2][2]=49;
              nuOfmoves--;
              moves_1++;
              score1++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
        }
        }
else if((point1==2 &&point2==3)||(point1==3&&point2==2))
    {   if(grid[0][6]!=' '){continue;}

        else{grid[0][5]=205; grid[0][6]=205; grid[0][7]=205;
         if(check_down(0,4,9,9,grid))
         {    grid[2][6]=49;
              nuOfmoves--;
              moves_1++;
              score1++;
              system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
       }
       }
else if((point1==4 &&point2==5)||(point1==5&&point2==4))
    {   if(grid[4][2]!=' '){continue;}

        else{grid[4][1]=205;grid[4][2]=205; grid[4][3]=205;
         if(check_up_down(4,0,9,9,grid))
         {    grid[2][2]=49; grid[6][2]=49;
              nuOfmoves--;
              moves_1++;
              score1=score1+2;
              system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

         else if(check_up(4,0,9,9,grid))
         {  grid[2][2]=49;
            nuOfmoves--;
            moves_1++;
            score1++;
            system("cls");
           print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_down(4,0,9,9,grid))
         {    grid[6][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==5 &&point2==6)||(point1==6&&point2==5))
     {  if(grid[4][6]!=' '){continue;}

       else{grid[4][5]=205; grid[4][6]=205; grid[4][7]=205;
        if(check_up_down(4,4,9,9,grid))
        {   grid[2][6]=49; grid[6][6]=49;
            nuOfmoves--;
            moves_1++;
            score1=score1+2;
            system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_up(4,4,9,9,grid))
        {   grid[2][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_down(4,4,9,9,grid))
        {   grid[6][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
         print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
       }
       }
else if((point1==7 &&point2==8)||(point1==8&&point2==7))
     {  if(grid[8][2]!=' '){continue;}

        else{grid[8][1]=205; grid[8][2]=205; grid[8][3]=205;
          if(check_up(8,0,9,9,grid))
          {  grid[6][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
           print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
      }
      }
else if((point1==8 &&point2==9)||(point1==9&&point2==8))
     {  if(grid[8][6]!=' '){continue;}
        else{grid[8][5]=205; grid[8][6]=205; grid[8][7]=205;
          if(check_up(8,4,9,9,grid))
          {   grid[6][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
      }
      }
else if((point1==1 &&point2==4)||(point1==4&&point2==1))
     {  if(grid[2][0]!=' '){continue;}
        else{grid[1][0]=186; grid[2][0]=186; grid[3][0]=186;
         if(check_right(0,0,9,9,grid))
         {    grid[2][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==2 &&point2==5)||(point1==5&&point2==2))
     {   if(grid[1][4]!=' '){continue;}
         else{grid[1][4]=186; grid[2][4]=186; grid[3][4]=186;///drawline
           if(check_left_right(0,4,9,9,grid))
           {    grid[2][2]=49; grid[2][6]=49;
                nuOfmoves--;
                score1=score1+2;
                moves_1++;
                system("cls");
                print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}

           else if(check_left(0,4,9,9,grid))
           {    grid[2][2]=49;
                nuOfmoves--;
                score1++;
                moves_1++;
                system("cls");
               print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}

           else if(check_right(0,4,9,9,grid))
           {    grid[2][6]=49;
                nuOfmoves--;
                score1++;
                moves_1++;
                system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}
    }
    }
else if ((point1==3 &&point2==6)||(point1==6 &&point2==3))
      {   if(grid[2][8]!=' '){continue;}
          else{grid[1][8]=186; grid[2][8]=186; grid[3][8]=186;
           if(check_left(0,8,9,9,grid))
           {    grid[2][6]=49;
                nuOfmoves--;
                score1++;
                moves_1++;
                system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}
      }
      }
else if((point1==4 &&point2==7)||(point1==7&&point2==4))
     {   if(grid[6][0]!=' '){continue;}
         else{grid[5][0]=186; grid[6][0]=186; grid[7][0]=186;
          if(check_right(4,0,9,9,grid))
          {   grid[6][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
     }
     }
else if ((point1==5 &&point2==8)||(point1==8&&point2==5))
     {    if(grid[6][4]!=' '){continue;}
          else{grid[5][4]=186; grid[6][4]=186; grid[7][4]=186;
            if(check_left_right(4,4,9,9,grid))
            {  grid[6][2]=49; grid[6][6]=49;
               nuOfmoves--;
               score1=score1+2;
               moves_1++;
               system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}

            else if(check_left(4,4,9,9,grid))
            {  grid[6][2]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}

            else if(check_right(4,4,9,9,grid))
            {  grid[6][6]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}
     }
     }
else if((point1==6 &&point2==9)||(point1==9&&point2==6))
     {  if(grid[6][8]!=' '){continue;}
        else{grid[5][8]=186; grid[6][8]=186; grid[7][8]=186;
          if(check_left(4,8,9,9,grid))
          {   grid[6][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
     }
     }
     else if(point1==40&&point2==40)
     {
         system("cls");
         SetColor(13);
         printf("choose one of the files 1 or 2 or 3");
         scanf("%d",&file);

        save(file,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
        continue;

     }
     else if(point1==50&&point2==50)
     {
         goto Label1;
     }
       else{  SetColor(6);
              printf("Invalid\n");
              continue;}

 nuOfmoves--;
 moves_1++;
 system("cls");
print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
 break;
 }


    while(2) /////////player 2 loop
    {if(nuOfmoves<=0)
    {
        break;
    }
    SetColor(12);
    printf("Player's two turn\n");
    SetColor(14);
    printf("enter 1st point:");
    scanf("%d",&point1);
    printf("enter 2nd point:");
    scanf("%d",&point2);
if((point1==1 &&point2==2)||(point1==2 &&point2==1))
        { if(grid[0][1]!= ' '){continue;}///check if played before

         else{grid[0][1]=205; grid[0][2]=205; grid[0][3]=205;
           if(check_down(0,0,9,9,grid)) /////checkthebox
           {  grid[2][2]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
        }
        }
else if((point1==2 &&point2==3)||(point1==3&&point2==2))
    {   if(grid[0][6]!=' '){continue;}

        else{grid[0][5]=205; grid[0][6]=205; grid[0][7]=205;
         if(check_down(0,4,9,9,grid))
         {    grid[2][6]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
        print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
       }
       }
else if((point1==4 &&point2==5)||(point1==5&&point2==4))
    {   if(grid[4][2]!=' '){continue;}

        else{grid[4][1]=205;grid[4][2]=205; grid[4][3]=205;
         if(check_up_down(4,0,9,9,grid))
         {    grid[2][2]=50; grid[6][2]=50;
              nuOfmoves--;
              score2=score2+2;
              moves_2++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

         else if(check_up(4,0,9,9,grid))
         {  grid[2][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
      print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_down(4,0,9,9,grid))
         {    grid[6][2]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
   print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==5 &&point2==6)||(point1==6&&point2==5))
     {  if(grid[4][6]!=' '){continue;}

       else{grid[4][5]=205; grid[4][6]=205; grid[4][7]=205;
        if(check_up_down(4,4,9,9,grid))
        {   grid[2][6]=50; grid[6][6]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
      print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_up(4,4,9,9,grid))
        {   grid[2][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
       print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_down(4,4,9,9,grid))
        {   grid[6][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
     print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
       }
       }
else if((point1==7 &&point2==8)||(point1==8&&point2==7))
     {  if(grid[8][2]!=' '){continue;}

        else{grid[8][1]=205; grid[8][2]=205; grid[8][3]=205;
          if(check_up(8,0,9,9,grid))
          {  grid[6][2]=50;
             nuOfmoves--;
             score2++;
             moves_2++;
             system("cls");
           print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
      }
      }
else if((point1==8 &&point2==9)||(point1==9&&point2==8))
     {  if(grid[8][6]!=' '){continue;}
        else{grid[8][5]=205; grid[8][6]=205; grid[8][7]=205;
          if(check_up(8,4,9,9,grid))
          {   grid[6][6]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
           print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
      }
      }
else if((point1==1 &&point2==4)||(point1==4&&point2==1))
     {  if(grid[2][0]!=' '){continue;}
        else{grid[1][0]=186; grid[2][0]=186; grid[3][0]=186;
         if(check_right(0,0,9,9,grid))
         {    grid[2][2]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==2 &&point2==5)||(point1==5&&point2==2))
     {   if(grid[1][4]!=' '){continue;}
         else{grid[1][4]=186; grid[2][4]=186; grid[3][4]=186;///drawline
           if(check_left_right(0,4,9,9,grid))
           {    grid[2][2]=50; grid[2][6]=50;
                nuOfmoves--;
                score2=score2+2;
                moves_2++;
                system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}

           else if(check_left(0,4,9,9,grid))
           {    grid[2][2]=50;
                nuOfmoves--;
                score2++;
                moves_2++;
                system("cls");
                print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}

           else if(check_right(0,4,9,9,grid))
           {    grid[2][6]=50;
                nuOfmoves--;
                score2++;
                moves_2++;
                system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}
    }
    }
else if ((point1==3 &&point2==6)||(point1==6 &&point2==3))
      {   if(grid[2][8]!=' '){continue;}
          else{grid[1][8]=186; grid[2][8]=186; grid[3][8]=186;
           if(check_left(0,8,9,9,grid))
           {    grid[2][6]=50;
                nuOfmoves--;
                score2++;
                moves_2++;
                system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                continue;}
      }
      }
else if((point1==4 &&point2==7)||(point1==7&&point2==4))
     {   if(grid[6][0]!=' '){continue;}
         else{grid[5][0]=186; grid[6][0]=186; grid[7][0]=186;
          if(check_right(4,0,9,9,grid))
          {   grid[6][2]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
    print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
     }
     }
else if ((point1==5 &&point2==8)||(point1==8&&point2==5))
     {    if(grid[6][4]!=' '){continue;}
          else{grid[5][4]=186; grid[6][4]=186; grid[7][4]=186;
            if(check_left_right(4,4,9,9,grid))
            {  grid[6][2]=50; grid[6][6]=50;
               nuOfmoves--;
               score2=score2+2;
               moves_2++;
               system("cls");
         print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}

            else if(check_left(4,4,9,9,grid))
            {  grid[6][2]=50;
               nuOfmoves--;
               score2++;
               moves_2++;
               system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}

            else if(check_right(4,4,9,9,grid))
            {  grid[6][6]=50;
               nuOfmoves--;
               score2++;
               moves_2++;
               system("cls");
           print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}
     }
     }
else if((point1==6 &&point2==9)||(point1==9&&point2==6))
     {  if(grid[6][8]!=' '){continue;}
        else{grid[5][8]=186; grid[6][8]=186; grid[7][8]=186;
          if(check_left(4,8,9,9,grid))
          {   grid[6][6]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
     }
     }
     else if(point1==40&&point2==40)
     {
         system("cls");
         SetColor(13);
         printf("choose one of the files 1 or 2 or 3");
         scanf("%d",&file);

        save(file,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
        continue;

     }
     else if(point1==50&&point2==50)
     {
         goto Label1;
     }
    else{  SetColor(6);
              printf("Invalid\n");
              continue;}

 nuOfmoves--;
 moves_2++;
 system("cls");
print_grid(9,9,grid,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
 break;
 }
}
SetColor(15);
printf("GAME ENDED\n");
if(score1>score2)
{
    SetColor(5);
    printf("congratulation %s is the winner\n",name1);
}
else if(score1<score2)
{
    SetColor(12);
    printf("congratulation %s is the winner\n",name2);
}
else {
    SetColor(11);
    printf("The game is draw\n");

}
SetColor(15);
int Z;
printf("enter 1 to return to main menu\n enter 2 to exit\n");
scanf("%d",&Z);
if(Z==1){ goto Label1;}
else{exit(0);}
}
else if(game_dif==1&&game_mode==1)//////////////////////////playervscomputergrid2x2
{ int nuOfmoves=12;
     print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
while(nuOfmoves>0)
{
    while(1) //////////////player one loop
    {if(nuOfmoves<=0)
    {
        break;
    }
    SetColor(5);
    printf("Player's one turn\n");
    SetColor(14);
    printf("enter 1st point:");
    scanf("%d",&point1);
    printf("enter 2nd point:");
    scanf("%d",&point2);
if((point1==1 &&point2==2)||(point1==2 &&point2==1))
        { if(grid[0][1]!= ' '){continue;}///check if played before

         else{grid[0][1]=205; grid[0][2]=205; grid[0][3]=205;
           if(check_down(0,0,9,9,grid)) /////checkthebox
           {  grid[2][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
        }
        }
else if((point1==2 &&point2==3)||(point1==3&&point2==2))
    {   if(grid[0][6]!=' '){continue;}

        else{grid[0][5]=205; grid[0][6]=205; grid[0][7]=205;
         if(check_down(0,4,9,9,grid))
         {    grid[2][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
       }
       }
else if((point1==4 &&point2==5)||(point1==5&&point2==4))
    {   if(grid[4][2]!=' '){continue;}

        else{grid[4][1]=205;grid[4][2]=205; grid[4][3]=205;
         if(check_up_down(4,0,9,9,grid))
         {    grid[2][2]=49; grid[6][2]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
              system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

         else if(check_up(4,0,9,9,grid))
         {  grid[2][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_down(4,0,9,9,grid))
         {    grid[6][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==5 &&point2==6)||(point1==6&&point2==5))
     {  if(grid[4][6]!=' '){continue;}

       else{grid[4][5]=205; grid[4][6]=205; grid[4][7]=205;
        if(check_up_down(4,4,9,9,grid))
        {   grid[2][6]=49; grid[6][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
      print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

        else if(check_up(4,4,9,9,grid))
        {   grid[2][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
        print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

        else if(check_down(4,4,9,9,grid))
        {   grid[6][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
        print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
       }
       }
else if((point1==7 &&point2==8)||(point1==8&&point2==7))
     {  if(grid[8][2]!=' '){continue;}

        else{grid[8][1]=205; grid[8][2]=205; grid[8][3]=205;
          if(check_up(8,0,9,9,grid))
          {  grid[6][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
    print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
      }
      }
else if((point1==8 &&point2==9)||(point1==9&&point2==8))
     {  if(grid[8][6]!=' '){continue;}
        else{grid[8][5]=205; grid[8][6]=205; grid[8][7]=205;
          if(check_up(8,4,9,9,grid))
          {   grid[6][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
       print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
      }
      }
else if((point1==1 &&point2==4)||(point1==4&&point2==1))
     {  if(grid[2][0]!=' '){continue;}
        else{grid[1][0]=186; grid[2][0]=186; grid[3][0]=186;
         if(check_right(0,0,9,9,grid))
         {    grid[2][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
       print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==2 &&point2==5)||(point1==5&&point2==2))
     {   if(grid[1][4]!=' '){continue;}
         else{grid[1][4]=186; grid[2][4]=186; grid[3][4]=186;///drawline
           if(check_left_right(0,4,9,9,grid))
           {    grid[2][2]=49; grid[2][6]=49;
                nuOfmoves--;
                score1=score1+2;
                moves_1++;
                system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}

           else if(check_left(0,4,9,9,grid))
           {    grid[2][2]=49;
                nuOfmoves--;
                score1++;
                moves_1++;
                system("cls");
          print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}

           else if(check_right(0,4,9,9,grid))
           {    grid[2][6]=49;
                nuOfmoves--;
                score1++;
                moves_1++;
                system("cls");
      print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}
    }
    }
else if ((point1==3 &&point2==6)||(point1==6 &&point2==3))
      {   if(grid[2][8]!=' '){continue;}
          else{grid[1][8]=186; grid[2][8]=186; grid[3][8]=186;
           if(check_left(0,8,9,9,grid))
           {    grid[2][6]=49;
                nuOfmoves--;
                score1++;
                moves_1++;
                system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}
      }
      }
else if((point1==4 &&point2==7)||(point1==7&&point2==4))
     {   if(grid[6][0]!=' '){continue;}
         else{grid[5][0]=186; grid[6][0]=186; grid[7][0]=186;
          if(check_right(4,0,9,9,grid))
          {   grid[6][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
   print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
     }
     }
else if ((point1==5 &&point2==8)||(point1==8&&point2==5))
     {    if(grid[6][4]!=' '){continue;}
          else{grid[5][4]=186; grid[6][4]=186; grid[7][4]=186;
            if(check_left_right(4,4,9,9,grid))
            {  grid[6][2]=49; grid[6][6]=49;
               nuOfmoves--;
               score1=score1+2;
               moves_1++;
               system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

            else if(check_left(4,4,9,9,grid))
            {  grid[6][2]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

            else if(check_right(4,4,9,9,grid))
            {  grid[6][6]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
           print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}
     }
     }
else if((point1==6 &&point2==9)||(point1==9&&point2==6))
     {  if(grid[6][8]!=' '){continue;}
        else{grid[5][8]=186; grid[6][8]=186; grid[7][8]=186;
          if(check_left(4,8,9,9,grid))
          {   grid[6][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
         print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
     }
     }
     else if(point1==40&&point2==40)
     {
         system("cls");
         SetColor(13);
         printf("choose one of the files 1 or 2 or 3");
         scanf("%d",&file);

        save(file,9,grid,name1,score1,moves_1,name2,compname,compscore,nuOfmoves);
        continue;

     }
     else if(point1==50&&point2==50)
     {
         goto Label1;
     }
       else{  SetColor(6);
              printf("Invalid\n");
              continue;}

 nuOfmoves--;
 moves_1++;
 system("cls");
  print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
 break;
 }


    while(2) /////////computer loop
    {if(nuOfmoves<=0)
    {
        break;
    }

if((grid[0][1]== ' ')&&(check_down(0,0,9,9,grid))){                 ///point 1,2
              grid[0][1]=205; grid[0][2]=205; grid[0][3]=205;
              grid[2][2]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
       print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[0][6]==' ')&&(check_down(0,4,9,9,grid))){             ///point 2,3
              grid[0][5]=205; grid[0][6]=205; grid[0][7]=205;
              grid[2][6]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[4][2]==' ')&&(check_up_down(4,0,9,9,grid))){        ///point 4,5
              grid[4][1]=205;grid[4][2]=205; grid[4][3]=205;
              grid[2][2]=50; grid[6][2]=50;
              nuOfmoves--;
              compscore=compscore+2;
              moves_2++;
              system("cls");
               print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[4][2]==' ')&&(check_up(4,0,9,9,grid))){             ///point 4,5
            grid[4][1]=205;grid[4][2]=205; grid[4][3]=205;
            grid[2][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid[4][2]==' ')&&(check_down(4,0,9,9,grid))){             ///point 4,5
              grid[4][1]=205;grid[4][2]=205; grid[4][3]=205;
              grid[6][2]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[4][6]==' ')&&(check_up_down(4,4,9,9,grid))){             ///point 5,6
            grid[4][5]=205; grid[4][6]=205; grid[4][7]=205;
            grid[2][6]=50; grid[6][6]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid[4][6]==' ')&&(check_up(4,4,9,9,grid))){             ///point 5,6
            grid[4][5]=205; grid[4][6]=205; grid[4][7]=205;
            grid[2][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid[4][6]==' ')&&(check_down(4,4,9,9,grid))){             ///point 5,6
           grid[4][5]=205; grid[4][6]=205; grid[4][7]=205;
            grid[6][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
             print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid[8][2]==' ')&&(check_up(8,0,9,9,grid))){           /// point 7,8
             grid[8][1]=205; grid[8][2]=205; grid[8][3]=205;
             grid[6][2]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
             system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid[8][6]==' ')&&(check_up(8,4,9,9,grid))){            ///point 8,9
              grid[8][5]=205; grid[8][6]=205; grid[8][7]=205;
              grid[6][6]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
               print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[2][0]==' ')&&(check_right(0,0,9,9,grid))){              /// point 1,4
              grid[1][0]=186; grid[2][0]=186; grid[3][0]=186;
              grid[2][2]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
               print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[1][4]==' ')&&(check_left_right(0,4,9,9,grid))){                    /// point 2,5
                grid[1][4]=186; grid[2][4]=186; grid[3][4]=186;
                grid[2][2]=50; grid[2][6]=50;
                nuOfmoves--;
                compscore=compscore+2;
                moves_2++;
                system("cls");
                 print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}

else if((grid[1][4]==' ')&&(check_left(0,4,9,9,grid))){                    /// point 2,5
                grid[1][4]=186; grid[2][4]=186; grid[3][4]=186;
                grid[2][2]=50;
                nuOfmoves--;
                compscore++;
                moves_2++;
                system("cls");
                print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}

else if((grid[1][4]==' ')&&(check_right(0,4,9,9,grid))){                    /// point 2,5
                grid[1][4]=186; grid[2][4]=186; grid[3][4]=186;
                grid[2][6]=50;
                nuOfmoves--;
                compscore++;
                moves_2++;
                system("cls");
                 print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}

else if((grid[2][8]==' ')&&(check_left(0,8,9,9,grid))){              /// point 3,6
                grid[1][8]=186; grid[2][8]=186; grid[3][8]=186;
                grid[2][6]=50;
                nuOfmoves--;
                compscore++;
                moves_2++;
                system("cls");
                 print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                continue;}

else if((grid[6][0]==' ')&&(check_right(4,0,9,9,grid))){              ///point 4,7
              grid[5][0]=186; grid[6][0]=186; grid[7][0]=186;
              grid[6][2]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid[6][4]==' ')&&(check_left_right(4,4,9,9,grid))){                     ///point 5,8
               grid[5][4]=186; grid[6][4]=186; grid[7][4]=186;
               grid[6][2]=50; grid[6][6]=50;
               nuOfmoves--;
               compscore=compscore+2;
               moves_2++;
               system("cls");
               print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid[6][4]==' ')&&(check_left(4,4,9,9,grid))){                     ///point 5,8
               grid[5][4]=186; grid[6][4]=186; grid[7][4]=186;
               grid[6][2]=50;
               nuOfmoves--;
               compscore++;
               moves_2++;
               system("cls");
               print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid[6][4]==' ')&&(check_right(4,4,9,9,grid))){                     ///point 5,8
               grid[5][4]=186; grid[6][4]=186; grid[7][4]=186;
               grid[6][6]=50;
               nuOfmoves--;
               compscore++;
               moves_2++;
               system("cls");
                print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid[6][8]==' ')&&(check_left(4,8,9,9,grid))){             ///point 6,9
              grid[5][8]=186; grid[6][8]=186; grid[7][8]=186;
              grid[6][6]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
              system("cls");
              print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if(grid[0][1]==' '){grid[0][1]=205;grid[0][2]=205;grid[0][3]=205;}  ///point 1,2

else if(grid[2][0]==' '){grid[1][0]=186;grid[2][0]=186;grid[3][0]=186;}  ///point 1,4

else if(grid[4][2]==' '){grid[4][1]=205;grid[4][2]=205;grid[4][3]=205;}  ///point 4,5

else if(grid[1][4]==' '){grid[1][4]=186;grid[2][4]=186;grid[3][4]=186;}  ///point 2,5

else if(grid[6][0]==' '){grid[5][0]=186;grid[6][0]=186;grid[7][0]=186;}  ///point 4,7

else if(grid[8][2]==' '){grid[8][1]=205;grid[8][2]=205;grid[8][3]=205;}  ///point 7,8

else if(grid[6][4]==' '){grid[5][4]=186;grid[6][4]=186;grid[7][4]=186;}  ///point 5,8

else if(grid[0][6]==' '){grid[0][5]=205;grid[0][6]=205;grid[0][7]=205;}  ///point 2,3

else if(grid[2][8]==' '){grid[1][8]=186;grid[2][8]=186;grid[3][8]=186;}  ///point 3,6

else if(grid[4][6]==' '){grid[4][5]=205;grid[4][6]=205;grid[4][7]=205;}  ///point 5,6

else if(grid[6][8]==' '){grid[5][8]=186;grid[6][8]=186;grid[7][8]=186;}  ///point 6,9

else if(grid[8][6]==' '){grid[8][5]=205;grid[8][6]=205;grid[8][7]=205;}  ///point 8,9

     else{  SetColor(6);
            printf("Invalid\n");
            continue;}

 nuOfmoves--;
 moves_2++;
 system("cls");
  print_grid(9,9,grid,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
 break;
 }

}
SetColor(15);
 printf("GAME HAS ENDED\n");
if(score1>compscore)
{
    SetColor(5);
    printf("congratulation %s is the winner\n",name1);
}
else if(score1<compscore)
{
    SetColor(12);
    printf("%s is the winner\n",compname);
}
else {
    SetColor(11);
    printf("The game is draw\n");

}
SetColor(15);
printf("enter 1 to return to main menu\n enter 2 to exit\n");
int M;
scanf("%d",&M);
if(M==1){ goto Label1;}
else{exit(0);}

}

///////////////////////////////////////////////////////////////////////////////////////////// grid5x5
  else if (game_dif==2 && game_mode==2){

   int nuOfmoves=60;
   print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);

while(nuOfmoves>0)
{
    while(1) //////////////player one loop
    { if(nuOfmoves<=0)
    {
        break;
    }
    SetColor(5);
    printf("Player's one turn\n");
    SetColor(14);
    printf("enter 1st point:");
    scanf("%d",&point1);
    printf("enter 2nd point:");
    scanf("%d",&point2);

if((point1==1 &&point2==2)||(point1==2 &&point2==1))
        { if(grid2[0][1]!= ' ') {continue;}
        else{grid2[0][1]=205; grid2[0][2]=205; grid2[0][3]=205;
           if(check_down(0,0,21,21,grid2))
           {  grid2[2][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                  continue;}
    }
    }
else if((point1==2 &&point2==3)||(point1==3&&point2==2))
    {   if(grid2[0][6]!=' '){continue;}
        else{grid2[0][5]=205; grid2[0][6]=205; grid2[0][7]=205;
         if(check_down(0,4,21,21,grid2))
         {    grid2[2][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==3 &&point2==4)||(point1==4&&point2==3))
    {   if(grid2[0][10]!=' '){continue;}
        else{grid2[0][9]=205; grid2[0][10]=205; grid2[0][11]=205;
         if(check_down(0,8,21,21,grid2))
         {    grid2[2][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==4 &&point2==5)||(point1==5&&point2==4))
    {   if(grid2[0][14]!=' '){continue;}
        else{ grid2[0][13]=205; grid2[0][14]=205; grid2[0][15]=205;
         if(check_down(0,12,21,21,grid2))
         {    grid2[2][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==5 &&point2==6)||(point1==6&&point2==5))
    {   if(grid2[0][18]!=' '){continue;}
        else{grid2[0][17]=205; grid2[0][18]=205; grid2[0][19]=205;
         if(check_down(0,16,21,21,grid2))
         {   grid2[2][18]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==7 &&point2==8)||(point1==8&&point2==7))
     {   if(grid2[4][2]!=' '){continue;}
     else{grid2[4][1]=205;grid2[4][2]=205; grid2[4][3]=205;
      if(check_up_down(4,0,21,21,grid2))
      {      grid2[2][2]=49; grid2[6][2]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

      else if(check_up(4,0,21,21,grid2))
      {     grid2[2][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

      else if(check_down(4,0,21,21,grid2))
      {     grid2[6][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==8 &&point2==9)||(point1==9&&point2==8))
     {  if(grid2[4][6]!=' '){continue;}
        else{grid2[4][5]=205; grid2[4][6]=205; grid2[4][7]=205;
         if(check_up_down(4,4,21,21,grid2))
         {  grid2[2][6]=49; grid2[6][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_up(4,4,21,21,grid2))
         {  grid2[2][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_down(4,4,21,21,grid2))
        {   grid[6][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==9 &&point2==10)||(point1==10&&point2==9))
     {  if(grid2[4][10]!=' '){continue;}
        else{grid2[4][9]=205;grid2[4][10]=205; grid2[4][11]=205;
          if(check_up_down(4,8,21,21,grid2))
          {  grid2[2][10]=49; grid2[6][10]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

          else if(check_up(4,8,21,21,grid2))
          {  grid2[2][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(4,8,21,21,grid2))
          {  grid2[6][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue; }
    }
    }
else if((point1==10 &&point2==11)||(point1==11&&point2==10))
     {  if(grid2[4][14]!=' '){continue;}
        else{grid2[4][13]=205;grid2[4][14]=205; grid2[4][15]=205;
         if(check_up_down(4,12,21,21,grid2))
         {  grid2[2][14]=49; grid2[6][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_up(4,12,21,21,grid2))
         {  grid2[2][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_down(4,12,21,21,grid2))
         {  grid2[6][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==11 &&point2==12)||(point1==12&&point2==11))
     {   if(grid2[4][18]!=' '){continue;}
         else{grid2[4][17]=205;grid2[4][18]=205; grid2[4][19]=205;
          if(check_up_down(4,16,21,21,grid2))
          {  grid2[2][18]=49; grid2[6][18]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else  if(check_up(4,16,21,21,grid2))
          {  grid2[2][18]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else  if(check_down(4,16,21,21,grid2))
          {  grid2[6][18]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==13 &&point2==14)||(point1==14&&point2==13))
     {   if(grid2[8][2]!=' '){continue;}
         else{grid2[8][1]=205;grid2[8][2]=205; grid2[8][3]=205;
          if(check_up_down(8,0,21,21,grid2))
          {  grid2[6][2]=49; grid2[10][2]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}


          else if(check_up(8,0,21,21,grid2))
          {  grid2[6][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(8,0,21,21,grid2))
          {  grid2[10][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==14 &&point2==15)||(point1==15&&point2==14))
     {   if(grid2[8][6]!=' '){continue;}
         else{grid2[8][5]=205;grid2[8][6]=205; grid2[8][7]=205;
          if(check_up_down(8,4,21,21,grid2))
          {  grid2[6][6]=49; grid2[10][6]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_up(8,4,21,21,grid2))
          {  grid2[6][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

         else if(check_down(8,4,21,21,grid2))
         {   grid2[10][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==15 &&point2==16)||(point1==16&&point2==15))
     {   if(grid2[8][10]!=' '){continue;}
         else{grid2[8][9]=205;grid2[8][10]=205; grid2[8][11]=205;
         if(check_up_down(8,8,21,21,grid2))
         {  grid2[6][10]=49; grid2[10][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}


         else if(check_up(8,8,21,21,grid2))
         {   grid2[6][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

        else if(check_down(8,8,21,21,grid2))
        {   grid2[10][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==16 &&point2==17)||(point1==17&&point2==16))
     {   if(grid2[8][14]!=' '){continue;}
         else{grid2[8][13]=205;grid2[8][14]=205; grid2[8][15]=205;
           if(check_up_down(8,12,21,21,grid2))
           {   grid2[6][14]=49; grid2[10][14]=49;
               nuOfmoves--;
               score1=score1+2;
               moves_1++;
               system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}

          else if(check_up(8,12,21,21,grid2))
          {   grid2[6][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

          else if(check_down(8,12,21,21,grid2))
          {   grid2[10][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==17 &&point2==18)||(point1==18&&point2==17))
     {   if(grid2[8][18]!=' '){continue;}
         else{grid2[8][17]=205;grid2[8][18]=205; grid2[8][19]=205;
           if(check_up_down(8,16,21,21,grid2))
           {  grid2[6][18]=49; grid2[10][18]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
              system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(8,16,21,21,grid2))
           {  grid2[6][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

           else if(check_down(8,16,21,21,grid2))
           {  grid2[10][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==19 &&point2==20)||(point1==20&&point2==19))
     {   if(grid2[12][2]!=' '){continue;}
         else{grid2[12][1]=205;grid2[12][2]=205; grid2[12][3]=205;
          if(check_up_down(12,0,21,21,grid2))
          {  grid2[10][2]=49; grid2[14][2]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

          else if(check_up(12,0,21,21,grid2))
          {  grid2[10][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(12,0,21,21,grid2))
          {  grid2[14][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==20 &&point2==21)||(point1==21&&point2==20))
    {   if(grid2[12][6]!=' '){continue;}
        else{grid2[12][5]=205;grid2[12][6]=205; grid2[12][7]=205;
      if(check_up_down(12,4,21,21,grid2))
      {  grid2[10][6]=49; grid2[14][6]=49;
         nuOfmoves--;
         score1=score1+2;
         moves_1++;
         system("cls");
        print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
         continue;}

      else if(check_up(12,4,21,21,grid2))
      {  grid2[10][6]=49;
         nuOfmoves--;
         score1++;
         moves_1++;
         system("cls");
         print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
         continue;}

      else if(check_down(12,4,21,21,grid2))
      {   grid2[14][6]=49;
          nuOfmoves--;
          score1++;
          moves_1++;
          system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==21 &&point2==22)||(point1==22&&point2==21))
     {   if(grid2[12][10]!=' '){continue;}
         else{grid2[12][9]=205;grid2[12][10]=205; grid2[12][11]=205;
          if(check_up_down(12,8,21,21,grid2))
          {  grid2[10][10]=49; grid2[14][10]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_up(12,8,21,21,grid2))
          {  grid2[10][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(12,8,21,21,grid2))
          {  grid2[14][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==22 &&point2==23)||(point1==23&&point2==22))
     {   if(grid2[12][14]!=' '){continue;}
         else{grid2[12][13]=205;grid2[12][14]=205; grid2[12][15]=205;
          if(check_up_down(12,12,21,21,grid2))
          {  grid2[10][14]=49; grid2[14][14]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_up(12,12,21,21,grid2))
          { grid2[10][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else  if(check_down(12,12,21,21,grid2))
         {  grid2[14][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==23 &&point2==24)||(point1==24&&point2==23))
     {   if(grid2[12][18]!=' '){continue;}
         else{grid2[12][17]=205;grid2[12][18]=205; grid2[12][19]=205;
         if(check_up_down(12,16,21,21,grid2))
         { grid2[10][18]=49; grid2[14][18]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_up(12,16,21,21,grid2))
        {  grid2[10][18]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

       else if(check_down(12,16,21,21,grid2))
       {  grid2[14][18]=49;
          nuOfmoves--;
          score1++;
          moves_1++;
          system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==25 &&point2==26)||(point1==26&&point2==25))
     {   if(grid2[16][2]!=' '){continue;}
         else{grid2[16][1]=205;grid2[16][2]=205; grid2[16][3]=205;
          if(check_up_down(16,0,21,21,grid2))
          { grid2[14][2]=49; grid2[18][2]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

          else if(check_up(16,0,21,21,grid2))
          {  grid2[14][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

         else if(check_down(16,0,21,21,grid2))
         {  grid2[18][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==26 &&point2==27)||(point1==27&&point2==26))
     {   if(grid2[16][6]!=' '){continue;}
         else{grid2[16][5]=205;grid2[16][6]=205; grid2[16][7]=205;
          if(check_up_down(16,4,21,21,grid2))
          {  grid2[14][6]=49; grid2[18][6]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}


          else if(check_up(16,4,21,21,grid2))
          {  grid2[14][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(16,4,21,21,grid2))
          {  grid2[18][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==27 &&point2==28)||(point1==28&&point2==27))
     {   if(grid2[16][10]!=' '){continue;}
         else{grid2[16][9]=205;grid2[16][10]=205; grid2[16][11]=205;
           if(check_up_down(16,8,21,21,grid2))
           {  grid2[14][10]=49; grid2[18][10]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,8,21,21,grid2))
           {  grid2[14][10]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,8,21,21,grid2))
            {  grid2[18][10]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==28 &&point2==29)||(point1==29&&point2==28))
     {   if(grid2[16][14]!=' '){continue;}
         else{grid2[16][13]=205;grid2[16][14]=205; grid2[16][15]=205;
           if(check_up_down(16,12,21,21,grid2))
           {  grid2[14][14]=49; grid2[18][14]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,12,21,21,grid2))
           {  grid2[14][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,12,21,21,grid2))
           {  grid2[18][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
                 print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==29 &&point2==30)||(point1==30&&point2==29))
     {   if(grid2[16][18]!=' '){continue;}
         else{grid2[16][17]=205;grid2[16][18]=205; grid2[16][19]=205;
           if(check_up_down(16,16,21,21,grid2))
           {  grid2[14][18]=49; grid2[18][18]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
              system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,16,21,21,grid2))
           {  grid2[14][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,16,21,21,grid2))
           {  grid2[18][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==31 &&point2==32)||(point1==32&&point2==31))
     {   if(grid2[20][2]!=' '){continue;}
         else{ grid2[20][1]=205; grid2[20][2]=205; grid2[20][3]=205;
          if(check_up(20,0,21,21,grid2))
          {  grid2[18][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==32 &&point2==33)||(point1==33&&point2==32))
     {   if(grid2[20][6]!=' '){continue;}
         else{ grid2[20][5]=205; grid2[20][6]=205; grid2[20][7]=205;
           if(check_up(20,4,21,21,grid2))
           {  grid2[18][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==33 &&point2==34)||(point1==34&&point2==33))
     {   if(grid2[20][10]!=' '){continue;}
         else{ grid2[20][9]=205; grid2[20][10]=205; grid2[20][11]=205;
            if(check_up(20,8,21,21,grid2))
            {  grid2[18][10]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==34 &&point2==35)||(point1==35&&point2==34))
     {   if(grid2[20][14]!=' '){continue;}
         else{ grid2[20][13]=205; grid2[20][14]=205; grid2[20][15]=205;
           if(check_up(20,12,21,21,grid2))
           {  grid2[18][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==35 &&point2==36)||(point1==36&&point2==35))
     {   if(grid2[20][18]!=' '){continue;}
         else{ grid2[20][17]=205; grid2[20][18]=205; grid2[20][19]=205;
            if(check_up(20,16,21,21,grid2))
            {  grid2[18][18]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
               system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==1 &&point2==7)||(point1==7&&point2==1))
     { if(grid2[2][0]!=' '){continue;}
       else{grid2[1][0]=186; grid2[2][0]=186; grid2[3][0]=186;
         if(check_right(0,0,21,21,grid2))
         {  grid2[2][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                  continue;}
    }
    }
else if((point1==7 &&point2==13)||(point1==13&&point2==7))
     { if(grid2[6][0]!=' '){continue;}
       else{grid2[5][0]=186; grid2[6][0]=186; grid2[7][0]=186;
         if(check_right(4,0,21,21,grid2))
         {  grid2[6][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==13 &&point2==19)||(point1==19&&point2==13))
     { if(grid2[10][0]!=' '){continue;}
       else{grid2[9][0]=186; grid2[10][0]=186; grid2[11][0]=186;
         if(check_right(8,0,21,21,grid2))
         {  grid2[10][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==19 &&point2==25)||(point1==25&&point2==19))
     { if(grid2[14][0]!=' '){continue;}
       else{grid2[13][0]=186; grid2[14][0]=186; grid2[15][0]=186;
         if(check_right(12,0,21,21,grid2))
         {  grid2[14][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==25 &&point2==31)||(point1==31&&point2==25))
     { if(grid2[18][0]!=' '){continue;}
       else{grid2[17][0]=186; grid2[18][0]=186; grid2[19][0]=186;
         if(check_right(16,0,21,21,grid2))
         {  grid2[18][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==2 &&point2==8)||(point1==8&&point2==2))
     { if(grid2[1][4]!=' '){continue;}
       else{grid2[1][4]=186; grid2[2][4]=186; grid2[3][4]=186;///drawline
         if(check_left_right(0,4,21,21,grid2))
         {  grid2[2][2]=49; grid2[2][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else  if(check_left(0,4,21,21,grid2))
        {  grid2[2][2]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(0,4,21,21,grid2))
        {  grid[2][6]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }

else if((point1==8 &&point2==14)||(point1==14&&point2==8))
     { if(grid2[6][4]!=' '){continue;}
       else{grid2[5][4]=186; grid2[6][4]=186; grid2[7][4]=186;///drawline
          if(check_left_right(4,4,21,21,grid2))
          {  grid2[6][2]=49; grid2[6][6]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_left(4,4,21,21,grid2))
          {  grid2[6][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_right(4,4,21,21,grid2))
          {  grid2[6][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==14 &&point2==20)||(point1==20&&point2==14))
     { if(grid2[10][4]!=' '){continue;}
       else{grid2[9][4]=186; grid2[10][4]=186; grid2[11][4]=186;///drawline
        if(check_left_right(8,4,21,21,grid2))
        {  grid2[10][2]=49; grid2[10][6]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
           system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}

        else if(check_left(8,4,21,21,grid2))
        {  grid2[10][2]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
         print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(8,4,21,21,grid2))
        {  grid2[10][6]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==20 &&point2==26)||(point1==26&&point2==20))
     { if(grid2[14][4]!=' '){continue;}
       else{grid2[13][4]=186; grid2[14][4]=186; grid2[15][4]=186;///drawline
         if(check_left_right(12,4,21,21,grid2))
         {  grid2[14][2]=49; grid2[14][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,4,21,21,grid2))
         {  grid2[14][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(12,4,21,21,grid2))
         {  grid2[14][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==26&&point2==32)||(point1==32&&point2==26))
     { if(grid2[18][4]!=' '){continue;}
       else{grid2[17][4]=186; grid2[18][4]=186; grid2[19][4]=186;///drawline
         if(check_left_right(16,4,21,21,grid2))
         {  grid2[18][2]=49; grid2[18][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,4,21,21,grid2))
         {  grid2[18][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,4,21,21,grid2))
         {  grid2[18][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==3&&point2==9)||(point1==9&&point2==3))
     { if(grid2[2][8]!=' '){continue;}
       else{grid2[1][8]=186; grid2[2][8]=186; grid2[3][8]=186;///drawline
         if(check_left_right(0,8,21,21,grid2))
         {  grid2[2][6]=49; grid2[2][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,8,21,21,grid2))
         {  grid2[2][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,8,21,21,grid2))
         {  grid2[2][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==9&&point2==15)||(point1==15&&point2==9))
     { if(grid2[6][8]!=' '){continue;}
       else{grid2[5][8]=186; grid2[6][8]=186; grid2[7][8]=186;///drawline
         if(check_left_right(4,8,21,21,grid2))
         {  grid2[6][6]=49; grid2[6][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(4,8,21,21,grid2))
         {  grid2[6][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(4,8,21,21,grid2))
        {  grid2[6][10]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==15&&point2==21)||(point1==21&&point2==15))
     { if(grid2[10][8]!=' '){continue;}
       else{grid2[9][8]=186; grid2[10][8]=186; grid2[11][8]=186;///drawline
         if(check_left_right(8,8,21,21,grid2))
         {  grid2[10][6]=49; grid2[10][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(8,8,21,21,grid2))
         {  grid2[10][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(8,8,21,21,grid2))
         {  grid2[10][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==21&&point2==27)||(point1==27&&point2==21))
     { if(grid2[14][8]!=' '){continue;}
       else{grid2[13][8]=186; grid2[14][8]=186; grid2[15][8]=186;///drawline
        if(check_left_right(12,8,21,21,grid2))
        {  grid2[14][6]=49; grid2[14][10]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(12,8,21,21,grid2))
        {  grid2[14][6]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else  if(check_right(12,8,21,21,grid2))
        {  grid2[14][10]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==27&&point2==33)||(point1==33&&point2==27))
     { if(grid2[18][8]!=' '){continue;}
       else{grid2[17][8]=186; grid2[18][8]=186; grid2[19][8]=186;///drawline
         if(check_left_right(16,8,21,21,grid2))
         {  grid2[18][6]=49; grid2[18][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,8,21,21,grid2))
         {  grid2[18][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,8,21,21,grid2))
         {  grid2[18][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==4&&point2==10)||(point1==10&&point2==4))
     { if(grid2[2][12]!=' '){continue;}
       else{grid2[1][12]=186; grid2[2][12]=186; grid2[3][12]=186;///drawline
         if(check_left_right(0,12,21,21,grid2))
         {  grid2[2][10]=49; grid2[2][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,12,21,21,grid2))
         {  grid2[2][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,12,21,21,grid2))
         {  grid2[2][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==10&&point2==16)||(point1==16&&point2==10))
     { if(grid2[6][12]!=' '){continue;}
       else{grid2[5][12]=186; grid2[6][12]=186; grid2[7][12]=186;///drawline
         if(check_left_right(4,12,21,21,grid2))
         {  grid2[6][10]=49; grid2[6][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(4,12,21,21,grid2))
         {  grid2[6][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(4,12,21,21,grid2))
         {  grid2[6][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==16&&point2==22)||(point1==22&&point2==16))
     { if(grid2[10][12]!=' '){continue;}
       else{grid2[9][12]=186; grid2[10][12]=186; grid2[11][12]=186;///drawline
        if(check_left_right(8,12,21,21,grid2))
        {  grid2[10][10]=49; grid2[10][14]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(8,12,21,21,grid2))
        {  grid2[10][10]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else  if(check_right(8,12,21,21,grid2))
        {  grid2[10][14]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==22&&point2==28)||(point1==28&&point2==22))
     { if(grid2[14][12]!=' '){continue;}
       else{grid2[13][12]=186; grid2[14][12]=186; grid2[15][12]=186;///drawline
         if(check_left_right(12,12,21,21,grid2))
         {  grid2[14][10]=49; grid2[14][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,12,21,21,grid2))
         {  grid2[14][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_right(12,12,21,21,grid2))
        {  grid2[14][14]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==28&&point2==34)||(point1==34&&point2==28))
     { if(grid2[18][12]!=' '){continue;}
       else{grid2[17][12]=186; grid2[18][12]=186; grid2[19][12]=186;///drawline
         if(check_left_right(16,12,21,21,grid2))
         {  grid2[18][10]=49; grid2[18][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,12,21,21,grid2))
         {  grid2[18][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,12,21,21,grid2))
         {  grid2[18][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==5&&point2==11)||(point1==11&&point2==5))
     { if(grid2[2][16]!=' '){continue;}
       else{grid2[1][16]=186; grid2[2][16]=186; grid2[3][16]=186;///drawline
         if(check_left_right(0,16,21,21,grid2))
         {  grid2[2][14]=49; grid2[2][18]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,16,21,21,grid2))
         {  grid2[2][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,16,21,21,grid2))
         {  grid2[2][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==11&&point2==17)||(point1==17&&point2==11))
     { if(grid2[6][16]!=' '){continue;}
       else{grid2[5][16]=186; grid2[6][16]=186; grid2[7][16]=186;///drawline
        if(check_left_right(4,16,21,21,grid2))
        {  grid2[6][14]=49; grid2[6][18]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(4,16,21,21,grid2))
        {  grid2[6][14]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(4,16,21,21,grid2))
        {  grid2[6][18]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==17&&point2==23)||(point1==23&&point2==17))
     { if(grid2[10][16]!=' '){continue;}
       else{grid2[9][16]=186; grid2[10][16]=186; grid2[11][16]=186;///drawline
         if(check_left_right(8,16,21,21,grid2))
         {  grid2[10][14]=49; grid2[10][18]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(8,16,21,21,grid2))
         {  grid2[10][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(8,16,21,21,grid2))
         {  grid2[10][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==23&&point2==29)||(point1==29&&point2==23))
     { if(grid2[14][16]!=' '){continue;}
       else{grid2[13][16]=186; grid2[14][16]=186; grid2[15][16]=186;///drawline
         if(check_left_right(12,16,21,21,grid2))
         {  grid2[14][14]=49; grid2[14][18]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,16,21,21,grid2))
         {  grid2[14][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(12,16,21,21,grid2))
         {  grid2[14][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==29 && point2==35)||(point1==35 && point2==29))
     { if(grid2[18][16]!=' '){continue;}
       else{grid2[17][16]=186; grid2[18][16]=186; grid2[19][16]=186;///drawline
        if(check_left_right(16,16,21,21,grid2))
        {  grid2[18][14]=49; grid2[18][18]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(16,16,21,21,grid2))
        {  grid2[18][14]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(16,16,21,21,grid2))
        {  grid2[18][18]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
           system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==6 &&point2==12)||(point1==12&&point2==6))
     { if(grid2[2][20]!=' '){continue;}
       else{grid2[1][20]=186; grid2[2][20]=186; grid2[3][20]=186;
         if(check_left(0,20,21,21,grid2))
         {  grid2[2][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==12 &&point2==18)||(point1==18&&point2==12))
     { if(grid2[6][20]!=' '){continue;}
       else{grid2[5][20]=186; grid2[6][20]=186; grid2[7][20]=186;
         if(check_left(4,20,21,21,grid2))
         {  grid2[6][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
          print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==18 &&point2==24)||(point1==24&&point2==18))
     { if(grid2[10][20]!=' '){continue;}
       else{grid2[9][20]=186; grid2[10][20]=186; grid2[11][20]=186;
         if(check_left(8,20,21,21,grid2))
         {  grid2[10][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==24 &&point2==30)||(point1==30&&point2==24))
     { if(grid2[14][20]!=' '){continue;}
       else{grid2[13][20]=186; grid2[14][20]=186; grid2[15][20]=186;
         if(check_left(12,20,21,21,grid2))
         {  grid2[14][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==30 &&point2==36)||(point1==36&&point2==30))
     { if(grid2[18][20]!=' '){continue;}
       else{grid2[17][20]=186; grid2[18][20]=186; grid2[19][20]=186;
         if(check_left(16,20,21,21,grid2))
         {  grid2[18][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                  continue;}
    }
    }
    else if(point1==40&&point2==40)
     {
         system("cls");
         SetColor(13);
         printf("choose one of the files 1 or 2 or 3");
         scanf("%d",&file);

        save(file,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
        continue;

     }
     else if(point1==50&&point2==50)
     {
         goto Label1;
     }
else{
         SetColor(6);
         printf("Invalid\n");
         continue;
    }
         nuOfmoves--;
         moves_1++;
         system("cls");
         print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
         break;
    }
    while(2) ///////////////////////////////////////////////////////////////////////player 2 loop
    { if(nuOfmoves<=0)
    {
        break;
    }
    SetColor(5);
    printf("Player's two turn\n");
    SetColor(14);
    printf("enter 1st point:");
    scanf("%d",&point1);
    printf("enter 2nd point:");
    scanf("%d",&point2);
if((point1==1 &&point2==2)||(point1==2 &&point2==1))
        { if(grid2[0][1]!= ' ') {continue;}
        else{grid2[0][1]=205; grid2[0][2]=205; grid2[0][3]=205;
           if(check_down(0,0,21,21,grid2))
           {  grid2[2][2]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                  continue;}
    }
    }
else if((point1==2 &&point2==3)||(point1==3&&point2==2))
    {   if(grid2[0][6]!=' '){continue;}
        else{grid2[0][5]=205; grid2[0][6]=205; grid2[0][7]=205;
         if(check_down(0,4,21,21,grid2))
         {    grid2[2][6]=50;
             nuOfmoves--;
             score2++;
             moves_2++;
             system("cls");
             print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==3 &&point2==4)||(point1==4&&point2==3))
    {   if(grid2[0][10]!=' '){continue;}
        else{grid2[0][9]=205; grid2[0][10]=205; grid2[0][11]=205;
         if(check_down(0,8,21,21,grid2))
         {    grid2[2][10]=50;
             nuOfmoves--;
             score2++;
             moves_2++;
             system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==4 &&point2==5)||(point1==5&&point2==4))
    {   if(grid2[0][14]!=' '){continue;}
        else{ grid2[0][13]=205; grid2[0][14]=205; grid2[0][15]=205;
         if(check_down(0,12,21,21,grid2))
         {    grid2[2][14]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
              system("cls");
              print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==5 &&point2==6)||(point1==6&&point2==5))
    {   if(grid2[0][18]!=' '){continue;}
        else{grid2[0][17]=205; grid2[0][18]=205; grid2[0][19]=205;
         if(check_down(0,16,21,21,grid2))
         {   grid2[2][18]=50;
             nuOfmoves--;
             score2++;
             moves_2++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==7 &&point2==8)||(point1==8&&point2==7))
     {   if(grid2[4][2]!=' '){continue;}
     else{grid2[4][1]=205;grid2[4][2]=205; grid2[4][3]=205;
      if(check_up_down(4,0,21,21,grid2))
      {      grid2[2][2]=50; grid2[6][2]=50;
             nuOfmoves--;
             score2=score2+2;
             moves_2++;
             system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

      else if(check_up(4,0,21,21,grid2))
      {     grid2[2][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

      else if(check_down(4,0,21,21,grid2))
      {     grid2[6][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==8 &&point2==9)||(point1==9&&point2==8))
     {  if(grid2[4][6]!=' '){continue;}
        else{grid2[4][5]=205; grid2[4][6]=205; grid2[4][7]=205;
         if(check_up_down(4,4,21,21,grid2))
         {  grid2[2][6]=50; grid2[6][6]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_up(4,4,21,21,grid2))
         {  grid2[2][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_down(4,4,21,21,grid2))
        {   grid[6][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==9 &&point2==10)||(point1==10&&point2==9))
     {  if(grid2[4][10]!=' '){continue;}
        else{grid2[4][9]=205;grid2[4][10]=205; grid2[4][11]=205;
          if(check_up_down(4,8,21,21,grid2))
          {  grid2[2][10]=50; grid2[6][10]=50;
             nuOfmoves--;
             score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

          else if(check_up(4,8,21,21,grid2))
          {  grid2[2][10]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(4,8,21,21,grid2))
          {  grid2[6][10]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue; }
    }
    }
else if((point1==10 &&point2==11)||(point1==11&&point2==10))
     {  if(grid2[4][14]!=' '){continue;}
        else{grid2[4][13]=205;grid2[4][14]=205; grid2[4][15]=205;
         if(check_up_down(4,12,21,21,grid2))
         {  grid2[2][14]=50; grid2[6][14]=50;
            nuOfmoves--;
            score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_up(4,12,21,21,grid2))
         {  grid2[2][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_down(4,12,21,21,grid2))
         {  grid2[6][14]=50;
            nuOfmoves--;
            score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==11 &&point2==12)||(point1==12&&point2==11))
     {   if(grid2[4][18]!=' '){continue;}
         else{grid2[4][17]=205;grid2[4][18]=205; grid2[4][19]=205;
          if(check_up_down(4,16,21,21,grid2))
          {  grid2[2][18]=50; grid2[6][18]=50;
             nuOfmoves--;
             score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else  if(check_up(4,16,21,21,grid2))
          {  grid2[2][18]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else  if(check_down(4,16,21,21,grid2))
          {  grid2[6][18]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==13 &&point2==14)||(point1==14&&point2==13))
     {   if(grid2[8][2]!=' '){continue;}
         else{grid2[8][1]=205;grid2[8][2]=205; grid2[8][3]=205;
          if(check_up_down(8,0,21,21,grid2))
          {  grid2[6][2]=50; grid2[10][2]=50;
             nuOfmoves--;
             score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}


          else if(check_up(8,0,21,21,grid2))
          {  grid2[6][2]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(8,0,21,21,grid2))
          {  grid2[10][2]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==14 &&point2==15)||(point1==15&&point2==14))
     {   if(grid2[8][6]!=' '){continue;}
         else{grid2[8][5]=205;grid2[8][6]=205; grid2[8][7]=205;
          if(check_up_down(8,4,21,21,grid2))
          {  grid2[6][6]=50; grid2[10][6]=50;
             nuOfmoves--;
             score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_up(8,4,21,21,grid2))
          {  grid2[6][6]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

         else if(check_down(8,4,21,21,grid2))
         {   grid2[10][6]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==15 &&point2==16)||(point1==16&&point2==15))
     {   if(grid2[8][10]!=' '){continue;}
         else{grid2[8][9]=205;grid2[8][10]=205; grid2[8][11]=205;
         if(check_up_down(8,8,21,21,grid2))
         {  grid2[6][10]=50; grid2[10][10]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}


         else if(check_up(8,8,21,21,grid2))
         {   grid2[6][10]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

        else if(check_down(8,8,21,21,grid2))
        {   grid2[10][10]=50;
            nuOfmoves--;
            score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==16 &&point2==17)||(point1==17&&point2==16))
     {   if(grid2[8][14]!=' '){continue;}
         else{grid2[8][13]=205;grid2[8][14]=205; grid2[8][15]=205;
           if(check_up_down(8,12,21,21,grid2))
           {   grid2[6][14]=50; grid2[10][14]=50;
               nuOfmoves--;
               score2=score2+2;
                moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}

          else if(check_up(8,12,21,21,grid2))
          {   grid2[6][14]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

          else if(check_down(8,12,21,21,grid2))
          {   grid2[10][14]=50;
              nuOfmoves--;
              score2++;
               moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==17 &&point2==18)||(point1==18&&point2==17))
     {   if(grid2[8][18]!=' '){continue;}
         else{grid2[8][17]=205;grid2[8][18]=205; grid2[8][19]=205;
           if(check_up_down(8,16,21,21,grid2))
           {  grid2[6][18]=50; grid2[10][18]=50;
              nuOfmoves--;
              score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(8,16,21,21,grid2))
           {  grid2[6][18]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

           else if(check_down(8,16,21,21,grid2))
           {  grid2[10][18]=50;
              nuOfmoves--;
              score2++;
               moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==19 &&point2==20)||(point1==20&&point2==19))
     {   if(grid2[12][2]!=' '){continue;}
         else{grid2[12][1]=205;grid2[12][2]=205; grid2[12][3]=205;
          if(check_up_down(12,0,21,21,grid2))
          {  grid2[10][2]=50; grid2[14][2]=50;
             nuOfmoves--;
             score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

          else if(check_up(12,0,21,21,grid2))
          {  grid2[10][2]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(12,0,21,21,grid2))
          {  grid2[14][2]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==20 &&point2==21)||(point1==21&&point2==20))
    {   if(grid2[12][6]!=' '){continue;}
        else{grid2[12][5]=205;grid2[12][6]=205; grid2[12][7]=205;
      if(check_up_down(12,4,21,21,grid2))
      {  grid2[10][6]=50; grid2[14][6]=50;
         nuOfmoves--;
         score2=score2+2;
          moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
         continue;}

      else if(check_up(12,4,21,21,grid2))
      {  grid2[10][6]=50;
         nuOfmoves--;
         score2++;
          moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
         continue;}

      else if(check_down(12,4,21,21,grid2))
      {   grid2[14][6]=50;
          nuOfmoves--;
          score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==21 &&point2==22)||(point1==22&&point2==21))
     {   if(grid2[12][10]!=' '){continue;}
         else{grid2[12][9]=205;grid2[12][10]=205; grid2[12][11]=205;
          if(check_up_down(12,8,21,21,grid2))
          {  grid2[10][10]=50; grid2[14][10]=50;
             nuOfmoves--;
             score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_up(12,8,21,21,grid2))
          {  grid2[10][10]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(12,8,21,21,grid2))
          {  grid2[14][10]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==22 &&point2==23)||(point1==23&&point2==22))
     {   if(grid2[12][14]!=' '){continue;}
         else{grid2[12][13]=205;grid2[12][14]=205; grid2[12][15]=205;
          if(check_up_down(12,12,21,21,grid2))
          {  grid2[10][14]=50; grid2[14][14]=50;
             nuOfmoves--;
             score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_up(12,12,21,21,grid2))
          { grid2[10][14]=50;
            nuOfmoves--;
            score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else  if(check_down(12,12,21,21,grid2))
         {  grid2[14][14]=50;
            nuOfmoves--;
            score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==23 &&point2==24)||(point1==24&&point2==23))
     {   if(grid2[12][18]!=' '){continue;}
         else{grid2[12][17]=205;grid2[12][18]=205; grid2[12][19]=205;
         if(check_up_down(12,16,21,21,grid2))
         { grid2[10][18]=50; grid2[14][18]=50;
           nuOfmoves--;
           score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_up(12,16,21,21,grid2))
        {  grid2[10][18]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

       else if(check_down(12,16,21,21,grid2))
       {  grid2[14][18]=50;
          nuOfmoves--;
          score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==25 &&point2==26)||(point1==26&&point2==25))
     {   if(grid2[16][2]!=' '){continue;}
         else{grid2[16][1]=205;grid2[16][2]=205; grid2[16][3]=205;
          if(check_up_down(16,0,21,21,grid2))
          { grid2[14][2]=50; grid2[18][2]=50;
            nuOfmoves--;
            score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

          else if(check_up(16,0,21,21,grid2))
          {  grid2[14][2]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

         else if(check_down(16,0,21,21,grid2))
         {  grid2[18][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==26 &&point2==27)||(point1==27&&point2==26))
     {   if(grid2[16][6]!=' '){continue;}
         else{grid2[16][5]=205;grid2[16][6]=205; grid2[16][7]=205;
          if(check_up_down(16,4,21,21,grid2))
          {  grid2[14][6]=50; grid2[18][6]=50;
             nuOfmoves--;
             score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}


          else if(check_up(16,4,21,21,grid2))
          {  grid2[14][6]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_down(16,4,21,21,grid2))
          {  grid2[18][6]=50;
             nuOfmoves--;
             score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==27 &&point2==28)||(point1==28&&point2==27))
     {   if(grid2[16][10]!=' '){continue;}
         else{grid2[16][9]=205;grid2[16][10]=205; grid2[16][11]=205;
           if(check_up_down(16,8,21,21,grid2))
           {  grid2[14][10]=50; grid2[18][10]=50;
              nuOfmoves--;
              score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,8,21,21,grid2))
           {  grid2[14][10]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,8,21,21,grid2))
            {  grid2[18][10]=50;
               nuOfmoves--;
               score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==28 &&point2==29)||(point1==29&&point2==28))
     {   if(grid2[16][14]!=' '){continue;}
         else{grid2[16][13]=205;grid2[16][14]=205; grid2[16][15]=205;
           if(check_up_down(16,12,21,21,grid2))
           {  grid2[14][14]=50; grid2[18][14]=50;
              nuOfmoves--;
              score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,12,21,21,grid2))
           {  grid2[14][14]=50;
              nuOfmoves--;
              score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,12,21,21,grid2))
           {  grid2[18][14]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==29 &&point2==30)||(point1==30&&point2==29))
     {   if(grid2[16][18]!=' '){continue;}
         else{grid2[16][17]=205;grid2[16][18]=205; grid2[16][19]=205;
           if(check_up_down(16,16,21,21,grid2))
           {  grid2[14][18]=50; grid2[18][18]=50;
              nuOfmoves--;
              score2=score2+2;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,16,21,21,grid2))
           {  grid2[14][18]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,16,21,21,grid2))
           {  grid2[18][18]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==31 &&point2==32)||(point1==32&&point2==31))
     {   if(grid2[20][2]!=' '){continue;}
         else{ grid2[20][1]=205; grid2[20][2]=205; grid2[20][3]=205;
          if(check_up(20,0,21,21,grid2))
          {  grid2[18][2]=50;
             nuOfmoves--;
             score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==32 &&point2==33)||(point1==33&&point2==32))
     {   if(grid2[20][6]!=' '){continue;}
         else{ grid2[20][5]=205; grid2[20][6]=205; grid2[20][7]=205;
           if(check_up(20,4,21,21,grid2))
           {  grid2[18][6]=50;
              nuOfmoves--;
              score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==33 &&point2==34)||(point1==34&&point2==33))
     {   if(grid2[20][10]!=' '){continue;}
         else{ grid2[20][9]=205; grid2[20][10]=205; grid2[20][11]=205;
            if(check_up(20,8,21,21,grid2))
            {  grid2[18][10]=50;
               nuOfmoves--;
               score2++;
               moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==34 &&point2==35)||(point1==35&&point2==34))
     {   if(grid2[20][14]!=' '){continue;}
         else{ grid2[20][13]=205; grid2[20][14]=205; grid2[20][15]=205;
           if(check_up(20,12,21,21,grid2))
           {  grid2[18][14]=50;
              nuOfmoves--;
              score2++;
              moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==35 &&point2==36)||(point1==36&&point2==35))
     {   if(grid2[20][18]!=' '){continue;}
         else{ grid2[20][17]=205; grid2[20][18]=205; grid2[20][19]=205;
            if(check_up(20,16,21,21,grid2))
            {  grid2[18][18]=50;
               nuOfmoves--;
               score2++;
               moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==1 &&point2==7)||(point1==7&&point2==1))
     { if(grid2[2][0]!=' '){continue;}
       else{grid2[1][0]=186; grid2[2][0]=186; grid2[3][0]=186;
         if(check_right(0,0,21,21,grid2))
         {  grid2[2][2]=50;
            nuOfmoves--;
            score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                  continue;}
    }
    }
else if((point1==7 &&point2==13)||(point1==13&&point2==7))
     { if(grid2[6][0]!=' '){continue;}
       else{grid2[5][0]=186; grid2[6][0]=186; grid2[7][0]=186;
         if(check_right(4,0,21,21,grid2))
         {  grid2[6][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==13 &&point2==19)||(point1==19&&point2==13))
     { if(grid2[10][0]!=' '){continue;}
       else{grid2[9][0]=186; grid2[10][0]=186; grid2[11][0]=186;
         if(check_right(8,0,21,21,grid2))
         {  grid2[10][2]=50;
            nuOfmoves--;
            score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==19 &&point2==25)||(point1==25&&point2==19))
     { if(grid2[14][0]!=' '){continue;}
       else{grid2[13][0]=186; grid2[14][0]=186; grid2[15][0]=186;
         if(check_right(12,0,21,21,grid2))
         {  grid2[14][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==25 &&point2==31)||(point1==31&&point2==25))
     { if(grid2[18][0]!=' '){continue;}
       else{grid2[17][0]=186; grid2[18][0]=186; grid2[19][0]=186;
         if(check_right(16,0,21,21,grid2))
         {  grid2[18][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==2 &&point2==8)||(point1==8&&point2==2))
     { if(grid2[1][4]!=' '){continue;}
       else{grid2[1][4]=186; grid2[2][4]=186; grid2[3][4]=186;///drawline
         if(check_left_right(0,4,21,21,grid2))
         {  grid2[2][2]=50; grid2[2][6]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else  if(check_left(0,4,21,21,grid2))
        {  grid2[2][2]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(0,4,21,21,grid2))
        {  grid[2][6]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }

else if((point1==8 &&point2==14)||(point1==14&&point2==8))
     { if(grid2[6][4]!=' '){continue;}
       else{grid2[5][4]=186; grid2[6][4]=186; grid2[7][4]=186;///drawline
          if(check_left_right(4,4,21,21,grid2))
          {  grid2[6][2]=50; grid2[6][6]=50;
             nuOfmoves--;
             score2=score2+2;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_left(4,4,21,21,grid2))
          {  grid2[6][2]=50;
             nuOfmoves--;
             score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}

          else if(check_right(4,4,21,21,grid2))
          {  grid2[6][6]=50;
             nuOfmoves--;
             score2++;
             moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==14 &&point2==20)||(point1==20&&point2==14))
     { if(grid2[10][4]!=' '){continue;}
       else{grid2[9][4]=186; grid2[10][4]=186; grid2[11][4]=186;///drawline
        if(check_left_right(8,4,21,21,grid2))
        {  grid2[10][2]=50; grid2[10][6]=50;
           nuOfmoves--;
           score2=score2+2;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}

        else if(check_left(8,4,21,21,grid2))
        {  grid2[10][2]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(8,4,21,21,grid2))
        {  grid2[10][6]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==20 &&point2==26)||(point1==26&&point2==20))
     { if(grid2[14][4]!=' '){continue;}
       else{grid2[13][4]=186; grid2[14][4]=186; grid2[15][4]=186;///drawline
         if(check_left_right(12,4,21,21,grid2))
         {  grid2[14][2]=50; grid2[14][6]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,4,21,21,grid2))
         {  grid2[14][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(12,4,21,21,grid2))
         {  grid2[14][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==26&&point2==32)||(point1==32&&point2==26))
     { if(grid2[18][4]!=' '){continue;}
       else{grid2[17][4]=186; grid2[18][4]=186; grid2[19][4]=186;///drawline
         if(check_left_right(16,4,21,21,grid2))
         {  grid2[18][2]=50; grid2[18][6]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,4,21,21,grid2))
         {  grid2[18][2]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,4,21,21,grid2))
         {  grid2[18][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==3&&point2==9)||(point1==9&&point2==3))
     { if(grid2[2][8]!=' '){continue;}
       else{grid2[1][8]=186; grid2[2][8]=186; grid2[3][8]=186;///drawline
         if(check_left_right(0,8,21,21,grid2))
         {  grid2[2][6]=50; grid2[2][10]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,8,21,21,grid2))
         {  grid2[2][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,8,21,21,grid2))
         {  grid2[2][10]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==9&&point2==15)||(point1==15&&point2==9))
     { if(grid2[6][8]!=' '){continue;}
       else{grid2[5][8]=186; grid2[6][8]=186; grid2[7][8]=186;///drawline
         if(check_left_right(4,8,21,21,grid2))
         {  grid2[6][6]=50; grid2[6][10]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(4,8,21,21,grid2))
         {  grid2[6][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(4,8,21,21,grid2))
        {  grid2[6][10]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==15&&point2==21)||(point1==21&&point2==15))
     { if(grid2[10][8]!=' '){continue;}
       else{grid2[9][8]=186; grid2[10][8]=186; grid2[11][8]=186;///drawline
         if(check_left_right(8,8,21,21,grid2))
         {  grid2[10][6]=50; grid2[10][10]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(8,8,21,21,grid2))
         {  grid2[10][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(8,8,21,21,grid2))
         {  grid2[10][10]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==21&&point2==27)||(point1==27&&point2==21))
     { if(grid2[14][8]!=' '){continue;}
       else{grid2[13][8]=186; grid2[14][8]=186; grid2[15][8]=186;///drawline
        if(check_left_right(12,8,21,21,grid2))
        {  grid2[14][6]=50; grid2[14][10]=50;
           nuOfmoves--;
           score2=score2+2;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(12,8,21,21,grid2))
        {  grid2[14][6]=50;
           nuOfmoves--;
           score2++;
          moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else  if(check_right(12,8,21,21,grid2))
        {  grid2[14][10]=50;
           nuOfmoves--;
           score2++;
          moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==27&&point2==33)||(point1==33&&point2==27))
     { if(grid2[18][8]!=' '){continue;}
       else{grid2[17][8]=186; grid2[18][8]=186; grid2[19][8]=186;///drawline
         if(check_left_right(16,8,21,21,grid2))
         {  grid2[18][6]=50; grid2[18][10]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,8,21,21,grid2))
         {  grid2[18][6]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,8,21,21,grid2))
         {  grid2[18][10]=50;
            nuOfmoves--;
            score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==4&&point2==10)||(point1==10&&point2==4))
     { if(grid2[2][12]!=' '){continue;}
       else{grid2[1][12]=186; grid2[2][12]=186; grid2[3][12]=186;///drawline
         if(check_left_right(0,12,21,21,grid2))
         {  grid2[2][10]=50; grid2[2][14]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,12,21,21,grid2))
         {  grid2[2][10]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,12,21,21,grid2))
         {  grid2[2][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==10&&point2==16)||(point1==16&&point2==10))
     { if(grid2[6][12]!=' '){continue;}
       else{grid2[5][12]=186; grid2[6][12]=186; grid2[7][12]=186;///drawline
         if(check_left_right(4,12,21,21,grid2))
         {  grid2[6][10]=50; grid2[6][14]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(4,12,21,21,grid2))
         {  grid2[6][10]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(4,12,21,21,grid2))
         {  grid2[6][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==16&&point2==22)||(point1==22&&point2==16))
     { if(grid2[10][12]!=' '){continue;}
       else{grid2[9][12]=186; grid2[10][12]=186; grid2[11][12]=186;///drawline
        if(check_left_right(8,12,21,21,grid2))
        {  grid2[10][10]=50; grid2[10][14]=50;
           nuOfmoves--;
           score2=score2+2;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(8,12,21,21,grid2))
        {  grid2[10][10]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else  if(check_right(8,12,21,21,grid2))
        {  grid2[10][14]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==22&&point2==28)||(point1==28&&point2==22))
     { if(grid2[14][12]!=' '){continue;}
       else{grid2[13][12]=186; grid2[14][12]=186; grid2[15][12]=186;///drawline
         if(check_left_right(12,12,21,21,grid2))
         {  grid2[14][10]=50; grid2[14][14]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,12,21,21,grid2))
         {  grid2[14][10]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

        else if(check_right(12,12,21,21,grid2))
        {  grid2[14][14]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==28&&point2==34)||(point1==34&&point2==28))
     { if(grid2[18][12]!=' '){continue;}
       else{grid2[17][12]=186; grid2[18][12]=186; grid2[19][12]=186;///drawline
         if(check_left_right(16,12,21,21,grid2))
         {  grid2[18][10]=50; grid2[18][14]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,12,21,21,grid2))
         {  grid2[18][10]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,12,21,21,grid2))
         {  grid2[18][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==5&&point2==11)||(point1==11&&point2==5))
     { if(grid2[2][16]!=' '){continue;}
       else{grid2[1][16]=186; grid2[2][16]=186; grid2[3][16]=186;///drawline
         if(check_left_right(0,16,21,21,grid2))
         {  grid2[2][14]=50; grid2[2][18]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,16,21,21,grid2))
         {  grid2[2][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,16,21,21,grid2))
         {  grid2[2][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==11&&point2==17)||(point1==17&&point2==11))
     { if(grid2[6][16]!=' '){continue;}
       else{grid2[5][16]=186; grid2[6][16]=186; grid2[7][16]=186;///drawline
        if(check_left_right(4,16,21,21,grid2))
        {  grid2[6][14]=50; grid2[6][18]=50;
           nuOfmoves--;
           score2=score2+2;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(4,16,21,21,grid2))
        {  grid2[6][14]=50;
           nuOfmoves--;
           score2++;
          moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(4,16,21,21,grid2))
        {  grid2[6][18]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==17&&point2==23)||(point1==23&&point2==17))
     { if(grid2[10][16]!=' '){continue;}
       else{grid2[9][16]=186; grid2[10][16]=186; grid2[11][16]=186;///drawline
         if(check_left_right(8,16,21,21,grid2))
         {  grid2[10][14]=50; grid2[10][18]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(8,16,21,21,grid2))
         {  grid2[10][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(8,16,21,21,grid2))
         {  grid2[10][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==23&&point2==29)||(point1==29&&point2==23))
     { if(grid2[14][16]!=' '){continue;}
       else{grid2[13][16]=186; grid2[14][16]=186; grid2[15][16]=186;///drawline
         if(check_left_right(12,16,21,21,grid2))
         {  grid2[14][14]=50; grid2[14][18]=50;
            nuOfmoves--;
            score2=score2+2;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,16,21,21,grid2))
         {  grid2[14][14]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}

         else if(check_right(12,16,21,21,grid2))
         {  grid2[14][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==29 && point2==35)||(point1==35 && point2==29))
     { if(grid2[18][16]!=' '){continue;}
       else{grid2[17][16]=186; grid2[18][16]=186; grid2[19][16]=186;///drawline
        if(check_left_right(16,16,21,21,grid2))
        {  grid2[18][14]=50; grid2[18][18]=50;
           nuOfmoves--;
           score2=score2+2;
          moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_left(16,16,21,21,grid2))
        {  grid2[18][14]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
           continue;}

        else if(check_right(16,16,21,21,grid2))
        {  grid2[18][18]=50;
           nuOfmoves--;
           score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==6 &&point2==12)||(point1==12&&point2==6))
     { if(grid2[2][20]!=' '){continue;}
       else{grid2[1][20]=186; grid2[2][20]=186; grid2[3][20]=186;
         if(check_left(0,20,21,21,grid2))
         {  grid2[2][18]=50;
            nuOfmoves--;
            score2++;
           moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==12 &&point2==18)||(point1==18&&point2==12))
     { if(grid2[6][20]!=' '){continue;}
       else{grid2[5][20]=186; grid2[6][20]=186; grid2[7][20]=186;
         if(check_left(4,20,21,21,grid2))
         {  grid2[6][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==18 &&point2==24)||(point1==24&&point2==18))
     { if(grid2[10][20]!=' '){continue;}
       else{grid2[9][20]=186; grid2[10][20]=186; grid2[11][20]=186;
         if(check_left(8,20,21,21,grid2))
         {  grid2[10][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==24 &&point2==30)||(point1==30&&point2==24))
     { if(grid2[14][20]!=' '){continue;}
       else{grid2[13][20]=186; grid2[14][20]=186; grid2[15][20]=186;
         if(check_left(12,20,21,21,grid2))
         {  grid2[14][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==30 &&point2==36)||(point1==36&&point2==30))
     { if(grid2[18][20]!=' '){continue;}
       else{grid2[17][20]=186; grid2[18][20]=186; grid2[19][20]=186;
         if(check_left(16,20,21,21,grid2))
         {  grid2[18][18]=50;
            nuOfmoves--;
            score2++;
            moves_2++;
            system("cls");
           print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
                  continue;}
    }
    }
    else if(point1==40&&point2==40)
     {
         system("cls");
         SetColor(13);
         printf("choose one of the files 1 or 2 or 3");
         scanf("%d",&file);

        save(file,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
        continue;

     }
     else if(point1==50&&point2==50)
     {
         goto Label1;
     }
else{
         SetColor(6);
         printf("Invalid\n");
         continue;
    }
         nuOfmoves--;
         moves_2++;
        system("cls");
        print_grid(21,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
         break;
    }
}
SetColor(15);
printf("GAME ENDED\n");
if(score1>score2)
{   SetColor(5);
    printf("congratulation player 1 is the winner\n");
}
else if(score1<score2)
{
    SetColor(12);
    printf("congratulation player 2 is the winner\n");
}
else {
    SetColor(11);
    printf("The game is draw\n");
}
SetColor(15);
printf("enter 1 to return to main menu\n enter 2 to exit\n");
int B;
scanf("%d",&B);
if(B==1){ goto Label1;}
else{exit(0);}



  }
  /////////////////////////////playerVScomputer
else if (game_dif==2 && game_mode==1)

{
   int nuOfmoves=60;
   print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);

while(nuOfmoves>0)
{
    while(1) //////////////player one loop
    { if(nuOfmoves<=0)
    {
        break;
    }
    SetColor(5);
    printf("Player's one turn\n");
    SetColor(14);
    printf("enter 1st point:");
    scanf("%d",&point1);
    printf("enter 2nd point:");
    scanf("%d",&point2);

if((point1==1 &&point2==2)||(point1==2 &&point2==1))
        { if(grid2[0][1]!= ' ') {continue;}
        else{grid2[0][1]=205; grid2[0][2]=205; grid2[0][3]=205;
           if(check_down(0,0,21,21,grid2))
           {  grid2[2][2]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                  continue;}
    }
    }
else if((point1==2 &&point2==3)||(point1==3&&point2==2))
    {   if(grid2[0][6]!=' '){continue;}
        else{grid2[0][5]=205; grid2[0][6]=205; grid2[0][7]=205;
         if(check_down(0,4,21,21,grid2))
         {    grid2[2][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==3 &&point2==4)||(point1==4&&point2==3))
    {   if(grid2[0][10]!=' '){continue;}
        else{grid2[0][9]=205; grid2[0][10]=205; grid2[0][11]=205;
         if(check_down(0,8,21,21,grid2))
         {    grid2[2][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==4 &&point2==5)||(point1==5&&point2==4))
    {   if(grid2[0][14]!=' '){continue;}
        else{ grid2[0][13]=205; grid2[0][14]=205; grid2[0][15]=205;
         if(check_down(0,12,21,21,grid2))
         {    grid2[2][14]=49;
              nuOfmoves--;
              score1++;
             moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==5 &&point2==6)||(point1==6&&point2==5))
    {   if(grid2[0][18]!=' '){continue;}
        else{grid2[0][17]=205; grid2[0][18]=205; grid2[0][19]=205;
         if(check_down(0,16,21,21,grid2))
         {   grid2[2][18]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==7 &&point2==8)||(point1==8&&point2==7))
     {   if(grid2[4][2]!=' '){continue;}
     else{grid2[4][1]=205;grid2[4][2]=205; grid2[4][3]=205;
      if(check_up_down(4,0,21,21,grid2))
      {      grid2[2][2]=49; grid2[6][2]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

      else if(check_up(4,0,21,21,grid2))
      {     grid2[2][2]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
              system("cls");
               print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

      else if(check_down(4,0,21,21,grid2))
      {     grid2[6][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==8 &&point2==9)||(point1==9&&point2==8))
     {  if(grid2[4][6]!=' '){continue;}
        else{grid2[4][5]=205; grid2[4][6]=205; grid2[4][7]=205;
         if(check_up_down(4,4,21,21,grid2))
         {  grid2[2][6]=49; grid2[6][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_up(4,4,21,21,grid2))
         {  grid2[2][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

        else if(check_down(4,4,21,21,grid2))
        {   grid[6][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==9 &&point2==10)||(point1==10&&point2==9))
     {  if(grid2[4][10]!=' '){continue;}
        else{grid2[4][9]=205;grid2[4][10]=205; grid2[4][11]=205;
          if(check_up_down(4,8,21,21,grid2))
          {  grid2[2][10]=49; grid2[6][10]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

          else if(check_up(4,8,21,21,grid2))
          {  grid2[2][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_down(4,8,21,21,grid2))
          {  grid2[6][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue; }
    }
    }
else if((point1==10 &&point2==11)||(point1==11&&point2==10))
     {  if(grid2[4][14]!=' '){continue;}
        else{grid2[4][13]=205;grid2[4][14]=205; grid2[4][15]=205;
         if(check_up_down(4,12,21,21,grid2))
         {  grid2[2][14]=49; grid2[6][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_up(4,12,21,21,grid2))
         {  grid2[2][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_down(4,12,21,21,grid2))
         {  grid2[6][14]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==11 &&point2==12)||(point1==12&&point2==11))
     {   if(grid2[4][18]!=' '){continue;}
         else{grid2[4][17]=205;grid2[4][18]=205; grid2[4][19]=205;
          if(check_up_down(4,16,21,21,grid2))
          {  grid2[2][18]=49; grid2[6][18]=49;
             nuOfmoves--;
             score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else  if(check_up(4,16,21,21,grid2))
          {  grid2[2][18]=49;
             nuOfmoves--;
             score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else  if(check_down(4,16,21,21,grid2))
          {  grid2[6][18]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==13 &&point2==14)||(point1==14&&point2==13))
     {   if(grid2[8][2]!=' '){continue;}
         else{grid2[8][1]=205;grid2[8][2]=205; grid2[8][3]=205;
          if(check_up_down(8,0,21,21,grid2))
          {  grid2[6][2]=49; grid2[10][2]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}


          else if(check_up(8,0,21,21,grid2))
          {  grid2[6][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_down(8,0,21,21,grid2))
          {  grid2[10][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==14 &&point2==15)||(point1==15&&point2==14))
     {   if(grid2[8][6]!=' '){continue;}
         else{grid2[8][5]=205;grid2[8][6]=205; grid2[8][7]=205;
          if(check_up_down(8,4,21,21,grid2))
          {  grid2[6][6]=49; grid2[10][6]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_up(8,4,21,21,grid2))
          {  grid2[6][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

         else if(check_down(8,4,21,21,grid2))
         {   grid2[10][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==15 &&point2==16)||(point1==16&&point2==15))
     {   if(grid2[8][10]!=' '){continue;}
         else{grid2[8][9]=205;grid2[8][10]=205; grid2[8][11]=205;
         if(check_up_down(8,8,21,21,grid2))
         {  grid2[6][10]=49; grid2[10][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}


         else if(check_up(8,8,21,21,grid2))
         {   grid2[6][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

        else if(check_down(8,8,21,21,grid2))
        {   grid2[10][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==16 &&point2==17)||(point1==17&&point2==16))
     {   if(grid2[8][14]!=' '){continue;}
         else{grid2[8][13]=205;grid2[8][14]=205; grid2[8][15]=205;
           if(check_up_down(8,12,21,21,grid2))
           {   grid2[6][14]=49; grid2[10][14]=49;
               nuOfmoves--;
               score1=score1+2;
               moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

          else if(check_up(8,12,21,21,grid2))
          {   grid2[6][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

          else if(check_down(8,12,21,21,grid2))
          {   grid2[10][14]=49;
              nuOfmoves--;
              score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==17 &&point2==18)||(point1==18&&point2==17))
     {   if(grid2[8][18]!=' '){continue;}
         else{grid2[8][17]=205;grid2[8][18]=205; grid2[8][19]=205;
           if(check_up_down(8,16,21,21,grid2))
           {  grid2[6][18]=49; grid2[10][18]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_up(8,16,21,21,grid2))
           {  grid2[6][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

           else if(check_down(8,16,21,21,grid2))
           {  grid2[10][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==19 &&point2==20)||(point1==20&&point2==19))
     {   if(grid2[12][2]!=' '){continue;}
         else{grid2[12][1]=205;grid2[12][2]=205; grid2[12][3]=205;
          if(check_up_down(12,0,21,21,grid2))
          {  grid2[10][2]=49; grid2[14][2]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}
          else if(check_up(12,0,21,21,grid2))
          {  grid2[10][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_down(12,0,21,21,grid2))
          {  grid2[14][2]=49;
             nuOfmoves--;
             score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==20 &&point2==21)||(point1==21&&point2==20))
    {   if(grid2[12][6]!=' '){continue;}
        else{grid2[12][5]=205;grid2[12][6]=205; grid2[12][7]=205;
      if(check_up_down(12,4,21,21,grid2))
      {  grid2[10][6]=49; grid2[14][6]=49;
         nuOfmoves--;
         score1=score1+2;
         moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
         continue;}

      else if(check_up(12,4,21,21,grid2))
      {  grid2[10][6]=49;
         nuOfmoves--;
         score1++;
         moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
         continue;}

      else if(check_down(12,4,21,21,grid2))
      {   grid2[14][6]=49;
          nuOfmoves--;
          score1++;
          moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==21 &&point2==22)||(point1==22&&point2==21))
     {   if(grid2[12][10]!=' '){continue;}
         else{grid2[12][9]=205;grid2[12][10]=205; grid2[12][11]=205;
          if(check_up_down(12,8,21,21,grid2))
          {  grid2[10][10]=49; grid2[14][10]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_up(12,8,21,21,grid2))
          {  grid2[10][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_down(12,8,21,21,grid2))
          {  grid2[14][10]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==22 &&point2==23)||(point1==23&&point2==22))
     {   if(grid2[12][14]!=' '){continue;}
         else{grid2[12][13]=205;grid2[12][14]=205; grid2[12][15]=205;
          if(check_up_down(12,12,21,21,grid2))
          {  grid2[10][14]=49; grid2[14][14]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_up(12,12,21,21,grid2))
          { grid2[10][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else  if(check_down(12,12,21,21,grid2))
         {  grid2[14][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==23 &&point2==24)||(point1==24&&point2==23))
     {   if(grid2[12][18]!=' '){continue;}
         else{grid2[12][17]=205;grid2[12][18]=205; grid2[12][19]=205;
         if(check_up_down(12,16,21,21,grid2))
         { grid2[10][18]=49; grid2[14][18]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_up(12,16,21,21,grid2))
        {  grid2[10][18]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

       else if(check_down(12,16,21,21,grid2))
       {  grid2[14][18]=49;
          nuOfmoves--;
          score1++;
          moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==25 &&point2==26)||(point1==26&&point2==25))
     {   if(grid2[16][2]!=' '){continue;}
         else{grid2[16][1]=205;grid2[16][2]=205; grid2[16][3]=205;
          if(check_up_down(16,0,21,21,grid2))
          { grid2[14][2]=49; grid2[18][2]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

          else if(check_up(16,0,21,21,grid2))
          {  grid2[14][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

         else if(check_down(16,0,21,21,grid2))
         {  grid2[18][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==26 &&point2==27)||(point1==27&&point2==26))
     {   if(grid2[16][6]!=' '){continue;}
         else{grid2[16][5]=205;grid2[16][6]=205; grid2[16][7]=205;
          if(check_up_down(16,4,21,21,grid2))
          {  grid2[14][6]=49; grid2[18][6]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}


          else if(check_up(16,4,21,21,grid2))
          {  grid2[14][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_down(16,4,21,21,grid2))
          {  grid2[18][6]=49;
             nuOfmoves--;
             score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==27 &&point2==28)||(point1==28&&point2==27))
     {   if(grid2[16][10]!=' '){continue;}
         else{grid2[16][9]=205;grid2[16][10]=205; grid2[16][11]=205;
           if(check_up_down(16,8,21,21,grid2))
           {  grid2[14][10]=49; grid2[18][10]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,8,21,21,grid2))
           {  grid2[14][10]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,8,21,21,grid2))
            {  grid2[18][10]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==28 &&point2==29)||(point1==29&&point2==28))
     {   if(grid2[16][14]!=' '){continue;}
         else{grid2[16][13]=205;grid2[16][14]=205; grid2[16][15]=205;
           if(check_up_down(16,12,21,21,grid2))
           {  grid2[14][14]=49; grid2[18][14]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,12,21,21,grid2))
           {  grid2[14][14]=49;
              nuOfmoves--;
              score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,12,21,21,grid2))
           {  grid2[18][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==29 &&point2==30)||(point1==30&&point2==29))
     {   if(grid2[16][18]!=' '){continue;}
         else{grid2[16][17]=205;grid2[16][18]=205; grid2[16][19]=205;
           if(check_up_down(16,16,21,21,grid2))
           {  grid2[14][18]=49; grid2[18][18]=49;
              nuOfmoves--;
              score1=score1+2;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_up(16,16,21,21,grid2))
           {  grid2[14][18]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

           else if(check_down(16,16,21,21,grid2))
           {  grid2[18][18]=49;
              nuOfmoves--;
              score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

    }
    }
else if((point1==31 &&point2==32)||(point1==32&&point2==31))
     {   if(grid2[20][2]!=' '){continue;}
         else{ grid2[20][1]=205; grid2[20][2]=205; grid2[20][3]=205;
          if(check_up(20,0,21,21,grid2))
          {  grid2[18][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==32 &&point2==33)||(point1==33&&point2==32))
     {   if(grid2[20][6]!=' '){continue;}
         else{ grid2[20][5]=205; grid2[20][6]=205; grid2[20][7]=205;
           if(check_up(20,4,21,21,grid2))
           {  grid2[18][6]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==33 &&point2==34)||(point1==34&&point2==33))
     {   if(grid2[20][10]!=' '){continue;}
         else{ grid2[20][9]=205; grid2[20][10]=205; grid2[20][11]=205;
            if(check_up(20,8,21,21,grid2))
            {  grid2[18][10]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==34 &&point2==35)||(point1==35&&point2==34))
     {   if(grid2[20][14]!=' '){continue;}
         else{ grid2[20][13]=205; grid2[20][14]=205; grid2[20][15]=205;
           if(check_up(20,12,21,21,grid2))
           {  grid2[18][14]=49;
              nuOfmoves--;
              score1++;
              moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}
    }
    }
else if((point1==35 &&point2==36)||(point1==36&&point2==35))
     {   if(grid2[20][18]!=' '){continue;}
         else{ grid2[20][17]=205; grid2[20][18]=205; grid2[20][19]=205;
            if(check_up(20,16,21,21,grid2))
            {  grid2[18][18]=49;
               nuOfmoves--;
               score1++;
               moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}
    }
    }
else if((point1==1 &&point2==7)||(point1==7&&point2==1))
     { if(grid2[2][0]!=' '){continue;}
       else{grid2[1][0]=186; grid2[2][0]=186; grid2[3][0]=186;
         if(check_right(0,0,21,21,grid2))
         {  grid2[2][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                  continue;}
    }
    }
else if((point1==7 &&point2==13)||(point1==13&&point2==7))
     { if(grid2[6][0]!=' '){continue;}
       else{grid2[5][0]=186; grid2[6][0]=186; grid2[7][0]=186;
         if(check_right(4,0,21,21,grid2))
         {  grid2[6][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==13 &&point2==19)||(point1==19&&point2==13))
     { if(grid2[10][0]!=' '){continue;}
       else{grid2[9][0]=186; grid2[10][0]=186; grid2[11][0]=186;
         if(check_right(8,0,21,21,grid2))
         {  grid2[10][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==19 &&point2==25)||(point1==25&&point2==19))
     { if(grid2[14][0]!=' '){continue;}
       else{grid2[13][0]=186; grid2[14][0]=186; grid2[15][0]=186;
         if(check_right(12,0,21,21,grid2))
         {  grid2[14][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==25 &&point2==31)||(point1==31&&point2==25))
     { if(grid2[18][0]!=' '){continue;}
       else{grid2[17][0]=186; grid2[18][0]=186; grid2[19][0]=186;
         if(check_right(16,0,21,21,grid2))
         {  grid2[18][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==2 &&point2==8)||(point1==8&&point2==2))
     { if(grid2[1][4]!=' '){continue;}
       else{grid2[1][4]=186; grid2[2][4]=186; grid2[3][4]=186;///drawline
         if(check_left_right(0,4,21,21,grid2))
         {  grid2[2][2]=49; grid2[2][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

        else  if(check_left(0,4,21,21,grid2))
        {  grid2[2][2]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_right(0,4,21,21,grid2))
        {  grid[2][6]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }

else if((point1==8 &&point2==14)||(point1==14&&point2==8))
     { if(grid2[6][4]!=' '){continue;}
       else{grid2[5][4]=186; grid2[6][4]=186; grid2[7][4]=186;///drawline
          if(check_left_right(4,4,21,21,grid2))
          {  grid2[6][2]=49; grid2[6][6]=49;
             nuOfmoves--;
             score1=score1+2;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_left(4,4,21,21,grid2))
          {  grid2[6][2]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

          else if(check_right(4,4,21,21,grid2))
          {  grid2[6][6]=49;
             nuOfmoves--;
             score1++;
             moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}
    }
    }
else if((point1==14 &&point2==20)||(point1==20&&point2==14))
     { if(grid2[10][4]!=' '){continue;}
       else{grid2[9][4]=186; grid2[10][4]=186; grid2[11][4]=186;///drawline
        if(check_left_right(8,4,21,21,grid2))
        {  grid2[10][2]=49; grid2[10][6]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}

        else if(check_left(8,4,21,21,grid2))
        {  grid2[10][2]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_right(8,4,21,21,grid2))
        {  grid2[10][6]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==20 &&point2==26)||(point1==26&&point2==20))
     { if(grid2[14][4]!=' '){continue;}
       else{grid2[13][4]=186; grid2[14][4]=186; grid2[15][4]=186;///drawline
         if(check_left_right(12,4,21,21,grid2))
         {  grid2[14][2]=49; grid2[14][6]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,4,21,21,grid2))
         {  grid2[14][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(12,4,21,21,grid2))
         {  grid2[14][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==26&&point2==32)||(point1==32&&point2==26))
     { if(grid2[18][4]!=' '){continue;}
       else{grid2[17][4]=186; grid2[18][4]=186; grid2[19][4]=186;///drawline
         if(check_left_right(16,4,21,21,grid2))
         {  grid2[18][2]=49; grid2[18][6]=49;
            nuOfmoves--;
            score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,4,21,21,grid2))
         {  grid2[18][2]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,4,21,21,grid2))
         {  grid2[18][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==3&&point2==9)||(point1==9&&point2==3))
     { if(grid2[2][8]!=' '){continue;}
       else{grid2[1][8]=186; grid2[2][8]=186; grid2[3][8]=186;///drawline
         if(check_left_right(0,8,21,21,grid2))
         {  grid2[2][6]=49; grid2[2][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,8,21,21,grid2))
         {  grid2[2][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,8,21,21,grid2))
         {  grid2[2][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==9&&point2==15)||(point1==15&&point2==9))
     { if(grid2[6][8]!=' '){continue;}
       else{grid2[5][8]=186; grid2[6][8]=186; grid2[7][8]=186;///drawline
         if(check_left_right(4,8,21,21,grid2))
         {  grid2[6][6]=49; grid2[6][10]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(4,8,21,21,grid2))
         {  grid2[6][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(4,8,21,21,grid2))
        {  grid2[6][10]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==15&&point2==21)||(point1==21&&point2==15))
     { if(grid2[10][8]!=' '){continue;}
       else{grid2[9][8]=186; grid2[10][8]=186; grid2[11][8]=186;///drawline
         if(check_left_right(8,8,21,21,grid2))
         {  grid2[10][6]=49; grid2[10][10]=49;
            nuOfmoves--;
            score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(8,8,21,21,grid2))
         {  grid2[10][6]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(8,8,21,21,grid2))
         {  grid2[10][10]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==21&&point2==27)||(point1==27&&point2==21))
     { if(grid2[14][8]!=' '){continue;}
       else{grid2[13][8]=186; grid2[14][8]=186; grid2[15][8]=186;///drawline
        if(check_left_right(12,8,21,21,grid2))
        {  grid2[14][6]=49; grid2[14][10]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_left(12,8,21,21,grid2))
        {  grid2[14][6]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else  if(check_right(12,8,21,21,grid2))
        {  grid2[14][10]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==27&&point2==33)||(point1==33&&point2==27))
     { if(grid2[18][8]!=' '){continue;}
       else{grid2[17][8]=186; grid2[18][8]=186; grid2[19][8]=186;///drawline
         if(check_left_right(16,8,21,21,grid2))
         {  grid2[18][6]=49; grid2[18][10]=49;
            nuOfmoves--;
            score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,8,21,21,grid2))
         {  grid2[18][6]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,8,21,21,grid2))
         {  grid2[18][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==4&&point2==10)||(point1==10&&point2==4))
     { if(grid2[2][12]!=' '){continue;}
       else{grid2[1][12]=186; grid2[2][12]=186; grid2[3][12]=186;///drawline
         if(check_left_right(0,12,21,21,grid2))
         {  grid2[2][10]=49; grid2[2][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,12,21,21,grid2))
         {  grid2[2][10]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,12,21,21,grid2))
         {  grid2[2][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==10&&point2==16)||(point1==16&&point2==10))
     { if(grid2[6][12]!=' '){continue;}
       else{grid2[5][12]=186; grid2[6][12]=186; grid2[7][12]=186;///drawline
         if(check_left_right(4,12,21,21,grid2))
         {  grid2[6][10]=49; grid2[6][14]=49;
            nuOfmoves--;
            score1=score1+2;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(4,12,21,21,grid2))
         {  grid2[6][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(4,12,21,21,grid2))
         {  grid2[6][14]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==16&&point2==22)||(point1==22&&point2==16))
     { if(grid2[10][12]!=' '){continue;}
       else{grid2[9][12]=186; grid2[10][12]=186; grid2[11][12]=186;///drawline
        if(check_left_right(8,12,21,21,grid2))
        {  grid2[10][10]=49; grid2[10][14]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_left(8,12,21,21,grid2))
        {  grid2[10][10]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else  if(check_right(8,12,21,21,grid2))
        {  grid2[10][14]=49;
           nuOfmoves--;
           score1++;
          moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==22&&point2==28)||(point1==28&&point2==22))
     { if(grid2[14][12]!=' '){continue;}
       else{grid2[13][12]=186; grid2[14][12]=186; grid2[15][12]=186;///drawline
         if(check_left_right(12,12,21,21,grid2))
         {  grid2[14][10]=49; grid2[14][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,12,21,21,grid2))
         {  grid2[14][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

        else if(check_right(12,12,21,21,grid2))
        {  grid2[14][14]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==28&&point2==34)||(point1==34&&point2==28))
     { if(grid2[18][12]!=' '){continue;}
       else{grid2[17][12]=186; grid2[18][12]=186; grid2[19][12]=186;///drawline
         if(check_left_right(16,12,21,21,grid2))
         {  grid2[18][10]=49; grid2[18][14]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(16,12,21,21,grid2))
         {  grid2[18][10]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(16,12,21,21,grid2))
         {  grid2[18][14]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==5&&point2==11)||(point1==11&&point2==5))
     { if(grid2[2][16]!=' '){continue;}
       else{grid2[1][16]=186; grid2[2][16]=186; grid2[3][16]=186;///drawline
         if(check_left_right(0,16,21,21,grid2))
         {  grid2[2][14]=49; grid2[2][18]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(0,16,21,21,grid2))
         {  grid2[2][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(0,16,21,21,grid2))
         {  grid2[2][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==11&&point2==17)||(point1==17&&point2==11))
     { if(grid2[6][16]!=' '){continue;}
       else{grid2[5][16]=186; grid2[6][16]=186; grid2[7][16]=186;///drawline
        if(check_left_right(4,16,21,21,grid2))
        {  grid2[6][14]=49; grid2[6][18]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_left(4,16,21,21,grid2))
        {  grid2[6][14]=49;
           nuOfmoves--;
           score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_right(4,16,21,21,grid2))
        {  grid2[6][18]=49;
           nuOfmoves--;
           score1++;
          moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}
    }
    }
else if((point1==17&&point2==23)||(point1==23&&point2==17))
     { if(grid2[10][16]!=' '){continue;}
       else{grid2[9][16]=186; grid2[10][16]=186; grid2[11][16]=186;///drawline
         if(check_left_right(8,16,21,21,grid2))
         {  grid2[10][14]=49; grid2[10][18]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(8,16,21,21,grid2))
         {  grid2[10][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(8,16,21,21,grid2))
         {  grid2[10][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==23&&point2==29)||(point1==29&&point2==23))
     { if(grid2[14][16]!=' '){continue;}
       else{grid2[13][16]=186; grid2[14][16]=186; grid2[15][16]=186;///drawline
         if(check_left_right(12,16,21,21,grid2))
         {  grid2[14][14]=49; grid2[14][18]=49;
            nuOfmoves--;
            score1=score1+2;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_left(12,16,21,21,grid2))
         {  grid2[14][14]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

         else if(check_right(12,16,21,21,grid2))
         {  grid2[14][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==29 && point2==35)||(point1==35 && point2==29))
     { if(grid2[18][16]!=' '){continue;}
       else{grid2[17][16]=186; grid2[18][16]=186; grid2[19][16]=186;///drawline
        if(check_left_right(16,16,21,21,grid2))
        {  grid2[18][14]=49; grid2[18][18]=49;
           nuOfmoves--;
           score1=score1+2;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_left(16,16,21,21,grid2))
        {  grid2[18][14]=49;
           nuOfmoves--;
           score1++;
          moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

        else if(check_right(16,16,21,21,grid2))
        {  grid2[18][18]=49;
           nuOfmoves--;
           score1++;
          moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}
    }
    }
else if((point1==6 &&point2==12)||(point1==12&&point2==6))
     { if(grid2[2][20]!=' '){continue;}
       else{grid2[1][20]=186; grid2[2][20]=186; grid2[3][20]=186;
         if(check_left(0,20,21,21,grid2))
         {  grid2[2][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==12 &&point2==18)||(point1==18&&point2==12))
     { if(grid2[6][20]!=' '){continue;}
       else{grid2[5][20]=186; grid2[6][20]=186; grid2[7][20]=186;
         if(check_left(4,20,21,21,grid2))
         {  grid2[6][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }

else if((point1==18 &&point2==24)||(point1==24&&point2==18))
     { if(grid2[10][20]!=' '){continue;}
       else{grid2[9][20]=186; grid2[10][20]=186; grid2[11][20]=186;
         if(check_left(8,20,21,21,grid2))
         {  grid2[10][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==24 &&point2==30)||(point1==30&&point2==24))
     { if(grid2[14][20]!=' '){continue;}
       else{grid2[13][20]=186; grid2[14][20]=186; grid2[15][20]=186;
         if(check_left(12,20,21,21,grid2))
         {  grid2[14][18]=49;
            nuOfmoves--;
            score1++;
            moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}
    }
    }
else if((point1==30 &&point2==36)||(point1==36&&point2==30))
     { if(grid2[18][20]!=' '){continue;}
       else{grid2[17][20]=186; grid2[18][20]=186; grid2[19][20]=186;
         if(check_left(16,20,21,21,grid2))
         {  grid2[18][18]=49;
            nuOfmoves--;
            score1++;
           moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                  continue;}
    }
    }
    else if(point1==40&&point2==40)
     {
         system("cls");
         SetColor(13);
         printf("choose one of the files 1 or 2 or 3");
         scanf("%d",&file);

        save(file,21,grid2,name1,score1,moves_1,name2,score2,moves_2,nuOfmoves);
        continue;

     }
     else if(point1==50&&point2==50)
     {
         goto Label1;
     }
else{
         SetColor(6);
         printf("Invalid\n");
         continue;
    }
         nuOfmoves--;
         moves_1++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
         break;
    }
    while(2) ///////////////////////////////////////////////////////////////////////Computerloop
    { if(nuOfmoves<=0)
    {
        break;
    }

if((grid2[0][1]== ' ')&& (check_down(0,0,21,21,grid2))){
              grid2[0][1]=205; grid2[0][2]=205; grid2[0][3]=205;
              grid2[2][2]=50;
              nuOfmoves--;
              compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
                  continue;}

else if((grid2[0][6]==' ')&&(check_down(0,4,21,21,grid2))){
             grid2[0][5]=205; grid2[0][6]=205; grid2[0][7]=205;
             grid2[2][6]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[0][10]==' ')&&(check_down(0,8,21,21,grid2))){
             grid2[0][9]=205; grid2[0][10]=205; grid2[0][11]=205;
             grid2[2][10]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[0][14]==' ')&&(check_down(0,12,21,21,grid2))){
              grid2[0][13]=205; grid2[0][14]=205; grid2[0][15]=205;
              grid2[2][14]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[0][18]==' ')&&(check_down(0,16,21,21,grid2))){
             grid2[0][17]=205; grid2[0][18]=205; grid2[0][19]=205;
             grid2[2][18]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[4][2]==' ')&&(check_up_down(4,0,21,21,grid2))){
             grid2[4][1]=205;grid2[4][2]=205; grid2[4][3]=205;
             grid2[2][2]=50; grid2[6][2]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[4][2]==' ')&&(check_up(4,0,21,21,grid2))){
            grid2[4][1]=205;grid2[4][2]=205; grid2[4][3]=205;
            grid2[2][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][2]==' ')&&(check_down(4,0,21,21,grid2))){
            grid2[4][1]=205;grid2[4][2]=205; grid2[4][3]=205;
            grid2[6][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][6]==' ')&&(check_up_down(4,4,21,21,grid2))){
            grid2[4][5]=205;grid2[4][6]=205; grid2[4][7]=205;
            grid2[2][6]=50; grid2[6][6]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][6]==' ')&&(check_up(4,4,21,21,grid2))){
            grid2[4][5]=205;grid2[4][6]=205; grid2[4][7]=205;
            grid2[2][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][6]==' ')&&(check_down(4,4,21,21,grid2))){
            grid2[4][5]=205;grid2[4][6]=205; grid2[4][7]=205;
            grid[6][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][10]==' ')&&(check_up_down(4,8,21,21,grid2))){
             grid2[4][9]=205;grid2[4][10]=205; grid2[4][11]=205;
             grid2[2][10]=50; grid2[6][10]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][10]==' ')&&(check_up(4,8,21,21,grid2))){
             grid2[4][9]=205;grid2[4][10]=205; grid2[4][11]=205;
             grid2[2][10]=50;
             nuOfmoves--;
             compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[4][10]==' ')&&(check_down(4,8,21,21,grid2))){
             grid2[4][9]=205;grid2[4][10]=205; grid2[4][11]=205;
             grid2[6][10]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue; }

else if((grid2[4][14]==' ')&&(check_up_down(4,12,21,21,grid2))){
            grid2[4][13]=205;grid2[4][14]=205; grid2[4][15]=205;
            grid2[2][14]=50; grid2[6][14]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][14]==' ')&&(check_up(4,12,21,21,grid2))){
            grid2[4][13]=205;grid2[4][14]=205; grid2[4][15]=205;
            grid2[2][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][14]==' ')&&(check_down(4,12,21,21,grid2))){
            grid2[4][13]=205;grid2[4][14]=205; grid2[4][15]=205;
            grid2[6][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[4][18]==' ')&&(check_up_down(4,16,21,21,grid2))){
             grid2[4][17]=205;grid2[4][18]=205; grid2[4][19]=205;
             grid2[2][18]=50; grid2[6][18]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[4][18]==' ')&&(check_up(4,16,21,21,grid2))){
             grid2[4][17]=205;grid2[4][18]=205; grid2[4][19]=205;
             grid2[2][18]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[4][18]==' ')&&(check_down(4,16,21,21,grid2))){
             grid2[4][17]=205;grid2[4][18]=205; grid2[4][19]=205;
             grid2[6][18]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][2]==' ')&&(check_up_down(8,0,21,21,grid2))){
             grid2[8][1]=205;grid2[8][2]=205; grid2[8][3]=205;
             grid2[6][2]=50; grid2[10][2]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}


else if((grid2[8][2]==' ')&&(check_up(8,0,21,21,grid2))){
             grid2[8][1]=205;grid2[8][2]=205; grid2[8][3]=205;
             grid2[6][2]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][2]==' ')&&(check_down(8,0,21,21,grid2))){
             grid2[8][1]=205;grid2[8][2]=205; grid2[8][3]=205;
             grid2[10][2]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][6]==' ')&&(check_up_down(8,4,21,21,grid2))){
             grid2[8][5]=205;grid2[8][6]=205; grid2[8][7]=205;
             grid2[6][6]=50; grid2[10][6]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][6]==' ')&&(check_up(8,4,21,21,grid2))){
             grid2[8][5]=205;grid2[8][6]=205; grid2[8][7]=205;
             grid2[6][6]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][6]==' ')&&(check_up_down(8,4,21,21,grid2))){
             grid2[8][5]=205;grid2[8][6]=205; grid2[8][7]=205;
             grid2[10][6]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[8][10]==' ')&&(check_up_down(8,8,21,21,grid2))){
            grid2[8][9]=205;grid2[8][10]=205; grid2[8][11]=205;
            grid2[6][10]=50; grid2[10][10]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[8][10]==' ')&&(check_up(8,8,21,21,grid2))){
             grid2[8][9]=205;grid2[8][10]=205; grid2[8][11]=205;
             grid2[6][10]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][10]==' ')&&(check_down(8,8,21,21,grid2))){
            grid2[8][9]=205;grid2[8][10]=205; grid2[8][11]=205;
            grid2[10][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[8][14]==' ')&&(check_up_down(8,12,21,21,grid2))){
               grid2[8][13]=205;grid2[8][14]=205; grid2[8][15]=205;
               grid2[6][14]=50; grid2[10][14]=50;
               nuOfmoves--;
               compscore=compscore+2;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid2[8][14]==' ')&&(check_up(8,12,21,21,grid2))){
              grid2[8][13]=205;grid2[8][14]=205; grid2[8][15]=205;
              grid2[6][14]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[8][14]==' ')&&(check_down(8,12,21,21,grid2))){
              grid2[8][13]=205;grid2[8][14]=205; grid2[8][15]=205;
              grid2[10][14]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[8][18]==' ')&&(check_up_down(8,16,21,21,grid2))){
              grid2[8][17]=205;grid2[8][18]=205; grid2[8][19]=205;
              grid2[6][18]=50; grid2[10][18]=50;
              nuOfmoves--;
              compscore=compscore+2;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[8][18]==' ')&&(check_up(8,16,21,21,grid2))){
              grid2[8][17]=205;grid2[8][18]=205; grid2[8][19]=205;
              grid2[6][18]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[8][18]==' ')&&(check_down(8,16,21,21,grid2))){
              grid2[8][17]=205;grid2[8][18]=205; grid2[8][19]=205;
              grid2[10][18]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[12][2]==' ')&&(check_up_down(12,0,21,21,grid2))){
             grid2[12][1]=205;grid2[12][2]=205; grid2[12][3]=205;
             grid2[10][2]=50; grid2[14][2]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][2]==' ')&&(check_up(12,0,21,21,grid2))){
             grid2[12][1]=205;grid2[12][2]=205; grid2[12][3]=205;
             grid2[10][2]=50;
             nuOfmoves--;
             compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][2]==' ')&&(check_down(12,0,21,21,grid2))){
             grid2[12][1]=205;grid2[12][2]=205; grid2[12][3]=205;
             grid2[14][2]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][6]==' ')&&(check_up_down(12,4,21,21,grid2))){
         grid2[12][5]=205;grid2[12][6]=205; grid2[12][7]=205;
         grid2[10][6]=50; grid2[14][6]=50;
         nuOfmoves--;
         compscore=compscore+2;
         moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
         continue;}

else if((grid2[12][6]==' ')&&(check_up(12,4,21,21,grid2))){
         grid2[12][5]=205;grid2[12][6]=205; grid2[12][7]=205;
         grid2[10][6]=50;
         nuOfmoves--;
         compscore++;
         moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
         continue;}

else if((grid2[12][6]==' ')&&(check_down(12,4,21,21,grid2))){
         grid2[12][5]=205;grid2[12][6]=205; grid2[12][7]=205;
          grid2[14][6]=50;
          nuOfmoves--;
          compscore++;
         moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}

else if((grid2[12][10]==' ')&&(check_up_down(12,8,21,21,grid2))){
             grid2[12][9]=205;grid2[12][10]=205; grid2[12][11]=205;
             grid2[10][10]=50; grid2[14][10]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][10]==' ')&&(check_up(12,8,21,21,grid2))){
             grid2[12][9]=205;grid2[12][10]=205; grid2[12][11]=205;
             grid2[10][10]=50;
             nuOfmoves--;
             compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][10]==' ')&&(check_down(12,8,21,21,grid2))){
             grid2[12][9]=205;grid2[12][10]=205; grid2[12][11]=205;
             grid2[14][10]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][14]==' ')&&(check_up_down(12,12,21,21,grid2))){
             grid2[12][13]=205;grid2[12][14]=205; grid2[12][15]=205;
             grid2[10][14]=50; grid2[14][14]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[12][14]==' ')&&(check_up(12,12,21,21,grid2))){
            grid2[12][13]=205;grid2[12][14]=205; grid2[12][15]=205;
            grid2[10][14]=50;
            nuOfmoves--;
            compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[12][14]==' ')&&(check_down(12,12,21,21,grid2))){
            grid2[12][13]=205;grid2[12][14]=205; grid2[12][15]=205;
            grid2[14][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[12][18]==' ')&&(check_up_down(12,16,21,21,grid2))){
           grid2[12][17]=205;grid2[12][18]=205; grid2[12][19]=205;
           grid2[10][18]=50; grid2[14][18]=50;
           nuOfmoves--;
           compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[12][18]==' ')&&(check_up(12,16,21,21,grid2))){
           grid2[12][17]=205;grid2[12][18]=205; grid2[12][19]=205;
           grid2[10][18]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[12][18]==' ')&&(check_down(12,16,21,21,grid2))){
          grid2[12][17]=205;grid2[12][18]=205; grid2[12][19]=205;
          grid2[14][18]=50;
          nuOfmoves--;
          compscore++;
          moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}

else if((grid2[16][2]==' ')&&(check_up_down(16,0,21,21,grid2))){
            grid2[16][1]=205;grid2[16][2]=205; grid2[16][3]=205;
            grid2[14][2]=50; grid2[18][2]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[16][2]==' ')&&(check_up(16,0,21,21,grid2))){
             grid2[16][1]=205;grid2[16][2]=205; grid2[16][3]=205;
             grid2[14][2]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[16][2]==' ')&&(check_down(16,0,21,21,grid2))){
            grid2[16][1]=205;grid2[16][2]=205; grid2[16][3]=205;
            grid2[18][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[16][6]==' ')&&(check_up_down(16,4,21,21,grid2))){
             grid2[16][5]=205;grid2[16][6]=205; grid2[16][7]=205;
             grid2[14][6]=50; grid2[18][6]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}


else if((grid2[16][6]==' ')&&(check_up(16,4,21,21,grid2))){
             grid2[16][5]=205;grid2[16][6]=205; grid2[16][7]=205;
             grid2[14][6]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[16][6]==' ')&&(check_down(16,4,21,21,grid2))){
             grid2[16][5]=205;grid2[16][6]=205; grid2[16][7]=205;
             grid2[18][6]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[16][10]==' ')&&(check_up_down(16,8,21,21,grid2))){
              grid2[16][9]=205;grid2[16][10]=205; grid2[16][11]=205;
              grid2[14][10]=50; grid2[18][10]=50;
              nuOfmoves--;
              compscore=compscore+2;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[16][10]==' ')&&(check_up(16,8,21,21,grid2))){
              grid2[16][9]=205;grid2[16][10]=205; grid2[16][11]=205;
              grid2[14][10]=50;
              nuOfmoves--;
              compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[16][10]==' ')&&(check_down(16,8,21,21,grid2))){
               grid2[16][9]=205;grid2[16][10]=205; grid2[16][11]=205;
               grid2[18][10]=50;
               nuOfmoves--;
               compscore++;
               moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid2[16][14]==' ')&&(check_up_down(16,12,21,21,grid2))){
               grid2[16][13]=205;grid2[16][14]=205; grid2[16][15]=205;
               grid2[14][14]=50; grid2[18][14]=50;
               nuOfmoves--;
               compscore=compscore+2;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid2[16][14]==' ')&&(check_up(16,12,21,21,grid2))){
              grid2[16][13]=205;grid2[16][14]=205; grid2[16][15]=205;
              grid2[14][14]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[16][14]==' ')&&(check_down(16,12,21,21,grid2))){
              grid2[16][13]=205;grid2[16][14]=205; grid2[16][15]=205;
              grid2[18][14]=50;
              nuOfmoves--;
              compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[16][18]==' ')&&(check_up_down(16,16,21,21,grid2))){
              grid2[16][17]=205;grid2[16][18]=205; grid2[16][19]=205;
              grid2[14][18]=50; grid2[18][18]=50;
              nuOfmoves--;
              compscore=compscore+2;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[16][18]==' ')&&(check_up(16,16,21,21,grid2))){
              grid2[16][17]=205;grid2[16][18]=205; grid2[16][19]=205;
              grid2[14][18]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[16][18]==' ')&&(check_down(16,16,21,21,grid2))){
              grid2[16][17]=205;grid2[16][18]=205; grid2[16][19]=205;
              grid2[18][18]=50;
              nuOfmoves--;
              compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[20][2]==' ')&&(check_up(20,0,21,21,grid2))){
             grid2[20][1]=205; grid2[20][2]=205; grid2[20][3]=205;
             grid2[18][2]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[20][6]==' ')&&(check_up(20,4,21,21,grid2))){
              grid2[20][5]=205; grid2[20][6]=205; grid2[20][7]=205;
              grid2[18][6]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[20][10]==' ')&&(check_up(20,8,21,21,grid2))){
               grid2[20][9]=205; grid2[20][10]=205; grid2[20][11]=205;
               grid2[18][10]=50;
               nuOfmoves--;
               compscore++;
               moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid2[20][14]==' ')&&(check_up(20,12,21,21,grid2))){
              grid2[20][13]=205; grid2[20][14]=205; grid2[20][15]=205;
              grid2[18][14]=50;
              nuOfmoves--;
              compscore++;
              moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
              continue;}

else if((grid2[20][18]==' ')&&(check_up(20,6,21,21,grid2))){
               grid2[20][17]=205; grid2[20][18]=205; grid2[20][19]=205;
               grid2[18][18]=50;
               nuOfmoves--;
               compscore++;
               moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
               continue;}

else if((grid2[2][0]==' ')&&(check_right(0,0,21,21,grid2))){
            grid2[1][0]=186; grid2[2][0]=186; grid2[3][0]=186;
            grid2[2][2]=50;
            nuOfmoves--;
            compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][0]==' ')&&(check_right(4,0,21,21,grid2))){
            grid2[5][0]=186; grid2[6][0]=186; grid2[7][0]=186;
            grid2[6][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][0]==' ')&&(check_right(8,0,21,21,grid2))){
            grid2[9][0]=186; grid2[10][0]=186; grid2[11][0]=186;
            grid2[10][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}


else if((grid2[14][0]==' ')&&(check_right(12,0,21,21,grid2))){
            grid2[13][0]=186; grid2[14][0]=186; grid2[15][0]=186;
            grid2[14][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][0]==' ')&&(check_right(16,0,21,21,grid2))){
            grid2[17][0]=186; grid2[18][0]=186; grid2[19][0]=186;
            grid2[18][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[1][4]==' ')&&(check_left_right(0,4,21,21,grid2))){
            grid2[1][4]=186; grid2[2][4]=186; grid2[3][4]=186;
            grid2[2][2]=50; grid2[2][6]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[1][4]==' ')&&(check_left(0,4,21,21,grid2))){
           grid2[1][4]=186; grid2[2][4]=186; grid2[3][4]=186;
           grid2[2][2]=50;
           nuOfmoves--;
           compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[1][4]==' ')&&(check_right(0,4,21,21,grid2))){
           grid2[1][4]=186; grid2[2][4]=186; grid2[3][4]=186;
           grid[2][6]=50;
           nuOfmoves--;
           compscore++;
          moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}


else if((grid2[6][4]==' ')&&(check_left_right(4,4,21,21,grid2))){
             grid2[5][4]=186; grid2[6][4]=186; grid2[7][4]=186;
             grid2[6][2]=50; grid2[6][6]=50;
             nuOfmoves--;
             compscore=compscore+2;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[6][4]==' ')&&(check_left(4,4,21,21,grid2))){
             grid2[5][4]=186; grid2[6][4]=186; grid2[7][4]=186;
             grid2[6][2]=50;
             nuOfmoves--;
             compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[6][4]==' ')&&(check_right(4,4,21,21,grid2))){
             grid2[5][4]=186; grid2[6][4]=186; grid2[7][4]=186;
             grid2[6][6]=50;
             nuOfmoves--;
             compscore++;
             moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
             continue;}

else if((grid2[10][4]==' ')&&(check_left_right(8,4,21,21,grid2))){
           grid2[9][4]=186; grid2[10][4]=186; grid2[11][4]=186;
           grid2[10][2]=50; grid2[10][6]=50;
           nuOfmoves--;
           compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[10][4]==' ')&&(check_left(8,4,21,21,grid2))){
           grid2[9][4]=186; grid2[10][4]=186; grid2[11][4]=186;
           grid2[10][2]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[10][4]==' ')&&(check_right(8,4,21,21,grid2))){
           grid2[9][4]=186; grid2[10][4]=186; grid2[11][4]=186;
           grid2[10][6]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[14][4]==' ')&&(check_left_right(12,4,21,21,grid2))){
            grid2[13][4]=186; grid2[14][4]=186; grid2[15][4]=186;
            grid2[14][2]=50; grid2[14][6]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][4]==' ')&&(check_left(12,4,21,21,grid2))){
            grid2[13][4]=186; grid2[14][4]=186; grid2[15][4]=186;
            grid2[14][2]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][4]==' ')&&(check_right(12,4,21,21,grid2))){
            grid2[13][4]=186; grid2[14][4]=186; grid2[15][4]=186;
            grid2[14][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][4]==' ')&&check_left_right(16,4,21,21,grid2)){
            grid2[17][4]=186; grid2[18][4]=186; grid2[19][4]=186;
            grid2[18][2]=50; grid2[18][6]=50;
            nuOfmoves--;
            compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][4]==' ')&&check_left(16,4,21,21,grid2)){
            grid2[17][4]=186; grid2[18][4]=186; grid2[19][4]=186;
            grid2[18][2]=50;
            nuOfmoves--;
            compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][4]==' ')&&check_right(16,4,21,21,grid2)){
            grid2[17][4]=186; grid2[18][4]=186; grid2[19][4]=186;
            grid2[18][6]=50;
            nuOfmoves--;
            compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][8]==' ')&&(check_left_right(0,8,21,21,grid2))){
            grid2[1][8]=186; grid2[2][8]=186; grid2[3][8]=186;
            grid2[2][6]=50; grid2[2][10]=50;
            nuOfmoves--;
            compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][8]==' ')&&(check_left(0,8,21,21,grid2))){
            grid2[1][8]=186; grid2[2][8]=186; grid2[3][8]=186;
            grid2[2][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][8]==' ')&&(check_right(0,8,21,21,grid2))){
            grid2[1][8]=186; grid2[2][8]=186; grid2[3][8]=186;
            grid2[2][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][8]==' ')&&(check_left_right(4,8,21,21,grid2))){
            grid2[5][8]=186; grid2[6][8]=186; grid2[7][8]=186;
            grid2[6][6]=50; grid2[6][10]=50;
            nuOfmoves--;
            compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][8]==' ')&&(check_left(4,8,21,21,grid2))){
            grid2[5][8]=186; grid2[6][8]=186; grid2[7][8]=186;
            grid2[6][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][8]==' ')&&(check_right(4,8,21,21,grid2))){
           grid2[5][8]=186; grid2[6][8]=186; grid2[7][8]=186;
           grid2[6][10]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[10][8]==' ')&&(check_left_right(8,8,21,21,grid2))){
            grid2[9][8]=186; grid2[10][8]=186; grid2[11][8]=186;
            grid2[10][6]=50; grid2[10][10]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][8]==' ')&&(check_left(8,8,21,21,grid2))){
            grid2[9][8]=186; grid2[10][8]=186; grid2[11][8]=186;
            grid2[10][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][8]==' ')&&(check_right(8,8,21,21,grid2))){
            grid2[9][8]=186; grid2[10][8]=186; grid2[11][8]=186;
            grid2[10][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][8]==' ')&&(check_left_right(12,8,21,21,grid2))){
           grid2[13][8]=186; grid2[14][8]=186; grid2[15][8]=186;
           grid2[14][6]=50; grid2[14][10]=50;
           nuOfmoves--;
           compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[14][8]==' ')&&(check_left(12,8,21,21,grid2))){
          grid2[13][8]=186; grid2[14][8]=186; grid2[15][8]=186;
           grid2[14][6]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[14][8]==' ')&&(check_right(12,8,21,21,grid2))){
           grid2[13][8]=186; grid2[14][8]=186; grid2[15][8]=186;
           grid2[14][10]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[18][8]==' ')&&(check_left_right(16,8,21,21,grid2))){
            grid2[17][8]=186; grid2[18][8]=186; grid2[19][8]=186;
            grid2[18][6]=50; grid2[18][10]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][8]==' ')&&(check_left_right(16,8,21,21,grid2))){
            grid2[17][8]=186; grid2[18][8]=186; grid2[19][8]=186;
            grid2[18][6]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][8]==' ')&&(check_left_right(16,8,21,21,grid2))){
            grid2[17][8]=186; grid2[18][8]=186; grid2[19][8]=186;
            grid2[18][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][12]==' ')&&(check_left_right(0,12,21,21,grid2))){
            grid2[1][12]=186; grid2[2][12]=186; grid2[3][12]=186;
            grid2[2][10]=50; grid2[2][14]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][12]==' ')&&(check_left(0,12,21,21,grid2))){
            grid2[1][12]=186; grid2[2][12]=186; grid2[3][12]=186;
            grid2[2][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][12]==' ')&&(check_left_right(0,12,21,21,grid2))){
            grid2[1][12]=186; grid2[2][12]=186; grid2[3][12]=186;
            grid2[2][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][12]==' ')&&(check_left_right(4,12,21,21,grid2))){
            grid2[5][12]=186; grid2[6][12]=186; grid2[7][12]=186;
            grid2[6][10]=50; grid2[6][14]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][12]==' ')&&(check_left(4,12,21,21,grid2))){
            grid2[5][12]=186; grid2[6][12]=186; grid2[7][12]=186;
            grid2[6][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][12]==' ')&&(check_left(4,12,21,21,grid2))){
            grid2[5][12]=186; grid2[6][12]=186; grid2[7][12]=186;
            grid2[6][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][12]==' ')&&(check_left_right(8,12,21,21,grid2))){
           grid2[9][12]=186; grid2[10][12]=186; grid2[11][12]=186;
           grid2[10][10]=50; grid2[10][14]=50;
           nuOfmoves--;
           compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[10][12]==' ')&&(check_left_right(8,12,21,21,grid2))){
           grid2[9][12]=186; grid2[10][12]=186; grid2[11][12]=186;
           grid2[10][10]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[10][12]==' ')&&(check_left_right(8,12,21,21,grid2))){
           grid2[9][12]=186; grid2[10][12]=186; grid2[11][12]=186;
           grid2[10][14]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[14][12]==' ')&&(check_left_right(12,12,21,21,grid2))){
            grid2[13][12]=186; grid2[14][12]=186; grid2[15][12]=186;
            grid2[14][10]=50; grid2[14][14]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][12]==' ')&&(check_left_right(12,12,21,21,grid2))){
            grid2[13][12]=186; grid2[14][12]=186; grid2[15][12]=186;
            grid2[14][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][12]==' ')&&(check_left_right(12,12,21,21,grid2))){
           grid2[13][12]=186; grid2[14][12]=186; grid2[15][12]=186;
           grid2[14][14]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[18][12]==' ')&&(check_left_right(16,12,21,21,grid2))){
            grid2[17][12]=186; grid2[18][12]=186; grid2[19][12]=186;
            grid2[18][10]=50; grid2[18][14]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][12]==' ')&&(check_left_right(16,12,21,21,grid2))){
            grid2[17][12]=186; grid2[18][12]=186; grid2[19][12]=186;
            grid2[18][10]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][12]==' ')&&(check_left_right(16,12,21,21,grid2))){
            grid2[17][12]=186; grid2[18][12]=186; grid2[19][12]=186;
            grid2[18][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][16]==' ')&&(check_left_right(0,16,21,21,grid2))){
            grid2[1][16]=186; grid2[2][16]=186; grid2[3][16]=186;
            grid2[2][14]=50; grid2[2][18]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][16]==' ')&&(check_left(0,16,21,21,grid2))){
            grid2[1][16]=186; grid2[2][16]=186; grid2[3][16]=186;
            grid2[2][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[2][16]==' ')&&(check_right(0,16,21,21,grid2))){
            grid2[1][16]=186; grid2[2][16]=186; grid2[3][16]=186;
            grid2[2][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][16]==' ')&&(check_left_right(4,16,21,21,grid2))){
           grid2[5][16]=186; grid2[6][16]=186; grid2[7][16]=186;
           grid2[6][14]=50; grid2[6][18]=50;
           nuOfmoves--;
           compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[6][16]==' ')&&(check_left(4,16,21,21,grid2))){
           grid2[5][16]=186; grid2[6][16]=186; grid2[7][16]=186;
           grid2[6][14]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[6][16]==' ')&&(check_right(4,16,21,21,grid2))){
           grid2[5][16]=186; grid2[6][16]=186; grid2[7][16]=186;
           grid2[6][18]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[10][16]==' ')&&(check_left_right(8,16,21,21,grid2))){
            grid2[9][16]=186; grid2[10][16]=186; grid2[11][16]=186;
            grid2[10][14]=50; grid2[10][18]=50;
            nuOfmoves--;
            compscore=compscore+2;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][16]==' ')&&(check_left(8,16,21,21,grid2))){
            grid2[9][16]=186; grid2[10][16]=186; grid2[11][16]=186;
            grid2[10][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][16]==' ')&&(check_right(8,16,21,21,grid2))){
            grid2[9][16]=186; grid2[10][16]=186; grid2[11][16]=186;
            grid2[10][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][16]==' ')&&(check_left_right(12,16,21,21,grid2))){
            grid2[13][16]=186; grid2[14][16]=186; grid2[15][16]=186;
            grid2[14][14]=50; grid2[14][18]=50;
            nuOfmoves--;
            compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][16]==' ')&&(check_left(12,16,21,21,grid2))){
            grid2[13][16]=186; grid2[14][16]=186; grid2[15][16]=186;
            grid2[14][14]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if(((grid2[14][16]==' ')&&(check_right(12,16,21,21,grid2)))){
            grid2[13][16]=186; grid2[14][16]=186; grid2[15][16]=186;
            grid2[14][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][16]==' ')&&(check_left_right(16,16,21,21,grid2))){
        grid2[17][16]=186; grid2[18][16]=186; grid2[19][16]=186;
           grid2[18][14]=50; grid2[18][18]=50;
           nuOfmoves--;
           compscore=compscore+2;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[18][16]==' ')&&(check_left(16,16,21,21,grid2))){
           grid2[17][16]=186; grid2[18][16]=186; grid2[19][16]=186;
           grid2[18][14]=50;
           nuOfmoves--;
           compscore++;
          moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
           continue;}

else if((grid2[18][16]==' ')&&(check_right(16,16,21,21,grid2))){
           grid2[17][16]=186; grid2[18][16]=186; grid2[19][16]=186;
           grid2[18][18]=50;
           nuOfmoves--;
           compscore++;
           moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
          continue;}

else if((grid2[2][20]==' ')&&(check_left(0,20,21,21,grid2))){
            grid2[1][20]=186; grid2[2][20]=186; grid2[3][20]=186;
            grid2[2][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[6][20]==' ')&&(check_left(4,20,21,21,grid2))){
            grid2[5][20]=186; grid2[6][20]=186; grid2[7][20]=186;
            grid2[6][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[10][20]==' ')&&(check_left(8,20,21,21,grid2))){
            grid2[9][20]=186; grid2[10][20]=186; grid2[11][20]=186;
            grid2[10][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[14][20]==' ')&&(check_left(12,20,21,21,grid2))){
            grid2[13][20]=186; grid2[14][20]=186; grid2[15][20]=186;
            grid2[14][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if((grid2[18][20]==' ')&&(check_left(16,20,21,21,grid2))){
            grid2[17][20]=186; grid2[18][20]=186; grid2[19][20]=186;
            grid2[18][18]=50;
            nuOfmoves--;
            compscore++;
            moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
            continue;}

else if(grid2[0][1]==' '){grid2[0][1]=205;grid2[0][2]=205;grid2[0][3]=205;}  ///point 1,2

else if(grid2[1][0]==' '){grid2[1][0]=186;grid2[2][0]=186;grid2[3][0]=186;}  ///point 1,7

else if(grid2[4][1]==' '){grid2[4][1]=205;grid2[4][2]=205;grid2[4][3]=205;}  ///point 7,8

else if(grid2[1][4]==' '){grid2[1][4]=186;grid2[2][4]=186;grid2[3][4]=186;}  ///point 2,8

else if(grid2[4][5]==' '){grid2[4][5]=205;grid2[4][6]=205;grid2[4][7]=205;}  ///point 8,9

else if(grid2[12][5]==' '){grid2[12][5]=205;grid2[12][6]=205;grid2[12][7]=205;}  ///point 20,21

else if(grid2[5][4]==' '){grid2[5][4]=186;grid2[6][4]=186;grid2[7][4]=186;}  ///point 8,14

else if(grid2[9][8]==' '){grid2[9][8]=186;grid2[10][8]=186;grid2[11][8]=186;}  ///point 15,21

else if(grid2[9][4]==' '){grid2[9][4]=186;grid2[10][4]=186;grid2[11][4]=186;}  ///point 14,20

else if(grid2[5][8]==' '){grid2[5][8]=186;grid2[6][8]=186;grid2[7][8]=186;}  ///point 9,15

else if(grid2[8][5]==' '){grid2[8][5]=205;grid2[8][6]=205;grid2[8][7]=205;}  ///point 14,15

else if(grid2[0][5]==' '){grid2[0][5]=205;grid2[0][6]=205;grid2[0][7]=205;}  ///point 2,3

else if(grid2[1][8]==' '){grid2[1][8]=186;grid2[2][8]=186;grid2[3][8]=186;}  ///point 3,9

else if(grid2[8][17]==' '){grid2[8][17]=205;grid2[8][18]=205;grid2[8][19]=205;}  ///point 17,18

else if(grid2[16][17]==' '){grid2[16][17]=205;grid2[16][18]=205;grid2[16][19]=205;}  ///point 29,30

else if(grid2[9][16]==' '){grid2[9][16]=186;grid2[10][16]=186;grid2[11][16]=186;}  ///point 17,23

else if(grid2[13][20]==' '){grid2[13][20]=186;grid2[14][20]=186;grid2[15][20]=186;}  ///point 24,30

else if(grid2[13][16]==' '){grid2[13][16]=186;grid2[14][16]=186;grid2[15][16]=186;}  ///point 23,29

else if(grid2[9][20]==' '){grid2[9][20]=186;grid2[10][8]=186;grid2[11][20]=186;}  ///point 18,24

else if(grid2[12][17]==' '){grid2[12][17]=205;grid2[12][18]=205;grid2[12][19]=205;}  ///point 23,24

else if(grid2[0][13]==' '){grid2[0][13]=205;grid2[0][14]=205;grid2[0][15]=205;}  ///point 4,5

else if(grid2[4][9]==' '){grid2[4][9]=205;grid2[4][10]=205;grid2[4][11]=205;}  ///point 9,10

else if(grid2[1][16]==' '){grid2[1][16]=186;grid2[2][16]=186;grid2[3][16]=186;}  ///point 5,11

else if(grid2[0][9]==' '){grid2[0][9]=205;grid2[0][10]=205;grid2[0][11]=205;}  ///point 3,4

else if(grid2[4][13]==' '){grid2[4][13]=205;grid2[4][14]=205;grid2[4][15]=205;}  ///point 10,11

else if(grid2[1][12]==' '){grid2[1][12]=186;grid2[2][12]=186;grid2[3][12]=186;}  ///point 4,10

else if(grid2[20][5]==' '){grid2[20][5]=205;grid2[20][6]=205;grid2[20][7]=205;}  ///point 32,33

else if(grid2[13][4]==' '){grid2[13][4]=186;grid2[14][4]=186;grid2[15][4]=186;}  ///point 20,26

else if(grid2[17][4]==' '){grid2[17][4]=186;grid2[18][4]=186;grid2[19][4]=186;}  ///point 26,32

else if(grid2[16][5]==' '){grid2[16][5]=205;grid2[16][6]=205;grid2[16][7]=205;}  ///point 26,27

else if(grid2[20][9]==' '){grid2[20][9]=205;grid2[20][10]=205;grid2[20][11]=205;}  ///point 33,34

else if(grid2[17][16]==' '){grid2[17][16]=186;grid2[18][16]=186;grid2[19][16]=186;}  ///point 29,35

else if(grid2[16][13]==' '){grid2[16][13]=205;grid2[16][14]=205;grid2[16][15]=205;}  ///point 28,29

else if(grid2[20][13]==' '){grid2[20][13]=205;grid2[20][14]=205;grid2[20][15]=205;}  ///point 34,35

else if(grid2[16][9]==' '){grid2[16][9]=205;grid2[16][10]=205;grid2[16][11]=205;}  ///point 27,28

else if(grid2[17][12]==' '){grid2[17][12]=186;grid2[18][12]=186;grid2[19][12]=186;}  ///point 28,34

else if(grid2[12][9]==' '){grid2[12][9]=205;grid2[12][10]=205;grid2[12][11]=205;}  ///point 21,22

else if(grid2[13][12]==' '){grid2[13][12]=186;grid2[14][12]=186;grid2[15][12]=186;}  ///point 22,28

else if(grid2[12][13]==' '){grid2[12][13]=205;grid2[12][14]=205;grid2[12][15]=205;}  ///point 22,23

else if(grid2[8][9]==' '){grid2[8][9]=205;grid2[8][10]=205;grid2[8][11]=205;}  ///point 15,16

else if(grid2[9][12]==' '){grid2[9][12]=186;grid2[10][12]=186;grid2[11][12]=186;}  ///point 16,22

else if(grid2[8][13]==' '){grid2[8][13]=205;grid2[8][14]=205;grid2[8][15]=205;}  ///point 16,17

else if(grid2[13][0]==' '){grid2[13][0]=186;grid2[14][0]=186;grid2[15][0]=186;}  ///point 19,25

else if(grid2[20][1]==' '){grid2[20][1]=205;grid2[20][2]=205;grid2[20][3]=205;}  ///point 31,32

else if(grid2[12][1]==' '){grid2[12][1]=205;grid2[12][2]=205;grid2[12][3]=205;}  ///point 19,20

else if(grid2[16][1]==' '){grid2[16][1]=205;grid2[16][2]=205;grid2[16][3]=205;}  ///point 25,26

else if(grid2[17][0]==' '){grid2[17][0]=186;grid2[18][0]=186;grid2[19][0]=186;}  ///point 25,31

else if(grid2[0][17]==' '){grid2[0][17]=205;grid2[0][18]=205;grid2[0][19]=205;}  ///point 5,6

else if(grid2[5][16]==' '){grid2[5][16]=186;grid2[6][16]=186;grid2[7][16]=186;}  ///point 11,17

else if(grid2[5][12]==' '){grid2[5][12]=186;grid2[6][12]=186;grid2[7][12]=186;}  ///point 10,16

else if(grid2[5][20]==' '){grid2[5][20]=186;grid2[6][8]=186;grid2[7][20]=186;}  ///point 12,18

else if(grid2[4][17]==' '){grid2[4][17]=205;grid2[4][18]=205;grid2[4][19]=205;}  ///point 11,12

else if(grid2[1][20]==' '){grid2[1][20]=186;grid2[2][20]=186;grid2[3][20]=186;}  ///point 6,12

else if(grid2[5][0]==' '){grid2[5][0]=186;grid2[6][0]=186;grid2[7][0]=186;}  ///point 7,13

else if(grid2[8][1]==' '){grid2[8][1]=205;grid2[8][2]=205;grid2[8][3]=205;}  ///point 13,14

else if(grid2[9][0]==' '){grid2[9][0]=186;grid2[10][0]=186;grid2[11][0]=186;}  ///point 13,19

else if(grid2[17][20]==' '){grid2[17][20]=186;grid2[18][20]=186;grid2[19][20]=186;}  ///point 30,36

else if(grid2[20][17]==' '){grid2[20][17]=205;grid2[20][18]=205;grid2[20][19]=205;}  ///point 35,36

else if(grid2[17][8]==' '){grid2[17][8]=186;grid2[18][8]=186;grid2[19][8]=186;}  ///point 27,33

else if(grid2[13][8]==' '){grid2[13][8]=186;grid2[14][8]=186;grid2[15][8]=186;}  ///point 21,27


   else{
         SetColor(6);
         printf("Invalid\n");
         continue;
    }
         nuOfmoves--;
         moves_2++;
            system("cls");
            print_grid(21,21,grid2,name1,score1,moves_1,compname,compscore,moves_2,nuOfmoves);
         break;
    }
}
SetColor(15);
printf("GAME ENDED");
if(score1>compscore)
{   SetColor(5);
    printf("congratulation player 1 is the winner\n");
}
else if(score1<compscore)
{
    SetColor(12);
    printf("Computer is the winner\n");
}
else {
    SetColor(11);
    printf("The game is draw\n");
}
SetColor(15);
printf("enter 1 to return to main menu\n enter 2 to exit\n");
int U;
scanf("%d",&U);
if(U==1){ goto Label1;}
else{exit(0);}

  }


}
