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
void addFarmerProfile(Farmer *user, int *size)
{
    if (*size >= MAX_USER) 
    {
        printf("No more users available\n");
        return;
    }

    printf("Input ID Number: ");
    scanf("%d", &user[*size].idNum);
    printf("Input First Name: ");
    scanf("%s", user[*size].fName);
    printf("Input Last Name: ");
    scanf("%s", user[*size].lName);
    printf("Input Username: ");
    scanf("%s", user[*size].username);
    printf("Input Password: ");
    scanf("%s", user[*size].password);

    (*size)++;
}
/*
decrypt and validate */
int farmerLogin(Farmer *user, int *size, Farmer *currentUser)
{
    String50 inputUser;
    String50 inputPassword;
    int i, index = -1;

    printf("Input username: ");
    scanf("%s", inputUser);
    printf("Input password: ");
    scanf("%s", inputPassword);

    for (i = 0; i < *size; i++)
    {
        if (strcmp(inputUser, user[i].username) == 0 &&
            strcmp(inputPassword, user[i].password) == 0)
        {
        	index = i;
            *currentUser = user[i];  // Copy to current user
        }
    }

    return index;
}

/*
reset + encrypt
*/
void forgotPassword(Farmer *user)
{
	int i, match = -1, nIndex;
	Farmer temp;
	String50 Name;
	
    printf("Enter username: ");
    scanf("%s", temp.username);
    
    printf("Verification:\n");
    printf("Enter first name : ");
    scanf("%s", temp.fName);
    printf("Enter family name: ");
    scanf("%s", temp.lName);
    
    
    for(i = 0; i < *size; i++)
    {
    	if(strcmp(temp.fName, user[i].fName) == 0 && strcmp(temp.lName, user[i].lName) == 0 && strcmp(temp.username,user[i].username) == 0)
    	{
    		match = i;
		}
	}
    
    if(match == -1)
    {
    	printf("Verification failed.\n");
	}
	else
	{
		printf("Verification success.\n Enter new password: ");
		scanf("%s", temp.password);
		
		strcpy(user[i].password, temp.password);
		
		printf("Password reset success.\n");
	}
    
    
}

int deleteFarmerProfile(Farmer *user, int *size)
{
    int index, i;
    int flag = 0;
    
    
    if(*size == 0)
    {
    	printf("No entries to delete.\n");
    	flag = 2;
	}
	else
	{
		printf("Enter farmer to delete (1 to %d): ", *size);
	    scanf("%d", &index);
	    index--;

	    if (index >= 0 && index < *size) 
		{
	        for(i = index; i < *size - 1; i++) 
			{
	            user[i] = user[i + 1];
	        }
	
	        // Clear last contact (optional)
	        user[*size - 1].fName = '\0';
	        user[*size - 1].lName = '\0';
	        user[*size - 1].idNum = 0;
	        user[*size - 1].password = '\0';
	        user[*size - 1].username = '\0';
	        
	
	        (*size)--;
	        printf("User deleted.\n");
	        flag = 1;
	    }
	}
	return flag;
}

int loadFarmerData(Farmer *user, int *size)
{
    
    int i = 0;
    int flag;

    FILE *bin;
    FILE *txt;
	 
	char binName[MAX_LENGTH];
	char fileName[MAX_LENGTH];
	char txtName[MAX_LENGTH];
	
	printf("Input file name. No extension (_file.dat): ");
	scanf("%s", fileName);
	
	strcpy(binName, fileName);
	strcat(binName, ".dat");
    bin = fopen(binName, "rb");

	//if loading from binary file
    if (bin == NULL) 
	{
        printf("Failed to open binary file.\n");
        flag = 0;
    }
	else
	{
		while (i < *size &&
           fread(user[i].idNum, sizeof(int), 1, bin) == 1 &&
           fread(user[i].fName, sizeof(String50), 1, bin) == 1 &&
           fread(user[i].lName, sizeof(String50), 1, bin) == 1 &&
           fread(user[i].password, sizeof(String50), 1, bin) == 1 &&
           fread(user[i].username, sizeof(String50), 1, bin) == 1) 
		{
        	i++;
    	}
    	
    	fclose(bin);
    	flag = 1;
    	
	}
    
	//if loading from text file
	
	strcpy(txtName, fileName);
	strcat(txtName, ".txt");
	txt = fopen(txtName, "r");
	
    if (txt == NULL)
    {
    	printf("Failed to open text file.")
	}
	else
	{
		while(i < *size && 
		fscanf(txt, "%d", &user[i].idNum) == 1 &&
		fscanf(txt, "%s", user[i].fName) == 1 &&
		fscanf(txt, "%s", user[i].lName) == 1 &&
		fscanf(txt, "%s", user[i].password) == 1 &&
		fscanf(txt, "%s", user[i].username) == 1)
		{
			i++;
		}
		
		fclose(txt);
		flag = 2;
	}
    
    
	*size = i;
    
    printf("%d contact(s) loaded from binary file.\n", *size);
    
    return flag;

}

