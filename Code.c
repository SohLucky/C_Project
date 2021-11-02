/*
5 Functions
1) listNameCards()
    - Functionality: Prints the contents in the name card holder [DONE]
    - Prints "listNameCards():" when executed [DONE]
    - If empty, print "The name card holder is empty" [DONE]
2) addNameCard()
    - Functionality: Adds a new name card
    - Stored in an array of NameCard Structures in ascending order,[DONE]
    according to integer value of nameCardID
    - Features
        - After adding, print "The name card has been added successfully" [DONE]
        - If namecard existed, print "The nameCardID has already existed" [DONE]
        - If namecard holder is full, print "The name card holder is full" and do nothing [DONE]
3) removeNameCard()
    - Functionality: Removes the first appearance of the target person name [DONE]
    - Casing of the string should not matter, all characters in the string should be converted into lower/upper case [DONE]
    - Features
        - After name removed, print "The name card is removed" and print the contents of the name card [DONE]
        - If empty, print "The name card is empty" [DONE]
        - If person doesnt exists, print "The target person is not in the name card holder" [DONE]
4) getNameCard()
    - Functionality : Finds first appearance of target person and prints contents to the screen [DONE]
    - Prints "getNameCard():" when executed [DONE]
    - Features
        - If person exists, print "The target person name is found" and print contents [DONE]
        - If person does not exists, print "The target person name is not found" [DONE]
        - Letter Casing does not matter
5) quit()
    - Funcationality : Quit the program :)
*/

# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>

# define MAX 5
# define NAME_MAX 20

typedef struct NameCard{
    int nameCardID;
    char personName[NAME_MAX];
    char companyName[NAME_MAX];
};

// Prototype Declaration
void addname(struct NameCard card[MAX], int items, int id, char p_name[NAME_MAX], char c_name[NAME_MAX]);
void removename(struct NameCard card[MAX], char p_name[NAME_MAX], int item_count, int index);
void lowercase(char* str);
void printcard(struct NameCard card[MAX],int index);

