/*
 * ImGuiWindow.h
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_IMGUIWINDOW_H_
#define CORE_GUI_IMGUIWINDOW_H_

namespace Golem {

class ImGuiWindow {
public:
    ImGuiWindow();
    virtual ~ImGuiWindow();

    virtual void update(){}
};

} /* namespace Golem */

#endif /* CORE_GUI_IMGUIWINDOW_H_ */
