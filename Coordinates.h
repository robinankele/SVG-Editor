//------------------------------------------------------------------------------
/// Filename: Coordinates.h
/// Description: The Class represents the Coordinates
/// Authors:
///          Ralph Ankele (0931953)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 16.09.2011
/// Last change: 16.09.2011
//------------------------------------------------------------------------------

#ifndef COORDINATES_H_INCLUDED
#define COORDINATES_H_INCLUDED

class Coordinates 
{
private:
  //----------------------------------------------------------------------------
  /// x value of Coordiante
  signed int x_;

  //----------------------------------------------------------------------------
  /// y value of Coordinate
  signed int y_;
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param x is the x coordinate of an object
  /// @param y is the y coordinate of an object
  Coordinates(signed int x, 
              signed int y);
              
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~Coordinates() throw();

  //----------------------------------------------------------------------------
  /// setX() setterMethod
  /// @param x sets the x value
  /// @return returns void
  void setX( signed int x) { x_ = x;}

  //----------------------------------------------------------------------------
  /// setY() setterMethod
  /// @param y sets the y value
  /// @return returns void
  void setY( signed int y) { y_ = y;}

  //----------------------------------------------------------------------------
  /// getX() getterMethod
  /// @return  returns the x value
  signed int getX() { return x_;}

  //----------------------------------------------------------------------------
  /// getY() getterMethod
  /// @return  returns the y value
  signed int getY() { return y_;}
};
#endif // COORDINATES_H_INCLUDED
