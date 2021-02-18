#include "main.h"


struct invoiceInfo{
    std::string invoiceNum;
    std::string customerName;
    std::string custDL;
    std::string carYear;
    std::string carModel;
    std::string rentDays;
    std::string rentDue;

};


void addCar(){
    std::string carYear;
    std::string carMake;
    std::string carName;
    std::string carType;
    std::string line;
    char yesOrNo;
    std::cout << "\t\t\t\t\t------------------------------";
    std::cout << "\n\t\t\t\t\t       ADD CAR \n";
    std::cout << "\t\t\t\t\t------------------------------\n\n";
    printFileToScreen("carCollection.txt");

    std::cout << "Please enter the YEAR MAKE NAME TYPE of the new car" << std::endl;
    std::cout << ":";
    std::cin >> carYear >> carMake >> carName >> carType;
    std::cout << "The car entered was " << carYear << " " << carMake << " " << carName << " " << carType << " " << std::endl;

    std::cout << "Is that the correct name? (y/n) " << std::endl;
    std::cout << ":";
    std::cin >> yesOrNo;
    switch(yesOrNo) {
        case 'y':{
            std::cout << "CAR ADDED" << std::endl;
            sleep(4);
            ClearScreen();
            std::ofstream carCollect;
            carCollect.open("carCollection.txt", std::ios_base::app);
            std::string Result = "AVAILABLE\t\t" + carYear + " " + carMake + " " + carName + " " + carType;
            carCollect << Result;
            carCollect << std::endl;
            sortFileData("carCollection.txt", 3);
            std::string wholeCar = carYear + " " + carMake + " " + carName + " " + carType;
            constructHistory(wholeCar, 1);
            break;
        }
        case 'n': {
            ClearScreen();
            addCar();
            break;
        }
        default:
            std::cout << "INVALID" << std::endl;
            ClearScreen();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }



}
void removeCar(){
    std::string carInfo;
    std::string carYear;
    std::string carMake;
    std::string carName;
    std::string carType;
    std::string line;
    std::string availCarInfo;
    char yesOrNo;

    do{
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t       CAR'S AVAILABLE \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("carCollection.txt");
        std::cout << "Please enter the YEAR MAKE NAME TYPE of the new car" << std::endl;
        std::cout << ":";
        std::cin >> carYear >> carMake >> carName >> carType;
        carInfo = carYear + " " + carMake + " " + carName + " " + carType;
        ClearScreen();
        std::cout << "The car entered was: " + carInfo << std::endl;
        std::cout << "Is that the correct name? (y/n) " << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
        availCarInfo = "AVAILABLE\t\t" + carInfo;
        std::string unavailCarInfo = "UNAVAILABLE\t\t" + carInfo;
        if(checkFileData("carCollection.txt", unavailCarInfo) == 0){
            std::cout << "The vehicle is listed as UNAVAILABLE and cannot be removed" << std::endl;
            yesOrNo = 'n';
            sleep(4);
            ClearScreen();
        }
        else if(checkFileData("carCollection.txt", availCarInfo) < 0 ){
            std::cout << "Vehicle does not exist on file" << std::endl;
            yesOrNo = 'n';
            sleep(4);
            ClearScreen();
        }
    }while(yesOrNo != 'y');
    constructHistory(carInfo, 2);
    removeFileData("carCollection.txt", availCarInfo, 3);

}

void editCar(){
    std::string carInfo;
    std::string carYear;
    std::string carMake;
    std::string carName;
    std::string carType;
    std::string line;
    std::string availCarInfo;
    char yesOrNo;

    do{
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t       CAR'S AVAILABLE \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("carCollection.txt");
        std::cout << "Please enter the YEAR MAKE NAME TYPE of the car listed you would to EDIT" << std::endl;
        std::cout << ":";
        std::cin >> carYear >> carMake >> carName >> carType;
        carInfo = carYear + " " + carMake + " " + carName + " " + carType;
        ClearScreen();
        std::cout << "The car to be edited was: " + carInfo << std::endl;
        std::cout << "Is that correct? (y/n) " << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
        availCarInfo = "AVAILABLE\t\t" + carInfo;
        std::string unavailCarInfo = "UNAVAILABLE\t\t" + carInfo;
        if(checkFileData("carCollection.txt", unavailCarInfo) == 0){
            std::cout << "The vehicle is listed as UNAVAILABLE and cannot be edited" << std::endl;
            yesOrNo = 'n';
            sleep(4);
            ClearScreen();
        }
        else if(checkFileData("carCollection.txt", availCarInfo) < 0 ){
            std::cout << "Vehicle does not exist on file" << std::endl;
            yesOrNo = 'n';
            sleep(4);
            ClearScreen();
        }
    }while(yesOrNo != 'y');
    constructHistory(carInfo, 2);
    removeFileData("carCollection.txt", availCarInfo, 3);
    std::cout << "Car to be edited found" << std::endl;
    sleep(2);
    addCar();

}

