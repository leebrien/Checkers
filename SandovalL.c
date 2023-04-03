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
#include <stdlib.h>
#include <time.h>

#define SIZE 20

typedef char String20[21];
typedef char String150[151];
typedef char String30[31];

// This struct holds the components of a question
struct quizRecord
{
    String20 Topic;
    int Number;
    String150 Question;
    String30 C1;
    String30 C2;
    String30 C3;
    String30 Answer;
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
    bool inputValid = false;
    bool answerMatch = false;
    char cInput;

    do
    {
        system("cls");

        printf("Enter a question: ");
        getString(tempQuestion, 151);
        printf("\nEnter the answer: ");
        getString(tempAnswer, 31);

        existingRecord = false;

        for (int i = 0; i < SIZE; i++)
        {

            if (strcmp(tempQuestion, records[i].Question) == 0)
            {

                if (strcmp(tempAnswer, records[i].Answer) == 0)
                {

                    system("cls");
                    printf("%s\n", records[i].Topic);
                    printf("%d. %s\n", records[i].Number, records[i].Question);
                    printf("A) %s\n", records[i].C1);
                    printf("B) %s\n", records[i].C2);
                    printf("C) %s\n", records[i].C3);
                    printf("\nAnswer: %s\n\n", records[i].Answer);

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
            strcpy(records[*ctrRecord].Answer, tempAnswer);

            do
            {
                printf("%s", records[*ctrRecord].Question);
                printf("\n%s", records[*ctrRecord].Answer);

                printf("\n\nEnter topic: ");
                getString(records[*ctrRecord].Topic, 21);
                printf("Enter 1st choice: ");
                getString(records[*ctrRecord].C1, 31);
                printf("Enter 2nd choice: ");
                getString(records[*ctrRecord].C2, 31);
                printf("Enter 3rd choice: ");
                getString(records[*ctrRecord].C3, 31);

                records[*ctrRecord].Number = *ctrRecord + 1;

                if (strcmp(records[*ctrRecord].Answer, records[*ctrRecord].C1) == 0 ||
                    strcmp(records[*ctrRecord].Answer, records[*ctrRecord].C2) == 0 ||
                    strcmp(records[*ctrRecord].Answer, records[*ctrRecord].C3) == 0)
                {

                    *ctrRecord += 1;

                    system("cls");
                    printf("Record Successfully Added!\n\n");
                    system("pause");

                    answerMatch = true;
                }

                else
                {

                    system("cls");

                    printf("Answer does not match any of the choices, try again.\n\n\n");

                    system("pause");
                    system("cls");
                }

            } while (answerMatch == false);
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
                    inputValid = true;
                    break;

                case 'N':
                case 'n':
                    returnMenu = false;
                    inputValid = true;
                    break;

                default:
                    inputValid = false;
                    break;
                }

            } while (inputValid == false);
        }

    } while (existingRecord == true && returnMenu == false);
}

