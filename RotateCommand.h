//------------------------------------------------------------------------------
/// Filename: RotateCommand.h
/// Description: Header for Base Class RotateCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef ROTATECOMMAND_H_INCLUDED
#define ROTATECOMMAND_H_INCLUDED

#include "Command.h"

class UserInterface;
class Database;
class Error;

class RotateCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Connection to Errorclass
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another RotateCommand Object.
  /// @param source Original to copy.
  RotateCommand(const RotateCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one RotateCommand to another
  /// @param source Original with values to copy.
  RotateCommand &operator=(const RotateCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  RotateCommand(UserInterface *ui, 
                Database *db);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~RotateCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the RotateCommand
  /// @return returns true if execute was correct
  virtual bool execute();
};
#endif  //ROTATECOMMAND_H_INCLUDED
