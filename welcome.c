#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
COORD coord= {0,0};

struct product
{
    char type[20];
    char name[20];
    char brand[20];
    char code[20];
    int price;
    int gst;
    char a[20];
    char buy[20];
} item;


void login();
void admin();
void user();
void admin_insert();
void admin_delete();
void admin_viewAll();
void admin_find();
void admin_update();
void admin_check();
void SetColor(int ForgC);
void welcome();
void gotoxy(int x,int y);
void box(int x1,int y1,int x2,int y2,int c);
void category();

void main()
{

    welcome();
    login();


}

void login()
{
    int ch;

    do
    {
        system("cls");
        SetColor(3);
        printf("\n\t---------------------------------------------------------------------------------------");
        printf("\n\t|                                    C TRENDZ                                          |");
        printf("\n\t---------------------------------------------------------------------------------------");
        printf("\n\n");

        printf("\n\tPress <1> ADMIN LOGIN");
        printf("\n\tPress <2> USER LOGIN");
        printf("\n\tPress <0> EXIT");

        printf("\n\tEnter your Choice :: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1 :
            admin_check();
            break;

        case 2 :
            user();
            break;

        case 0:
            printf("\n\n\t\tThank you For Visiting US!!\n\n");
            exit(0);
            break;

        default:
            printf("Please enter a valid option");
            break;
        }
    }
    while(ch!=0);



}

void admin_check()
{

    char pass[20]="a";
    char username[20]="a";
    char temp_pass[20];
    char temp_name[20];
    system("cls");
    printf("\n\t--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t|                                              ADMINISTRATOR LOG IN                                                       |");
    printf("\n\t--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n");
    printf("\n\n\n\t");
    printf("Enter Username:: ");
    scanf("%s",temp_name);

    printf("\n\tEnter Password:: ");
    scanf("%s",temp_pass);
    if(strcmp(username,temp_name) == 0 && strcmp(pass,temp_pass) == 0)
    {
        admin();

    }


    else
        printf("Invalid Credentials!");

}

void admin()
{
    system("cls");

    printf("\n\t--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t|                                           C TRENDZ-ADMINISTRATOR                                                        |");
    printf("\n\t--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n");


    int ch;
    do
    {



        printf("\nPress <1> Insert New Product ");
        printf("\nPress <2> Search Product ");
        printf("\nPress <3> View All Product");
        printf("\nPress <4> Update Product ");
        printf("\nPress <5> Delete Product ");
        printf("\nPress <6> Exit ");

        printf("\nEnter your Choice ::");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1 :
            admin_insert();
            break;

        case 2:
            admin_find();
            break;

        case 3:
            admin_viewAll();
            break;

        case 4:
            admin_update();
            break;

        case 5:
            admin_delete();
            break;

        case 6:
            login();
            break;

        default:
            printf("Please enter a valid option");
            break;
        }
    }
    while(ch!=0);

}