/* This function is for editing existing records of the quiz.
Precondition: Topic names are case sensitive.
@param records is the array of structures for quiz records.
@param ctrRecord is the value of the number of existing records.
@param returnManageData is an option to return to manage data menu when opt enter a topic.
@return void
*/
void editRecord(struct quizRecord *records, int *ctrRecord, bool *returnManageData)
{

    int tempSize = *ctrRecord;
    int numberInput;
    int inputIndex;

    char uniqueTopics[tempSize][21];

    String20 topicInput;

    bool inputValid = false;

    if (*ctrRecord > 0)
    {

        // Copy all the topic names into a different string array.
        for (int i = 0; i < tempSize; i++)
        {
            strcpy(uniqueTopics[i], records[i].Topic);
        }

        // Remove the duplicate topic names of the array.
        for (int j = 0; j < tempSize; j++)
        {

            for (int k = j + 1; k < tempSize; k++)
            {

                if (strcmp(uniqueTopics[j], uniqueTopics[k]) == 0)
                {

                    for (int l = k; l < tempSize; l++)
                    {

                        strcpy(uniqueTopics[l], uniqueTopics[l + 1]);
                    }

                    tempSize -= 1;

                    k--;
                }
            }
        }

        do
        {
            do
            {
                system("cls");
                printf("Choose a topic or return to menu\n\n");

                for (int i = 0; i < tempSize; i++)
                {

                    printf(" %d. %s\n", i + 1, uniqueTopics[i]);
                }

                printf("\n[%d] Return to menu\n", 0);

                printf("\nEnter: ");
                getString(topicInput, 31);

                if (strcmp(topicInput, "0") == 0)
                {

                    inputValid = true;
                }

                for (int i = 0; i < tempSize; i++)
                {

                    if (strcmp(topicInput, uniqueTopics[i]) == 0)
                    {

                        inputValid = true;
                    }
                }

                if (inputValid == false)
                {

                    system("cls");
                    printf("Input does not match any of the given topics, try again.\n\n");
                    system("pause");
                }

            } while (inputValid == false);

            if (strcmp(topicInput, "0") == 0)
            {

                *returnManageData = true;
            }

            else
            {

                system("cls");

                do
                {

                    inputValid = false;

                    printf("\nChoose a question (Enter corresponding number)\n\n");

                    for (int i = 0; i < *ctrRecord; i++)
                    {

                        if (strcmp(topicInput, records[i].Topic) == 0)
                        {

                            printf("[%d] %s\n", records[i].Number, records[i].Question);
                        }
                    }

                    printf("\n[0] Return");

                    printf("\n\nEnter: ");

                    scanf("%d", &numberInput);

                    if (numberInput == 0)
                    {

                        inputValid = true;
                    }

                    else
                    {

                        for (int i = 0; i < *ctrRecord; i++)
                        {

                            if (numberInput == records[i].Number)
                            {

                                inputValid = true;

                                inputIndex = i;
                            }
                        }
                    }

                    if (inputValid == false)
                    {

                        system("cls");
                        printf("Input does not match with any of the given question numbers, try again.\n\n");
                        system("pause");
                        system("cls");
                    }

                } while (inputValid == false);

                if (numberInput != 0)
                {
                    do
                    {

                        inputValid = false;
                        system("cls");

                        printf("Topic: %s\n[%d] %s\nC1: %s\nC2: %s\nC3: %s\n\nAnswer: %s",
                               records[inputIndex].Topic, records[inputIndex].Number,
                               records[inputIndex].Question, records[inputIndex].C1,
                               records[inputIndex].C2, records[inputIndex].C3,
                               records[inputIndex].Answer);

                        printf("\n----------------------\nChoose which field to modify: \n\n");
                        printf("[1] Topic");
                        printf("\n[2] Question");
                        printf("\n[3] 1st Choice");
                        printf("\n[4] 2nd Choice");
                        printf("\n[5] 3rd Choice");
                        printf("\n[6] Answer");
                        printf("\n\n[0] Cancel");

                        printf("\n\nEnter: ");
                        scanf("%d", &numberInput);

                        switch (numberInput)
                        {

                        case 1:
                            printf("\nEnter topic: ");
                            getString(records[inputIndex].Topic, 21);
                            inputValid = true;
                            break;

                        case 2:
                            printf("\nEnter Question: ");
                            getString(records[inputIndex].Question, 151);
                            inputValid = true;
                            break;

                        case 3:
                            printf("\nEnter C1: ");
                            getString(records[inputIndex].C1, 31);
                            inputValid = true;
                            break;

                        case 4:
                            printf("\nEnter C2: ");
                            getString(records[inputIndex].C2, 31);
                            inputValid = true;
                            break;

                        case 5:
                            printf("\nEnter C3: ");
                            getString(records[inputIndex].C3, 31);
                            inputValid = true;
                            break;

                        case 6:
                            printf("\nEnter Answer: ");
                            getString(records[inputIndex].Answer, 31);
                            inputValid = true;
                            break;

                        case 0:
                            inputValid = true;
                            break;

                        default:
                            inputValid = false;
                        }

                        if (numberInput == 0)
                        {

                            system("cls");
                            printf("Cancelled.\n\n");
                            system("pause");
                        }

                        else if (inputValid == true && numberInput != 0)
                        {

                            system("cls");
                            printf("Edit Successful\n\n");
                            system("pause");
                        }

                        else
                        {

                            system("cls");
                            printf("Input does not match any of the corresponding numbers, try again.\n\n");
                            system("pause");
                        }

                    } while (inputValid == false);
                }
            }

        } while (*returnManageData == false);
    }

    else
    {

        system("cls");
        printf("There are no records to edit.\n\n");
        system("pause");
        *returnManageData = true;
    }
}

