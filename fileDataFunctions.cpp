#include "main.h"

class ElementSort{
public:
    std::vector<std::string> elements;
};

int sortFileData(const std::string& fileName, int whichData){
    ElementSort unsortedElements;
    std::string line;
    unsigned int curLine = 0;
    std::ifstream titleFile(fileName);
    std::ofstream newTitleFile;

    if(titleFile.is_open()){
        while( getline(titleFile,line)){
            curLine++;
            unsortedElements.elements.push_back(line);
        }
        titleFile.close();
    }
    else{
        std::cout << "UNABLE TO OPEN:" << fileName << std::endl;
        return -1;
    }

    sort(unsortedElements.elements.begin(), unsortedElements.elements.end());
    newTitleFile.open("replacementFile.txt");
    for(const auto &e : unsortedElements.elements){
        newTitleFile << e << "\n";
    }
    //std::ostream_iterator<std::string> output_iterator(newTitleFile, "\n");
    //std::copy(unsortedElements.elements.begin(), unsortedElements.elements.end(), output_iterator);
    newTitleFile.close();
    if(whichData == 3 || whichData == 1){
        remove("carCollection.txt");
        rename("replacementFile.txt", "carCollection.txt");
    }
    if(whichData == 2){
        remove("customerInfo.txt");
        rename("replacementFile.txt", "customerInfo.txt");
    }
    return 0;
}


int removeFileData(const std::string& fileName, const std::string& fileLine, int whichData){
    std::string line;
    unsigned int curLine = 0;
    unsigned int carLocateLine = 0;
    bool elementFound = false;
    std::ifstream titleFile(fileName);
    std::ofstream newTitleFile;

    if(titleFile.is_open()){
        newTitleFile.open("replacementFile.txt");
        while( getline(titleFile,line)){
            curLine++;
            if(line.find(fileLine, 0) != std::string::npos){
                elementFound = true;
                carLocateLine = curLine;
            }
            else{
                newTitleFile << line << std::endl;
            }
        }
        titleFile.close();
        if(elementFound){
            if(whichData == 1){
                newTitleFile << "UNAVAILABLE\t\t" << fileLine << std::endl;
                remove("carCollection.txt");
                rename("replacementFile.txt", "carCollection.txt");
            }
            if(whichData == 2){
                remove("customerInfo.txt");
                rename("replacementFile.txt", "customerInfo.txt");
            }
            if(whichData == 3){
                remove("carCollection.txt");
                rename("replacementFile.txt", "carCollection.txt");
            }
            newTitleFile.close();
            return 0;
        }
        else{
            if(whichData == 1 || whichData == 3){
                std::cout << "Vehicle does not exist on file" << std::endl;
            }
            if(whichData == 2){
                std::cout << "Customer does not exist on file" << std::endl;
            }
            remove("replacementFile.txt");
            newTitleFile.close();
            return -1;
        }
    }
    else{
        std::cout << "UNABLE TO OPEN:" << fileName << std::endl;
        return -1;
    }
}


int checkFileData(const std::string& fileName, const std::string& fileLine){
    std::string line;
    bool elementFound = false;
    unsigned int curLine = 0;
    unsigned int elementLocateLine = 0;
    std::ifstream titleFile(fileName);

    if(titleFile.is_open()){
        while( getline(titleFile,line)){
            curLine++;
            if(line.find(fileLine, 0) != std::string::npos){
                elementLocateLine = curLine;
                elementFound = true;
            }
        }
        titleFile.close();
        if(elementFound){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        std::cout << "UNABLE TO OPEN:" << fileName << std::endl;
        return -1;
    }
}

