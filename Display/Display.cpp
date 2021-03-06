/////////////////////////////////////////////////////////////////////////////
//display.cpp - Displays  the converted output                             //
// ver 1.0                                                                 //
// Language:    Visual C++ 2017											   //
// Platform:    HP Intel Core i7, Win10                                    //
// Application: Project #1, Spring 2019                                    //
// Author:      Arjun Kalyanasundaram, akalyana@syr.edu                    //
/////////////////////////////////////////////////////////////////////////////


#include"Display.h"


/*--------------------------------------------------<Display Function>-------------------------------------------------------------*/
void display::dis(std::vector<std::string> htmlfile)//----<Function Displays in web browser the html page>--------//
{
	int Process_End = 0;
	std::string filed;                    //////string for the file name///////
	Process p;                            //////creating an object of process//////
	p.title("test application");          
	for (auto filed : htmlfile) {        /////displays files in the vector///////
		if (Process_End >= 5)            ///stops diplaying after 5 times//////
			return;                    /////if it displays more than 5 times process ends//////
		Process_End++;                  
		std::cout << "\n  Demonstrating code pop-up in Mozilla Firefox";    /////code pop up in Mozilla////
		std::cout << "\n ======================================";
		std::string displayfile = "file:///" + filed;
		std::string appPath = "C:\\Program Files\\Mozilla Firefox\\firefox.exe";  // path to application to start//
		p.application(appPath);
		std::string cmdLine = "/A " + displayfile;  // asking Mozilla to display //
		p.commandLine(cmdLine);
		std::cout << "\n  Will start Mozilla Firefox 5 times and each time wait for termination.";
		std::cout << "\n  You need to kill each window (upper right button) to continue.";
		std::cout << "\n  starting process: \"" << appPath << "\"";
		p.create();                                                              ///passes the new file//////
		CBP callback = []() { std::cout << "\n  --- child process exited with this message ---"; };
		p.setCallBackProcessing(callback);
		p.registerCallback();
		WaitForSingleObject(p.getProcessHandle(), INFINITE);  // wait for created process to terminate*//
		std::cout << "\n  after OnExit";
		std::cout.flush();
	}
}



#ifdef  Test_D1


int main()
{
	std::vector<std::string> htmlfile1;
	display d;
	d.dis(htmlfile1);
	std::cout << "\n  Demonstrating code pop-up in Mozilla Firefox";    /////code pop up in Mozilla////
	std::cout << "\n ======================================";
	std::cout << "\n  Will start Mozilla Firefox 5 times and each time wait for termination.";
	std::cout << "\n  You need to kill each window (upper right button) to continue.";
}




#endif // DEBUG