int main()
{
    // Declaration of variables
    int choice, num_of_items = 0;
    struct NameCard CardHolder1[MAX];
    // Menu
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");
    do{
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:;
        // Printing in reverse order
            int i;
            printf("listNameCards():\n");
            if (num_of_items == 0)
                printf("The name card holder is empty\n");
            else
                for (i = 0; i < num_of_items; i++)
                {
                    /*printf("nameCardID: %d\n", CardHolder1[i].nameCardID);
                    printf("personName: %s\n", CardHolder1[i].personName);
                    printf("companyName: %s\n", CardHolder1[i].companyName);*/
                    printcard(CardHolder1, i);
                }   
            break;
        case 2:;
            char *p, *c, id[3];
            int count;
            char p_name[NAME_MAX], c_name[NAME_MAX];
            bool error = false;
            
            printf("addNameCard():\n");
            printf("Enter nameCardID:\n");
            //fflush(stdin);
            scanf("\n"); // Removes "\n" from the buffer
            fgets(id, 3, stdin);
            printf("Enter personName:\n");
            scanf("\n"); // Removes "\n" from the buffer
            //fflush(stdin);
            fgets(p_name, NAME_MAX, stdin);
            if (p = strchr(p_name, '\n')) *p = '\0';
            printf("Enter companyName:\n");
            //fflush(stdin);
            scanf("\n"); // Removes "\n" from the buffer
            fgets(c_name, NAME_MAX, stdin);
            if (c = strchr(c_name, '\n')) *c = '\0';
            // Checks for duplicate nameCardID in array
            if (num_of_items != 0)
            {
                if (num_of_items == MAX)
                {
                    printf("The name card holder is full\n");
                    break;
                }
                else
                {
                    for (count = 0; count < num_of_items; count++)
                    {
                        if (CardHolder1[count].nameCardID == atoi(id))
                            {
                                printf("The nameCardID has already existed\n");
                                error = true;
                                break;
                            }
                    }
                    if (error == true) break;
                }
            }
            addname(CardHolder1, num_of_items, atoi(id), p_name, c_name);
            num_of_items += 1;
            break;
        case 3:;
            int j;
            char remove_name[NAME_MAX], lower_pname[NAME_MAX];
            bool exists = true;

            printf("removeNameCard():\n");
            printf("Enter personName:\n");
            scanf("\n"); // Removes "\n" from the buffer
            fgets(remove_name, NAME_MAX, stdin);
            if (c = strchr(remove_name, '\n')) *c = '\0';
            if (num_of_items == 0)
            {
                printf("The name card holder is empty\n");
                break;
            }
            else
            {
                lowercase(remove_name);
                for (j = 0; j < num_of_items; j++)
                {
                    strcpy(lower_pname, CardHolder1[j].personName);
                    lowercase(lower_pname);
                    //printf("USER INPUT: %s\n", remove_name);
                    //printf("NAME CARD: %s\n", lower_pname);
                    //printf("STRING CMP: %d", strcmp(lower_pname, remove_name));
                    if (strcmp(lower_pname, remove_name) == 0)
                    {
                        //printf("DEBUG 1");
                        removename(CardHolder1, CardHolder1[j].personName, num_of_items, j);
                        num_of_items -= 1;
                        exists = true;
                        break;
                    }
                    else
                    {
                        //printf("DEBUG 1");
                        exists = false;
                    }
                }
            }
            if (exists == false) printf("The target person name is not in the name card holder\n");
            break;     
        case 4:;
            char target[NAME_MAX], card_name[NAME_MAX];
            int counter;
            bool target_exists = true;
            printf("getNameCard():\n");
            printf("Enter personName:\n");
            scanf("\n"); // Removes "\n" from the buffer
            fgets(target, NAME_MAX, stdin);
            if (c = strchr(target, '\n')) *c = '\0';
            if (num_of_items == 0)
                printf("The name card holder is empty\n");
            else
                for (counter = 0; counter < num_of_items; counter++)
                {
                    strcpy(card_name,CardHolder1[counter].personName);
                    lowercase(card_name);
                    lowercase(target);
                    if (strcmp(card_name,target) == 0)
                    {
                        printf("The target person name is found\n");
                        /*printf("nameCardID: %d\n", CardHolder1[counter].nameCardID);
                        printf("personName: %s\n", CardHolder1[counter].personName);
                        printf("companyName: %s\n", CardHolder1[counter].companyName);*/
                        printcard(CardHolder1, counter);
                        target_exists = true;
                        break;
                    }
                    target_exists = false;
                }
            if (target_exists == false) printf("The target person name is not found\n");
            break;
        default:
            break;
        }
    } while (choice != 5);
    return 0;
}

void addname(struct NameCard card[MAX], int items, int id, char p_name[NAME_MAX], char c_name[NAME_MAX])
{
    struct NameCard last;
    int s, loop;
    //printf("ADDING TO SLOT: %d", items);
    card[items].nameCardID = id;
    strcpy(card[items].personName,p_name);
    strcpy(card[items].companyName,c_name);
    
    //printf("items: %d", items);
    items += 1;
    if (items != 0) 
    {
        last = card[items-1];
        for (s = 0; s < items; s++)
        {
            //printf("COMPARING %d and %d\n",last.nameCardID, card[s].nameCardID);
            if (last.nameCardID < card[s].nameCardID)
            { 
                for (loop = items - 2; s <= loop; loop--)
                {
                    card[loop + 1] = card[loop];
                    //printf("Placing %d into slot %d\n", card[loop + 1].nameCardID, loop+1);
                }
                card[s]= last;
                break;
            }
        }
    }
    printf("The name card has been added successfully\n");
    return;
}
void removename(struct NameCard card[MAX], char p_name[NAME_MAX], int item_count, int index)
{
    int loop;
    printf("The name card is removed\n");
    /*printf("nameCardID: %d\n", card[index].nameCardID);
    printf("personName: %s\n", card[index].personName);
    printf("companyName: %s\n", card[index].companyName);*/
    printcard(card, index);
    for (loop = index; loop < item_count; loop++)
    {
        card[loop] = card[loop + 1];
    }
    //item_count -= 1;
    return;
}
void lowercase(char *str)
{
    while (*str != '\0')
    {
        *str = tolower(*str);
        str++;
    }
}
void printcard(struct NameCard card[MAX],int index)
{
    printf("nameCardID: %d\n", card[index].nameCardID);
    printf("personName: %s\n", card[index].personName);
    printf("companyName: %s\n", card[index].companyName);
}
