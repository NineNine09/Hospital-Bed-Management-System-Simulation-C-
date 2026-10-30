#include <iostream>
#include <fstream>
#include <limits>

//By Nayan Subba

// Function prototypes
void loadBeds(int &, int &, int &, int &, int &);
void saveBeds(int, int, int, int, int);
int countAvailableBeds(int, int, int, int, int);
void admitPatient(int &, int &, int &, int &, int &);
void dischargePatient(int &, int &, int &, int &, int &);
void displayBeds(int , int , int , int , int);


int main() {
    int bed1 = 0, bed2 = 0, bed3 = 0, bed4 = 0, bed5 = 0;
    int choice;

    // Load initial bed statuses from file
    loadBeds(bed1, bed2, bed3, bed4, bed5);

    do {
        // Display menu options
        std::cout << "\nHospital Bed Management System\n";
        std::cout << "1. Check available beds\n";
        std::cout << "2. Admit a new patient\n";
        std::cout << "3. Discharge a patient\n";
        std::cout << "4. Exit\n" << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> choice;
        std::cout <<'\n';




        // Validate the user input
        while (std::cin.fail() || choice < 1 || choice > 4) {
            std::cout << "Invalid choice! Enter a positive choice number between 1 and 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
            std::cout <<'\n';
        }

        // Execute user's choice
        if (choice == 1) {
            displayBeds(bed1, bed2, bed3, bed4, bed5);
            std::cout << std::endl << countAvailableBeds(bed1, bed2, bed3, bed4, bed5) << " beds are available.\n";
        } else if (choice == 2) {
            admitPatient(bed1, bed2, bed3, bed4, bed5);
        } else if (choice == 3) {
            dischargePatient(bed1, bed2, bed3, bed4, bed5);
        }

    } while (choice != 4);
    std::cin.clear();

    // Save final bed statuses to file
    saveBeds(bed1, bed2, bed3, bed4, bed5);
    std::cout << "Program ended. Bed statuses saved.\n";

    return 0;
}

// Implement your functions below

// TODO: Implement loadBeds
void loadBeds(int &bed1,int &bed2,int &bed3,int &bed4,int &bed5){
    std::ifstream file("Beds1.txt");

    if (!file.is_open()){
        std::cout << "Can't open file.";
        file.close();
        return;
    }

    file >> bed1 >> bed2 >> bed3 >> bed4 >> bed5;
    file.close();


}

// TODO: Implement saveBeds
void saveBeds(int bed1,int bed2,int bed3,int bed4,int bed5){
    std::ofstream file("Beds1.txt");

    if (!file.is_open()){
        std::cout << "Can't save file.";
        file.close();
        return;
    }

    file << bed1 << " " << bed2 << " " << bed3 << " " << bed4 << " " << bed5;
    file.close();


}

// TODO: Implement countAvailableBeds
int countAvailableBeds(int bed1,int bed2,int bed3,int bed4,int bed5){
    int emptycount = 0;
    if (bed1 == 0){emptycount++;}
    if (bed2 == 0){emptycount++;}
    if (bed3 == 0){emptycount++;}
    if (bed4 == 0){emptycount++;}
    if (bed5 == 0){emptycount++;}
    return emptycount;


}

// TODO: Implement admitPatient
void admitPatient(int &bed1,int &bed2,int &bed3,int &bed4,int &bed5){

    if (bed1 == 1 && bed2 == 1 && bed3 == 1 && bed4 == 1 && bed5 == 1){
    std::cout <<'\n';
    displayBeds(bed1, bed2, bed3, bed4, bed5);
    std::cout << "\nAll beds are occupied. Please discharge a patient first." << std::endl;
    return;
    }

    int ch;
    do{
    displayBeds(bed1, bed2, bed3, bed4, bed5);
    std::cout <<'\n';
    std::cout << "\n>> Enter 6 to exit back to menu << \nChoose beds 1-5 to admit the patient in: " ;
    std::cin >> ch;
    std::cout <<'\n';

    while(std::cin.fail() || ch < 1 || ch > 6 ){
        std::cout << "Invalid, Please enter a positive choice number 1-6: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> ch;
    }

    std::cin.clear();
    switch (ch){
        case 1:
            if (bed1 == 0){
                bed1 = 1;
                std::cout << "Patient has been admitted to Bed 1" << std::endl;
            }
            else{
                std::cout << "Bed 1 is occupied" << std::endl;
            }
            break;
        case 2:
            if (bed2 == 0){
                bed2 = 1;
                std::cout << "Patient has been admitted to Bed 2" << std::endl;
            }
            else{
                std::cout << "Bed 2 is occupied" << std::endl;
            }
            break;
        case 3:
            if (bed3 == 0){
                bed3 = 1;
                std::cout << "Patient has been admitted to Bed 3" << std::endl;
            }
            else{
                std::cout << "Bed 3 is occupied" << std::endl;
            }
            break;
        case 4:
            if (bed4 == 0){
                bed4 = 1;
                std::cout << "Patient has been admitted to Bed 4" << std::endl;
            }
            else{
                std::cout << "Bed 4 is occupied" << std::endl;
            }
            break;
        case 5:
            if (bed5 == 0){
                bed5 = 1;
                std::cout << "Patient has been admitted to Bed 5" << std::endl;
            }
            else{
                std::cout << "Bed 5 is occupied" << std::endl;
            }
            break;
         case 6:
            std::cout <<">> Going to back menu <<" << std::endl;
            break;
        }

    } while (ch != 6);


}

