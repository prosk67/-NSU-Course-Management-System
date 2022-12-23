#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
void start_page();
void origin();
void student_info();
void initial_list();
void Course_selection(int option);
void backend_course();
void final_receipt();
void store();


struct std_info
{
    char name[50];
    char ID[11];
    char courses[4][7];
    int credit;
};
typedef struct std_info STD;

STD Info_array[2];
char chosen_sub[4][7];
int totalcred=0;
int a = 0;

int main()
{
    start_page();
    origin();

}

void start_page()
{
    int i;
    system("color 0b");
    printf("\n\n\n\n");
    printf("\t\t\t ___________________________________________________________________________ \n");
    printf("\t\t\t|                                                                           |\n");
    printf("\t\t\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n\n");
    printf("\t\t\t|                  Welcome to NSU Course Management System                  |\n\n");
    printf("\t\t\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("\t\t\t|___________________________________________________________________________|\n\n\n");
    for(i=0; i<240; i++)
    {
        printf("-");
        Sleep(1); //after printing one (-) another comes after 0.001 seconds
    }
}

void origin()
{
    system("color 0f");
    int i,Num,noc;
    char start;
    printf("\n\nDo you want to continue?(y/n)");
    for(i=0; i<10; i++)
    {
        printf(".");
        Sleep(100); //after printing one (.) another comes after 0.1 seconds
    }
    printf(" ");
    scanf("%c",&start);
    fflush(stdin);
    if(tolower(start) == 'n')
    {
        MessageBox(NULL,"Why are you terminating the program??!  \n\n               Anyways ..... Bye Bye  :( ","Alert!!!",MB_OK);
        fflush(stdin);
        exit(0);

    }

    else if(tolower(start) == 'y')
    {
        system("cls");
        student_info();
        printf("How many courses do you want? ");
        scanf("%d",&noc);
        fflush(stdin);

        while(noc<2||noc>4)
        {
            if(noc<2)
            {
                MessageBox(NULL,"You have to take atleast 2 courses. TRY AGAIN!","Alert!!!",MB_OK);
                fflush(stdin);
                printf("\nHow many courses do you want? ");
                scanf("%d",&noc);
                fflush(stdin);

            }
            else if(noc>4)
            {
                MessageBox(NULL,"You can take maximum 4 courses. TRY AGAIN!","Alert!!!",MB_OK);
                fflush(stdin);
                printf("\nHow many courses do you want? ");
                scanf("%d",&noc);
                fflush(stdin);

            }
        }

       for(i=0;i<noc;i++)                                 //Choosing course 4 times
       {
          initial_list();
          scanf("%d", &Num);
          fflush(stdin);
          while(Num < 1 || Num >4)
          {

              MessageBox(NULL,"Invalid Input. TRY AGAIN!","Alert!!!",MB_OK);
              initial_list();
              scanf("%d", &Num);
              fflush(stdin);
          }

          printf("\n");
          Course_selection(Num);
          backend_course();

       }
       final_receipt();
       store();

    }

    else
      {

             printf("Invalid Input. Type 'y' to continue or 'n' to exit.\n");
             origin();

      }
}

void student_info()
{
    int i,flg = 0;
    int count;
    printf("\nEnter your name: ");
    gets(Info_array[1].name);
    fflush(stdin);
    printf("\nEnter your ID: ");
    scanf("%s", &Info_array[1].ID);
    fflush(stdin);
    while(1)
    {
        if(strlen(Info_array[1].ID) != 10)
        {
            MessageBox(NULL,"Invalid Input. TRY AGAIN!","Alert!!!",MB_OK);
            printf("\nEnter your ID: ");
            scanf("%s", &Info_array[1].ID);
            fflush(stdin);

        }
        else if(strlen(Info_array[1].ID) == 10)
        {
            count=0;
            for(i=0;Info_array[1].ID[i] != '\0';i++)
            {

                if(isalpha(Info_array[1].ID[i]) != 0)
                {
                    MessageBox(NULL,"Invalid Input. TRY AGAIN!","Alert!!!",MB_OK);
                    printf("\nEnter your ID: ");
                    scanf("%s", &Info_array[1].ID);
                    fflush(stdin);
                    count++;

                }

            }

        }
        if(count == 0)
        {
            break;
        }


    }

    fflush(stdin);
    printf("\n");
}

void initial_list()
{
    system("cls");
    puts("\nFrom where you want to choose your course from?\n");
    puts("1. CSE\n2. EEE\n3. MAT\n4. GED");
    printf("\nYour choice: ");
}

void Course_selection(int option)
{
    switch(option)
    {
    case 1:
            {
                FILE * cse;
                cse = fopen("CSE_file.txt","r");
                char cse_course[100];

                while(!feof(cse))
                {
                    fgets(cse_course, 100, cse);
                    puts(cse_course);
                }

                fclose(cse);
                break;

            }

    case 2:
            {
                FILE * eee;
                eee = fopen("EEE_file.txt","r");
                char eee_course[100];

                while(!feof(eee))
                {
                    fgets(eee_course, 100, eee);
                    puts(eee_course);
                }

                fclose(eee);
                break;

            }

    case 3:
            {
                FILE * mat;
                mat = fopen("MAT_file.txt","r");
                char mat_course[100];

                while(!feof(mat))
                {
                    fgets(mat_course, 100, mat);
                    puts(mat_course);
                }

                fclose(mat);
                break;

            }
    case 4:
            {
                FILE * ged;
                ged = fopen("GED_file.txt","r");
                char ged_course[100];

                while(!feof(ged))
                {
                    fgets(ged_course, 100, ged);
                    puts(ged_course);
                }

                fclose(ged);
                break;
            }


    }
}

void backend_course()
{
    int i;
    int flag = 0;
    char inp_course[7],nocap[7];

    char Cred_3[103][7] = {"ENG102","ENG103","ENG111","BEN205","PHI104","HIS102","HIS103","ECO101","ECO104","POL101","SOC101","ANT101","ENV203","GEO205","MAT361","MAT125","MAT116","MAT120","MAT130","MAT250","MAT261","MAT350","CSE173","CSE231","CSE311","CSE323","CSE327","CSE331","CSE373","CSE332","CSE425","CSE499","CSE401","CSE417","CSE418","CSE426","CSE473","CSE491","CSE411","CSE427","CSE428","CSE429","CSE492","CSE422","CSE438","CSE482","CSE485","CSE486","CSE493","CSE433","CSE435","CSE413","CSE414","CSE415","CSE494","CSE440","CSE445","CSE465","CSE467","CSE470","CSE419","CSE446","CSE447","CSE448","CSE449","CSE442","CSE496","EEE132","EEE211","EEE221","EEE223","EEE241","EEE254","EEE280","EEE311","EEE312","EEE313","EEE321","EEE331","EEE332","EEE337","EEE342","EEE361","EEE362","EEE363","EEE400","EEE421","EEE422","EEE423","EEE424","EEE425","EEE426","EEE427","EEE428","EEE451","EEE452","EEE453","EEE471","EEE493","EEE494","EEE499","\0"};
    char Cred_4[9][7] =  {"CSE115","BIO103","PHY107","CHE101","PHY108","CSE215","EEE141","EEE111"};
    char Cred_1[4][7] =  {"CSE299","CEE110","EEE154"};
    printf("\nType the course you want to choose: ");
    scanf("%s" , &nocap);
    fflush(stdin);
    for(i=0;i<7;i++)
    {
        inp_course[i] = toupper(nocap[i]);

    }


    for(i=0;i<103;i++)
    {
        if(strcmp(Cred_3[i], inp_course)== 0)
        {
            totalcred =totalcred + 3;
            flag = 1;
            break;
        }


    }
    for(i=0;i<9;i++)
    {
        if(strcmp(Cred_4[i], inp_course)== 0)
        {
            totalcred =totalcred + 4;
            flag = 1;
            break;
        }

    }
    for(i=0;i<4;i++)
    {
        if(strcmp(Cred_1[i], inp_course)== 0)
        {
            totalcred =totalcred + 1;
            flag = 1;
            break;
        }

    }

    if(flag == 1)
    {
        strcpy(chosen_sub+a,inp_course);
        a++;
    }
    else
    {
        MessageBox(NULL,"No Such Courses !!! LETS TRY AGAIN...","Alert!!!",MB_OK);
        backend_course();
    }
}

void final_receipt()
{
        system("cls");

        int i,j;

        for(j=0;j<4;j++)
        {
            strcpy(Info_array[1].courses[j], chosen_sub[j]);
        }
        Info_array[1].credit = totalcred;


        printf("\n\n%s you have taken the following courses- \n\n", Info_array[1].name);

        for(j=0;j<4;j++)
        {
            printf("%s  ",Info_array[1].courses[j]);
        }

        printf("\n\nTotal credit of the courses: %d\n",Info_array[1].credit);
        printf("\nTotal fee: %d tk.\n\n\n\n",Info_array[1].credit *6500 + 9500);

}

void store()
{
    FILE *store_info;
    store_info = fopen("Student_courses.txt", "a");
    fprintf(store_info, "Name: %s\nID: %s\nCourses: %s %s %s %s\n\n", Info_array[1].name, Info_array[1].ID, Info_array[1].courses[0], Info_array[1].courses[1], Info_array[1].courses[2], Info_array[1].courses[3]);
    fclose(store_info);
}

















































