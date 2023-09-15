#pragma once
#include <iostream>
#include <string>
#include <cmath>


class clsUtil
{
public:


static void AddArrayElements(int Number, int arr[100], int& arrLength){
/// its a new array so we need  to add the length by 1
arrLength++;
arr[arrLength-1] = Number;

}


static int FindNumberPositionInArray(int Number, int arr[100], int arrLength){
 /*This function will search for a number in array and
 return its index , or return -1 if it does not exists*/

 for (int i =0; i < arrLength; i++)
  {
    if (arr[i] == Number)
        return i; // And return the index
  }
// if you reached here, this mean the number is not found
return -1;

}
static bool IsNumberInArray(int Number, int arr[100], int arrLength){

 return FindNumberPositionInArray(Number,arr,arrLength) != -1;

}

 enum enPrimeNotPrime{Prime = 1, NotPrime = 2};

static enPrimeNotPrime CheckPrime(int Number){

  int M = round(Number / 2);
  for(int Counter =2; Counter <= M; Counter++)
    {
    if ( Number % Counter == 0)
    return enPrimeNotPrime::NotPrime;
    }
  return enPrimeNotPrime::Prime;

}

static void CopyArray(int arrSource[100],int arrDestination[100], int arrLength){

  for(int i =0; i < arrLength; i++)
    {
      arrDestination[i]= arrSource[i];
    }

}

static int EvenCount(int arr[100],int arrLength){

 int Counter =0;

 for (int i =0; i < arrLength; i++)
 {
     if (arr[i]% 2 == 0)
     {
         Counter++;
     }

 }
 return Counter ;

 }

static int OddCount(int arr[100],int arrLength){

 int Counter =0;

 for (int i =0; i < arrLength; i++)
 {
     if (arr[i] % 2 != 0)
     {
         Counter++;
     }

 }
 return Counter ;

 }

static int PositiveCount(int arr[100],int arrLength){

 int Counter =0;

 for (int i =0; i < arrLength; i++)
 {
     if (arr[i] >= 0)
     {
         Counter++;
     }

 }
 return Counter ;

 }

 static int CountDigitFrequency(short DigitToCheck, int Number )
    {
        int FreqCount =0, Remainder =0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
        return FreqCount;
    }

static float GetFractionsPart(float Number){
return Number - int(Number);

}

static int MaxNumberInArray(int arr[100], int arrLength){

 int Max=0;

 for (int i =0; i < arrLength; i++)
 {
     if (arr[i]> Max)
    {
          Max = arr[i];
    }

 }
  return Max;


}

static int MinNumberInArray(int arr[100], int arrLength){

 int Min=0;
 Min = arr[0];
 for (int i =0; i < arrLength; i++)
 {
     if (arr[i]< Min)
    {
          Min = arr[i];
    }

 }
  return Min;

}

static bool isPerfecNumber(int Number)
{
    int Sum=0;
    for (int i =1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum+=i;
    }
    return Number == Sum;
}

 static void PrintArray(int arr[100], int arrLength){

 for (int i =0; i < arrLength; i++)
     cout << arr[i] << " ";

     cout<< "\n";

 }

 static void PrintArray(string arr[100], int arrLength){

 for (int i =0; i < arrLength; i++)
     cout << arr[i] << " ";

     cout<< "\n";

 }

static void PrintDigits(int Number){

 int Remainder = 0;
 while(Number > 0)
 {
     Remainder = Number % 10;
     Number = Number / 10;
     cout << Remainder << endl;
 }

}

static void PrintPartWordInverse(string Num){
 int LengthNumber =0;
 string Number =Num;
  LengthNumber= Number.length();

 for (int i = LengthNumber; i >= 0; i--)
 {
     cout << Number[i] <<endl;
 }

}

static void Srand()
{
    srand((unsigned)time(NULL));
}

static int RandomNumber(int From , int To){

//Function to generate a random number

  int randNum = rand()% (To - From + 1) + From;
  return randNum;
}

static void ReadArray(int arr[100], int& arrLength){

 cout << "\nEnter number of elements:\n";
 cin >> arrLength;

 cout << "\nEnter array elements: \n";

 for (int i = 0; i < arrLength; i++)
 {
     cout << "Element [" << i +1 << "] : ";
     cin >> arr[i];
 }
    cout << endl;

    }

static int ReadPositiveNumber(string Message){

    int Number;
    do
    {

    cout << Message << endl;
    cin >> Number;

    }while(Number < 0);
     return Number;

    }

static int ReversedNumber(int Number)
{
    int Remainder =0, Number2 =0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;

}

static int SumArray(int arr[100], int arrLength){

 int Sum =0;

 for (int i = 0; i < arrLength; i++)
 {
     Sum += arr[i];
 }
 return Sum;

}

static int  SumOfDigits(int Number){

 int  Sum = 0,Remainder = 0;

 while(Number > 0)
 {
     Remainder = Number % 10;
     Number = Number / 10;
    Sum += Remainder;
 }
 return  Sum ;

}

static void Swap(int& A, int& B)
 {

 int Timp;

  Timp = A;
  A = B;
  B = Timp;

 }

