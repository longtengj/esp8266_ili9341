#ifndef _CORDIC_INC_H
#define _CORDIC_INC_H
/**
 @file cordic2c_inc.h
 Generated by:[cordic2c]
 On: Wed May 10 19:59:49 2017
 By Mike Gore 2015, Cordic C Table
*/
typedef int Cordic_T; /* 32 */
typedef unsigned int UCordic_T; /* 32 */
typedef double FCordic_T; /* 64 */
#define Cordic_T_Bits     32
#define Cordic_T_FractionBits  28
#define Cordic_One    0x10000000 /* 1.000000000000000e+00 */
#define Cordic_K      0x9b74eda /* 6.072529350088812e-01 */
#define Cordic_INVK   0x1a592148 /* 1.646760258121066e+00 */
#define Cordic_KP     0x1351e872 /* 1.207497067763072e+00 */
#define Cordic_INVKP  0xd402407 /* 8.281593609602157e-01 */
#define Cordic_HalfPI 0x1921fb54 /* 1.570796325802803e+00 */
#define Cordic2FP(a)  ( (double) (a) / (double) (Cordic_One)) 
#define FP2Cordic(a)  ((Cordic_T) (Cordic_One * (a)))
#ifdef CORDIC_TABLE
static const Cordic_T v_atangrad[] = {
	0x8000000, /* 5.00000000e-01 */
	0x4b90147, /* 2.95167234e-01 */
	0x27ece16, /* 1.55958258e-01 */
	0x1444475, /* 7.91668482e-02 */
	0xa2c350, /* 3.97370458e-02 */
	0x5175f8, /* 1.98878944e-02 */
	0x28bd87, /* 9.94637236e-03 */
	0x145f15, /* 4.97348979e-03 */
	0xa2f94, /* 2.48678029e-03 */
	0x517cb, /* 1.24339387e-03 */
	0x28be6, /* 6.21698797e-04 */
	0x145f3, /* 3.10849398e-04 */
	0xa2f9, /* 1.55422837e-04 */
	0x517c, /* 7.77095556e-05 */
	0x28be, /* 3.88547778e-05 */
	0x145f, /* 1.94273889e-05 */
	0xa2f, /* 9.71183181e-06 */
	0x517, /* 4.85405326e-06 */
	0x28b, /* 2.42516398e-06 */
	0x145, /* 1.21071935e-06 */
	0xa2, /* 6.03497028e-07 */
	0x51, /* 3.01748514e-07 */
	0x28, /* 1.49011612e-07 */
	0x14, /* 7.45058060e-08 */
	0xa, /* 3.72529030e-08 */
	0x5, /* 1.86264515e-08 */
	0x2, /* 7.45058060e-09 */
	0x1, /* 3.72529030e-09 */
	0x0, /* 0.00000000e+00 */
	0
};
#else // CORDIC_TABLE
extern const Cordic_T v_atangrad[];
#endif // CORDIC_TABLE
#endif // _CORDIC_INC_H
