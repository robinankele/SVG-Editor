//------------------------------------------------------------------------------
/// Filename: ResizeCommand.h
/// Description: Header for Base Class ResizeCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef RESIZECOMMAND_H_INCLUDED
#define RESIZECOMMAND_H_INCLUDED

#include "Command.h"

class UserInterface;
class Database;
class Error;

class ResizeCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Connection to Errorclass
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another ResizeCommand Object.
  /// @param source Original to copy.
  ResizeCommand(const ResizeCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one ResizeCommand to another
  /// @param source Original with values to copy.
  ResizeCommand &operator=(const ResizeCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  ResizeCommand(UserInterface *ui,
                Database *db);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~ResizeCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the ResizeCommand
  /// @return returns true if execute was correct
  virtual bool execute();
};
#endif  //RESIZECOMMAND_H_INCLUDED
