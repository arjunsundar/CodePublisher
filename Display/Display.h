/////////////////////////////////////////////////////////////////////////////
// Display.h - Includes all functions required for Display                 //
// ver 1.0                                                                 //
// Language:    Visual C++ 2017											   //
// Platform:    HP Intel Core i7, Win10                                    //
// Application: Project #1, Spring 2019                                    //
// Author:      Arjun Kalyanasundaram, akalyana@syr.edu                    //
/////////////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
Displays stored files from converted webpage folder.Allows to create pop up window from browser to display the converted
source code.

Public Interface:
=================
dis(std::vector<std::string> str);

Build Process:
==============
Required files
- Process.h 

Build commands
==============
- devenv D3.sln
Maintenance History:
====================
ver 1.0 : 2/5/2019
first release
*/

#include <iostream>
#include <vector>
#include"../DirectoryNavigator/Process/Process.h"

class display         //<----creating class display---->//
{
public:
	static void dis(std::vector<std::string> str);    //<----function to display converted html---->//
	
};

