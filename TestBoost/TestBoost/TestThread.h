#pragma once

#include <boost/thread/thread.hpp>

class CTestThread
{
public:
	CTestThread(void);
	~CTestThread(void);

	static	void	ThreadProc();
	static	bool	Test();
};

