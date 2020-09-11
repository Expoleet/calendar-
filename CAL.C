#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int six(int, int, int);
void print(int,int);
void current(void);
void end(int,int);
 int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void main() {
 char days[7][10]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};

    int leap = 0;
    int date;
    int  month, year;
    int dateno, option,flag=0;
    do{
restart:
clrscr();
       current();
    printf("PRESS 1 FOR DAY FINDING  \nPRESS 2 FOR MONTH PRINTING \n");
    printf("PRESS 3 FOR WEEKEND FINDING \n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &option);
    switch (option) {
	case 1:
	    printf("Enter Date : ");
	    scanf("%d", &date);
	    printf("Enter Month : ");
	    scanf("%d", &month);
	    printf("Enter Year : ");
	    scanf("%d", &year);
	    if (!(year >= 1900 && year < 3000)) {
		printf("\n ENTER CORRECT DATE \n");
		sleep(3);
		goto restart;
	    } else if ((year % 100) % 4 == 0) {
		leap = 1;
		if (month == 2) {
		    mon[1] = 29;
		}
	    }
	    if (!(month >= 1 && month < 13)) {
		printf("\n ENTER CORRECT DATE \n");
	       sleep(3);
	       //	getch();
	       //	clrscr();
		goto restart;
	    } else if (!(date >= 1 && date <= mon[month - 1])) {
		printf("\n ENTER CORRECT DATE \n ");
		sleep(3);
		goto restart;
	    }
	    dateno = six(date, month, year);
	  /*  if (leap == 1 && (month == 1 || month == 2)) {
	    if(dateno==0){
		     dateno=6;
	    }  else{
		dateno = dateno - 1;
		}
	    }*/
	    printf("%s ",days[dateno]);
	    printf("\nPress 1 for continue");
	    scanf("%d",&flag);
	    break;
	case 2:
	    printf("Enter Date : ");
	    scanf("%d", &date);
	    printf("Enter Month : ");
	    scanf("%d", &month);
	    printf("Enter Year : ");
	    scanf("%d", &year);
	    if (!(year >= 1900 && year < 3000)) {
		printf("\n ENTER CORRECT DATE \n");
		sleep(3);
		goto restart;
	    } else if ((year % 100) % 4 == 0) {
		leap = 1;
		if (month == 2) {
		    mon[1] = 29;
		}
	    }
	    if (!(month >= 1 && month < 13)) {
		printf("\n ENTER CORRECT DATE \n");
		sleep(3);
		goto restart;
	    } else if (!(date >= 1 && date <= mon[month - 1])) {
		printf("\n ENTER CORRECT DATE \n ");
		sleep(3);
		goto restart;
	    }
	    dateno = six(1, month, year);



	    print(dateno,mon[month-1]);
	    printf("\nPress 1 for continue");
	    scanf("%d",&flag);
	break;

	case 3:
	if (!(year >= 1900 && year < 3000)) {
		printf("\n ENTER CORRECT DATE \n");
		sleep(3);
		goto restart;
	    } else if ((year % 100) % 4 == 0) {
		leap = 1;
		if (month == 2) {
		    mon[1] = 29;
		}
	    }
	   if (!(date >= 1 && date <= mon[month - 1])) {
		printf("\n ENTER CORRECT DATE \n ");
		sleep(3);
		goto restart;
	    }
	 printf("Enter Month : ");
	    scanf("%d", &month);
	    printf("Enter Year : ");
	    scanf("%d", &year);
	    end(month,year);
	    break;

    }
    }while(flag==1);
   // getch();
}

void print(int space, int lastdate) {
    int i = 1, dateno = 1;
    printf("Su\tM\tT\tW\tT\tF\tSa\n");
    if (space == 1) {
	printf("\t");
    } else if (space == 2) {
	printf("\t\t");
    } else if (space == 3) {
	printf("\t\t\t");
    } else if (space == 4) {
	printf("\t\t\t\t");
    } else if (space == 5) {
	printf("\t\t\t\t\t");
    } else if (space == 6) {
	printf("\t\t\t\t\t\t");
    }
    for (i = 1; dateno <= lastdate; i++) {
	while (space <= 6 && dateno <= lastdate) {
	    printf("%2d\t", dateno);
	    dateno++;
	    space++;
	}
	space = 0;
	printf("\n");
    }

}

int six(int day, int mon, int year) {
    int cen_offcet;
    int mon_offcet[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int yearoff;
    int dayoff, res;
    if (year >= 1900 && year < 2000) {
	cen_offcet = 0;
    } else if (year >= 2000 && year < 3000) {
	cen_offcet = 6;
    }
    year = year % 100;
    yearoff = (year + year / 4) % 7;
    dayoff = day % 7;
    res = cen_offcet + yearoff + mon_offcet[mon - 1] + dayoff;
    res = res % 7;
    if (((year%100)%4) == 0 && (mon == 1 || mon == 2)) {
      if(res==0){
	 res=6;
    }
    else{
     res = res - 1;
   }
   }
    return res;
}
void current(){
time_t tn;
struct tp *loc_time;
printf("\t\t\tWelcome to Calendar \n");

  tn = time(NULL);
  loc_time = localtime(&tn);
    printf("\t\t\t %s",asctime (loc_time));

}
void end(int month,int year){
int i,j;
int b;
int c=1;
b=six(c,month,year);
printf("Saturday Of this Month are \n");
for(i=b;i<6;i++){
     b=b+1;
     c=c+1;
	}
     for(j=c;j<=mon[month-1];j++){
	printf("%d-%d-%d \n",j,month,year);
	j=j+6;

     }
     printf("Sundays of this month are \n");
       for(j=c+1;j<=mon[month-1];j++){
	printf("%d-%d-%d \n",j,month,year);
	j=j+6;

     }
getch();

}


