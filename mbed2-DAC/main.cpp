///***********************************************************************
//* 26-05-2022
//* DAC - Projeto-Final-SisElo-2022-2-Marco_Tulio_Masselli
//************************************************************************/

#include "mbed.h"

// Inputs declaration
InterruptIn wave_button(D2); // button that changes the wave form 
InterruptIn rise_freq(D3); // button that rises the freq
InterruptIn low_freq(D4); // button that lowers the freq

BusOut signal(D6, D7, D8, D9, D10, D11, D12, D13);

// wait time 
float period = 0.00005;
// wave index
int wave = 0;
// Look-up-table of the normalized sen values for the senoidal wave
float sin_values[] = {0, 2,  4,  7,  9,  11, 13, 15, 18, 20, 22, 24, 26, 29, 31, 33, 35, 
37, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 73, 75, 77, 79,
81, 82, 84, 86, 87, 89, 90, 92, 94, 95, 97, 98, 99, 101, 102, 104, 105, 106, 107, 109, 
110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 119, 120, 121, 122, 122, 123, 124, 
124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 128, 128, 128, 128, 128};

// function that changes the frequency os the waves
void change_freq()
{
    if (rise_freq == 1) {
        period = period / 1.2;
        wait_ms(50);
    }

    if (low_freq == 1) {
        period = period * 1.2;
        wait_ms(50);
    }


}


// function that changes the wave form that is been generated
void change_wave()
{
    if (wave < 3) {
        wave++;
        wait(0.5);
    } else {
        wave = 0;
        wait(0.5);
    }
}


int main()
{
    wave_button.rise(change_wave);
    rise_freq.rise(change_freq);
    low_freq.rise(change_freq);


    while(1) 
{
//-------- square wave -------
        if (wave == 0) {
            while (wave == 0) {
                signal = 0;
                //printf("\n\rSquare:%4d",signal);
                wait(period*512);
                signal = 255;
                //printf("\n\rSquare:%4d",signal);
                wait(period*512);

            }
        }

//-------- triangular wave -------
        if (wave ==1) {
            for (int i = 0; i < 256; i++) {
                signal = i;
                wait(period);
                //printf("\n\rTriangular Up:%4d",signal);

            }
            for (int i = 255; i > -1; i--) {
                signal = i;
                wait(period);
                //printf("\n\rTriangular Down:%4d",signal);
            }
        }


//-------- senoidal wave -------
            while (wave == 3) {
                // first sin quarter
                for (int i = 0; i < 91; i++) {
                    signal = 127 + sin_values[i];
                    //printf("\n\rSenoidal 1/4:");
                    wait (period);
                }
                 //second sin quarter
                for (int i = 89; i > -1; i--) {
                    signal = 127 + sin_values[i];
                    //printf("\n\rSenoidal 2/4:");
                    wait (period);
                }
                // third sin quarter
                for (int i = 0; i < 91; i++) {
                    signal = 128 + sin_values[i]*(-1);
                    //printf("\n\rSenoidal 3/4:");
                    wait (period);
                }
                // fourth sin quarter
                for (int i = 89; i > -1; i--) {
                    signal = 128 + sin_values[i]*(-1);
                    //printf("\n\rSenoidal: 4/4");
                    wait (period);
                }

        }



    }

}