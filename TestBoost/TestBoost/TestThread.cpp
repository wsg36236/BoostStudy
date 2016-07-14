#include "StdAfx.h"
#include "TestThread.h"


CTestThread::CTestThread(void)
{
}


CTestThread::~CTestThread(void)
{
}


void	CTestThread::ThreadProc()
{
	printf("Call %s \n", __FUNCTION__);
}

bool	CTestThread::Test()
{
	boost::thread* pThread = new boost::thread(&ThreadProc);  

	if (pThread)
	{
		//pThread->join();
		delete	pThread;

		return	true;
	}

	return	false;
}