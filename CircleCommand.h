//------------------------------------------------------------------------------
/// Filename: CircleCommand.h
/// Description: Header for Base Class CircleCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#ifndef CIRCLECOMMAND_H_INCLUDED
#define CIRCLECOMMAND_H_INCLUDED

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

class CircleCommand: public Command
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
  /// Makes a copy of another CircleCommand Object.
  /// @param source Original to copy.
  CircleCommand(const CircleCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one CircleCommand to another
  /// @param source Original with values to copy.
  CircleCommand &operator=(const CircleCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVGHandler
  CircleCommand(UserInterface *ui, 
                Database *db, 
                SVGHandler *svgh);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~CircleCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the CircleCommand
  /// @return returns true if execute was correct
  virtual bool execute();
  
  //----------------------------------------------------------------------------
  /// This Function reads Params from UserInterface
  /// @param prompt the promp which should be displayed
  /// @return returns the readed integer value
  signed int readParam(std::string prompt);
};
#endif  //CIRCLECOMMAND_H_INCLUDED
