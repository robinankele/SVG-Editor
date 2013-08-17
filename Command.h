//------------------------------------------------------------------------------
/// Filename: Command.h
/// Description: Header for Base Class Command
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>

class Database;
class UserInterface;

class Command
{
private:
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another Command Object.
  /// @param source Original to copy.
  Command(const Command& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one Command to another
  /// @param source Original with values to copy.
  Command &operator=(const Command& source);

protected:
  //----------------------------------------------------------------------------
  /// Connection to UserInterface
  UserInterface* ui_;
  
  //----------------------------------------------------------------------------
  /// Connection to Database
  Database *db_;
  
  //----------------------------------------------------------------------------
  ///  Name of Command
  std::string name_;
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  Command(UserInterface *ui, 
          Database *db) : ui_(ui),
                          db_(db) {}
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~Command() throw() {}
  
  //----------------------------------------------------------------------------
  /// This Function executes the Command
  /// @return returns true if execute was correct
  virtual bool execute() { return false;}
  
  //----------------------------------------------------------------------------
  /// Function getName()
  /// @return The commands name
  std::string getName() { return name_;}
};
#endif  //COMMAND_H_INCLUDED
