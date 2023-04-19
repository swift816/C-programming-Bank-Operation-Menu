//Function that saves or updates any information in the financial.dat file
void SaveFinancial(char *sAccountNum, int acctType, float fBalance, int status, int saveType)
{
	//for saving client financial information into financial.dat
	FINANCIAL clientFinancial;
	

	strcpy(clientFinancial.sAccountNum, sAccountNum);
	clientFinancial.acctType = acctType;
	clientFinancial.fBalance = fBalance;
	clientFinancial.status = status;
	if(saveType == 2)	
	{
		fseek(file, (detect)*sizeof(FINANCIAL), SEEK_SET);	
	}
	fwrite(&clientFinancial, sizeof(FINANCIAL), 1, file);
	
	
}

void SavePersonal(char *sAccountNum, char *sFirstName, char *sMiddleName, char *sLastName)
{
	//for saving client personal information into personal.dat
	PERSONAL clientPersonal;
	
	strcpy(clientPersonal.sAccountNum, sAccountNum);
	strcpy(clientPersonal.personName.sFirstName, sFirstName);
	strcpy(clientPersonal.personName.sMiddleName, sMiddleName);
	strcpy(clientPersonal.personName.sLastName, sLastName);
	fwrite(&clientPersonal, sizeof(PERSONAL), 1, file);
}

void SaveEmployee(char *sAccountNum, char *sFirstName, char *sMiddleName, char *sLastName, int position)
{
	//saving new employees into empInfo.dat
	EMPLOYEE employee;
	
	strcpy(employee.sAccountNum, sAccountNum);
	strcpy(employee.personName.sFirstName, sFirstName);
	strcpy(employee.personName.sMiddleName, sMiddleName);
	strcpy(employee.personName.sLastName, sLastName);
	employee.position = position;

	fwrite(&employee, sizeof(EMPLOYEE), 1, file);
	
}

void SaveLogs(char *sAccountNum, int transactionType, float oldBalance, float amount, float newBalance)
{
	//for saving client logs into clientlogs.dat
	TRANSACTION transaction;
	CLIENTLOGS clientLogs;
	FILE *file2;
	
	file2 = fopen(path6, "a+");
	
	strcpy(clientLogs.thisClient.sAccountNum, sAccountNum);
	clientLogs.thisClient.transactionType = transactionType;
	clientLogs.oldBalance = oldBalance;
	clientLogs.amount = amount;
	clientLogs.newBalance = newBalance;

	fwrite(&transaction, sizeof(TRANSACTION), 1, file2);
	fwrite(&clientLogs, sizeof(CLIENTLOGS), 1, file2);
	
	fclose(file2);
	
}