void displayFarmerProfile(Farmer *user, int *size, Farmer *currentUser)
{
	
    int i;
    
    for(i = 0; i < *size; i++)
    {
    	if(strcmp(currentUser.username, user[i].username) == 0)
    	{
    		printf("Farmer Profile\n");
    		printf("ID Number: %d\n", user[i].idNum);
    		printf("First Name: %s\n", user[i].fName);
    		printf("Family Name: %s\n", user[i].lName);
    		printf("Username: %s\n", user[i].username);
    		printf("Password: %s\n", user[i].password);
		}
	}
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

int saveFarmerdata(Farmer *user, int *size)
{
      
    FILE *bin;
    FILE *txt;
    
    int i, flag;
    
	char binName[MAX_LENGTH];
	char txtName[MAX_LENGTH];
	char fileName[MAX_LENGTH];
	
	printf("Input file name. No extension (-file.dat/-file.exe): ");
	scanf("%s", fileName);
	
	strcpy(binName, fileName);
	strcpy(txtName, fileName);
	strcat(binName, ".dat");
	strcat(txtName, ".txt");
    
    
    bin = fopen(binName, "wb");
    txt = fopen(txtName, "w");
    
	if(!bin)
	{
		printf("Error in opening bin file.\n");
		flag = 0;
	}
    else if(!txt)
    {
    	printf("Error in opening txt file.\n");
    	flag = 0;
	}
	else
	{
		for(i = 0; i < *size; i++)
		{	
			fprintf(txt, "%d\n", user[i].idNum);
			fprintf(txt, "%s\n", user[i].fName);
			fprintf(txt, "%s\n", user[i].lName);
			fprintf(txt, "%s\n", user[i].password);
			fprintf(txt, "%s\n\n", user[i].username);
			
			fwrite(user[i].idNum, sizeof(int), 1, bin);
			fwrite(user[i].fName, sizeof(String50), 1, bin);
			fwrite(user[i].lName, sizeof(String50), 1, bin);
			fwrite(user[i].password, sizeof(String50), 1, bin);
			fwrite(user[i].username, sizeof(String50), 1, bin);
		}
		
    	flag = 1;
    	
    	fclose(txt);
    	fclose(bin);
	}
	
	return flag;
}

int saveCropData(CropRecord *crops, int *size)
{
      
    FILE *bin;
    FILE *txt;
    
    int i, flag;
    
	char binName[MAX_LENGTH];
	char txtName[MAX_LENGTH];
	char fileName[MAX_LENGTH];
	
	printf("Input file name. No extension (-file.dat/-file.exe): ");
	scanf("%s", fileName);
	
	strcpy(binName, fileName);
	strcpy(txtName, fileName);
	strcat(binName, ".dat");
	strcat(txtName, ".txt");
    
    
    bin = fopen(binName, "wb");
    txt = fopen(txtName, "w");
    
	if(!bin)
	{
		printf("Error in opening bin file.\n");
		flag = 0;
	}
    else if(!txt)
    {
    	printf("Error in opening txt file.\n");
    	flag = 0;
	}
	else
	{
		for(i = 0; i < *size; i++)
		{	
			fprintf(txt, "%s\n", crops[i].cropType);
			fprintf(txt, "Nickname: %s\n", crops[i].soilType);
			fprintf(txt, "Address: %s\n", crops[i].plantingDate);
			fprintf(txt, "Phone number: %s\n", crops[i].waterReq);
			fprintf(txt, "email: %s\n\n", crops[i].estYield);
			
			fwritecrops[i].cropType, sizeof(String50), 1, bin);
			fwrite(crops[i].soilType, sizeof(String50), 1, bin);
			fwrite(crops[i].plantingDate, sizeof(String50), 1, bin);
			fwrite(crops[i].waterReq, sizeof(String50), 1, bin);
			fwrite(crops[i].estYield, sizeof(String50), 1, bin);
		}
		
    	flag = 1;
    	
    	fclose(txt);
    	fclose(bin);
	}
	
	return flag;
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

void getValidateMenu(char *variable, char min, char max)
{
	do
		{
			printf("Enter: ");
			scanf(" %c", variable);

			if (*variable < min || *variable > max)
			{
				printf("Try Again. Only Enter %c-%c.\n", min, max);
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
