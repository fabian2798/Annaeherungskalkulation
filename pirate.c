#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    double epsilon = 0.0000001; // annährungswert der schiffe
    double x_p = 0;             // x-koordinate piratenschiff
    double y_p = 0;             // y-koordinate piratenschiff
    double v_p = 1;             // geschwindigkeit piratenschiff
    double x_h = 1;             // x-koordinate handelsschiff
    double y_h = 0;             // y-koordinate handelsschiff
    double v_h = 0.75;          // geschwindigkeit handelsschiff
    int repeat = 0;             // anzahl an durchgängen
    double delta_t = 0.0000001;
    double time = 0;
    double delta_x = delta_t; // zurückgelegter weg auf x-achse
    double delta_y = 0;       // zurückgelegter weg auf y-achse
    double phi = 0;           // steigerungswinkel
    while ((x_h - x_p) > epsilon || (y_h - y_p) > epsilon)
    {
        repeat += 1;             // k
        time = repeat * delta_t; // delta time
        y_h = delta_t * repeat * v_h;
        x_p = x_p + delta_x; // akutelle x_pos
        y_p = y_p + delta_y; // aktuelle y_pos
        phi = atan((y_h - y_p) / (1 - x_p)); // arctan des winkels phi == ankathete/gegenhathete
        delta_x = delta_t * cos(phi); // x_pos veränderung nach einer bestimmten zeit
        delta_y = delta_t * sin(phi); // y_pos veränderung nach einer bestimmten zeit
    }
    printf("Die Schiffe treffen sich bei y: %f\n", y_p);
    printf("Nach einer Zeit von t: %f", time);
    return 0;
}