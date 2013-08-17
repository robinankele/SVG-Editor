//------------------------------------------------------------------------------
/// Filename: main.cpp 
/// Description: Main Function
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include <string>
#include "SVGHandler.h"
#include "Error.h"
#include "ErrorCodes.h"

//------------------------------------------------------------------------------
/// Main Function
/// @return returns an errorcode
/// @param argc number of parameters
/// @param argv parameters
int main(unsigned int argc, char *argv[])
{
  signed int errorcode = SUCCESS;
  SVGHandler *svghandler = NULL;
  Error *error = NULL;
  std::string filename;

  try
  {
    error = new Error();
    svghandler = new SVGHandler(argc, argv);
    errorcode = svghandler->getErrors();
    
    if(errorcode != USAGE_CONFIG_FILE)
      filename.assign(svghandler->getDB()->getFilename());
    
    delete svghandler;
  }
  catch(std::bad_alloc& exception)
  {
    if(error)
    {
      errorcode = OUT_OF_MEMORY;
      delete error;
    }
    if(svghandler)
      delete svghandler;
  }
  
  switch(errorcode)
  {
    case SUCCESS:
      break; 
    case USAGE_CONFIG_FILE:
      error->usageConfigFile();
      break; 
    case OUT_OF_MEMORY:
      error->outOfMemory();
      break; 
    case CANNOT_READ_CONFIG_FILE:
      error->cannotReadConfigFile(filename);
      break;
    case CONFIG_FILE_CORRUPT:
      error->configFileCorrupt(filename);
      break;
    default:
      break;
  }
  delete error;

  return errorcode;
}
