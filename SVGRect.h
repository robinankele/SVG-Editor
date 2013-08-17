//------------------------------------------------------------------------------
/// Filename: SVGRect.h
/// Description: Header for Class SVGRect
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 25.09.2011
//------------------------------------------------------------------------------

#ifndef SVGRECT_H_INCLUDED
#define SVGRECT_H_INCLUDED

#include "SVGObject.h"

class SVGRect: public SVGObject
{
private:
  //----------------------------------------------------------------------------
  /// width of rectangle
  signed int width_;
  
  //----------------------------------------------------------------------------
  /// height of rectangle
  signed int height_;
  
  //----------------------------------------------------------------------------
  /// fill color of rectangle
  std::string fill_;
  
  //----------------------------------------------------------------------------
  /// stroke of rectangle
  std::string stroke_;
  
  //----------------------------------------------------------------------------
  /// stroke width of rectangle
  std::string stroke_width_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another SVGRect Object.
  /// @param source Original to copy.
  SVGRect(const SVGRect& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one SVGRect to another
  /// @param source Original with values to copy.
  SVGRect &operator=(const SVGRect& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVHHandler
  /// @param id id of the object
  /// @param group_id group id of the object
  /// @param coordinates vector with coordinates of the object
  /// @param width is the width of the object
  /// @param height is the height of the object
  /// @param fill fill color of the object
  /// @param stroke stroke of the object
  /// @param stroke_width stroke widt of the object
  SVGRect(UserInterface *ui,
          Database *db,
          SVGHandler *svgh,
          signed int id,
          signed int group_id,
          std::vector<Coordinates> coordinates,
          signed int width,
          signed int height,
          std::string fill,
          std::string stroke,
          std::string stroke_width);
  
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGRect() throw();
  
  //----------------------------------------------------------------------------
  /// resize Method: resizes the SVG Object 
  /// @return returns true if resize fits
  virtual bool resize();
  
  //----------------------------------------------------------------------------
  /// rotate Method: rotates the SVG Object 
  /// @param direction is the direction in which the object rotates
  /// @return returns true if rotate fits
  virtual bool rotate(std::string direction);
  
  //----------------------------------------------------------------------------
  /// getSVGTag returns the svg tag of the object
  /// @return returns the svg tag as string
  virtual std::string getSVGTag();
};
#endif // SVGRECT_H_INCLUDED
