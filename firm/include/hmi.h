#ifndef HMI_H
#define HMI_H

//--------------------------------------------------------------------------------
// Globals variables for HMI "scope"
//--------------------------------------------------------------------------------

extern TFT_eSPI tft; // TFT Display Instance
extern uint16_t HMI_Page;
extern uint16_t HMI_PageMemory;

extern uint16_t PLCstateOld; 
extern unsigned long  auxOldScanTime;

extern unsigned long  auxOldScanTime;
extern int networkColorBack;
extern int networkColorGrid;

//----------------------------------------------------
// Network to show under Online animation
//----------------------------------------------------

extern uint16_t showingNetwork;
extern uint16_t showingNetworkOld;

extern uint16_t editionMode;
extern uint16_t editionModeOld;

//----------------------------------------------------
// Flags for Logic Online animation
//----------------------------------------------------

extern uint16_t NetworkFlagsOnline[NET_COLUMNS - 1];

//----------------------------------------------------
// Datatypes Strings
//----------------------------------------------------

extern const String MnemonicsTypes[FIRST_INVALID_TYPE];
extern const String MnemonicsCodes[FIRST_INVALID_CODE];

//----------------------------------------------------
// Invoke the TFT_eSPI button class and 
// create all the numeric button objects
//----------------------------------------------------

#define NUM_KEY_LEN 16
extern char numberBuffer[NUM_KEY_LEN + 1];
extern uint8_t numberIndex;  

extern TFT_eSPI_Button numericKeys[16];

extern double numericValue;            // Variable to use as return value of numeric keyboard
extern uint16_t numericValueAccepted;  // Variable to use as return value of numeric keyboard


//--------------------------------------------------------------------------------
// Used Global variables in HMI scope, declared in another task
//--------------------------------------------------------------------------------

extern unsigned long actualScanTime;

//--------------------------------------------------------------------------------
// HMI Page numbers
//--------------------------------------------------------------------------------

#define PAGE_MainMenu           0
#define PAGE_MainLadder        10
#define PAGE_MainHMI           20
#define PAGE_MainConfig        30
#define PAGE_InputNumber      100

//--------------------------------------------------------------------------------
// TFT Display and TS (TouchScreen) Pinout in board socket at LOLIN D32 PRO
//--------------------------------------------------------------------------------

#define TFT_CS        14  
#define TFT_DC        27  
#define TFT_RST       33 
#define TS_CS         12 

//--------------------------------------------------------------------------------
// TFT Display and TouchScreen Rotation
//--------------------------------------------------------------------------------

#define TFT_ROTATION   3
#define TS_ROTATION    1

//--------------------------------------------------------------------------------
// TFT Display Dimmensions
//--------------------------------------------------------------------------------

#define TFT_PIXELS_X 320 // width
#define TFT_PIXELS_Y 240 // heigth

//--------------------------------------------------------------------------------
// TS Calibration default constants.
// 2.8" SPI display 
//--------------------------------------------------------------------------------

#define TS_LEFT_X    394
#define TS_RIGHT_X  3469 
#define TS_TOP_Y     323
#define TS_BOTTOM_Y 3441

//--------------------------------------------------------------------------------
// Toch Screen type of command
//--------------------------------------------------------------------------------

#define ONECLICK       1
#define DOUBLECLICK    2
#define LONGPRESS      3

//--------------------------------------------------------------------------------
// TFT Display Colors definitions
//--------------------------------------------------------------------------------

#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define CYANL    0x05FF
#define AQUA     0x04FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF
#define DARKGREY 0x39E7
#define ORANGE   0xFA60
#define LIME     0x07FF
#define PINK     0xF8FF
#define PURPLE   0x78EF
#define PURPLE1  0x60C8
#define PURPLE2  0x2064
#define BROWN    0x2020
#define BROWN1   0x1000
#define YELLOW1  0x3920
#define YELLOW2  0x7DE0
#define BLUE1    0x00E7
#define WHITE1   0xE77C
#define WHITE2   0xC6F8

//--------------------------------------------------------------------------------
// Main Menu and Body dimmensions [pixels]
//--------------------------------------------------------------------------------

#define MENU_HEIGTH       40
#define MENU_WIDTH        53
#define BODY_WIDTH        TFT_PIXELS_X
#define BODY_HEIGTH       TFT_PIXELS_Y - MENU_HEIGTH

//--------------------------------------------------------------------------------
// Network dimmensions [pixels]
//--------------------------------------------------------------------------------

#define POWER_BAR_WIDTH    2

#define NET_BODY_HEIGTH   BODY_HEIGTH
#define NET_BODY_WIDTH    BODY_WIDTH - POWER_BAR_WIDTH

#define NET_COL_WIDTH     53
#define NET_ROW_HEIGTH    40

//--------------------------------------------------------------------------------
// Ladder Logic Animation
//--------------------------------------------------------------------------------

