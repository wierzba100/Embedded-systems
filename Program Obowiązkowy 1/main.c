#include <LPC21xx.H>

#define NULL 0

enum CompResult {DIFFERENT,EQUAL};
enum Result {OK,ERROR};

void CopyString(char pcSource[], char pcDestination[])
{
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0;pcSource[ucCharacterCounter]!=NULL;ucCharacterCounter++)
	{
		pcDestination[ucCharacterCounter]=pcSource[ucCharacterCounter];
	}
	pcDestination[ucCharacterCounter]=NULL;
}

//int main()
//{
//    char pcSource[]= {"NAPIS"};
//    char pcDestination[254];
//		CopyString(pcSource, pcDestination);
//}

enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0; pcStr1[ucCharacterCounter]==pcStr2[ucCharacterCounter];ucCharacterCounter++)
	{
		if(pcStr1[ucCharacterCounter]==NULL)
		{
			return EQUAL;
		}
	}
  return DIFFERENT;
}

//char pcStr1[]="NAPIS";
//char pcStr2[]="NAPdsfgsIS";
//printf("%s\n", pcStr1);
//printf("%s\n", pcStr2);
//printf("%s\n", eCompareString(pcStr1, pcStr2));
//return 0;

void AppendString (char pcSourceStr[],char pcDestinationStr[])
{
	unsigned char ucNullLocation;
  for(ucNullLocation=0; pcDestinationStr[ucNullLocation]!=NULL; ucNullLocation++) {}
  CopyString(pcSourceStr, pcDestinationStr+ucNullLocation);
}

//int main()
//{
  //char pcSourceStr[]="NAPIS";
	//char pcDestinationStr[254]="abcdgdbh";
	//AppendString(pcSourceStr,pcDestinationStr);
//}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar)
{
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0;pcString[ucCharacterCounter]!=NULL;ucCharacterCounter++)
	{
		if(pcString[ucCharacterCounter]==cOldChar)
		{
			pcString[ucCharacterCounter]=cNewChar;
		}
	}
}

enum CompResult eTest;
int main()
{
  char pcStr1[]="NAPIS";
	char pcStr2[]="NAPdsfgsIS";
	eTest=eCompareString(pcStr1, pcStr2);
}
