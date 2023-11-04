#pragma once



#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

#pragma warning (disable : 4996);

const double PI = 3.141592653589793238462643383279502884197;

namespace legend
{


	int GetRandomNumber(int From, int To)
	{
		return  rand() % (To - From + 1) + From;
	}


	namespace ReadNumber {

		short ReadNumber_short_Version(string Message) {

			short Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail()) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << " \n|Be Sure To Enter A Number ~" + Message;
				cin >> Number;

			}

			return Number;
		}
		float ReadNumber_float_Version(string Message) {

			float Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail()) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << " \n|Be Sure To Enter A Number ~" + Message;
				cin >> Number;

			}

			return Number;
		}
		int ReadNumber(string Message) {

			int Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail()) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << " \n|Be Sure To Enter A Number ~" + Message;
				cin >> Number;

			}

			return Number;
		}
		bool ReadNumber_bool_Version(string Message) {

			bool Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number < 0 || Number>1)) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << " \n|Be Sure To Enter A Number ~" + Message;
				cin >> Number;

			}

			return Number;
		}
	}

	namespace ReadNumber_InRange {

		int ReadNumber_InRange(string Message, int From, int To) {

			int Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number<From || Number>To)) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				printf("\n|Be Sure To Enter A Number Between [ %d and %d ] ~", From, To);
				cout << Message;
				cin >> Number;

			}

			return Number;
		}
		float ReadNumber_InRange_float_Ver(string Message, float From, float To) {

			float Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number<From || Number>To)) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				printf("\n|Be Sure To Enter A Number Between [ %.3f and %.3f ] ~", From, To);
				cout << Message;
				cin >> Number;

			}

			return Number;
		}
		short ReadNumber_InRange_short_Ver(string Message, short From, short To) {

			short Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number<From || Number>To)) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				printf("\n|Be Sure To Enter A Number Between [ %d and %d ] ~", From, To);
				cout << Message;
				cin >> Number;

			}

			return Number;
		}
	}

	namespace ReadPositiveNumbers {

		short ReadPositiveNumber_short_Ver(string Message) {

			short Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number < 0)) {


				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				printf("\n|Be Sure To Enter A Positive Number ~");
				cout << Message;

			}

			return Number;
		}
		float ReadPositiveNumber_float_Ver(string Message) {

			float Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number < 0)) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				printf("\n|Be Sure To Enter A Positive Number ~");
				cout << Message;
				cin >> Number;

			}

			return Number;
		}
		int ReadPositiveNumber(string Message) {

			int Number = 0;
			cout << Message;

			cin >> Number;


			while (cin.fail() || (Number < 0)) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				printf("\n|Be Sure To Enter A Positive Number ~");
				cout << Message;
				cin >> Number;

			}

			return Number;
		}
	}

	namespace Strings {

		string TrimLeft(string S1) {

			for (short i = 0; i < S1.length(); i++) {

				if (S1[i] != ' ')
					return S1.substr(i, S1.length() - 1);
			}
			return "";
		}

		string TrimRight(string S1) {

			for (short i = S1.length() - 1; i >= 0; i--) {

				if (S1[i] != ' ')
					return S1.substr(0, i + 1);
			}
			return "";
		}

		string Trem(string S1) {

			return (TrimLeft(TrimRight(S1)));
		}

		string JoinString(vector <string> vWords, string Delim = "#//#") {

			string JoinedWord = "";

			for (string& Word : vWords)
				JoinedWord += Word + Delim;

			return JoinedWord.substr(0, JoinedWord.length() - Delim.length());
		}

		string JoinString(string arr[], short arrLength, string Delim = "#//#") {

			string Word;

			for (short i = 0; i < arrLength; i++) {

				Word += arr[i] + Delim;
			}
			return Word.substr(0, Word.length() - Delim.length());
		}

		string ReadString(string Message)
		{
			string Word = "";

			cout << Message;
			getline(cin, Word);

			return Word;
		}

		string AllStringToUpper(string Word) {

			for (short i = 0; i < Word.length(); i++) {

				Word[i] = toupper(Word[i]);
			}
			return Word;

		}

		string AllStringToLower(string Word) {

			for (short i = 0; i < Word.length(); i++) {

				Word[i] = tolower(Word[i]);
			}
			return Word;

		}

		string UpperFirstLetterOf_EachWord(string Word) {

			bool IsFirstLetter = true;

			for (short i = 0; i < Word.length(); i++) {

				if (Word[i] != ' ' && IsFirstLetter)
				{
					Word[i] = toupper(Word[i]);
				}
				IsFirstLetter = ((Word[i] == ' ') ? true : false);
			}
			return Word;
		}

		string LowerFirstLetterOf_EachWord(string Word) {

			bool IsFirstLetter = true;

			for (short i = 0; i < Word.length(); i++) {

				if (Word[i] != ' ' && IsFirstLetter)
				{
					Word[i] = tolower(Word[i]);
				}
				IsFirstLetter = ((Word[i] == ' ') ? true : false);
			}
			return Word;
		}

		char InvertCharacter_Case(char Char) {

			return ((isupper(Char)) ? tolower(Char) : toupper(Char));
		}

		char ReadChar(string Message) {

			char Character;
			cout << Message;

			cin >> Character;
			return Character;
		}

		string InvertString_Case(string S1) {


			for (short i = 0; i < S1.length(); i++) {
				S1[i] = legend::Strings::InvertCharacter_Case(S1[i]);
			}
			return S1;
		}

		short CountLetters(string& S1, char& Letter, bool MatchCase = true) {

			short Counter = 0;

			if (MatchCase) {

				for (short i = 0; i < S1.length(); i++) {
					(S1[i] == Letter) ? Counter++ : 0;
				}
				return Counter;
			}

			for (short i = 0; i < S1.length(); i++) {
				(toupper(S1[i]) == toupper(Letter)) ? Counter++ : 0;
			}
			return Counter;

		}

		bool IsVowel(char Letter) {

			Letter = tolower(Letter);
			return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
		}

		vector <string> SplitStringToVector(string S1, string Delim = "#//#") {

			vector <string> vWord;

			string Word;
			short Pos = 0;

			while ((Pos = S1.find(Delim)) != std::string::npos) {

				Word = S1.substr(0, Pos);

				if (Word != "")
					vWord.push_back(Word);

				S1.erase(0, Pos + Delim.length());
			}

			if (S1 != "")
				vWord.push_back(S1);

			return vWord;
		}

	}

	namespace Matrix {

		void FillMatrix_WithRandomNumbers(short Array[3][3], short Rows, short Cols)
		{
			for (int i = 0; i < Rows; i++)
			{
				for (short j = 0; j < Cols; j++) {

					Array[i][j] = legend::GetRandomNumber(1, 100);
				}

			}
		}

		void PrintMatrix(short arr[3][3], short Rows, short Cols) {

			for (short i = 0; i < Rows; i++) {

				for (short j = 0; j < Cols; j++) {

					cout << setw(3); printf("%0*d\t", 2, arr[i][j]);
				}
				cout << endl;
			}
		}

		void FillMatrixWithOrderedNumbers(short arr[3][3], short Rows, short Cols)
		{

			short Counter = 0;
			for (short i = 0; i < Rows; i++)
			{
				for (short j = 0; j < Cols; j++)
				{
					Counter++;
					arr[i][j] = Counter;
				}
			}
		}

		short RowsSum(short arr[3][3], short Rows, short Cols) {

			int RowsSum = 0;

			for (short j = 0; j < Cols; j++) {

				RowsSum += arr[Rows][j];
			}

			return RowsSum;
		}

		short ColumsSum(short arr[3][3], short Rows, short Cols) {

			int SumColum = 0;

			for (short j = 0; j < Rows; j++) {

				SumColum += arr[j][Cols];

			}

			return SumColum;
		}

		int MatrixSum(short Marr[3][3], short Rows, short Cols) {

			int MatrixSum = 0;

			for (short i = 0; i < Rows; i++) {

				for (short j = 0; j < Cols; j++) {

					MatrixSum += Marr[i][j];
				}
			}

			return MatrixSum;
		}

		short Count_NeededNumber_InMatrix(short arr[3][3], short NumberToCount, short Rows, short Cols) {

			short Count_RepeatedNumber = 0;

			for (short i = 0; i < Rows; i++) {

				for (short j = 0; j < Cols; j++) {

					(arr[i][j] == NumberToCount) ? Count_RepeatedNumber++ : 0;
				}
			}

			return Count_RepeatedNumber;

		}

		bool IsNumber_InMatrix(short marr[3][3], short NumberToCheck, short Rows, short Cols) {

			for (short i = 0; i < Rows; i++) {

				for (short j = 0; j < Cols; j++) {

					if (marr[i][j] == NumberToCheck)
						return true;
				}
			}
			return false;
		}
	}

	namespace Arrays {

		void FillArray_WithRandomNumbers(int Array[100], short& arrLength)
		{
			arrLength = legend::ReadNumber_InRange::ReadNumber_InRange_short_Ver("How Many Elements Do You Want ,From [ 1 to 100 ] ?    |~ ", 1, 100);

			for (int i = 0; i < arrLength; i++)
			{
				Array[i] = legend::GetRandomNumber(1, 100);
			}
		}
		void FillArray_WithRandomNumbers(short Array[100], short& arrLength)
		{
			arrLength = legend::ReadNumber_InRange::ReadNumber_InRange_short_Ver("How Many Elements Do You Want ,From [ 1 to 100 ] ?    |~ ", 1, 100);

			for (int i = 0; i < arrLength; i++)
			{
				Array[i] = legend::GetRandomNumber(1, 100);
			}
		}
		void FillArray_WithRandomNumbers_WithoutRead(short Array[100], short& arrLength)
		{

			for (int i = 0; i < arrLength; i++)
			{
				Array[i] = legend::GetRandomNumber(1, 100);
			}
		}


		short FindNumberPosition_InArray(short arr[100], short arrLength, short SearchFor)
		{
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] == SearchFor)
					return i;
			}

			return -1;
		}

		bool IsNumber_InArray(short arr[100], short arrLength, short NumberToCheck)
		{
			return (FindNumberPosition_InArray(arr, arrLength, NumberToCheck) != -1);
		}

		void AddArrayElement_InArray(int NumberToAdd, int ArrayDistination[100], short& arrDistinationLength)
		{
			arrDistinationLength++;
			ArrayDistination[arrDistinationLength - 1] = NumberToAdd;
		}
		void AddArrayElement_InArray(short NumberToAdd, short ArrayDistination[100], short& arrDistinationLength)
		{
			arrDistinationLength++;
			ArrayDistination[arrDistinationLength - 1] = NumberToAdd;
		}

		void InputUserNumbers_InArray(int arr[100], short& arrLength)
		{
			char AddMore = ' ';

			do
			{
				AddArrayElement_InArray(legend::ReadNumber::ReadNumber("Please enter a Number ? | "), arr, arrLength);

				AddMore = legend::Strings::ReadChar("Press [y] For Add More Elements  Or Any Key If You Finish   |"); cout << "\n\n";

			} while (AddMore == 'Y' || AddMore == 'y');
		}
		void CopyArray(short SourceArray[100], short ArrayDistination[100], short arrSourceLength, short& arrDistinationLength)
		{
			for (int i = 0; i < arrSourceLength; i++)
			{
				AddArrayElement_InArray(SourceArray[i], ArrayDistination, arrDistinationLength);
			}
		}

		void ReadArray(int arr[100], short& arrLength)
		{

			arrLength = legend::ReadPositiveNumbers::ReadPositiveNumber_short_Ver("Enter Number Of Elements :\n");

			cout << "\nEnter array elements :\n";

			for (int i = 0; i < arrLength; i++)
			{
				arr[i] = legend::ReadNumber::ReadNumber("Element [" + to_string(i + 1) + "]:");
			}
		}

		void PrintArray(int Arr[], short arrLength)
		{
			for (int i = 0; i < arrLength; i++)
			{
				cout << Arr[i] << " ";
			}
			cout << endl;
		}
		void PrintArray(short Arr[], short arrLength)
		{
			for (int i = 0; i < arrLength; i++)
			{
				cout << Arr[i] << " ";
			}
			cout << endl;
		}
	}

	namespace Time {

		char* LocalTime() {
			time_t Time = time(NULL);
			char* pLocTime = (ctime(&Time));
			return pLocTime;
		}

		char* GMT_Time() {
			time_t Time = time(NULL);
			tm* GMT_Time = gmtime(&Time);
			char* pGMT_Time = asctime(GMT_Time);
			return pGMT_Time;
		}
	}

	namespace Vector {

		void InputUserNumber_InVector(vector <int>& vUserInputs) {

			char AddMore = ' ';
			do {

				vUserInputs.push_back(legend::ReadNumber::ReadNumber("Please , Enter A Number ?  | "));

				AddMore = legend::Strings::ReadChar("Press [y] For Add More Elements  Or Any Key If You Finish   |"); cout << "\n\n";

			} while (toupper(AddMore) == 'Y');
		}

		void PrintVector_Int(vector <int>& vNumbers) {

			for (int& Number : vNumbers)
				cout << Number << endl;
		}
	}

	namespace Files {

		void PrintFileContenet(string FileName) {

			fstream MyFile; string Line;

			MyFile.open(FileName, ios::in); //read mode

			if (MyFile.is_open()) {

				while (getline(MyFile, Line)) {

					cout << Line << endl;
				}
				MyFile.close();
			}
		}

		void LoadDataFromFileToVector(string FileName, vector <string>& vFileContenet) {

			fstream MyFile; string Line;

			MyFile.open(FileName, ios::in);

			if (MyFile.is_open()) {

				while (getline(MyFile, Line)) {

					vFileContenet.push_back(Line);
				}

				MyFile.close();
			}
		}

		void SaveVectorToFile(string FileName, vector <string>& vFileContenet) {

			fstream MyFile;

			MyFile.open(FileName, ios::out);

			if (MyFile.is_open()) {

				for (string& Line : vFileContenet) {

					if (Line != "") {

						MyFile << Line << endl;
					}
				}
				MyFile.close();
			}
		}

		void DeleteRecordFromFile(string MyFile, string RecordToDelete) {

			vector <string> vFileContenet;
			legend::Files::LoadDataFromFileToVector(MyFile, vFileContenet);

			for (string& Line : vFileContenet) {

				if (Line == RecordToDelete) {
					Line = "";
				}
			}
			legend::Files::SaveVectorToFile(MyFile, vFileContenet);
		}

		void UpdateRecordInFile(string FileName, string RecordToReplace, string UpdateTo) {

			vector <string> vFileContenet;
			legend::Files::LoadDataFromFileToVector(FileName, vFileContenet);

			for (string& Line : vFileContenet) {

				if (Line == RecordToReplace) {

					Line = UpdateTo;
				}
			}
			legend::Files::SaveVectorToFile(FileName, vFileContenet);
		}

		void AddDataLineToFile(string FileName, string Line) {

			fstream MyFile;

			MyFile.open(FileName, ios::out | ios::app);

			if (MyFile.is_open()) {

				MyFile << Line << endl;

				MyFile.close();
			}

		}
	}







	int ReverseNumber(int Number)
	{
		short Remainder = 0; int ReversedNumber = 0;
		while (Number > 0)
		{
			Remainder = (Number % 10);
			Number /= 10;

			ReversedNumber = ReversedNumber * 10 + Remainder;
		}

		return ReversedNumber;
	}
	bool Check_IsPrimeNumber(int Number)
	{

		for (int i = 2; i <= ceil(Number / 2); i++)
		{
			if (Number % i == 0)
				return false;
		}

		return true;
	}
	bool Check_IsPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i <= ceil(Number / 2); i++)
		{
			if (Number % i == 0)
			{
				Sum += i;
			}
		}

		return (Number == Sum);
	}
	bool Check_IsPalindromeNumber(int Number)
	{
		return (Number == ReverseNumber(Number));
	}



	enum enCharType { CapitalLetter, SmallLetter, SpecialCharacter, Digit };
	char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{

		case enCharType::SmallLetter:
		{
			return char(legend::GetRandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(legend::GetRandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(legend::GetRandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(legend::GetRandomNumber(48, 57));
			break;
		}

		}
	}

	string NextLine(short NumberOfLinesToStepUp) {

		string NextLine = "";
		for (short NextLines = 1; NextLines <= NumberOfLinesToStepUp; NextLines++)
			NextLine += "\n";

		return NextLine;

	}

	string Tabs(short NumberOfTabs) {

		string OrderedTabs = "";

		for (short i = 1; i <= NumberOfTabs; i++)
			OrderedTabs += "\t";

		return OrderedTabs;
	}



	void Swap(short& FirstNumber, short& SecondNumber)
	{
		short* Temp = new short;

		*Temp = FirstNumber;
		FirstNumber = SecondNumber;
		SecondNumber = *Temp;

		delete Temp;
	}
	void Swap(int& FirstNumber, int& SecondNumber)
	{
		int* Temp = new int;

		*Temp = FirstNumber;
		FirstNumber = SecondNumber;
		SecondNumber = *Temp;

		delete Temp;
	}

}


