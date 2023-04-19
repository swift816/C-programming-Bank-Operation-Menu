void ViewAllAccounts()
{
	//for viewing of all existing accounts
	PERSONAL clientPersonal;
	int xAxis;
	int yAxis = 2;
	
	system("CLS");
	
	file = fopen(path1, "r");

	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		printf("Account Number\t\tAccount Holder Name\t\t\tAccount Type\t\tStatus\n-----------------------------------------------------------------------------------------------\n");
		while((fread(&clientPersonal, sizeof(PERSONAL), 1, file))==1)		
		{ 
				gotoxy(0,yAxis);  printf("%s", clientPersonal.sAccountNum);
				gotoxy(24,yAxis); printf("%s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);	
				yAxis++;
		}
		fclose(file);
	}
	
	printf("\n\n");
	yAxis = 2;
	FINANCIAL clientFinancial;
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
				gotoxy(60,yAxis);
				if(clientFinancial.acctType == 1)
					{
						printf("    SAVINGS ACCOUNT");	
					}
					else if(clientFinancial.acctType == 2)
					{
						printf("    CURRENT ACCOUNT");
					}
				gotoxy(80,yAxis); 
				if(clientFinancial.status == 1)
					{
						printf("\tACTIVE");	
					}
					else if(clientFinancial.status == 2)
					{
						printf("\tINACTIVE");
					}
				yAxis++;
		}
		fclose(file);
	}
	getch();
}


void ViewSpecificRecord()
{
	//for viewing of a specific bank client account.
	//show all info here, personal, financial and the transaction history
	printf("\n\nView Specific Account\n\n");
	getchar();
	PERSONAL clientPersonal;
	FINANCIAL clientFinancial; 
	TRANSACTION transaction;
	CLIENTLOGS clientLogs;
	
	char sAccountNum[10];
	int xAxis;
	int yAxis = 10;
	int found = 0;
	int loop = 1;
	
	printf("Enter account number to open:  ");
	gets(sAccountNum);
	system("CLS");
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
					printf("Account Found!\n");
					printf("\nAccount Number: %s", clientPersonal.sAccountNum);
					printf("\nAccount Name: %s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);
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
				if(clientFinancial.acctType == 1)
				{
					printf("\nAccount Type: SAVINGS ACCOUNT");	
				}
				else if(clientFinancial.acctType == 2)
				{
					printf("\nAccount Type: CURRENT ACCOUNT");
				}
				printf("\nAccount Balance: PHP %.2f", clientFinancial.fBalance);
				if(clientFinancial.status == 1)
				{
					printf("\nAccount Status: ACTIVE");	
				}
				else if(clientFinancial.status == 2)
				{
					printf("\nAccount Status: INACTIVE");
				}
			break;	
			}
		}
		fclose(file);
	}
	
	file = fopen(path6, "r+");
	if(file == NULL)
	{
		printf("File Does Not Exist!!!");
		getch();
	}
	else
	{
		printf("\n-------------------------------------------------------------------------------------------------\n");
		printf("Transaction Type\t\tOld Balance\t\tAmount\t\tNew balance\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		while(((fread(&transaction, sizeof(TRANSACTION), 1, file))==1) && ((fread(&clientLogs, sizeof(CLIENTLOGS), 1, file))==1))
		{
			if(!strcmp(sAccountNum, clientLogs.thisClient.sAccountNum))
			{
				gotoxy(0,yAxis);	
				printf("%d. ", loop++);
				gotoxy(4,yAxis);
				if(clientLogs.thisClient.transactionType == 1)
				{
					printf(" DEPOSIT");
				}
				else if(clientLogs.thisClient.transactionType == 2)
				{
					printf(" WITHDRAW");
				}
				else if(clientLogs.thisClient.transactionType == 3)
				{
					printf(" ACTIVE TO INACTIVE");
				}
				else if(clientLogs.thisClient.transactionType == 4)
				{
					printf(" INACTIVE TO ACTIVE");
				}
				gotoxy(32,yAxis);	
				printf("%.2f", clientLogs.oldBalance);
				gotoxy(56,yAxis);	
				printf("%.2f", clientLogs.amount);
				gotoxy(72,yAxis);	
				printf("%.2f\n", clientLogs.newBalance);
				yAxis++;
			}
		}
		fclose(file);
	}
	getch();
}

void ViewAccountByStatus(int status)
{
	//for viewing account status
	PERSONAL clientPersonal;
	FINANCIAL clientFinancial;
	FILE *file2;
	
	int xAxis;
	int yAxis = 2;
	
	file = fopen(path1, "r+");
	file2 = fopen(path2, "r+");
		
	if(status == 1)
	{
		system("CLS");

		if(file == NULL)
		{
			printf("File Does Not Exist!!!");
			getch();
		}
		else
		{
			printf("Account Number\t\tAccount Holder Name\t\t\tAccount Type\t\tStatus\n-----------------------------------------------------------------------------------------------\n");
			while(((fread(&clientPersonal, sizeof(PERSONAL), 1, file)) == 1) && ((fread(&clientFinancial, sizeof(FINANCIAL), 1, file2)) == 1))
			{			
				if(clientFinancial.status == 1)
				{
					gotoxy(0,yAxis);  printf("%s",  clientPersonal.sAccountNum);
					gotoxy(24,yAxis); printf("%s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);	
					
					gotoxy(60,yAxis);
					if(clientFinancial.acctType == 1)
					{
						printf("    SAVINGS ACCOUNT");	
					}
					else if(clientFinancial.acctType == 2)
					{
						printf("    CURRENT ACCOUNT");
					}
					
					gotoxy(80,yAxis); 
					printf("\tACTIVE");
					
					yAxis++;
				}
			}
			fclose(file);
			fclose(file2);
		}
		getch();
	}
	else if(status == 2)
	{
		system("CLS");
		if(file == NULL)
		{
			printf("File Does Not Exist!!!");
			getch();
		}
		else
		{
			printf("Account Number\t\tAccount Holder Name\t\t\tAccount Type\t\tStatus\n-----------------------------------------------------------------------------------------------\n");
			while(((fread(&clientPersonal, sizeof(PERSONAL), 1, file)) == 1) && ((fread(&clientFinancial, sizeof(FINANCIAL), 1, file2)) == 1))
			{
				if(clientFinancial.status == 2)
				{
					gotoxy(0,yAxis);  printf("%s", clientPersonal.sAccountNum);
					gotoxy(24,yAxis); printf("%s, %s  %s", clientPersonal.personName.sLastName, clientPersonal.personName.sFirstName, clientPersonal.personName.sMiddleName);	
					
					gotoxy(60,yAxis);
					if(clientFinancial.acctType == 1)
					{
						printf("    SAVINGS ACCOUNT");	
					}
					else if(clientFinancial.acctType == 2)
					{
						printf("    CURRENT ACCOUNT");
					}
					
					gotoxy(80,yAxis); 
					printf("\tINACTIVE");
						
					yAxis++;
				}
			}
			fclose(file);
			fclose(file2);
		}
		getch();
	}
		
}





