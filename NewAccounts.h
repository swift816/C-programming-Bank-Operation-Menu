void CreatAccountNumbers(char *startString)
{
	//purpose of this function is for a system-generated client account number
	ACCOUNTNUM accountNum;
	int sequence;
	char sAccountNum[10];
	char charNumber[1];
		
	file = fopen(path3, "a+");
	if(file == NULL)
	{
		printf("File Could Not be Created!!!");
		getch();
	}
	else
	{
		while((fread(&accountNum, sizeof(ACCOUNTNUM), 1, file))==1)	
		{ 
				sequence = accountNum.sequence;
				strcpy(sAccountNum, accountNum.sAccountNum);
		}
		
		sequence++;
		fflush(stdin);
		accountNum.sequence = sequence;
		sprintf(charNumber, "%d", sequence);

		strcat(startString, charNumber);

		strcpy(accountNum.sAccountNum, startString);

		fwrite(&accountNum, sizeof(ACCOUNTNUM), 1, file);
		fclose(file);
	}
}

void AddNewAccounts()
{
	//purpose of this function is to add new accounts
	//information are added to this files
	//personal.dat = account number, first name, middle name and last name
	//financial.dat = account number, type of account opened, status, balance
	//clientLogs.dat = store initial transaction type of NEW ACCOUNTS 
	system("CLS");
	printf("Adding New Accounts");

	PERSONAL clientPersonal;
	FINANCIAL clientFinancial; 
	getchar();

    char sAccountNum[10] = "111-";
	char sFirstName[30];
    char sMiddleName[30];
    char sLastName[30];
    float fBalance;
    int status = 1;		//1 - active
    int acctType;
    int saveType = 1;		// 1- add new financial data or append
        
    printf("\n\n\n");
	CreatAccountNumbers(sAccountNum);
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
    	printf("\nSelect [1] For Savings Account, [2] For Current Account: ");
    	scanf("%d", &acctType);
		if(acctType == 1 || acctType == 2)
		{
			break;
		}
		else
		{
			printf("\nInvalid Account Type......Press Any Key to Continue.");
			getch();	
		}	
	}
	
    printf("Enter intial balance to open New Account: PHP ");
    scanf("%f", &fBalance);
	
	//saving into personal.dat
	file = fopen(path1, "a+");
	if(file == NULL)
	{
		printf("File Could Not be Created!!!");
		getch();
	}
	else
	{
		fflush(stdin);
		strcpy(clientPersonal.sAccountNum, sAccountNum);
		strcpy(clientPersonal.personName.sFirstName, sFirstName);
		strcpy(clientPersonal.personName.sMiddleName, sMiddleName);
		strcpy(clientPersonal.personName.sLastName, sLastName);

		fwrite(&clientPersonal, sizeof(PERSONAL), 1, file);

		fclose(file);
	}
	
	//saving into financial.dat
	file = fopen(path2, "a+");
	if(file == NULL)
	{
		printf("File Could Not be Created!!!");
		getch();
	}
	else
	{
		fflush(stdin);
//		strcpy(clientFinancial.sAccountNum, sAccountNum);
//		clientFinancial.acctType = acctType;
//		clientFinancial.fBalance = fBalance;
//		clientFinancial.status = 1;
//		fwrite(&clientFinancial, sizeof(FINANCIAL), 1, file);
		SaveFinancial(sAccountNum, acctType, fBalance, status, saveType);
			
		fclose(file);
	}
	
	printf("Data Added Successfully!!!");
	getch();
}