/* This function is for deleting existing records of the quiz.
Precondition: Topic names are case sensitive.
@param records is the array of structures for quiz records.
@param ctrRecord is the value of the number of existing records.
@param returnManageData is an option to return to manage data menu when opt enter a topic.
@return void
*/
void deleteRecord(struct quizRecord *records, int *ctrRecord,
                  bool *returnManageData)
{

    int tempSize = *ctrRecord;
    int numberInput;
    int inputIndex;

    char uniqueTopics[tempSize][21];
    char cInputDelete;

    String20 topicInput;

    bool inputValid = false;

    if (*ctrRecord > 0)
    {

        // Copy all the topic names into a different string array.
        for (int i = 0; i < tempSize; i++)
        {
            strcpy(uniqueTopics[i], records[i].Topic);
        }

        // Remove the duplicate topic names of the array.
        for (int j = 0; j < tempSize; j++)
        {

            for (int k = j + 1; k < tempSize; k++)
            {

                if (strcmp(uniqueTopics[j], uniqueTopics[k]) == 0)
                {

                    for (int l = k; l < tempSize; l++)
                    {

                        strcpy(uniqueTopics[l], uniqueTopics[l + 1]);
                    }

                    tempSize -= 1;

                    k--;
                }
            }
        }

        do
        {
            do
            {
                system("cls");
                printf("Choose a topic or return to menu\n\n");

                for (int i = 0; i < tempSize; i++)
                {

                    printf(" %d. %s\n", i + 1, uniqueTopics[i]);
                }

                printf("\n[%d] Return to menu\n", 0);

                printf("\nEnter: ");
                getString(topicInput, 31);

                if (strcmp(topicInput, "0") == 0)
                {

                    inputValid = true;
                }

                for (int i = 0; i < tempSize; i++)
                {

                    if (strcmp(topicInput, uniqueTopics[i]) == 0)
                    {

                        inputValid = true;
                    }
                }

                if (inputValid == false)
                {

                    system("cls");
                    printf("Input does not match any of the given topics, try again.\n\n");
                    system("pause");
                }

            } while (inputValid == false);

            if (strcmp(topicInput, "0") == 0)
            {

                *returnManageData = true;
            }

            else
            {

                system("cls");

                do
                {

                    inputValid = false;

                    for (int i = 0; i < *ctrRecord; i++)
                    {

                        if (strcmp(topicInput, records[i].Topic) == 0)
                        {

                            printf("[%d] %s\n", records[i].Number, records[i].Question);
                        }
                    }

                    printf("\nChoose a question (Enter corresponding number): ");
                    scanf("%d", &numberInput);

                    for (int i = 0; i < *ctrRecord; i++)
                    {

                        if (numberInput == records[i].Number)
                        {

                            inputValid = true;

                            inputIndex = i;
                        }
                    }

                    if (inputValid == false)
                    {

                        system("cls");
                        printf("Input does not match with any of the given question numbers, try again.\n\n");
                        system("pause");
                        system("cls");
                    }

                } while (inputValid == false);

                do
                {
                    printf("\nAre you sure you want to delete this record?");
                    printf("\n[Y] Yes\n[N] No\n\n");

                    printf("Enter: ");
                    scanf(" %c", &cInputDelete);

                    switch (cInputDelete)
                    {

                    case 'y':
                    case 'Y':

                        for (int i = inputIndex; i < *ctrRecord; i++)
                        {

                            strcpy(records[i].Topic, records[i + 1].Topic);
                            records[i + 1].Number -= 1;
                            strcpy(records[i].Question, records[i + 1].Question);
                            strcpy(records[i].C1, records[i + 1].C1);
                            strcpy(records[i].C2, records[i + 1].C2);
                            strcpy(records[i].C3, records[i + 1].C3);
                            strcpy(records[i].Answer, records[i + 1].Answer);
                        }

                        *ctrRecord -= 1;
                        inputValid = true;
                        break;

                    case 'n':
                    case 'N':
                        inputValid = true;
                        break;

                    default:
                        inputValid = false;
                    }

                    if (cInputDelete == 'Y' || cInputDelete == 'y')
                    {

                        system("cls");
                        printf("Record Deleted!\n\n");
                        system("pause");
                    }

                    else if (inputValid == false)
                    {

                        system("cls");
                        printf("Invalid input, try again.\n");
                        system("pause");
                    }

                } while (inputValid == false);
            }

        } while (*returnManageData == false);
    }

    else
    {

        system("cls");
        printf("There are no records to delete.\n\n");
        system("pause");
        *returnManageData = true;
    }
}

