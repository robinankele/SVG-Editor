//------------------------------------------------------------------------------
/// Filename: SVGCircle.h
/// Description: Header for Base Class SVGCircle
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 18.09.2011
//------------------------------------------------------------------------------

#ifndef SVGCIRCLE_H_INCLUDED
#define SVGCIRCLE_H_INCLUDED

#include "SVGObject.h"

class UserInterface;
class Database;
class SVGHandler;

class SVGCircle: public SVGObject
{
private:
  //----------------------------------------------------------------------------
  /// radius of circle
  signed int r_;
  
  //----------------------------------------------------------------------------
  /// fill color of circle
  std::string fill_;
  
  //----------------------------------------------------------------------------
  /// stroke of circle
  std::string stroke_;
  
  //----------------------------------------------------------------------------
  /// stroke width of circle
  std::string stroke_width_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another SVGCircle Object.
  /// @param source Original to copy.
  SVGCircle(const SVGCircle& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one SVGCircle to another
  /// @param source Original with values to copy.
  SVGCircle &operator=(const SVGCircle& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgh Connection to SVHHandler
  /// @param id id of the object
  /// @param group_id group id of the object
  /// @param coordinates vector with coordinates of the object
  /// @param r radius of the object
  /// @param fill fillcolor of the object
  /// @param stroke stroke of the object
  /// @param stroke_width stroke width of the object
  SVGCircle(UserInterface *ui,
            Database *db,
            SVGHandler *svgh,
            signed int id,
            signed int group_id,
            std::vector<Coordinates> coordinates,
            signed int r,
            std::string fill,
            std::string stroke,
            std::string stroke_width);
  
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGCircle() throw();
  
  //----------------------------------------------------------------------------
  /// resize Method: resizes the SVG Object 
  /// @return returns true if resize fits
  virtual bool resize();
  
  //----------------------------------------------------------------------------
  /// rotate Method: rotates the SVG Object 
  /// @return returns true if rotate fits
  virtual bool rotate() { return true;}
  
  //----------------------------------------------------------------------------
  /// getSVGTag returns the svg tag of the object
  /// @return returns the svg tag as string
  virtual std::string getSVGTag();
};
#endif // SVGCIRCLE_H_INCLUDED
