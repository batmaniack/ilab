#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
const int NPoints = 100;
const int ERROR = -1;
const double SigmSist = 0.0001 ;
int
ReadData (double i[], double u[])
{
  FILE *data = fopen ("data1.txt", "r");
  if (!data)			// Проверка открытия файла
    {
      printf ("Cannot open Data.txt");
      return ERROR;		//закрытие функции
    };
  int line = 0;
  for (;;)			// цикл по считыванию данных
    {
      line++;
      int res = fscanf (data, "%lg %lg", &u[line], &i[line]);
      if (res == EOF)
			break;
    };
  fclose (data);
  return line;			//проверяем все ли сторки считались
};

int
calculatelaba(double i[] , double u[], double r[], int line, double *sigma1, double *sigma2)
{

  int c = 0;
  int d = 0;
  double SigmRand1=0, SigmRand2=0, ui=0, u1=0, i1=0, ui2=0;
  double u2=0, i2=0, r1=0, r2=0, ui1=0, ptrsigma1, ptrsigma2;
  //ptrsigma1= *sigma1;
  //ptrsigma2= *sigma2;
  for (;;)
    {
      c++;
      if (line == c)
			break;
      r[c] = u[c] / i[c];
    }
  for (;;)
    {
      d++;
      if (line == d)
			break;
      if(d>0 && d<12)
        {
          ui1 += u[d]*i[d];
          i1 += i[d]*i[d];
          u1 += u[d]*u[d];
          //printf("%lg\t %lg\t %lg\t %d\t %d\n ", ui1, i1, u1, line, d );

        }
      if(d>11 && d<24)
        {
          ui2 += u[d]*i[d];
          i2 += i[d]*i[d];
          u2 += u[d]*u[d];
        }
    }
  r1 = ui1/i1;
  r2 = ui2/i2;
  SigmRand1 = sqrt(( u1/i1 - r1*r1)/10);
  *sigma1 = sqrt(SigmRand1*SigmRand1 + SigmSist*SigmSist);
  SigmRand2 = sqrt(( u2/i2 - r2*r2)/10);
  *sigma2 = sqrt(SigmRand2*SigmRand2 + SigmSist*SigmSist);
}

int
WriteData (double i[], double u[], double r[], int line, double sigma1, double sigma2)
{ FILE *result = fopen ("result.txt", "w");
  if (!result)			// Проверка открытия файла
    {
      printf ("Cannot open result.txt");
      return ERROR;			//закрытие файла
    }
  int c = 0;
  fprintf (result, "Таблица значений\n");
  for (;;)
    {
      c++;
      if (line == c)
			break;
      fprintf (result, "%lg\t %lg\t %lg\n", u[c], i[c], r[c]) != EOF;
    };
  printf("%lg\t %lg\n", sigma1, sigma2 );
  fprintf (result, "Погрешность при 20 см: %lg\nПогрешность при 30 см: %lg\n", sigma1, sigma2);
  fclose (result);
  return line;
};

void myfree(double** data)
{
  free( *data);
  *data= NULL;
}

int
main ()
{
  int nMeas1, nMeas2 = 0;
  double sigma1= 0;
  double sigma2 = 0;
  double* i = (double*) calloc(NPoints, sizeof(double));
  double* u = (double*) calloc(NPoints, sizeof(double));
  double* r = (double*) calloc(NPoints, sizeof(double));
  nMeas1 = ReadData (i, u);
  if (nMeas1 <= 0)		//в нашей программе ошибка 1
    {
     return ERROR;
    }
  calculatelaba (i, u, r, nMeas1, &sigma1, &sigma2);
  nMeas2 = WriteData (i, u, r, nMeas1, sigma1, sigma2);
  if (nMeas2 <= 0)		//в нашей программе ошибка 1
    {
     return ERROR;
    }
  myfree(&i);
  myfree(&u);
  myfree(&r);
  return (0);
}
