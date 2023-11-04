#include "Header.h"



const string ClientsFileName = "Clients.txt";

void Login(void);
void ShowMainATM_MenuScreen(void);
void ShowQuickWithdrawMenuScreen(void);

struct strClient
{
	string AccountNumber;
	string PIN_Code;
	double Balance;
};

strClient CurrentClient;

void BackToATM_MenuScreen() {

	printf("\nPress Any Key, To Go Back To The ATM Menu...");
	system("pause > 0");

	ShowMainATM_MenuScreen();
}

void LoginScreen() {

	system("cls");
	printf("--------------------------------------\n");
	printf("              Login Screen            \n");
	printf("--------------------------------------\n");
}

vector <string> SplitString(string S1, string Seperator = "#//#") {

	vector <string> vString;

	short Pos;
	string sWord;

	while ((Pos = S1.find(Seperator)) != std::string::npos) 
	{
		sWord = S1.substr(0, Pos);

		if (sWord != "") {

			vString.push_back(sWord);
		}

		S1.erase(0, Pos + Seperator.length());
	}

	if (S1 != "") 
	{
		vString.push_back(S1);
	}

	return vString;
}

strClient ConvertLineToClientRecord(string DataLine,string Seperator = "#//#") {

	vector <string> vString = SplitString(DataLine, Seperator);

	strClient Client;
	Client.AccountNumber = vString[0];
	Client.PIN_Code = vString[1];
	Client.Balance = stod(vString[2]);

	return Client;
}

