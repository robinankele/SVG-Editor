//------------------------------------------------------------------------------
/// Filename: ResizeCommand.cpp
/// Description: Base Class for ResizeCommands
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include "ResizeCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "Error.h"

//------------------------------------------------------------------------------
ResizeCommand::ResizeCommand(UserInterface *ui, 
                             Database *db): Command(ui,db)
{
  name_.assign("resize");
  error_ = new Error();
}

//------------------------------------------------------------------------------
ResizeCommand::~ResizeCommand() throw()
{
  delete error_;
}

//------------------------------------------------------------------------------
bool ResizeCommand::execute()
{
  signed int int_value, group_id;
  std::string id, str_value;
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
  
  found = id.find("gr-");
  if(found != std::string::npos)
  {
    str_value = id.substr(found+3);
    if(!ui_->stringToSignedInt(str_value,group_id))
      return false;

   for(std::vector<SVGObject*>::iterator it =
       db_->getSVGObjectByGrp(group_id).begin();
       it != db_->getSVGObjectByGrp(group_id).end(); ++it)
    {
      if(!(*it)->resize())
        return false;
    }
  }
  else
  {
    signed int id_int;
    if(!ui_->stringToSignedInt(id, id_int))
      return false;
      
    if(!db_->getSVGObjectByID(id_int)->resize())
      return false;
  }
  return true;
}
