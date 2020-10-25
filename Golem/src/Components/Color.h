/*
 * Color.h
 *
 *  Created on: 06-Oct-2020
 *      Author: anantha
 */

#ifndef COMPONENTS_COLOR_H_
#define COMPONENTS_COLOR_H_

#include <iostream>

#include "../GLM.h"

namespace Golem {

class Color {
    glm::vec3 m_colorValue;

public:
    Color();
    Color(float t_r, float t_g, float t_b){
        r = t_r;
        g = t_g;
        b = t_b;
    }

    virtual ~Color();

    float r = 0;
    float g = 0;
    float b = 0;

    static Color white;
    static Color black;
    static Color red;
    static Color green;
    static Color blue;
    static Color yellow;
    static Color lime;


    static Color fromHSV(float H, float S, float V){
        if(H>360 || H<0 || S>100 || S<0 || V>100 || V<0){
            std::cout<<"The givem HSV values are not in valid range"<<std::endl;
                return Color();
            }
            float s = S/100;
            float v = V/100;
            float C = s*v;
            float X = C*(1-abs(fmod(H/60.0, 2)-1));
            float m = v-C;
            float r,g,b;
            if(H >= 0 && H < 60){
                r = C,g = X,b = 0;
            }
            else if(H >= 60 && H < 120){
                r = X,g = C,b = 0;
            }
            else if(H >= 120 && H < 180){
                r = 0,g = C,b = X;
            }
            else if(H >= 180 && H < 240){
                r = 0,g = X,b = C;
            }
            else if(H >= 240 && H < 300){
                r = X,g = 0,b = C;
            }
            else{
                r = C,g = 0,b = X;
            }
            int R = (r+m)*255;
            int G = (g+m)*255;
            int B = (b+m)*255;
            std::cout<<"R : "<<R<<std::endl;
            std::cout<<"G : "<<G<<std::endl;
            std::cout<<"B : "<<B<<std::endl;

        return Color(R, G, B);
    }

    static Color fromHex(unsigned int HEX){
        //TODO: needs testing.
        const unsigned int R = HEX/65536;
        const unsigned int G = (HEX-R*65536)/256;
        const unsigned int B = (HEX-R*65536-G*256);

        return Color(R, G ,B);
    }

    unsigned int rgbToHex(float R, float G, float B ){
        return (R*65536)+(G*256)+B;
    }

    void updateVector(){
        m_colorValue.r = r/255.0;
        m_colorValue.g = g/255.0;
        m_colorValue.b = b/255.0;
    }

    const glm::vec3 getVector() {
        updateVector();

        return m_colorValue;

    }
};


} /* namespace Golem */

#endif /* COMPONENTS_COLOR_H_ */
