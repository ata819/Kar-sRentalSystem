//
// Created by Alan Ta on 2/1/21.
//
#include "main.h"


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