 static void Swap(double& A, double& B)
 {

 double Timp;

  Timp = A;
  A = B;
  B = Timp;

 }

 static void Swap(bool& A, bool& B)
 {

 bool Timp;

  Timp = A;
  A = B;
  B = Timp;

 }

 static void Swap(char& A, char& B)
 {

 char Timp;

  Timp = A;
  A = B;
  B = Timp;

 }

 static void Swap(string& A, string& B)
 {

 string Timp;

  Timp = A;
  A = B;
  B = Timp;

 }

 static void Swap(clsDate& A, clsDate& B)
 {
    clsDate::SwapDates(A,B);
 }


static int TimesRepeated(int Number, int arr[100], int arrLength){

 int Count =0;
 for(int i =0; i <= arrLength -1; i++)
 {
     if (Number == arr[i])
     {
         Count++;
     }
 }
 return Count;

}

enum enCharType{SmallLetter= 1,CapitalLetter=2,SpecialCharacter=3,Digit=4};

static char GetRandomCharacter(enCharType CharType){

 switch(CharType)
 {
 case enCharType::SmallLetter:
   {
        return char(RandomNumber(97,122));
        break;
   }
 case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65,90));
        break;
    }
 case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33,47));
        break;
    }
 case enCharType::Digit:
    {
        return char(RandomNumber(48,57));
        break;
    }
 }
}

static string GenerateWord(enCharType CharType, short Length){

string Word;
 for (int i =1; i<= Length; i++)
 {
    Word = Word + GetRandomCharacter(CharType);
 }
 return Word;

}

static string GenerateKey(){

string Key= "";

  Key = GenerateWord(enCharType::CapitalLetter,4) + "-";
  Key = Key + GenerateWord(enCharType::CapitalLetter,4) + "-";
  Key = Key + GenerateWord(enCharType::CapitalLetter,4) + "-";
  Key = Key + GenerateWord(enCharType::CapitalLetter,4) ;

  return Key;
}

static void GenerateKeys(int NumberOfKeys){

 for (int i =1; i <= NumberOfKeys; i++)
 {
     cout << "["<< i << "] : ";
     cout << GenerateKey() << endl;
 }

}

static void FillArrayWithRandomKeys(string arr[100], int arrLength){

  for (int i=0; i < arrLength; i++)
       arr[i] = GenerateKey();

}


static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength){

         for (int i=0; i < arrLength; i++)
       arr[i] = GenerateWord(CharType,WordLength);

}

static void FillArrayWithRandomNumbers(int arr[100], int& arrLength){

 cout << "\nEnter number of elements: \n";
 cin >> arrLength;

 for (int i =0; i < arrLength; i++)
    arr[i] = RandomNumber(1,100);

}

static string ReadText()
{
    string Text;
    cout << "Please enter the Text \n";
    getline(cin,Text);
    return Text;
}

static string EncryptText(string Text, short EncryptionKey = 2)
{
  for (int i =0; i<= Text.length(); i++)
  {

      Text[i] = char((int)Text[i] + EncryptionKey);

  }
  return Text;
}

static string DecryptText(string Text, short EncryptionKey = 2)
{
    for (int i = 0; i <= Text.length(); i++)
    {

        Text[i] = char(Text[i] - EncryptionKey);

    }
    return Text;
}

static string ReadPassword(string Message)
{
    string Password;
    cout << Message << endl;
    cin >> Password;
    return Password;
}
static bool GuessPassword(string OriginalPassword)
{

    string Word = "";
    int Counter =0;
    cout << "\n";
  for (int i = 65; i <=  90 ; i++)
  {
      for (int j = 65; j <= 90 ; j++)
      {
        for (int k = 65; k <= 90; k++)
        {

            Word = Word + char(i);
            Word = Word + char(j);
            Word = Word + char(k);
            Counter++;
            cout << "Trial["<< Counter << "]: " << Word << endl;
            if ( Word == OriginalPassword )
            {
                system("color F1");
                cout << "\nPassword is "<< Word << "\n";
                cout << "Found after ";
                cout << Counter << " Trial(s)\n";

                return true;
            }
            Word = "";
        }

      }

  }
   return false;
  }

