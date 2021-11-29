/*#################################################################################
# Тестовое задание по поределению периодичности функции и нахождения ее периода
#
#   выполнил Иванов Григорий ivanov_g_o@pstu.edu
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define quoting(a) prequoting(a)
#define prequoting(a) #a
#define func sin //здесь задаем функцию
#define arguments 1,1 //аргументы функции A*f(k*x) A и k соответственно
#define d_angle 1 //шаг дифференцирования


double get_period(double (*f)(double),double A,double k){
double y,py,dy,dx,px,dy_dx,p_dy_dx;
double T=0;
px=0;//вычиялем нулевые заначения
py=A*f(k*px);
int count=0;//заводим счетчик экстремумов
double ang = d_angle;
while (!count){
if (ang>360*80) return 0;//8 периодов наверное хватит
y=A*f(k*ang*M_PI/180);//подставляем угол в радианах
dy=y-py;//изменение функции
py=y;//задаем предыдущее
dx=ang-px;//изменение аргумента
px=ang;//задаем предыдущее
dy_dx=dy/dx;//вычисляем производную
if (dx!=0.0) dy_dx=dy/dx; else {puts("infinity!");return 0;};//на всякий случай
if (p_dy_dx/dy_dx==-1) count++;//ищем экстремум по смене знака производной
p_dy_dx=dy_dx;//задаем предыдущее
//printf("deriv=%1.8f pderiv=%1.8f dy/dx=0 %i times \n",dy_dx,p_dy_dx,count);//отладочная информация
ang+=d_angle;//next step
}
count=0;
T=ang;
while (!count){
if (ang>360*80) return 0;//8 периодов наверное хватит
y=A*f(k*ang*M_PI/180);//подставляем угол в радианах
dy=y-py;//изменение функции
py=y;//задаем предыдущее
dx=ang-px;//изменение аргумента
px=ang;//задаем предыдущее
dy_dx=dy/dx;//вычисляем производную
if (dx!=0.0) dy_dx=dy/dx; else {puts("infinity!");return 0;};//на всякий случай
if (p_dy_dx/dy_dx==-1) count++;//ищем экстремум по смене знака производной
p_dy_dx=dy_dx;//задаем предыдущее
//printf("deriv=%1.8f pderiv=%1.8f dy/dx=0 %i times \n",dy_dx,p_dy_dx,count);//отладочная информация
ang+=d_angle;//next step
}
T=T-ang;
return abs(T)*M_PI/180;//если было больше одного экстремума то скорей всего периодическая
}




unsigned int test_periodic(double (*f)(double),double A,double k){//тестируем функцию на периодичность
double y,py,dy,dx,px,dy_dx,p_dy_dx;
px=0;//вычиялем нулевые заначения
py=A*f(k*px);
int count=0;//заводим счетчик экстремумов
int ang=1;
while (count<2){
if (ang>360*800) return 0;//8 периодов наверное хватит
y=A*f(k*ang*M_PI/180);//подставляем угол в радианах
dy=y-py;//изменение функции
py=y;//задаем предыдущее
dx=ang-px;//изменение аргумента
px=ang;//задаем предыдущее
dy_dx=dy/dx;//вычисляем производную
if (dx!=0.0) dy_dx=dy/dx; else {puts("infinity!");return 0;};//на всякий случай
if (p_dy_dx/dy_dx==-1) count++;//ищем экстремум по смене знака производной
p_dy_dx=dy_dx;//задаем предыдущее
printf("deriv=%1.8f pderiv=%1.8f dy/dx=0 %i times \n",dy_dx,p_dy_dx,count);//отладочная информация
ang+=d_angle;//next step
}
return count;//если было больше одного экстремума то скорей всего периодическая
}


int main (){ //аргументы не нужны

char str[25] = quoting(func);//переводим название функции в string  для printf


if (test_periodic(func, arguments )) 
	printf("Function %s is periodic and have %1.5f period\n",str,get_period(func, arguments )); 
		else printf("Function %s is not periodic\n",str);


return 0;//так надо в С++ не может быть void
}
