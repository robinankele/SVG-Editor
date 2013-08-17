//------------------------------------------------------------------------------
/// Filename: SVGPolygon.cpp
/// Description: Base Class of SVG Objects
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#include "SVGPolygon.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include "Error.h"
#include <iostream>

//------------------------------------------------------------------------------
SVGPolygon::SVGPolygon(UserInterface *ui,
                       Database *db,
                       SVGHandler *svgh,
                       signed int id,
                       signed int group_id,
                       std::vector<Coordinates> coordinates,
                       std::string fill): 
                       SVGObject(ui, db, svgh, id, group_id, coordinates),
                       fill_("")
{
  fill_.assign(fill);
  error_ = new Error();
}

//------------------------------------------------------------------------------
SVGPolygon::~SVGPolygon() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool SVGPolygon::resize()
{
  std::string str_value;
  unsigned int coord_count = 0;
  Coordinates *coord = new Coordinates(0,0);
  
  std::cout << "id: " << id_ << std::endl;
  for(std::vector<Coordinates>::iterator it = coordinates_.begin() + 1; 
      it != coordinates_.end(); ++it)
  {
    std::cout << "x: " << (*it).getX() << std::endl;
    std::cout << "y: " << (*it).getY() << std::endl;
  }
  
  coord_count = coordinates_.size();
  coordinates_.erase(coordinates_.begin()+1,coordinates_.end());

  signed int y = 0;
  signed int x = 0;
  for(unsigned int count = 0; count < coord_count - 1; count++)
  {
    while(true)
    {
      if(ui_->getParam("  x? ", false, false, x, str_value, true))
        break;
    }
    coord->setX(x);
    
    while(true)
    {
      if(ui_->getParam("  y? ", false, false, y, str_value, true))
        break;
    }
    coord->setY(y);
    coordinates_.push_back(*coord);
  }
  delete coord;
  
  return true;
}

//------------------------------------------------------------------------------
bool SVGPolygon::move(signed int x, signed int y)
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
std::string SVGPolygon::getSVGTag()
{
  tag_ << "<polygon points=\"";
  for (std::vector<Coordinates>::iterator it = coordinates_.begin();
       it != coordinates_.end(); ++it)
  {
    tag_ << (*it).getX() << " " << (*it).getY() << " ";  
  }
  tag_ << "\" " << "fill=\"" << fill_ 
       << "\" style=\"stroke:gray;stroke-width:1\" />";
  
  return tag_.str();
}
