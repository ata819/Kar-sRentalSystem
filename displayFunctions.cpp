//
// Created by Alan Ta on 2/1/21.
//
#include "main.h"

std::string timeAndDate(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%m/%d/%Y/ at %I:%M:%S ", timeinfo);
    std::string str(buffer);
    return str;
}

void loadingScreen(){
    std::cout << std::string( 100, '\n' );
    printf("\t\t\t\t\tLoading...\n");
    sleep(3);
    std::cout << std::string( 100, '\n' );
}

void ClearScreen()
{
    std::cout << std::string( 100, '\n' );
}

void printFileToScreen(const std::string& fileName){
    std::string line;
    std::ifstream titleFile (fileName);
    if(titleFile.is_open()){
        while( getline(titleFile,line)){
            std::cout << line << std::endl;
        }
        titleFile.close();
    }
    else{
        std::cout << "UNABLE TO OPEN:" << fileName << std::endl;
    }
}
