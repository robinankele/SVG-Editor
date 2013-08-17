//------------------------------------------------------------------------------
/// Filename: PolygonCommand.h
/// Description: Header for Base Class PolygonCommand
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#ifndef POLYGONCOMMAND_H_INCLUDED
#define POLYGONCOMMAND_H_INCLUDED

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

class PolygonCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Connection to SVGHandler
  SVGHandler *svgh_;
  
  //----------------------------------------------------------------------------
  /// Connection to class Error
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Vector with Startpoint Coordinates
  SVGCoordinates coordinates_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another PolygonCommand Object.
  /// @param source Original to copy.
  PolygonCommand(const PolygonCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one PolygonCommand to another
  /// @param source Original with values to copy.
  PolygonCommand &operator=(const PolygonCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVGHandler
  PolygonCommand(UserInterface *ui,
                 Database *db, 
                 SVGHandler *svgh);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~PolygonCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the PolygonCommand
  /// @return returns true if execute was correct
  virtual bool execute();
  
  //----------------------------------------------------------------------------
  /// This Function reads the Coordinates of a Polygon
  void readCoordinates();
};
#endif  //POLYGONCOMMAND_H_INCLUDED
