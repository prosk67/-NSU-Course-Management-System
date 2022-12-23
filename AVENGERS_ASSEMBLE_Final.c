#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

void start_page();
void origin();
void student_info();
void initial_list();                   //Prototyping all the user defined functions.
void Course_selection(int option);
void backend_course();
void final_receipt();
void store();

struct std_info   //Declaring a structure data type.
{
    char name[50];              //Declaring a character type array for name and ID inputs.
    char ID[11];
    char courses[4][7];         //Declaring a character type array or string for course inputs.
    int credit;                 //Declaring a integer data for credit inputs.
};
typedef struct std_info STD;

STD Info_array[10];      //declaring a structure variable to store all the credentials.
char chosen_sub[4][7];  //all the courses seleced by the user gets stored in this string array.
int totalcred=0;        //all the course credits add up and gets stored here.
int a = 0;

int main()       //The main function calls the start_page() and the origin() function.
{
    start_page();
    origin();

}

void start_page()    //this void function mainly greets the user with a welcome page.
{
    int i;
    system("color 0b");  //console background color stays black but the text color changes to aqua blue.
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
        Sleep(1);  //after printing one (-) another comes after 0.001 seconds.
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
        Sleep(100); //after printing one (.) another comes after 0.1 seconds.
    }
    printf(" ");
    scanf("%c",&start);  //takes input from the user which determines if the user wants to continue further or not.
    fflush(stdin);
    if(tolower(start) == 'n') //when the user inputs 'n' or 'N' as input the following codes get executed.
    {
        MessageBox(NULL,"Why are you terminating the program??!  \n\n               Anyways ..... Bye Bye  :( ","Alert!!!",MB_OK);  //shows a pop up message box to the user.
        fflush(stdin);
        exit(0); //returns 0 and exits the program.


    }

    else if(tolower(start) == 'y')  //when the user inputs 'y' or 'Y' as input the following codes get executed.
    {
        system("cls");  //clears the console screen.
        system("color 0b");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t    ENTERING THE DEN");
        printf("\n\n\t\t\t\t   ");
        for(int i=0;i<26;i++)
        {
        printf("%c ",219);     //Displays a Loading screen while entering the program. After printing one block(ASCII 219) another comes after 0.05 seconds.
        Sleep(150);
        }
        Sleep(400);
        system("cls");
        system("color 0f");
        student_info(); //calling the function to take certain inputs.
        printf("How many courses do you want? ");
        scanf("%d",&noc);  //takes input of the number of courses from the user.
        fflush(stdin);

        while(noc<2||noc>4) //running a infinite loop, every time the user provides invalid input.
        {
            if(noc<2)   //In case the user chooses lesser than 2 courses,the program displays a message box informing the user about the error and asks to retry.
            {
                MessageBox(NULL,"You have to take atleast 2 courses. TRY AGAIN!","Alert!!!",MB_OK);
                fflush(stdin);
                printf("\nHow many courses do you want? ");
                scanf("%d",&noc);
                fflush(stdin);

            }
            else if(noc>4) //In case the user chooses more than 4 courses,the program displays a message box informing the user about the error and asks to retry.
            {
                MessageBox(NULL,"You can take maximum 4 courses. TRY AGAIN!","Alert!!!",MB_OK);
                fflush(stdin);
                printf("\nHow many courses do you want? ");
                scanf("%d",&noc);
                fflush(stdin);

            }
        }

       for(i=0;i<noc;i++)  //Depending on the input of the number of courses, the loop runs for that many times.
       {
          initial_list();
          scanf("%d", &Num);  //takes input from the user, which executes respective case from the Course_selecton() function.
          fflush(stdin);
          while(Num < 1 || Num >4)
          {
              //running a infinite loop, every time the user provides invalid input and displays error message.
              MessageBox(NULL,"Invalid Input. TRY AGAIN!","Alert!!!",MB_OK);
              initial_list();
              scanf("%d", &Num);
              fflush(stdin);
          }

          printf("\n");
          Course_selection(Num);  //after getting a valid input from the user, the programs heads on to call the next functions.
          backend_course();

       }
       final_receipt();
       store();

    }

    else   //shows invalid input message and using recursion calls the origin() function
      {

             printf("Invalid Input. Type 'y' to continue or 'n' to exit.\n");
             origin();

      }
}

void student_info() //takes input of the student's name and ID
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
        if(strlen(Info_array[1].ID) != 10)  //if the ID length is not equal to 10, program shows error.
        {
            MessageBox(NULL,"Invalid Input. TRY AGAIN!","Alert!!!",MB_OK);
            printf("\nEnter your ID: ");
            scanf("%s", &Info_array[1].ID);
            fflush(stdin);

        }
        else if(strlen(Info_array[1].ID) == 10)  //if the ID length is equal to 10, program heads further to check if there is a character in the input or not.
        {
            count=0;
            for(i=0;Info_array[1].ID[i] != '\0';i++)
            {

                if(isalpha(Info_array[1].ID[i]) != 0) //if there's a character in the input, the program returns true value and shows a error message.
                {
                    MessageBox(NULL,"Invalid Input. TRY AGAIN!","Alert!!!",MB_OK);
                    printf("\nEnter your ID: ");
                    scanf("%s", &Info_array[1].ID);
                    fflush(stdin);
                    count++; //in case there is a character, the value of count changes.

                }

            }

        }
        if(count == 0) //when the value of count does not change and remains 0, the loop breaks.
        {
            break;
        }


    }

    fflush(stdin);
    printf("\n");
}

