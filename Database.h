//------------------------------------------------------------------------------
/// Filename: Database.h
/// Description: Header for Class Database
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 19.09.2011
//------------------------------------------------------------------------------

#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <string>
#include <vector>
#include "SVGObject.h"
class SVGHandler;

class Database
{
private:
  //----------------------------------------------------------------------------
  /// SVGHandler handle
  SVGHandler *svgh_;

  //----------------------------------------------------------------------------
  /// Config Filename
  std::string filename_;
  
  //----------------------------------------------------------------------------
  /// Magic Number
  std::string magic_number_;
  
  //----------------------------------------------------------------------------
  /// Width of SVGDocument
  signed int width_;
  
  //----------------------------------------------------------------------------
  /// Height of SVGDocument
  signed int height_;
  
  //----------------------------------------------------------------------------
  /// amount of SVGObjects in the SVGObject database
  unsigned int svg_objects_counter_;
  
  //----------------------------------------------------------------------------
  /// Database of SVGObjects
  std::vector<SVGObject*> svg_objects_; 
  
  //----------------------------------------------------------------------------
  /// Group of SVGObjects
  std::vector<SVGObject*> group_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another Database Object.
  /// @param source Original to copy.
  Database(const Database& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one Database to another
  /// @param source Original with values to copy.
  Database &operator=(const Database& source);
 
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param parameter contains the filename of the svg file
  /// @param svhg Connection to the SVGHandler
  Database(std::string parameter,
           SVGHandler *svgh);
  
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~Database() throw();
  
  //----------------------------------------------------------------------------
  /// getFilename() getterMethod: returns the filename of the Config File
  /// @return returns the filename of the Config File
  std::string getFilename() { return filename_;}
  
  //----------------------------------------------------------------------------
  /// getWidth() getterMethod: returns the width of the SVGDocument
  /// @return returns the width of the SVGDocument
  signed int getWidth() { return width_;}
  
  //----------------------------------------------------------------------------
  /// getHeight() getterMethod: returns the height of the SVGDocument
  /// @return returns the height of the SVGDocument
  signed int getHeight() { return height_;}
  
  //----------------------------------------------------------------------------
  /// checkConfigFile() Method: checks if Config File can be opened
  /// @return returns true if Config File can be opened
  bool checkConfigFile();
  
  //----------------------------------------------------------------------------
  /// readConfigFile() Method: checks if Config File fits
  /// @return returns true if Config File fits
  bool readConfigFile();
  
  //----------------------------------------------------------------------------
  /// checkMagicNumber() Method: checks the Magic Number of the Config File
  /// @param content holds the magic number
  /// @return returns true if Magic Number fits
  bool checkMagicNumber(char *content);
  
  //----------------------------------------------------------------------------
  /// readPrompt() Method: checks and sets the Prompt
  /// @param buffer is the char* where the prompt is saved
  /// @return returns true if prompt fits
  bool checkPrompt(char *buffer);
  
  //----------------------------------------------------------------------------
  /// setSVGDimensions() Method: reads the dimensions of the SVG File from the 
  ///                            Config File and converts to signed int
  /// @param buffer the readed config file 
  /// @return true if Dimensions fits
  bool setSVGDimensions(unsigned char *buffer);
  
  //----------------------------------------------------------------------------
  /// charToSignedInt() Method: converts char to signed ints
  /// @param content is the string which should be converted
  /// @return returns the result of the convertion
  signed int charToSignedInt(unsigned char *content);
  
  //----------------------------------------------------------------------------
  /// readFile() Method: reads from File and checks if read was correct
  /// @param buffer is the char* where the result will be saved
  /// @param lenght is the size of bits which should be readed
  /// @param config_file is the file handle from which should be readed
  /// @return returns true if read from File fits
  bool readFile(unsigned char *buffer, unsigned int lenght, 
                std::ifstream &config_file);
  
  //----------------------------------------------------------------------------
  /// getAllSVGObjects() getterMethod: returns the database of all SVGObjects
  /// @return return returns a vector of all SVGObjects
  std::vector<SVGObject*>& getAllSVGObjects() { return svg_objects_;}
  
  //----------------------------------------------------------------------------
  /// getSVGObjectByGrp() getterMethod: returns SVGObjects selected by a special
  ///                                   Group
  /// @param grp_id the special group identifier of the SVGObjects
  /// @return return returns SVGObjects selected by a special Group
  std::vector<SVGObject*>& getSVGObjectByGrp(signed int grp_id);
  
  //----------------------------------------------------------------------------
  /// getSVGObjectByID() getterMethod: returns a SVGObject selected by ID
  /// @param id the identifier of a SVGObject
  /// @return return returns a SVGOBject selected by ID
  SVGObject* getSVGObjectByID(signed int id);
  
  //----------------------------------------------------------------------------
  /// setSVGObject() setterMethod: inserts a SVGObject in the SVGObject database
  /// @param svg_object the commited svg object which should be saved in the 
  ///                   database
  /// @return returns void
  void setSVGObject(SVGObject *svg_object);
  
  //----------------------------------------------------------------------------
  /// sort() Method: sorts the SVGObject database
  /// @return returns void
  void sort();
};
#endif  //DATABASE_H_INCLUDED
