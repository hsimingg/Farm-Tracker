#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "functions.c"


int main()
{
    /* INITIALIZATION */
    int exitProgram = 0;
    int programMenu;
    int userMenu, cropMenu, recordMenu, sortMenu, usageMenu, invMenu, systemMenu, climateMenu;

    Farmer userList[MAX_USER];        // Farmer list
    int userCount = 0;                // Number of users
    Farmer currentUser;               // Logged-in farmer
    int isLoggedIn = 0;

    Croprecord cropList[MAX_CROP];
    int cropCount = 0;

    while (!exitProgram)
    {
        if (!isLoggedIn)
        {
            printf("\n+---------------------------------------+\n");
            printf("|\tSUSTAINABLE FARM TRACKER\t|\n");
            printf("+---------------------------------------+\n");
            printf("[1] Register New Farmer\n");
            printf("[2] Login\n");
            printf("[3] Forgot Password\n")
            printf("[0] Exit Program\n");
            printf("+---------------------------------------+\n");
            getValidateMenu(&userMenu, 0, 3);

            switch (userMenu)
            {
            case 1:
                addFarmerProfile(userList, &userCount);
                break;
            case 2:
                if (farmerLogin(userList, &userCount, &currentUser) != -1)
                {
                    printf("Login successful. Welcome, %s!\n", currentUser.fName);
                    isLoggedIn = 1;
                }
                else
                {
                    printf("Login failed. Please try again.\n");
                }
                break;
            case 3:
            	forgotPassword(userList);
            	break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                exitProgram = 1;
                break;
            }
        }
        else
        {
            // Main Menu Loop (Requires Login)
            printf("\n+---------------------------------------+\n");
            printf("|\tSUSTAINABLE FARM TRACKER\t|\n");
            printf("+---------------------------------------+\n");
            printf("[1] Farmer Profile\n");
            printf("[2] Planting Records\n");
            printf("[3] Crop Yield & Water Usage\n");
            printf("[4] Irrigation & Inventory\n");
            printf("[5] Climate & Recommendations\n");
            printf("[6] Logout\n");
            printf("[7] Save & Exit\n");
            printf("+---------------------------------------+\n");
            getValidateMenu(&programMenu, 1, 7);

            switch (programMenu)
            {
            case 1: // Farmer Profile
                printf("\n----- FARMER PROFILE -----\n");
                printf("[1] View Profile\n");
                printf("[2] Delete Farmer Account\n");
                printf("[0] Back to Main Menu\n");
                getValidateMenu(&userMenu, 0, 2);

                switch (userMenu)
                {
                case 1:
                    displayFarmerProfile(userList, &userCount); 
                    break;
                case 2:
                    deleteFarmerProfile(userList, &userCount); 
                    break;
                case 0:
                    break;
                }
                break;

            case 2: // Planting Records
                do 
                {
                    printf("\n----- PLANTING RECORDS -----\n");
                    printf("[1] Add New Planting Record\n");
                    printf("[2] View All Records\n");
                    printf("[3] Delete a Record\n");
                    printf("[4] Search Crop Records\n");
                    printf("[5] Sort Records\n");
                    printf("[0] Back to Main Menu\n");
                    getValidateMenu(&recordMenu, 0, 5);

                    switch (recordMenu)
                    {
                    case 1: addCropRecord(); break;
                    case 2: displayCropRecord(); break;
                    case 3: deleteCropRecord(); break;
                    case 4:
                        printf("\nSEARCH CROP RECORDS\n");
                        printf("[1] Search by Crop Name\n");
                        printf("[2] Search by Crop Type\n");
                        printf("[0] Back\n");
                        getValidateMenu(&cropMenu, 0, 2);
                        switch (cropMenu)
                        {
                        case 1: searchCropRecord(); break;
                        case 2: searchCropRecord(); break;
                        case 0: break;
                        }
                        break;
                    case 5:
                        printf("\nSORT RECORDS\n");
                        printf("[1] Sort by Crop Name\n");
                        printf("[2] Sort by Yield (Descending)\n");
                        printf("[0] Back\n");
                        getValidateMenu(&sortMenu, 0, 2);
                        switch (sortMenu)
                        {
                        case 1: sortCropRecord(); break;
                        case 2: sortCropRecord(); break;
                        case 0: break;
                        }
                        break;
                    }
                } while (recordMenu != 0);
                break;

            case 3: // Crop Yield & Water Usage
                printf("\n----- CROP YIELD & WATER USAGE -----\n");
                printf("[1] Input Crop Water Requirements\n");
                printf("[2] Compute Average Water Use\n");
                printf("[3] Compute Expected Yield\n");
                printf("[0] Back to Main Menu\n");
                getValidateMenu(&usageMenu, 0, 3);

                switch (usageMenu)
                {
                case 1: inputWaterData(); break;
                case 2: computeAverageWaterUse(); break;
                case 3: computeExpectedYield(); break;
                case 0: break;
                }
                break;

            case 4: // Irrigation & Inventory
                printf("\n----- IRRIGATION & INVENTORY -----\n");
                printf("[1] Log Irrigation Usage\n");
                printf("[2] View Resource Summary\n");
                printf("[3] Track Fertilizer and Seeds\n");
                printf("[0] Back to Main Menu\n");
                getValidateMenu(&invMenu, 0, 3);

                switch (invMenu)
                {
                case 1: track_IrrigationUsage(); break;
                case 2: track_ResourceUsage(); break;
                case 3: 
                    addInventoryItem();
                    updateInventoryItem();
                    displayInventory();
                    deleteInventoryItem();
                    break;
                case 0: break;
                }
                break;

            case 5: // Climate & Recommendations
                printf("\n----- CLIMATE & RECOMMENDATIONS -----\n");
                printf("[1] View Seasonal Planting Guide\n");
                printf("[2] Check Weather Simulation\n");
                printf("[3] Get Sustainable Practice Tips\n");
                printf("[0] Back to Main Menu\n");
                getValidateMenu(&climateMenu, 0, 3);

                switch (climateMenu)
                {
                case 1: recommendPractices(); break;
                case 2: weatherInformation(); break;
                case 3: recommendPractices(); break;
                case 0: break;
                }
                break;

            case 6: // Logout
                printf("You have been logged out.\n");
                isLoggedIn = 0;
                break;

            case 7: // Save & Exit
                printf("\n----- SYSTEM EXIT -----\n");
                printf("[1] Save Data\n");
                printf("[2] Exit Without Saving\n");
                printf("[0] Cancel\n");
                getValidateMenu(&systemMenu, 0, 2);

                switch (systemMenu)
                {
                case 1:
                    saveFarmerdata();
                    saveCropData();
                    exitProgram = 1;
                    printf("Data saved. Goodbye!\n");
                    break;
                case 2:
                    exitProgram = 1;
                    printf("Exiting without saving. Goodbye!\n");
                    break;
                case 0:
                    break;
                }
                break;
            }
        }
    }

    return 0;
}
