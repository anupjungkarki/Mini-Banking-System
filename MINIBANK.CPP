#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
int i,j;
int main_exit;
void menu();
void close();
struct date{
    int month;
    int day;
    int year;

    };
struct emp {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}


void create()

{
    int choice;
    FILE *ptr;
    system("cls");
    setbkcolor(RED);
    ptr=fopen("record.dat","a+");
    account_no:
    printf("\t\t\t\ADD RECORD ");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
	if (check.acc_no==add.acc_no)
	    {printf("Account no. already in use!");

		goto account_no;

	    }
    }
    add.acc_no=check.acc_no;
	printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

	fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
      { system("cls");
	menu();
      }
    else if(main_exit==0)
	    close();
    else
	{
	    printf("\nInvalid!\a");
	    goto add_invalid;
	}
}
void list()
{
    FILE *view;

    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
	   printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
	   test++;
       }

    fclose(view);
    if (test==0)
	{   system("cls");
	    printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if (main_exit==1)
	  { system("cls");
	    menu();
	  }
	else if(main_exit==0)
	    close();
	else
	{
	    printf("\nInvalid!\a");
	    goto view_list_invalid;
	}
}
void updates()
{      system("cls");
   setbkcolor(BLUE);
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
	if (add.acc_no==upd.acc_no)
	{   test=1;
	    printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
	    scanf("%d",&choice);


	    if(choice==1)
		{printf("Enter the new address:");
		scanf("%s",upd.address);
		fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		system("cls");
		 setbkcolor(BLUE);
		printf("Changes saved!");
		}
	    else if(choice==2)
		{
		    printf("Enter the new phone number:");
		scanf("%lf",&upd.phone);
		fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		 system("cls");
		    setbkcolor(BLUE);
		printf("Changes saved!");
		}

	}
	else
	    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
	{   system("cls");
	    setbkcolor(BLUE);
	    printf("\nRecord not found!!\a\a\a");
	    edit_invalid:
	      printf("\nEnter 0 to try again\n1 to return to main menu\n2 to exit:");
	      scanf("%d",&main_exit);
	      system("cls");
		 if (main_exit==1)
		   { system("cls");
		    menu();
		   }
		else if (main_exit==2)
		    close();
		else if(main_exit==0)
		    updates();
		else
		    {printf("\nInvalid!\a");
		    goto edit_invalid;}
	}
    else
	{printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);

	system("cls");

	if (main_exit==1)
	    menu();
	else
	    close();
	}
}

void transact()
{   system("cls");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

	printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

	    if(add.acc_no==transaction.acc_no)
	    {   test=1;
		if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
		{
		    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
		    system("cls");
		    menu();

		}
		printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
		scanf("%d",&choice);
		if (choice==1)
		{
		    printf("Enter the amount you want to deposit:$ ");
		    scanf("%f",&transaction.amt);
		    add.amt+=transaction.amt;
		    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		    printf("\n\nDeposited successfully!");
		}
		else
		{
		    printf("Enter the amount you want to withdraw:$ ");
		    scanf("%f",&transaction.amt);
		    add.amt-=transaction.amt;
		    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		    printf("\n\nWithdrawn successfully!");
		}

	    }
	    else
	    {
	       fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	    }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
	{ system("cls");
	transact();
	}
    else if (main_exit==1)
       { system("cls");
	menu();
       }
    else if (main_exit==2)
	close();
    else
    {
	printf("\nInvalid!");
	goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if (main_exit==1)
	    { system("cls");
	    menu();
	    }
	else
	    close();
   }

}
void deletes()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
	if(add.acc_no!=rem.acc_no)
	    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

	else
	    {test++;
	    printf("\nRecord deleted successfully!\n");
	    }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
	{
	    printf("\nRecord not found!!\a\a\a");
	    erase_invalid:
	      printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	      scanf("%d",&main_exit);

		 if (main_exit==1)
		    menu();
		else if (main_exit==2)
		    close();
		else if(main_exit==0)
		    deletes();
		else
		    {printf("\nInvalid!\a");
		    goto erase_invalid;}
	}
    else
	{printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if (main_exit==1)
	    menu();
	else
	    close();
	}

}

