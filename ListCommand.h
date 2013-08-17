//------------------------------------------------------------------------------
/// Filename: ListCommand.h
/// Description: Header for Base Class ListCommand
/// Authors:
///          Robin Ankele (0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef LISTCOMMAND_H_INCLUDED
#define LISTCOMMAND_H_INCLUDED

#include "Command.h"

class UserInterface;
class Database;

class ListCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another ListCommand Object.
  /// @param source Original to copy.
  ListCommand(const ListCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one ListCommand to another
  /// @param source Original with values to copy.
  ListCommand &operator=(const ListCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  ListCommand(UserInterface *ui, Database *db);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~ListCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the ListCommand
  /// @return returns true if execute was correct
  virtual bool execute();
};
#endif  //LISTCOMMAND_H_INCLUDED
