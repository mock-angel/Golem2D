/*
 * SpriteScript.h
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#ifndef RES_SCRIPTS_SPRITESCRIPT_H_
#define RES_SCRIPTS_SPRITESCRIPT_H_

#include "../../Component.h"
#include "../../Components/Color.h"
#include "../../Graphics/Sprites/Sprite.h"

#include SCRIPT_HEADERS

namespace Golem {

class Transform;

class SpriteScript : public Component {
    GAME_SCRIPT(SpriteScript)

public:

    Sprite sprite;

    virtual ~SpriteScript();

    void render() override;
    void setColor();

private:
    Color m_color;//TODO: must be RGB

};

} /* namespace Golem */

#endif /* RES_SCRIPTS_SPRITESCRIPT_H_ */
