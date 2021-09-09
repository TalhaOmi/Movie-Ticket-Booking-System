#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct book
{
char code[20];
char name[20];
char genre[20];
char date[20];
int cost;
} b;

int mainseat=60 ;


void id_pass();
void main2();
void main3();
void insert();
void view();
void transaction();
void book();
void find();
void find1();
void find2();
void find3();
void find4();
void feedback();
void viewfeed();


void main()
{
    system("color 9b ");
    int a;
    do{
        printf("\n\t\t\xDB\xDB\xDB\xDB\xB2WELCOME TO BLOCKBUSTER CINEMA HALL SYSTEM\xDB\xDB\xDB\xDB\xB2\n");

        printf("\n\t\xDB\xDB\xDB\xDB\xB2<1>Admin\n");
        printf("\n\t\xDB\xDB\xDB\xDB\xB2<2>Customer\n");
        printf("\n\t\xDB\xDB\xDB\xDB\xB2<0>Exit\n");
        printf("\n\n Enter your choice:  ");
        scanf("%d",&a);

        switch(a)
        {
             case 1:
               id_pass();
               break;
             case 2:
               main3();
               break;
             case 0:
               exit(0);
               break;
        }getch();
    }while(a>0);
}

void id_pass()
{
    system("color 4b");
    char password[100];
    int given_id=777;
    fflush(stdin);
    char pas[]="777";
    fflush(stdin);
    int len,m=0,m1;
    len=strlen(pas);
    int i,j,id,count=0;
    char ch;
    jump:
    printf("ENTER ID      ::");
    scanf("%d",&id);
    fflush(stdin);

  printf("ENTER PASSWORD   :: ");
   for(i=0;i<100;i++)
   {
       ch=getch();

       if (ch==13)
       {

           break;
       }
       else if (ch==8)
       {
           printf("\b \b");
       }
       else
       {

       password[i]=ch;
       printf("*");
       }

       fflush(stdin);
   }
    printf("\n");

    if (strcmp(password,pas)==0)
     {
        ++count ;
     }
     else if (strcmp(password,pas)!=0)
     {
        count=0 ;

    }

    fflush(stdin);
    if (id==given_id && count>0)
    {
        printf("\n\tPassword granted:\n\n");
        printf("\n\tLOGIN SUCCESFULLY\n\n");
        printf("\n");
        main2();
    }
    else if(id!=given_id || count==0)
    {
      printf("\nWrong Id or Password::\n");
      fflush(stdin);
      printf("\nPress<0>To go main window::\n");
      printf("\nPress<1>To try again::\n");
      scanf("%d",&m1);
      if(m==m1)
        main();
      else if(m1==1)
       id_pass() ;
    }
    getch();
}




void  main2()
{
    system("color 4b");
  int a ;

  do{

  printf("\xDB\xDB\xDB\xDB\xB2 Press<1> To insert Movie           ::\n");
  printf("\xDB\xDB\xDB\xDB\xB2 Press<2> To view Movie             ::\n");
  printf("\xDB\xDB\xDB\xDB\xB2 Press<3> To find Movie             ::\n");
  printf("\xDB\xDB\xDB\xDB\xB2 Press<4> To view all Transaction   ::\n");
  printf("\xDB\xDB\xDB\xDB\xB2 Press<5> To view all Feedback      ::\n");
  printf("\xDB\xDB\xDB\xDB\xB2 Press<6> To go main Window         ::\n");
  printf("\xDB\xDB\xDB\xDB\xB2 Press<0> To Exit                   ::\n");

  printf("\n\n Enter your choice::\n");
  scanf("%d",&a);

  switch(a)
  {
   case 1:
       insert();
       break;
   case 2:
       view();
       break;
    case 3:
        find();
        break;
   case 4:
        transaction();
        break;
   case 5:
        viewfeed();
        break;
   case 6:
         main();
         break;
   case 0:
         exit(0);
         break;
   default:
    printf("\t\nInvalid Option FOR This System\t\n");
    printf("\n");
    main2();

  }getch();

  }while(a>0);
}

