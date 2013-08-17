//------------------------------------------------------------------------------
/// Filename: PolygonCommand.cpp
/// Description: Base Class for PolygonCommands
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#include "PolygonCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include "SVGPolygon.h"
#include "ErrorCodes.h"
#include "Error.h"
#include <sstream>
#include <iostream>

//------------------------------------------------------------------------------
PolygonCommand::PolygonCommand(UserInterface *ui, 
                               Database *db,
                               SVGHandler *svgh): Command(ui,db),
                                                  svgh_(svgh)
{
  name_.assign("polygon");
  error_ = new Error();
}

//------------------------------------------------------------------------------
PolygonCommand::~PolygonCommand() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool PolygonCommand::execute()
{
  signed int id, group_id, int_value;
  std::string fill, str_value, id_str;

  while(true)
  {
    while(true)
    {
      ui_->getParam("  id? ", false, false, int_value, id_str, false);
      
      if(!ui_->checkIfIdExists(id_str))
        break;
      error_->idAlreadyExist();
    }
    if(ui_->stringToSignedInt(id_str, id))
      break;
    error_->invalidParameter();
  }
  
  readCoordinates();
  ui_->getParam("  fill? ", true, false, int_value, fill, false);
  
  while(true)
  {
    if(ui_->getParam("  group? ", false, false, group_id, str_value, true))
      break;
  }

  try
  {
    SVGPolygon *polygon = new SVGPolygon(ui_, db_, svgh_, id, group_id,
                                         coordinates_, fill);
    db_->setSVGObject(polygon);
    coordinates_.clear();
  }
  catch(std::bad_alloc& exception)
  {
    svgh_->setErrors(OUT_OF_MEMORY);
  }
  return true;
}

//------------------------------------------------------------------------------
void PolygonCommand::readCoordinates()
{
  Coordinates *coord = new Coordinates(0,0);
  unsigned int count = 0;
  signed int x = 0, y = 0, int_value = 0;
  std::string x_str, y_str;
  bool end_polygon = false;
  
  while(true)
  {
    while(true)
    {
      if(!ui_->getParam("  x? ", true, false, int_value, x_str, false))
        end_polygon = true;
      else
      {
        if(!ui_->stringToSignedInt(x_str, x))
          error_->invalidParameter();
        break;
      }
      
      if(end_polygon)
      {
        end_polygon = false;
        if(count == 0)
          error_->invalidParameter();
        else
        {
          delete coord;
          return;
        }
      }
    }
    coord->setX(x);

    while(true)
    {
      if(!ui_->getParam("  y? ", true, false, int_value, y_str, false))
        end_polygon = true;
      else
      {
        if(!ui_->stringToSignedInt(y_str, y))
          error_->invalidParameter();
        break;
      }
      
      if(end_polygon)
      {
        end_polygon = false;
        if(count == 0)
          error_->invalidParameter();
        else
        {
          delete coord;
          return;
        }
      }
    }
    coord->setY(y);
      
    count++;
    coordinates_.push_back(*coord);
  }
}
