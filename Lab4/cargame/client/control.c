#include "client.h"

void control(const InputPacket* inpack, OutputPacket* outpack)
{
    outpack -> accelaration = 100;
    outpack -> steering = 0;
    if (inpack -> sen_left_type == SEN_WALL){
        outpack -> steering = 5;
        outpack -> accelaration = 80;
    }
    if (inpack -> sen_close_left_dist == SEN_WALL)
    {
        outpack -> steering = 5;
        outpack -> accelaration = 50;
    }
    if (inpack -> sen_right_type == SEN_WALL)
    {
        outpack -> steering = -5;
        outpack -> accelaration = 80;
    }
    if (inpack -> sen_close_right_type == SEN_WALL)
    {
        outpack -> steering = -5;
        outpack -> accelaration = 50;
    }
    outpack -> steering = 0.5;
    outpack -> tintr = 55;
    outpack -> tintg = 255;
    outpack -> tintb = 55;
}
