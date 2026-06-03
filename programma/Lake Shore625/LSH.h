#ifndef LS625_AGT_H
#define LS625_AGT_H

#ifdef __cplusplus
extern "C" {
#endif

// ================= GPIB ADDRESS =================
extern const int LS625;

// ================= INITIALIZATION =================
void InitMagLS625(void);        // FLDS + basic setup
void InitCurrLS625(void);       // current mode setup
void InitVoltLS625(void);       // voltage mode setup
void InitDispLS625(void);       // display init

// ================= MEASUREMENT =================
float GetCoeffLS625(void);          // FLDS? (field coefficient)
float ReadOutputCurrLS625(void);    // rdgi?
float GetVoltageLS625(void);        // optional (if used)
float GetCurrentLS625(void);        // optional (if used)

// ================= CONTROL =================
long SetILS625(float I);            // set current
long SetCoeffLS625(float Coeff);    // set FLDS coefficient
long SetDISPLS625(unsigned int Mode,
                  unsigned int VoltSense,
                  unsigned int Brightness);

long SetRampLS625(float R);         // ramp rate

// ================= DEVICE CHECK =================
int FindLS625(void);

// ================= SYSTEM =================
void OpenLS625(void);
void CloseLS625(void);

#ifdef __cplusplus
}
#endif

#endif // LS625_AGT_H