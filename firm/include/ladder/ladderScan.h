

extern uint16_t ShowingNetwork;
extern uint16_t NetworkFlagsOnline[NET_COLUMNS - 1];


void execNop (int n, int c, int r, int f);
void execConn (int n, int c, int r, int f);
void execNeg (int n, int c, int r, int f);
void execNO (int n, int c, int r, int f);
void execNC (int n, int c, int r, int f);
void execRE (int n, int c, int r, int f);
void execFE (int n, int c, int r, int f);
void execCoil (int n, int c, int r, int f);
void execCoilL (int n, int c, int r, int f);
void execCoilU (int n, int c, int r, int f);
void execTON (int n, int c, int r, int f);
void execTOFF (int n, int c, int r, int f);
void execTP (int n, int c, int r, int f);
void execCTU (int n, int c, int r, int f);
void execCTD (int n, int c, int r, int f);
void execMOVE (int n, int c, int r, int f);
void execSUB (int n, int c, int r, int f);
void execADD (int n, int c, int r, int f);
void execMUL (int n, int c, int r, int f);
void execDIV (int n, int c, int r, int f);
void execMOD (int n, int c, int r, int f);
void execSHL (int n, int c, int r, int f);
void execSHR (int n, int c, int r, int f);
void execROL (int n, int c, int r, int f);
void execROR (int n, int c, int r, int f);
void execAND (int n, int c, int r, int f);
void execOR (int n, int c, int r, int f);
void execXOR (int n, int c, int r, int f);
void execNOT (int n, int c, int r, int f);

void execBars (int n, int c);
