//------------------------------------------------------------------------------
/// Filename: SVGHandler.h
/// Description: Header for Class SVGHandler
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef SVGHANDLER_H_INCLUDED
#define SVGHANDLER_H_INCLUDED

#include <string>
#include "Database.h"

class Error;
class UserInterface;
class SVGDocument;

class SVGHandler
{
private:  
  //----------------------------------------------------------------------------
  /// Connection to the Errorclass
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Connection to the UserInterface
  UserInterface *ui_;
  
  //----------------------------------------------------------------------------
  /// Connection to the Database
  Database *db_;
  
  //----------------------------------------------------------------------------
  /// Connection to the SVGDocument
  SVGDocument *svgdoc_;
  
  //----------------------------------------------------------------------------
  /// Errorflag
  signed int errors_;
  
  //----------------------------------------------------------------------------
  /// Prompt of Config File
  std::string prompt_;

  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another SVGHandler Object.
  /// @param source Original to copy.
  SVGHandler(const SVGHandler& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one SVGHandler to another
  /// @param source Original with values to copy.
  SVGHandler &operator=(const SVGHandler& source);

public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param arg_count is the count of commandline arguments
  /// @param parameters contains the commandline arguments
  SVGHandler(unsigned int arg_count, 
             char **parameters);
  
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGHandler() throw();
  
  //----------------------------------------------------------------------------
  /// getErrors() Method: returns any errorcode
  /// @return returns errorcode for main.cpp
  signed int getErrors() { return errors_;}
  
  //----------------------------------------------------------------------------
  /// setErrors() Method: sets Errorcode
  /// @param errorcode the submited errorcode
  /// @return returns void
  void setErrors(signed int errorcode) { errors_ = errorcode;}
  
  //----------------------------------------------------------------------------
  /// checkParameter() Method: checks the command line parameter
  /// @param parameter is the content of the commandline parameter 
  /// @return true if Commandline Parameters are correct
  bool checkParameter(std::string parameter);
  
  //----------------------------------------------------------------------------
  /// getDB() GetterMethod: returns a Database handle
  /// @return returns a Database handle
  Database* getDB() { return db_;}
  
  //----------------------------------------------------------------------------
  /// freeMemory() Method: frees the memory
  /// @return returns void
  void freeMemory();
  
  //----------------------------------------------------------------------------
  /// setPrompt() setterMethod: sets the prompt of Config File
  /// @param prompt the prompt of the Config File
  /// @return returns void
  void setPrompt(std::string prompt) { prompt_.assign(prompt);}
};
#endif // SVGHANDLER_H_INCLUDED
