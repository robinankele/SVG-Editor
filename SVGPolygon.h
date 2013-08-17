//------------------------------------------------------------------------------
/// Filename: SVGPolygon.h
/// Description: Header for Class SVGPolygon
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#ifndef SVGPOLYGON_H_INCLUDED
#define SVGPOLYGON_H_INCLUDED

#include "SVGObject.h"

class Error;

class SVGPolygon: public SVGObject
{
private:
  //----------------------------------------------------------------------------
  /// fill color for Polygon 
  std::string fill_;
  
  //----------------------------------------------------------------------------
  /// Connection to class Error
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another SVGPolygon Object.
  /// @param source Original to copy.
  SVGPolygon(const SVGPolygon& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one SVGPolygon to another
  /// @param source Original with values to copy.
  SVGPolygon &operator=(const SVGPolygon& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVHHandler
  /// @param id id of the object
  /// @param group_id group id of the object
  /// @param coordinates vector with coordinates of the object
  /// @param fill is the fill color of the object
  SVGPolygon(UserInterface *ui,
             Database *db,
             SVGHandler *svgh,
             signed int id,
             signed int group_id,
             std::vector<Coordinates> coordinates,
             std::string fill);
  
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGPolygon() throw();
  
  //----------------------------------------------------------------------------
  /// resize Method: resizes the SVG Object 
  /// @return returns true if resize fits
  virtual bool resize();
  
  //----------------------------------------------------------------------------
  /// move() Method: moves the SVG Object 
  /// @param x is the x direction in which is moved
  /// @param y is the y direction in which is moved
  /// @return returns true if move is correct
  virtual bool move(signed int x, signed int y);
  
  //----------------------------------------------------------------------------
  /// getSVGTag returns the svg tag of the object
  /// @return returns the svg tag as string
  virtual std::string getSVGTag();
};
#endif // SVGPOLYGON_H_INCLUDED
