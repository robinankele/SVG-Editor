//------------------------------------------------------------------------------
/// Filename: RotateCommand.cpp
/// Description: Base Class for RotateCommands
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include "RotateCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "Error.h"

//------------------------------------------------------------------------------
RotateCommand::RotateCommand(UserInterface *ui, 
                             Database *db): Command(ui,db)
{
  name_.assign("rotate");
  error_ = new Error();
}

//------------------------------------------------------------------------------
RotateCommand::~RotateCommand() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool RotateCommand::execute()
{
  signed int int_value, group_id;
  std::string id, str_value, direction;
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
    ui_->getParam("  cw/ccw? ", false, false, int_value, direction, false);
    if(!direction.compare("cw") || !direction.compare("ccw"))
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
      if(!((*it)->rotate(direction)))
        return false;
    }
  }
  else
  {
    signed int object_id = 0;
    ui_->stringToSignedInt(id, object_id);
    
    if(!db_->getSVGObjectByID(object_id)->rotate(direction))
      return false;
  }
  return true;
}
