//------------------------------------------------------------------------------
/// Filename: UserInterface.h
/// Description: Header for Class UserInterface
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED
  
#include <string>
#include <vector>

class Command;
class Database;
class SVGHandler;
class Error;
class SVGDocument;

class UserInterface 
{
private:
  //----------------------------------------------------------------------------
  /// Array of Commands
  std::vector<Command*> commands_;
  
  //----------------------------------------------------------------------------
  /// Is true if progamm runs otherwise false
  bool run_;

  //----------------------------------------------------------------------------
  /// Prompt which is displayed at userinput
  std::string prompt_;

  //----------------------------------------------------------------------------
  /// Connection to the Database
  Database *db_;

  //----------------------------------------------------------------------------
  /// Connection to the SVGDocument
  SVGDocument *svgdoc_;
  
  //----------------------------------------------------------------------------
  /// Connection to the SVGHandler
  SVGHandler *svgh_;

  //----------------------------------------------------------------------------
  /// Connection to the Errorclass
  Error *error_;

  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another UserInterface Object.
  /// @param source Original to copy.
  UserInterface(const UserInterface& source);

  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one UserInterface to another
  /// @param source Original with values to copy.
  UserInterface &operator=(const UserInterface& source);

public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param db Connection to Database
  /// @param svgdoc Connection to SVGDocument
  /// @param svgh Connection to SVGHandler
  /// @param prompt inputprompt for commandline
  UserInterface(Database *db, 
                SVGDocument *svgdoc, 
                SVGHandler *svgh,
                std::string prompt);

  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~UserInterface();

  //----------------------------------------------------------------------------
  /// Function run()
  /// A Infinity Loop which checks the commands 
  /// @return returns void
  void run();
  
  //----------------------------------------------------------------------------
  /// Function getString()
  ///  Read the userinput into a string
  /// @return : returns the userinput
  std::string getString();

  //----------------------------------------------------------------------------
  /// Function checkCommand()
  /// Checks if a Command is entered
  /// @param name is the name of the command which should be checked
  /// @return true if a command was found otherwise false
  bool checkCommand(std::string& name);

  //----------------------------------------------------------------------------
  /// stringToSignedInt(): convert a string into an integer.
  /// @param  string_number  the string which might contain a number
  /// @param  value       the result will be written to this variable
  /// @return                true if successful, false otherwise
  bool stringToSignedInt(std::string& string_number, signed int& value);

  //----------------------------------------------------------------------------
  /// Function setRun()
  /// sets run_ = false stop the program
  void setRun(bool run) {run_ = run;}
  
  //----------------------------------------------------------------------------
  /// Function getStringParam()
  /// Checks if a string is empty and returns the string
  /// @param prompt which is displayd to user for input
  /// @param polygon is true if polygon is selected and false if an e is typed
  /// @param mod_command is true if a modificating command call the method
  /// @param int_value is the converted integer
  /// @param str_value is the user typed string
  /// @param conv_int is true if an integer should converted
  /// @return returns true if a string or integer is correct converted
  bool getParam(std::string prompt, bool polygon, bool mod_command,
                signed int &int_value, std::string &str_value, bool conv_int);

//----------------------------------------------------------------------------
  /// Function checkID()
  /// Checks if a ID is correct entered
  /// @param id is the user typed id
  /// @return returns true if the id was correct
  bool checkID(std::string id);
  
//----------------------------------------------------------------------------
  /// Function checkIfIdExists()
  /// Checks if a ID already exists or even exists
  /// @return returns true if the id exists and false if not
  bool checkIfIdExists(std::string id);
};
#endif  //USERINTERFACE_H_INCLUDED
