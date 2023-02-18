#include <stdio.h>

#include "program_obowiazkowy_funkcje.h"

void TestOf_CopyString(void)
{
	printf("CopyString\n\n ");

	printf("Test 1 - ");
	//ta sama dlugosc
	char cSource1[]="hello";
	char cDestination1[]="napis";
	CopyString(cSource1,cDestination1);
	if(eCompareString(cDestination1,cSource1)==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//kopiowany string krotszy
	char cSource2[]="kot";
	char cDestination2[]="napis";
	CopyString(cSource2,cDestination2);
	if(eCompareString(cDestination2,cSource2)==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 3 - ");
	//kopiowany string pusty
	char cSource3[]="";
	char cDestination3[]="napis";
	CopyString(cSource3,cDestination3);
	if(eCompareString(cDestination3,cSource3)==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_eCompareString(void)
{
    printf("eCompareString\n\n ");

    printf("Test 1 - ");
    //taka sama wartosc i dlugosc
    char cStr1_1[]="napis";
	char cStr2_1[]="napis";
	if (eCompareString(cStr1_1,cStr2_1)==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    //jeden string pusty
    char cStr1_2[]="";
	char cStr2_2[]="napis";
	if (eCompareString(cStr1_2,cStr2_2)==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
	printf("Test 3 - ");

    //jeden string dluzszy
    char cStr1_3[]="napisanyjesttenstring";
	char cStr2_3[]="napis";
	if (eCompareString(cStr1_3,cStr2_3)==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_AppendString(void)
{
    printf("AppendString\n\n ");

    printf("Test 1 - ");
    //dowolne
    char cDestination1[]="napis";
	AppendString("cos", cDestination1);
	if (eCompareString(cDestination1,"napiscos")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
    //lancuch zrodla pusty
    char cDestination2[]="napis";
	AppendString("", cDestination2);
	if (eCompareString(cDestination2,"napis")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
    //lancuch destination pusty
    char cDestination3[]="";
	AppendString("cos", cDestination3);
	if (eCompareString(cDestination3,"cos")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_ReplaceCharactersInString(void)
{
    printf("ReplaceCharactersInString\n\n ");

    printf("Test 1 - ");
	//rozne znaki
	char cString1[]="Hello World";
	ReplaceCharactersInString(cString1, 'l', 'x');
	if (eCompareString(cString1, "Hexxo Worxd")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
	//Null jako nowy char
	char cString2[]="Hello World";
	ReplaceCharactersInString(cString2, 'l', NULL);
	if (eCompareString(cString2, "He\0\0o Wor\0d")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_UIntToHexStr(void)
{
    printf("UIntToHexStr\n\n ");

    printf("Test 1 - ");
    //krance przedzialow, 0,9,A,F
	char cStr1[6];
	unsigned int uiValue1=0xAF09;
	UIntToHexStr(uiValue1, cStr1);
	if (eCompareString(cStr1, "0xAF09")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//zero na koncu i poczatku stringa
    char cStr2[6]="";
    unsigned int uiValue2=0x0120;
	UIntToHexStr(uiValue2, cStr2);
	if (eCompareString(cStr2,"0x0120")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}


void TestOf_eHexStringToUInt(void)
{
    printf("eHexStringToUInt\n\n ");

    printf("Test 1 - ");
    //zly znak na poczatku headera
    unsigned int puiValueAfterConversion1;
    char pcStringToConversion1[8]="1x05DC";
    if (eHexStringToUInt(pcStringToConversion1,&puiValueAfterConversion1)==0) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    //zly znak na koncu headera
    unsigned int puiValueAfterConversion2;
    char pcStringToConversion2[8]="0D05DC";
    if (eHexStringToUInt(pcStringToConversion2,&puiValueAfterConversion2)==0) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 3 - ");
    //za dlugi string
    unsigned int puiValueAfterConversion3;
    char pcStringToConversion3[10]="0x05DCDDD";
    if (eHexStringToUInt(pcStringToConversion3,&puiValueAfterConversion3)==0) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 4 - ");
    //Null w srodku stringa
    unsigned int puiValueAfterConversion4;
    char pcStringToConversion4[8]="0x 05DC";
    if (eHexStringToUInt(pcStringToConversion4,&puiValueAfterConversion4)==0) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 5 - ");
    //string zgodny z konwencja funkcji
    unsigned int puiValueAfterConversion5;
    char pcStringToConversion5[8]="0x05DC";
    if (eHexStringToUInt(pcStringToConversion5,&puiValueAfterConversion5)==0) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 6 - ");
    //krotszy string
    unsigned int puiValueAfterConversion6;
    char pcStringToConversion6[8]="0x5DC";
    if (eHexStringToUInt(pcStringToConversion6,&puiValueAfterConversion6)==0) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_AppendUIntToString(void)
{
    printf("AppendUIntToString\n\n ");

    printf("Test 1 - ");
	//niepusty string
	char cDestination1[]="Napis";
	unsigned uiValue1=452;
	AppendUIntToString(uiValue1,cDestination1);
	if (eCompareString(cDestination1,"Napis0x01C4")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//pusty string
	char cDestination2[]="";
	unsigned uiValue2=452;
	AppendUIntToString(uiValue2,cDestination2);
	if (eCompareString(cDestination2,"0x01C4")==EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_ucFindTokensInString(void)
{
	printf("ucFindTokensInString\n\n ");

    unsigned char ucTokenNumber;
	printf("Test 1 - ");
	//max liczba tokenow
	char cString1="napis 0x1234 load";
	ucTokenNumber=ucFindTokensInString(cString1);
	if (ucTokenNumber==3) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//delimitery na poczatku i wiecej niz 1 pomiedzy tokenami
	char cString2=" napis  0x1234  load ";
	ucTokenNumber=ucFindTokensInString(cString2);
	if (ucTokenNumber==3) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	//mniej tokenow niz max
	char cString3="napis load";
	ucTokenNumber=ucFindTokensInString(cString3);
	if (ucTokenNumber==2) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 4 - ");
	//same delimitery
	char cString4="napis load";
	ucTokenNumber=ucFindTokensInString(cString4);
	if (ucTokenNumber==0) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 5 - ");
	//wiecej tokenow niz max
    char cString5[]="napis 0x1234 load hello";
	ucTokenNumber=ucFindTokensInString(cString5);
	if ((ucTokenNumber==3) printf("OK\n\n "); else printf("Error\n\n\n");
}

enum KeywordCode eTokenCode;
void TestOf_eStringToKeyword(void)
{
	printf("eStringToKeyword\n\n ");

	printf("Test 1 - ");
	//string nie jest keywordem
	char cKeyword1="napis"
	if (eStringToKeyword(cKeyword1,&eTokenCode)==ERROR) printf("OK\n\n\n"); else printf("Error\n\n\n");

	printf("Test 2 - ");
	//string jest keywordem
	char cKeyword2="load"
	if (eStringToKeyword(cKeyword2, &eTokenCode)==OK) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_DecodeTokens()
{

	printf("DecodeTokens\n\n ");

	unsigned char ucTokenNumber;
	printf("Test 1 - ");
	//w komunikacie mamy liczbe, stringa i keyworda
	char cMessage1[]="0x1234 napis load";
	ucTokenNumber=ucFindTokensInString(cMessage1);
	ReplaceCharactersInString(cMessage1,' ',NULL);
	DecodeTokens();
	if ((asToken[0].eType==NUMBER) && (asToken[0].uValue.uiNumber==0x1234) &&
			(asToken[1].eType==STRING) && (&cMessage1[7]==asToken[1].uValue.pcString) &&
			(asToken[2].eType==KEYWORD) && (asToken[2].uValue.eKeyword==LD)) printf("OK\n\n\n"); else printf("Error\n\n\n");
}

void TestOf_DecodeMsg()
{
    printf("DecodeMsg\n\n ");
	printf("Test 1 - ");
	//w komunikacie mamy liczbe, stringa i keyworda
	char cMessageToDecode[]="0x1234 napis load";
	DecodeMsg(ucMessageToDecode);
	if ((asToken[0].eType==NUMBER) && (asToken[0].uValue.uiNumber==0x1234) &&
			(asToken[1].eType==STRING) && (&cMessageToDecode[7]==asToken[1].uValue.pcString) &&
			(asToken[2].eType==KEYWORD) && (asToken[2].uValue.eKeyword==LD)) printf("OK\n\n\n"); else printf("Error\n\n\n");
}

int main()
{
    printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n ");
    TestOf_CopyString();
    TestOf_eCompareString();
    TestOf_AppendString();
    TestOf_ReplaceCharactersInString();
    printf("TESTY FUNKCJI DO KONWERSJI \n\n\n ");
    TestOf_UIntToHexStr();
    TestOf_eHexStringToUInt();
    TestOf_AppendUIntToString();
    printf("TESTY FUNKCJI DO DEKODOWANIA \n\n\n ");
    TestOf_ucFindTokensInString(void);
    TestOf_eStringToKeyword(void);
    TestOf_DecodeTokens();
    TestOf_DecodeMsg();

    return 0;
}