// TODO: Implement dischargePatient
void dischargePatient(int &bed1,int &bed2,int &bed3,int &bed4,int &bed5){
    if (bed1 == 0 && bed2 == 0 && bed3 == 0 && bed4 == 0 && bed5 == 0){
    displayBeds(bed1, bed2, bed3, bed4, bed5);
    std::cout << "\nAll beds are empty. Please admit a patient first." << std::endl;
    return;
    }

    int ch;

    do{

    displayBeds(bed1, bed2, bed3, bed4, bed5);
    std::cout <<'\n';
    std::cout << "\n>> Enter 6 to exit back to menu << \nChoose beds 1-5 to discharge the patient from: " ;
    std::cin >> ch;
    std::cout <<'\n';

    while(std::cin.fail() || ch < 1 || ch > 6 ){
        std::cout << "Invalid, Please enter a positive choice number 1-6: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> ch;
    }

    std::cin.clear();
    switch (ch){
        case 1:
            if (bed1 == 1){
                bed1 = 0;
                std::cout << "Bed 1 has been discharged" << std::endl;
            }
            else{
                std::cout << "Bed 1 is already empty" << std::endl;
            }
            break;
        case 2:
            if (bed2 == 1){
                bed2 = 0;
                std::cout << "Bed 2 has been discharged" << std::endl;
            }
            else{
                std::cout << "Bed 2 is already empty" << std::endl;
            }
            break;
        case 3:
            if (bed3 == 1){
                bed3 = 0;
                std::cout << "Bed 3 has been discharged" << std::endl;
            }
            else{
                std::cout << "Bed 3 is already empty" << std::endl;
            }
            break;
        case 4:
            if (bed4 == 1){
                bed4 = 0;
                std::cout << "Bed 4 has been discharged" << std::endl;
            }
            else{
                std::cout << "Bed 4 is already empty" << std::endl;
            }
            break;
        case 5:
            if (bed5 == 1){
                bed5 = 0;
                std::cout << "Bed 5 has been discharged" << std::endl;
            }
            else{
                std::cout << "Bed 5 is already empty" << std::endl;
            }
            break;
        case 6:
            std::cout <<">> Going to back menu <<" << std::endl;
            break;
        }

    }while (ch != 6);
}


void displayBeds(int bed1, int bed2, int bed3, int bed4, int bed5){
    if (bed1 == 1){
        std::cout << ">> Bed 1: Occupied << ";
    }
    else{
        std::cout << "\n>> Bed 1: Empty <<" ;
    }
    if (bed2 == 1){
        std::cout << "\n>> Bed 2: Occupied << ";
    }
    else{
        std::cout << "\n>> Bed 2: Empty <<" ;
    }
    if (bed3 == 1){
        std::cout << "\n>> Bed 3: Occupied << ";
    }
    else{
        std::cout << "\n>> Bed 3: Empty <<" ;
    }
    if (bed4 == 1){
        std::cout << "\n>> Bed 4: Occupied << ";
    }
    else{
        std::cout << "\n>> Bed 4: Empty <<" ;
    }
    if (bed5 == 1){
        std::cout << "\n>> Bed 5: Occupied << ";
    }
    else{
        std::cout << "\n>> Bed 5: Empty <<" ;
    }

}
