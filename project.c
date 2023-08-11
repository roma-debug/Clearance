#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct clearance{
	char roll_no[20];
	char full_name[50];
	char bct[10];
	char bme[10];
	char bar[10];
	char lab[10];
	char library[10];	
}clear;




void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ **");
    printf("\n\t\t\t**                                                                         **");
    printf("\n\t\t\t**              Clearance Management System Project in C                   **");
    printf("\n\t\t\t**                                                                         **");
    printf("\n\t\t\t** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ ** _ **");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}


//add record
void addstudentRecord()
{
    FILE *fp;   
    clear s;
    fp = fopen("clearance.bin","ab");
    headMessage("Add Student");
    printf("\n \n Enter roll number:");
    scanf("%s",s.roll_no);
    printf("\n  Enter name of student:");
    scanf(" %[^\n]s",s.full_name);
    printf("\nEnter the clearance detail:\n");
    printf("\nBCT:");
    scanf("%s",s.bct);
    printf("\nBME:");
    scanf("%s",s.bme);
    printf("\nBAR:");
    scanf("%s",s.bar);
    printf("\nLAB:");
    scanf("%s",s.lab);
    printf("\nLibrary:");
    scanf("%s",s.library);

    fwrite(&s,sizeof(clear),1,fp);
    fclose(fp);
}

//display record
void displaystudentRecord()
{
    FILE *fp;
    clear s;
    fp = fopen("clearance.bin","rb");
    headMessage("Student Clearance Detail");
    printf("\n\n\n");
    printf("Roll No. \tName\t\t\tBCT\t\tBME\t\tBAR\t\tLAB\t\tLibrary\n");
    while(fread(&s,sizeof(clear),1,fp)==1)
    {
        printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s  ",s.roll_no,s.full_name,s.bct,s.bme,s.bar,s.lab,s.library);
    }
    fclose(fp);
}

//search student
void searchstudentDetail()
{
    int found = 0;
    char roll_no[20]={0};
    clear s={0};
    FILE *fp = NULL;
   
    fp = fopen("clearance.bin","rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH Student");
  //put the control on students detail
    if (fseek(fp,sizeof(clear),SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\t\t\tEnter roll number to search:");
    fflush(stdin);
   scanf("%s",&roll_no);
   
    while (fread (&s, sizeof(clear), 1, fp)>0 &&found==0)
    {
        if(strcmp(s.roll_no, roll_no)==0)
        {
        	found=1;
          printf("\nRoll No.\t\tName\t\t\tBCT\t\tBME\t\tBAR\t\tLAB\t\tLibrary\n");
     // fscanf(fp,"%s%s%s%s%s%s%s",s.roll_no,s.full_name,s.bct,s.bme,s.bar,s.lab,s.library);
      printf("\n%s\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",s.roll_no,s.full_name,s.bct,s.bme,s.bar,s.lab,s.library);
      
            
        }
    }
    if(found==0){
    	printf("\n\t\t\tno record");
	}
    fclose(fp);
    getchar();
}


//update record
void updatestudentRecord()
{
    FILE *fp;
    clear s;
    char ch[20];
    char roll[20];
    fp = fopen("clearance.bin","r+b");
    headMessage("UPDATE STUDENT CLEARANCE");
    printf("\n \n \tEnter the student roll no. whose cleareance is to be update:");
    scanf("%s",roll);
    while(fread(&s,sizeof(clear),1,fp)==1)
    {
        if(strcmp(s.roll_no,roll)==0)
        {
            if(strcmp(s.bct,"not")==0){
			printf(" update BCT:\n");
            scanf("%s",&ch);
            strcpy(s.bct,ch);
            fseek(fp,-sizeof(clear),SEEK_CUR);
            fwrite(&s,sizeof(clear),1,fp);
            printf("%s clearance is updated\n",s.roll_no);
            }
            
            else if(strcmp(s.bme,"not")==0){
			printf("Update BME:\n");
            scanf("%s",&ch);
            strcpy(s.bme,ch);
            fseek(fp,-sizeof(clear),SEEK_CUR);
            fwrite(&s,sizeof(clear),1,fp);
            printf("%s roll number student's clearance is updated\n",s.roll_no);
            }
            
            
            else if(strcmp(s.bar,"not")==0){
			printf("enter the update BAR:\n");
            scanf("%s",&ch);
            strcpy(s.bar,ch);
            fseek(fp,-sizeof(clear),SEEK_CUR);
            fwrite(&s,sizeof(clear),1,fp);
            printf("%s clearance is updated\n",s.roll_no);
            }
            
            else if(strcmp(s.lab,"not")==0){
			printf(" Update LAB:\n");
            scanf("%s",&ch);
            strcpy(s.lab,ch);
            fseek(fp,-sizeof(clear),SEEK_CUR);
            fwrite(&s,sizeof(clear),1,fp);
            printf("%s roll number student's clearance is updated\n",s.roll_no);
            }
            
            else if(strcmp(s.library,"not")==0){
			printf("enter the update LIbrary:\n");
            scanf("%s",&ch);
            strcpy(s.library,ch);
            fseek(fp,-sizeof(clear),SEEK_CUR);
            fwrite(&s,sizeof(clear),1,fp);
            printf("%s clearance is updated\n",s.roll_no);
            }
            
            break;
        }
    }
    fclose(fp);
}



//delete record
void deletestudentRecord()
{
    FILE *fp,*temp;
    char temp_roll_no[20];
    clear s;
    fp=fopen("clearance.bin","rb");
    headMessage("Delete Record ");
    temp=fopen("temp.bin","wb");
    printf("\n \nEnter the student roll number Whose record is to be deleted: ");
    scanf("%s",&temp_roll_no);
    while(fread(&s,sizeof(clear),1,fp)==1)
    {
        if(!strcmp(s.roll_no,temp_roll_no)==0)
        {
            fwrite(&s,sizeof(clear),1,temp);
        }
        else
        {
            printf("The %s roll number record has been deleted",s.roll_no);
        }
    }
    fclose(fp);
    fclose(temp);
    fp=fopen("clearance.bin","wb");
    temp=fopen("temp.bin","rb");
    while(fread(&s,sizeof(clear),1,temp)==1)
    {
        fwrite(&s,sizeof(clear),1,fp);
    }
    fclose(fp);
    fclose(temp);
}


int main()
{
    int choice;
    while(1)
    {
        system("cls");
        headMessage("Student Clearance management system menu");
        printf("\n1. addstudentRecord\n");
        printf("2. displaystudentRecord\n");
        printf("3. searchstudentDetail\n");
        printf("4. updatestudentRecord\n");
        printf("5. deletestudentRecord\n");
        printf("6. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:addstudentRecord();
                    break;
            case 2:displaystudentRecord();
                    break;
            case 3:searchstudentDetail();
                    break;
            case 4:updatestudentRecord();
                    break;
            case 5:deletestudentRecord();
                    break;
            case 6:exit(0);

        }
        getch();
    }
    return 0;
}
