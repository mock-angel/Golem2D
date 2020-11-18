/*
 * ProjectManagerImGui.cpp
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#include "ProjectManagerImGui.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "Window.h"


namespace ImGui {

bool InputRect(const char* label, Rect* rectPtr,
    int decimal_precision = -1, ImGuiInputTextFlags extra_flags = 0)
{
    ImGui::PushID(label);
    ImGui::BeginGroup();

    bool valueChanged = false;

    std::array<float*, 4> arr = { &rectPtr->x, &rectPtr->y,
                                  &rectPtr->w, &rectPtr->h };

    for (auto& elem : arr) {
        ImGui::PushID(elem);
        ImGui::PushItemWidth(64.f);
        valueChanged |= ImGui::InputFloat("##arr", elem, 0, 0,
                "%f", extra_flags);

        ImGui::PopID();
        ImGui::SameLine();
    }

    ImGui::SameLine();
    ImGui::TextUnformatted(label);
    ImGui::EndGroup();

    ImGui::PopID(); // pop label id;

    return valueChanged;
}

static auto vector_getter = [](void* vec, int idx, const char** out_text)
{
    auto& vector = *static_cast<std::vector<std::string>*>(vec);
    if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
    *out_text = vector.at(idx).c_str();
    return true;
};

bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
{
    if (values.empty()) { return false; }
    return Combo(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}

bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values)
{
    if (values.empty()) { return false; }
    return ListBox(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}

}


namespace Golem {

ProjectManagerImGui::ProjectManagerImGui() {
    // TODO Auto-generated constructor stub
    m_projectManager.reloadList();


}

ProjectManagerImGui::~ProjectManagerImGui() {
    // TODO Auto-generated destructor stub
}

void ProjectManagerImGui::update(){
    if(!isOpen) return;

    ImVec2 pos{0.f, 0.f};//, pivot{0.5f, 0.5f};

    Window* windowInstance = Window::getWindow();
    ImVec2 size(windowInstance->getWidth(), windowInstance->getHeight());

    ImGui::SetNextWindowPos(pos, ImGuiCond_Once);
    ImGui::SetNextWindowSize(size);


    //Debug::log("Entered WIndow IMGUI ProjectManagerImGUI");
    ImGui::Begin("Golem Engine - Project Manager", NULL, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoTitleBar);

    static char name[128] = "";
    static char dir[128] = "";

    ImGui::Columns(2, NULL, false);

    ImGui::Text("Golem Engine - Project Manager");
    ImGui::NextColumn();

    std::string versionText = "Golem v2020.11.18r1";

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(versionText.c_str()).x \
        - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
    ImGui::Text(versionText.c_str());

    ImGui::Columns(1);

    int currentwidth = ImGui::GetWindowSize().x;
    int size_ = ImGui::CalcTextSize("Project List").x + ImGui::CalcTextSize("Templates").x;



    ImGui::BeginGroup();

    ImGui::SetCursorPosX(currentwidth/2 - size_/2);
    ImGui::BeginTabBar("Project TabBar");

    if (ImGui::BeginTabItem("Project List")){

        if(ImGui::Button("New Project")) ;//m_projectManager.addProject(name, dir);
            //ImGui::SameLine(); ImGui::InputText("##ProjName", name, IM_ARRAYSIZE(name));
            //ImGui::SameLine(); ImGui::InputText("##ProjDir", dir, IM_ARRAYSIZE(dir));

        if(ImGui::Button("Open Project"));
        if(ImGui::Button("Recent Projects"));


        ImGui::InputFloat4("Array", arr2.data());
        ImGui::InputRect("Rect", &r);

        ImGui::EndTabItem();
    }

    if(ImGui::BeginTabItem("Templates")){
        ImGui::EndTabItem();
    }

    ImGui::EndTabBar();
    ImGui::EndGroup();



    ImGui::End();
}

} /* namespace Golem */
