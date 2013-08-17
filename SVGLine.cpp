//------------------------------------------------------------------------------
/// Filename: SVGLine.cpp
/// Description: Base Class of SVG Objects
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 18.09.2011
//------------------------------------------------------------------------------

#include "SVGLine.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include <iostream>

//------------------------------------------------------------------------------
SVGLine::SVGLine(UserInterface *ui,
                 Database *db,
                 SVGHandler *svgh,
                 signed int id,
                 signed int group_id,
                 std::vector<Coordinates> coordinates):
                 SVGObject(ui, db, svgh, id, group_id, coordinates)
{
}

//------------------------------------------------------------------------------
SVGLine::~SVGLine() throw()
{
}

//------------------------------------------------------------------------------
bool SVGLine::resize()
{
  signed int x, y;
  std::string str_value;
  Coordinates *coord = new Coordinates(0,0);
  
  std::cout << "id: " << id_ << std::endl;
  std::cout << "x2: " << coordinates_.back().getX() << std::endl;
  std::cout << "y2: " << coordinates_.back().getY() << std::endl;
  
  coordinates_.erase(coordinates_.begin()+1);
  while(true)
  {
    if(ui_->getParam("  x2? ", false, false, x, str_value, true))
      break;
  }
  coord->setX(x);
  
  while(true)
  {
    if(ui_->getParam("  y2? ", false, false, y, str_value, true))
      break;
  }
  coord->setY(y);
  coordinates_.push_back(*coord);
  delete coord;
  
  return true;
}

//------------------------------------------------------------------------------
bool SVGLine::move(signed int x, signed int y)
{
  for(std::vector<Coordinates>::iterator it = coordinates_.begin(); 
      it != coordinates_.end(); ++it)
  {
    (*it).setX((*it).getX() + x);
    (*it).setY((*it).getY() + y);
  }
  
  return true;
}

//------------------------------------------------------------------------------
std::string SVGLine::getSVGTag() 
{
  unsigned int coord_count = 1;
  
  tag_ << "<line ";
  for (std::vector<Coordinates>::iterator it = coordinates_.begin();
       it != coordinates_.end(); ++it)
  {
    tag_ << "x" << coord_count << "=\"" << (*it).getX() << "\" ";
    tag_ << "y" << coord_count++ << "=\"" << (*it).getY() << "\" "; 
  }
  tag_ << "style=\"stroke:black;stroke-width:2\" />";
  
  return tag_.str();
}
