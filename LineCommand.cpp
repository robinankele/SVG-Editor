//------------------------------------------------------------------------------
/// Filename: LineCommand.cpp
/// Description: Base Class for LineCommands
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#include "LineCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include "SVGLine.h"
#include "ErrorCodes.h"
#include "Error.h"
#include <sstream>
#include <iostream>

//------------------------------------------------------------------------------
LineCommand::LineCommand(UserInterface *ui, 
                         Database *db, 
                         SVGHandler *svgh): Command(ui,db),
                                            svgh_(svgh)
{
  name_.assign("line");
  error_ = new Error();
}

//------------------------------------------------------------------------------
LineCommand::~LineCommand() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool LineCommand::execute()
{
  signed int id, group_id, x, y, int_value;
  std::string id_str;
  Coordinates *coord = new Coordinates(0,0);
  
  while(true)
  {
    while(true)
    {
      ui_->getParam("  id? ", false, false, int_value, id_str, false);
      if(!ui_->checkIfIdExists(id_str))
        break;
      error_->idAlreadyExist();
    }
    if(ui_->stringToSignedInt(id_str,id))
      break;
    error_->invalidParameter();
  }

  for(unsigned int count = 1; count < 3; count++)
  {
    std::stringstream param_x;
    param_x << "  x"<< count <<"? ";
    
    x = readParam(param_x.str());
    coord->setX(x);
    
    std::stringstream param_y;
    param_y << "  y"<< count <<"? ";
    
    y = readParam(param_y.str());
    coord->setY(y);
    
    coordinates_.push_back(*coord);
  }
  
  group_id = readParam("  group? ");
  delete coord;
 
  try
  {
    SVGLine *line = new SVGLine(ui_, db_, svgh_, id, group_id, coordinates_);
    db_->setSVGObject(line);
    coordinates_.clear();
  }
  catch(std::bad_alloc& exception)
  {
    svgh_->setErrors(OUT_OF_MEMORY);
  }
  return true;
}

//------------------------------------------------------------------------------
signed int LineCommand::readParam(std::string prompt)
{
  signed int param = 0;
  std::string str_value;
  
  while(true)
  {
    if(ui_->getParam(prompt, false, false, param, str_value, true))
      break;
  }
  
  return param;
}
