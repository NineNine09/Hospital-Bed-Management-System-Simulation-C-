#include <iostream>
#include <limits>
#include <string>
//By Nayan Subba

int main()
{
    std::string bed1 = "Empty", bed2 = "Empty" , bed3 = "Empty", bed4 = "Empty", bed5 = "Empty";
    int emptbed = 0;
    int choice = 0;

    std::cout << "Welcome to the Hospital Bed Management System!" <<std::endl;
    std::cout << "\t1. Check available beds" << std::endl;
    std::cout << "\t2. Admit a new patient" << std::endl;
    std::cout << "\t3. Discharge a patient" << std::endl;
    std::cout << "\t4. Exit" << std::endl;



    do{
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 4){
            std::cout << "Invalid choice! Enter a number between 1 and 4" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice){
            case 1:
                emptbed = 0;
                if (bed1.find("Empty") != std::string::npos){
                    emptbed = emptbed + 1;
                }
                if (bed2.find("Empty") != std::string::npos){
                    emptbed = emptbed + 1;
                }
                if (bed3.find("Empty") != std::string::npos){
                    emptbed = emptbed + 1;
                }
                if (bed4.find("Empty") != std::string::npos){
                    emptbed = emptbed + 1;
                }
                if (bed5.find("Empty") != std::string::npos){
                    emptbed = emptbed + 1;
                }
                std::cout << "Available beds: " << emptbed << std::endl;
                break;

            case 2:
                int bedassign;

                if (bed1 == "Occupied" && bed2 == "Occupied" && bed3 == "Occupied" && bed4 == "Occupied" && bed5 == "Occupied"){
                    std::cout << "No available beds! Please discharge a patient first." << std::endl;
                    break;
                }

                std::cout << "Which bed would you like to admit a patient (1-5)" << std::endl;
                std::cin >> bedassign;

                if (std::cin.fail() || bedassign < 1 || bedassign > 5){
                    std::cout << "Invalid choice! Enter a number between 1 and 5" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

               if (bedassign == 1){
                    if (bed1 == "Occupied"){
                        std::cout << "Bed1 is occupied" << std::endl;
                    }
                    else if(bed1 == "Empty"){
                        bed1 = "Occupied";
                        std::cout << "Bed1 has been assigned" << std::endl;
                    }
               }
               if (bedassign == 2){
                    if (bed2 == "Occupied"){
                        std::cout << "Bed2 is occupied" << std::endl;
                    }
                    else if(bed2 == "Empty"){
                        bed2 = "Occupied";
                        std::cout << "Bed2 has been assigned" << std::endl;
                    }
               }
               if (bedassign == 3){
                    if (bed3 == "Occupied"){
                        std::cout << "Bed3 is occupied" << std::endl;
                    }
                    else if(bed3 == "Empty"){
                        bed3 = "Occupied";
                        std::cout << "Bed3 has been assigned" << std::endl;
                    }
               }
               if (bedassign == 4){
                    if (bed4 == "Occupied"){
                        std::cout << "Bed4 is occupied" << std::endl;
                    }
                    else if(bed4 == "Empty"){
                        bed4 = "Occupied";
                        std::cout << "Bed4 has been assigned" << std::endl;
                    }
               }
               if (bedassign == 5){
                    if (bed5 == "Occupied"){
                        std::cout << "Bed5 is occupied" << std::endl;
                    }
                    else if(bed5 == "Empty"){
                        bed5 = "Occupied";
                        std::cout << "Bed5 has been assigned" << std::endl;
                    }
               }
                break;


            case 3:
                int discharge;

                if (bed1 == "Empty" && bed2 == "Empty" && bed3 == "Empty" && bed4 == "Empty" && bed5 == "Empty"){
                    std::cout << "All beds are already empty" << std::endl;
                    break;
                }

                std::cout << "Enter bed number 1-5 to discharge" << std::endl;
                std::cin >> discharge;

                if (std::cin.fail() || discharge < 1 || discharge > 5){
                    std::cout << "Invalid choice! Enter a number between 1 and 5" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }


                if (discharge == 1){
                    if (bed1 == "Empty"){
                        std::cout << "bed1 is empty already" << std::endl;
                    }
                    else{
                        bed1 = "Empty";
                        std::cout << "Bed1 has been freed" << std::endl;
                    }

                }
                else if (discharge == 2){
                    if (bed2 == "Empty"){
                        std::cout << "bed2 is empty already" << std::endl;
                    }
                    else{
                        bed2 = "Empty";
                        std::cout << "Bed2 has been freed" << std::endl;
                    }
                }
                else if (discharge == 3){
                    if (bed3 == "Empty"){
                        std::cout << "bed3 is empty already" << std::endl;
                    }
                    else{
                        bed3 = "Empty";
                        std::cout << "Bed3 has been freed" << std::endl;
                    }
                }
                else if (discharge == 4){
                    if (bed4 == "Empty"){
                        std::cout << "Bed4 is empty already" << std::endl;
                    }
                    else{
                        bed4 = "Empty";
                        std::cout << "Bed4 has been freed" << std::endl;
                    }
                }
                else if (discharge == 5){
                   if (bed5 == "Empty"){
                        std::cout << "bed5 is empty already" << std::endl;
                    }
                    else{
                        bed5 = "Empty";
                        std::cout << "Bed5 has been freed" << std::endl;
                    }
                }
                break;



            default:
                std::cout << "Exiting System" << std::endl;
                break;
            }


        }while (choice != 4);
    return 0;
}
