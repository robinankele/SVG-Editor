//------------------------------------------------------------------------------
/// Filename: LineCommand.h
/// Description: Header for Base Class LineCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#ifndef LINECOMMAND_H_INCLUDED
#define LINECOMMAND_H_INCLUDED

#include "Command.h"
#include "Coordinates.h"
#include <vector>

class UserInterface;
class Database;
class SVGHandler;
class Error;

//------------------------------------------------------------------------------
/// typedef to a vector of Coordinates 
typedef std::vector<Coordinates> SVGCoordinates;

class LineCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Connection to SVGHandler
  SVGHandler *svgh_;
  
  //----------------------------------------------------------------------------
  /// Connection to class Error
  Error *error_;
  
  //----------------------------------------------------------------------------
  ///  Vector with Startpoint Coordinates
  SVGCoordinates coordinates_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another LineCommand Object.
  /// @param source Original to copy.
  LineCommand(const LineCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one LineCommand to another
  /// @param source Original with values to copy.
  LineCommand &operator=(const LineCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVGHandler
  LineCommand(UserInterface *ui,
              Database *db, 
              SVGHandler *svgh);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~LineCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the LineCommand
  /// @return returns true if execute was correct
  virtual bool execute();
  
  //----------------------------------------------------------------------------
  /// This Function reads Params from UserInterface
  /// @param prompt the promp which should be displayed
  /// @return returns the readed integer value
  signed int readParam(std::string prompt);
};
#endif  //LINECOMMAND_H_INCLUDED