void  main3()
{
    system("color 3b");
    int a ;

  do{
  printf("\n\t\t\xDB\xDB\xDB\xDB\xB2WELCOME TO BLOCKBUSTER CINEMA HALL\xDB\xDB\xDB\xDB\xB2\n");

  printf("\n\t\xDB\xDB\xDB\xDB\xB2Press<1> To view movie             ::\n");
  printf("\n\t\xDB\xDB\xDB\xDB\xB2Press<2> To find movie             ::\n");
  printf("\n\t\xDB\xDB\xDB\xDB\xB2Press<3> To book ticket            ::\n");
  printf("\n\t\xDB\xDB\xDB\xDB\xB2Press<4> To  give feedback         ::\n");
  printf("\n\t\xDB\xDB\xDB\xDB\xB2Press<5> To go main window         ::\n");
  printf("\n\t\xDB\xDB\xDB\xDB\xB2Press<0> To exit                   ::\n");

  printf("\n\n Enter your choice::\n");
  scanf("%d",&a);

  switch(a)
  {
   case 1:
       view();
       break;
    case 2:
        find();
        break;
   case 3:
        book();
        break;
    case 4:
        feedback();
        break;
   case 5:
        main();
   case 0:
        exit(0);
   default:
         printf("Invalid choice\n\n");
         main3();
         break;
}getch();
  }while(a!=0);
}

void insert()
{
    system("color 4b");
FILE *fp ;
struct book b;
printf("\n\t***** Enter all information *******\n");

printf("\nEnter Movie code             ::\n");
scanf("%s",b.code);
printf("\nEnter Movie name[first_last] ::\n");
scanf("%s",b.name);
printf("\nEnter Movie Genre            ::\n");
scanf("%s",b.genre);
printf("\nEnter release date[dd-mm-yy] ::\n");
scanf("%s",b.date);
fflush(stdin);
printf("\nEnter ticket price           ::\n");
scanf("%d",&b.cost);
fp=fopen("SAVE1.txt","a"); // creating a file
if(fp == NULL)
	{
		printf("!!FILE DOES NOT EXIT ");
		main();
	}
	else
    {
fprintf(fp,"%s %s %s %s %d\n",b.code,b.name,b.genre,b.date,b.cost); // transfer data from ram to text file ;

printf("\n**MOVIE DATA INSERT SUCCESSFULLY**\n");
    }
    printf("\n");
fclose(fp); // closing the file ;
}


void find()
{
    system("color 6b");

printf("\nPress<1> To find movie via code            ::\n");
printf("\nPress<2> To find movie via name            ::\n");
printf("\nPress<3> To find movie via date            ::\n");
printf("\nPress<4> To find movie via genre           ::\n");
printf("\nPress<5> To find go main window            ::\n");
printf("\nPress<0> To exit                           ::\n");

int f;
printf("\n Enter your choice:\n");
scanf("%d",&f);
switch(f)
{
case 1:
    find1();
    break;
case 2:
    find2();
    break;
case 3:
    find3();
    break;
case 4:
    find4();
    break;
case 5:
    main();
    break;
case 0:
    exit(0);
    break;
default:
        printf("Wrong input\n\n");
        find();
        break;

}

}
void find1()
{
    system("color 6b");
    struct book b;
	FILE *fp;

	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("SAVE1.txt","r");
	if(fp == NULL)
	{
		printf("!!NO MOVIE DATA FOUND!");
		main();

	}
	else
	{


			while(fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.genre,b.date,&b.cost)!=EOF)
            {


			if(strcmp(b.code,ch) == 0)
			{
				printf("\n**MOVIE DATA FOUND**\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie genre ::%s",b.genre);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d\n",b.cost);
				break;
			}

		}

	}

	fclose(fp);

}
void find2()
{
    system("color 6b");

    struct book b;
    char ch[20];
	FILE *fp;


	printf("Enter movie name[first_last]:");
    scanf("%s",ch);
	fp = fopen("SAVE1.txt","r");
	if(fp == NULL)
	{
		printf("!!NO MOVIE DATA FOUND");
		main();

	}
	else
	{


			while(fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.genre,b.date,&b.cost)!=EOF)
            {


			if(strcmp(b.name,ch) == 0)
			{
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n**MOVIE DATA FOUND**\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie genre ::%s",b.genre);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d\n",b.cost);
				break;
			}



		}

	}

	fclose(fp);
}
void find3()
{
    system("color 6b");

    struct book b;
	FILE *fp;

	char ch[20];
	printf("Enter movie released date[dd-mm-yy]  :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("SAVE1.txt","r");
	if(fp == NULL)
	{
		printf("!!NO MOVIE DATA FOUND");
		main();

	}
	else
	{
			while(fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.genre,b.date,&b.cost)!=EOF)

            {

			if(strcmp(b.date,ch) == 0)
			{
			    printf("\n**MOVIE DATA FOUND**\n");
			    do{


				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie genre ::%s",b.genre);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d\n",b.cost);
				break;
			    }
			    while(fscanf(fp,"%s",b.date)!=EOF);

			}



            }

		}

	fclose(fp);
}


