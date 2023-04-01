/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
Lee Brien V. Sandoval, 12209317
*********************************************************************************************************/
// Preprocessor Directives
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#define SIZE 20

typedef char String50[21];
typedef char String150[151];
typedef char String30[31];

// This struct holds the components of a question
struct quizRecord
{
    String50 topicName;
    int qNumber;
    String150 Question;
    String30 C1;
    String30 C2;
    String30 C3;
    String30 qAnswer;
};

/* This function is for getting the password of the admin.
Precondition: The length of the password is limited to 30 characters
@param password This holds the inputted string as a password
@return void
*/
void getPassword(String30 password)
{

    int i = 0;
    char ch;

    while ((ch = getch()) != '\r')
    {

        if (ch == '\b')
        {

            password[i - 1] = '\0';
            printf("\b \b");
            i -= 1;
        }

        else
        {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    password[i] = '\0';
}

/* This function is for getting the string for the record.
Precondition: The length of the input is limited to 200 characters
@param password This holds the inputted string as a password
@return void
*/
void getString(char string[], int nSize)
{

    char ch;
    int i = 0;
    String150 stringInput;

    do
    {
        if (i == 0)
        {

            scanf(" %c", &ch);

            if (ch != '\n')
            {
                stringInput[i] = ch;
                i++;
                stringInput[i] = '\0';
            }
        }

        else
        {

            scanf("%c", &ch);

            if (ch != '\n')
            {
                stringInput[i] = ch;
                i++;
                stringInput[i] = '\0';
            }
        }
        
    } while (ch != '\n');

    if (stringInput[strlen(stringInput) - 1] == ' ')
    {

        stringInput[strlen(stringInput) - 1] = '\0';
    }

    strcpy(string, stringInput);
}

/* This function is for logging into admin after registration
Precondition: The length of the password is limited to 30 characters
@param password This holds the inputted string as a password.
@param currentPassword is used if user will return to manage data.
@param returnMenu This is for choosing if the user wishes to return to the
       main menu after an incorrect password input.
@param bContinue is used to signal if login/registration was successful, thus continue through
       managing the data.
@return void
*/
void adminLogin(String30 password, String30 currentPassword, bool *returnMenu, bool *bContinue)
{

    // To signal validity of input for the whole function.
    bool validInput = false;

    // To signal validity of input when password did not match.
    bool validInput2 = false;

    int dInput;

    do
    {
        printf("\n=== Admin Login ===\n\n");
        printf("Enter password: \n");
        getPassword(password);

        if (strcmp(password, currentPassword) == 0)
        {

            printf("\n\nLogin Successful!\n\n");
            system("pause");
            system("cls");

            *bContinue = true;
            validInput = true;
        }

        else if (strcmp(password, currentPassword) != 0)
        {

            do
            {
                system("cls");
                printf("PASSWORD DO NOT MATCH");
                printf("\n\nPress [1] to retry");
                printf("\nPress [2] to return to main menu");

                printf("\nEnter: ");
                scanf("%d", &dInput);

                if (dInput == 2)
                {
                    validInput = true;
                    validInput2 = true;
                    *returnMenu = true;
                }

                else if (dInput == 1)
                {
                    validInput2 = true;
                    system("cls");
                }

            } while (validInput2 == false);
        }

    } while (validInput == false);
}

/* This function is for registering a password for the first time.
Precondition: The length of the password is limited to 30 characters
@param password This holds the inputted string as a password.
@param tempPassword is used to compare the password input.
@param currentPassword is used if user will return to manage data.
@param returnMenu This is for choosing if the user wishes to return to the
       main menu after an incorrect password input.
@param bContinue is used to signal if login/registration was successful, thus continue through
       managing the data.
@return void
*/
void adminRegistration(String30 password, String30 tempPassword, String30 currentPassword, bool *returnMenu, bool *bContinue)
{
    bool validInput = false;
    bool validInput2 = false;

    int dInput;

    do
    {
        printf("\n=== Admin Registration ===\n\n");
        printf("Enter password for registration: \n");
        getPassword(password);

        printf("\nConfirm your password: \n");
        getPassword(tempPassword);

        if (strcmp(password, tempPassword) == 0)
        {

            printf("\n\nRegistration Successful!\n\n");
            system("pause");
            system("cls");

            *bContinue = true;
            validInput = true;
            strcpy(currentPassword, password);
        }

        else if (strcmp(password, tempPassword) != 0)
        {

            do
            {
                system("cls");
                printf("PASSWORD DO NOT MATCH");
                printf("\n\nPress [1] to retry");
                printf("\nPress [2] to return to main menu");

                printf("\nEnter: ");
                scanf("%d", &dInput);

                if (dInput == 2)
                {
                    validInput = true;
                    validInput2 = true;
                    *returnMenu = true;
                }

                else if (dInput == 1)
                {
                    validInput2 = true;
                    system("cls");
                }

            } while (validInput2 == false);
        }

    } while (validInput == false);
}

/* This function is for adding a record into the quiz.
Precondition: Assume that the input is case sensitive when checking existing records.
@param records is the array of structures for quiz records.
@param password This holds the inputted string as a password.
@param ctrRecord is the value of the number of existing records.
@return void
*/
void addRecord(struct quizRecord *records, int *ctrRecord)
{

    system("cls");

    String150 tempQuestion;
    String30 tempAnswer;
    bool existingRecord = false;
    bool returnMenu = false;
    bool cInputValid = false;
    char cInput;

    do
    {
        system("cls");

        printf("Enter a question: ");
        getString(tempQuestion, 151);
        printf("\nEnter the answer: ");
        getString(tempAnswer, 31);

        for (int i = 0; i < SIZE; i++)
        {

            if (strcmp(tempQuestion, records[i].Question) == 0)
            {

                if (strcmp(tempAnswer, records[i].qAnswer) == 0)
                {

                    system("cls");
                    printf("%s\n", records[i].topicName);
                    printf("%d. %s\n", records[i].qNumber, records[i].Question);
                    printf("A) %s\n", records[i].C1);
                    printf("B) %s\n", records[i].C2);
                    printf("C) %s\n", records[i].C3);
                    printf("\nAnswer: %s\n\n", records[i].qAnswer);

                    printf("RECORD ALREADY LISTED\n\n");

                    system("pause");

                    existingRecord = true;
                }
            }
        }

        if (existingRecord == false)
        {

            system("cls");

            strcpy(records[*ctrRecord].Question, tempQuestion);
            strcpy(records[*ctrRecord].qAnswer, tempAnswer);

            printf("%s", records[*ctrRecord].Question);
            printf("\n%s", records[*ctrRecord].qAnswer);

            printf("\n\nEnter topic: ");
            getString(records[*ctrRecord].topicName, 51);
            printf("Enter 1st choice: ");
            getString(records[*ctrRecord].C1, 31);
            printf("Enter 2nd choice: ");
            getString(records[*ctrRecord].C2, 31);
            printf("Enter 3rd choice: ");
            getString(records[*ctrRecord].C3, 31);

            records[*ctrRecord].qNumber = *ctrRecord + 1;

            *ctrRecord += 1;

            system("cls");
            printf("Record Successfully Added!\n\n");
            system("pause");
        }

        else
        {

            do
            {

                system("cls");

                printf("Return to MANAGE DATA?\n");
                printf("[Y] if yes");
                printf("\n[N] if no");

                printf("\n\nEnter: ");
                scanf(" %c", &cInput);

                switch (cInput)
                {

                case 'Y':
                case 'y':
                    returnMenu = true;
                    cInputValid = true;
                    break;

                case 'N':
                case 'n':
                    returnMenu = false;
                    cInputValid = true;
                    break;

                default:
                    cInputValid = false;
                    break;
                }

            } while (cInputValid == false);
        }

    } while (existingRecord == true && returnMenu == false);
}

/* This function is the menu for admins which manages the data of the program
Precondition: cInput from int main() must be 'm' or 'M'
@param records is the array of structures for quiz records.
@param password This holds the inputted string as a password.
@param tempPassword is used to compare the password input.
@param currentPassword is used if user will return to manage data.
@param returnMenu This is for choosing if the user wishes to return to the
       main menu after an incorrect password input.
@param ctrRecord is the value of the number of existing records.
@return void
*/
void manageData(struct quizRecord *records, String30 password, String30 tempPassword, String30 currentPassword, bool *returnMenu, int *ctrRecord)
{

    bool bContinue = false;
    bool switchValid = false;
    bool returnManageData = false;
    char adminInput;

    system("cls");

    if (strcmp(password, currentPassword) != 0)
    {
        adminRegistration(password, tempPassword, currentPassword, returnMenu, &bContinue);
    }

    else if (strcmp(password, currentPassword) == 0)
    {

        adminLogin(password, currentPassword, returnMenu, &bContinue);
    }

    if (bContinue == true)
    {
        do
        {

            system("cls");

            printf("\n[A] to add record");
            printf("\n[E] to edit record");
            printf("\n[D] to delete record");
            printf("\n[I] to import data");
            printf("\n[X] to export record");
            printf("\n\n[R] to return to main menu");

            printf("\n\nEnter: ");
            scanf(" %c", &adminInput);

            switch (adminInput)
            {

            case 'a':
            case 'A':
                addRecord(records, ctrRecord);
                switchValid = true;
                *returnMenu = true;
                break;

            case 'e':
            case 'E':
                // function
                switchValid = true;
                break;

            case 'd':
            case 'D':
                // function
                switchValid = true;
                break;

            case 'i':
            case 'I':
                // function
                switchValid = true;
                break;

            case 'x':
            case 'X':
                // function
                switchValid = true;
                break;

            case 'r':
            case 'R':
                *returnMenu = true;
                switchValid = true;
                break;

            default:
                switchValid = false;
            }
        } while (switchValid == false || returnManageData == true);
    }
}

/* This function serves as the main menu of the program.
@param records is the array of structure for quiz records.
@param password This holds the inputted string as a password.
@param tempPassword is used to compare the password input.
@param currentPassword is used if user will return to manage data.
@return void
*/
void enterMenu(struct quizRecord *records, String30 password, String30 tempPassword, String30 currentPassword)
{

    int ctrRecord = 0;
    char cInput;
    bool validInput = false;
    bool returnMenu = true;

    while (validInput == false || returnMenu == true)
    {

        system("cls");
        printf("This is a General Knowledge Quiz Game!");
        printf("\n\nPress [P] to play.\n\n");
        printf("Press [M] to manage data\n\n");

        printf("Enter: ");
        scanf("%c", &cInput);

        switch (cInput)
        {

        case 'p':
        case 'P':
            // function
            validInput = true;
            break;

        case 'm':
        case 'M':
            validInput = true;
            returnMenu = false;
            manageData(records, password, tempPassword, currentPassword, &returnMenu, &ctrRecord);
            break;

        default:
            validInput = false;
        }
    }
}

int main()
{

    String30 password;
    String30 tempPassword;

    // This will change once user registers.
    String30 currentPassword = "N/A";

    struct quizRecord records[SIZE];

    enterMenu(records, password, tempPassword, currentPassword);

    return 0;
}