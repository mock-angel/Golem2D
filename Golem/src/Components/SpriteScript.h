/*
 * SpriteScript.h
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#ifndef COMPONENTS_SPRITESCRIPT_H_
#define COMPONENTS_SPRITESCRIPT_H_

#include "../Component.h"
#include "../Sprites/Sprite.h"

namespace Golem {

class SpriteScript : public Component {
public:
    SpriteScript();
    virtual ~SpriteScript();

    //Sprites should have a sprite controller.
    Sprite sprite;
    void render() override;

};

} /* namespace Golem */

#endif /* COMPONENTS_SPRITESCRIPT_H_ */
