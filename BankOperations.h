int DepositWithdraw(int userType)
{
	//FOR DEPOSIT AND WITHDRAW OPERATION
	FINANCIAL clientFinancial; 
	PERSONAL clientPersonal;
	
	char sAccountNum[10];
	char sFamilyName[20];
	float fBalance;
	float oldBalance;
	float oldAmount;
	float newBalance;
	int transactionType;
	int status;
	int performTransaction = 0;
	float amount = 0;
	int count = 0;
	int acctType;
	char choice;
	int found = 0;
	int saveType = 2;		
	
	detect = 0;
	if(userType == 1)
	{
		system("cls");	
		getchar();
		printf("Enter account number to open transaction:  ");
		gets(sAccountNum);
	
		file = fopen(path1, "r+");
		if(file == NULL)
		{
			printf("File Does Not Exist!!!");
			getch();
		}
		else
		{
			while((fread(&clientPersonal, sizeof(PERSONAL), 1, file))==1)		
			{ 
				if(!strcmp(sAccountNum, clientPersonal.sAccountNum))
				{
					printf("\n\nACCOUNT FOUND\n\n");
					printf("ACCOUNT NUMBER: %s\n", clientPersonal.sAccountNum);
					printf("ACCOUNT NAME: %s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);
					found = 1;
					break;
				}				
			}
			fclose(file);
		}
	
		if(found == 0)
		{
			printf("\nAccount Does Not Exist.....Press Any Key To Continue....");
			return;
		}
	}
	else if(userType == 2)
	{

		printf("Enter account number to open transaction:  ");
		gets(sAccountNum);
		printf("Enter Family Name of Client: ");
		gets(sFamilyName);
		
		file = fopen(path1, "r+");
		if(file == NULL)
		{
			printf("File Does Not Exist!!!");
			getch();
		}
		else
		{
			while((fread(&clientPersonal, sizeof(PERSONAL), 1, file))==1)	
			{ 
				if((!strcmp(sAccountNum, clientPersonal.sAccountNum)) && (strcmp(sFamilyName, clientPersonal.personName.sLastName) == 0))
				{
					printf("\n\nACCOUNT FOUND\n\n");
					printf("ACCOUNT NUMBER: %s\n", clientPersonal.sAccountNum);
					printf("ACCOUNT NAME: %s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);
					found = 1;
					break;	
				}
			}
			fclose(file);
		}
		if(found == 0)
		{
			printf("\nAccount Does Not Exist.....Press Any Key To Continue....");
			getche();
			UserTypeSelect();
		}
		if(strcmp(sFamilyName, clientPersonal.personName.sLastName) != 0)
		{
			printf("\nFamily Name Does Not Exist......Press Any Key To Continue....");
			getche();
			UserTypeSelect();
		}
	}
	
	file = fopen(path2, "r+");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		while((fread(&clientFinancial, sizeof(FINANCIAL), 1, file))==1)
		{ 
			if(!strcmp(sAccountNum, clientFinancial.sAccountNum))
			{
				if(clientFinancial.status == 1)
				{
					acctType = clientFinancial.acctType;
					fBalance = clientFinancial.fBalance;
					status = clientFinancial.status;
					oldBalance = fBalance;
					performTransaction = 1;
					detect = count++;
					break;
				}
				else if(clientFinancial.status == 2)
				{
					performTransaction = 2;
					break;
				}
			}
			else
			{
				count++;
			}
		}
	
		if(performTransaction == 2)
		{
			printf("\n\n\nCannot Perform Transaction...........Account is Inactive.............Change status first of account to perform transactions");
			getch();
			return 0;
		}
		else
		{
			while(1)
			{
				if(acctType == 1)
				{
					printf("\nSavings Account Balance: %.2f\n", fBalance);
			}
				else if(acctType == 2)
				{
					printf("\nCurrent Account Balance: %.2f\n", fBalance);
				}
				printf("\n\nSelect Transaction\n--------------------------------------\n");
				printf("[1] Deposit\n");
				printf("[2] Withdraw\n");
				printf("[3] Return to Previous Menu\n");
				printf("--------------------------------------\n");
				printf("Select your choice: ");
				scanf("%c", &choice);
							
				if(choice == '1')
				{
					printf("\nEnter Amount to deposit: ");
					scanf("%f", &amount);
					transactionType = 1;
					fBalance = fBalance + amount;
					printf("\nNew Balance: %.2f", fBalance);
					newBalance = fBalance;
					SaveLogs(sAccountNum, 1, oldBalance, amount, newBalance);
					break;	
				}
				else if(choice == '2')
				{
					printf("\nEnter Amount to withdraw: ");
					scanf("%f", &amount);
					transactionType = 2;
					fBalance = fBalance - amount;
					printf("\nNew Balance: %.2f", fBalance);
					newBalance = fBalance;
					SaveLogs(sAccountNum, 2, oldBalance, amount, newBalance);
					break;
				}
				else if(choice == '3')
				{
					return(0);
				}
				else
				{
					printf("\n\nInvalid Input....");
					getch();
				}
			}
			SaveFinancial(sAccountNum, acctType, fBalance, status, saveType);
			
			fclose(file);
		}
	}
	getch();
}

int UpdateAccounts()
{
	//FOR UPDATING ACCOUNT STATUS, ACTIVE TO INACTIVE AND VICE VERSA
	getchar();
	system("CLS");
	
	FINANCIAL clientFinancial; 
	PERSONAL clientPersonal;
	char changeStatus;
	float fBalance;
	int status;
	int detect = 0;
	int count = 0;
	int acctType;
	int transactionType;
	float oldBalance = 0; 
	float amount = 0; 
	float newBalance = 0;
	char sAccountNum[10];
    int tempStatus;
    int found = 0;
    int saveType = 2;
	
	printf("Enter account number to update:  ");
	gets(sAccountNum);
	
	file = fopen(path1, "r");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		while((fread(&clientPersonal, sizeof(PERSONAL), 1, file))==1)		
		{ 
			if(!strcmp(sAccountNum, clientPersonal.sAccountNum))
			{
				printf("\n\nACCOUNT FOUND\n\n");
				printf("ACCOUNT NUMBER: ");
				gotoxy(20,4);	printf("%s", clientPersonal.sAccountNum);
				printf("\nACCOUNT NAME: ");
				gotoxy(20,5);	printf("%s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);
				found = 1;
				break;
			}	
		}
		fclose(file);
	}
	
	if(found == 0)
	{
		printf("\nAccount Does Not Exist.....Press Any Key To Continue....");
		return;
	}
	
	file = fopen(path2, "r");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
		
	}
	else
	{
		while((fread(&clientFinancial, sizeof(FINANCIAL), 1, file))==1)		
		{
			if(!strcmp(sAccountNum, clientFinancial.sAccountNum))
			{
				fBalance = clientFinancial.fBalance;
				status = clientFinancial.status;
				break;
			}
		}
		printf("\nCURRENT BALANCE: ");
		gotoxy(20,6);	printf("%.2f", fBalance);
		printf("\nACCOUNT STATUS: ");
		gotoxy(20,7);	
		
		if(clientFinancial.status == 1)
		{
			printf("ACTIVE\n\n");	
		}
		else if(clientFinancial.status == 2)
		{
			printf("INACTIVE\n\n");
		}
				
		fclose(file);
	}
	
	file = fopen(path2, "r+");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		while((fread(&clientFinancial, sizeof(FINANCIAL), 1, file))==1)		//1 - THERE IS STILL A RECORD TO READ
		{ 
			if(!strcmp(sAccountNum, clientFinancial.sAccountNum))
			{
				acctType = clientFinancial.acctType;
				fBalance = clientFinancial.fBalance;
				status = clientFinancial.status;
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
			printf("Press Y to change to INACTIVE.....Others for Cancel: ");
			scanf("%c", &changeStatus);
			if(changeStatus == 'Y' || changeStatus == 'y')
			{
				transactionType = 3;
				status = 2;
			}
		}
		else if(status == 2)
		{
			printf("Press Y to change to ACTIVE.....Others for Cancel: ");
			scanf("%c", &changeStatus);
			if(changeStatus == 'Y' || changeStatus == 'y')
			{
				transactionType = 4;
				status = 1;
			}
		}
				
		SaveLogs(sAccountNum, transactionType, oldBalance, amount, newBalance);
		SaveFinancial(sAccountNum, acctType, fBalance, status, saveType);
		fclose(file);
		
		if(changeStatus == 'Y' || changeStatus == 'y')
		{
			printf("\n\n\n ACCOUNT STATUS UPDATED.....");
			getche();
		}
		else
		{
			printf("\n\n\n ACCOUNT STATUS NOT UPDATED.....");
			getche();
		}
	}
}

