

//I made a login area can be used by school,that teaches student simple calculation .It also allow them to play a game name tictoe with friends when get bored



#include<stdio.h>

#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void gotoxy(int i,int j);//its a function used to move cursor on screeen
void login(void);//function for login
void signup(void);//its a function where a file is called to store a password and ID,its called when new user uses first time program
void clrscr (void);//to clear the screen
void product(void);//perform multiplication
void subtraction(void);
void division(void);
void add(void);
void tictoe(void);//a game in this function
int checkWin();//function used in game that is used to check all possibility of winning.
void drawBoard();
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

struct//struct :a kind variable in which more than 1 variable can be stored ,string variable for storage of password etc'
{
   
char password[20];
   
char username[20];
 } s;

FILE * fp;// its a predefine function in stdio.h,

void main () 
{
  system("color 5b");
int ch;
  
while (1)// a infinite loop exit when escape 

    
 {
      
gotoxy (2, 1);//function to move cursor on screen 
      
printf ("----------------------MATHLAND---------------------");
      
gotoxy (8, 2);
      
printf ("WELCOME TO MY MATHLAND");
      
gotoxy (8, 2.5);
      
printf ("PRINT 1 FOR LOG IN");
      
 
gotoxy (8, 3);
      
printf ("PRINT 2 FOR SIGNUP");
      
gotoxy (8, 3.5);
      
printf ("PRINT 3 FOR EXIT");
      
gotoxy (9, 4);
      
printf ("--------------------------********---------------------\n");
      

      
scanf("%d",&ch);

  
switch (ch)
	
	{
	
case 1:
	  
	  {
	    
clrscr ();// function made to clear screen
	    
gotoxy (1, 4);
	    

login ();
exit(0);//tells the processor that we completed succesfully
	    
break;
	  
}
	
case 2:
	  
	  {
	    
clrscr ();
	    
gotoxy (10, 14);
	    

signup ();
	    
break;
	  
}
	
case 3:
	  
	  {
	    exit (0);
	    
         break;
	  }
	
 
}
    
 
}
  
getchar ();
  
 
 


}


void signup() 
{
  
char c;
  
fp = fopen ("record.bin", "ab");//file is opened ,two parameters given address of file where we store our enterd data and second parameter mode
  
clrscr ();
  
gotoxy (1, 2);
  
printf
    ("-\t\t\t\t\t--------SIGN UP ZONE ------------\n\t\t\t\t\tFOR  \n\t\t\t\t-------------MATHLAND-----------------");
  
gotoxy (1, 3);
  
printf ("ENTER THE USERNAME:");
  
scanf ("%s",&s.username);
  
gotoxy (1, 4);
  
     printf ("PASSWORD");
  
      scanf("%s",&s.password);
      gotoxy (1, 5);
  
  

      
     fwrite (&s ,sizeof(s),1,(fp));//data stored in our file
      
     printf ("INFORMATION SAVED...\n");
    

  
    
     return;
  
        fclose (fp);//file close
  
         getchar ();

}


