#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date_of_birth
        {
            int day;
            int month;
            int year;
        };


struct passport
        {
            int serial;
            int id;
            char date[20];
        };


struct rab
    {
        char first_name[50];
        char last_name[50];
        char otchestvo[50];
        struct date_of_birth db;
        struct passport psprt;
        enum gender {male, female, other} gndr;
    };




int main(){

    struct rab rabotnik;
    strcpy(rabotnik.first_name, "Eugene");
    strcpy(rabotnik.last_name, "Kurenov");
    strcpy(rabotnik.otchestvo, "Igorevich");
    rabotnik.psprt.serial = 3180;
    rabotnik.psprt.id = 989123;
    strcpy(rabotnik.psprt.date, "16.04.2018");
    rabotnik.db.day = 29;
    rabotnik.db.month = 1;
    rabotnik.db.year = 2004;
    rabotnik.gndr = male;

    struct rab rabotnik1;
    strcpy(rabotnik1.first_name, "Vladislave");
    strcpy(rabotnik1.last_name, "Keshishev");
    strcpy(rabotnik1.otchestvo, "Abobusovich");
    rabotnik1.psprt.serial = 3220;
    rabotnik1.psprt.id = 933123;
    strcpy(rabotnik1.psprt.date, "16.04.2018");
    rabotnik1.db.day = 6;
    rabotnik1.db.month = 2;
    rabotnik1.db.year = 2004;
    rabotnik1.gndr = male;

    struct rab rabotnik2;
    strcpy(rabotnik2.first_name, "Abobus");
    strcpy(rabotnik2.last_name, "Abobusov");
    strcpy(rabotnik2.otchestvo, "Abobusovich");
    rabotnik2.psprt.serial = 1488;
    rabotnik2.psprt.id = 133712;
    strcpy(rabotnik2.psprt.date, "26.05.2023");
    rabotnik2.db.day = 6;
    rabotnik2.db.month = 9;
    rabotnik2.db.year = 2023;
    rabotnik2.gndr = other;

    struct rab rabs[3];
    rabs[0] = rabotnik;
    rabs[1] = rabotnik1;
    rabs[2] = rabotnik2;
    // printf("First name: %s \nLast name: %s \nDate of birth: %d.%d.%d\n", rabotnik.first_name, rabotnik.last_name, rabotnik.db.day, rabotnik.db.month, rabotnik.db.year);
    // printf("%d", rabotnik.gndr);
    for(int i=0;i<3;i++)
    {
        int j = i + 1;
        printf("Работник %d: %s\n", i, rabs[i].last_name);
        
    }
    printf("Find by date of birth:");
    int year;
    int count = 0;
    scanf("%d",&year);
    for (int i = 0; i < 3; i++)
    {
        if (rabs[i].db.year == year)
        {   
            if (count == 0){
                printf("Работники с годом рождения %d: %s\n", year, rabs[i].last_name);
            }
            else {
                printf("%s\n",rabs[i].last_name );
            }
            count = count + 1;
        }
        else
        {
            if (count == 0)
            {
                printf("Ни одного работника, рожденного в этот год");
                count = count + 1;
            }
            
        }
    }


    return 0;
}


 