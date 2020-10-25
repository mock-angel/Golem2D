/*
 * SpriteScript.h
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#ifndef RES_SCRIPTS_SPRITESCRIPT_H_
#define RES_SCRIPTS_SPRITESCRIPT_H_

#include "../../Component.h"
#include "../../Sprites/Sprite.h"
#include "../../Components/Color.h"

namespace Golem {

class Transform;

class SpriteScript : public Component {
    //required Transform

    Color m_color;//TODO: must be RGB

    //std::shared_ptr<Transform> transform;

public:
    SpriteScript();
    virtual ~SpriteScript();

    //Sprites should have a sprite controller.
    Sprite sprite;
    void render() override;

    void setColor();
    //std::weak_ptr<Transform> getTransform();
};

} /* namespace Golem */

#endif /* RES_SCRIPTS_SPRITESCRIPT_H_ */
