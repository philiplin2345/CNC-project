
#ifndef STEP_MOTOR_DRV
#define STEP_MOTOR_DRV

#include  "MEPCIOINI.H"
#include  "MEPCIODEV.H"

/* -------------------- initMotionCard ------------------------- *
 * 1. cycleTime為form timer設定的時間，必須和intpInit設定的相同  *
 * ------------------------------------------------------------- */
int initMotionCard( double U , double V , double W , int cycleTime , LIOISR TimerFunction );
;
/* ---------- 關閉軸卡 -------------- *
 * 1. 不須參數
 * ---------------------------------- */
int closeMotionCard( void );

// -------------------------------------------------- //
//    putAxisValue
// -------------------------------------------------- //
int putAxisValue(int axis, int increment);

/* ---------- 開啟 timer ------------- *
 * 1. interval 的單位是ms
 * ----------------------------------- */
int enableHDTimer(int interval);

/* ---------- 關閉 timer -------------- *
 * 1. 不須參數
 * ------------------------------------ */
int disableHDTimer(void);


#endif