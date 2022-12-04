#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"interface.h"  //Hospital management interface code
#include "readwrite.h" //include choice instructions

int main(){
   inter();
    read();
   int choice,num=0,sum=0;
   while(choice!=6){
   printf("\nWhat you would like to do???\n\n");//services that this program is responsible for giving
   printf("1.Add Patient Record\n");
   printf("2.Delete Patient Record\n");
   printf("3.Update Patient Record\n");
   printf("4.Search Patient Record\n");
   printf("5.Display All Patients\n");
   printf("6.Exit\n");
   printf("Enter your choice(1-6): ");
   scanf("%d",&choice);  //exit on entering 6
   while(choice<=0 || choice>6){
   	printf("Enter positive number which is within a range(1-6): ");
   	scanf("%d",&choice);
   }
   if(choice==1){
   	system("cls");     //clear counsole so no mess will be created
   	inter();
        add();}
     else if(choice==2){
     	system("cls");
     	inter();
     	del();}       //variety of choices to delete a patient record whole or selective
    else if(choice==3){
    	system("cls");
    	inter();
     	edit();}      //variety of choices to update a patient record whole or selective
    else if(choice==4){
    	system("cls");
    	inter();
     	search();}     //variety of choices to search a patient
     else if(choice==5){
     	system("cls");
     	inter();
     	view();}
     else if(choice==6){
     	system("cls");
     	inter();
     	printf("\n\n\n\t\t\t\t\t    Thank You for visitin us:)");
     	write();}     //writing data into a file
   
}
return 0;
}