void carListScreen(){
    std::vector<std::string> stock;
    int carListOption;
    std:: string line;
    std::ifstream myFile("carCollection.txt");
    if ( myFile.is_open() ) //Always test the file open.
    {
        while (std::getline(myFile, line))
        {
            stock.push_back(line);
            std::cout << line << std::endl;
        }
        myFile.close();
    }
    else
    {
        std::cout << "Unable to open file\n";
    }

    std::cout << "\n1:ADD CAR | 2:REMOVE CAR | 3:EDIT CAR | 4:BACK" << std::endl ;
    std::cout << ":";
    std::cin >> carListOption;
    switch (carListOption) {
        case 1: {
            ClearScreen();
            addCar();
            break;
        }
        case 2:
            ClearScreen();
            removeCar();
            break;
        case 3:
            editCar();
            break;
        case 4:
            ClearScreen();
            std::cout << "\t\t\t\t\t\t\t\tGOING BACK...\n";
            sleep(4);
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ClearScreen();
            carListScreen();
    }

}

class CustomerDetails{
public:
    void customerInformation(){
        std::string line;
        int custOption;
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t       CUSTOMER INFO \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("customerInfo.txt");

        std::cout << "\n1:ADD CUSTOMER | 2:REMOVE CUSTOMER | 3:EDIT CUSTOMER | 4:BACK" << std::endl ;
        std::cout << ":";
        std::cin >> custOption;
        switch (custOption) {
            case 1:
                addCustomer();
                break;
            case 2:
                removeCustomer();
                break;
            case 3:
                break;
            case 4:
                ClearScreen();
                std::cout << "\t\t\t\t\t\t\t\tGOING BACK...\n";
                sleep(4);
                break;
            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                customerInformation();
        }
    }

