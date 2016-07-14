#include "StdAfx.h"
#include "TestBoostOption.h"
#include "getopt.h"
#include <string>

static struct option long_options[] =
{
	{_T("check-heapspray"),      ARG_NONE, 0, 0},
	{_T("open-with-extension-name"),	 ARG_OPT, 0, 'e'},
	{0, 0, 0, 0}
};


CTestBoostOption::CTestBoostOption(void)
{
}


CTestBoostOption::~CTestBoostOption(void)
{
}


bool	CTestBoostOption::Test(int argc, _TCHAR* argv[])
{
	CTestBoostOption	oCTestBoostOption;

	return	oCTestBoostOption.TestQuotation(argc, argv);
}

bool	CTestBoostOption::TestQuotation(int argc, _TCHAR* argv[])
{
	int opt;
	int option_index = 0;
	static const TCHAR *optString = _T("t:o:a:x:o:e::cspfmhvd");

	while( (opt = getopt_long( argc, argv, optString, long_options, &option_index)) != -1 ) {
		switch( opt ) {
		case 0:
			if (_tcscmp(_T("check-heapspray"), long_options[option_index].name) == 0) 
			{
				_tprintf(_T("%s \n"), long_options[option_index].name);
			}
			break;
		case 'e':
			{
				_tprintf(_T("open-with-extension-name, extension name list : %s\n"), optarg);
				//std::string	str = optarg;
			}
			break;
		default:
			/* You won't actually get here. */
			break;
		}
	}

	return	true;
}