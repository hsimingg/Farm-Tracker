#ifndef DEFS_H
#define DEFS_H

#define MAX_USER 10
#define MAX_CROP 100
#define MAX_LENGTH 51
#define KEY 5

typedef char String50[MAX_LENGTH];
//expectedYield = crop.avgYield * waterFactor * area;

// Structures for storing crop related data
typedef struct {
    //use -1.0 if N/A
    String50 cropName;
    float areaused;
    String50 plantedMonth;
    float plantedDay;
    float plantedYear;
    float waterUsed;    //m^3
    float fertilizerUsed; //kg
    String50 soilUsed;
    String50 harvestDate;
    float yieldUsed;    //tons
} cropRecord;

typedef struct {
    String50 cropName;
    String50 soilRecommend;
    String50 monthsRecommend;
    float minWaterRecommend;
    float maxWaterRecommend;
    float fertilizerRecommend;
    float expectedDuration;
    float expectedYield;
} crop_Preloaded;

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
void forgotPassword(Farmer *user, int *size);
int deleteFarmerProfile(Farmer *user, int *size);
int loadFarmerData(Farmer *user, int *size);
void displayFarmerProfile(Farmer *user, int *size, Farmer *currentUser);

// Crop Record Functions
void addCropRecord(cropRecord *crop, int *size);
void displayCropRecord(cropRecord *crop, int *size);
int deleteCropRecord(cropRecord *crop, int *size);
void sortCropRecord(cropRecord *crop, int *size, int byNameElseYield);
int searchCropRecord(cropRecord *crop, int *size);
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
int saveCropData(cropRecord *crops, int *size);
void exportReporttoFile();
void encryptStr(String50 str, int key);
void decryptStr(String50 str, int key);
void encryptUsers(Farmer *user, int *size, int key);
void decryptUsers(Farmer *user, int *size, int key);
void runTestDataSimulation();

// Utility
void getValidateMenu(int *variable, int min, int max);
void updateCropRecord();

#endif // DEFS_H
