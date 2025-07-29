#ifndef DEFS_H
#define DEFS_H

#define MAX_USER 10
#define MAX_CROP 100
#define MAX_LENGTH 51

typedef char String50[MAX_LENGTH];
//expectedYield = crop.avgYield * waterFactor * area;

// Structure for storing crop records
typedef struct cropDataTag {
    String50 cropName;
    String50 soilType;
    float avgYield;
    float minReqWater;
    float maxReqWater;
    float fertilizerReq;
    String50 plantingMonths;
} CropRecord;

// Structure for storing farmer profiles
typedef struct farmerInfoTag {
    int idNum; 
    String50 fName;
    String50 lName;
    String50 password;
    String50 username;
} Farmer;

// Function Prototypes

// Farmer Profile Functions
void addFarmerProfile(Farmer *user, int *size);
int farmerLogin(Farmer *user, int *size, Farmer *currentUser);
void forgotPassword(Farmer *user);
void deleteFarmerProfile(Farmer *user, int *size);
int loadFarmerData(Farmer *user, int *size);
void displayFarmerProfile(Farmer *user, int *size, Farmer *currentUser);

// Crop Record Functions
void addCropRecord();
int validateCropType();
void displayCropRecord();
void deleteCropRecord();
void sortCropRecord();
void searchCropRecord();
int loadCropData();

// Water Requirement Functions
int computeWaterUsage();
void computeAverageWaterUse();
void inputWaterData();

// Yield Functions
int computeExpectedYield();
void computeAverageYield();

// Irrigation & Inventory Functions
void track_IrrigationUsage();
void track_ResourceUsage();
void addInventoryItem();
void updateInventoryItem();
void displayInventory();
void deleteInventoryItem();

// Climate & Recommendations
void weatherInformation();
void recommendPractices();

// System Functions
int saveFarmerdata(Farmer *user, int *size);
int saveCropData(CropRecord *crops, int *size);
void exportReporttoFile();
void encryptUser();
void decryptUser();
void runTestDataSimulation();

// Utility
void getValidateMenu(int *variable, int min, int max);
void updateCropRecord();

#endif // DEFS_H
