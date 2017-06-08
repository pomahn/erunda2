#include <stdio.h>
#include <math.h>

const double eps=1E-6;




int IfZero(double a)
    {
    if (fabs(a)<=eps) return 1;
        else return 0;
    }


int IfPos(double a)
    {
    if (a>eps) return 1;
        else return 0;
    }


int IfNeg(double a)
    {
    if (a<-eps) return 1;
        else return 0;
    }

double disqr(double a, double b, double c)
    {
    return b*b-4*a*c;
    }


int SqEquation(double a,double b,double c,double *x1,double *x2)
    {
    if (IfPos(disqr(a, b, c )))

        {
        *x1=(-b+sqrt(disqr(a,b,c)))/(2*a);
        *x2=(-b-sqrt(disqr(a, b, c)))/(2*a);
        return 2;
        }
        else
            {
            if (IfZero(disqr(a, b, c)))
                {
                *x1=-b/(2*a);
                return 1;
                }
            else return 0;
            }
    }



int LinearEquation(double b, double c, double *x1)
    {
    if (b==0)
        {
        if (c==0)
            return -1;
        else
            return 0;
        }
    else
        {
        *x1=-c/b;

        return 1;
        }
    }



int main()
{
double a = 0, b = 0, c = 0, x1, x2;
int d = 0, e = 0;


while (e != 3)    //reading correct abc;
    {
    printf( "Enter a,b,c\n");
    e=scanf("%lg %lg %lg", &a, &b, &c);
    scanf("%*[^\n]");
    }

if (IfZero(a))

    {
    d=LinearEquation(b,c,&x1);
    }
    else d=SqEquation(a,b,c,&x1,&x2);
if (IfZero(x1))  x1=0;
switch(d)
    {
    case -1 : printf("Infinity roots\n");  break;
    case 0  : printf("No roots\n"); break;
    case 1 : printf("x1=%lg\n", x1); break;
    case 2 : printf("x1= %lg ,x2= %lg\n", x1,  x2); break;
    default : printf("Error\n"); return 1; break;
    }

 return 0;
}















