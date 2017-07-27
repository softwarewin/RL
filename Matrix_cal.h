#ifndef _Matrix_cal
#define _Matrix_cal
char Matrix_Mult(float **mul1, char m1, char n1, float **mul2, char m2, char n2, float **mulout, char m3, char n3);
char Matrix_Add(float **mul1, char m1, char n1, float **mul2, char m2, char n2, float **mulout, char m3, char n3);
char Matrix_Trans(float **mul1, char m1, char n1,float **mulout, char m3, char n3);
char Matrix_Inv22(float **mul1, char m1, char n1,float **mulout, char m3, char n3);
char Matrix_Mult_Num(float **mul1, char m1, char n1,float num);
#endif
