#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "defs.h"

//! FARMER PROFILES

/*
	This function adds a farmer profile by accepting inputs from the user
	and stores them in a data structure 

	@param *user: pointer to the address of the structure userList
	@param *size: pointer to the address of userCount
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
    This function logs in a farmer using either username or ID number
    with a matching password. On success, it copies the record to currentUser
    and returns its index; otherwise, returns -1.

    @param  *user       : pointer to the address of the structure userList
    @param  *size       : pointer to the address of userCount
    @param  *currentUser: pointer where the logged-in user data will be copied
    @return index of the logged-in user, or -1 if not found
*/
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
    This function resets a farmer's password after verifying
    username + first name + last name.

    @param *user: pointer to the address of the structure userList
    @param *size: pointer to the address of userCount
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


/*
    This function deletes a farmer profile based on a 1-based index
    provided by the user.

    @param *user: pointer to the address of the structure userList
    @param *size: pointer to the address of userCount
    @return 1 if deleted, 2 if list empty, 0 if invalid index
*/
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


/*
    This function loads farmer data from a text file named "<fileBase>.txt".
    Each farmer entry is expected to contain 5 tokens per line:
    idNum fName lName password username

    @param *user    : pointer to the address of the structure userList
    @param *size    : pointer to the address of userCount (updated on success)
    @param  *fileBase: base file name without extension
    @return 1 on success, 0 on failure
*/
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


/*
	This function displays the profile of the current user.

 	@param *user    : pointer to the address of the structure userList
   	@param *size    : pointer to the address of userCount (updated on success)
    	@param  *currentUser: pointer to the address of the currentUser 
*/
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


//! PLANTING RECORDS

/*
    This function adds a crop record by accepting inputs from the user
    and stores them in a data structure.

    @param *crops: pointer to the address of the array cropList
    @param *size : pointer to the address of cropCount
*/
void addCropRecord(CropRecord *crop, int *size)
{

	int flag;

    if (*size >= MAX_CROP)
    {
        printf("No more records available.\n");
        flag = 0;
    }
    else
    {
        flag = 1;
    }

    if (flag == 1)
    {
    	printf("Enter crop name: ");
	    scanf("%s", crop[*size].cropName);
	    printf("Enter area used (hectares): ");
	    scanf("%f", &crop[*size].areaused);
	    printf("Enter planted month (e.g., Jan, February): ");
	    scanf("%s", crop[*size].plantedMonth);
	    printf("Enter planted day (use -1 if N/A): ");
	    scanf("%f", &crop[*size].plantedDay);
	    printf("Enter planted year (use -1 if N/A): ");
	    scanf("%f", &crop[*size].plantedYear);
	    printf("Enter water used in m^3 (use -1 if N/A): ");
	    scanf("%f", &crop[*size].waterUsed);
	    printf("Enter fertilizer used in kg (use -1 if N/A): ");
	    scanf("%f", &crop[*size].fertilizerUsed);
	    printf("Enter soil used: ");
	    scanf("%s", crop[*size].soilUsed);
	    printf("Enter harvest date (e.g., 2025-08-30 or N/A): ");
	    scanf("%s", crop[*size].harvestDate);
	    printf("Enter yield in tons (use -1 if N/A): ");
	    scanf("%f", &crop[*size].yieldUsed);
	}

    (*size)++;
    printf("Record added.\n");
    
}


/*
    This function displays crop records filtered by crop name.
    If multiple records share the same name, all are shown.

    @param *crop: pointer to the address of the array cropList
    @param *size: pointer to the address of cropCount
*/
void displayCropRecord(cropRecord *crop, int *size)
{
    
    for (i = 0; i < *size; i++)
    {
        if (strcmp(key, crop[i].cropName) == 0)
        {
            printf("Crop name: %s\n", crop[i].cropName);
            printf("Area used (ha): %.2f\n", crop[i].areaused);
            printf("Planted month: %s\n", crop[i].plantedMonth);
            printf("Planted day: %.0f\n", crop[i].plantedDay);
            printf("Planted year: %.0f\n", crop[i].plantedYear);
            printf("Water used (m^3): %.2f\n", crop[i].waterUsed);
            printf("Fertilizer used (kg): %.2f\n", crop[i].fertilizerUsed);
            printf("Soil used: %s\n", crop[i].soilUsed);
            printf("Harvest date: %s\n", crop[i].harvestDate);
            printf("Yield (tons): %.2f\n\n", crop[i].yieldUsed);
            found = 1;
        }
    }

}


