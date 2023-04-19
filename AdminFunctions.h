//THIS LIBRARY FILE is IDENTIFIED  as having functions that only the Administrator account is privileged to do

void CreateEmployeeID(char *startString)
{
	//purpose of this function is for a system-generated employee id number
	ACCOUNTNUM accountNum;
	int sequence;
	char sAccountNum[10];
	char charNumber[1];
		
	file = fopen(path4, "a+");
	if(file == NULL)
	{
		printf("File Could Not be Created!!!");
		getch();
	}
	else
	{
		while(fread(&accountNum, sizeof(ACCOUNTNUM), 1, file)==1)	
		{
			sequence = accountNum.sequence;
			strcpy(sAccountNum, accountNum.sAccountNum);
		}
		
		sequence++;
		fflush(stdin);
		accountNum.sequence = sequence;
		sprintf(charNumber, "1-%d", sequence);

		strcat(startString, charNumber);

		strcpy(accountNum.sAccountNum, startString);

		fwrite(&accountNum, sizeof(ACCOUNTNUM), 1, file);
		fclose(file);
	}
}


void AddNewEmployee()
{
	//purpose of this function is to add a new employee 
	//take note of the following assignments
	//			1 - Manager
	//			2 - Bank Teller
	system("CLS");
	printf("Adding New Employees");

	EMPLOYEE employee;
	
	getchar();

    char sAccountNum[10] = "CPE1B1-202";
	char sFirstName[30];
    char sMiddleName[30];
    char sLastName[30];
    float fBalance;
    int status = 1;	
    int acctType;
    int position;
    int saveType = 1;	
        
    printf("\n\n\n");
	CreateEmployeeID(sAccountNum);
	getch();
	printf("New Account Number: %s \n", sAccountNum);
    printf("Enter Client First Name: ");
    gets(sFirstName);
    printf("Enter Client Middle Name: ");
    gets(sMiddleName);
    printf("Enter Client Family Name: ");
    gets(sLastName);
    while(1)
    {
    	printf("\nSelect [1] Manager, [2] For bank Teller: ");
    	scanf("%d", &position);
		if(position == 1 || position == 2)
		{
			break;
		}
		else
		{
			printf("\nInvalid Account Type......Press Any Key to Continue.");
			getch();	
		}	
	}

	//saving into personal.dat
	file = fopen(path5, "a+");
	if(file == NULL)
	{
		printf("File Could Not be Created!!!");
		getch();
	}
	else
	{
		fflush(stdin);
		
		SaveEmployee(sAccountNum,sFirstName,sMiddleName,sLastName,position);

		fclose(file);
	}

	printf("Data Added Successfully!!!");
	getchar();

}

void ViewAllEmployees()
{
	//the purpose of this function is for the viewing of the employee list
	EMPLOYEE employee;
	int xAxis;
	int yAxis = 2;
	
	system("CLS");
	
	file = fopen(path5, "r");

	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		printf("Employee ID Number\t\tEmployee Name\t\t\tPosition\n-----------------------------------------------------------------------------------------------\n");
		while((fread(&employee, sizeof(EMPLOYEE), 1, file))==1)		
		{ 
				gotoxy(0,yAxis);  printf("%s", employee.sAccountNum);
				gotoxy(24,yAxis); printf("%s, %s  %s", employee.personName.sLastName, employee.personName.sFirstName, employee.personName.sMiddleName);	
				gotoxy(60,yAxis); 
				if(employee.position == 1)
					{
						printf("    MANAGER");	
					}
				else if(employee.position == 2)
					{
						printf("    BANK TELLER");
					}
				yAxis++;
		}
		fclose(file);
	}
	getch();
}

void ChangeEmployeePosition()
{
	//purpose of this function is to change employee positio(e.g. manager to bank teller or bank teller to manager)
	getchar();
	system("CLS");
	
	FINANCIAL clientFinancial; 
	PERSONAL clientPersonal;
	EMPLOYEE employee;
	
	char changeStatus;
	int status;
	int detect = 0;
	int count = 0;
	
	char sAccountNum[10];
    int tempStatus;
    int found = 0;
    
	printf("This is change employee position module\n\n");
	printf("Enter ID number to update:  ");
	gets(sAccountNum);
	
	file = fopen(path5, "r");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		while((fread(&employee, sizeof(EMPLOYEE), 1, file))==1)		
		{ 
			if(!strcmp(sAccountNum, employee.sAccountNum))
			{
				printf("\n\nEMPLOYEE FOUND\n");
				gotoxy(20,4);
				printf("\nEMPLOYEE NUMBER: ");
				printf("%s", employee.sAccountNum);
				gotoxy(20,5);	
				printf("\nEMPLOYEE NAME: ");
				printf("%s, %s  %s", employee.personName.sLastName, employee.personName.sFirstName, employee.personName.sMiddleName);
				gotoxy(20,7);
				printf("\nCURRENT POSTITION: ");
				if(employee.position == 1)
				{
					printf("MANAGER\n\n");	
				}
				else if(employee.position == 2)
				{
					printf("BANK TELER\n\n");
				}
				found = 1;
				break;
			}			
		}
		fclose(file);
	}
	
	if(found == 0)
	{
		printf("\nAccount Does Not Exist.....Press Any Key To Continue....");
		getch();
		return;
	}
	
	file = fopen(path5, "r+");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		while((fread(&employee, sizeof(EMPLOYEE), 1, file))==1)				//1 - THERE IS STILL A RECORD TO READ
		{ 
			if(!strcmp(sAccountNum, employee.sAccountNum))
			{
				status = employee.position;
				detect = count++;
				break;
			}
			else
			{
				count++;
			}
		}
		
		getchar();
		if(status == 1)
		{
			printf("Press Y to change to BANK TELLER.....Others for Cancel: ");
			scanf("%c", &changeStatus);
			if(changeStatus == 'Y' || changeStatus == 'y')
			{
				status = 2;
			}
		}
		else if(status == 2)
		{
			printf("Press Y to change to MANAGER.....Others for Cancel: ");
			scanf("%c", &changeStatus);
			if(changeStatus == 'Y' || changeStatus == 'y')
			{
				status = 1;
			}
		}
			
		strcpy(employee.sAccountNum, sAccountNum);
		employee.position = status;
		fseek(file, (detect)*sizeof(EMPLOYEE), SEEK_SET);		//SEEK_SET-> start reading from beginning of record
		fwrite(&employee, sizeof(EMPLOYEE), 1, file);
		
		fclose(file);
		
		if(changeStatus == 'Y' || changeStatus == 'y')
		{
			printf("\n\n\n EMPLOYEE POSITION UPDATED.....");
			getch();
		}
		else
		{
			printf("\n\n\n EMPLOYEE POSITION NOT UPDATED.....");
			getch();
		}
	}
}

