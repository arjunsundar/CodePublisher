#pragma once
/////////////////////////////////////////////////////////////////////////////
// converter.h - includes all functions required for conversion            //
// ver 1.0                                                                 //
// Language:    Visual C++ 2017											   //
// Platform:    HP Intel Core i7, Win10                                    //
// Application: Project #1, Spring 2019                                    //
// Author:      Arjun Kalyanasundaram, akalyana@syr.edu                    //
/////////////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
Creates files for being Converted into HTML. Files created include:The HTML tags.
Files are made into vector of strings and then converted.The special characters
'<' and '>' are rplaced with their HTMl equivalent.

Public Interface:
=================
void code_Html(std::vector<string> & file);
void filter(std::string &lin);

Build Process:
==============
Required files
- converter.h convert.cpp 

Build commands
- devenv D3.sln

Maintenance History:
====================
ver 1.0 : 2/5/2019
first release
*/

#include<iostream>
#include<vector>
#include<string>
#include"../DirExplorer-Naive/DirExplorerN.h"

using namespace FileSystem;

class Convert                                            //<----creating class Convert---->//
{
	public:
		void code_Html(std::vector<std::string> & file);//<---function converts source code into Html--->//
		void filter(std::string &lin);//<---filter funcion removes special characters and replaces with html equivalent--->//
	private:
		std::string str_;
};