void clrscr (void) 
{
  int i=0;
for (i==0;i < 10; i++)
{

    
printf ("\n");
}

} 
 
 
void gotoxy (int i, int j) //i is column j is rows
{
  int o = 0, p = 0;
  
for (; p <= j; p++)
    
    {
      printf ("\n");
    
    }
  
for (; o <= i; o++)
    
    {
      printf (" ");
    
    }

 
}
void login()
{gotoxy(3,4);
printf("MAKE SURE YOU HAVE AN EXISTING ACCOUNT\n");
   
    
    
    
    
    int i;
     char c;
     char chkp; 
     char chku;
     char pass[20];
     char username[20];
     clrscr();
     gotoxy(3,5);
     printf("-------login Area------------------\n");
      gotoxy(3,7);
      fp=fopen("record.bin","rb");//file opened where the password and ID SAVED.
      printf("ENTER THE USER NAME:");
      scanf("%s", &username);
      gotoxy(3,9);
      printf("ENTER THE PASSWORD");
      
          scanf("%s",&pass);
       
      while(!feof(fp))//file end function
      {
          fread(&s, sizeof(fp) , 1 ,fp);
          chku=strcmp(username,s.username );//string comparison function used to compare user password and ID
          chkp=strcmp(pass,s.password);
          if(chku==0 & chkp!=0)
          { printf("INCORRECT PASSWORD !!!!!!");
            break;
          
          }
          else if (chku!=0 &chkp==0)
          {  printf("INVALID USERNAME!!!!!");
              break;
          }
          else(chku==0 & chkp==0);
          {
              clrscr();
              gotoxy(2,1);
              printf("--------WELCOME TO YOUR MATHLAND ----------\n----------------LEARN SOME MATHS FOR FUN---------\n ");
              printf("KEEP YOUR PASSWORD SAVE\n");
              
                  {
                 	printf("Enter -1 to end\n");
                 	srand(time(NULL));
                 		printf("Enter: 1 for addition, 2 for subtraction\n");
		printf("Enter: 3 for multiplication, \n");
		printf("Enter: 4 for division\n ");
		printf("Enter : 5 for playing game if you are bored\n");
		printf("? ");
		int choice=0;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			clrscr();
			add();//function add called
			break;
		case 2:
			clrscr();
			subtraction();//function called for subtraction
			break;
		case 3:
			clrscr();
			product();//function called for multiplication
		case 4:
			clrscr();
			division();//function called for division
			break;
		case 5:
				{
					tictoe();//function called where gaming command is stored
				}
		}
                   	printf("That's all for now .Bye.");
                  	getchar();
                  }

              
              
              break;
          }
          
      }
      getchar();
      
      
}
 void product(void)
{
	int x, y, z, numb = 0;
	while (numb != -1)
	{
		x = rand() % 10;//random number generattion
		y = rand() % 10;
		z = x*y;
		printf("How much %d times %d?", x, y);
		while (numb != -1)
		{
			scanf("%d", &numb);
			if (numb == z)
			{
				printf("Very good!\n");
				break;
			}
			else if (numb != z && numb != -1)
			{
				printf("No,Please Try Again\n");
			}
		}
	}
}
 void add(void)
{system("color 3d");
	int x, y, z, numb = 0;
	while (numb != -1)
	{
		x = rand() % 10;//random number generattion
		y = rand() % 10;
		z = x+y;
		printf("How much %d add %d?", x, y);
		while (numb != -1)
		{
			scanf("%d", &numb);
			if (numb == z)
			{
				printf("Very good!\n");
				break;
			}
			else if (numb != z && numb != -1)
			{
				printf("No,Please Try Again\n");
			}
		}
	}
}
 void subtraction(void)
{system("color 6d");
	int x, y, z, numb = 0;
	while (numb != -1)
	{
		x = rand() % 10;//random number generattion
		y = rand() % 10;
		z = x-y;
		printf("How much %d subtract %d?", x, y);
		while (numb != -1)
		{
			scanf("%d", &numb);
			if (numb == z)
			{
				printf("Very good!\n");
				break;
			}
			else if (numb != z && numb != -1)
			{
				printf("No,Please Try Again\n");
			}
		}
	}
}
 
void division(void)
{system("color 4d");//chaNGES COLOR
	int x, y, z, numb = 0;
	while (numb != -1)
	{
		x = rand() % 10;
		y = rand() % 10;
		z = x/y;
		printf("How much %d times %d?", x, y);
		while (numb != -1)
		{
			scanf("%d", &numb);
			if (numb == z)
			{
				printf("Very good!\n");
				break;
			}
			else if (numb != z && numb != -1)
			{
				printf("No,Please Try Again\n");
			}
		}
	}
}
void tictoe()
{
	system("color 3d");//command that is used to change the color of the text and background
	int player = 1, i ,choice;
	char mark; // X,O
	do {
		drawBoard();
		player = (player % 2) ? 1 : 2;
		printf("Player %d, enter the choice : ",player);
		scanf("%d",&choice);
		mark = (player == 1) ? 'X' : 'O';
		if(choice == 1 && square[1] == '1')
			square[1] = mark;
		else if(choice == 2 && square[2] == '2')
			square[2] = mark;
			else if(choice == 3 && square[3] == '3')
			square[3] = mark;
			else if(choice == 4 && square[4] == '4')
			square[4] = mark;
			else if(choice == 5 && square[5] == '5')
			square[5] = mark;
			else if(choice == 6 && square[6] == '6')
			square[6] = mark;
			else if(choice == 7 && square[7] == '7')
			square[7] = mark;
			else if(choice == 8 && square[8] == '8')
			square[8] = mark;
			else if(choice == 9 && square[9] == '9')
			square[9] = mark;
			
			else {
				printf("Invalid option !");
				player--;
				getch();
			}
			i = checkWin();//function checkwin called everytime to check winner
			player++;	
		
	}while(i == -1);
	
	drawBoard();
	if(i==1){
		printf("==>Player %d won",--player);
	}
	else {
		printf("==>Game draw");
	}
		getch();
		
	
}
int checkWin(){
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if(square[7] == square[8] && square[8] == square[9])
		return 1;
	else if(square[1] == square[4] && square[4] == square[7])
		return 1;
	else if(square[2] == square[5] && square[5] == square[8])
		return 1;
	else if(square[3] == square[6] && square[6] == square[9])
		return 1;
	else if(square[1] == square[5] && square[5] == square[9])
		return 1;
	else if(square[3] == square[5] && square[5] == square[7])
		return 1;
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] !='4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else 
		return -1;	
}

void drawBoard(){//to draw the display page of game
	system("cls");
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
	printf("     |     |     \n");	
}


