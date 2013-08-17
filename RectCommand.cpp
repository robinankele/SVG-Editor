//------------------------------------------------------------------------------
/// Filename: RectCommand.cpp
/// Description: Base Class for RectCommands
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#include "RectCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGHandler.h"
#include "SVGRect.h"
#include "Coordinates.h"
#include "ErrorCodes.h"
#include "Error.h"

//------------------------------------------------------------------------------
RectCommand::RectCommand(UserInterface *ui, 
                         Database *db, 
                         SVGHandler *svgh): Command(ui,db),
                                            svgh_(svgh)
{
  name_.assign("rect");
  error_ = new Error();
}

//------------------------------------------------------------------------------
RectCommand::~RectCommand() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool RectCommand::execute()
{
  signed int id, group_id, x, y, width, height, int_value;
  std::string fill, stroke, id_str, stroke_width;
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
    if(ui_->stringToSignedInt(id_str, id))
      break;
    error_->invalidParameter();
  }
  
  x = readParam("  x? ");
  coord->setX(x);
  
  y = readParam("  y? ");
  coord->setY(y);
  
  coordinates_.push_back(*coord);
  delete coord;
  
  width = readParam("  width? ");
  height = readParam("  height? ");
  ui_->getParam("  fill? ", false, false, int_value, fill, false);
  ui_->getParam("  stroke? ", false, false, int_value, stroke, false);
  ui_->getParam("  stroke-width? ", false, false, int_value, stroke_width,
                false);
  group_id = readParam("  group? ");

  try
  {
    SVGRect *rect = new SVGRect(ui_, db_, svgh_, id, group_id, coordinates_,
                                width, height, fill, stroke, stroke_width);
    db_->setSVGObject(rect);
    coordinates_.clear();
  }
  catch(std::bad_alloc& exception)
  {
    svgh_->setErrors(OUT_OF_MEMORY);
  }
  return true;
}

//------------------------------------------------------------------------------
signed int RectCommand::readParam(std::string prompt)
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
