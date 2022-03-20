#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
  void login()
  { 
    int a=0,i=0;
    char uname[10],c='character';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
    { 
        printf("\n*********************************LOGIN***********************************************");
		printf("\n\n             ENTER USER NAME:-  ");
		scanf("%s",&uname);
		printf("\n\n             ENTER PASSWORD:-   ");
		  while(i<1)
		  { 
		    pword[i]=getch();
		    c=pword[i];
		    if(c==13)
		     break;
		    else 
		     printf("*");
			 i++;
 		  }
 		      pword[i]='\0';
 		      i=0;
 		      if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
 		    {
 		    	printf("\n\n\nWELCOME TO BOOKING PORTAL!!!\n LOGIN SUCCESSFUL");
 		    	printf("press any key to continue.......");
 		    	getch();
 		    	break;
			 }
	     }
	           while(a<3);
	           if(a>2)
	             {
				   printf("\nSorry you have entered the wrong user name and password for four times!!!");
				   getch();
			     }
			       system("cls");
		}
		         struct book 
		         {
				   char code[20];
				   char name[20];
				   char date[20];
				   int cost;
			     }b;
			       int seat=50;
			        void insert_details();
			        void view_all();
			        void find();
			        void book_ticket();
			        void old_record();
			        
			        int main()
			        {
					  login();
					  int ch;
					   do
					    {
						   printf("\n*********************************************************************************");
						   printf("\n");
						   printf("\t MOVIE TICKET BOOKING");
						   printf("\n");
						   printf("\n*********************************************************************************");
						   printf("\nEnter 1 :- to insert movie");
						   printf("\nEnter 2 :- to view all movie");
						   printf("\nEnter 3 :- to find movie");
						   printf("\nEnter 4 :- to book tickets");
						   printf("\nEnter 5 :- to view transactions");
						   printf("\nEnter 0 :- to exit");
						   printf("Enter your choice:");
						   scanf(":%d",&ch);
						     system("cls");
						     switch(ch)
						     {
							  case 1:
							  	insert_details();
						      break;
						      case 2:
						      	view_all();
						      break;
						      case 3:
						      	find();
						      break;
						      case 4:
						        book_ticket();
						      break;
						      case 5:
						      	old_record();
						      break;
						      case 0:
						      	exit(0);
						      break;
						      default:
						      printf("wrong choice");
						      break;
						}
					}
					  while(ch!=0);
				}
				   void insert_details()
				   {
				      FILE *fp;
				      struct book b;
				      printf("Enter movie code:-");
				      scanf("%s",b.code);
				      printf("Enter name:-");
				      scanf("%s",b.name);
				      printf("Enter release date:-");
				      scanf("%s",b.date);
				      printf("Enter ticket price:-");
				      scanf("%d",&b.cost);
			           fp=fopen("data.txt","a");
					    if(fp==NULL)	
					{
					   printf("File not found");
				}
				else
				  {
				  	fprintf(fp,"%s     %s      %s         %d\n",b.code,b.name,b.date,b.cost);
				  	printf("Recorded successfully");
				}
				  printf("\n");
				  fclose(fp);
				  system("cls");
			}
			    void find()
			    {
				  struct book b;
				  FILE *fp;
				  char ch[20];
				  printf("Enter movie code:");
				  scanf("%s",&ch);
				fp=fopen("data.txt","r");
				if(fp==NULL)
				{
				  printf("file does not exist");
				  exit(1);
			    }
			    else
			    {
			      while(getc(fp)!=EOF)
				  {
					fscanf(fp,"%s  %s   %s    %d",b.code,b.name,b.date,&b.cost);
					if(strcmp(b.code,ch)==0)
					 {
					   printf("\n Record found");
					   printf("\n\t\tcode::%s",b.code);
					   printf("\n\t\tmovie name::%s",b.name);
					   printf("\n\t\tmovie date::%s",b.date);
					   printf("\n\t\tprice of a ticket::%d",b.cost);
				}
			}
		}
		            fclose(fp);
		            system("cls");
		        }
		        void view_all()
		        {
				  char ch;
				  FILE *fp;
				  fp=fopen("data.txt","r");
				  if(fp==NULL)
                  {
				  printf("files does not exist");
				  exit(1);
			      }
			        else
			        {
			        	system("cls");
			        	while((ch=fgetc(fp))!=EOF)
			        	printf("%c",ch);
					}
				       fclose(fp);
				   }
				     void book_ticket()
				     {
					   struct book b;
					   FILE *fp;
					   FILE *ufp;
					   int total_seat,mobile,total_amount;
					   char name[20];
					   char ch;
					   char movie_code[20];
					   fp=fopen("data.txt","r");
					   if(fp==NULL)
					   {
					   	 printf("file does not exist");
					   	 exit(1);
					   }
					    else
					    {
					    	system("cls");
					    	while((ch=fgetc(fp))!=EOF)
					    	printf("%c",ch);
						}
						  fclose(fp);
						  printf("\n For booking ticket choice movie(Enter Movie code first letter of movie)\n");
						    printf("\n Enter movie code:");
						    scanf("%s",movie_code);
						    fp=fopen("data.txt","r");
						     if(fp==NULL)
						      {
						      	printf("file is not found");
						      	exit(1);
							  }
							    else
							    {
								   while(getc(fp)!=EOF)
								   {
								     fscanf(fp,"%s     %s    %s     %d",b.code,b.name,b.date,&b.cost);
								     if(strcmp(b.code,movie_code)==0)
								     {
									 printf("\n   Record Found");
									 printf("\n\t\t code::%s",b.code);
									 printf("\n\t\tmovie name::%s",b.date);
									 printf("\n\t\tdate ::%s",b.date);
									 printf("\n\t\tprice of ticket::%d",b.cost);
								}
							}
						}
						           printf("\n*** FILL DETAILS ***");
								   printf("\n your name:");
								   scanf("%s",&name);
								   printf("\n mobile number:");
								   scanf("%d",&mobile);
								   printf("\n Total number of tickets:");
								   scanf("%d",&total_seat);
								   total_amount=b.cost*total_seat;
								   printf("\n ENJOY THE MOVIE");
								   printf("\n\t\tname:%s",name);
								   printf("\n\t\tmobile number:%d",mobile);
								   printf("\n\t\tmovie name:%s",name);
								   printf("\n\t\ttotal seats:%d",total_seat);
								   printf("\n\t\tcost per ticket:%d",b.cost);
								   printf("\n\t\total amount:%d",total_amount);
								   ufp=fopen("old transcation.txt","a");
								   if(ufp==NULL)
								   {
								   	 printf("File not found");
									}
									else
									{
										fprintf(ufp,"%s   %d   %d   %d   %s     %d\n",name,mobile,total_seat,total_amount,b.name,b.cost);
										printf("\n Record insert successfull to the old record file");
									 }
									   printf("\n");
									   fclose(ufp);
									   fclose(fp);
								}
								  void old_record()
								  {
								  	char ch;
								  	FILE *fp;
								  	fp=fopen("old transaction.txt","r");
								  	if(fp==NULL)
								  	{
									  printf("file does not exist");
									  exit(1);
								  }
								  else
								  {
								    system("cls");
								    while((ch=fgetc(fp))!=EOF)
								    printf("%c",ch);
									}
									fclose(fp);
								}
