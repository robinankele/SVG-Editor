//------------------------------------------------------------------------------
/// Filename: UserInterface.cpp
/// Description: Class UserInterface
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include "UserInterface.h"
#include "SVGDocument.h"
#include "SVGObject.h"
#include "Database.h"
#include "SVGHandler.h"
#include "LineCommand.h"
#include "CircleCommand.h"
#include "RectCommand.h"
#include "PolygonCommand.h"
#include "MoveCommand.h"
#include "ResizeCommand.h"
#include "RotateCommand.h"
#include "ListCommand.h"
#include "QuitCommand.h"
#include "Command.h"
#include "ErrorCodes.h"
#include "Error.h"

#include <iostream>
#include <sstream>


//------------------------------------------------------------------------------
UserInterface::UserInterface(Database *db,
                             SVGDocument *svgdoc,
                             SVGHandler *svgh,
                             std::string prompt) : run_(true),
                                                   db_(db),
                                                   svgdoc_(svgdoc),
                                                   svgh_(svgh)
{
  prompt_.assign(prompt);
  
  try
  {
    error_ = new Error();
    commands_.push_back(new LineCommand(this, db_, svgh_));
    commands_.push_back(new CircleCommand(this, db_, svgh_));
    commands_.push_back(new RectCommand(this, db_, svgh_));
    commands_.push_back(new PolygonCommand(this, db_, svgh_));
    commands_.push_back(new MoveCommand(this, db_));
    commands_.push_back(new ResizeCommand(this, db_));
    commands_.push_back(new RotateCommand(this, db_));
    commands_.push_back(new ListCommand(this, db_));
    commands_.push_back(new QuitCommand(this, db_, svgdoc_));
  }
  catch (std::bad_alloc& exception)
  {
    delete error_;
    svgh_->setErrors(OUT_OF_MEMORY);
    
    for (size_t count = 0; count < commands_.size(); ++count)
      delete commands_[count];
  }
}

//------------------------------------------------------------------------------
UserInterface::~UserInterface()
{
  delete error_;
  
  for (size_t count = 0; count < commands_.size(); ++count)
  {
    delete commands_[count];
  }
}

//------------------------------------------------------------------------------
void UserInterface::run()
{
  std::string input;
  bool command = true;

  while(run_)
  {
    while(command)
    {
      std::cout << prompt_ << "> "<< std::flush;
      input = getString();
      
      if(input.empty())
        command = true;
      else if(checkCommand(input))
        command = false;
    }
    command = true;
  }
}
  
//------------------------------------------------------------------------------
std::string UserInterface::getString()
{
  std::string input;
  
  getline(std::cin, input);
  return input;
}

//------------------------------------------------------------------------------
bool UserInterface::checkCommand(std::string& name)
{
  for (std::vector<Command*>::iterator it = commands_.begin();
       it != commands_.end(); ++it)
  {
    if(!((*it)->getName()).compare(name))
    {
      if(!(*it)->execute())
        return false;
      return true;
    }
  }
  
  error_->unknownCommand();
  return false;
}

//------------------------------------------------------------------------------
bool UserInterface::stringToSignedInt(std::string& string_number,
                                        signed int& value)
{
  std::stringstream stream(string_number);
  stream >> value;
  
  if(stream.fail() || !stream.eof())
  {
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
bool UserInterface::getParam(std::string prompt, bool polygon, bool mod_command,
                             signed int& int_value, std::string& str_value,
                             bool conv_int)
{
  std::string input;

  while(true)
  {
    std::cout << prompt << std::flush;
    input = getString();

    if(mod_command && input.empty())
      return false;
    if(!input.empty())
      break;
  }
  
  if(polygon)
  {
    if(!input.compare("e"))
      return false;
  }
  
  if(conv_int)
  {
    if(!stringToSignedInt(input, int_value))
    {
      error_->invalidParameter();
      return false;
    }    
  }
  
  str_value.assign(input);
  return true;
}

//------------------------------------------------------------------------------
bool UserInterface::checkID(std::string id)
{
  signed int int_value;
  std::string group_id;

  if(stringToSignedInt(id,int_value))
    return true;
    
  if(id.compare(0, 3, "gr-"))
  {
    error_->invalidParameter();
    return false;
  }
  
  group_id = id.substr(3);  
  if(!stringToSignedInt(group_id, int_value))
  {
    error_->invalidParameter();
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
bool UserInterface::checkIfIdExists(std::string id)
{
  signed int id_int = 0;
  std::string group_id;
  
  if(db_->getAllSVGObjects().empty())
    return false;
    
  if(!id.compare(0, 3, "gr-"))
  {
    group_id = id.substr(3); 
    stringToSignedInt(group_id, id_int);
    
    for(std::vector<SVGObject*>::iterator it = db_->getAllSVGObjects().begin();
        it != db_->getAllSVGObjects().end(); ++it)
    {
      if((*it)->getGrpID() == id_int)
        return true;
    }
  }
  else
  {
    stringToSignedInt(id, id_int);
    for(std::vector<SVGObject*>::iterator it = db_->getAllSVGObjects().begin();
        it != db_->getAllSVGObjects().end(); ++it)
    {
      if((*it)->getID() == id_int)
        return true;
    }
  }
  return false;
}
