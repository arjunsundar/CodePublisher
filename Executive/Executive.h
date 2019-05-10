
/////////////////////////////////////////////////////////////////////////////
// Executive.h - Executive package for  Source Code Publisher              //
// ver 1.0                                                                 //
// Language:    Visual C++ 2017			                                   //
// Platform:    HP Intel Core i7, Win10                                    //
// Application: Project #1, Spring 2019                                    //
// Author:     Arjun Kalyanasundaram, akalyana@syr.edu                     //
// Source:     Jim Fawcett,Syracuse University                             //
/////////////////////////////////////////////////////////////////////////////
/*

Module Operations:
==================
The Executive package links all the other packages, this includes Convert and
Display.The module works to convert all the source code in the folder into webpages,
this is done using converter.An object of convert is being created and is called from the
Executive package, this sends all the files into a vector and then the debugging command
arguments are set to *.cpp *.h to convert only the .cpp and .h files.The package makes use of
Regular expression to find file names and then converts them,in REGEX the command line argument
is passed, the command line argument with regex expression detects for file names within a specified range.
The converted webpages are stored in the ConvertedWebpges folder and using the display
package the webpages are displayed in html format using the browser.On termnating each window
of the browser a new window pops up to display the next converted webpage.The Executive package is
referenced with convert  and Display.In addition Each package is being demostrated 
separately.

Build Process:
==============
Required files
converter.h Display.h

Build commands
==============
- devenv D3.sln

Maintenance History:
====================
ver 1.0 : 2/5/2019
first release

*/



#include<iostream>
#include "../DirectoryNavigator/Utilities/StringUtilities/StringUtilities.h"
#include "../DirectoryNavigator/Utilities/CodeUtilities/CodeUtilities.h"
#include "../DirectoryNavigator/convert/converter.h"
#include "../Display/Display.h"
#include <regex>

using namespace Utilities;
using namespace FileSystem;

class Executive            ///Creating a class Executive///////
{
public:
	void Demo1();  // ---<demonstrating requirement 1 visual studio>-------//
	void Demo2(); //----<demonstrating requirement 2 | using library>----//
	void Demo3();//----<demonstrating requirement 3 | using  packages>----//
	void Demo4();//----<demonstrating requirement 4 | Command line Argument>----//
	void Demo5(int argc, char *argv[]);//----<demonstrating requirement 5 | Error Message >----//
	void Demo6(int argc, char *argv[]);//----<demonstrating requirement 6 | stores converted webpages,final output>----//

};




