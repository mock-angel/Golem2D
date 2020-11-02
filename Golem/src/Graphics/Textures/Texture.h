/*
 * Texture.h
 *
 *  Created on: 10-Oct-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_TEXTURES_TEXTURE_H_
#define GRAPHICS_TEXTURES_TEXTURE_H_



namespace Golem {

class Texture {

public:
    Texture();
    virtual ~Texture();

    void load(const char* str );

    unsigned int get(){
        return m_texture;
    }
private:
    unsigned int m_texture;
};

} /* namespace Golem */

#endif /* GRAPHICS_TEXTURES_TEXTURE_H_ */
