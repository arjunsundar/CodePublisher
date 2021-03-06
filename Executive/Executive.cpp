/////////////////////////////////////////////////////////////////////////////
// Executive.cpp - Executive package for  Source Code Publisher            //
// ver 1.0                                                                 //
// Language:    Visual C++ 2017			                                   //
// Platform:    HP Intel Core i7, Win10                                    //
// Application: Project #1, Spring 2019                                    //
// Author:     Arjun Kalyanasundaram, akalyana@syr.edu                     //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
/*

Module Operations:
==================
The Executive  package consists of the functions used  in Executive.h
Member functions of the Exectuive package are being used.All the requirements
are being provided in this package.

Build Process:
==============
Required files
-Executive.h
*/
#include"Executive.h"
using namespace std;

///////--------------------------------------------------<Requirement 1>---------------------------------------///////
void::Executive::Demo1()
{

	cout << "*--------------------------------------------------<Demonstrating Requirement 1>-----------------------------------------*" << endl;
	cout << "\n";
	cout << "Using Visual Studio 2017 " << endl;
	cout << "\n";
}
///////--------------------------------------------------<Requirement 2>---------------------------------------///////
void::Executive::Demo2() {

	cout << "*--------------------------------------------------<Demonstrating Requirement 2>-----------------------------------------*" << endl;
	cout << " using  the standard streams libraries for all I/O and operators new and delete for memory management. " << endl;
	cout << "Code Fragments  :" << endl;
	cout << "std::string filepath = file;\nstd::ifstream in(filepath);\nstd::vector<std::string> filecontent;\n" << endl;
	cout << "\n";
}
///////--------------------------------------------------<Requirement 3>---------------------------------------///////
void::Executive::Demo3() {


	cout << "*--------------------------------------------------<Demonstrating Requirement 3>-----------------------------------------*" << endl;
	cout << "Packages provided are:" << endl;
	cout << "1.Executive" << endl;
	cout << "2.Convert" << endl;
	cout << "3.Display " << endl;;
	cout << "\n";

}
///////--------------------------------------------------<Requirement 4>---------------------------------------///////
void::Executive::Demo4()///////Command line Argument ///////
{
	cout << "*--------------------------------------------------<Demonstrating Requirement 4>-----------------------------------------*" << endl;
	cout << "regular expression used to select filenames to process." << endl;
	cout << "Command line Arguments are:" << endl;
	cout << ".. /s *.* *.cpp *.h [A-D](.*)" << endl;
	cout << "\n";

}
ProcessCmdLine::Usage customUsage()
{
	std::string usage;
	usage += "\n  Command Line: path [/option]* [/pattern]*";
	usage += "\n    path is relative or absolute path where processing begins";
	usage += "\n    [/option]* are one or more options of the form:";
	usage += "\n      /s - walk directory recursively";
	usage += "\n    [pattern]* are one or more pattern strings of the form:";
	usage += "\n      *.h *.cpp *.cs *.txt or *.*";
	usage += "\n";
	return usage;

}
///////--------------------------------------------------<Requirement 5>---------------------------------------///////
void::Executive::Demo5(int argc, char *argv[])/////No matches found----reads error message-----///////////////////
{
	cout << "*--------------------------------------------------<Demonstrating Requirement 5>-----------------------------------------*" << endl;
	cout << " Error message for files that are not matched using REGEX" << endl;
	ProcessCmdLine pcl(argc, argv);
	pcl.usage(customUsage());
	DirExplorerN de(pcl.path());
	for (auto patt : pcl.patterns())
	{
		de.addPattern(patt);
	}
	if (pcl.hasOption('s'))
	{
		de.recurse();
	}
	de.search();
	auto files = de.filestoProcess();
	for (auto regex_str : pcl.regexes())  ///checkcks for regex pattern////
	{
		std::regex r(regex_str);
		for (auto file : files)
		{
			std::string filename = FileSystem::Path::getName(file); // gets filename //
			if (std::regex_match(filename, r))
			{
				cout << "Files matched :"<<filename<< endl;      //displays file matched with regex expression////

			}
			else
			{
				cout << "Error No Files Matched :"<<filename<< endl;  //dispalys error when not matched with regex expression//
			}
		}

	}
}
///////--------------------------------------------------<Requirement 6>---------------------------------------///////


std::vector<std::string> code_Convert(std::string &file, std::vector<std::string> &displaypath)///function to convert into html and store in folder////
{
	std::string dir = "../ConvertedWebpages"; //directory to store converted webpages////
	std::vector<std::string> listf;
	listf.push_back(file);//////pushing the files into a vector///////
	Convert C;//////////////Creating an object from class Convert//////////////
	C.code_Html(listf);//////////////function converts .cpp and .h files into html format//////////////
	listf.pop_back();
	std::string webfolderpath1 = dir + '/' + FileSystem::Path::getName(file) + ".html";  ////directory name in .html extension/////
	displaypath.push_back(FileSystem::Path::getFullFileSpec(webfolderpath1));
	return  displaypath; /////returns the path to display//////
}
void::Executive::Demo6(int argc, char *argv[]) ////////file conversion//////////////
{
	ProcessCmdLine pcl(argc, argv);
	pcl.usage(customUsage());
	DirExplorerN de(pcl.path());
	using files = std::vector<std::string>;
	for (auto patt : pcl.patterns())
	{
		de.addPattern(patt);
	}
	if (pcl.hasOption('s'))
	{
		de.recurse();
	}
	de.search();                                ///list of files in directory//
	files FileList = de.filestoProcess();       ///list for files to process////
	std::vector<std::string> displaypath1;      ///vector to sto store the path to display////
	if (pcl.regexes().size() == 0) {
		for (auto file : FileList)          
		{
			code_Convert(file,displaypath1);  ///converts file  to html and returns path to display////
		}
	}
	else
	{
		for (auto regex_str : pcl.regexes())   ////to match with regex expression////
		{
			std::regex r(regex_str);
			for (auto file : FileList)
			{
				std::string filename = FileSystem::Path::getName(file);
				if (std::regex_match(filename, r))
				{
					code_Convert(file, displaypath1);  ///converts to html and returns path to display////
				}
			}
		}
	}
	cout << "\n";
	cout << "*--------------------------------------------------<Demonstrating Requirement 7>-----------------------------------------*" << endl;
	cout << "\n";
	cout << "*--------------------------------------------------<Dislaying the webpages >-----------------------------------------*" << endl;
	display d;          //////////////Creating an object of class display//////////////
	d.dis(displaypath1);////--------<-----converted files are displayed------------>/////
}


/*--------------------------------------------------<<Main Function>-------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	Executive E1;  ///creating an object of class Executive/////
	E1.Demo1();
	E1.Demo2();
	E1.Demo3();
	E1.Demo4();
	E1.Demo5(argc,argv);
	cout << "*--------------------------------Demonstrating Requirement 6 to show the converted pages---------------------------------* " << endl;
	cout << "\n";
	cout << "Converted  source code and stored in ConvertedWebpages folder:" << endl;
	cout << "\n";
	E1.Demo6(argc, argv);	
}

	



