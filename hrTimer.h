
#ifndef _HRTIMER
#define _HRTIMER

#include <windows.h>

class timer
{
private:	

	LARGE_INTEGER strt, frequency;

public:

	//constructor
	timer()
	{
		QueryPerformanceFrequency( &frequency );
		reset();
	}

	//reset timer
	void reset() { QueryPerformanceCounter( &strt ); }
	void start() { reset(); }

	//return elapsed times
	double getElapsedTimeSeconds()
	{	
		LARGE_INTEGER stp, timeElapsed;
		
		QueryPerformanceCounter( &stp );	
		timeElapsed.QuadPart = stp.QuadPart - strt.QuadPart;			
		return (double) timeElapsed.QuadPart / frequency.QuadPart ;		
	}

	double getElapsedTimeMilliseconds()
	{	
		LARGE_INTEGER stp, timeElapsed;
		
		QueryPerformanceCounter( &stp );	
		timeElapsed.QuadPart = stp.QuadPart - strt.QuadPart;			
		return (double) timeElapsed.QuadPart / frequency.QuadPart * 1000 ;		
	}
};	

#endif
