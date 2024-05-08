#pragma once

#include <string>
#include <vector>

#include "rect.h"
#include "stat.h"

class Entity: public Stat {
    public:
    int  xDraw;
    int  yDraw;
    int  priority;
    Rect rect;
    Entity(int type, std::string name = "");
    std::string              name;
    bool                     inAction;
    int                      actionTimes;
    void                     setName(std::string name);
    std::vector<std::string> output();
    void                     addActionTimes();
    void                     setPosDraw(int x, int y);
    bool                     cmp(Entity other);
};