// including libraries
#include <stdio.h>
#include "reminder.h"

/**
 * @author Eliandro Pizzonia
 * 
 * The implementation file containing functions for inserting reminders into the calendar and displaying the calendar.
 */

void insert_to_calendar(int day, const char* value){
    
    // temp array to hold the reminder
    char temp_value[strlen(value)];

    // checking if reminder date is within the moth of November's range
    if (day > November.month_days || day < 1){
        printf("\nInvalid input!\n");
    }

    else{
        
        //copying the reminder to new arrays to remove the date and leading space before inserting to the struct
        for (int i = 0; i <= strlen(value); i++){
            temp_value[i] = value[i + 2];
        }

        if(temp_value[0] == ' '){
            for (int i = 0; i < strlen(temp_value); i++){
                temp_value[i] = temp_value[i+1];
            }
        }

        // copying reminder into the struct reminder array and setting true on that day (since there is now a reminder on that day) 
        strcpy(November.reminder_str[day], temp_value);

        November.reminders[day] = 1;
    }
}

int read_reminder(char *str, int n){

    // getting rid of the newline from fgets
    str[n - 1] = '\0';

    //getting the first three elements of the user input (which contain the date of the reminder)
    char date_str[3]; 

    for(int i = 0; i < 2; i++){
        date_str[i] = str[i];
    }

    // converting and returning the date from a string format to an int
    int date = atoi(date_str);

    return date;
}

void print_calendar() {

    
    char empty_char = ' ';

    // printing day of the week
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // representing the days of the previous month before the first day of November 
    for (int i = 1; i < November.start_day; i++) {
        printf("   %c ", empty_char);
    }

    // printing the days of the month 
    for(int i = 1; i <= November.month_days; i++){
        
        // days with reminders
        if(November.reminders[i] == 1){
            printf(" (%2d)", i);
        }

        // days without reminders
        else{
        printf("  %2d ", i);
        }

        // new line after every saturday
        if ((i + November.start_day - 1) % 7 == 0){
                printf("\n");
        }
    }

    // printing the list of reminders
    printf("\nReminders:\n");
    for (int i = 1; i <= November.month_days; i++){
        if(November.reminders[i] == 1){
            printf("Day %d: %s\n", i, November.reminder_str[i]);
        }
    }
    printf("____________________________");
}

