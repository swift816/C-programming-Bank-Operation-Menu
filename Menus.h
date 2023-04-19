//for displays of menu and sub-menus
void MenuDashBoard()
{
	system("CLS");
	printf("CPE 1B1 BANKING SOFTWARE SYSTEM VERSION 4\n");
	printf("-------------------------------------------\n");
	printf("[1] Application Administrator\n");
	printf("[2] Bank Employee\n");
	printf("[3] Bank Client\n");
	printf("[4] Close Application\n");
	printf("-------------------------------------------\n");
}

int Menu(int menuType) //try to improve variables like (int employeeType)
{
	//this function is to direct menu display for Bank Manager, Bank Teller or Bank Client
	//guide
	int employeeType;
	
	if(menuType == 1)
	{
		employeeType = 1;
		MenuBankEmployee();
	}
	else if(menuType == 2)
	{
		employeeType = 2;
		MenuBankEmployee();
	}
	else if(menuType == 3)
	{
		MenuBankClient();
	}
}

int MenuBankEmployee(int employeeType)
{
	// purpose of this function is to appropriately display menu options based on employee type and redirect to appropriate functions
	char choice;
	int userType;
	
	userType = 1;
	if(employeeType == 1)
	{
		while(1)
		{
			system("CLS");
			printf("CPE 1B1 Bank Software System\n----------------------------\n");
			printf("[1] Deposit/Withdraw\n");
			printf("[2] Display Accounts\n");
			printf("[3] Add New Accounts\n");
			printf("[4] Update Accounts\n");
			printf("[X] Exit\n ");
			printf("----------------------------\n");
			printf("Please select desired operation: ");
			scanf("%c", &choice);
			if(choice == '1')
			{
				getchar();
				DepositWithdraw(userType);
			}
			else if(choice == '2')
			{
				DisplayAccounts();
			}
			else if(choice == '3')
			{
				AddNewAccounts();
			}
			else if(choice == '4')
			{
				UpdateAccounts();
			}
			else if(choice == 'x' || choice == 'X')
			{
				printf("Program Terminated...............Thank you for using CPE 1B1 Bank Software System");
				getch();
				UserTypeSelect();
			}
			else
			{
				printf("Unknown input............please try again...........");
				getch();
			}
			getchar();
		}
	}
	else if(employeeType == 2)
	{
		while(1)
		{
			system("CLS");
			printf("CPE 1B1 Bank Software System\n----------------------------\n");
			printf("[1] Deposit/Withdraw\n");
			printf("[2] Display Accounts\n");
			printf("[X] Exit\n ");
			printf("-------------------------\n");
			printf("Please select desired operation: ");
			scanf("%c", &choice);
			if(choice == '1')
			{
				getchar();
				DepositWithdraw(userType);
			}
			else if(choice == '2')
			{
				DisplayAccounts();
			}
			else if(choice == 'x' || choice == 'X')
			{
				printf("Program Terminated...............Thank you for using CPE 1B1 Bank Software System");
				getch();
				UserTypeSelect();
			}
			else
			{
				printf("Unknown input............please try again...........");
				getch();
			}
			getchar();
		}
	}
}

int MenuBankClient()
{
	system("cls");	
	getchar();
	printf("\nMenu Bank Client\n\n");
	DepositWithdraw(2);
	return(0);
}

int DisplayAccounts()
{
	//purpose of this function to display sub-menu options when viewing, or querying of accounts
	char choice;
	int status =0;
	getchar();
	while(1)
	{
		system("CLS");
		printf("View Bank Account Records");
		printf("\n-------------------------\n");
		printf("[1] All Accounts\n");
		printf("[2] Individual Accounts\n");
		printf("[3] Active Accounts\n");
		printf("[4] Inactive Accounts\n");
		printf("[5] Back to Previous Menu\n");
		printf("\n-------------------------\n");
		printf("Select your choice: ");
		scanf("%c", &choice);
		//ADD CODE HERE
		switch(choice)
		{
			case '1':
				ViewAllAccounts();
				getchar();
				break;
			case '2':
				ViewSpecificRecord();
				getchar();
				break;
			case '3':
				status = 1;
				ViewAccountByStatus(status);
				break;
			case '4':	
				status = 2;
				ViewAccountByStatus(status);
				break;
			case '5':
				return 0;
				break;
			default:
				printf("Invalid Choice...Try Again");
				getch();
		}
	}
	getch();
}

void AdminMenu()
{
	//function for displaying options for administrator account only and redirecting to a desired function of operation.

	char choice;
	getch();
	
	while(1)
	{
		system("CLS");
		printf("Administrator Options");
		printf("\n-------------------------\n");
		printf("[1] Add New Bank Employee Accounts\n");
		printf("[2] Add New Bank Client Accounts\n");
		printf("[3] View Employee List\n");
		printf("[4] View Clients List\n");
		printf("[5] Update Employee Position\n");
		printf("[6] Update Status Client\n");
		printf("[X] Back to Previous Menu\n");
		printf("\n-------------------------\n");
		printf("Select your choice: ");
		scanf("%c", &choice);
		//ADD CODE HERE
		if(choice == '1')
		{
			AddNewEmployee();
		}
		else if(choice == '2')
		{
			AddNewAccounts();
		}
		else if(choice == '3')
		{
			ViewAllEmployees();
		}
		else if(choice == '4')
		{
			ViewAllAccounts();
		}
		else if(choice == '5')
		{
			ChangeEmployeePosition();
		}
		else if(choice == '6')
		{
			UpdateAccounts();
		}
		else if(choice == 'x' || choice == 'X')
		{
			UserTypeSelect();
		}
		else
		{
			printf("Unknown input............please try again...........");
			getch();
		}
	}
}

