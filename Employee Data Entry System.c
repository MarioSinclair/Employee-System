/*
Name:Mario Sinclair
Date: November 7, 2021
Description: Computer Science SBA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{ //structure declaration
        int id;
        char fname[50];
        char lname[50];
        int dobd;
        int dobm;
        int doby;
        char phone[50];
        char email[50];
        char edlvl[50];
        char dept[50];
        char status[50];
        int salary;
};

struct verify{
    int id;
    char fname[50];
    char lname[50];
    int dobd;
    int dobm;
    int doby;
    char phone[50];
    char email[50];
    char edlvl[50];
    char dept[50];
    char status[50];
    int salary;
};

int data(struct employee *s)//data entry function
{
    struct verify info[100];
    char fn[10];
    char ln[50];
    char d[50];
    char ph[50];
    char em[50];
    int i;
    int ed;
    int dep;
    int st;
    int sa;
    int day;
    int mon;
    int year;
    int count = 0;
    int veri = 0;
    int c = 0, max;
    FILE *fptr = fopen("Records.txt", "r");
    while (veri != 1){//verification loop for the data entry
            printf ("Please enter the ID Number of the employee \n");
            scanf ("%d", &i);
            while (!feof(fptr)){
                fscanf(fptr,"\n%d %s %s %d %d %d %s %s %s %s %s %d", &info[c].id, info[c].fname, info[c].lname, &info[c].dobd, &info[c].dobm, &info[c].doby, info[c].phone, info[c].email, info[c].edlvl, info[c].dept, info[c].status, &info[c].salary);
                c++;
            }
            fclose(fptr);
            max = c;
            for (c = 0; c <= (max) ; c++){//for loop for ID number verification
                    if (info[c].id == i){
                    printf("The ID number is already in use\n");
                    printf("Press enter to restart and use a different ID number");
                    getch();
                    main();
                }
            }
            s->id = i;
            printf ("Please enter the first name of the employee \n");
            scanf ("%s", fn);
            strcpy (s->fname,fn);
            printf ("Please enter the last name of the employee \n");
            scanf ("%s", ln);
            strcpy (s->lname,ln);
                do{//Date of birth verification
                    count = 0;
                    printf("Please enter the date of birth\n");
                    printf("Day: ");
                    scanf("%d",&day);
                        if (day>31){
                            printf("Invalid Day\n");

                        }else{
                        count++;
                        s->dobd = day;
                        }
                    printf("Month: ");
                    scanf("%d",&mon);
                        if (mon>12){
                            printf("Invalid Month\n");
                        }else{
                        count++;
                        s->dobm = mon;
                        }
                    printf("Year: ");
                    scanf("%d",&year);
                    s->doby = year;
                    if(count!= 2){
                        printf("Please re-enter a VALID date of birth\n");
                        sleep(2);
                        system("cls");
                     }
                }while (count!= 2);
                printf("Date of Birth: %d/%d/%d\n",day,mon,year);
                printf ("Please enter the phone number of the employee (XXX-XXXX)\n");
                scanf ("%s", ph);
                strcpy (s->phone,ph);
                printf ("Please enter the email address of the employee \n");
                scanf ("%s", em);
                strcpy (s->email,em);
                printf ("Please enter the education level of the employee \n1.N/A\n2.High School\n3.Associates\n4.Bachelors\n5.Masters\n6.Doctorate\n");
                scanf ("%d", &ed);
                if (ed == 1){
                    strcpy(s->edlvl, "N/A");
                        }else if(ed == 2){
                            strcpy(s->edlvl, "HighSchool");
                                }else if(ed == 3){
                                    strcpy(s->edlvl, "Associates");
                                        }else if(ed == 4){
                                            strcpy(s->edlvl, "Bachelors");
                                                }else if(ed == 5){
                                                    strcpy(s->edlvl, "Masters");
                                                        }else if(ed == 6){
                                                            strcpy(s->edlvl, "Doctorate");
                                                        }else{
                                                            printf("Invalid Entry\n");
                                                            printf("Press enter to restart");
                                                            getch();
                                                            main();
                                                        }
                printf ("Please enter the department of the employee \n1.Sales\n2.Marketing\n3.Operations\n4.Finance\n5.Human Resource\n");
                scanf ("%d", &dep);
                if (dep == 1){
                    strcpy(s->dept, "Sales");
                        }else if(dep == 2){
                            strcpy(s->dept, "Marketing");
                                }else if(dep == 3){
                                    strcpy(s->dept, "Operations");
                                        }else if(dep == 4){
                                            strcpy(s->dept, "Finance");
                                                }else if(dep == 5){
                                                    strcpy(s->dept, "Human Resource");
                                                }else{
                                                    printf("Invalid Entry\n");
                                                    printf("Press enter to restart");
                                                    getch();
                                                    main();
                                                }
                printf ("Please enter the status of the employee\n1.Employed\n2.Unemployed\n");
                scanf ("%d", &st);
                    if (st == 1){
                        strcpy(s->status, "Employed");
                            }else if(st == 2){
                                strcpy(s->status, "Unemployed");
                                    }else{
                                        printf("Invalid Entry\n");
                                        printf("Press enter to restart");
                                        getch();
                                        main();
                                    }
                printf ("Please enter the salary of the employee \n");
                scanf ("%d", &sa);
                s->salary = sa;
                system("cls");
                    printf("Please verify the entered information.\n");//error verification
                    printf (" ------------------------------  \n");
                    printf("ID Number: %d\n",i);
                    printf("First Name: %s\n",fn);
                    printf("Last Name: %s\n",ln);
                    printf("Date of Birth: %d/%d/%d\n", day, mon, year);
                    printf("Phone Number: %s\n",ph);
                    printf("Email Address: %s\n",em);
                    printf("Education Level: %s\n",s->edlvl);
                    printf("Department: %s\n",s->dept);
                    printf("Employee Status: %s\n",s->status);
                    printf("Salary: $%d\n\n",sa);
                    printf("Please enter 1 if correct and 2 if incorrect\n");
                    scanf("%d", &veri);
    }
}

int search()
{
    int id;
    char fname[50];
    char lname[50];
    int dobd;
    int dobm;
    int doby;
    char phone[50];
    char email[50];
    char edlvl[50];
    char dept[50];
    char status[50];
    int salary;
        int choice;
        int num;
        int opt1;
        int i = 1;
        opt1 = 1;
        FILE *fptr = fopen("Records.txt","r");
        printf("Please enter the ID number you are looking for #");
        scanf("%d", &num);
            while (!feof(fptr)){//scanning the file for records
                fscanf(fptr,"\n%d %s %s %d %d %d %s %s %s %s %s %d", &id, fname, lname, &dobd, &dobm, &doby, phone, email, edlvl, dept, status, &salary);
                if (id == num){//if id is found it is displayed
                    printf("ID Number: %d\n",id);
                    printf("First Name: %s\n",fname);
                    printf("Last Name: %s\n",lname);
                    printf("Date of Birth (dd/mm/yyyy): %d/%d/%d\n", dobd, dobm, doby);
                    printf("Phone Number: %s\n",phone);
                    printf("Email Address: %s\n",email);
                    printf("Education Level: %s\n",edlvl);
                    printf("Department: %s\n",dept);
                    printf("Employee Status: %s\n",status);
                    printf("Salary: $%d\n",salary);
                }else{
                    printf("ID not found");
                }
            }
            printf("Would you like to enter another ID number 1 for Yes 2 for No\n");
            scanf("%d", &opt1);
            fclose (fptr);
            system("cls");
                if (opt1 == 1)
                    search();
        printf("Press a key to return to the menu");
        getch();
        system("cls");
        main();
}

int update()
{
    int id;
    char fname[50];
    char lname[50];
    int dobd;
    int dobm;
    int doby;
    char phone[50];
    char email[50];
    int ed;
    char edlvl[50];
    int dep;
    char dept[50];
    int st;
    char status[50];
    int salary;
    int num;
    int count;
    int day;
    int mon;
    int year;
    FILE *fptr = fopen("Records.txt","r");
    FILE *fptr2 = fopen("temp.txt","w");
        printf("Please enter the ID # of the employee you would like to update \n");
        scanf("%d", &num);
        while (!feof(fptr)){//scanning the file for records
            fscanf(fptr,"\n%d %s %s %d %d %d %s %s %s %s %s %d", &id, fname, lname, &dobd, &dobm, &doby, phone, email, edlvl, dept, status, &salary);
            if (id != num){//copying files to the new file
                 fprintf(fptr2,"\n%d %s %s %d %d %d %s %s %s %s %s %d", id, fname, lname, dobd, dobm, doby, phone, email, edlvl, dept, status, salary);
            }else{
            printf ("\nPlease enter the first name of the employee \n");
            scanf ("%s", &fname);
            printf ("Please enter the last name of the employee \n");
            scanf ("%s", &lname);
            printf ("Please enter the ID number of the employee \n#");
            scanf ("%d", &id);
                do{//Date of Birth verification
                    count = 0;
                    printf("Please enter the date of birth (DD/MM/YYYY)\n");
                    printf("Day: ");
                    scanf("%d",&day);
                        if (day>31){
                            printf("Invalid Day\n");
                        }else{
                        count++;
                        }
                    printf("Month: ");
                    scanf("%d",&mon);
                        if (mon>12){
                            printf("Invalid Month\n");
                        }else{
                        count++;
                        }
                    printf("Year: ");
                    scanf("%d",&year);
                    if(count!= 2){
                        printf("Please re-enter a VALID date of birth\n");
                        sleep(2);
                        system("cls");
                     }
                }while (count!= 2);
                    printf("Date of Birth: %d/%d/%d\n",day,mon,year);
                    printf ("Please enter the phone number of the employee (XXX-XXXX)\n");
                    scanf ("%s", &phone);
                    printf ("Please enter the email address of the employee \n");
                    scanf ("%s", &email);
                printf ("Please enter the education level of the employee \n1.N/A\n2.High School\n3.Associates\n4.Bachelors\n5.Masters\n6.Doctorate\n");
                scanf ("%d", &ed);
                if (ed== 1){//selection for education level
                    strcpy(edlvl, "N/A");
                        }else if(ed == 2){
                            strcpy(edlvl, "HighSchool");
                                }else if(ed == 3){
                                    strcpy(edlvl, "Associates");
                                        }else if(ed == 4){
                                            strcpy(edlvl, "Bachelors");
                                                }else if(ed == 5){
                                                    strcpy(edlvl, "Masters");
                                                        }else if(ed == 6){
                                                            strcpy(edlvl, "Doctorate");
                                                        }else{
                                                            printf("Invalid Entry\n");
                                                            printf("Press enter to restart");
                                                            getch();
                                                            main();
                                                        }
                printf ("Please enter the department of the employee \n1.Sales\n2.Marketing\n3.Operations\n4.Finance\n5.Human Resource\n");
                scanf ("%d", &dep);
                if (dep == 1){//selection for department
                    strcpy(dept, "Sales");
                        }else if(dep == 2){
                            strcpy(dept, "Marketing");
                                }else if(dep == 3){
                                    strcpy(dept, "Operations");
                                        }else if(dep == 4){
                                            strcpy(dept, "Finance");
                                                }else if(dep == 5){
                                                    strcpy(dept, "Human Resource");
                                                }else{
                                                    printf("Invalid Entry\n");
                                                    printf("Press enter to restart");
                                                    getch();
                                                    main();
                                                }
                printf ("Please enter the status of the employee\n1.Employed\n2.Unemployed\n");
                scanf ("%d", &st);
                    if (st == 1){//selection for the status of the employee
                        strcpy(status, "Employed");
                            }else if(st == 2){
                                strcpy(status, "Unemployed");
                                    }else{
                                        printf("Invalid Entry\n");
                                        printf("Press enter to restart");
                                        getch();
                                        main();
                                    }
                fprintf(fptr2,"\n%d %s %s %d %d %d %s %s %s %s %s %d", id, fname, lname, day, mon, year, phone, email, edlvl, dept, status, salary);//printing to the file
            }
        }
        fclose(fptr);
        fclose(fptr2);
            remove("Records.txt");
            rename("temp.txt", "Records.txt");
    system("cls");
    printf("Updated :)");
    getch();
    main();
}

int report()
{
    int id;
    char fname[50];
    char lname[50];
    int dobd;
    int dobm;
    int doby;
    char phone[50];
    char email[50];
    char edlvl[50];
    char dept[50];
    char status[50];
    int salary;
    int choice;
        do{//entry verification
            system ("cls");
            printf(" Please enter the corresponding number:\n");
            printf(" ------------------------------------ \n");
            printf (" ------ Print all employees -------- 1\n");
            printf(" ------------------------------------ \n");
            printf (" ---Employees based on Department -- 2\n");
            printf(" ------------------------------------ \n");
            printf (" ---- Employees based on status ---- 3\n");
            printf(" ------------------------------------ \n");
            printf (" -------------- Exit --------------- 0\n");
            printf(" ------------------------------------ \n");
            scanf ("%d", &choice);
            system ("cls");
        switch (choice)
        {
            case 1:
                all();
                break;
            case 2:
                department();
                break;
            case 3:
                stat();
                break;
            case 0:
                main();
            default:
                printf ("An incorrect choice has been entered.\n");
                printf ("Please enter a valid option.\n");
                printf ("Press any key to continue.\n");
                getch();
                system ("cls");
        }
    }while (choice != 0);
}

int all(){
    int id;
    char fname[50];
    char lname[50];
    int dobd;
    int dobm;
    int doby;
    char phone[50];
    char email[50];
    char edlvl[50];
    char dept[50];
    char status[50];
    int salary;
    FILE *fptr = fopen("Records.txt","r");
        while (!feof(fptr)){//loop for scanning the file
                fscanf(fptr,"%d %s %s %d %d %d %s %s %s %s %s %d", &id, fname, lname, &dobd, &dobm, &doby, phone, email, edlvl, dept, status, &salary);
                    printf("-----------------------------------------\n");//printing records
                    printf("|  ID Number: %d                        \n",id);
                    printf("|  First Name: %s                       \n",fname);
                    printf("|  Last Name: %s                        \n",lname);
                    printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd, dobm, doby);
                    printf("|  Phone Number: %s                     \n",phone);
                    printf("|  Email Address: %s                    \n",email);
                    printf("|  Education Level: %s                  \n",edlvl);
                    printf("|  Department: %s                       \n",dept);
                    printf("|  Employee Status: %s                  \n",status);
                    printf("|  Salary: $%d                          \n",salary);
                    printf("-----------------------------------------\n");
        }
            printf ("Press any key to return to the menu.\n");
            getch();
    fclose (fptr);
            system("cls");
}

int department(){
    int scount = 0;
    int mcount = 0;
    int ocount = 0;
    int fcount = 0;
    int hcount = 0;
    int c = 0;
    int max;
    int choice;
        int id[50];
        char fname[50][50];
        char lname[50][50];
        int dobd[50];
        int dobm[50];
        int doby[50];
        char phone[50][50];
        char email[50][50];
        char edlvl[50][50];
        char dept[50][50];
        char status[50][50];
        int salary[50];
    FILE * fptr2 = fopen("Records.txt","r");
        while (!feof(fptr2)){//loop to scan records
           fscanf(fptr2,"%d %s %s %d %d %d %s %s %s %s %s %d", &id[c], fname[c], lname[c], &dobd[c], &dobm[c], &doby[c], phone[c], email[c], edlvl[c], dept[c], status[c], &salary[c]);
           c++;
        }
    fclose(fptr2);
        max = c;
        for (c = 0; c <= max ; c++){//count for the records in each department
            if (strcmp(dept[c], "Sales") == 0 && strcmp(status[c], "Employed") == 0){
                scount++;
                }else if (strcmp(dept[c], "Marketing") == 0 && strcmp(status[c], "Employed") == 0){
                    mcount++;
                    }else if (strcmp(dept[c], "Operations") == 0 && strcmp(status[c], "Employed") == 0){
                        ocount++;
                        }else if (strcmp(dept[c], "Finance") == 0 && strcmp(status[c], "Employed") == 0){
                            fcount++;
                                }else if (strcmp(dept[c], "Human Resource") == 0 && strcmp(status[c], "Employed") == 0){
                                    hcount++;
                                }
        }
            printf("Enter 1 for Sales 2 for Marketing 3 for Operations 4 for Finance 5 for Human Resource\n");
            scanf("%d", &choice);
            if(choice == 1){
                for (c = 0; c <= max ; c++){// for loop to search each record based on department
                    if (strcmp(dept[c], "Sales") == 0){
                        printf("-------------- Sales --------------\n");
                        printf("|  ID Number: %d                        \n",id[c]);
                        printf("|  First Name: %s                       \n",fname[c]);
                        printf("|  Last Name: %s                        \n",lname[c]);
                        printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                        printf("|  Phone Number: %s                     \n",phone[c]);
                        printf("|  Email Address: %s                    \n",email[c]);
                        printf("|  Education Level: %s                  \n",edlvl[c]);
                        printf("|  Department: %s                       \n",dept[c]);
                        printf("|  Employee Status: %s                  \n",status[c]);
                        printf("|  Salary: $%d                          \n",salary[c]);
                        printf("-----------------------------------------\n");
                            }
                }
            }else if(choice == 2){
                for (c = 0; c <= max ; c++){
                    if (strcmp(dept[c], "Marketing") == 0){
                            printf("---------------- Employed --------------\n");
                            printf("|  ID Number: %d                        \n",id[c]);
                            printf("|  First Name: %s                       \n",fname[c]);
                            printf("|  Last Name: %s                        \n",lname[c]);
                            printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                            printf("|  Phone Number: %s                     \n",phone[c]);
                            printf("|  Email Address: %s                    \n",email[c]);
                            printf("|  Education Level: %s                  \n",edlvl[c]);
                            printf("|  Department: %s                       \n",dept[c]);
                            printf("|  Employee Status: %s                  \n",status[c]);
                            printf("|  Salary: $%d                          \n",salary[c]);
                            printf("-----------------------------------------\n");
                    }
                }
            }else if(choice == 3){
                for (c = 0; c <= max ; c++){
                    if (strcmp(dept[c], "Operations") == 0){
                            printf("---------------- Employed --------------\n");
                            printf("|  ID Number: %d                        \n",id[c]);
                            printf("|  First Name: %s                       \n",fname[c]);
                            printf("|  Last Name: %s                        \n",lname[c]);
                            printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                            printf("|  Phone Number: %s                     \n",phone[c]);
                            printf("|  Email Address: %s                    \n",email[c]);
                            printf("|  Education Level: %s                  \n",edlvl[c]);
                            printf("|  Department: %s                       \n",dept[c]);
                            printf("|  Employee Status: %s                  \n",status[c]);
                            printf("|  Salary: $%d                          \n",salary[c]);
                            printf("-----------------------------------------\n");
                            }
                }
            }else if(choice == 4){
                for (c = 0; c <= max ; c++){
                    if (strcmp(dept[c], "Finance") == 0){
                            printf("---------------- Employed --------------\n");
                            printf("|  ID Number: %d                        \n",id[c]);
                            printf("|  First Name: %s                       \n",fname[c]);
                            printf("|  Last Name: %s                        \n",lname[c]);
                            printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                            printf("|  Phone Number: %s                     \n",phone[c]);
                            printf("|  Email Address: %s                    \n",email[c]);
                            printf("|  Education Level: %s                  \n",edlvl[c]);
                            printf("|  Department: %s                       \n",dept[c]);
                            printf("|  Employee Status: %s                  \n",status[c]);
                            printf("|  Salary: $%d                          \n",salary[c]);
                            printf("-----------------------------------------\n");
                    }
                }
            }else if(choice == 5){
                for (c = 0; c <= max ; c++){
                    if (strcmp(dept[c], "Human Resource") == 0){
                            printf("---------------- Employed --------------\n");
                            printf("|  ID Number: %d                        \n",id[c]);
                            printf("|  First Name: %s                       \n",fname[c]);
                            printf("|  Last Name: %s                        \n",lname[c]);
                            printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                            printf("|  Phone Number: %s                     \n",phone[c]);
                            printf("|  Email Address: %s                    \n",email[c]);
                            printf("|  Education Level: %s                  \n",edlvl[c]);
                            printf("|  Department: %s                       \n",dept[c]);
                            printf("|  Employee Status: %s                  \n",status[c]);
                            printf("|  Salary: $%d                          \n",salary[c]);
                            printf("-----------------------------------------\n");
                    }
                }
            }else{
                printf("Invalid entry\n");
                printf("Press enter to retry\n");
                getch();
                department();
            }
        printf("Employees in the Sales Department: %d \n\nEmployees in the Marketing Department: %d \n\nEmployees in the Operations Department: %d \n\nEmployees in the Finance Department: %d \n\nEmployees in the Human Resource Department: %d", scount, mcount, ocount, fcount , hcount);
        getch();
}

int stat(){
    int id[50];
    char fname[50][50];
    char lname[50][50];
    int dobd[50];
    int dobm[50];
    int doby[50];
    char phone[50][50];
    char email[50][50];
    char edlvl[50][50];
    char dept[50][50];
    char status[50][50];
    int salary[50];
        int c = 0;
        int max;
        int choice;
        int ucount = 0;
        int ecount = 0;
        FILE * fptr2 = fopen("Records.txt","r");
        while (!feof(fptr2)){
           fscanf(fptr2,"%d %s %s %d %d %d %s %s %s %s %s %d", &id[c], fname[c], lname[c], &dobd[c], &dobm[c], &doby[c], phone[c], email[c], edlvl[c], dept[c], status[c], &salary[c]);
           c++;
        }
        max = c;
        for (c = 0; c <= max ; c++){
            if (strcmp(status[c], "Unemployed") == 0){
                ucount++;
            }else if (strcmp(status[c], "Employed") == 0){
                ecount++;
                }
        }
            printf("Enter 1 for Employed and 2 for Unemployed Employees\n");
            scanf("%d", &choice);
            if(choice == 2){
                for (c = 0; c <= max ; c++){//for loop to search each record based on status
                        if (strcmp(status[c], "Unemployed") == 0){
                        printf("-------------- Unemployed --------------\n");
                        printf("|  ID Number: %d                        \n",id[c]);
                        printf("|  First Name: %s                       \n",fname[c]);
                        printf("|  Last Name: %s                        \n",lname[c]);
                        printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                        printf("|  Phone Number: %s                     \n",phone[c]);
                        printf("|  Email Address: %s                    \n",email[c]);
                        printf("|  Education Level: %s                  \n",edlvl[c]);
                        printf("|  Department: %s                       \n",dept[c]);
                        printf("|  Employee Status: %s                  \n",status[c]);
                        printf("|  Salary: $%d                          \n",salary[c]);
                        printf("-----------------------------------------\n");
                            }
                }
            }else if(choice == 1){
                for (c = 0; c <= max ; c++){
                    if (strcmp(status[c], "Employed") == 0){
                            printf("---------------- Employed --------------\n");
                            printf("|  ID Number: %d                        \n",id[c]);
                            printf("|  First Name: %s                       \n",fname[c]);
                            printf("|  Last Name: %s                        \n",lname[c]);
                            printf("|  Date of Birth (dd/mm/yyyy): %d/%d/%d \n", dobd[c], dobm[c], doby[c]);
                            printf("|  Phone Number: %s                     \n",phone[c]);
                            printf("|  Email Address: %s                    \n",email[c]);
                            printf("|  Education Level: %s                  \n",edlvl[c]);
                            printf("|  Department: %s                       \n",dept[c]);
                            printf("|  Employee Status: %s                  \n",status[c]);
                            printf("|  Salary: $%d                          \n",salary[c]);
                            printf("-----------------------------------------\n");
                            }
                }
            }else{
                printf("Invalid entry\n");
                printf("Press enter to retry\n");
                getch();
                stat();
                            }
        printf("Previous employees: %d\nCurrent Employees: %d ", ucount, ecount);
        getch();
        fclose(fptr2);
}


int sort(){
    int id[50];
    char fname[50][50];
    char lname[50][50];
    int dobd[50];
    int dobm[50];
    int doby[50];
    char phone[50][50];
    char email[50][50];
    char edlvl[50][50];
    char dept[50][50];
    char status[50][50];
    int salary[50];
    int index[50];
    int c = 0;
    int temp = 0;
    int i, j, max, x = 0;
    FILE *fptr = fopen("Records.txt","r");
    FILE *fptr2 = fopen("Sort.txt", "w");
            do{
                fscanf(fptr,"\n%d %s %s %d %d %d %s %s %s %s %s %d", &id[c], fname[c], lname[c], &dobd[c], &dobm[c], &doby[c], phone[c], email[c], edlvl[c], dept[c], status[c], &salary[c]);
                c++;
                x++;
            }while (!feof(fptr));
            max = x;
            for (c = 0; c <= max ; c++){//bubble sort for the index of each record
                index[c] = c;
            }
                    for (i = 0; i < (max - 1); i++){
                        for (j = 0 ; j < (max - 1); j++){
                            if (id[index[j]] > id[index[j+1]]){
                                temp = index[j];
                                index[j] = index[j+1];
                                index[j+1] = temp;
                            }
                        }
                    }
        for (int c = 0 ; c <= (max - 1) ; c++){//for loop for printing to the file
            fprintf(fptr2,"\n%d %s %s %d %d %d %s %s %s %s %s %d", id[index[c]], fname[index[c]], lname[index[c]], dobd[index[c]], dobm[index[c]], doby[index[c]], phone[index[c]], email[index[c]], edlvl[index[c]], dept[index[c]], status[index[c]], salary[index[c]]);
        }
        fclose(fptr);
        fclose(fptr2);
        remove("Records.txt");
        rename("Sort.txt", "Records.txt");
        printf("Sorted :)");
        getch();
        main();
}

int main()
{
    int choice;
    int data();
    struct employee s;
    FILE *fptr2 = fopen("Records.txt","a");
    fclose(fptr2);
    do{
        system("cls");
        printf ("     Welcome to the program    \n");//menu for the functions
        printf (" Please select a function to run \n");
        printf (" ------------------------------  \n");
        printf (" ------ Data collection ------- 1\n");
        printf (" ------------------------------  \n");
        printf (" ----- Search for a record ---- 2\n");
        printf (" ------------------------------  \n");
        printf (" ----------- Update ----------- 3\n");
        printf (" ------------------------------  \n");
        printf (" ----------- Reports ---------- 4\n");
        printf (" ------------------------------ \n");
        printf (" --------- Sort Records ------- 5\n");
        printf (" ------------------------------ \n");
        printf (" ------------ Exit ------------ 0\n");
        printf (" ------------------------------ \n");
        scanf ("%d", &choice);
        system ("cls");
        switch (choice)
        {
            case 1:
                data(&s);
                FILE *fptr = fopen("Records.txt","a");
                    if ((fptr = fopen("Records.txt","a")) == NULL){
                            printf("The file could not be opened");
                        }else{
                            fprintf(fptr,"%d %s %s %d %d %d %s %s %s %s %s %d\n", s.id, s.fname, s.lname, s.dobd, s.dobm, s.doby, s.phone, s.email, s.edlvl, s.dept, s.status, s.salary);//printing records to the file
                        }
                fclose(fptr);
                sort();
                break;
            case 2:
                search(&s);
                break;
            case 3:
                update();
            case 4:
                report();
            case 5:
                sort();
        }
    }while (choice != 0);
}
