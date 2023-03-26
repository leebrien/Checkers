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

typedef char String50[21];
typedef char String200[151];
typedef char String30[31];

// This struct holds the components of a question
struct quizRecord
{
    String50 topicName;
    int qNumber;
    String200 Question;
    String30 C1;
    String30 C2;
    String30 C3;
    String30 qAnswer;
};

typedef struct quizRecord quizRecord;

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

/* This function is for getting the password of the admin.
Precondition: The length of the password is limited to 30 characters
@param password This holds the inputted string as a password
@param returnMenu This is for choosing if the user wishes to return to the 
       main menu after an incorrect password input.
@return void
*/
void adminRegistration(String30 password, bool *returnMenu)
{

    String30 tempPassword;
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

            validInput = true;
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

/* This function is the menu for admins which manages the data of the program
Precondition: cInput from int main() must be 'm' or 'M'
@param returnMenu This is for choosing if the user wishes to return to the 
       main menu after an incorrect password input.
@return void
*/
void manageData(bool *returnMenu)
{
    String30 password;

    system("cls");

    adminRegistration(password, returnMenu);
    
    
}

/* This function is the menu for admins which manages the data of the program
Precondition: cInput from int main() must be 'm' or 'M'
@param <name> <param_description>
@return void
*/
void enterMenu()
{

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
            manageData(&returnMenu);
            break;

        default:
            validInput = false;
        }
    }
}

int main()
{

    enterMenu();

    return 0;
}