vector <strClient> LoadDataFromClientsFile() {

	vector <strClient> vClients;

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::in);

	if (MyFile.is_open()) {

		string DataLine;
		strClient Client;

		while (getline(MyFile,DataLine))
		{
			Client = ConvertLineToClientRecord(DataLine);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber , string PINCODE , strClient &Client) {

	vector <strClient> vClients = LoadDataFromClientsFile();

	for (strClient& C : vClients) {

		if (C.AccountNumber == AccountNumber && C.PIN_Code == PINCODE) {

			Client = C;
			return true;
		}
	}

	return false;
}

bool LoadClientsInfo(string AccountNumber, string PINCODE) {

	return FindClientByAccountNumberAndPinCode(AccountNumber, PINCODE, CurrentClient);
}

enum enATM_Menu { eQuick_Withdraw = 1 , eNormal_Withdraw , eDeposit , eCheck_Balance , eLogout };

short ReadATM_MenuOption() {

	return legend::ReadNumber_InRange::ReadNumber_InRange_short_Ver("Choose , What Do You Want To Do [ 1 To 5 ] ?  | ",1,5);
}

void Logout() {

	Login();
}

void ShowCheckBalanceScreen() {

	system("cls");
	printf("--------------------------------------\n");
	printf("          Check Balance Screen        \n");
	printf("--------------------------------------\n\n");

	printf("Your Balance is { %.3f } \n\n", CurrentClient.Balance);
}

bool IsAcceptableWithdrawing(double AmountToDeposite) {

	return ((int)AmountToDeposite % 5 == 0);
}

string ConvertClientRecordToLine(strClient& Client , string Seperator = "#//#") {

	return Client.AccountNumber + Seperator + Client.PIN_Code + Seperator + to_string(Client.Balance);
}

void LoadClientsToFile(vector <strClient> &vClients) {

	fstream MyFile;
	MyFile.open(ClientsFileName, ios::out);

	if (MyFile.is_open()) {

		string DataLine;

		for (strClient& C : vClients) {

			DataLine = ConvertClientRecordToLine(C);
			MyFile << DataLine << endl;
		}

		MyFile.close();
	}
}

bool DepositeMoneyFromAccount(vector <strClient> vClient , double AmountOfDeposite) {

	char SureToPerform = legend::Strings::ReadChar("\nAre You Sure To Perform This Transaction [ Y / N ] ?  | ");

	if (toupper(SureToPerform) == 'Y') {

		for (strClient& C : vClient) {

			if (C.AccountNumber == C.AccountNumber) 
			{
				C.Balance += AmountOfDeposite;
				printf("Done Successfully , New Balance is: %.3f\n", C.Balance);
				break;
			}
		}

		LoadClientsToFile(vClient);
		
		return true;
	}

	return false;
}


void ShowDepositScreen() {

	system("cls");
	printf("--------------------------------------\n");
	printf("             Deposite Screen          \n");
	printf("--------------------------------------\n");

	vector <strClient> vClients = LoadDataFromClientsFile();
	double AmountToDeposite = legend::ReadPositiveNumbers::ReadPositiveNumber_float_Ver("\nEnter An Amount ?  | ");

	DepositeMoneyFromAccount(vClients, AmountToDeposite);
	CurrentClient.Balance += AmountToDeposite;
}


void ShowWithdrawScreen() {

	system("cls");
	printf("--------------------------------------\n");
	printf("             Withdraw Screen          \n");
	printf("--------------------------------------\n");

	vector <strClient> vClients = LoadDataFromClientsFile();

	double AmountToWithdraw;

	do {

		AmountToWithdraw = legend::ReadPositiveNumbers::ReadPositiveNumber_float_Ver("\nEnter An Amount Of Withdrawing (Multiple 5's) ?  | "); cout << endl;

		if (AmountToWithdraw > CurrentClient.Balance) {

			printf("The Amount Exceeds Your Balance , Make Another Choice.\n");
			system("pause");
			ShowWithdrawScreen();
			return;
		}

	} while (!IsAcceptableWithdrawing(AmountToWithdraw));

	DepositeMoneyFromAccount(vClients, AmountToWithdraw * -1);
	CurrentClient.Balance -= AmountToWithdraw;
}


short ReadQuickWithdrawMenuOption() {

	return legend::ReadNumber_InRange::ReadNumber_InRange_short_Ver("Choose , What Do You Want To Do [ 1 To 9 ] ?  | ", 1, 9);
}

short GetQuickWithdrawAmount(short QuickWithdrawOption) {

	switch (QuickWithdrawOption)
	{
	case 1:
		return 20;

	case 2:
		return 50;

	case 3:
		return 100;

	case 4:
		return 200;

	case 5:
		return 400;

	case 6:
		return 600;

	case 7:
		return 800;

	case 8:
		return 1000;
	}
}

void PerformQuickWithdrawOptions(short QuickWithdrawOption) {

	if (QuickWithdrawOption == 9)
		return;

	double WithdrawAmount = GetQuickWithdrawAmount(QuickWithdrawOption);
	
	if (WithdrawAmount > CurrentClient.Balance) {

		printf("The Amount Exceeds Your Balance , Make Another Choice.\n");
		system("pause");
		ShowQuickWithdrawMenuScreen();
		return;
	}

	vector <strClient> vClients = LoadDataFromClientsFile();
	DepositeMoneyFromAccount(vClients, WithdrawAmount * -1);
	CurrentClient.Balance -= WithdrawAmount;
}

void ShowQuickWithdrawMenuScreen() {

	system("cls");
	printf("======================================\n");
	printf("             Deposite Screen          \n");
	printf("======================================\n");
	printf("       [1] 20             [2] 50 \n");
	printf("       [3] 100            [4] 200 \n");
	printf("       [5] 400            [6] 600 \n");
	printf("       [7] 800            [8] 1000 \n");
	printf("       [9] Exit \n");
	printf("======================================\n");

	printf("Your Balance is %.3f \n\n", CurrentClient.Balance);

	PerformQuickWithdrawOptions(ReadQuickWithdrawMenuOption());
}

void PerformATM_MenuOptions(enATM_Menu ATMOption) {

	switch (ATMOption)
	{

	case eQuick_Withdraw:
		ShowQuickWithdrawMenuScreen();
		BackToATM_MenuScreen();
		break;

	case eNormal_Withdraw:
		ShowWithdrawScreen();
		BackToATM_MenuScreen();
		break;

	case eDeposit:
		ShowDepositScreen();
		BackToATM_MenuScreen();
		break;

	case eCheck_Balance:
		ShowCheckBalanceScreen();
		BackToATM_MenuScreen();
		break;

	case eLogout:
		Logout();
		break;
	}
}


void ShowMainATM_MenuScreen() {

	system("cls");

	printf("==================================================== \n");
	printf("                  ATM Menu Screen               \n");
	printf("==================================================== \n");
	printf("          [1] Quick Withdraw.  \n");
	printf("          [2] Normal Withdraw. \n");
	printf("          [3] Deposit. \n");
	printf("          [4] Check Balance. \n");
	printf("          [5] Logout. \n");
	printf("==================================================== \n");

	PerformATM_MenuOptions((enATM_Menu)ReadATM_MenuOption());
}

void Login() {

	string AccountNumber, PIN_Code;

	bool LoginFailed = false;

	do {

		LoginScreen();

		if (LoginFailed)
		{
			printf("Invalid { Account Number / PIN CODE } !! \n");
		}


		printf("Enter An Account Number ?  | ");
		getline(cin >> ws, AccountNumber);

		PIN_Code = legend::Strings::ReadString("Enter PIN CODE ?  | ");

		LoginFailed = !LoadClientsInfo(AccountNumber,PIN_Code);

	} while (LoginFailed);

	ShowMainATM_MenuScreen();
}



void main() {

	Login();
}