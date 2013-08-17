//------------------------------------------------------------------------------
/// Filename: SVGCircle.cpp
/// Description: Base Class of SVG Objects
/// Authors:
///         Robin Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 18.09.2011
//------------------------------------------------------------------------------

#include "SVGCircle.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include <iostream>

//------------------------------------------------------------------------------
SVGCircle::SVGCircle(UserInterface *ui,
                     Database *db,
                     SVGHandler *svgh,
                     signed int id,
                     signed int group_id,
                     std::vector<Coordinates> coordinates,
                     signed int r,
                     std::string fill,
                     std::string stroke,
                     std::string stroke_width):
                     SVGObject(ui, db, svgh, id, group_id, coordinates),
                     r_(r),
                     fill_(""),
                     stroke_(""),
                     stroke_width_(stroke_width)
{
  fill_.assign(fill);
  stroke_.assign(stroke);
}

//------------------------------------------------------------------------------
SVGCircle::~SVGCircle() throw()
{
}

//------------------------------------------------------------------------------
bool SVGCircle::resize()
{
  std::string str_value;
  
  std::cout << "id: " << id_ << std::endl;
  std::cout << "r: " << r_ << std::endl;

  while(true)
  {
    if(ui_->getParam("  r? ", false, false, r_, str_value, true))
      break;
  }
  
  return true;
}

//------------------------------------------------------------------------------
std::string SVGCircle::getSVGTag()
{
  tag_ << "<circle ";
  for (std::vector<Coordinates>::iterator it = coordinates_.begin();
       it != coordinates_.end(); ++it)
  {
    tag_ << "cx=\"" << (*it).getX() << "\" ";
    tag_ << "cy=\"" << (*it).getY() << "\" "; 
  }
  tag_ << "r=\"" << r_  << "\" fill=\"" << fill_  << "\" stroke=\"" <<  stroke_ 
       << "\" stroke-width=\"" <<  stroke_width_ <<"\"  />";

  return tag_.str();
}
