#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "defs.h"

//! FARMER PROFILES

/*

/*
with password encryption
*/
int addFarmerProfile()
{ 
	//return 1 if success
}

/*
decrypt and validate */
int farmerLogin()
{
	//return struct pointer for validation
}

/*
reset + encrypt
*/
void forgotPassword()
{

}

void deleteFarmerProfile()
{

}

int loadFarmerData()
{
	
	
	return; //return 1 if success
}

void displayFarmerProfile()
{

}


/*
	This function loads cropdata and farmerdata from a .txt file into their proper structures.

*/

//! PLANTING RECORDS

void addCropRecord()
{
	
}

int validateCropType()
{

}


void displayCropRecord()
{

}

void deleteCropRecord()
{

}

/*
must use sort algorithm + w recursion
sort records by yield or crop name
*/
void sortCropRecord()
{
	
}

/*
search by crop name, type, etc
search by crop type: food crops, feed crops
*/
void searchCropRecord()
{

}


int loadCropData()
{
	
}

//! WATER REQUIREMENTS

/*
average water use*/
int computeWaterUsage()
{

}

void computeAverageWaterUse()
{

}

/*
water requirements and water quality
 */
void inputWaterData()
{

}


//! YIELD PLANTING

/*
expected yield of optimal planting schedule
average yield per crop
*/
int computeExpectedYield()
{

}

void computeAverageYield()
{

}

//! RESOURCES

void track_IrrigationUsage()
{

}

//! WEATHER

/*
weather and climate information
*/
void weatherInformation()
{

}

/*

*/



//! SYSTEM

int saveFarmerdata()
{
	
}

int saveCropData()
{
	
}

void exportReporttoFile()
{

}

void encryptPassword()
{

}

void decryptPassword()
{

}

//? validate / test

void runTestDataSimulation()
{

}

void getValidateMenu(int *variable, int min, int max)
{
	do
		{
			printf("Enter: ");
			scanf("%d", variable);

			if (*variable < min || *variable > max)
			{
				printf("Try Again. Only Enter %d-%d.\n", min, max);
			}

		} while(*variable < min || *variable > max);
}


// ? OPTIONAL

void updateCropRecord()
{

}

void recommendPractices()
{

}

void track_ResourceUsage()
{

}

/*
fertilizer, seeds, etc
*/
void addInventoryItem()
{

}

void updateInventoryItem()
{

}

void displayInventory()
{

}

void deleteInventoryItem()
{

}

*/

*/