static void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";
   for (int i = 65 + Number -1; i >= 65; i--)
    {
      for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
      {
          cout << char(i);
      }
      cout << endl;
    }
  }

static void PrintInvertedNumberPattern(int Number)
{
    cout << "\n";

    for (int i =Number; i >= 1; i--)
    {
        for (int j= 1; j <= i; j++)
        {
            cout << i ;
        }
        cout << "\n";
    }
}

static bool IsPalindromeArray(int arr[100],int arrLength){
 for (int i=0; i < arrLength; i++)
 {

    if  (arr[i] != arr[arrLength - i - 1])
    {
        return false;
    }

 }
   return true;

}

static bool IsPalindromeNumber(int Number)
{
    return Number == ReversedNumber(Number);
}

static void PrintPerfectNumbersFrom1ToN(int Number)
{
    for (int i =1; i < Number; i++)
    {

    if (isPerfecNumber(i))
        cout << i <<endl;
    }

}


static void PrintPrimeNumbersFrom1toN(int Number)
    {

cout << "\n";
cout << "Prime Numbers From " << 1 << " To " <<Number << " are : " <<endl;
for (int i=1; i <= Number; i++)
    {

    if (CheckPrime(i) == enPrimeNotPrime::Prime)
        {

    cout << i <<endl;

        }
    }
    }

static void PrintWordsFromAAAtoZZZ()
{

    cout << "\n";
    string Word = "";

  for (int i = 65; i <=  90 ; i++)
  {
      for (int j = 65; j <= 90 ; j++)
      {
        for (int k = 65; k <= 90; k++)
        {
            Word = Word + char(i);
            Word = Word + char(j);
            Word = Word + char(k);

            cout << Word << endl;

            Word = "";
        }

      }
      cout << "\n--------------------\n";
  }

  }

static void ShuffleArray(int arr[100], int arrLength){

 for (int i=0; i < arrLength; i++)
 {
 Swap(arr[RandomNumber(1,arrLength)-1],arr[RandomNumber(1,arrLength)-1]);
 }

}

static void ShuffleArray(string arr[100], int arrLength){

 for (int i=0; i < arrLength; i++)
 {
 Swap(arr[RandomNumber(1,arrLength)-1],arr[RandomNumber(1,arrLength)-1]);
 }

}


static bool Login(string PassWord,short NumberOfTrying)
{
    string PW = "";
    int Counter = NumberOfTrying;
    do
    {
        Counter--;
        PW = ReadPassword("Please Enter A PassWord");

        if (PW == PassWord)
        {
            system("color 0F");
            return 1; //this will exit the function and return true
        }
        else
        {
            if(Counter >= 1)
            {

            system("color 4F");//turn screen to Red
            cout << "\nWrong PassWord, you have "<< Counter << " more tries \n";

            }
            else
            {
                system("color 4F");//turn screen to Red
                cout << "Invalid Login " << endl;

            }
        }

    }while (Counter >= 1 && PW != PassWord);

    return 0;//when you reach here this means login faild
}

 static string NumberToText(int Number)
 {
     // Base Case
     if(Number == 0)
        return " ";

     // Recursive Base

     if(Number >= 1 && Number <= 19)
     {
         string arr[] =  {" ", "One", "Tow", "Three", "Four", "Five","Six","Seven","Eight","Nine",
        "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","NineTeen"};
          return arr[Number];
     }

     if(Number >= 20 && Number <= 99)
     {
         string arr[] = {" "," ","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
         return arr[Number / 10] + " " + NumberToText(Number % 10);
     }

     if(Number >= 100 && Number <= 199)
     {
        return  "One Hundred " + NumberToText(Number % 100);
     }

     if(Number >= 200 && Number <= 999)
     {
         return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
     }

     if(Number >= 1000 && Number <= 1999)
     {
         return "One Thousand " + NumberToText(Number % 1000);
     }

     if(Number >= 2000 && Number <= 999999)
     {
         return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number %1000);
     }

     if(Number >= 1000000 && Number <= 1999999)
     {
         return "One Million " + NumberToText(Number % 1000000);
     }

     if(Number >= 2000000 && Number <= 999999999)
     {
         return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
     }

     if(Number >= 1000000000 && Number <= 1999999999)
     {
         return "One Billion " + NumberToText(Number % 1000000000);
     }
     else
     {
         return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
     }

 }





};
