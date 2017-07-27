#include "Matrix_cal.h"
// ����˷�
char Matrix_Mult(float **mul1, char m1, char n1, float **mul2, char m2, char n2, float **mulout, char m3, char n3)// �������1��ַ �������2��ַ �������3��ַ
{
  unsigned char dest_i,dest_j,mul1_i,mul1_j,mul2_i,mul2_j;
  float sum;
  // ������ߴ�
  if((n1!=m2)||(m1!=m3)||(n2!=n3))
	  return(1);
  // �������˷� //Ѱַa[i][j] = *((float*)a+n*i+j)
  for(dest_i=0;dest_i<m1;dest_i++)           // �б仯
	  for(dest_j=0;dest_j<n1;dest_j++)       // �б仯
	  {
		  sum = 0;
		  for(mul1_j=0;mul1_j<n1;mul1_j++)
		  {
			  mul1_i = dest_i;
			  mul2_i = mul1_j;
			  mul2_j = mul1_i;
			  sum =sum + (*((float*)mul1+n1*mul1_i+mul1_j)) * (*((float*)mul2+n2*mul2_i+mul2_j)); // ���������������2������һ��
		  }
		  (*((float*)mulout+n3*dest_i+dest_j)) = sum;
	  }
  return(0);
}
// ����ӷ�
char Matrix_Add(float **mul1, char m1, char n1, float **mul2, char m2, char n2, float **mulout, char m3, char n3)
{
   unsigned char dest_i,dest_j;
   // ������ߴ�
   if((n1!=n2)||(m1!=m2)||(n1!=n3)||(m1!=m3))
		return(1);
   // �������ӷ� //Ѱַa[i][j] = *((float*)a+n*i+j)
   for(dest_i=0;dest_i<m1;dest_i++)           // �б仯
	  for(dest_j=0;dest_j<n1;dest_j++)       // �б仯
	  {
		 (*((float*)mulout+n2*dest_i+dest_j)) = (*((float*)mul1+n1*dest_i+dest_j)) + (*((float*)mul2+n2*dest_i+dest_j)); // ���������������2������һ��
	  }
   return(0);
}
char Matrix_Trans(float **mul1, char m1, char n1,float **mulout, char m3, char n3)
{
   unsigned char dest_i,dest_j;
   // ������ߴ�
   if((n1!=m3)||(m1!=n3))
		return(1);
   // �������ת�� //Ѱַa[i][j] = *((float*)a+n*i+j)
   for(dest_i=0;dest_i<m1;dest_i++)                        // �б仯
	  for(dest_j=0;dest_j<n1;dest_j++)                     // �б仯
	  {
		    (*((float*)mulout+n3*dest_j+dest_i)) = (*((float*)mul1+n1*dest_i+dest_j)); // ����ת��
	  }
   return(0);
}
char Matrix_Mult_Num(float **mul1, char m1, char n1,float num)
{
	unsigned char dest_i,dest_j;
	for(dest_i=0;dest_i<m1;dest_i++)                        // �б仯
	  for(dest_j=0;dest_j<n1;dest_j++)                     // �б仯
	  {
			(*((float*)mul1+n1*dest_j+dest_i)) = (*((float*)mul1+n1*dest_i+dest_j))*num; // ������Գ���
	  }
   return(0);
}
char Matrix_Inv22(float **mul1, char m1, char n1,float **mulout, char m3, char n3)
{
   float det,temp;
   // ������ߴ�
   if((n1!=n3)||(m1!=m3)||(n1!=m1))
		return(1);
   // ��������ʽ
   det = (*((float*)mul1+n1*0+0)) * (*((float*)mul1+n1*1+1)) - (*((float*)mul1+n1*1+0)) * (*((float*)mul1+n1*0+1));
   if(det == 0)
	   return(1);
   // ����2*2������� //Ѱַa[i][j] = *((float*)a+n*i+j)
   temp = (*((float*)mul1+n1*0+0))/det;
   (*((float*)mulout+n3*0+0)) = (*((float*)mul1+n1*1+1))/det;
   (*((float*)mulout+n3*0+1)) = -(*((float*)mul1+n1*0+1))/det;
   (*((float*)mulout+n3*1+0)) = -(*((float*)mul1+n1*1+0))/det;
   (*((float*)mulout+n3*1+1)) = temp;
   return(0);
}
