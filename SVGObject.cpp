//------------------------------------------------------------------------------
/// Filename: SVGObject.cpp
/// Description: Base Class of SVG Objects
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#include "SVGObject.h"
#include "UserInterface.h"
#include "Database.h"

//------------------------------------------------------------------------------
SVGObject::SVGObject(UserInterface *ui,
                     Database *db,
                     SVGHandler *svgh,
                     signed int id,
                     signed int group_id,
                     std::vector<Coordinates> coordinates):
                     ui_(ui),
                     db_(db),
                     svgh_(svgh),
                     id_(id),
                     group_id_(group_id),
                     coordinates_(coordinates)
{
}

//------------------------------------------------------------------------------
SVGObject::~SVGObject() throw()
{
}

//------------------------------------------------------------------------------
bool SVGObject::move(signed int x, signed int y)
{  
  coordinates_.front().setX(coordinates_.front().getX() + x);
  coordinates_.front().setY(coordinates_.front().getY() + y);
  
  return true;
}

//------------------------------------------------------------------------------
bool SVGObject::rotate(std::string direction)
{
  signed int x_temp = 0, y_temp = 0;
  signed int x_start = 0, y_start = 0;

  x_start = coordinates_.front().getX();
  y_start = coordinates_.front().getY();
  
  move(-x_start, -y_start);

  if(!direction.compare("cw"))
  {
    for(std::vector<Coordinates>::iterator it = coordinates_.begin() + 1;
        it != coordinates_.end(); ++it)
    {
      x_temp = (*it).getX();
      y_temp = (*it).getY();
      (*it).setX(-y_temp);
      (*it).setY(x_temp);
    }
  }
  
  if(!direction.compare("ccw"))
  {
    for(std::vector<Coordinates>::iterator it = coordinates_.begin() + 1;
        it != coordinates_.end(); ++it)
    {
      x_temp = (*it).getX();
      y_temp = (*it).getY();
      (*it).setX(y_temp);
      (*it).setY(-x_temp);
    }
  }

  move(x_start, y_start);
  
  return true;
}