void admin_insert()
{

    struct product item;
    FILE *fp;
    FILE *fp2;
    //system("clear");

    fp=fopen("all_data.txt","a");
    fp2=fopen("all_data.txt","r");


    printf("\n\t Enter Product Code(must be unique)::");
    scanf("%s",item.a);

    while(fscanf(fp2,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst)!=EOF)
    {
        if(strcmp(item.code,item.a)==0)
        {
            printf("\n\tError! This code exist earlier\n");
            delay(1000);

            admin_insert();

        }
        else
        {
            strcpy(item.code,item.a);


        }
    }
    setbuf(stdin,NULL);

    printf("\n\t Enter Product name :: ");
    scanf("%s",item.name);
    setbuf(stdin,NULL);

    printf("\n\t Enter Product Brand :: ");
    scanf("%s",item.brand);
    setbuf(stdin,NULL);

    printf("\n\tEnter Product type::");
    scanf("%s",item.type);
    setbuf(stdin,NULL);

    printf("\n\t Enter Price of Product ::");
    scanf("%d",&item.price);
    printf("\n\t Enter GST Rate of Product ::");
    scanf("%d",&item.gst);

    if(fp == NULL)
    {
    }
    else
    {
        fprintf(fp,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
        printf("Record Inserted ! ...... \n");
        fclose(fp);
    }

}


void admin_delete()
{
    FILE *fpt,*fptr;
    struct product item;
    int found=0;
    char code[20]; //for search

    fpt=fopen("all_data.txt","r");

    if(fpt==NULL)
    {
        printf("\n Error In Opening File....");

    }

    fptr=fopen("temp.txt","w");

    if(fptr==NULL)
    {
        printf("\n Error In Opening File....");

    }


    setbuf(stdin,NULL);

    printf("\n Enter code  : ");
    scanf("%s",code);

    while(fscanf(fpt,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst)!=EOF)
    {
        if(item.code==0)
            break;

        if(strcmp(item.code,code)==0)
        {
            found=1;
        }
        else
        {
            fprintf(fptr,"%s ",item.code);
            fprintf(fptr,"%s ",item.name);
            fprintf(fptr,"%s ",item.brand);
            fprintf(fptr,"%d ",item.price);
            fprintf(fptr,"%s ",item.type);
            fprintf(fptr,"%d ",item.gst);

        }
    }

    fclose(fptr);
    fclose(fpt);

    if(found==0)
    {
        printf("\n\n\n *****************************************\n\n");
        printf("\n Record Not Found....");
        printf("\n\n\n *****************************************\n\n");
    }
    else
    {
        fpt=fopen("all_data.txt","w");

        if(fpt==NULL)
        {
            printf("\n Error In Opening File....");

        }

        fptr=fopen("temp.txt","r");

        if(fptr==NULL)
        {
            printf("\n Error In Opening File....");

        }

        while(fscanf(fptr,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst)!=EOF)
        {
            if(item.code==0)
                break;

            fprintf(fpt,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
        }

        printf("\n Record Successfully Deleted...............................!\n");
        fclose(fptr);
        fclose(fpt);
    }

}
void admin_viewAll()
{

    char ch;
    FILE *fp;

    fp = fopen("all_data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        //system("clear");
        printf("Code \t\tName \t\tBrand \t\tPrice \t\tType \t\tGST\n");
        while( fscanf(fp,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
        {
            printf("%s  \t\t%s  \t\t%s  \t\t%d  \t\t%s  \t\t%d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
        }

    }

}




void admin_find()
{
    struct product item;
    FILE *fp;
    int flag=0;
    char findCode[20];
    printf("Enter Product code to search for product ::");
    scanf("%s",findCode);

    fp = fopen("all_data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        while(fscanf(fp,"%s %s %s %d %s %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF)
        {


            if(strcmp(item.code,findCode) == 0)
            {
                flag=1;
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",item.code);
                printf("\n\t\tProduct name ::%s",item.name);
                printf("\n\t\tBrand name ::%s",item.brand);
                printf("\n\t\tCost of Item ::%d",item.price);
                printf("\n\t\tProduct Type ::%s",item.type);
                printf("\n\t\tGST applicable ::%d",item.gst);

            }
        }
        if(flag == 0)
            printf("\nRecord Not Found\n");

    }




}

void admin_update() //update price of item
{
    FILE *tf,*fp;
    char code[20];	//search code
    int rno,cnt=0;

    tf=fopen("temp.txt","w");

    fp=fopen("all_data.txt","r");

    printf("\n Enter Item Code : ");
    scanf("%s",code);


    while(fscanf(fp,"%s %s %s %d %s %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF)
    {

        if(strcmp(item.code,code) == 0)
        {
            cnt = 1;
            int choice;
            printf("\n Record Found\n");
            printf("\n\n\n\t\tCode ::%s",item.code);
            printf("\n\t\tProduct name ::%s",item.name);
            printf("\n\t\tBrand name ::%s",item.brand);
            printf("\n\t\tCost of Item ::%d",item.price);
            printf("\n\t\tProduct Type ::%s",item.type);
            printf("\n\t\tGST applicable ::%d",item.gst);

            printf("\n\nWhat you want to update!!");
            printf("\nPress <1> Product Name");
            printf("\nPress <2> Product Type");
            printf("\nPress <3> Brand Name");
            printf("\nPress <4> Product Price");
            printf("\nPress <5> GST Rate");
            printf("\nPress <6> Back to Administrator menu");
            printf("\nEnter Your Choice:: ");

            scanf("%d",&choice);


            switch(choice)
            {

            case 1:
                printf("\n\t Enter New Product Name ::");
                scanf("%s",item.name);
                break;

            case 2:
                printf("\n\t Enter New Product Type ::");
                scanf("%s",item.type);
                break;

            case 3:
                printf("\n\t Enter New Product Brand Name ::");
                scanf("%s",item.brand);
                break;

            case 4:
                printf("\n\t Enter New Price ::");
                scanf("%d",&item.price);
                break;

            case 5:
                printf("\n\t Enter New GST rate ::");
                scanf("%d",&item.gst);
                break;

            case 6:
                admin();
                break;
            default:
                printf("enter valid option");






            }

            fprintf(tf,"%s %s %s %d %s %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);

        }
        else
        {
            fprintf(tf,"%s %s %s %d %s %d \n",item.code,item.name,item.brand,item.price,item.type);
        }
    }
    fclose(fp);
    fclose(tf);

    if(cnt==0)
    {
        printf("\n\n\n *****************************************\n\n");
        printf("\n Record Not Available ");
        printf("\n\n\n *****************************************\n\n");
    }
    else
    {
        fp=fopen("all_data.txt","w");

        tf=fopen("temp.txt","r");

        while(fscanf(tf,"%s %s %s %d %s %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst)!=EOF)
        {
            if(item.code==0)
                break;

            fprintf(fp,"%s %s %s %d %s %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
        }

        printf("\n Success!");

        fclose(fp);
        fclose(tf);
    }


}

void user()
{

    int ch;
    int choice;
    char username[20];
    char password[20];
    FILE *log;
    log=fopen("details.txt","a");
    do
    {

        printf("\n\n\tPress <1> LOGIN");
        printf("\n\tPress <2> CREATE AN ACCOUNT");
        printf("\n\tPress <0> EXIT");
        printf("\n\tENTER YOUR CHOICE:");

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            /*
            printf("\nENTER YOUR USERNAME:\n");
            scanf("%s",username);
            printf("\nENTER YOUR PASSWORD:\n");
            scanf("%s",password);
            */
            break;

        case 2:
            printf("\nENTER USERNAME:");
            scanf("%s",username);
            printf("\nENTER PASSWORD:");
            scanf("%s",password);
            if(log == NULL)
            {
            }
            else
            {
                fprintf(log,"%s  %s \n",username,password);
                printf("You are Registered \n");
                fclose(log);
                user();
            }


            break;

        case 3:
            printf("view cart");
        case 0:
            login();
            break;

        default:
            printf("invalid choice");
            break;
        }
        while(choice!=0);



        do
        {


            printf("\n\n\tPress <1> SHOP BY CATEGORY");
            printf("\n\tPress <2> SEARCH FOR PRODUCT");
            printf("\n\tPress <3> VIEW CART");
            printf("\n\tPress <0> EXIT");
            printf("\n\tENTER YOUR CHOICE:");

            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                category();
                break;

            case 2:
                printf("search");
                break;

            case 3:
                printf("view cart");
            case 0:
                login();
                break;

            default:
                printf("invalid choice");
                break;
            }
        }
        while(ch!=0);


    }
    while(choice!=0);

}

void category()
{

    FILE *fp;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp5;


    fp=fopen("all_data.txt","r");
    fp2=fopen("elec.txt","w");
    fp3=fopen("fash.txt","w");
    fp4=fopen("home.txt","w");
    fp5=fopen("hapc.txt","w");
    int ch;
    int ch2;
    int ch3;

    FILE *fp6;
    int flag;


    while( fscanf(fp,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
    {
        if(strcmp(item.type,"elec")==0)
        {


            if(fp2 == NULL)
            {
            }
            else
            {
                fprintf(fp2,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
                printf("Record Inserted in elec ! ...... \n");

            }
        }


        if(strcmp(item.type,"fash")==0)
        {


            if(fp3 == NULL)
            {
            }
            else
            {
                fprintf(fp3,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
                printf("Record Inserted in fash ! ...... \n");

            }
        }

        if(strcmp(item.type,"home")==0)
        {


            if(fp4 == NULL)
            {
            }
            else
            {
                fprintf(fp4,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
                printf("Record Inserted in home ! ...... \n");

            }
        }


        if(strcmp(item.type,"hapc")==0)
        {


            if(fp5 == NULL)
            {
            }
            else
            {
                fprintf(fp5,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
                printf("Record Inserted in health and Personal Care ! ...... \n");

            }


        }


    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp);

    fp=fopen("all_data.txt","r");
    fp2=fopen("elec.txt","r");
    fp3=fopen("fash.txt","r");
    fp4=fopen("home.txt","r");
    fp5=fopen("hapc.txt","r");


    do
    {


        printf("\nPress <1> ELECTRONICS");
        printf("\nPress <2> FASHION");
        printf("\nPress <3> HEALTH AND PERSONAL CARE");
        printf("\nPress <4> HOME AND FURNITURE");
        printf("\nPress <0> Exit");
        printf("\nEnter your choice\n");

        scanf("%d",&ch);
        switch(ch)
        {
        case 1:

            printf("\n\n");
            printf("\tCODE \t\tNAME \t\tBRAND \t\tPRICE\n");
            while( fscanf(fp2,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
            {
                printf("\t%s \t\t%s  \t\t%s  \t\t%d \n",item.code,item.brand,item.name,item.price);
            }



            do
            {



                printf("\n\n ENTER WHAT YOU WANT TO DO?\n");
                printf("\nPress <1> ADD TO CART");
                printf("\nPress <2> ADD TO WISHLIST");
                printf("\nPress <3> DID NOT FIND YOUR PRODUCT, SUGGEST ADMIN!");
                printf("\nPress <0> Exit");
                printf("\nENTER YOUR CHOICE\n");

                scanf("%d",&ch3);
                switch(ch3)
                {
                case 1:

                    printf("\n\n ENTER PRODUCT OF CODE YOU WANT TO BUY?\n");
                    scanf("%s",item.buy);
                    fp6=fopen("user_cart.txt","a");

                    while( fscanf(fp,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
                    {
                        if(strcmp(item.buy,item.code)==0)
                        {


                            if(fp6 == NULL)
                            {
                            }
                            else
                            {
                                fprintf(fp6,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,item.price,item.type,item.gst);
                                printf("Added to Cart");
                                flag=1;
                                fclose(fp6);
                            }



                        }

                    }

                    if(flag!=1)
                    {
                        printf("invalid code");

                    }

                    break;

                case 2:
                    printf("wishlist");
                    break;

                case 3:
                    printf("ask");
                case 0:
                    category();
                    break;

                default:
                    printf("invalid choice");
                    break;
                }
            }
            while(ch3!=0);



            break;




        case 2:
            printf("\n\n");
            printf("\tCODE \t\tNAME \t\tBRAND \t\tPRICE\n");
            while( fscanf(fp3,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
            {
                printf("\t%s \t\t%s  \t\t%s  \t\t%d \n",item.code,item.brand,item.name,item.price);
            }

            fclose(fp3);

            printf("\n\n ENTER CODE OF PRODUCT YOU WANT TO BUY!");
            break;

        case 3:
            printf("\n\n");
            printf("\tCODE \t\tNAME \t\tBRAND \t\tPRICE\n");
            while( fscanf(fp4,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
            {
                printf("\t%s \t\t%s  \t\t%s  \t\t%d \n",item.code,item.brand,item.name,item.price);
            }

            fclose(fp4);

            printf("\n\n ENTER CODE OF PRODUCT YOU WANT TO BUY!");
            break;


        case 4:
            printf("\n\n");
            printf("\tCODE \t\tNAME \t\tBRAND \t\tPRICE\n");
            while( fscanf(fp5,"%s  %s  %s  %d  %s  %d \n",item.code,item.name,item.brand,&item.price,item.type,&item.gst) != EOF )
            {
                printf("\t%s \t\t%s  \t\t%s  \t\t%d \n",item.code,item.brand,item.name,item.price);
            }

            fclose(fp5);

            printf("\n\n ENTER CODE OF PRODUCT YOU WANT TO BUY!");
            break;


        case 0:
            user();
            break;

        default:
            printf("invalid choice");
            break;

        }


    }
    while(ch!=0);
}






void SetColor(int ForgC)
{
    WORD wColor;               //This handle is needed to get the current background attribute

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;           //csbi is used for wAttributes word

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void welcome()
{

    SetColor(3);
    printf("\n\n\n\n\n\n\n");
    printf("______________________________________________________________________________________________________________________________________________________________________");
    printf("\n\n\n\n\n");
    printf("\t\t =============            ==================      =========          =============      ==        =      ==============         ==========  \n");
    printf("\t\t=                                  =             =         =        =                   = =       =       =            =                =   \n");
    printf("\t\t=                                  =             =         =        =                   =  =      =       =            =               =    \n");
    printf("\t\t=                                  =             ==========         =                   =   =     =       =            =              =     \n");
    printf("\t\t=                =======           =             =  =               ==============      =    =    =       =            =             =      \n");
    printf("\t\t=                                  =             =   =              =                   =     =   =       =            =            =       \n");
    printf("\t\t=                                  =             =    =             =                   =      =  =       =            =           =        \n");
    printf("\t\t=                                  =             =     =            =                   =       = =       =            =          =         \n");
    printf("\t\t =============                     =             =      =            =============      =        ==      ==============          ==========");
    printf("\n\n\n\n\n");
    printf("______________________________________________________________________________________________________________________________________________________________________");

    delay(3000);



    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t<<<<Press Any key>>>>");
    box(5,35,160,40,15);

    getch();
    system("cls");

}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void box(int x1,int y1,int x2,int y2,int c)
{
    int y,x,i;
    gotoxy(x1,y1);
    printf("%c",201);
    for(x=x1+1; x<x2; x++)
    {
        gotoxy(x,y1);
        printf("%c",205);
    }
    gotoxy(x2,y1);
    printf("%c",187);
    for(y=y1+1; y<y2; y++)
    {
        gotoxy(x1,y);
        printf("%c",186);
        gotoxy(x2,y);
        printf("%c",186);
    }
    gotoxy(x1,y2);
    printf("%c",200);
    for(i=x1+1; i<x2; i++)
    {
        gotoxy(i,y2);
        printf("%c",205);
    }
    gotoxy(x2,y2);
    printf("%c",188);
}