void search()
{   system("cls");
  setbkcolor(BROWN);
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
	scanf("%d",&check.acc_no);

	while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
	    if(add.acc_no==check.acc_no)
	    {   system("cls");
	       setbkcolor(BROWN);
		test=1;

		printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
		add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		if(strcmpi(add.acc_type,"fixed1")==0)
		    {
			time=1.0;
			rate=9;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
		    }
		else if(strcmpi(add.acc_type,"fixed2")==0)
		    {
			time=2.0;
			rate=11;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

		    }
		else if(strcmpi(add.acc_type,"fixed3")==0)
		    {
			time=3.0;
			rate=13;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

		    }
		 else if(strcmpi(add.acc_type,"saving")==0)
		    {
			time=(1.0/12.0);
			rate=8;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

		     }
		 else if(strcmpi(add.acc_type,"current")==0)
		    {

			printf("\n\nYou will get no interest\a\a");

		     }

	    }
	}
    }
    else if (choice==2)
    {   printf("Enter the name:");
	scanf("%s",&check.name);
	while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
	    if(strcmpi(add.name,check.name)==0)
	    {   system("cls");
		test=1;
		printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
		add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		if(strcmpi(add.acc_type,"fixed1")==0)
		    {
			time=1.0;
			rate=9;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
		    }
		else if(strcmpi(add.acc_type,"fixed2")==0)
		    {
			time=2.0;
			rate=11;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

		    }
		else if(strcmpi(add.acc_type,"fixed3")==0)
		    {
			time=3.0;
			rate=13;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

		    }
		 else if(strcmpi(add.acc_type,"saving")==0)
		    {
			time=(1.0/12.0);
			rate=8;
			intrst=interest(time,add.amt,rate);
			printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

		     }
		 else if(strcmpi(add.acc_type,"current")==0)
		    {

			printf("\n\nYou will get no interest\a\a");

		     }

	    }
	}
    }


    fclose(ptr);
     if(test!=1)
	{   system("cls");
	    printf("\nRecord not found!!\a\a\a");
	    see_invalid:
	      printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	      scanf("%d",&main_exit);
	      system("cls");
		 if (main_exit==1)
		   { system("cls");
		      menu();
		   }
		else if (main_exit==2)
		    close();
		else if(main_exit==0)
		    search();
		else
		    {
			system("cls");
			printf("\nInvalid!\a");
			goto see_invalid;}
	}
    else
	{printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);}
	if (main_exit==1)
	{
	    system("cls");
	    menu();
	}

	else
	   {

	     system("cls");
	    close();
	    }

}



void close()
{  
  system("cls");
  textcolor(BLUE);
    cprintf("\n\n\n\n\n\n\n\n\n\n\t\Mini Banking system Developed by group A  \n\n\n\n\n\n\n\n\n\t\t");
    cprintf("(Sajan,Jitu,Anup,Patrik,Anuj)");

    }


void menu()
{  again:
   system("cls");
   setbkcolor(BLUE);
    int choice,ch;
    printf("\n\n\t\t\t\tMINIBANKING SYSTEM");
    printf("\n\n\n\t\t\t\4\4\4\4\4\4 WELCOME TO THE MAIN MENU \4\4\4\4\4\4\n\n\n");
    printf("\t\t1.Customer Entry\n");
    printf("\t\t2.Update Information\n");
    printf("\t\t3.Transcation(Deposit/Withdraw)\n");
    printf("\t\t4.Search Customer\n");
    printf("\t\t5.Delete Customer\n");
    printf("\t\t6.All Customer\n");
    printf("\t\t7.Exit\n\n\n\n");
    printf( "\t\tEnter Your Choise=");
    scanf("%d",&choice);



    switch(choice)
    {
	case 1:create();
	break;
	case 2:updates();
	break;
	case 3:transact();
	break;
	case 4:search();
	break;
	case 5:deletes();
	break;
	case 6:list();
	break;
	case 7:close();
	break;
	default:
	printf("invalid select(1-7)") ;
	printf("\nenter 1 to return \n 0 to close");
	scanf("%d",&ch);
	if(ch==1)
	  {goto again;
	  }
	  else
	  { close();
	  }



    }
}

void login()
    {   int ch;
	char username[20];
	char password[20];
	  again:
	    printf("\nEnter Your User Name:");
	    scanf("%s",&username);


		if(strcmp(username,"minibank")==0)
		{     try:
		      printf("\nEnter Your Password:");
		       scanf("%s",&password);


		    if(strcmp(password,"12345")==0)
		       {
			printf("\nYou Are Logged In Sucessfully!!!");

			menu();
		       }
		    else{
			 printf("\nInvalid Password");
			 printf("enter\n 1 to try again 0 to exit ");
			 scanf("%d",&ch);
			 if(ch==1)
			 { system("cls");
			   setbkcolor(BLUE);
			  goto try;
			  }
			  if(ch==0)
			    { close();
			    }


			}
		}
	     else
		 printf("\nInvalid Username");
		  printf("\nenter\n 1 to try again\n 0 to exit ");
			 scanf("%d",&ch);
			 if(ch==1)
			  { system("cls");
			  setbkcolor(BLUE);
			  goto again;
			  }
			  if(ch==0)
			    { close();
			    }
   }
       getch();





void main()
   { clrscr();
     int gm,gd=DETECT;
     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     setbkcolor(BLUE);
     login();
     getch();
   }
