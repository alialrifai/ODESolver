#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f1(float z); /*function to find ODE solution*/

float f2(float t, float y, float z, float A, float w, float seg, float B, float w_sq,float m); /* function to find ODE solution */
float m; /* Used to store the content of ODE */
int i,j,m2; /* Used for counters */
float t=0; /* Used for time */
/* Constants Definitions */
float ODE[9]; /* float array to store the ODE constants */
/* Where:*/
/*
Coefficient of y" term     = ODE[0]
Coefficient of y' term     = ODE[1]
Coefficient of y term      = ODE[2]
Coefficient of cos term (A)= ODE[3]
Frequency                  = ODE[4]
Phase                      = ODE[5]
step size (h)              = ODE[6]
Initial condition y(0)     = ODE[7]
Initial condition y'(0)    = ODE[8]

*/



float k1_y, k1_z, k2_y, k2_z; /*Constants k1, k2, k3, and k4 for each of the y and z (z=y')*/
float k3_y,k3_z,k4_y,k4_z;

int main()
{

/* RK2 Solution */

    FILE* fin,*fout;

    fin =fopen("CP3_ODEin.txt","r");
    fout =fopen("CP3_ODEout.txt","w");

/*  this section simply counts how many float number divide them by 9 to
find the number of ODEs and store it at j*/

for (j=0; fscanf(fin,"%f",&m) !=EOF; ++j);
    j =j /9;


        fclose(fin);
        fin =fopen("CP3_ODEin.txt","r");

for(m2=0; m2<j; ++m2)

    {
    t=0;
    fprintf(fout,"%d:\n",m2+1);
    fprintf(fout,"RK2:\n");

    for (i=0;i<9; ++i)
    {
        fscanf(fin,"%f",&m);
        ODE[i] = m;


    }
     float y, z;
     y = ODE[7];
     z = ODE[8];
     fout =fopen("CP3_ODEout.txt","a");



        for (i=0;i<(30/ ODE[6]); ++i)
        {   if (i == 10)
                fprintf(fout,"x= +%4.1f  and  y=                %+f\n",t,y);
            if (i == 20)
                fprintf(fout,"x= +%4.1f  and  y=                %+f\n",t,y);
            if (i == 50)
                fprintf(fout,"x= +%4.1f  and  y=                %+f\n",t,y);

            if ( i == 100 || i == 200 ||i == 300 ||i == 400 ||i == 500 ||i == 600 ||i == 700 ||i == 800 ||i == 900 ||i == 1000 )
                fprintf(fout,"x= +%4.1f  and  y= \t\t %+f\n",t,y);

            if ( i == 1100 || i == 1200 ||i == 1300 ||i == 1400 ||i == 1500 ||i == 1600 ||i == 1700 ||i == 1800 ||i == 1900 ||i == 2000 )
                fprintf(fout,"x= +%4.1f  and  y= \t\t %+f\n",t,y);

            if ( i == 2100 || i == 2200 ||i == 2300 ||i == 2400 ||i == 2500 ||i == 2600 ||i == 2700 ||i == 2800 ||i == 2900 ||i == 3000 )
                fprintf(fout,"x= +%4.1f  and  y= \t\t %+f\n",t,y);




            t=t+ODE[6];

            k1_y = f1(z);

            k1_z = f2(t,y,z,ODE[3],ODE[4],ODE[5],ODE[1],ODE[2],ODE[0]);


            k2_y = f1(z+k1_z*ODE[6]);

            k2_z = f2(t+ODE[6],y+k1_y*ODE[6],z+k1_z*ODE[6],ODE[3],ODE[4],ODE[5],ODE[1],ODE[2],ODE[0]);


            y= y + (0.5*k1_y + 0.5*k2_y)*ODE[6]; /* this line is to find y at a specific x  */

            z= z + (0.5*k1_z + 0.5*k2_z)*ODE[6];




    }



        y = ODE[7];
        z = ODE[8];
            t=0;
            fprintf(fout,"RK4:\n");

        for (i=0;i<(30/ ODE[6]); ++i)
        {
            if (i == 10)
                fprintf(fout,"x= +%4.1f  and  y=                %+f\n",t,y);
            if (i == 20)
                fprintf(fout,"x= +%4.1f  and  y=                %+f\n",t,y);
            if (i == 50)
                fprintf(fout,"x= +%4.1f  and  y=                %+f\n",t,y);

            if ( i == 100 || i == 200 ||i == 300 ||i == 400 ||i == 500 ||i == 600 ||i == 700 ||i == 800 ||i == 900 ||i == 1000 )
                fprintf(fout,"x= +%4.1f  and  y= \t\t %+f\n",t,y);

            if ( i == 1100 || i == 1200 ||i == 1300 ||i == 1400 ||i == 1500 ||i == 1600 ||i == 1700 ||i == 1800 ||i == 1900 ||i == 2000 )
                fprintf(fout,"x= +%4.1f  and  y= \t\t %+f\n",t,y);

            if ( i == 2100 || i == 2200 ||i == 2300 ||i == 2400 ||i == 2500 ||i == 2600 ||i == 2700 ||i == 2800 ||i == 2900 ||i == 3000 )
                fprintf(fout,"x= +%4.1f  and  y= \t\t %+f\n",t,y);


            t=t+ODE[6];

            k1_y = f1(z);

            k1_z = f2(t,y,z,ODE[3],ODE[4],ODE[5],ODE[1],ODE[2],ODE[0]);


            k2_y = f1(z+k1_z*ODE[6]);

            k2_z = f2(t+ODE[6],y+k1_y*ODE[6],z+k1_z*ODE[6],ODE[3],ODE[4],ODE[5],ODE[1],ODE[2],ODE[0]);


            k3_y = f1(z+k2_z*ODE[6]);

            k3_z = f2(t+ODE[6],y+k2_y*ODE[6],z+k2_z*ODE[6],ODE[3],ODE[4],ODE[5],ODE[1],ODE[2],ODE[0]);


            k4_y = f1(z+k3_z*ODE[6]);

            k4_z = f2(t+ODE[6],y+k3_y*ODE[6],z+k3_z*ODE[6],ODE[3],ODE[4],ODE[5],ODE[1],ODE[2],ODE[0]);



            y= y + (1/6)*(k1_y + 2*k2_y+2*k3_y+k4_y)*ODE[6]; /* this line is to find y at a specific x  */

            z= z + (1/6)*(k1_z + 2*k2_z+2*k3_z+k4_z)*ODE[6];




    }




}




}








float f1(float z)
{
    return z;
}

float f2(float t, float y, float z, float A, float w, float seg, float B, float w_sq,float m)
{
    float f2_res = (1/m) *( A* cos(w*t+seg)-(B*z)-(w_sq*y));

    return f2_res;
}
