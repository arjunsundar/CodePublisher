/////////////////////////////////////////////////////////////////////////////
// converter.cpp - converter                                               //
// ver 1.0                                                                 //
// Language:    Visual C++ 2017											   //
// Platform:    HP Intel Core i7, Win10                                    //
// Application: Project #1, Spring 2019                                    //
// Author:      Arjun Kalyanasundaram, akalyana@syr.edu                    //
/////////////////////////////////////////////////////////////////////////////



#include "converter.h"

/*--------------------------------------------------<filter Function>-------------------------------------------------------------*/
void Convert::filter(std::string &lin)       ////filter function definition//////////
{
	size_t searcht = lin.find("<");///////special character to find ///////
	if (lin.size() > searcht)
	{
		lin.replace(searcht, 1, "&lt"); ///////////replaces special character '<' with html equivalent '&lt' ///////////

	}
	else {}
	size_t searcht1 = lin.find(">"); ///////special character to find ///////
	if (lin.size() > searcht1)
	{
		lin.replace(searcht1, 1, "&gt");///////////replaces special character '<' with html equivalent '&gt' ///////////
	}
	else {}
}

/*--------------------------------------------------<Function to convert into Html>-------------------------------------------------------------*/
void Convert::code_Html(std::vector<std::string> & files)/////////function definition to convert into html format /////////////
{
	std::ifstream in;
	std::string path;
	std::string pattern;
	std::string dir = "../ConvertedWebpages"; //////////storing converterd files in directory Converted Webpages//////////
	if (!FileSystem::Directory::exists(dir))
	{
		FileSystem::Directory::create(dir);//////////if directory does not exist creating a new directory//////////
	}
	if (files.size() == 0)
	{
		std::cout << "error no files found.\n";//////////reads error when the file size is zero//////////
	}
	std::vector<std::string>  webfiles;       //////////creating vector to store files//////////   
	for (auto file : files)
	{
		std::string filesn;
		std::string filepath = file;
		std::ifstream in(filepath);               //////////using ifstream to read file path//////////
		std::vector<std::string> filecontent;
		for (std::string line; std::getline(in, line);)
		{
			Convert::filter(line);                 ////using filter function to replace special characters////
			filecontent.push_back(line);
		}
		std::string webfolderpath = dir + '/' + FileSystem::Path::getName(file) + ".html";  /////folder  to store Converted webpages//////
		webfiles.push_back(FileSystem::Path::getFullFileSpec(webfolderpath));
		for (auto filesn : webfiles)
		{

			std::cout << filesn << std::endl;         /////displaying the files which are converted into webpage/////
		}
		std::ofstream str(webfolderpath);   //////////reads from web folder path and adds Html tags//////////
		str << "<!Doctype html>\n";          //--<Html tag>--//
		str << "<html>";					 //--<Html tag>--//
		str << "<head>";					 //--<Html tag>--//
		str << "<body>";                     //--<Html tag>--//
		str << "<pre>";                      //--<Html tag>--//
		for (size_t i = 0; i < filecontent.size(); i++)
		{
			str << filecontent.at(i) << "<br/>";
		}
		str << "</pre>";                     //--<Html tag>--//
		str << "</body>";                    //--<Html tag>--//
		str << "</head";                     //--<Html tag>--//
		str << "</html>";                    //--<Html tag>--//
		str.close();                          //close ofstream//
	}
}




#ifdef Test_convert
int main()
{

	std::vector<std::string>  file;
	Convert C1;
	cout << "converted files are:" << endl;
	C1.code_Html(file);

}
#endif // Test_convert






















