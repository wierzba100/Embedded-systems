#include <stdio.h>

#include "program_obowiazkowy_funkcje.h"

#define NULL 0
#define Tetrad_Mask 0x000F


unsigned char ucTokenNr;

void CopyString(char pcSource[], char pcDestination[])
{
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0;pcSource[ucCharacterCounter]!=NULL;ucCharacterCounter++)
	{
		pcDestination[ucCharacterCounter]=pcSource[ucCharacterCounter];
	}
	pcDestination[ucCharacterCounter]=NULL;
}

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

void AppendString (char pcSourceStr[],char pcDestinationStr[])
{
    unsigned char ucNullLocation;
    for(ucNullLocation=0; pcDestinationStr[ucNullLocation]!=NULL; ucNullLocation++) {}
    CopyString(pcSourceStr, pcDestinationStr+ucNullLocation);
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

void UIntToHexStr(unsigned int uiValue, char pcStr[])
{
	unsigned char ucTetradCounter;
	unsigned int uiAuxiliaryVariable=uiValue;
	pcStr[0]='0';
	pcStr[1]='x';
	for(ucTetradCounter=0;ucTetradCounter<4;ucTetradCounter++)
	{
		if((uiAuxiliaryVariable & Tetrad_Mask)<10)
		{
			pcStr[5-ucTetradCounter]=(uiAuxiliaryVariable & Tetrad_Mask)+'0';
		}
		else
		{
			pcStr[5-ucTetradCounter]=(uiAuxiliaryVariable & Tetrad_Mask)-10+'A';
		}
		uiAuxiliaryVariable=uiAuxiliaryVariable>>4;
	}
	pcStr[6]=NULL;
}


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

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[])
{
    unsigned char ucCharacterCounter;
    for(ucCharacterCounter=0; pcDestinationStr[ucCharacterCounter]!=NULL; ucCharacterCounter++){}
    UIntToHexStr(uiValue, &pcDestinationStr[ucCharacterCounter]);
}


