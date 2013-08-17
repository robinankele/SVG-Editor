//------------------------------------------------------------------------------
/// Filename: SVGHandler.cpp
/// Description: Is the Handler of the Progam
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include "SVGHandler.h"
#include "Database.h"
#include "SVGDocument.h"
#include "Error.h"
#include "UserInterface.h"
#include "ConfigFileException.h"
#include "ErrorCodes.h"

//------------------------------------------------------------------------------
SVGHandler::SVGHandler(unsigned int arg_count,
                       char **parameters) : ui_(NULL),
                                            db_(NULL),
                                            svgdoc_(NULL),
                                            errors_(0)
{
  try
  {
    error_ = new Error();
    if(arg_count < 2 || arg_count > 3)
    {
      errors_ = USAGE_CONFIG_FILE;
      throw ConfigFileException();
    }
    
    std::string parameter(parameters[1]);
    if(!checkParameter(parameter))
    {
      errors_ = USAGE_CONFIG_FILE;
      throw ConfigFileException();
    }
    
    db_ = new Database(parameter, this);
    if(!db_->checkConfigFile())
    { 
      errors_ = CANNOT_READ_CONFIG_FILE;
      throw ConfigFileException();
    }
    if(!db_->readConfigFile())
    {
      if(errors_ != OUT_OF_MEMORY)
        errors_ = CONFIG_FILE_CORRUPT;
      throw ConfigFileException();
    }
    
    svgdoc_ = new SVGDocument(db_, this);
    ui_ = new UserInterface(db_, svgdoc_, this, prompt_);
    
    if(errors_ != OUT_OF_MEMORY)
    {
      svgdoc_->setUI(ui_);
      ui_->run();
    }
  }
  catch(std::bad_alloc& exception)
  {
    errors_ = OUT_OF_MEMORY;
  }
  catch(ConfigFileException& exception)
  {
  }
}

//------------------------------------------------------------------------------
SVGHandler::~SVGHandler() throw()
{
  freeMemory();
}

//------------------------------------------------------------------------------
bool SVGHandler::checkParameter(std::string parameter)
{
  if(!parameter.compare(0,3,"-c="))
    return true;
  return false;
}

//------------------------------------------------------------------------------
void SVGHandler::freeMemory()
{
  if(error_)
    delete error_;
  if(db_)
    delete db_;
  if(svgdoc_)
    delete svgdoc_;
  if(ui_)
    delete ui_;
}
