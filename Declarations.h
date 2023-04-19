struct person{
	char sFirstName[30];
    char sMiddleName[30];
    char sLastName[30];
};

typedef struct person Person;

struct clientPersonal{
    char sAccountNum[10];
    Person personName;
   };

// ALL struct declarations and global variables are defined here.  Do not add anything to this library file

struct clientFinancial{
    char sAccountNum[10];
    int acctType;
	float fBalance;
    int status;
};

struct accountNum{
	int sequence;
	char sAccountNum[10];
};

typedef struct clientPersonal PERSONAL;
typedef struct clientFinancial FINANCIAL;
typedef struct accountNum ACCOUNTNUM;

struct employee{
    char sAccountNum[20];
    Person personName;
    int position;       //1-Manager, 2-Bank Teller
   };
   
typedef struct employee EMPLOYEE;

struct transaction{
    char sAccountNum[20];
    int transactionType;
};

typedef struct transaction TRANSACTION;

struct clientLogs{
    TRANSACTION thisClient;
    float oldBalance;
    float amount;
    float newBalance;
};

typedef struct clientLogs CLIENTLOGS;

char path1[300] = "E:\\A PROGRAMMER'S WORKS\\C PROGRAMS\\CPE1B1AY202021\\DataFilesForFileHandling\\personal.dat";
char path2[300] = "E:\\A PROGRAMMER'S WORKS\\C PROGRAMS\\CPE1B1AY202021\\DataFilesForFileHandling\\financial.dat";
char path3[300] = "E:\\A PROGRAMMER'S WORKS\\C PROGRAMS\\CPE1B1AY202021\\DataFilesForFileHandling\\acctNumbers.dat";
char path4[300] = "E:\\A PROGRAMMER'S WORKS\\C PROGRAMS\\CPE1B1AY202021\\DataFilesForFileHandling\\empID.dat";
char path5[300] = "E:\\A PROGRAMMER'S WORKS\\C PROGRAMS\\CPE1B1AY202021\\DataFilesForFileHandling\\empInfo.dat";
char path6[300] = "E:\\A PROGRAMMER'S WORKS\\C PROGRAMS\\CPE1B1AY202021\\DataFilesForFileHandling\\clientLogs.dat";

FILE *file;

int detect;

void AdminMenu();



