#include <LPC21xx.H>


#define NULL 0
#define MAX_BUF_SIZE 254
#define MAX_TOKEN_NR 3 //maksymalna dopuszczalna ilosc tokenow
#define MAX_KEYWORD_NR 3  ///maksymalna ilosc slow kluczowych
#define MAX_KEYWORD_STRING_LTH 10 ///maksymalna dlugosc komendy

enum CompResult {DIFFERENT,EQUAL};
enum Result {OK,ERROR};
enum KeywordCode {LD, ST, RST};

typedef struct Keyword
{
	enum KeywordCode eCode;
  char cString[MAX_KEYWORD_STRING_LTH + 1];
}Keyword;

typedef union TokenValue
{
	enum KeywordCode eKeyword; // jezeli KEYWORD
	unsigned int uiNumber; // jezeli NUMBER
	char * pcString; // jezeli STRING
}TokenValue;

typedef enum { KEYWORD, NUMBER, STRING} TokenType;

typedef struct Token
{
	TokenType eType; /// KEYWORD, NUMBER, STRING
  union TokenValue uValue; /// enum, unsigned int, char*
}Token;

struct Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr;
struct Keyword asKeywordList[MAX_KEYWORD_NR];
struct Keyword asKeywordList[MAX_KEYWORD_NR]=
{
	{RST,"reset"},
  {LD, "load" },
  {ST, "store"}
};

enum State{TOKEN, DELIMITER};

unsigned char ucFindTokensInString (char* pcString)
{
  enum State eState=TOKEN;
  unsigned char ucCharCounter;
  unsigned char ucTokenCounter=0;
  for(ucCharCounter=0;;ucCharCounter++)
  {
		switch(eState)
    {
			case TOKEN:
      {
				if(ucTokenCounter==MAX_TOKEN_NR)
				{
					return ucTokenCounter;
				}
				else if(*pcString==' ')
				{
					eState=DELIMITER;
				}
				else if (*pcString==NULL)
				{
					return  ucTokenCounter;
				}
				else if(ucCharCounter==0)    // jesli nie ma spacji ani NULLA na pierwszym miejscu
				{
					asToken[ucTokenCounter].uValue.pcString=pcString;
					ucTokenCounter++;
					eState=TOKEN;
				}
				else
				{
					eState=TOKEN;
				}
				break;
      }
      case DELIMITER:
      {
				if(*pcString==' ')
				{
					eState=DELIMITER;
				}
				else if(*pcString==NULL)
				{
					return ucTokenCounter;
				}
				else
				{
					asToken[ucTokenCounter].uValue.pcString=pcString;
					ucTokenCounter++;
					eState=TOKEN;
				}
				break;
      }
    }
    pcString++;
	}
}

//unsigned char NumberOfTokens;
//int main()
//{
	//char* cString="ola ma kota";
	//NumberOfTokens=ucFindTokensInString(cString);
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

enum Result eStringToKeyword(char pcStr[],enum KeywordCode *peKeywordCode)
{
    unsigned char ucKeywordCounter;

    for(ucKeywordCounter=0;ucKeywordCounter<MAX_KEYWORD_NR;ucKeywordCounter++)
    {
        if(eCompareString(asKeywordList[ucKeywordCounter].cString,pcStr )==EQUAL)
        {
            *peKeywordCode=asKeywordList[ucKeywordCounter].eCode;
            return OK;
        }
    }
    return ERROR;
}

//enum KeywordCode eTokenCode;
//enum Result eTest;
//int main()
//{
	//eTest=eStringToKeyword("resesdfasdt", &eTokenCode);	
//}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue)
{
    unsigned char ucCharCounter;
    if((pcStr[0]!='0') || (pcStr[1]!='x') || (pcStr[6]!=NULL) || (pcStr[2]==NULL))
    {
        return ERROR;
    }
    *puiValue = 0;
    for(ucCharCounter=2;pcStr[ucCharCounter]!=NULL;ucCharCounter++)
    {
        *puiValue=*puiValue << 4;
        if (pcStr[ucCharCounter] < 'A')
        {
            *puiValue=*puiValue | (pcStr[ucCharCounter]-'0');
        }
        else
        {
            *puiValue=*puiValue | (pcStr[ucCharCounter]-'A'+10);
        }
    }
    return OK;
}

void DecodeTokens(void)
{
    unsigned char ucTokenNumberCounter;
    char *cCurrentToken;
    enum KeywordCode peKeywordCode;
    unsigned int uiValue;
    TokenType eType;
    union TokenValue uValue;
    for(ucTokenNumberCounter=0; ucTokenNumberCounter<ucTokenNr; ucTokenNumberCounter++)
    {
        cCurrentToken=asToken[ucTokenNumberCounter].uValue.pcString;

        if(eStringToKeyword(cCurrentToken,&peKeywordCode)==OK)
        {
            eType=KEYWORD;
            uValue.eKeyword=peKeywordCode;
        }
        else if(eHexStringToUInt(cCurrentToken,&uiValue)==OK)
        {
            eType=NUMBER;
            uValue.uiNumber=uiValue;
        }
        else
        {
            eType=STRING;
            uValue.pcString=cCurrentToken;
        }
        asToken[ucTokenNumberCounter].eType=eType;
        asToken[ucTokenNumberCounter].uValue=uValue;
    }
}

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

//int main()
//{
	//char cString[]="0x1234 XYZ reset";
	//ucTokenNr=ucFindTokensInString(cString);
	//ReplaceCharactersInString(cString,' ',NULL);
	//DecodeTokens();
//}

void DecodeMsg(char *pcString)
{
    unsigned char ucTokenNumberCounter;
    ucTokenNr=ucFindTokensInString(pcString);
    ReplaceCharactersInString(pcString,' ',NULL);
    DecodeTokens();
}

int main()
{
	char cString[]="0x1234 XYZ reset";
	DecodeMsg(cString);
}
