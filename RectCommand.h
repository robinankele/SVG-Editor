//------------------------------------------------------------------------------
/// Filename: RectCommand.h
/// Description: Header for Base Class RectCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#ifndef RECTCOMMAND_H_INCLUDED
#define RECTCOMMAND_H_INCLUDED

#include <vector>
#include "Command.h"

class UserInterface;
class Database;
class SVGHandler;
class Coordinates;
class Error;

//------------------------------------------------------------------------------
/// typedef to a vector of Coordinates 
typedef std::vector<Coordinates> SVGCoordinates;

class RectCommand: public Command
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
  /// Makes a copy of another RectCommand Object.
  /// @param source Original to copy.
  RectCommand(const RectCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one RectCommand to another
  /// @param source Original with values to copy.
  RectCommand &operator=(const RectCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVGHandler
  RectCommand(UserInterface *ui, 
              Database *db, 
              SVGHandler *svgh);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~RectCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the RectCommand
  /// @return returns true if execute was correct
  virtual bool execute();
  
  //----------------------------------------------------------------------------
  /// This Function reads Params from UserInterface
  /// @param prompt the promp which should be displayed
  /// @return returns the readed integer value
  signed int readParam(std::string prompt);
};
#endif  //RECTCOMMAND_H_INCLUDED
