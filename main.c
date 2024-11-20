// including libraries
#include <stdio.h>
#include "reminder.h"

/**
 * @author Eliandro Pizzonia
 * 
 * The main file where the main function exists, and user interaction occurs.
*/

// Creating a struct for the month of November and setting the 1st day of the month on the 6th day of the week (Friday) to resenble November 2024
struct Month November = {30, 6};

int main(){
    
    // variables to hold the date and reminder
    int date;
    char temp_reminder[MAX_STR_LEN];
    
    do{
    
    // getting the user reminder
    printf("\nEnter day and reminder (0 to quit): ");
    fgets(temp_reminder, MAX_STR_LEN, stdin);

    // checking if user wants to quit program
    if(temp_reminder[0] == '0'){
        break;
    }

    // getting the date of the user reminder
    date = read_reminder(temp_reminder, strlen(temp_reminder));

    // inserting the reminder into the calendar and printing it
    insert_to_calendar(date, temp_reminder);
    print_calendar();
    
    // keeps prompting the user to enter a reminder until the user quits the program 
    }while(temp_reminder[0] != '0');
    
    return 0;
}







