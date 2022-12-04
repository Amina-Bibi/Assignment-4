struct Patient
{
    int id;
    char name[30];
    char CNIC[15];	
    char disease[30];
    int phone,age;
    int isAdmitted;
} x[100];
int n=0,num=0,sum=0,i;
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num);//how many inputs
    printf("\n\t\tHow many entry do you want to add= ");
    scanf("%d",&n);
    sum=n+num;

    for(i=num; i<sum; i++)
    {
        printf("\n");
        printf("Enter patient's ID = ");
        scanf("%d",&x[i].id);
      int j=0,e=0;
          for(j=0;j<num;j++){     //don't take already existing ID
			if(x[i].id==x[j].id){
				while(x[j].id==x[i].id){
			printf("Alrady exist\n");
			scanf("%d",&x[i].id);}
			for(j=0;j<num;j++){
			if(x[i].id==x[j].id){
			while(x[j].id==x[i].id){	
			printf("Alrady existiii\n");
			scanf("%d",&x[i].id);}
			}}
		j=0;
			}}
		
        fflush(stdin);
        printf("Enter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter patient's CNIC = ");
        gets(x[i].CNIC); 
        for(j=0;j<num;j++){      //don't take already existing CNIC
				if(strcmp(x[j].CNIC,x[i].CNIC)==0){
			while(strcmp(x[j].CNIC,x[i].CNIC)==0){
				printf("Already existed\n");
		gets(x[i].CNIC);}
		for(j=0;j<num;j++){
				if(strcmp(x[j].CNIC,x[i].CNIC)==0){
			while(strcmp(x[j].CNIC,x[i].CNIC)==0){
				printf("Already existed\n");
		gets(x[i].CNIC);}
		}}
		j=0;
		}}
        fflush(stdin);
        printf("Enter disease = ");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("Is patient Admitted?(1-yes, 0-no) = ");
        scanf("%d",&x[i].isAdmitted);
        if(x[i].isAdmitted!=1 && x[i].isAdmitted!=0)    // 1is for Admitted & 0 is for non Admitted
        while((x[i].isAdmitted!=0) && (x[i].isAdmitted !=1))  //if user enters ther than digit it will store 0
        scanf("%d",&x[i].isAdmitted);
        fflush(stdin);
        printf("\n");
        num++;
    }
}
void read()
{
    FILE *fp = fopen("Patient_Record.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("Patient_Record.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, existing...\n\n\n");
    }

    num = fread(x, sizeof(struct Patient),100, fp);      //data reading
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("Patient_Record.txt","w");
    if(fp == NULL)
    {
        printf("Error");
    }
    else
    fwrite(x, num, sizeof(struct Patient), fp);        //data writing

    fclose(fp);
}
void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n",i);
        printf("Name = ");
        puts(x[i].name);
        printf("Disease = ");
        puts(x[i].disease);
        printf("CNIC = ");
        puts(x[i].CNIC);
        printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[i].id,x[i].phone,x[i].age,x[i].isAdmitted);
        printf("\t\t------------------------------\n"); 
    }
}
void del()						//delete and shuffle the records with variou choices
{
    int f,h;
    printf("Enter the serial number of the patient that you want to delete(0-%d)= ",num-1);
    scanf("%d",&f);
    if(f<num)
    {
        printf("\t\tWhat do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove CNIC\n6.Remove phone number\n");
		printf("7.Remove ID\n8.Remove isAdmitted\nOption = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                strcpy(x[f].CNIC,x[f+1].CNIC);
                x[f].age=x[f+1].age;
                x[f].id=x[f+1].id;
                x[f].phone=x[f+1].phone;
                x[f].isAdmitted=x[f+1].isAdmitted;
                f++;
                  }
                            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"#Cleared");

        }
        else if(h==3)
        {
            strcpy(x[f].disease,"#Cleared");
        }
        else if(h==4)
        {
            x[f].age=0;
        }
         else if(h==5)
        {
            x[f].id=0;
        }
        else if(h==6)
        {
            x[f].phone=0;                //if an integer vaue is deleted than assign 0in that place
        }
        else if(h==7)
        {
            x[f].id=0;
        }
        else if(h==8)
        {
            x[f].isAdmitted=0;          //if patient is not admitted than obviously he or she has left the hospital
        }

    }
    else
        printf("\n\t\tInvalid Serial number\n");   
         
         /*actually i have maitained the data 
		 thrugh erial number as it ia always going to be unique*/

}
void edit()
{
    int q,p;
    fflush(stdin);
    printf("\n\t\tWhat do you want to edit ?\n");
    printf("Enter your option\n");
    printf("0.ID\n1.Name\n2.Disease\n3.Age\n4.CNIC\n5.Phone no.\n6.isAdmitted");
    printf("\nOption=");
    scanf("%d",&q);//options
    if(q<=6)
    {
        printf("Enter the serial no of that patient= (0 - %d)=",num-1);
        scanf("%d",&p);//serial number
        if(p<num)
        {
        if(q==0)  //ID
         {
                fflush(stdin);
                printf("Enter the new ID=");
                scanf("%d",&x[p].id);
                int j=0,e=0;
          for(j=0;j<p;j++){             //check before the serial number
		   //don't take already existing ID
			while(x[p].id==x[j].id){
				printf("exist before it\n");
			scanf("%d",&x[p].id);   
				j=0;
			}	}
			 for(j=p+1;j<num;j++){      //check after the serial number
		   //don't take already existing ID
			while(x[p].id==x[j].id){
				printf("exist after it\n");
			    scanf("%d",&x[p].id);   
				j=p+1;
		}
	}
            }	
        	
           else if(q==1) //Name
            {
                fflush(stdin);
                printf("Enter the new name=");
                gets(x[p].name);

            }
            else if(q==2) //Disease
            {
                fflush(stdin);
                printf("Enter the new Disease=");
                gets(x[p].disease);
            }
            else if(q==3) //Age
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d",&x[p].age);
            }
            else if(q==4) //CNIC
            {
                fflush(stdin);
                printf("Enter the new CNIC=");
        gets(x[p].CNIC);
      int j=0,e=0;
          for(j=0;j<p;j++){             //check before the serial number
		   //don't take already existing ID
			while(strcmp(x[p].CNIC,x[j].CNIC)==0){
				printf("exist before it\n");
			gets(x[p].CNIC);  
				j=0;
			}	}
			 for(j=p+1;j<num;j++){      //check after the serial number
		   //don't take already existing ID
			while(strcmp(x[p].CNIC,x[j].CNIC)==0){
				printf("exist after it\n");
			   gets(x[p].CNIC);
				j=p+1;
		}
	}
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d",&x[p].phone);
            }
            else if(q==6)
            {
                fflush(stdin);
                printf("Enter the new isAdmitted status =");
                scanf("%d",&x[p].isAdmitted);
                if(x[p].isAdmitted!=1 && x[p].isAdmitted!=0) //1 means admitted 0 means no
                while((x[p].isAdmitted!=0) && (x[p].isAdmitted !=1))
                scanf("%d",&x[p].isAdmitted);
            }
        }
        else
        {
            printf("\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s,h,f,g;
    char u[100];
    printf("\n\t\tBy what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.ID.\n5.Phone no.\n6.Age\n\nOption = ");
    scanf("%d",&h); //search options
    if(h==1)
    {
        printf("Enter Serial number of the patient(0-%d)= ",num-1);
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number=%d\n",s);
            printf("Name = ");
			puts(x[s].name);
            printf("Disease = ");
            puts(x[s].disease);
            printf("CNIC = ");
       		puts(x[s].CNIC);
       		printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[s].id,x[s].phone,x[s].age,x[s].isAdmitted);
            printf("\n\n"); 
        }
        else
            printf("\n\nNot Found\n\n");
    }
        else if(h==2)  //By name
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("CNIC = ");
       			puts(x[g].CNIC);
       			printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[g].id,x[g].phone,x[g].age,x[g].isAdmitted);
                printf("\n\n"); 
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n"); //runs if name does not found



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("CNIC = ");
       			puts(x[g].CNIC);
       			printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[g].id,x[g].phone,x[g].age,x[g].isAdmitted);
                printf("\n\n"); 
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");


    }
    else if(h==4)
    {
        int f=1,m;
        printf("Enter ID number = ");
        scanf("%d",&m);
        for(g=0; g<num; g++)
        {
            if(m==x[g].id)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("CNIC = ");
       			puts(x[g].CNIC);
       			printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[g].id,x[g].phone,x[g].age,x[g].isAdmitted);
                printf("\n\n"); 
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1,m;
        printf("Enter Phone number = ");
        scanf("%d",&m);
        for(g=0; g<num; g++)
        {
            if(m==x[g].phone)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("CNIC = ");
       			puts(x[g].CNIC);
       			printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[g].id,x[g].phone,x[g].age,x[g].isAdmitted);
                printf("\n\n"); 
                f=0;
            }

        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==6)
    {
        int f=1,m;
        printf("Enter Age = ");
        scanf("%d",&m);
        for(g=0; g<num; g++)
        {
            if(x[g].age==m)
            {
            	 f=0;
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("CNIC = ");
       			puts(x[g].CNIC);
       			printf("ID= %d\nPhone number = %d\nAge=%d\niSAdmitted=%d\n",x[g].id,x[g].phone,x[g].age,x[g].isAdmitted);
                printf("\n\n"); 
               
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else
        printf("\n\nInvalid input\n\n");   //if other than choice data is entered
}


  