/*
    This function deletes a crop record by index (1-based).

    @param *crops: pointer to the address of the array cropList
    @param *size : pointer to the address of cropCount
    @return 1 if deleted, 2 if list empty, 0 if invalid index
*/
int deleteCropRecord(cropRecord *crop, int *size)
{
    int index, i, flag;

    flag = 0;

    if (*size == 0)
    {
        printf("No entries to delete.\n");
        flag = 2;
    }
    else
    {
        printf("Enter record to delete (1 to %d): ", *size);
        scanf("%d", &index);
        index = index - 1;

        if (index >= 0 && index < *size)
        {
            for (i = index; i < *size - 1; i++)
            {
                crop[i] = crop[i + 1];
            }

            /* Clear last slot (optional) */
            crop[*size - 1].cropName[0] = '\0';
            crop[*size - 1].areaused = -1.0f;
            crop[*size - 1].plantedMonth[0]= '\0';
            crop[*size - 1].plantedDay = -1.0f;
            crop[*size - 1].plantedYear = -1.0f;
            crop[*size - 1].waterUsed = -1.0f;
            crop[*size - 1].fertilizerUsed= -1.0f;
            crop[*size - 1].soilUsed[0] = '\0';
            crop[*size - 1].harvestDate[0]= '\0';
            crop[*size - 1].yieldUsed = -1.0f;

            (*size) = (*size) - 1;
            printf("Record deleted.\n");
            flag = 1;
        }
        else
        {
            printf("Invalid index.\n");
            flag = 0;
        }
    }

    return flag;
    
}


