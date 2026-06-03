#include <stdio.h>
#include "ni488.h"
#include "SR850_Agt.h"
#include <math.h>

static Addr4882_t SR850addr = 8;
static BOOL SR850AutoScale = TRUE;

int AGANSR850()
{
	char StrTemp[256] = "AGAN";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int APHSSR850()
{
	char StrTemp[256] = "APHS";
	GPIB_Command(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int ARSVSR850()
{
	char StrTemp[256] = "ARSV";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int ASCLSR850()
{
	char StrTemp[256] = "ASCL";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int CALCSR850()
{
	char StrTemp[256] = "CALC";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int CLSSR850()
{
	char StrTemp[256] = "*CLS";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int CMAXSR850()
{
	char StrTemp[256] = "CMAX";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int CNXTSR850()
{
	char StrTemp[256] = "CNXT";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int CPRVSR850()
{
	char StrTemp[256] = "CPRV";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int GetADSPSR850()
{
	char StrTemp[256] = "ADSP?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetALRMSR850()
{
	char StrTemp[256] = "ALRM?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetATRCSR850()
{
	char StrTemp[256] = "ATRC?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetAUXMSR850(int i_AUXM)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "AUXM? %i", i_AUXM);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetAUXVSR850(int i_AUXV)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "AUXV? %i", i_AUXV);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetCAGTSR850()
{
	char StrTemp[256] = "CAGT?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetCARGSR850()
{
	char StrTemp[256] = "CARG?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetCBINSR850()
{
	char StrTemp[256] = "CBIN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCDIVSR850()
{
	char StrTemp[256] = "CDIV?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCDSPSR850()
{
	char StrTemp[256] = "CDSP?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCLNKSR850()
{
	char StrTemp[256] = "CLNK?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCOPRSR850()
{
	char StrTemp[256] = "COPR?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCSEKSR850()
{
	char StrTemp[256] = "CSEK?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCTRCSR850()
{
	char StrTemp[256] = "CTRC?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetCURSSR850(int i_CURS, float* x_CURS, float* y_CURS)
{
	char StrTemp[256] = "";
	unsigned int comma_pos;
	sprintf_s(StrTemp, "CURS? %i", i_CURS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	*x_CURS = (float)atof(StrTemp);
	for (comma_pos = 0; comma_pos <= strlen(StrTemp); ++comma_pos)
		if (StrTemp[comma_pos] == ',') break;
	*y_CURS = (float)atof(&(StrTemp[comma_pos + 1]));
	return ThreadIbsta();
}

int GetCWIDSR850()
{
	char StrTemp[256] = "CWID?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetDDAYSR850()
{
	char StrTemp[256] = "DDAY?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetDHZSSR850(int i_DHZS)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "DHZS? %i", i_DHZS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetDMTHSR850()
{
	char StrTemp[256] = "DMTH?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetDOFFSR850(int i_DOFF)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "DOFF? %i", i_DOFF);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetDSCLSR850(int i_DSCL)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "DSCL? %i", i_DSCL);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetDTRCSR850(int i_DTRC)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "DTRC? %i", i_DTRC);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetDTYPSR850(int i_DTYP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "DTYP? %i", i_DTYP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetDYRSSR850()
{
	char StrTemp[256] = "DYRS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetERRESR850()
{
	char StrTemp[256] = "ERRE?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetERRESR850(int i_ERRE)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "ERRE? %i", i_ERRE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetERRSSR850()
{
	char StrTemp[256] = "ERRS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetERRSSR850(int i_ERRS)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "ERRS? %i", i_ERRS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetESESR850()
{
	char StrTemp[256] = "*ESE?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetESESR850(int i_ESE)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "*ESE? %i", i_ESE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetESRSR850()
{
	char StrTemp[256] = "*ESR?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetESRSR850(int i_ESR)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "*ESR? %i", i_ESR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetFASTSR850()
{
	char StrTemp[256] = "FAST?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetFMODSR850()
{
	char StrTemp[256] = "FMOD?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetFNAMSR850(char* s_FNAM)
{
	char StrTemp[256] = "FNAM?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	strcpy_s(s_FNAM, 256, StrTemp);
	return ThreadIbsta();
}

int GetFOUTSR850(int i_FOUT)
{
	char StrTemp[256] ="";
	sprintf_s(StrTemp, "FOUT? %i", i_FOUT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetFreqSR850()
{
	char StrTemp[256] = "FREQ?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetFTYPSR850()
{
	char StrTemp[256] = "FTYP?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetHARMSR850()
{
	char StrTemp[256] = "HARM?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetICPLSR850()
{
	char StrTemp[256] = "ICPL?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetIDNSR850(char* StrIDN)
{
	char StrTemp[256] = "*IDN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	strcpy_s(StrIDN, 256, StrTemp);
	return ThreadIbsta();
}

int GetIGANSR850()
{
	char StrTemp[256] = "IGAN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetIGNDSR850()
{
	char StrTemp[256] = "IGND?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetILINSR850()
{
	char StrTemp[256] = "ILIN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetISRCSR850()
{
	char StrTemp[256] = "ISRC?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetKCLKSR850()
{
	char StrTemp[256] = "KCLK?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetLIAESR850()
{
	char StrTemp[256] = "LIAE?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetLIAESR850(int i_LIAE)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "LIAE? %i", i_LIAE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetLIASSR850()
{
	char StrTemp[256] = "LIAS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetLIASSR850(int i_LIAS)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "LIAS %i", i_LIAS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetLOCLSR850()
{
	char StrTemp[256] = "LOCL?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetMACTSR850(int* arr_MACT)
{
	char StrTemp[256] = "MACT?";
	unsigned int comma_pos, old_comma_pos = 0;
	int Nmark;
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	Nmark = atoi(StrTemp);
	if (Nmark > 0)
	{
		for (int count = 1; count <= Nmark; ++count)
		{
			for (comma_pos = old_comma_pos; comma_pos <= strlen(StrTemp); ++comma_pos)
				if (StrTemp[comma_pos] == ',') break;
			arr_MACT[count-1] = atoi(&(StrTemp[comma_pos + 1]));
			old_comma_pos = comma_pos + 1;
		}
	}
	return Nmark;
}

int GetMBINSR850(int i_MBIN)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "MBIN? %i", i_MBIN);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetMNTRSR850()
{
	char StrTemp[256] = "MNTR?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetMTXTST850(int i_MTXT, char* s_MTXT)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "MTXT? %i", i_MTXT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	strcpy_s(s_MTXT, 255, StrTemp);
	return ThreadIbsta();
}

float GetOAUXSR850(int i_OAUX)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "OAUX? %i", i_OAUX);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetOEXPSR850(int i_OEXP, int* j_OEXP)
{
	char StrTemp[256] = "";
	unsigned int comma_pos;
	float x_OEXP;
	sprintf_s(StrTemp, "OEXP? %i", i_OEXP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	x_OEXP = (float)atof(StrTemp);
	for (comma_pos = 0; comma_pos <= strlen(StrTemp); ++comma_pos)
		if (StrTemp[comma_pos] == ',') break;
	*j_OEXP = atoi(&(StrTemp[comma_pos + 1]));
	return x_OEXP;
}

int GetOFLTSR850()
{
	char StrTemp[256] = "OFLT?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetOFSLSR850()
{
	char StrTemp[256] = "OFSL?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetOUTPSR850(int i_OUTP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "OUTP? %i", i_OUTP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetOUTRSR850(int i_OUTR)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "OUTR? %i", i_OUTR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetOUTXSR850()
{
	char StrTemp[256] = "OUTX?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetOVRMSR850()
{
	char StrTemp[256] = "OVRM?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetPARSSR850(int i_PARS)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "PARS? %i", i_PARS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetPhaseSR850()
{
	char StrTemp[256] = "PHAS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetPLTASR850()
{
	char StrTemp[256] = "PLTA?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPLTBSR850()
{
	char StrTemp[256] = "PLTB?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPLTSSR850()
{
	char StrTemp[256] = "PLTS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPNALSR850()
{
	char StrTemp[256] = "PNAL?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPNCRSR850()
{
	char StrTemp[256] = "PNCR?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPNGDSR850()
{
	char StrTemp[256] = "PNGD?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPNTRSR850()
{
	char StrTemp[256] = "PNTR?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPRNTSR850()
{
	char StrTemp[256] = "PRNT?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetPSCSR850()
{
	char StrTemp[256] = "*PSC?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetRBINSR850(int i_RBIN)
{
	char StrTemp[256] = "RBIN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetRMODSR850()
{
	char StrTemp[256] = "RMOD?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetRSLPSR850()
{
	char StrTemp[256] = "RSLP?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetRSRVSR850()
{
	char StrTemp[256] = "RSRV?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetSAUXSR850(int i_SAUX, float* y_SAUX, float* z_SAUX)
{
	char StrTemp[256] = "";
	char* Ptr = NULL;
	float x_SAUX;
	unsigned int count;
	sprintf_s(StrTemp, "SAUX? %i", i_SAUX);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	x_SAUX = (float)atof(StrTemp);
	for (count = 0; count <= strlen(StrTemp); ++count)
		if (StrTemp[count] == ',') break;
	Ptr = &(StrTemp[count + 1]);
	*y_SAUX = (float)atof(Ptr);
	for (count = 0; count <= strlen(Ptr); ++count)
		if (Ptr[count] == ',') break;
	Ptr = &(Ptr[count + 1]);
	*z_SAUX = (float)atof(Ptr);
	return x_SAUX;
}

int GetGPIB_SendCommandSR850()
{
	char StrTemp[256] = "GPIB_SendCommand?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSensSR850()
{
	char StrTemp[256] = "SENS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetSineOutSR850()
{
	char StrTemp[256] = "SLVL?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetSLENSR850()
{
	char StrTemp[256] = "SLEN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetSLLMSR850()
{
	char StrTemp[256] = "SLLM?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetSMODSR850()
{
	char StrTemp[256] = "SMOD?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSNAPSR850(int i_SNAP, int j_SNAP, float* resi_SNAP, float* resj_SNAP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SNAP? %i,%i", i_SNAP, j_SNAP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	sscanf_s(StrTemp, "%f,%f", resi_SNAP, resj_SNAP);
	return ThreadIbsta();
}

int GetSNAPSR850(int i_SNAP, int j_SNAP, int k_SNAP, float* resi_SNAP, float* resj_SNAP,
	float* resk_SNAP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SNAP? %i,%i,%i", i_SNAP, j_SNAP, k_SNAP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	sscanf_s(StrTemp, "%f,%f,%f", resi_SNAP, resj_SNAP, resk_SNAP);
	return ThreadIbsta();
}

int GetSNAPSR850(int i_SNAP, int j_SNAP, int k_SNAP, int l_SNAP, float* resi_SNAP,
	float* resj_SNAP, float* resk_SNAP, float* resl_SNAP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SNAP? %i,%i,%i,%i", i_SNAP, j_SNAP, k_SNAP, l_SNAP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	sscanf_s(StrTemp, "%f,%f,%f,%f", resi_SNAP, resj_SNAP, resk_SNAP, resl_SNAP);
	return ThreadIbsta();
}

int GetSNAPSR850(int i_SNAP, int j_SNAP, int k_SNAP, int l_SNAP, int m_SNAP, float* resi_SNAP,
	float* resj_SNAP, float* resk_SNAP, float* resl_SNAP, float* resm_SNAP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SNAP? %i,%i,%i,%i,%i", i_SNAP, j_SNAP, k_SNAP, l_SNAP, m_SNAP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	sscanf_s(StrTemp, "%f,%f,%f,%f,%f", resi_SNAP, resj_SNAP, resk_SNAP, resl_SNAP, resm_SNAP);
	return ThreadIbsta();
}

int GetSNAPSR850(int i_SNAP, int j_SNAP, int k_SNAP, int l_SNAP, int m_SNAP, int n_SNAP,
	float* resi_SNAP, float* resj_SNAP, float* resk_SNAP, float* resl_SNAP, float* resm_SNAP,
	float* resn_SNAP)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SNAP? %i,%i,%i,%i,%i,%i", i_SNAP, j_SNAP, k_SNAP, l_SNAP, m_SNAP,
		                                          n_SNAP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	sscanf_s(StrTemp, "%f,%f,%f,%f,%f,%f", resi_SNAP, resj_SNAP, resk_SNAP, resl_SNAP, resm_SNAP,
		                                resn_SNAP);
	return ThreadIbsta();
}

float GetSPARSR850(int i_SPAR)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SPAR? %i", i_SPAR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetSPTSSR850(int i_SPTS)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "SPTS? %i", i_SPTS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSRATSR850()
{
	char StrTemp[256] = "SRAT?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSRESR850()
{
	char StrTemp[256] = "*SRE?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSRESR850(int i_SRE)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "*SRE? %i", i_SRE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSTBSR850()
{
	char StrTemp[256] = "*STB?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSTBSR850(int i_STB)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "*STB? %i", i_STB);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetSULMSR850()
{
	char StrTemp[256] = "SULM?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int GetSWPTSR850()
{
	char StrTemp[256] = "SWPT?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetSYNCSR850()
{
	char StrTemp[256] = "SYNC?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetTHRSSR850()
{
	char StrTemp[256] = "THRS?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetTMINSR850()
{
	char StrTemp[256] = "TMIN?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetTRCASR850(int i_TRCA, int j_TRCA, int k_TRCA, float* res_TRCA)
{
	char StrTemp[256] = "";
	char* BufTemp = (char*)malloc(k_TRCA*16);
	unsigned int count1 = 0;
	char* Ptr;
	if (BufTemp == NULL) return 0;
	sprintf_s(StrTemp, "TRCA? %i,%i,%i", i_TRCA, j_TRCA, k_TRCA);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	BufTemp[ThreadIbcntl()] = 0;
	res_TRCA[0] = (float)atof(BufTemp);
	for (int count = 1; count < k_TRCA; ++count)
	{
		for (; count1 <= strlen(BufTemp); ++count1)
			if (BufTemp[count1] == ',') break;
		Ptr = &(BufTemp[count1+1]);
		res_TRCA[count] = (float)atof(Ptr);
	}
	free(BufTemp);
	return ThreadIbsta();
}

int GetTRCBSR850(int i_TRCB, int j_TRCB, int k_TRCB, float* res_TRCB)
{
	char StrTemp[256] = "";
	char* BufTemp = (char*)malloc(k_TRCB * 4);
	unsigned int count1 = 0;
	float* Ptr;
	if (BufTemp == NULL) return 0;
	sprintf_s(StrTemp, "TRCB? %i,%i,%i", i_TRCB, j_TRCB, k_TRCB);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	BufTemp[ThreadIbcntl()] = 0;
	for (int count = 0; count < k_TRCB; ++count)
	{
		Ptr = (float*) & (BufTemp[count * 4]);
		res_TRCB[count] = *Ptr;
	}
	free(BufTemp);
	return ThreadIbsta();
}

int GetTRCDSR850(int i_TRCD, int* k_TRCD, int* l_TRCD, int* m_TRCD)
{
	char StrTemp[256]="";
	char* Ptr;
	int j_TRCD;
	unsigned int count;
	sprintf_s(StrTemp, "TRCD? %i", i_TRCD);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	j_TRCD = atoi(StrTemp);
	for (count = 0; count <= strlen(StrTemp); ++count)
		if (StrTemp[count] == ',') break;
	Ptr = &(StrTemp[count + 1]);
	*k_TRCD = atoi(Ptr);
	for (count = 0; count <= strlen(Ptr); ++count)
		if (Ptr[count] == ',') break;
	Ptr = &(Ptr[count + 1]);
	*l_TRCD = atoi(Ptr);
	for (count = 0; count <= strlen(Ptr); ++count)
		if (Ptr[count] == ',') break;
	Ptr = &(Ptr[count + 1]);
	*m_TRCD = atoi(Ptr);
	return j_TRCD;
}

int GetTRCLSR850(int i_TRCL, int j_TRCL, int k_TRCL, float* res_TRCL)
{
	char StrTemp[256] = "";
	char* BufTemp = (char*)malloc(k_TRCL * 4);
	unsigned int count1 = 0;
	char* Ptr;
	float fltTemp = 0;
	if (BufTemp == NULL) return 0;
	sprintf_s(StrTemp, "TRCL? %i,%i,%i", i_TRCL, j_TRCL, k_TRCL);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	BufTemp[ThreadIbcntl()] = 0;
	for (int count = 0; count < k_TRCL; ++count)
	{
		Ptr = &(BufTemp[count * 4]);
		fltTemp = ((float)Ptr[1]*256.0f+(float)Ptr[0])*(float)pow(2, ((float)Ptr[2] - 124.0f));
		res_TRCL[count] = fltTemp;
	}
	free(BufTemp);
	return ThreadIbsta();
}

int GetTSECSR850()
{
	char StrTemp[256] = "TSEC?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

int GetTSTRSR850()
{
	char StrTemp[256] = "TSTR?";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return atoi(StrTemp);
}

float GetXSR850()
{
	char StrTemp[256] = "OUTP? 1";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

float GetYSR850()
{
	char StrTemp[256] = "OUTP? 2";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	GPIB_Read(SR850addr, StrTemp, 256);
	StrTemp[ThreadIbcntl()] = 0;
	return (float)atof(StrTemp);
}

int FITTSR850(int i_FITT, int j_FITT)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "FITT %i, %i", i_FITT, j_FITT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int MARKSR850()
{
	char StrTemp[256] = "MARK";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}
int MDELSR850()
{
	char StrTemp[256] = "MDEL";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int PALLSR850()
{
	char StrTemp[256] = "PALL";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int PAUSSR850()
{
	char StrTemp[256] = "PAUS";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int PRSCSR850()
{
	char StrTemp[256] = "PRSC";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int PTRCSR850()
{
	char StrTemp[256] = "PTRC";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int PCURSR850()
{
	char StrTemp[256] = "PCUR";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int RDATSR850()
{
	char StrTemp[256] = "RDAT";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int RESTSR850()
{
	char StrTemp[256] = "REST";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int RSETSR850()
{
	char StrTemp[256] = "RSET";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int RSTSR850()
{
	char StrTemp[256] = "*RST";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SASCSR850()
{
	char StrTemp[256] = "SASC";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SDATSR850()
{
	char StrTemp[256] = "SDAT";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SSETSR850()
{
	char StrTemp[256] = "SSET";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int STATSR850(int i_STAT, int j_STAT)
{
	char StrTemp[256] = "";
	sprintf_s(StrTemp, "STAT %i, %i", i_STAT, j_STAT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int STRDSR850()
{
	char StrTemp[256] = "STRD";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int STRTSR850()
{
	char StrTemp[256] = "STRT";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetAOFFSR850(int i_AOFF)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "AOFF %i", i_AOFF);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetADSPSR850(int i_ADSP)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ADSP %i", i_ADSP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetALRMSR850(int i_ALRM)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ALRM %i", i_ALRM);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetATRCSR850(int i_ATRC)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ATRC %i", i_ATRC);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetAUXMSR850(int i_AUXM, int j_AUXM)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "AUXM %i, %i", i_AUXM, j_AUXM);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetAUXVSR850(int i_AUXV, float x_AUXV)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "AUXV %i, %f", i_AUXV, x_AUXV);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCAGTSR850(int i_CAGT)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CAGT %i", i_CAGT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCARGSR850(float x_CARG)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CARG %f", x_CARG);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCBINSR850(int i_CBIN)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CBIN %i", i_CBIN);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCDIVSR850(int i_CDIV)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CDIV %i", i_CDIV);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCDSPSR850(int i_CDSP)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CDSP %i", i_CDSP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCLNKSR850(int i_CLNK)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CLNK %i", i_CLNK);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCOPRSR850(int i_COPR)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "COPR %i", i_COPR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCSEKSR850(int i_CSEK)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CSEK %i", i_CSEK);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCTRCSR850(int i_CTRC)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CTRC %i", i_CTRC);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetCWIDSR850(int i_CWID)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "CWID %i", i_CWID);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDDAYSR850(int i_DDAY)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DDAY %i", i_DDAY);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDHZSSR850(int i_DHZS, int j_DHZS)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DHZS %i, %i", i_DHZS, j_DHZS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDMTHSR850(int i_DMTH)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DMTH %i", i_DMTH);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDOFFSR850(int i_DOFF, float x_DOFF)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DOFF %i, %f", i_DOFF, x_DOFF);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDSCLSR850(int i_DSCL, float x_DSCL)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DSCL %i, %f", i_DSCL, x_DSCL);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDTRCSR850(int i_DTRC, int j_DTRC)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DTRC %i, %i", i_DTRC, j_DTRC);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDTYPSR850(int i_DTYP, int j_DTYP)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DTYP %i, %i", i_DTYP, j_DTYP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetDYRSSR850(int i_DYRS)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "DYRS %i", i_DYRS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetERRESR850(int i_ERRE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ERRE %i", i_ERRE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetERRESR850(int i_ERRE, int j_ERRE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ERRE %i, %i", i_ERRE, j_ERRE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetESESR850(int i_ESE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "*ESE %i", i_ESE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetESESR850(int i_ESE, int j_ESE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "*ESE %i, %i", i_ESE, j_ESE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetFASTSR850(int i_FAST)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "FAST %i", i_FAST);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetFMODSR850(int Mode)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "FMOD %i", Mode);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetFNAMSR850(char* s_FNAM)
{
	char StrTemp[256] = "FNAM ";
	strcat_s(StrTemp, s_FNAM);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetFOUTSR850(int i_FOUT, int j_FOUT)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "FOUT %i, %i", i_FOUT, j_FOUT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetFreqSR850(float Freq)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "FREQ %f", Freq);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetFTYPSR850(int i_FTYP)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "FTYP %i", i_FTYP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetHARMSR850(int Harm)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "HARM %i", Harm);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetICPLSR850(int ICPL)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ICPL %i", ICPL);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetIGANSR850(int Gain)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "IGAN %i", Gain);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetIGNDSR850(int Gnd)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "IGND %i", Gnd);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetILINSR850(int Line)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ILIN %i", Line);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetISRCSR850(int Src)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "ISCR %i", Src);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetKCLKSR850(int i_KCLK)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "KCLK %i", i_KCLK);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetLIAESR850(int i_LIAE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "LIAE %i", i_LIAE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetLIAESR850(int i_LIAE, int j_LIAE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "LIAE %i, %i", i_LIAE, j_LIAE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetLOCLSR850(int i_LOCL)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "LOCL %i", i_LOCL);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetMNTRSR850(int i_MNTR)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "MNTR %i", i_MNTR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetMTXTSR850(int i_MTXT, char* s_MTXT)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "MTXT %i, %s", i_MTXT, s_MTXT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetOEXPSR850(int i_OEXP, int x_OEXP, int j_OEXP)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "OEXP %i, %i, %i", i_OEXP, x_OEXP, j_OEXP);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetOFLTSR850(int OFlt)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "OFLT %i", OFlt);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetOFSLSR850(int OFsl)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "OFSL %i", OFsl);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetOUTXSR850(int i_OUTX)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "OUTX %i", i_OUTX);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetOVRMSR850(int i_OVRM)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "OVRM %i", i_OVRM);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPhaseSR850(float Phase)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PHAS %f", Phase);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPLTASR850(int i_PLTA)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PLTA %i", i_PLTA);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPLTBSR850(int i_PLTB)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PLTB %i", i_PLTB);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPLTSSR850(int i_PLTS)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PLTS %i", i_PLTS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPNALSR850(int i_PNAL)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PNAL %i", i_PNAL);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPNCRSR850(int i_PNCR)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PNCR %i", i_PNCR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPNGDSR850(int i_PNGD)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PNGD %i", i_PNGD);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPNTRSR850(int i_PNTR)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PNTR %i", i_PNTR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPRTNSR850(int i_PRTN)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "PRTN %i", i_PRTN);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetPSCSR850(int i_PSC)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "*PSC %i", i_PSC);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetRMODSR850(int RMod)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "RMOD %i", RMod);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetRSLPSR850(int RefSlope)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "RSLP %i", RefSlope);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetRSRVSR850(int Rsrv)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "RSRV %i", Rsrv);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSAUXSR850(int i_SAUX, float x_SAUX, float y_SAUX, float z_SAUX)
{
	char StrTemp[256]="";
	sprintf_s(StrTemp, "TRCD %i, %f, %f, %f", i_SAUX, x_SAUX, y_SAUX, z_SAUX);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetGPIB_SendCommandSR850(int i_GPIB_SendCommand)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "GPIB_SendCommand %i", i_GPIB_SendCommand);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSensSR850(int Sens)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SENS %i", Sens);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSineOutSR850(float Vrms)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SLVL %f", Vrms);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSLENSR850(float x_SLEN)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SLEN %f", x_SLEN);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSLLMSR850(float Freq)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SLLM %f", Freq);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSMODSR850(int i_SMOD)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SMOD %i", i_SMOD);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSRATSR850(int i_SRAT)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SRAT %i", i_SRAT);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSRESR850(int i_SRE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "*SRE %i", i_SRE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSRESR850(int i_SRE, int j_SRE)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "*SRE %i, %i", i_SRE, j_SRE);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSULMSR850(float Freq)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SULM %f", Freq);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSWPTSR850(int Sweep)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SWPT %i", Sweep);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetSYNCSR850(int Sync)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SYNC %i", Sync);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetTHRSSR850(int i_THRS)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "THRS %i", i_THRS);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetTMINSR850(int i_TMIN)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "TMIN %i", i_TMIN);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetTRCDSR850(int i_TRCD, int j_TRCD, int k_TRCD, int l_TRCD, int m_TRCD)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "TRCD %i, %i, %i, %i, %i", i_TRCD, j_TRCD, k_TRCD, l_TRCD, m_TRCD);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetTSECSR850(int i_TSEC)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "TSEC %i", i_TSEC);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SetTSTRSR850(int i_TSTR)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "TSTR %i", i_TSTR);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int SMTHSR850(int i_SMTH)
{
	char StrTemp[256];
	sprintf_s(StrTemp, "SMTH %i", i_SMTH);
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

int TRIGSR850()
{
	char StrTemp[] = "TRIG";
	GPIB_SendCommand(SR850addr, StrTemp, strlen(StrTemp));
	return ThreadIbsta();
}

BOOL FindSR850()
{
	Addr4882_t AddrList[2] = { SR850addr, NOADDR };
	short ResultList[2];
	char buf[] = "*IDN?";
	char responce[256];
	FindLstn(AddrList, ResultList, 1);
	if (!(ThreadIbsta() & ERR))
	{
		EnableRemote(AddrList);
		GPIB_SendCommand(SR850addr, buf, strlen(buf));
		GPIB_Read(SR850addr, responce, 256);
		responce[31] = 0;
		if (strcmp(responce, "Stanford_Research_Systems,SR850") == 0) return TRUE;
		else return FALSE;
	}
	else return FALSE;
}

void OpenSR850()
{
	Addr4882_t AddrList[2] = { SR850addr, NOADDR };
	EnableRemote(AddrList);
}

void CloseSR850()
{
	Addr4882_t AddrList[2] = { SR850addr, NOADDR };
	EnableLocal(AddrList);
}