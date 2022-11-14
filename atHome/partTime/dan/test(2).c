#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables to save dish information from different customers
char customer_1[12][50]; // string array, customer 1 can order up to 12 dishes,each dish is an array of 50 characters
char customer_2[12][50];
char customer_3[12][50];
char customer_4[12][50];
char customer_5[12][50];
char customer_6[12][50];

int price = 0; // global variable to calculate total cost
int count[6] = {0, 0, 0, 0, 0, 0};
int checkData(char *DC, int num, int i)
{
    count[i]++;
    if (i == 0) // first customer
    {
        if (strcmp(DC, "A1") == 0)
        {
            strcpy(customer_1[num], "A1\tHAM AND EGG\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "A2") == 0)
        {
            strcpy(customer_1[num], "A2\tBACON AND CHEESE\t$ 10");
            printf("here\n");
            printf("%s\n",customer_1[num]);
            price += 10;
        }
        else if (strcmp(DC, "A3") == 0)
        {
            strcpy(customer_1[num], "A3\tTUNA SALAD\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "A4") == 0)
        {
            strcpy(customer_1[num], "A4\tBEEF SOUP\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "B1") == 0)
        {
            strcpy(customer_1[num], "B1\tSPICY BEEF BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "B2") == 0)
        {
            strcpy(customer_1[num], "B2\tPORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "B3") == 0)
        {
            strcpy(customer_1[num], "B3\tOVEN CHICKEN BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "B4") == 0)
        {
            strcpy(customer_1[num], "B4\tPULLED BEEF BARBECUE BURGUR\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "C1") == 0)
        {
            strcpy(customer_1[num], "C1\tSPICY PORK BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "C2") == 0)
        {
            strcpy(customer_1[num], "C2\tVEGETABLE PORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "C3") == 0)
        {
            strcpy(customer_1[num], "C3\tOVEN PORK BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "C4") == 0)
        {
            strcpy(customer_1[num], "C4\tPULLED PORK BARBECUE\t$ 25");
            price += 25;
        }
    }
    else if (i == 1)
    {
        if (strcmp(DC, "A1") == 0)
        {
            strcpy(customer_2[num], "A1\tHAM AND EGG\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "A2") == 0)
        {
            strcpy(customer_2[num], "A2\tBACON AND CHEESE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "A3") == 0)
        {
            strcpy(customer_2[num], "A3\tTUNA SALAD\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "A4") == 0)
        {
            strcpy(customer_2[num], "A4\tBEEF SOUP\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "B1") == 0)
        {
            strcpy(customer_2[num], "B1\tSPICY BEEF BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "B2") == 0)
        {
            strcpy(customer_2[num], "B2\tPORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "B3") == 0)
        {
            strcpy(customer_2[num], "B3\tOVEN CHICKEN BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "B4") == 0)
        {
            strcpy(customer_2[num], "B4\tPULLED BEEF BARBECUE BURGUR\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "C1") == 0)
        {
            strcpy(customer_2[num], "C1\tSPICY PORK BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "C2") == 0)
        {
            strcpy(customer_2[num], "C2\tVEGETABLE PORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "C3") == 0)
        {
            strcpy(customer_2[num], "C3\tOVEN PORK BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "C4") == 0)
        {
            strcpy(customer_2[num], "C4\tPULLED PORK BARBECUE\t$ 25");
            price += 25;
        }
    }
    else if (i == 2)
    {
        if (strcmp(DC, "A1") == 0)
        {
            strcpy(customer_3[num], "A1\tHAM AND EGG\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "A2") == 0)
        {
            strcpy(customer_3[num], "A2\tBACON AND CHEESE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "A3") == 0)
        {
            strcpy(customer_3[num], "A3\tTUNA SALAD\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "A4") == 0)
        {
            strcpy(customer_3[num], "A4\tBEEF SOUP\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "B1") == 0)
        {
            strcpy(customer_3[num], "B1\tSPICY BEEF BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "B2") == 0)
        {
            strcpy(customer_3[num], "B2\tPORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "B3") == 0)
        {
            strcpy(customer_3[num], "B3\tOVEN CHICKEN BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "B4") == 0)
        {
            strcpy(customer_3[num], "B4\tPULLED BEEF BARBECUE BURGUR\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "C1") == 0)
        {
            strcpy(customer_3[num], "C1\tSPICY PORK BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "C2") == 0)
        {
            strcpy(customer_3[num], "C2\tVEGETABLE PORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "C3") == 0)
        {
            strcpy(customer_3[num], "C3\tOVEN PORK BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "C4") == 0)
        {
            strcpy(customer_3[num], "C4\tPULLED PORK BARBECUE\t$ 25");
            price += 25;
        }
    }
    else if (i == 3)
    {
        if (strcmp(DC, "A1") == 0)
        {
            strcpy(customer_4[num], "A1\tHAM AND EGG\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "A2") == 0)
        {
            strcpy(customer_4[num], "A2\tBACON AND CHEESE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "A3") == 0)
        {
            strcpy(customer_4[num], "A3\tTUNA SALAD\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "A4") == 0)
        {
            strcpy(customer_4[num], "A4\tBEEF SOUP\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "B1") == 0)
        {
            strcpy(customer_4[num], "B1\tSPICY BEEF BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "B2") == 0)
        {
            strcpy(customer_4[num], "B2\tPORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "B3") == 0)
        {
            strcpy(customer_4[num], "B3\tOVEN CHICKEN BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "B4") == 0)
        {
            strcpy(customer_4[num], "B4\tPULLED BEEF BARBECUE BURGUR\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "C1") == 0)
        {
            strcpy(customer_4[num], "C1\tSPICY PORK BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "C2") == 0)
        {
            strcpy(customer_4[num], "C2\tVEGETABLE PORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "C3") == 0)
        {
            strcpy(customer_4[num], "C3\tOVEN PORK BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "C4") == 0)
        {
            strcpy(customer_4[num], "C4\tPULLED PORK BARBECUE\t$ 25");
            price += 25;
        }
    }
    else if (i == 4)
    {
        if (strcmp(DC, "A1") == 0)
        {
            strcpy(customer_5[num], "A1\tHAM AND EGG\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "A2") == 0)
        {
            strcpy(customer_5[num], "A2\tBACON AND CHEESE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "A3") == 0)
        {
            strcpy(customer_5[num], "A3\tTUNA SALAD\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "A4") == 0)
        {
            strcpy(customer_5[num], "A4\tBEEF SOUP\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "B1") == 0)
        {
            strcpy(customer_5[num], "B1\tSPICY BEEF BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "B2") == 0)
        {
            strcpy(customer_5[num], "B2\tPORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "B3") == 0)
        {
            strcpy(customer_5[num], "B3\tOVEN CHICKEN BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "B4") == 0)
        {
            strcpy(customer_5[num], "B4\tPULLED BEEF BARBECUE BURGUR\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "C1") == 0)
        {
            strcpy(customer_5[num], "C1\tSPICY PORK BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "C2") == 0)
        {
            strcpy(customer_5[num], "C2\tVEGETABLE PORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "C3") == 0)
        {
            strcpy(customer_5[num], "C3\tOVEN PORK BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "C4") == 0)
        {
            strcpy(customer_5[num], "C4\tPULLED PORK BARBECUE\t$ 25");
            price += 25;
        }
    }
    else if (i == 5)
    {
        if (strcmp(DC, "A1") == 0)
        {
            strcpy(customer_6[num], "A1\tHAM AND EGG\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "A2") == 0)
        {
            strcpy(customer_6[num], "A2\tBACON AND CHEESE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "A3") == 0)
        {
            strcpy(customer_6[num], "A3\tTUNA SALAD\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "A4") == 0)
        {
            strcpy(customer_6[num], "A4\tBEEF SOUP\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "B1") == 0)
        {
            strcpy(customer_6[num], "B1\tSPICY BEEF BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "B2") == 0)
        {
            strcpy(customer_6[num], "B2\tPORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "B3") == 0)
        {
            strcpy(customer_6[num], "B3\tOVEN CHICKEN BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "B4") == 0)
        {
            strcpy(customer_6[num], "B4\tPULLED BEEF BARBECUE BURGUR\t$ 25");
            price += 25;
        }
        else if (strcmp(DC, "C1") == 0)
        {
            strcpy(customer_6[num], "C1\tSPICY PORK BARBECUE\t$ 20");
            price += 20;
        }
        else if (strcmp(DC, "C2") == 0)
        {
            strcpy(customer_6[num], "C2\tVEGETABLE PORK BARBECUE\t$ 10");
            price += 10;
        }
        else if (strcmp(DC, "C3") == 0)
        {
            strcpy(customer_6[num], "C3\tOVEN PORK BARBECUE\t$ 15");
            price += 15;
        }
        else if (strcmp(DC, "C4") == 0)
        {
            strcpy(customer_6[num], "C4\tPULLED PORK BARBECUE\t$ 25");
            price += 25;
        }
    }

    return 0;
}

int main()
{
    int number;        // number of customer
    char password[8];  // password
    char dish_code[2]; // string to hold dishcode

    do
    {
        printf("Enter password:\n");
        scanf("%s", password);
        if (strcmp(password, "20413059") == 0)
        {
            break;
        }
    } while (strcmp(password, "20413059") != 0);

    printf("User name: Yiyang Liu\n\n");
    printf("                               BREAKFAST     (Available: 8 am - 10 am)\n");
    printf("              A1   HAM AND EGG                  $20\n");
    printf("              A2   BACON AND CHEESE             $10\n");
    printf("              A3   TUNA SALAD                   $15\n");
    printf("              A4   BEEF SOUP                    $25\n");
    printf("                                 LUNCH       (Available: 11 am - 1 pm)\n");
    printf("             B1   SPICY BEEF BARBECUE          $20\n");
    printf("              B2   PORK BARBECUE                $10\n");
    printf("              B3   OVEN CHICKEN BARBECUE        $15\n");
    printf("              B4   PULLED BEEF BARBECUE BURGER  &25\n");
    printf("                                DINNER       (Available: 5 pm - 8 pm)\n");
    printf("              C1   SPICY PORK BARBECUE          $20\n");
    printf("              C2   VEGETABLE PORK BARBECUE      $10\n ");
    printf("             C3   OVEN PORK BARBECUE           $15\n");
    printf("              C4   PULLED PORK BARBECUE         $25\n");

    do
    {
        printf("Customer Number:\n");
        char c;
        while ((c = getchar()) != '\n');
        scanf("%d", &number);
        if (number >= 1 && number <= 6)
        {
            break;
        }
    } while (number < 1 || number > 6);

    int a = 0; // counter for dish code
    for (int i = 0; i < number; i++)
    {
        while (1)
        {
            // dish entry for specific customer
            printf("Dish entry for customer %d:\n", i + 1);
            printf("Dish Code:\n");
            scanf("%s", dish_code);

            if (strcmp(dish_code, "F") == 0)
            {
                break;
            }
            else if (strcmp(dish_code, "A1") != 0 && strcmp(dish_code, "A2") != 0 && strcmp(dish_code, "A3") != 0 && strcmp(dish_code, "A4") != 0 && strcmp(dish_code, "B1") != 0 && strcmp(dish_code, "B2") != 0 && strcmp(dish_code, "B3") != 0 && strcmp(dish_code, "B4") != 0 && strcmp(dish_code, "C1") != 0 && strcmp(dish_code, "C2") != 0 && strcmp(dish_code, "C3") != 0 && strcmp(dish_code, "C4") != 0)
            {
                printf("This dish code does not exist! Try again!\n");
                continue;
            }
            else
            {
                //printf("count dish:%d\n", a);
                //printf("count customer:%d\n", i);
                checkData(dish_code, a, i);
                a++;
            }
        }
        a = 0; // set back to 0, otherwise increment all the time.
    }

    printf("%s\n", customer_1[0]);
    // print receit
    printf(" ____________________________________________________\n");
    printf("\n");
    printf("\t\tTHANK YOU FOR DINNING HERE!\n");
    printf(" ____________________________________________________\n");
    printf("\t\tHere is your receit:\n");

    for (int j = 0; j < number; j++)
    {
        printf("Customer %d:\n", j + 1);
        printf("Code\tDish\t\tPrice\n");
        for (int i = 0; i < count[j]; i++)
        {
            if (j == 0)
            {
                printf("%.40s\n", customer_1[i]);
            }
            else if (j == 1)
            {
                printf("%.40s\n", customer_2[i]);
            }
            else if (j == 2)
            {
                printf("%.40s\n", customer_3[i]);
            }
            else if (j == 3)
            {
                printf("%.40s\n", customer_4[i]);
            }
            else if (j == 4)
            {
                printf("%.40s\n", customer_5[i]);
            }
            else if (j == 5)
            {
                printf("%.40s\n", customer_6[i]);
            }
        }
    }
    printf(" ____________________________________________________\n");
    printf("\t\t\tTOTAL COST: %.2f\n", (double)price);

    int cash = 0;
    int change = 0;

    do
    {
        printf("Cash Received:\n");
        scanf("%d", &cash);
        if (cash >= price)
            break;
    } while (cash < price);

    change = cash - price;
    printf("Change Given: %d\n", change);
    return 0;
}