/*
    This function sorts crop records either by name (ascending)
    or by estimated yield (descending).

    @param *crops         : pointer to the address of the array cropList
    @param *size          : pointer to the address of cropCount
    @param byNameElseYield: 1 to sort by name, 0 to sort by yield desc
*/
void sortCropRecord(CropRecord *crop, int *size, int byNameElseYield)
{
	
	CropRecord temp;
	int i, j;
	
    if (*size <= 1)
    {
        printf("Nothing to sort.\n");
    }
    else if (byNameElseYield == 1)
    {
        for (i = 0; i < *size - 1; i++)
        {
            for (j = 0; j < *size - 1 - i; j++)
            {
                if (strcmp(crop[j].cropName, crop[j + 1].cropName) > 0)
                {
                    temp = crop[j];
                    crop[j] = crop[j + 1];
                    crop[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < *size - 1; i++)
        {
            for (j = 0; j < *size - 1 - i; j++)
            {
                if (crops[j].avgYield < crops[j + 1].avgYield)
                {
                    temp = crop[j];
                    crop[j] = crops[j + 1];
                    crop[j + 1] = temp;
                }
            }
        }
    }

    printf("Records sorted.\n");
    
}


/*
    This function searches crop records by crop name or soil used
    and displays all matches.

    @param *crop: pointer to the address of the array cropList
    @param *size: pointer to the address of cropCount
    @return 1 if at least one record found, 0 if none, -1 if list empty
*/
int searchCropRecord(cropRecord *crop, int *size)
{
    char choice;
    String50 key;
    int i, found, flag;

    flag = 0;
    found = 0;

    if (*size == 0)
    {
        printf("No crop records.\n");
        flag = -1;
    }
    else
    {
        printf("SEARCH CROP RECORDS\n");
        printf("[1] Search by Crop Name\n");
        printf("[2] Search by Soil Used\n");
        printf("[0] Back\n");
        scanf(" %c", &choice);

        if (choice == '0')
        {
            /* user chose back; nothing to search */
            flag = 0;
        }
        else
        {
            printf("Enter search text: ");
            scanf("%s", key);

            i = 0;
            while (i < *size)
            {
                if ((choice == '1' && strcmp(key, crop[i].cropName) == 0) ||
                    (choice == '2' && strcmp(key, crop[i].soilUsed) == 0))
                {
                    printf("Crop name: %s\n", crop[i].cropName);
                    printf("Area used (ha): %.2f\n", crop[i].areaused);
                    printf("Planted month: %s\n", crop[i].plantedMonth);
                    printf("Planted day: %.0f\n", crop[i].plantedDay);
                    printf("Planted year: %.0f\n", crop[i].plantedYear);
                    printf("Water used (m^3): %.2f\n", crop[i].waterUsed);
                    printf("Fertilizer used (kg): %.2f\n", crop[i].fertilizerUsed);
                    printf("Soil used: %s\n", crop[i].soilUsed);
                    printf("Harvest date: %s\n", crop[i].harvestDate);
                    printf("Yield (tons): %.2f\n\n", crop[i].yieldUsed);
                    found = 1;
                }
                i = i + 1;
            }

            if (found == 0)
            {
                printf("No matching records found.\n");
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
    }

    return flag;
}


/*
    This function loads preloaded crop recommendations from a text file
    named "<fileBase>.txt". Each line must contain 8 space-separated fields:
    cropName soilRecommend monthsRecommend minWater maxWater fertilizer expectedDuration expectedYield

    @param *pre : pointer to the address of the array of crop_Preloaded
    @param *size: pointer to the address of the count to be filled (max MAX_CROP)
    @return 1 on success, 0 on failure to open/read
*/
int loadCropData(crop_Preloaded *pre, int *size)
{
    FILE *txt;
    char fileBase[MAX_LENGTH];
    char txtName[256];
    int i, flag;

    /* initialize */
    i = 0;
    flag = 0;

    printf("Input file name. No extension (-file.txt): ");
    scanf("%s", fileBase);

    /* build "<base>.txt" */
    strcpy(txtName, fileBase);
    strcat(txtName, ".txt");

    txt = fopen(txtName, "r");
    if (txt == NULL)
    {
        printf("Failed to open text file.\n");
        flag = 0;
    }
    else
    {
        /* read until EOF or MAX_CROP reached */
        while (i < MAX_CROP &&
                    fscanf(txt, "%s", pre[i].cropName) == 1 &&
                    fscanf(txt, "%s", pre[i].soilRecommend) == 1 &&
                    fscanf(txt, "%f", &pre[i].expectedYield) == 1 &&
                    fscanf(txt, "%f", &pre[i].minWaterRecommend) == 1 &&
                    fscanf(txt, "%f", &pre[i].maxWaterRecommend) == 1 &&
                    fscanf(txt, "%f", &pre[i].fertilizerRecommend) == 1 &&
                    fscanf(txt, "%f", &pre[i].expectedDuration) == 1 &&
                    fscanf(txt, "%s", pre[i].monthsRecommend) == 1)
        {
            i++;
        }

        fclose(txt);
        flag = 1;
    }

    *size = i;
    printf("%d record(s) loaded for preloaded crops.\n", *size);

    return flag;
}


/*
	This function displays all preloaded crop data.

 	@param *crop: pointer to the address of the array of crop_Preloaded
	@param *size: pointer to the address of the preloaded cropCount
*/  
void displayPreLoad(crop_Preload *pre, int *size)
{
	
	int i;
	
	while( i < *size)
	{
		printf("%s ", pre[i].cropName);
        	printf("%s ", pre[i].soilRecommend);
		printf("%.2f ", pre[i].expectedYield);
		printf("%.2f ", pre[i].minWaterRecommend);
	        printf("%.2f ", pre[i].maxWaterRecommend);
	        printf("%.2f ", pre[i].fertilizerRecommend);
	        printf("%.2f ", pre[i].expectedDuration);
	        printf("%s\n", pre[i].monthsRecommend);
		
		i++;
	}
	
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

/*
    This function saves all farmer records to two files:
    a binary file "<fileBase>.dat" and a text file "<fileBase>.txt".
    The text file is human-readable; the binary file is compact.

    @param *user : pointer to the address of the array of Farmer
    @param *size : pointer to the address of the count of Farmer records
    @return flag : 1 on success, 0 on failure to open at least one file
*/
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


/*
    This function saves all crop records to two files:
    a binary file "<fileBase>.dat" and a text file "<fileBase>.txt".
    The text file is human-readable; the binary file is compact.

    @param *crops: pointer to the address of the array of cropRecord
    @param *size : pointer to the address of cropCount
    @return flag : 1 on success, 0 on failure to open at least one file
*/
int saveCropData(CropRecord *crop, int *size)
{
      
    FILE *bin;
    FILE *txt;
    
    int i, flag;
    
	char binName[MAX_LENGTH];
	char txtName[MAX_LENGTH];
	char fileName[MAX_LENGTH];
	
	printf("Input file name. No extension (.dat/.exe): ");
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
            //TEXT OUTPUT (human-readable)
            fprintf(txt, "Crop name: %s\n", crop[i].cropName);
            fprintf(txt, "Area used (ha): %.2f\n", crop[i].areaused);
            fprintf(txt, "Planted month: %s\n", crop[i].plantedMonth);
            fprintf(txt, "Planted day: %.0f\n", crop[i].plantedDay);
            fprintf(txt, "Planted year: %.0f\n", crop[i].plantedYear);
            fprintf(txt, "Water used (m^3): %.2f\n", crop[i].waterUsed);
            fprintf(txt, "Fertilizer used (kg): %.2f\n", crop[i].fertilizerUsed);
            fprintf(txt, "Soil used: %s\n", crop[i].soilUsed);
            fprintf(txt, "Harvest date: %s\n", crop[i].harvestDate);
            fprintf(txt, "Yield (tons): %.2f\n\n", crop[i].yieldUsed);

            //BINARY OUTPUT (fixed layout matches struct order)
            fwrite(crop[i].cropName, sizeof(String50), 1, bin);
            fwrite(&crop[i].areaused, sizeof(float), 1, bin);
            fwrite(crop[i].plantedMonth, sizeof(String50), 1, bin);
            fwrite(&crop[i].plantedDay, sizeof(float), 1, bin);
            fwrite(&crop[i].plantedYear, sizeof(float), 1, bin);
            fwrite(&crop[i].waterUsed, sizeof(float), 1, bin);
            fwrite(&crop[i].fertilizerUsed, sizeof(float), 1, bin);
            fwrite(crop[i].soilUsed, sizeof(String50), 1, bin);
            fwrite(crop[i].harvestDate, sizeof(String50), 1, bin);
            fwrite(&crop[i].yieldUsed, sizeof(float), 1, bin);
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


// caesar cipher helper functions

void encryptStr(String50 str, int key)
{
	
    for (int i = 0; str[i] != '\0'; i++) 
	{
        char ch = str[i];
        
        if (ch >= 'A' && ch <= 'Z')
        {
        	str[i] = ((ch - 'A' + key) % 26) + 'A';
		}
        else if (ch >= 'a' && ch <= 'z')
        {
        	str[i] = ((ch - 'a' + key) % 26) + 'a';
		}
        else if (ch >= '0' && ch <= '9')
        {
        	str[i] = ((ch - '0' + key) % 10) + '0';
		}
    }	
}

void decryptStr(String50 str, int key)
{
	
    for (int i = 0; str[i] != '\0'; i++) 
	{
        char ch = str[i];
        
        if (ch >= 'A' && ch <= 'Z')
        {
        	str[i] = ((ch - 'A' - key + 26) % 26) + 'A';
		}
        else if (ch >= 'a' && ch <= 'z')
        {
        	str[i] = ((ch - 'a' - key + 26) % 26) + 'a';
		} 
        else if (ch >= '0' && ch <= '9')
        {
        	str[i] = ((ch - '0' - key + 10) % 10) + '0';
		} 
    }
    
}


void encryptUsers(Farmer *user, int *size, int key)
{
	   
	for (int i = 0; i < *size; i++)
    {
        encryptStr(user[i].idNum, key);
        encryptStr(user[i].fName, key);
        encryptStr(user[i].lName, key);
        encryptStr(user[i].username, key);
        encryptStr(user[i].password, key);
    }
    
}

void decrpytUsers(Farmer *user, int *size, int key)
{
	
    for (int i = 0; i < *size; i++)
    {
        decryptStr(user[i].idNum, key);
        decryptStr(user[i].fName, key);
        decryptStr(user[i].lName, key);
        decryptStr(user[i].username, key);
        decryptStr(user[i].password, key);
    }
    
}

//computation functions
int computeGrowthCycle (CropRecord *userData, int idx)
{
    int totaldays = -1;
    int i;
    int num_pMonth = -1;
    int num_hMonth = -1;
    int monthNum = 12;
    char months[][monthNum] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (strcmp(userData[idx].plantedMonth, "-1") != 0 && 
        strcmp(userData[idx].harvestMonth, "-1") != 0)
    {
        
        for (i = 0; i < monthNum; i++)
        {
            if (strcmp(userData[idx].plantedMonth, months[i]) == 0)
                num_pMonth = i;
            if (strcmp(userData[idx].harvestMonth, months[i]) == 0)
                num_hMonth = i;
        }
        
        if (num_pMonth != -1 && num_hMonth != -1)
        {

            totaldays = 0;

            if (userData[idx].plantedYear == userData[idx].harvestYear) //same yr
            {
                if (num_pMonth == num_hMonth) //same month
                {
                    totaldays = userData[idx].harvestDay - userData[idx].plantedDay;
                }
                else //same yr diff months
                {
                    //remaing days in pmonth
                    totaldays = daysMonth[num_pMonth] - userData[idx].plantedDay;
                    
                    for (i = num_pMonth + 1; i < num_hMonth; i++)
                    {
                        totaldays += daysMonth[i];
                    }
                    
                    totaldays += userData[idx].harvestDay;
                }
            }
            else //diff yr
            {
                totaldays = daysMonth[num_pMonth] - userData[idx].plantedDay; 
                
                for (i = num_pMonth + 1; i < monthNum; i++)
                {
                    totaldays += daysMonth[i];
                }
                
                for (i = userData[idx].plantedYear + 1; i < userData[idx].harvestYear; i++)
                {
                    totaldays += 365;
                }
                
                for (i = 0; i < num_hMonth; i++)
                {
                    totaldays += daysMonth[i];
                }
                
                totaldays += userData[idx].harvestDay;
            }
        }
        
    }

    return totaldays;
}