/* This function reads a string of a file.
@param records is the array of structures for quiz records.
@param ctrRecord is the value of the number of existing records.
@return void
*/
void readString(FILE *fp, char tempString[], int nSize)
{

    int i = 0;

    char ch = '\0';

    int nEnd;

    do
    {
        nEnd = fscanf(fp, "%c", &ch);

        if (i >= nSize || ch == '\n')
        {

            nEnd = -1;
        }

        else
        {
            tempString[i] = ch;
            i++;
            tempString[i] = '\0';
        }

    } while (nEnd == 1);
}

/* This function imports a record through a specified filename.
Precondition: file name is limited to 30 characters.
@param records is the array of structures for quiz records.
@param ctrRecord is the value of the number of existing records.
@return void
*/
void importRecord(struct quizRecord *records, int *ctrRecord, bool* returnManageData)
{

    String30 filename;

    struct quizRecord temp;

    FILE *fp;

    bool validInput = false;

    do
    {

        system("cls");
        printf("Enter filename.");
        printf("\n\nor\n");
        printf("\n[0] to return to menu.");

        printf("\n\nEnter: ");

        // Include ".txt"
        getString(filename, 31);
        
        //If user exits, signal return.
        if (strcmp(filename, "0") == 0){

            *returnManageData = true;
            validInput = true;
        }

        //Else, proceed with importing file to program.
        else{

            if ((fp = fopen(filename, "r")) != 0)
            {

                readString(fp, temp.Topic, 21);
                fscanf(fp, "%d ", &temp.Number);
                readString(fp, temp.Question, 151);
                readString(fp, temp.C1, 31);
                readString(fp, temp.C2, 31);
                readString(fp, temp.C3, 31);
                readString(fp, temp.Answer, 31);

                records[*ctrRecord] = temp;

                system("cls");
                printf("Import Successful.\n\n------------------------------\n");

                printf("[T]  %s\n\n[#]  %d\n\n[Q]  %s\n\n[C1] %s\n\n[C2] %s\n\n[C3] %s\n\n[A]  %s\n------------------------------\n\n", records[*ctrRecord].Topic,
                        records[*ctrRecord].Number, records[*ctrRecord].Question,
                        records[*ctrRecord].C1, records[*ctrRecord].C2,
                        records[*ctrRecord].C3, records[*ctrRecord].Answer);
                        
                system("pause");

                *ctrRecord += 1;

                validInput = true;
                *returnManageData = true;

                fclose (fp);

            }

            //Print error message if file does not exist.
            else{

                system("cls");
                printf("FILE NOT FOUND.\n\n");
                system("pause");

            }
        }


    } while (validInput == false);

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
void manageData(struct quizRecord *records, String30 password, String30 tempPassword,
                String30 currentPassword, bool *returnMenu, int *ctrRecord)
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
                returnManageData = true;
                break;

            case 'e':
            case 'E':
                editRecord(records, ctrRecord, &returnManageData);
                switchValid = true;
                break;

            case 'd':
            case 'D':
                deleteRecord(records, ctrRecord, &returnManageData);
                switchValid = true;
                break;

            case 'i':
            case 'I':
                importRecord(records, ctrRecord, &returnManageData);
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
                returnManageData = false;
                switchValid = true;
                break;

            default:
                switchValid = false;
            }
        } while (switchValid == false || returnManageData == true);
    }
}

