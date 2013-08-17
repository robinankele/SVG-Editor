//------------------------------------------------------------------------------
/// Filename: QuitCommand.cpp
/// Description: Base Class for QuitCommands
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 09.09.2011
//------------------------------------------------------------------------------

#include "QuitCommand.h"
#include "UserInterface.h"
#include "Database.h"
#include "SVGDocument.h"

//------------------------------------------------------------------------------
QuitCommand::QuitCommand(UserInterface *ui,
                         Database *db, 
                         SVGDocument *svgdoc): Command(ui,db),
                                               svgdoc_(svgdoc)
{
  name_.assign("quit");
}

//------------------------------------------------------------------------------
QuitCommand::~QuitCommand() throw()
{
}

//------------------------------------------------------------------------------
bool QuitCommand::execute()
{
  if(!svgdoc_->writeSVG())
    return false;
  else
    ui_->setRun(false);
  
  return true;
}