#define COLOR_TAG             WHITE
#define COLOR_OFF             WHITE
#define COLOR_ON              GREEN
#define COLOR_BACK_NET        BLACK
#define COLOR_BACK_NET_EDIT   BROWN1
#define COLOR_NET_GRID        DARKGREY
#define COLOR_NET_GRID_EDIT   ORANGE
#define COLOR_BAR_ON          GREEN
#define COLOR_BAR_OFF         RED
#define COLOR_VALUES_ONLINE   CYAN

//--------------------------------------------------------------------------------
// Task Functions prototypes
//--------------------------------------------------------------------------------

void pageMainMenu(uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y);
void pageMainLadder(uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y);
void pageMainHMI(uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y);
void pageMainConfig(uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y);
void pageInputNumber(uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y);

void touch_calibrate(void);
void touchMainMenu(uint16_t ts_x, uint16_t ts_y);
void touchMainLadder(uint16_t ts_x, uint16_t ts_y);
void touchMainHMI(uint16_t ts_x, uint16_t ts_y);
void touchMainConfig(uint16_t ts_x, uint16_t ts_y);
void touchInputNumber(uint16_t ts_x, uint16_t ts_y);
  
void drawNumericKeyboard(void);
void drawMainMenu(void);
void drawMainHMI(void);
void drawMainConfig(void);
void drawMainLadder(void);
  void drawLadderMenuBut1(void);
  void drawLadderMenuBut2(void);
  void drawLadderMenuBut3(void);
  void drawLadderMenuBut4(void);
  void drawLadderMenuBut5(void);
  void drawLadderMenuBut6(void);
  void drawHomeIcon(void);
  void drawLeftArrow(void);
  void drawRightArrow(void);
  void printEDIT();  
  void printPLCstateSmall(void); 
  
  void drawBaseNetwork(void);
  void drawPowerBar(void);
  void printNetworkNumber(void);
  void drawNetwork(void);   

void drawLadderOnline(void);
  uint16_t NetworkChanged(void);
  void EditionChanged(void);
  uint16_t PLCstateChange(void);
  void printPLCstateSmall (void);

void printPLCstate(void);
uint16_t ScanTimeChange(void);

void printEDIT(void);
void printSAVE(void);

int GetData (int r, int c);
int GetFlag (int r, int c);
void drawTagBit (int Row, int Column, int Color);

void drawBox2 (int Row, int Column, int boxcolor);
void drawBox3 (int Row, int Column, int boxcolor);

void drawBoxTag (int Row, int Column, int Color);
void drawBox2Tags (int Row, int Column, int Color);
void drawBox3Tags (int Row, int Column, int Color);

void drawBoxInputPin2 (int Row, int Column);
void drawBoxInputPin3 (int Row, int Column);

void drawBoxOutputPin2 (int Row, int Column);
void drawBoxOutputPin3 (int Row, int Column);

void drawTimerTags (int Row, int Column, int Color);
void drawCounterTags (int Row, int Column, int Color);
void drawNop (int Row, int Column, int Flag, int Data);
void drawNo (int Row, int Column, int Flag, int Data);
void drawNc (int Row, int Column, int Flag, int Data);
void drawRe (int Row, int Column, int Flag, int Data);
void drawFe (int Row, int Column, int Flag, int Data);
void drawCoil (int Row, int Column, int Flag, int Data);
void drawCoilU (int Row, int Column, int Flag, int Data);
void drawCoilL (int Row, int Column, int Flag, int Data);
void drawBar (int Row, int Column, int Color);
void drawConn(int Row, int Column, int Flag, int Data);
void drawNeg(int Row, int Column, int Flag, int Data);
void drawTon(int Row, int Column, int Flag, int Data);
void drawToff(int Row, int Column, int Flag, int Data);
void drawTp(int Row, int Column, int Flag, int Data);
void drawCtu(int Row, int Column, int Flag, int Data);
void drawCtd(int Row, int Column, int Flag, int Data);
void drawMove(int Row, int Column, int Flag, int Data);
void drawSub(int Row, int Column, int Flag, int Data);
void drawAdd(int Row, int Column, int Flag, int Data);
void drawMul(int Row, int Column, int Flag, int Data);
void drawDiv(int Row, int Column, int Flag, int Data);
void drawMod(int Row, int Column, int Flag, int Data);
void drawShl(int Row, int Column, int Flag, int Data);
void drawShr(int Row, int Column, int Flag, int Data);
void drawRol(int Row, int Column, int Flag, int Data);
void drawRor(int Row, int Column, int Flag, int Data);
void drawAnd(int Row, int Column, int Flag, int Data);
void drawOr(int Row, int Column, int Flag, int Data);
void drawXor(int Row, int Column, int Flag, int Data);
void drawNot(int Row, int Column, int Flag, int Data);

#endif