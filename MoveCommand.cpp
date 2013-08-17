//------------------------------------------------------------------------------
/// Filename: MoveCommand.cpp
/// Description: Base Class for MoveCommands
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include "MoveCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "Error.h"

//------------------------------------------------------------------------------
MoveCommand::MoveCommand(UserInterface *ui,
                         Database *db): Command(ui,db)
{
  name_.assign("move");
  error_ = new Error();
}

//------------------------------------------------------------------------------
MoveCommand::~MoveCommand() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool MoveCommand::execute()
{
  signed int x, y, int_value, group_id;
  std::string id, str_value, x_str, y_str;
  size_t found;
  
  while(true)
  {
    if(!ui_->getParam("  id? ", false, true, int_value, id, false))
      return false;
    if(ui_->checkID(id))
    {
      if(ui_->checkIfIdExists(id))
        break;
      error_->idDoesnotExist();
    }
  }
  
  while(true)
  {
    ui_->getParam("  x? ", false, false, int_value, x_str, false);
    if(ui_->stringToSignedInt(x_str, x))
      break;
    error_->invalidParameter();
  }
  
  while(true)
  {
    ui_->getParam("  y? ", false, false, int_value, y_str, false);
    if(ui_->stringToSignedInt(y_str, y))
      break;
    error_->invalidParameter();
  }
  
  found = id.find("gr-");
  if(found != std::string::npos)
  {
    str_value = id.substr(found + 3);
    if(!ui_->stringToSignedInt(str_value, group_id))
      return false;

    for(std::vector<SVGObject*>::iterator it = db_->getSVGObjectByGrp(group_id)
        .begin(); it != db_->getSVGObjectByGrp(group_id).end(); ++it)
    {
      if(!((*it)->move(x, y)))
        return false;
    }
  }
  else
  {
    signed int object_id = 0;
    ui_->stringToSignedInt(id, object_id);
    
    if(!db_->getSVGObjectByID(object_id)->move(x, y))
      return false;
  }
  
  return true;
}
