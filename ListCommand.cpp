//------------------------------------------------------------------------------
/// Filename: ListCommand.cpp
/// Description: Base Class for ListCommands
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 18.09.2011
//------------------------------------------------------------------------------

#include <iostream>
#include "ListCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGObject.h"

//------------------------------------------------------------------------------
ListCommand::ListCommand(UserInterface *ui,
                         Database *db): Command(ui,db)
{
  name_.assign("list");
}

//------------------------------------------------------------------------------
ListCommand::~ListCommand() throw()
{
}

//------------------------------------------------------------------------------
bool ListCommand::execute()
{
  std::vector<SVGObject*> svg_objects = db_->getAllSVGObjects();
  
  if(svg_objects.empty())
    return false;
    
  for(std::vector<SVGObject*>::iterator it = svg_objects.begin(); 
      it != svg_objects.end(); ++it)
  {
    std::cout<<"[gr-"<<(*it)->getGrpID()<<"]["<<(*it)->getID()<<std::flush
             <<"] "<<(*it)->getCoordinates().front().getX()<<std::flush
             <<" "<<(*it)->getCoordinates().front().getY()<<std::endl;
  }
  return true;
}
