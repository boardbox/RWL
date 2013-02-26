#ifndef WINMGR_H
#define WINMGR_H

class WinMgr{
	const char *appName;
	int xWinSize;
	int yWinSize;

	public:
	WinMgr(const char *appName, int xWinSize, int yWinSize);
	int openWindow();
	~WinMgr(void);
};

#endif