    void addCustomer(){
        std::string firstName;
        std::string lastName;
        std::string driverLicense;
        std::string line;
        char yesOrNo;
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t    ADD CUSTOMER ACCOUNT   \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("customerInfo.txt");

        std::cout << "Please enter the customer's FIRSTNAME LASTNAME" << std::endl;
        std::cout << ":";
        std::cin >> firstName >> lastName;
        std::cout << "Please enter the customer's DRIVER LICENSE NUMBER" << std::endl;
        std::cout << ":";
        std::cin >> driverLicense;

        std::cout << "The customer information entered was NAME:" << firstName << " " << lastName << " DL#:" << driverLicense<< std::endl;

        std::cout << "Is that the correct name? (y/n) " << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
        switch(yesOrNo) {
            case 'y':{
                std::cout << "CUSTOMER ADDED" << std::endl;
                sleep(4);
                ClearScreen();
                std::ofstream custInfoStream;
                custInfoStream.open("customerInfo.txt", std::ios_base::app);
                std::string Result = firstName + " " + lastName + " " + driverLicense;
                custInfoStream << Result;
                custInfoStream << std::endl;
                constructHistory(Result, 3);
                sortFileData("customerInfo.txt", 2);
                break;
            }
            case 'n': {
                ClearScreen();
                addCustomer();
                break;
            }
            default:
                std::cout << "INVALID" << std::endl;
                ClearScreen();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

    }

    void removeCustomer(){
        std::string firstName;
        std::string lastName;
        std::string driverLicense;
        std::string fullNameDL;
        std::string line;
        char yesOrNo;

        do{
            std::cout << "\t\t\t\t\t------------------------------";
            std::cout << "\n\t\t\t\t\t REMOVE CUSTOMER ACCOUNT   \n";
            std::cout << "\t\t\t\t\t------------------------------\n\n";
            printFileToScreen("customerInfo.txt");

            std::cout << "Please enter the customer's FIRSTNAME LASTNAME" << std::endl;
            std::cout << ":";
            std::cin >> firstName >> lastName;
            std::cout << "Please enter the customer's DRIVER LICENSE NUMBER" << std::endl;
            std::cout << ":";
            std::cin >> driverLicense;
            std::cout << "The customer information entered was NAME:" << firstName << " " << lastName << " DL#:" << driverLicense<< std::endl;
            std::cout << "Is that the correct name? (y/n) " << std::endl;
            std::cout << ":";
            std::cin >> yesOrNo;
        } while (yesOrNo != 'y');
        fullNameDL = firstName + " " + lastName + " " + driverLicense;
        if(removeFileData("customerInfo.txt",fullNameDL,2) < 0){
            std::cout << "The customer does not exist according to the info provided" << std::endl;
            sleep(4);
        }
        else{
            constructHistory(fullNameDL, 4);
            std::cout << "Customer was successfully removed from client list" << std::endl;
        }


    }

};

class intro{
public:
    static void introDisplay(){
        chdir("/Users/alanta/CLionProjects/CarRentalSystem");
        std::string line;
        printFileToScreen("titleCard.txt");
        sleep(4);

    }
    int loginSystem(){
        ClearScreen();
        std::string userPassword;
        std::string line;
        std::string realPassword;

        std::cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       KAR'S RENTAL SYSTEM \n\n";
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t\t     LOGIN \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        std::cout << "\t\t\t\t\tEnter Password: ";
        std::cin >> userPassword;

        std::ifstream loginPassword ("loginPassword.txt");
        if(loginPassword.is_open()){
            while(getline(loginPassword, line)){
                int compReslt = strcmp(userPassword.c_str(),line.c_str());
                if(compReslt == 0){
                    printf("\t\t\t\t\t\t\tSuccess\n");
                    sleep(2);
                    loadingScreen();
                    return 0;
                }
                else{
                    printf("\t\t\t\t\t\t\tFailed\n");
                    sleep(4);
                    loginSystem();
                }
            }

        }
        return 0;
    }
};

void rentOptions(){
    std::string line;
    int custOption;
    std::cout << "\t\t\t\t\t------------------------------";
    std::cout << "\n\t\t\t\t\t       CUSTOMER INFO \n";
    std::cout << "\t\t\t\t\t------------------------------\n\n";
    std::ifstream titleFile ("customerInfo.txt");
    if(titleFile.is_open()){
        while( getline(titleFile,line)){
            std::cout << line << std::endl;
        }
        titleFile.close();
    }
    else{
        std::cout << "Customer Information File missing" << std::endl;
    }
    std::cout << "\n1:ASSIGN CAR TO CUSTOMER | 2:CHECK RENT DUES | 3:UPDATE RENT INFO | 4:BACK" << std::endl ;
    std::cout << ":";
    std::cin >> custOption;
    switch (custOption) {
        case 1:
            rentCarAssignment();
            break;
        case 2:
            ClearScreen();
            rentCheck();
            break;
        case 3:
            rentUpdate();
            break;
        case 4:
            ClearScreen();
            std::cout << "\t\t\t\t\t\t\t\tGOING BACK...\n";
            sleep(4);
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ClearScreen();
            rentOptions();
    }

}

std::string invoiceNum(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%m%d%Y%I%M%S", timeinfo);
    std::string str(buffer);
    return str;
}

void invoiceCreate(const struct invoiceInfo& temp){
    std::ofstream invoiceFile;
    invoiceFile.open("invoiceHistory.txt", std::ios_base::app);
    invoiceFile << "\t\t\t\t\t-------------------------------------------";
    invoiceFile << "\n\t\t\t\t\t   Car Rental - Customer Invoice \n";
    invoiceFile << "\t\t\t\t\t-------------------------------------------\n\n";
    invoiceFile << "\t | Invoice No.    :----------------| " << temp.invoiceNum << std::endl;
    invoiceFile << "\t | Customer Name  :----------------| " << temp.customerName << std::endl;
    invoiceFile << "\t | Customer DL#   :----------------| " << temp.custDL << std::endl;
    invoiceFile << "\t | Car Year       :----------------| " << temp.carYear << std::endl;
    invoiceFile << "\t | Car Model      :----------------| " << temp.carModel << std::endl;
    invoiceFile << "\t | Rent Due Date  :----------------| " << temp.rentDue << std::endl;
    invoiceFile << "\t | Total Rent Days:----------------| " << temp.rentDays << std::endl;
    invoiceFile << "\t   ------------------------------------------------------------------------" << std::endl;
    int rentDaysToInt = std::stoi(temp.rentDays);
    int rentAmount = rentDaysToInt * 75;
    invoiceFile << "\t | Total Rental Amount is :--------| $" << rentAmount << std::endl;
    invoiceFile << "\t   ------------------------------------------------------------------------" << std::endl;
    invoiceFile << std::endl << std::endl;

}

void invoiceHist(){
    std::string line;
    unsigned int curLine = 0;
    int linePerPage = 15;
    char nxtOrPrev;
    std::ifstream titleFile("invoiceHistory.txt");
    if (titleFile.is_open()) {
        while (getline(titleFile, line)) {
            curLine++;
            std::cout << line << std::endl;
            if (curLine == linePerPage){
                std::cout << "Would you like to go the the NEXT PAGE? (n)" << std::endl;
                std::cout << ":";
                std::cin >> nxtOrPrev;
                if(nxtOrPrev == 'n') {
                    linePerPage += 15;
                    ClearScreen();
                }
            }
        }
        titleFile.close();
        sleep(5);
    }
}

void rentCarAssignment(){
    std::vector<invoiceInfo> invoice;
    std::string customerFN;
    std::string customerLN;
    std::string customerFullName;
    std::string DLNumber;
    std::string customerInfo;
    std::string rentDays;
    std::string rentDueDate;
    std::string carInfo;

    char yesOrNo;
    std::string line;
    invoiceInfo temp;
    do{
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t       CUSTOMER INFO \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("customerInfo.txt");
        std::cout << "Enter the customer FIRSTNAME LASTNAME that would like to rent a car" << std::endl;
        std::cout << ":";
        std::cin >> customerFN >> customerLN;
        customerFullName = customerFN + " " + customerLN;
        std::cout << "Enter the customer Driver License Number " << std::endl;
        std::cout << ":#";
        std::cin >> DLNumber;
        ClearScreen();
        std::cout << "Are these correct? (y/n)" << std::endl;
        std::cout << "FN&LN: " << customerFullName << " | " << "DL#: " << DLNumber << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
        customerInfo = customerFullName + " " + DLNumber;
        if(checkFileData("customerInfo.txt", customerInfo) < 0 ){
            std::cout << "Customer information does not exist on file" << std::endl;
            sleep(4);
            yesOrNo = 'n';
            ClearScreen();
        }
    } while(yesOrNo != 'y');

    temp.customerName = customerFullName;
    temp.custDL = DLNumber;
    yesOrNo = 'n';

    do{
        std::string carYear;
        std::string carMake;
        std::string carName;
        std::string carType;
        std::string availCarInfo;
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t       CAR'S AVAILABLE \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("carCollection.txt");
        std::cout << "Please enter the YEAR MAKE NAME TYPE of the new car" << std::endl;
        std::cout << ":";
        std::cin >> carYear >> carMake >> carName >> carType;
        carInfo = carYear + " " + carMake + " " + carName + " " + carType;
        ClearScreen();
        std::cout << "The car entered was: " + carInfo << std::endl;
        std::cout << "Is that the correct name? (y/n) " << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
        availCarInfo = "AVAILABLE\t\t" + carInfo;
        if(checkFileData("carCollection.txt", availCarInfo) < 0 ){
            std::cout << "Vehicle does not exist on file OR is UNAVAILABLE" << std::endl;
            sleep(4);
            yesOrNo = 'n';
            ClearScreen();
        }
        temp.carYear = carYear;
        temp.carModel = carMake + " " + carName + " " + carType;
    }while(yesOrNo != 'y');
    ClearScreen();
    if(removeFileData("carCollection.txt", carInfo, 1) == 0){
        sortFileData("carCollection.txt", 1); // Not sure if this is needed
        std::cout << "This is the information provided" << std::endl;
        std::cout << "Customer: " << customerFullName << " | DL#: " << DLNumber << " | Car: " << carInfo << std::endl;
        std::cout << "How many days will this customer rent this vehicle? (DD)" << std::endl;
        std::cout << ":";
        std:: cin >> rentDays;
        std::cout << "What date will the customer need to return the vehicle by? (MM/DD/YYYY)" << std::endl;
        std::cout << ":";
        std::cin >> rentDueDate;
        std::string invoiceN = invoiceNum();
        temp.invoiceNum = invoiceN;
        temp.rentDays = rentDays;
        temp.rentDue = rentDueDate;
        std::ofstream custCarRentStream;
        custCarRentStream.open("customerCarRentData.txt", std::ios_base::app);
        custCarRentStream << rentDays << "\t "  << rentDueDate << "      " << invoiceN << "\t";
        custCarRentStream << std::left << std::setw(20) << customerFullName << "\t" << std::right;
        custCarRentStream << DLNumber << "         " << carInfo;
        custCarRentStream << std::endl;

        std::cout << " DONE " << std::endl;
    }
    invoice.push_back(temp);
    invoiceCreate(temp);
    std::string carAndCustomer = customerInfo + " " + carInfo;
    constructHistory(carAndCustomer, 5);
    sleep(4);
    ClearScreen();

}

void rentCheck(){
    char yesOrNo;
    do{
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t         RENTAL INFO \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        std::cout << "# Days" << "\t "  << "Return Date:" << "\t     " << std::left << std::setw(20) << "Customer Name: " << "\t" << std::right;
        std::cout << "DL#:" << "\t\t" << "Car Being Rented:" << std::endl;
        std::cout << "==============================================="
                     "====================================================" << std::endl;
        printFileToScreen("customerCarRentData.txt");
        sleep(5);
        std::cout << "Would you like to exit? (y/n)" << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
    } while(yesOrNo != 'y');



}

void rentUpdate(){
    char yesOrNo;
    do{
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t         RENTAL INFO \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        std::cout << "# Days" << "\t "  << "Return Date:" << "\t     " << std::left << std::setw(20) << "Customer Name: " << "\t" << std::right;
        std::cout << "DL#:" << "\t\t" << "Car Being Rented:" << std::endl;
        std::cout << "==============================================="
                     "====================================================" << std::endl;
        printFileToScreen("customerCarRentData.txt");
        sleep(5);
        std::cout << "Would you like to exit? (y/n)" << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
    } while(yesOrNo != 'y');

}

int constructHistory(const std::string& fileLine, int whichData){
    /*
     * 1. New Car added and information
     * 2. Removed Car from listing
     * 3. Customer added and information
     * 4. Removed Customer from listing
     * 5. Invoice Created
     */

    std::ofstream historyStream;
    historyStream.open("historyFile.txt", std::ios_base::app);
    historyStream << "=================================================================="
                         "======================================" << std::endl;
    historyStream << std::endl;
    historyStream << timeAndDate();
    switch (whichData) {
        case 1:
            historyStream << fileLine << "was added to the Vehicle Listings" << std::endl;
            break;
        case 2:
            historyStream << fileLine << "was removed from the Vehicle Listings" << std::endl;
            break;
        case 3:
            historyStream << fileLine << "was added to the Customer Listing" << std::endl;
            break;
        case 4:
            historyStream << fileLine << "was removed from the Customer Listing" << std::endl;
            break;
        case 5:
            historyStream << "Created an Invoice Receipt: "  << std::endl << fileLine << std::endl;
            break;
    }
    historyStream << std::endl;
    historyStream << "=================================================================="
                         "======================================" << std::endl;
    historyStream << std::endl;


return 0;

}

void printHistory(){
    char yesOrNo;
    do{
        std::cout << "\t\t\t\t\t------------------------------";
        std::cout << "\n\t\t\t\t\t         HISTORY \n";
        std::cout << "\t\t\t\t\t------------------------------\n\n";
        printFileToScreen("historyFile.txt");
        sleep(5);
        std::cout << "Would you like to exit? (y/n)" << std::endl;
        std::cout << ":";
        std::cin >> yesOrNo;
    } while(yesOrNo != 'y');

}

class mainService{
public:
    int options(){
        std::cin.clear();
        int option = 10;
        std::cout << "\t\t\t\t\t\tPlease Select An Option to continue: \n";
        std::cout << "\t\t\t\t\t\t      OPTIONS:";
        std::cout << "\n\t\t\t\t\t\t\t      1: Customer Information";
        std::cout << "\n\t\t\t\t\t\t\t      2: Available Car List";
        std::cout << "\n\t\t\t\t\t\t\t      3: Car Rent";
        std::cout << "\n\t\t\t\t\t\t\t      4: Customer Invoice";
        std::cout << "\n\t\t\t\t\t\t\t      5: History";
        std::cout << "\n\t\t\t\t\t\t\t      6: EXIT\n";
        std::cout << "\n\t\t\t\t\t\t\t       :";
        std::cin >> option;
        switch (option) {
            case 1: {
                loadingScreen();
                CustomerDetails obj;
                obj.customerInformation();
                break;
            }
            case 2:
                loadingScreen();
                carListScreen();
                break;
            case 3:
                loadingScreen();
                rentOptions();
                break;
            case 4:
                loadingScreen();
                invoiceHist();
                break;
            case 5:
                loadingScreen();
                printHistory();
                break;
            case 6:
                ClearScreen();
                std::cout << "\t\t\t\t\t\t\t\tExiting...\n";
                sleep(5);
                exit(EXIT_SUCCESS);
            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                options();
                break;
        }
        options();
        return 0;

    }

};

int main() {
    intro::introDisplay();
    intro login;
    login.loginSystem();
    mainService services;
    services.options();

    return 0;
}