void find4()
{
    system("color 6b");

    struct book b;
	FILE *fp;

	char ch[20];
	printf("Enter movie genre :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("SAVE1.txt","r");
	if(fp == NULL)
	{
		printf("!!NO MOVIE DATA FOUND");
		main();

	}
	else
	{
			while(fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.genre,b.date,&b.cost)!=EOF)

            {

			if(strcmp(b.genre,ch) == 0)
			{
			  printf("\nMOVIE DATA FOUND::\n");
			    do{


				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie genre ::%s",b.genre);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d\n",b.cost);
				break;
			    }
			    while(fscanf(fp,"%s",b.genre)!=EOF);
			}


            }

		}

	fclose(fp);
}

void view()
{
    system("color 6b");

    char ch;
    FILE *fp;
    fp=fopen("SAVE1.txt","r");
    if(fp==NULL)
    {
       printf("!!FILE DOES NOT EXIT\n");
       main();
    }
    else
    {
    printf(" \nCODE--NAME--GENER--DATE--PRICE\n");
    printf("\n");
        while((ch = fgetc(fp))!=EOF)
        {
        printf("%c",ch);
        }
    }
    fclose(fp);
}
void book()
{
    system("color 3b");

    struct book b;
    FILE *fp ;
    FILE *fp2 ;

    int total_seat,mobile,total_amount;
	char name[20];
	char ch; //used in display all movies
	char movie_code[20];//for searching


    view() ; // calling view to see all movie list
    //end of view

    printf("\n**For Movie Booking Choose a Movie**\n");
    printf("\nEnter Movie Code::\n");
    scanf("%s",movie_code);
    fp=fopen("SAVE1.txt","r");
    if(fp == NULL)
    {

        printf("!!FILE DOES NOT EXIT ");
        main();
    }
        else
	{


			while(fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.genre,b.date,&b.cost)!=EOF)
            {


			if(strcmp(b.code,movie_code) == 0)
			{
				printf("\nMOVIE DATA FOUND::\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie genre::%s",b.genre);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);


	printf("\n Fill Details:\n\n");
	printf("\n Enter your name::");
	scanf("%s",name);
	printf("\n Enter your mobile number::");
	scanf("%d",&mobile);
    printf("\n Enter total number of tickets::");
	scanf("%d",&total_seat);

    if(total_seat > 60)
    {
        printf(" seats are not available\n");
            main3();
    }
    else if (total_seat<=60 && total_seat > 0)
        {
            total_amount = total_seat * (int)(b.cost) ;
    printf("\t\n**Enjoy the movie***\n");

    printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tmovie genre : %s",b.genre);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d Taka ",total_amount);

	fp2=fopen("data2.txt","a");
	if(fp2 == NULL)
        printf("!!FILE DOES NOT EXIT ");
    else
    {
        fprintf(fp2,"%s %d %s %s %d %d \n\n",name,mobile,b.name,b.genre,b.cost,total_amount);
        printf("\n**Booking Record insert successfully**\n");
    }
    printf("\n");
    fclose(fp);
    fclose(fp2);
        }
			}
            }
	}

}
void transaction()
{
    system("color 4b");
	char ch;
	FILE *fp2;

	//system("clear");

	fp2 = fopen("data2.txt","r");
	if(fp2 == NULL)
	{
		printf("!!FILE DOES NOT EXIT\n");
		main();

	}
	else
	{
		//system("clear");
		while( ( ch = fgetc(fp2) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp2);
}

void feedback()
{
    system("color 3b");

    FILE *fp3 ;
    char code[20];
    int rating;
    char comment[100];
    int star;
    fp3=fopen("feedback.txt","a");
    view();

    printf("\nEnter Movie code for feedback                            ::\n");
    scanf("%s",code);
    printf("\nGive your rating about this movie[out of 5]              ::\n");
    scanf("%d",&rating);
    printf("\nGive a THUMBS [up OR down] for this movie                 ::\n");
    scanf("%s",comment);

    if(fp3 == NULL)
	{
		printf("!!FILE DOES NOT EXIT\n");
		main();
	}
	else
    {
fprintf(fp3,"%s %d %s\n",code,rating,comment); // transfer data from ram to text file ;

printf("\n**Feedback is given successfully**\n");
    }
    printf("\n");
fclose(fp3);

}

void viewfeed()
{
    system("color 4b");
	char ch;
	FILE *fp3;



	fp3 = fopen("feedback.txt","r");
	if(fp3 == NULL)
	{
		printf("!!file does not found\n");
		main();

	}
	else
	{
    printf(" \nCODE ---RATING---THUMBS::\n");
    printf("\n");

		while( ( ch = fgetc(fp3) ) != EOF )
      		printf("%c",ch);

	}

	fclose(fp3);
}
