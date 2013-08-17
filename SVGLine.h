//------------------------------------------------------------------------------
/// Filename: SVGLine.h
/// Description: Header for Class SVGLine
/// Authors:
///         Ralph Ankele(0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#ifndef SVGLINE_H_INCLUDED
#define SVGLINE_H_INCLUDED

#include "SVGObject.h"

class SVGLine: public SVGObject
{
private:
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another SVGLine Object.
  /// @param source Original to copy.
  SVGLine(const SVGLine& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one SVGLine to another
  /// @param source Original with values to copy.
  SVGLine &operator=(const SVGLine& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVHHandler
  /// @param id id of the object
  /// @param group_id group id of the object
  /// @param coordinates vector with coordinates of the object
  SVGLine(UserInterface *ui,
          Database *db,
          SVGHandler *svgh,
          signed int id,
          signed int group_id,
          std::vector<Coordinates> coordinates);

  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGLine() throw();
  
  //----------------------------------------------------------------------------
  /// resize Method: resizes the SVG Object 
  /// @return returns true if resize fits
  virtual bool resize();
  
  //----------------------------------------------------------------------------
  /// move Method: moves the SVG Object 
  /// @param x is the x direction in which is moved
  /// @param y is the y direction in which is moved
  /// @return returns true if move is correct
  virtual bool move(signed int x, signed int y);
  
  //----------------------------------------------------------------------------
  /// getSVGTag returns the svg tag of the object
  /// @return returns the svg tag as string
  virtual std::string getSVGTag();
};
#endif // SVGLINE_H_INCLUDED
