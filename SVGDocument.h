//------------------------------------------------------------------------------
/// Filename: SVGDocument.h
/// Description: Header for Class SVGDocument
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef SVGDOCUMENT_H_INCLUDED
#define SVGDOCUMENT_H_INCLUDED

#include <string>

class UserInterface;
class Error;
class Database;
class SVGHandler;

class SVGDocument 
{
private:
  //----------------------------------------------------------------------------
  /// Error handle
  Error *error_;
  
  //----------------------------------------------------------------------------
  /// Database handle
  Database *db_;
  
  //----------------------------------------------------------------------------
  /// SVGHandler handle
  SVGHandler *svgh_;
  
  //----------------------------------------------------------------------------
  /// UserInterface handle
  UserInterface *ui_;
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param db Connection to Database
  /// @param svgh Connection to SVGHandler
  SVGDocument(Database *db,
              SVGHandler *svgh);

  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~SVGDocument() throw();
  
  //----------------------------------------------------------------------------
  /// getSVGHeader Method: writes the Header of the SVGDocument
  /// @return returns the header of a SVG File
  std::string getSVGHeader();
  
  //----------------------------------------------------------------------------
  /// getSVGFooter Method: writes the Footer of the SVGDocument
  /// @return returns the Footer of a SVG File
  std::string getSVGFooter();
  
  //----------------------------------------------------------------------------
  /// writeSVG Method: writes the content in the SVG File
  /// @return returns true if write to SVG file works
  bool writeSVG();
  
  //----------------------------------------------------------------------------
  /// setUI() setterMethod: sets the UserInterface handle
  /// @param ui is the UserInterface handle
  /// @return returns void
  void setUI(UserInterface *ui) { ui_ = ui;}
  
  //----------------------------------------------------------------------------
  /// checkOpen() Method: checks if the SVG file is already open
  /// @param filename the filename of the svg file which should be checked
  /// @return returns true if svg file is already open
  bool checkOpen(std::string filename);
};
#endif // SVGDOCUMENT_H_INCLUDED
