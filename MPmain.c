#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//#include "functions.c"

void getValidateMenu (int *variable, int min, int max);


int main()
{
	/* INITIALIZATION */
	int exitProgram = 0; //1 - save data, 2 - exit w/o saving
	int recordMenu = 0;
	int programMenu;
	int userMenu, cropMenu, sortMenu, usageMenu, invMenu, systemMenu, climateMenu;

	/* FLAGS */
	
	
	
	while (!exitProgram)
	{
		printf("\n+---------------------------------------+\n");
		printf("|\tSUSTAINABLE FARM TRACKER\t|\n");
		printf("+---------------------------------------+\n");
		printf("[1] Farmer Profile\n");
		printf("[2] Planting Records\n");
		printf("[3] Crop Yield & Water Usage\n");
		printf("[4] Irrigation & Inventory\n");
		printf("[5] Climate & Recommendations\n");
		printf("[6] Save & Exit\n");
		printf("+---------------------------------------+\n");
		getValidateMenu(&programMenu,1,6);

		switch(programMenu)
		{
			case 1: //farmer profile
				printf("\n----- FARMER PROFILE -----\n");
				printf("[1] Register New Farmer\n");
				printf("[2] Login\n");
				printf("[3] View Profile\n");
				printf("[4] Delete Farmer Account\n");
				printf("[5] Logout\n");
				printf("[0] Back to Main Menu\n");
				printf("--------------------------\n");
				getValidateMenu(&userMenu,0,5);

				switch(userMenu)
				{
					case 1: //register
						break;
					case 2: //login
						break;
					case 3: //view
						break;
					case 4: // delete
						break;
					case 5: //logout
						break;
					case 0:
						break;
				}
				break;
			case 2: //plant records
				do
				{
					printf("\n----- PLANTING RECORDS -----\n");
					printf("[1] Add New Planting Record\n");
					printf("[2] View All Records\n");
					printf("[3] Delete a Record\n");
					printf("[4] Search Crop Records\n");
					printf("[5] Sort Records\n");
					printf("[0] Back to Main Menu\n");
					printf("--------------------------\n");
					getValidateMenu(&recordMenu,0,5);

					switch(recordMenu)
					{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4: 
							printf("\nSEARCH CROP RECORDS\n");
							printf("[1] Search by Crop Name\n");
							printf("[2] Search by Crop Type\n");
							printf("[0] Back\n");
							getValidateMenu(&cropMenu,0,2);

							switch(cropMenu)
							{
								case 1:
									break;
								case 2:
									break;
								case 0:
									break;
							}
							break;
						case 5:
							printf("\nSORT RECORDS\n");
							printf("[1] Sort by Crop Name\n");
							printf("[2] Sort by Yield (Descending)\n");
							printf("[0] Back\n");
							getValidateMenu(&sortMenu,0,2);

							switch(sortMenu)
							{
								case 1:
									break;
								case 2:
									break;
								case 0:
									break;
							}
							break;
						case 0:
							
							break;
					}
				}while(recordMenu != 0);
				break;
			case 3: //yield & water
				printf("\n----- CROP YIELD & WATER USAGE -----\n");
				printf("[1] Input Crop Water Requirements\n");
				printf("[2] Compute Average Water Use\n");
				printf("[3] Compute Expected Yield\n");
				printf("[0] Back to Main Menu\n");
				printf("--------------------------\n");
				getValidateMenu(&usageMenu,0,5);

				switch(usageMenu)
				{
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 0:
						break;
				}
				break;
			case 4: //irrig & inv
				printf("\n----- IRRIGATION & INVENTORY -----\n");
				printf("[1] Log Irrigation Usage\n");
				printf("[2] View Resource Summary\n");
				printf("[3] Track Fertilizer and Seeds\n");
				printf("[0] Back to Main Menu\n");
				printf("--------------------------\n");
				getValidateMenu(&invMenu,0,5);

				switch(invMenu)
				{
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 0:
						break;
				}
				break;
			case 5: //climate & reco
				printf("\n----- CLIMATE & RECOMMENDATIONS -----\n");
				printf("[1] View Seasonal Planting Guide\n");
				printf("[2] Check Weather Simulation\n");
				printf("[3] Get Sustainable Practice Tips\n");
				printf("[0] Back to Main Menu\n");
				printf("--------------------------\n");
				getValidateMenu(&climateMenu,0,5);

				switch(climateMenu)
				{
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 0:
						break;
				}
				break;
			case 6: //save & exit
				printf("\n----- SYSTEM EXIT -----\n");
				printf("[1] Save Data\n");
				printf("[2] Exit Without Saving\n");
				printf("[0] Cancel\n");
				printf("--------------------------\n");
				getValidateMenu(&systemMenu,0,5);

				switch(systemMenu)
				{
					case 1: //save to file
						exitProgram = 1;
						break;
					case 2: // no save to file
						exitProgram = 1;
						break;
					case 0:
						break;
				}
				break;
		}
	}

	return 0;
}