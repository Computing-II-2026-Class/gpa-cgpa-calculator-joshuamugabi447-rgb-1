/*
Name: MUGABI JOSHUA
Registration Number: 25/U/BIE/01394/PE
*/

#include <stdio.h>

int main(void) {

    /* DECLARE VARIABLES HERE */

    int score[16];
    int gp[16];
    char grade[16];

    char *course[16] = {
        "1.TEMB1101","2.TEMB1102","3.TEMB1103","4.TEMB1104",
        "5.TEMB1105","6.TEMB1106","7.TEMB1107","8.TEMB1108",
        "9.TEMB1201","10.TEMB1202","11.TEMB1203","12.TEMB1204",
        "13.TEMB1205","14.TEMB1206","15.TEMB1207","16.TEMB1208"
    };

    int cu[16] = {4,3,3,3,3,3,2,3, 4,3,3,3,3,3,3,3};

    float sem1total = 0, sem2total = 0;
    float sem1gpa, sem2gpa, overal_cgpa;
    char *classification;

    /* READ 16 SCORES */

    printf("ENTER RESULTS FOR SEMESTER 1\n");

    for(int i = 0; i < 8; i++) {
        printf("%s: ", course[i]);
        scanf("%d", &score[i]);

        /* VALIDATE IMMEDIATELY */
        if(score[i] < 0 || score[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    printf("\nENTER RESULTS FOR SEMESTER 2\n");

    for(int i = 8; i < 16; i++) {
        printf("%s: ", course[i]);
        scanf("%d", &score[i]);

        /* VALIDATE IMMEDIATELY */
        if(score[i] < 0 || score[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    /* DETERMINE GRADES AND GRADE POINTS */

    for(int i = 0; i < 16; i++) {

        if(score[i] >= 80)
            gp[i] = 5;
        else if(score[i] >= 70)
            gp[i] = 4;
        else if(score[i] >= 60)
            gp[i] = 3;
        else if(score[i] >= 50)
            gp[i] = 2;
        else
            gp[i] = 0;

        switch(gp[i]) {
            case 5: grade[i] = 'A'; break;
            case 4: grade[i] = 'B'; break;
            case 3: grade[i] = 'C'; break;
            case 2: grade[i] = 'D'; break;
            default: grade[i] = 'F';
        }
    }

    /* COMPUTE SEMESTER I GPA */

    for(int i = 0; i < 8; i++) {
        sem1total += gp[i] * cu[i];
    }

    sem1gpa = sem1total / 24.0;

    /* COMPUTE SEMESTER II GPA */

    for(int i = 8; i < 16; i++) {
        sem2total += gp[i] * cu[i];
    }

    sem2gpa = sem2total / 25.0;

    /* COMPUTE CGPA */

    overal_cgpa = (sem1total + sem2total) / 49.0;

    /* DETERMINE CLASSIFICATION */

    if(overal_cgpa >= 4.40)
        classification = "First Class";
    else if(overal_cgpa >= 3.60)
        classification = "Second Class Upper";
    else if(overal_cgpa >= 2.80)
        classification = "Second Class Lower";
    else if(overal_cgpa >= 2.00)
        classification = "Pass";
    else
        classification = "Fail";

    /* DISPLAY FULL ACADEMIC REPORT */

    printf("\n\t\tSTUDENT'S ACADEMIC REPORT FOR YEAR ONE\n");

    printf("\n\tSEMESTER I RESULTS\n");

    for(int i = 0; i < 8; i++) {
        printf("\n%s\n", course[i]);
        printf("Score: %d\n", score[i]);
        printf("Grade: %c\n", grade[i]);
        printf("Grade Point: %d\n", gp[i]);
        printf("Credit Unit: %d\n", cu[i]);
        printf("Weighted Contribution: %d\n", gp[i] * cu[i]);
    }

    printf("\nSemester I GPA: %.2f\n", sem1gpa);

    printf("\n\tSEMESTER II RESULTS\n");

    for(int i = 8; i < 16; i++) {
        printf("\n%s\n", course[i]);
        printf("Score: %d\n", score[i]);
        printf("Grade: %c\n", grade[i]);
        printf("Grade Point: %d\n", gp[i]);
        printf("Credit Unit: %d\n", cu[i]);
        printf("Weighted Contribution: %d\n", gp[i] * cu[i]);
    }

    printf("\nSemester II GPA: %.2f\n", sem2gpa);


     printf("\nSemester I GPA: %.2f\n", sem1gpa);
    printf("Semester II GPA: %.2f\n", sem2gpa);
    printf("CGPA: %.2f\n", overal_cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}
