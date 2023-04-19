void UserTypeSelect()
{
	int userType;
	
	while(1)
	{
		system("CLS");
		MenuDashBoard();
		printf("Please select type of user: ");
		scanf("%d", &userType);
		getch();
		if(userType == 1)
		{
			getchar();
			UserLoginAdmin();
		}
		else if(userType == 2)
		{
			getchar();
			UserLoginEmployee();
		}
		else if(userType == 3)
		{
			getchar();
			UserLoginClient();
		}
		else if(userType == 4)
		{
			exit(0);
		}
		else
		{
			UserTypeSelect();
		}
		getch();
	}
}

void UserLoginAdmin()
{
	char user[20] = "usjrcpe";			//super admin username
	char pass[20] = "Usjrcpe123";		//super admin password
	
	char username[20];
	char password[20];
	int employeeType;
	int index = 0;
	int input;
	
	system("CLS");
	printf("\n\nEnter Username: ");
	gets(username);
	printf("Enter Password: ");
    do{
		input = getch();
		if(input == '\b')
		{
			if(index > 0)
			{
				printf("\b \b");
				password[index] = '\0';
				index--;
			}
		}	
		else if(input != '\r')		
		{
			printf("*");
			password[index] = input;
			index++;
		}
		else
		{
			password[index] = '\0';
			break;
		}
	}while(1);	
	
	if(strcmp(username, user) == 0)
	{
		if(strcmp(password, pass) == 0)
		{
			printf("\n\nLOGIN SUCCESSFUL!!......press any button to continue");
			getch();
			AdminMenu();
		}
		else
		{
			printf("\nPassword Incorrect!......press any button to continue");
			getch();
			return(0);
		}
	}
	else
	{
		printf("\nUsername is Incorrect!......press any button to continue");
		getch();
		return(0);
	}
	
}


void UserLoginEmployee()
{
	//for employee login
	EMPLOYEE employee;
	
	char sAccountNum[10];
	char sFamilyName[20];
	int detect = 0;
	int count = 0;
	int found = 0;
	int menuType;
	
	system("CLS");
	
	printf("BANK EMPLOYEE LOGIN\n");
	printf("Enter ID number to login:  ");
	gets(sAccountNum);
	printf("Enter Family Name of Employee: ");
	gets(sFamilyName);
		
	file = fopen(path5, "r+");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		while((fread(&employee, sizeof(EMPLOYEE), 1, file))==1)	
		{ 
			if((!strcmp(sAccountNum, employee.sAccountNum)) && (strcmp(sFamilyName, employee.personName.sLastName) == 0))
			{
				printf("\nWELCOME EMPLOYEE ID: <%s>\n", employee.sAccountNum);
				found = 1;
				detect = count++;
				if(employee.position == 1)
				{
					printf("\nYou are Manager: %s, %s  %s", employee.personName.sLastName, employee.personName.sFirstName, employee.personName.sMiddleName);
					menuType = 1;
				}
				else if(employee.position == 2)
				{
					printf("\nYou are Bank Teller: %s, %s  %s", employee.personName.sLastName, employee.personName.sFirstName, employee.personName.sMiddleName);
					menuType = 2;
				}
				break;	
			}	
			else
			{
				count++;
			}	
		}
		fclose(file);
	}
	if(found == 0)
	{
		printf("\n\nLogin Unsuccessful.....Press Any Key To Continue....");
		getche();
		UserTypeSelect();
	}
	else if(found == 1)
	{
		printf("\n\nLogin Successful.....Press Any Key To Continue....");
		getchar();
		Menu(menuType);
	}

}

void UserLoginClient()
{
	//for bank client login
	int menuType = 3;

	Menu(menuType);
}
