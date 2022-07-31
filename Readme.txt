
BUILD DLL (32-bit):
	i686-w64-mingw32-gcc -shared -o GRAM.dll  GRAM-init-run.cpp  C:\Users\vic-b\Documents\Victors\Job\Astos\project\EarthGRAM2016Version2\EarthGRAM2016Version2.0\Source\*.cpp  -lstdc++
BUILD ADA (32-bit):
	gprbuild -P dll_test.gpr


BUILD C++ standalone: 
( add --static flag if executer still expects DLL-files, compiler confusion is real) 
g++ -o test.exe GRAM-init-run.cpp C:\Users\vic-b\Documents\Victors\Job\Astos\project\EarthGRAM2016Version2\EarthGRAM2016Version2.0\Source\*.cpp


Remarks:

local paths in 
		GRAM-init-run.cpp (import of \EarthGRAM2016Version2)
		dll_test.adp (line 240-243)


Time in GRAM's Traj call seems to refer to (elapsed) seconds
 (see page 119/79/44 in 2010 documentation)
the parameters (set during initalization)
  mn - month
  ida - day of month
  iyr - 4 digit year
are used to determine which Athmosphere-data to use (see page 83 in 2010 documentation).
They can be derived from a Julian Date Format.
The parameter (set during initalization)
	delta
corresponds to the time increment in seconds.


Page 54:
"Like its predecessors, GRAM2010, is designed to produce atmospheric parameter values
either along a linear path (a profile) or along any set of related time-position data (a trajectory).
Based on user-selected input values, the program can step automatically in height, latitude, longitude, and time along any desired linear profile. "

It seems like time is given in seconds and corresponds to the elapsed time 
of the trajectory. As i understand it, it can be set to zero for the initial
data-point.