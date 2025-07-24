#DEFINE MAX_USER 10
#DEFINE MAX_CROP 100

typedef char String50[51];


struct cropData{
	int nCrops;
	String50 crop_type;
	String50 soil_type;
	float estYield;
};
 
struct farmer{
	int ID;
	String50 fName;
	String50 lName;
	String50 password;
};


//function prototypes
int addFarmerProfile();
int farmerLogin();
void forgotPassword();
void deleteFarmerProfile();
int loadFarmerData();
void displayFarmerProfile();
void addCropRecord();
int validateCropType();
void displayCropRecord();
void deleteCropRecord();
void sortCropRecord();
void searchCropRecord();
int loadCropData();
int computeWaterUsage();
void computeAverageWaterUse();
void inputWaterData();
int computeExpectedYield();
void computeAverageYield();
void track_IrrigationUsage();
void weatherInformation();
int saveFarmerdata();
int saveCropData();
void exportReporttoFile();
void encryptPassword();
void decryptPassword();
void runTestDataSimulation();
void updateCropRecord();
void recommendPractices();
void track_ResourceUsage();
void addInventoryItem();
void updateInventoryItem();
void displayInventory();
void deleteInventoryItem();


