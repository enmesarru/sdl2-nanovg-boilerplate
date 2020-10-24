#include <memory>
#include "graphic.h"
#include "circle.h"
#include "polygon.h"

std::unique_ptr<_Graphic> _Graphic::create_graphic(GraphicType type) {
    switch (type)
    {
    case GraphicType::CIRCLE:
        return std::unique_ptr<Circle>();
        break;
    case GraphicType::POLYGON:
        return std::unique_ptr<Polygon>();
        break;
    default:
        return nullptr;
        break;
    }
}