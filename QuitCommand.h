//------------------------------------------------------------------------------
/// Filename: QuitCommand.h
/// Description: Header for Class QuitCommand
/// Authors:
///          Robin Ankele (0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef QUITCOMMAND_H_INCLUDED
#define QUITCOMMAND_H_INCLUDED

#include "Command.h"

class UserInterface;
class Database;
class SVGDocument;

class QuitCommand: public Command
{
private:
  //----------------------------------------------------------------------------
  /// Connection to SVGDocument
  SVGDocument *svgdoc_;
  
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another QuitCommand Object.
  /// @param source Original to copy.
  QuitCommand(const QuitCommand& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one QuitCommand to another
  /// @param source Original with values to copy.
  QuitCommand &operator=(const QuitCommand& source);
  
public:
  //----------------------------------------------------------------------------
  /// Constructor
  /// @param ui Connection to UserInterface
  /// @param db Connection to Database
  /// @param svgdoc Connection to SVGDocument
  QuitCommand(UserInterface *ui, 
              Database *db, 
              SVGDocument *svgdoc);
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~QuitCommand() throw();
  
  //----------------------------------------------------------------------------
  /// This Function executes the QuitCommand
  /// @return returns true if execute was correct
  virtual bool execute();
};
#endif  //QUITCOMMAND_H_INCLUDED
