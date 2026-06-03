#ifndef K6430_H
#define K6430_H

#ifdef __cplusplus
extern "C" {
#endif

// ================= GPIB ADDRESS =================
extern int smuad;

// ================= INITIALIZATION =================
void ResetSMU(void);

void SetVMeasuring(void);
void SetIMeasuring(void);

// ================= SOURCE MODE =================
void SetVsourcing(float V);
void SetIsourcing(float I);
long SourcStat(void);

// ================= MEASUREMENT =================
float GetV(void);
float GetI(void);
float GetG(float* Curr);

// ================= OUTPUT CONTROL =================
void OutputON(void);
void OutputOFF(void);
int  OutputStat(void);

// ================= SPEED / NPLC =================
void SetVSpeed(float NPLC);
void SetISpeed(float NPLC);

// ================= RANGE CONTROL =================
void AutoRangeOn(void);
void AutoRangeOff(void);
void RangeUp(void);
void RangeDown(void);

// ================= DEVICE CHECK =================
int FindSMU(void);

#ifdef __cplusplus
}
#endif

#endif // K6430_H