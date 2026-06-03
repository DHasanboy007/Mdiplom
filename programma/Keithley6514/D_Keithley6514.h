#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#ifdef __cplusplus
extern "C" {
#endif

// ================= INIT =================
int  InitInstrument(int addr);
int  FindInstrument(int addr);
void CloseInstrument(void);

// ================= MEASUREMENT =================
float GetVoltage(int addr);
float GetCurrent(int addr);
float GetResistance(int addr);

// ================= CONTROL =================
void SetNPLC(int addr, float nplc);
void ResetInstrument(int addr);

// ================= OUTPUT CONTROL  =================
void OutputOn(int addr);
void OutputOff(int addr);

#ifdef __cplusplus
}
#endif

#endif