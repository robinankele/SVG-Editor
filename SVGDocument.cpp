//------------------------------------------------------------------------------
/// Filename: SVGDocument.cpp
/// Description: creates and writes the SVGDocument
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#include <sstream>
#include <iostream>
#include <fstream>
#include "SVGDocument.h"
#include "Error.h"
#include "Database.h"
#include "UserInterface.h"
#include "SVGObject.h"
#include "SVGHandler.h"
#include "ErrorCodes.h"

//------------------------------------------------------------------------------
SVGDocument::SVGDocument(Database *db,
                         SVGHandler *svgh) : db_(db),
                                             svgh_(svgh)
{
  try
  {
    error_ = new Error();
  }
  catch(std::bad_alloc& exception)
  {
    delete error_;
    svgh_->setErrors(OUT_OF_MEMORY);
  }
}

//------------------------------------------------------------------------------
SVGDocument::~SVGDocument() throw()
{
  if(error_)
    delete error_;
}

//------------------------------------------------------------------------------
std::string SVGDocument::getSVGHeader()
{
  std::stringstream header;
  header<<"<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n";
  header<<"  <!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "
        <<"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
  header<<"  <svg width=\""<<db_->getWidth()<<"\" height=\""<<db_->getHeight()
        <<"\" xmlns=\"http://www.w3.org/2000/svg\" "
        <<"xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n";
  return header.str();
}

//------------------------------------------------------------------------------
std::string SVGDocument::getSVGFooter()
{
  return std::string("  </svg>\n");
}

//------------------------------------------------------------------------------
bool SVGDocument::writeSVG()
{
  std::string filename, answer;
  signed int value = 0;

  ui_->getParam("  file? ", false, false, value, filename, false);
  if(checkOpen(filename))
  {
    while(true)
    { 
      error_->filenameExists(filename);
      ui_->getParam("", false, false, value, answer, false);
      
      if(!answer.compare("n"))
        return false;
      if(!answer.compare("y"))
        break;
    }
  }
  
  std::ofstream svg_file;
  svg_file.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
  if(svg_file.fail())
  {
    while(true)
    { 
      error_->cannotWriteToFile(filename);
      ui_->getParam("", false, false, value, answer, false);
      
      if(!answer.compare("n"))
        return false;
      if(!answer.compare("y"))
        return true;
    }
  }
     
  svg_file<<getSVGHeader();
  
  for(std::vector<SVGObject*>::iterator it = db_->getAllSVGObjects().begin(); 
      it != db_->getAllSVGObjects().end(); ++it)
  {
    svg_file<<(*it)->getSVGTag()<<"\n";
  }

  svg_file<<getSVGFooter();
  
  svg_file.close();
  return true;
}

//------------------------------------------------------------------------------
bool SVGDocument::checkOpen(std::string filename)
{
  std::fstream svg_file;
  svg_file.open (filename.c_str());
  if(svg_file.is_open())
  {
    svg_file.close();
    return true;
  }
  return false;
}
