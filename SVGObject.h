//------------------------------------------------------------------------------
/// Filename: SVGObject.h
/// Description: Header for Base Class SVGObject
/// Authors:
///         Ralph Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#ifndef SVGOBJECT_H_INCLUDED
#define SVGOBJECT_H_INCLUDED

#include <string>
#include <vector>
#include <sstream>
#include "Coordinates.h"

class UserInterface;
class Database;
class SVGHandler;

class SVGObject 
{ 
protected:
  //----------------------------------------------------------------------------
  /// Connection to UserInterface
  UserInterface *ui_;
  
  //----------------------------------------------------------------------------
  /// Connection to Database
  Database *db_;
  
  //----------------------------------------------------------------------------
  /// Connection to the SVGHandler
  SVGHandler *svgh_;
  
  //----------------------------------------------------------------------------
  /// Identifier
  signed int id_;
  
  //----------------------------------------------------------------------------
  /// Group Identifier
  signed int group_id_;
  
  //----------------------------------------------------------------------------
  /// Coordinates for the Startpoint
  std::vector<Coordinates> coordinates_;
  
  //----------------------------------------------------------------------------
  /// svg tag of objects
  std::stringstream tag_;
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVHHandler
  /// @param id id of the object
  /// @param group_id group id of the object
  /// @param coordinates vector with coordinates of the object
  SVGObject(UserInterface *ui,
            Database *db,
            SVGHandler *svgh,
            signed int id,
            signed int group_id,
            std::vector<Coordinates> coordinates);

  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGObject() throw();
  
  //----------------------------------------------------------------------------
  /// move Method: moves the SVG Object 
  /// @param x is the x direction in which is moved
  /// @param y is the y direction in which is moved
  /// @return returns true if move is correct
  virtual bool move(signed int x, signed int y);
  
  //----------------------------------------------------------------------------
  /// resize Method: resizes the SVG Object 
  /// @return returns true if resize was correct
  virtual bool resize() { return true;}
  
  //----------------------------------------------------------------------------
  /// rotate Method: rotates the SVG Object 
  /// @param direction is the direction in which the object rotates
  /// @return returns true if rotate was correct
  virtual bool rotate(std::string direction);

  //----------------------------------------------------------------------------
  /// getSVGTag returns the svg tag of the object
  /// @return returns the svg tag as string
  virtual std::string getSVGTag() { return NULL; }
  
  //----------------------------------------------------------------------------
  /// getID returns the id of a SVGObject
  /// @return returns the id
  signed int getID() { return id_; }
  
  //----------------------------------------------------------------------------
  /// getGrpID returns the group of a SVGObject
  /// @return returns the group
  signed int getGrpID() { return group_id_; }
  
  //----------------------------------------------------------------------------
  /// getCoordinates() returns the coordinates of SVGObject
  /// @return returns the coordinates
  std::vector<Coordinates>& getCoordinates() { return coordinates_;}
};
#endif // SVGOBJECT_H_INCLUDED
