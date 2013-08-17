//------------------------------------------------------------------------------
/// Filename: MoveCommand.h
/// Description: Header for Base Class MoveCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef MOVECOMMAND_H_INCLUDED
#define MOVECOMMAND_H_INCLUDED

#include "Command.h"

class UserInterface;
class Database;
class Error;

class MoveCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Connection to class Error
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another MoveCommand Object.
  /// @param source Original to copy.
  MoveCommand(const MoveCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one MoveCommand to another
  /// @param source Original with values to copy.
  MoveCommand &operator=(const MoveCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  MoveCommand(UserInterface *ui, 
              Database *db);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~MoveCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the MoveCommand
  /// @return returns true if execute was correct
  virtual bool execute();
};
#endif  //MOVECOMMAND_H_INCLUDED
