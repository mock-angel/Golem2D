/*
 * ProjectManagerImGui.h
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_PROJECTMANAGERIMGUI_H_
#define CORE_GUI_PROJECTMANAGERIMGUI_H_

#include "ImGuiWindow.h"
#include "../ProjectManager/ProjectManager.h"

struct Rect {
    float x;
    float y;
    float w;
    float h;
};


namespace Golem {

class ProjectManagerImGui : public ImGuiWindow {
public:
    ProjectManagerImGui();
    virtual ~ProjectManagerImGui();

    void update();

private:
    bool isOpen = true;

    Rect r{ 0.f, 0.f, 0.f, 0.f };
    std::array<float, 4> arr2 = { 0 };

    ProjectManager m_projectManager;
};

} /* namespace Golem */

#endif /* CORE_GUI_PROJECTMANAGERIMGUI_H_ */
