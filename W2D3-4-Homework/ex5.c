#include <stdio.h>
#include <stdint.h>

typedef struct MyTime{
    uint8_t month;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint16_t year;
    uint16_t day;
} MyTime;

int isLeapYear(MyTime t){
    if(t.year % 4 == 0){
        if(t.year % 100 == 0){
            if(t.year % 400 == 0){
                return 1;
            } else return 0;
        }
        return 1;
    } else return 0;
}

int totalDaysInYear(MyTime t){
    if(isLeapYear(t)){
        return 366;
    } else return 365;
}

void printMonth(MyTime t){
    const char* months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    printf("Month is %s\n", months[t.month - 1]);

}

int secondsPassed(MyTime t){
    MyTime test = {1, 0, 0, 0, 1970, 1};
    return t.second - test.second + (t.minute - test.minute) * 60 + (t.hour - test.hour) * 3600 + (t.day - test.day) * 86400 + (t.month - test.month) * 2629746 + (t.year - test.year) * 31557600;
}

int main(void){

    MyTime time = {8, 15, 30, 45, 2023, 5};


    printf("Size of MyTime struct: %ld\n", sizeof(MyTime));

    if (isLeapYear(time)) {
        printf("It's a leap year.\n");
    } else {
        printf("It's not a leap year.\n");
    }

    printf("Total days in the year: %d\n", totalDaysInYear(time));

    printMonth(time);

    printf("Seconds passed since 1.1.1970 time: %d\n", secondsPassed(time));

    return 0;
}