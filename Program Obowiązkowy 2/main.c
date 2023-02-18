#include <LPC21xx.H>

#define NULL 0

#define Tetrad_Mask 0x000F

enum Result {OK,ERROR};

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


//unsigned int uiValue=1500;
//char pcStr[10]="";
//UIntToHexStr (uiValue,pcStr);

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

//unsigned int puiValue;
//char pcStr[15]="0x05DC";
//eHexStringToUInt(pcStr,&puiValue);

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[])
{
    unsigned char ucCharacterCounter;
    for(ucCharacterCounter=0; pcDestinationStr[ucCharacterCounter]!=NULL; ucCharacterCounter++){}
    UIntToHexStr(uiValue, &pcDestinationStr[ucCharacterCounter]);
}

//unsigned int uiValue=145;
//char pcDestinationStr[254]="0xABCD";
//AppendUIntToString(uiValue, pcDestinationStr);

int main()
{
	unsigned int uiValue=0xAF09;
	char pcStr[10]="";
	UIntToHexStr (uiValue,pcStr);

}