/* This function shuffles the the values of the temporary array
   of which holds the question numbers of a topic
Precondition: There is at least one record.
@param topicQuestions is the value of questions with the same topic
@param tempArray is the temporary array that holds the question numbers
@return
*/
void randArray(int topicQuestions, int tempArray[topicQuestions])
{

    int j, temp;

    srand(time(NULL));

    for (int i = 0; i < topicQuestions; i++)
    {

        j = (rand() % topicQuestions - 1) + 1;

        temp = tempArray[i];
        tempArray[i] = tempArray[j];
        tempArray[j] = temp;
    }
}
/* This function is the quiz game itself.
Precondition: cInput from playGame() must be 'p' or 'P'
@param records is the array of structures for quiz records.
@param playerName is the name of the player.
@param ctrRecord is the value of the number of existing records.
@param returnMenu This is for choosing if the user wishes to return to the
       main menu after an incorrect password input.
@param quizScore is the score of the player.
@return void
*/
void startGame(struct quizRecord *records, String30 playerName, int *ctrRecord, bool *returnMenu, int *quizScore)
{

    int tempSize = *ctrRecord;
    int topicQuestions = 0;
    int tempArray[20];

    char uniqueTopics[tempSize][21];

    String30 quizAnswer;

    bool inputValid;
    bool topicMatch = false;
    bool endGame = false;

    if (*ctrRecord > 0)
    {
        system("cls");

        printf("What is your name?: ");
        getString(playerName, 31);

        printf("\n");
        system("pause");
        system("cls");

        // Copy all the topic names into a different string array.
        for (int i = 0; i < tempSize; i++)
        {
            strcpy(uniqueTopics[i], records[i].Topic);
        }

        // Remove the duplicate topic names of the array.
        for (int j = 0; j < tempSize; j++)
        {

            for (int k = j + 1; k < tempSize; k++)
            {

                if (strcmp(uniqueTopics[j], uniqueTopics[k]) == 0)
                {

                    for (int l = k; l < tempSize; l++)
                    {

                        strcpy(uniqueTopics[l], uniqueTopics[l + 1]);
                    }

                    tempSize -= 1;

                    k--;
                }
            }
        }

        do
        {
            topicQuestions = 0;
            String30 topicInput;

            // Loop until input is valid.
            do
            {
                inputValid = false;

                system("cls");

                printf("Score: %d\n--------------------\n\n", *quizScore);
                printf("Choose a topic\n\n");

                // Display available topics and option to end game.
                for (int i = 0; i < tempSize; i++)
                {
                    printf(" %d. %s\n", i + 1, uniqueTopics[i]);
                }

                printf("[0] End Game.\n");

                printf("\nEnter: ");
                getString(topicInput, 31);

                // Check if input matches any of the existing record topics.
                for (int i = 0; i < *ctrRecord; i++)
                {

                    if (strcmp(topicInput, records[i].Topic) == 0)
                    {
                        topicMatch = true;
                        inputValid = true;
                    }

                    // If input is 0, signal exit the game.
                    else if (strcmp(topicInput, "0") == 0)
                    {
                        inputValid = true;
                        *returnMenu = true;
                        endGame = true;
                    }
                }

                // Show error if invalid input.
                if (inputValid == false)
                {

                    system("cls");
                    printf("Input does not match any of the given topics, try again.\n\n");
                    system("pause");
                }

            } while (inputValid == false);

            system("cls");

            // If exit game, show score.
            if (strcmp(topicInput, "0") == 0)
            {

                system("cls");
                printf("Your score: %d\n\n", *quizScore);
                system("pause");
            }

            // Else, proceed with displaying question and getting answer.
            else if (topicMatch == true)
            {
                for (int i = 0; i < *ctrRecord; i++)
                {

                    if (strcmp(topicInput, records[i].Topic) == 0)
                    {

                        int j = records[i].Number;

                        tempArray[topicQuestions] = j;

                        topicQuestions += 1;
                    }
                }

                randArray(topicQuestions, tempArray);

                for (int i = 0; i < *ctrRecord; i++)
                {

                    if (tempArray[0] == records[i].Number)
                    {
                        printf("Score: %d\n--------------------\n\n", *quizScore);
                        printf("%d. %s\n", records[i].Number, records[i].Question);
                        printf("C1) %s\n", records[i].C1);
                        printf("C2) %s\n", records[i].C2);
                        printf("C3) %s\n", records[i].C3);

                        printf("\nWhat is your answer?: ");
                        getString(quizAnswer, 31);

                        if (strcmp(quizAnswer, records[i].Answer) == 0)
                        {

                            *quizScore += 1;

                            system("cls");
                            printf("Correct! your scsore is %d point/s.\n\n", *quizScore);
                            system("pause");
                        }

                        else
                        {

                            system("cls");
                            printf("Sorry, your answer is incorrect.\n\n");
                            system("pause");
                        }
                    }
                }
            }
        } while (endGame == false);
    }

    else
    {

        system("cls");
        printf("There are no existing records.\n\n");
        system("pause");
    }
}

