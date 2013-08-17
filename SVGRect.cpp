//------------------------------------------------------------------------------
/// Filename: SVGRect.cpp
/// Description: Base Class of SVG Objects
/// Authors:
///         Robin Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#include "SVGRect.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include <iostream>

//------------------------------------------------------------------------------
SVGRect::SVGRect(UserInterface *ui,
                 Database *db,
                 SVGHandler *svgh,
                 signed int id,
                 signed int group_id,
                 std::vector<Coordinates> coordinates,
                 signed int width,
                 signed int height,
                 std::string fill,
                 std::string stroke,
                 std::string stroke_width): SVGObject(ui, db, svgh, id, 
                                                       group_id, coordinates),
                                             width_(width),
                                             height_(height),
                                             fill_(""),
                                             stroke_(""),
                                             stroke_width_(stroke_width)
{
  fill_.assign(fill);
  stroke_.assign(stroke);
}

//------------------------------------------------------------------------------
SVGRect::~SVGRect() throw()
{
}

//------------------------------------------------------------------------------
bool SVGRect::resize()
{
  std::string str_value;
  
  std::cout << "id: " << id_ << std::endl;
  std::cout << "width: " << width_ << std::endl;
  std::cout << "height: " << height_ << std::endl;
  
  while(true)
  {
    if(ui_->getParam("  width? ", false, false, width_, str_value, true))
      break;
  }
  
  while(true)
  {
    if(ui_->getParam("  height? ", false, false, height_, str_value, true))
      break;
  }
  
  return true;
}

//------------------------------------------------------------------------------
bool SVGRect::rotate(std::string direction)
{
  signed int temp_height = height_;
  signed int temp_width = width_;
  
  if(!direction.compare("cw"))
  {
    height_ = temp_width; 
    width_ = -temp_height;
    return true;
  }
  if(!direction.compare("ccw"))
  {
    height_ = -temp_width; 
    width_ = temp_height;
    return true;
  }
  return false;
}

//------------------------------------------------------------------------------
std::string SVGRect::getSVGTag()
{
  tag_ << "<rect ";
  for (std::vector<Coordinates>::iterator it = coordinates_.begin();
       it != coordinates_.end(); ++it)
  {
    tag_ << "x=\"" << (*it).getX() << "\" ";
    tag_ << "y=\"" << (*it).getY() << "\" "; 
  }
  tag_ << "width=\"" << width_ << "\" height=\"" << height_ << "\" fill=\"" 
       << fill_  << "\" stroke=\"" <<  stroke_ << "\" stroke-width=\""
       << stroke_width_ <<"\"  />";

  return tag_.str();
}
