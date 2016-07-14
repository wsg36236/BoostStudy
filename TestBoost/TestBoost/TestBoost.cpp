// TestBoost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestThread.h"
#include "TestBoostOption.h"
#include <boost/algorithm/string.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	//std::string	strTemp = "string" + 11;
	//printf("%s\n", strTemp.c_str());

	//CTestThread::Test();
	//printf("CTestThread::Test call end\n");

	CTestBoostOption::Test(argc, argv);

	//std::string str(" .jd t		");
	//boost::trim(str);
	//printf("%s>>>>\n", str.c_str());

	system("pause");
	return 0;
}