void initial_list() //displays the course initial list from where the user determines where to choose his course from.
{
    system("cls"); //clears the console screen.
    puts("\nFrom where you want to choose your course from?\n");
    puts("1. CSE\n2. EEE\n3. MAT\n4. GED");
    printf("\nYour choice: ");
}

void Course_selection(int option)  //using switch and 4 cases, 4 different text files were called into the function.
{
    switch(option)
    {
    case 1:  //reads the text file containing CSE courses list.
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

    case 2:  //reads the text file containing EEE courses list.
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

    case 3:  //reads the text file containing MAT courses list.
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
    case 4:  //reads the text file containing GED courses list.
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

void backend_course() //In this function all the background calculations are being executed.
{
    int i;
    int flag = 0;
    char inp_course[7],nocap[7];

    //courses with different credit counts were stored in different string arrays.

    char Cred_3[103][7] = {"ENG102","ENG103","ENG111","BEN205","PHI104","HIS102","HIS103","ECO101","ECO104","POL101","SOC101","ANT101","ENV203","GEO205","MAT361","MAT125","MAT116","MAT120","MAT130","MAT250","MAT261","MAT350","CSE173","CSE231","CSE311","CSE323","CSE327","CSE331","CSE373","CSE332","CSE425","CSE499","CSE401","CSE417","CSE418","CSE426","CSE473","CSE491","CSE411","CSE427","CSE428","CSE429","CSE492","CSE422","CSE438","CSE482","CSE485","CSE486","CSE493","CSE433","CSE435","CSE413","CSE414","CSE415","CSE494","CSE440","CSE445","CSE465","CSE467","CSE470","CSE419","CSE446","CSE447","CSE448","CSE449","CSE442","CSE496","EEE132","EEE211","EEE221","EEE223","EEE241","EEE254","EEE280","EEE311","EEE312","EEE313","EEE321","EEE331","EEE332","EEE337","EEE342","EEE361","EEE362","EEE363","EEE400","EEE421","EEE422","EEE423","EEE424","EEE425","EEE426","EEE427","EEE428","EEE451","EEE452","EEE453","EEE471","EEE493","EEE494","EEE499","\0"};
    char Cred_4[9][7] =  {"CSE115","BIO103","PHY107","CHE101","PHY108","CSE215","EEE141","EEE111"};
    char Cred_1[4][7] =  {"CSE299","CEE110","EEE154"};

    printf("\nType the course you want to choose: ");
    scanf("%s" , &nocap);
    fflush(stdin);

    for(i=0;i<7;i++)
    {
        inp_course[i] = toupper(nocap[i]); //course name inputs get capitalized and stored in another string array.

    }
    for(i=0;i<103;i++)
    {
        if(strcmp(Cred_3[i], inp_course)== 0) //compares the input with the string the course was declared into and adds all the credits according to the courses ad stores it in the totalcred variable.
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
        MessageBox(NULL,"No Such Courses !!! LETS TRY AGAIN...","Alert!!!",MB_OK); //if the user inputs any invalid course inputs, the programs informs the user about it and recurses backend_course() function.
        backend_course();
    }

}

void final_receipt() //after taking all the inputs, the program shows the user a final receipt where all of the courses with the total credit and fees gets displayed.
{
        system("cls"); //clears the terminal.

        int i,j;

        for(j=0;j<4;j++)
        {
            strcpy(Info_array[1].courses[j], chosen_sub[j]); //all the courses user chose gets copied in the structure array.
        }
        Info_array[1].credit = totalcred; //total credit gets stored inside the structure array.

        printf("\n\n");

        for(i=0;i<120;i++)
        {
            printf("-");
            Sleep(1);
        }
        Sleep(100);

        printf("\n\n\t\t\t\t\tName         : %s    \n\n\t\t\t\t\tID           : %s \n\n", Info_array[1].name, Info_array[1].ID);
        printf("\t\t\t\t\tCourses      : ");
        for(j=0;j<4;j++)
        {
            printf("%s  ",Info_array[1].courses[j]);
        }
        printf("\n\n\t\t\t\t\tTotal Credit : %d\n",Info_array[1].credit);
        printf("\n\t\t\t\t\tTotal fee    : %d bdt.\n\n",Info_array[1].credit *6500 + 9500); //calculates and shows the total fees.

        Sleep(100);
        for(i=0;i<120;i++)
        {
            printf("-");
            Sleep(1);
        }
        printf("\n\n\n\n\n\n\n");
        getch();

}

void store() //stores all the credentials and inputs in a text file for further usages.
{
    FILE *store_info; //declaring a file pointer variable.
    store_info = fopen("Student_info.txt", "a");  //opens the text file and writes all the informations inside the text file using append mode of file handling.
    fprintf(store_info, "Name         : %s\nID           : %s\nCourses      : %s %s %s %s\nTotal Credit : %d\nTotal Fee    : %d bdt.\n\n", Info_array[1].name, Info_array[1].ID, Info_array[1].courses[0], Info_array[1].courses[1], Info_array[1].courses[2], Info_array[1].courses[3], Info_array[1].credit, Info_array[1].credit *6500 + 9500);
    fclose(store_info); //closes the text file.
}
