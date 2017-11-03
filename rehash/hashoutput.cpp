/*
 Copyright (c) 2003, Dominik Reichl <dominik.reichl@t-online.de>
 All rights reserved.

 LICENSE TERMS

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
 * Neither the name of ReichlSoft nor the names of its contributors may be used
   to endorse or promote products derived from this software without specific
   prior written permission.

 DISCLAIMER

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "hashoutput.h"
#include "clutil.h"
#include "hashmgr.h"
#include "../src_algo/base64.h"

CHashOutput::CHashOutput()
{
	m_nMaxHashName = 0;

	m_nOutputStyle = HASHOUTPUT_TEXT;
	m_nCombineWords = 4;
	m_bPadToFullWord = false;
	m_bBase64 = false;

	rhstrcpy(m_szCharCode, "%02X", RH_MAX_CHAR_CODE);
}

CHashOutput::~CHashOutput()
{
	m_nOutputStyle = HASHOUTPUT_NONE;
}

void CHashOutput::SetOutputStyleA(const char *pszSchemeName)
{
	RH_ASSERT(pszSchemeName != NULL);

	if(stricmp(pszSchemeName, "none") == 0) SetOutputStyleN(HASHOUTPUT_NONE);
	if(stricmp(pszSchemeName, "raw" ) == 0) SetOutputStyleN(HASHOUTPUT_TEXT);
	if(stricmp(pszSchemeName, "text") == 0) SetOutputStyleN(HASHOUTPUT_TEXT);
	if(stricmp(pszSchemeName, "html") == 0) SetOutputStyleN(HASHOUTPUT_HTML);
	if(stricmp(pszSchemeName, "xml" ) == 0) SetOutputStyleN(HASHOUTPUT_XML);
	if(stricmp(pszSchemeName, "csv" ) == 0) SetOutputStyleN(HASHOUTPUT_CSV);

	if(stricmp(pszSchemeName, "pad:true" ) == 0) m_bPadToFullWord = true;
	if(stricmp(pszSchemeName, "pad:false") == 0) m_bPadToFullWord = false;

	if(stricmp(pszSchemeName, "word:8"   ) == 0) m_nCombineWords =     1;
	if(stricmp(pszSchemeName, "word:16"  ) == 0) m_nCombineWords =     2;
	if(stricmp(pszSchemeName, "word:32"  ) == 0) m_nCombineWords =     4;
	if(stricmp(pszSchemeName, "word:64"  ) == 0) m_nCombineWords =     8;
	if(stricmp(pszSchemeName, "word:128" ) == 0) m_nCombineWords =    16;
	if(stricmp(pszSchemeName, "word:256" ) == 0) m_nCombineWords =    32;
	if(stricmp(pszSchemeName, "word:512" ) == 0) m_nCombineWords =    64;
	if(stricmp(pszSchemeName, "word:1024") == 0) m_nCombineWords =   128;
	if(stricmp(pszSchemeName, "word:2048") == 0) m_nCombineWords =   256;
	if(stricmp(pszSchemeName, "word:inf" ) == 0) m_nCombineWords = 32766;

	if(stricmp(pszSchemeName, "nospaces") == 0) m_nCombineWords = 32766;

	if(stricmp(pszSchemeName, "lowhex") == 0)
		rhstrcpy(m_szCharCode, "%02x", RH_MAX_CHAR_CODE);
	if(stricmp(pszSchemeName, "uphex") == 0)
		rhstrcpy(m_szCharCode, "%02X", RH_MAX_CHAR_CODE);

	if(stricmp(pszSchemeName, "decimal") == 0)
		rhstrcpy(m_szCharCode, "%u", RH_MAX_CHAR_CODE);

	if(stricmp(pszSchemeName, "base64") == 0) m_bBase64 = true;
	if(stricmp(pszSchemeName, "nobase64") == 0) m_bBase64 = false;
}

void CHashOutput::SetOutputStyleN(int nStyle)
{
	RH_ASSERT((nStyle > 0) && (nStyle < HASHOUTPUT_LAST));

	m_nOutputStyle = nStyle;
}

void CHashOutput::InitOutput(void *pManager)
{
	unsigned long i = 0;
	CHashManager *pMgr = (CHashManager *)pManager;

	RH_ASSERT(pMgr != NULL);

	m_nMaxHashName = 0;
	while(1)
	{
		if(pMgr->m_pAlgorithms[i] == NULL) break;
		m_nMaxHashName = max(m_nMaxHashName, strlen(pMgr->m_pAlgorithms[i]->GetName()));
		i++;
	}

	switch (m_nOutputStyle)
	{
	case HASHOUTPUT_TEXT:
		break;

	case HASHOUTPUT_HTML:
		printf("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">");
		rhNewLine();
		printf("<html><head><title>Hashes</title>"); rhNewLine();

		printf("<style type=\"text/css\"><!--"); rhNewLine();

		printf(".hashtable {"); rhNewLine();
		printf("border : 0px;"); rhNewLine();
		printf("width : 100%%;"); rhNewLine();
		printf("color : #FFFFFF;"); rhNewLine();
		printf("background-color : #000000;"); rhNewLine();
		printf("font-size : 12px;"); rhNewLine();
		printf("}"); rhNewLine();

		printf(".hashofcell {"); rhNewLine();
		printf("font-family: Verdana, Helvetica, Arial, sans-serif;"); rhNewLine();
		printf("font-size : 12px;"); rhNewLine();
		printf("vertical-align : middle;"); rhNewLine();
		printf("color : #000000;"); rhNewLine();
		printf("background-color : #DDDDDD;"); rhNewLine();
		printf("width : 112px;"); rhNewLine();
		printf("}"); rhNewLine();

		printf(".filecell {"); rhNewLine();
		printf("font-family: Verdana, Helvetica, Arial, sans-serif;"); rhNewLine();
		printf("font-size : 12px;"); rhNewLine();
		printf("vertical-align : middle;"); rhNewLine();
		printf("color : #000000;"); rhNewLine();
		printf("background-color : #DDDDDD;"); rhNewLine();
		printf("}"); rhNewLine();

		printf(".hashentrycell {"); rhNewLine();
		printf("font-family: Verdana, Helvetica, Arial, sans-serif;"); rhNewLine();
		printf("font-size : 12px;"); rhNewLine();
		printf("vertical-align : middle;"); rhNewLine();
		printf("color : #000000;"); rhNewLine();
		printf("background-color : #FFFFFF;"); rhNewLine();
		printf("width : 112px;"); rhNewLine();
		printf("}"); rhNewLine();

		printf(".hashcell {"); rhNewLine();
		printf("font-family : \"Courier New\", Courier, monospace;"); rhNewLine();
		printf("font-size : 11px;"); rhNewLine();
		printf("vertical-align : middle;"); rhNewLine();
		printf("color : #000000;"); rhNewLine();
		printf("background-color : #FFFFFF;"); rhNewLine();
		printf("}"); rhNewLine();

		printf("--></style>");

		printf("</head><body>");
		rhNewLine();
		break;

	case HASHOUTPUT_XML:
		printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"); rhNewLine();
		printf("<rehash version=\"");
		printf(RH_VERSION_STR);
		printf("\">"); rhNewLine();
		break;

	case HASHOUTPUT_CSV:
		printf("\"File\",\"HMAC\",\"HMAC Key\"");
		i = 0;
		while(1)
		{
			if(pMgr->m_pAlgorithms[i] == NULL) break;
			if(pMgr->m_bUseAlgorithm[i] == true)
			{
				printf(",\"");
				printf(pMgr->m_pAlgorithms[i]->GetName());
				printf("\"");
			}
			i++;
		}
		rhNewLine();
		break;

	case HASHOUTPUT_NONE:
		break;
	default:
		RH_ASSERT(false); // The default routine should never get called
		break;
	}
}

void CHashOutput::CloseOutput()
{
	switch (m_nOutputStyle)
	{
	case HASHOUTPUT_TEXT:
		break;

	case HASHOUTPUT_HTML:
		printf("</body></html>"); rhNewLine();
		break;

	case HASHOUTPUT_XML:
		printf("</rehash>"); rhNewLine();
		break;

	case HASHOUTPUT_CSV:
		break;

	case HASHOUTPUT_NONE:
		break;
	default:
		RH_ASSERT(false); // The default routine should never get called
		break;
	}
}

void CHashOutput::NewDataSource(const char *pFileDesc, bool bHMAC, char *pHMACKey)
{
	switch (m_nOutputStyle)
	{
	case HASHOUTPUT_TEXT:
		printf(pFileDesc);
		rhNewLine();

		if(bHMAC == true)
		{
			RH_ASSERT(pHMACKey != NULL);

			printf("HMAC hashes using key: ");
			printf(pHMACKey);
			rhNewLine();
		}
		break;

	case HASHOUTPUT_HTML:
		printf("<table class=\"hashtable\" cellspacing=\"1px\"><tr>");
		printf("<td class=\"hashofcell\">File</td><td class=\"filecell\">");
		printf(pFileDesc);
		printf("</td></tr>");

		if(bHMAC == true)
		{
			printf("<tr><td class=\"hashofcell\">HMAC key</td><td class=\"filecell\">");
			printf(pHMACKey);
			printf("</td></tr>");
			rhNewLine();
		}

		break;

	case HASHOUTPUT_XML:
		printf("<file>"); rhNewLine(); printf("<name>");
		printf(pFileDesc); printf("</name>"); rhNewLine();

		if(bHMAC == true)
		{
			printf("<hmac>1</hmac>"); rhNewLine();
			printf("<hkey>"); printf(pHMACKey); printf("</hkey>"); rhNewLine();
		}
		else
		{
			printf("<hmac>0</hmac>"); rhNewLine();
		}

		break;

	case HASHOUTPUT_CSV:
		printf("\"");
		printf(pFileDesc);
		printf("\",\"");
		if(bHMAC == true)
		{
			printf("1\",\"");
			printf(pHMACKey);
			printf("\"");
		}
		else
		{
			printf("0\",\"\"");
		}
		break;

	case HASHOUTPUT_NONE:
		break;
	default:
		RH_ASSERT(false); // The default routine should never get called
		break;
	}
}

void CHashOutput::CloseDataSource()
{
	switch (m_nOutputStyle)
	{
	case HASHOUTPUT_TEXT:
		rhNewLine();
		break;

	case HASHOUTPUT_HTML:
		printf("</table><br>"); rhNewLine(); rhNewLine();
		break;

	case HASHOUTPUT_XML:
		printf("</file>"); rhNewLine(); rhNewLine();
		break;

	case HASHOUTPUT_CSV:
		rhNewLine();
		break;

	case HASHOUTPUT_NONE:
		break;
	default:
		RH_ASSERT(false); // The default routine should never get called
		break;
	}
}

void CHashOutput::Output(const char *pHashName, unsigned char *pHash, unsigned long uLen)
{
	unsigned int i;

	RH_ASSERT(pHashName != NULL);
	RH_ASSERT(pHash != NULL);

	if(uLen == 0) return;

	switch (m_nOutputStyle)
	{
	case HASHOUTPUT_TEXT:
		printf(pHashName);
		i = m_nMaxHashName - strlen(pHashName);
		while(i != 0) { printf(" "); i--; }
		printf(" : ");

		_OutputHashBytes(pHash, uLen);

		rhNewLine();
		break;

	case HASHOUTPUT_HTML:
		printf("<tr><td class=\"hashentrycell\">");
		printf(pHashName);
		printf("</td>"); rhNewLine();
		printf("<td class=\"hashcell\">");

		_OutputHashBytes(pHash, uLen);

		printf("</td></tr>"); rhNewLine();

		break;

	case HASHOUTPUT_XML:
		printf("<hash type=\"");
		printf(pHashName);
		printf("\">");

		_OutputHashBytes(pHash, uLen);

		printf("</hash>"); rhNewLine();
		break;

	case HASHOUTPUT_CSV:
		printf(",\"");
		_OutputHashBytes(pHash, uLen);
		printf("\"");
		break;

	case HASHOUTPUT_NONE:
		break;
	default:
		RH_ASSERT(false); // The default routine should never get called
		break;
	}
}

void CHashOutput::_OutputHashBytes(unsigned char *pHash, unsigned long uLen)
{
	unsigned long i;
	int j = 0;

	RH_ASSERT(pHash != NULL);
	RH_ASSERT(uLen >= 1);

	if(m_bBase64 == true)
	{
		CBase64Codec baseCoder;
	
		m_szHashBuffer[0] = 0;

		i = RH_MAX_HASH_STRING;
		baseCoder.Encode(pHash, uLen, (unsigned char *)m_szHashBuffer, &i);

		printf(m_szHashBuffer);

		return;
	}

	for(i = 0; i < uLen; i++)
	{
		printf(m_szCharCode, pHash[i]);

		j++;
		if(j == m_nCombineWords)
		{
			j = 0;

			if(i != (uLen - 1)) printf(" ");
		}
	}

	if((m_bPadToFullWord == true) && (j != 0))
	{
		while(1)
		{
			printf("00");
			j++;
			if(j == m_nCombineWords) break;
		}
	}
}