/* This function displays the player's name and scores from an imported file and the
   current score accumulated from the program.
Precondition: cInput from playGame() must be 'p' or 'P'
@param playerName is the name of the player.
@param quizScore is the score of the player.
@return void
*/
void viewScores(String30 playerName, int *quizScore)
{

    system("cls");
    printf("Name: %s\n", playerName);
    printf("Score (Current): %d\n\n", *quizScore);
    // Score (File);

    system("pause");
}

/* This function is the menu of the play option of the program.
Precondition: cInput from int main() must be 'p' or 'P'
@param records is the array of structures for quiz records.
@param returnMenu This is for choosing if the user wishes to return to the
       main menu after an incorrect password input.
@param ctrRecord is the value of the number of existing records.
@param quizScore is the score of the player.
@return void
*/
void playGame(struct quizRecord *records, bool *returnMenu, int *ctrRecord, int *quizScore)
{

    char cInput;
    bool validInput = false;
    String30 playerName;

    do
    {
        system("cls");

        printf("[P] to play");
        printf("\n[V] to view scores");
        printf("\n[E] to exit");

        printf("\n\nEnter: ");
        scanf(" %c", &cInput);

        switch (cInput)
        {

        case 'p':
        case 'P':
            startGame(records, playerName, ctrRecord, returnMenu, quizScore);
            validInput = true;
            *returnMenu = false;
            break;

        case 'v':
        case 'V':
            viewScores(playerName, quizScore);
            validInput = true;
            *returnMenu = false;
            break;

        case 'e':
        case 'E':
            *returnMenu = true;
            validInput = true;
            break;

        default:
            validInput = false;
        }

        if (validInput == false)
        {

            system("cls");
            printf("Invalid input, try again.\n\n");
            system("pause");
        }

    } while (validInput == false || *returnMenu == false);
}

/* This function serves as the main menu of the program.
@param records is the array of structure for quiz records.
@param password This holds the inputted string as a password.
@param tempPassword is used to compare the password input.
@param currentPassword is used if user will return to manage data.
@param quizScore is the score of the player.
@return void
*/
void enterMenu(struct quizRecord *records, String30 password,
               String30 tempPassword, String30 currentPassword,
               int *quizScore)
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
            playGame(records, &returnMenu, &ctrRecord, quizScore);
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

    int quizScore = 0;

    // This will change once user registers.
    String30 currentPassword = "N/A";

    struct quizRecord records[SIZE];

    enterMenu(records, password, tempPassword, currentPassword, &quizScore);

    return 0;
}