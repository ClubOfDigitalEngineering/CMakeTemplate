//example from https://en.wikibooks.org/wiki/JsonCpp

#include <iostream>
#include <fftw3.h>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#define N 10
#define REAL 0
#define IMAG 1


void init(fftw_complex* signal)
{
    /* Generate two sine waves of different frequencies and
    * amplitudes.
    */

    for (int i = 0; i < N; ++i) 
    {
        double const theta = (double)i / (double)N * M_PI;

        signal[i][REAL] = 1.0 * cos(10.0 * theta) +
            0.5 * cos(25.0 * theta);

        signal[i][IMAG] = 1.0 * sin(10.0 * theta) +
            0.5 * sin(25.0 * theta);
    }
}

void print(fftw_complex* result) 
{
    for (int i = 0; i < N; ++i) 
    {
        const double mag = sqrt(result[i][REAL] * result[i][REAL] +
            result[i][IMAG] * result[i][IMAG]);

        printf("%g\n", mag);
    }
}

int main() 
{

    fftw_complex *in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
    init(in);
    
    fftw_complex *out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);

    const fftw_plan p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed */


    print(out);
    
    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);

    return 0;
}