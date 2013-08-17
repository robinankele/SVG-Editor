//------------------------------------------------------------------------------
/// Filename: Error.h
/// Description: Header for Class Error
/// Authors:
///          Robin Ankele (0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 08.09.2011
//------------------------------------------------------------------------------

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <iostream>
#include <string>

class Error
{
private:
  //----------------------------------------------------------------------------
  /// Copy Constructor
  /// Makes a copy of another Error Object.
  /// @param source Original to copy.
  Error(const Error& source);
  
  //----------------------------------------------------------------------------
  /// Assignment Operator
  /// Used to assign one Error to another
  /// @param source Original with values to copy.
  Error &operator=(const Error& source);

public:
  //----------------------------------------------------------------------------
  /// Constructor
  Error() {}
 
  //----------------------------------------------------------------------------
  /// Destructor
  virtual ~Error() throw() {}
  
  //----------------------------------------------------------------------------
  /// "usage: exA -c=configfile\n" 
  /// usageConfigFile() : Prints Errormessage
  /// @return returns void
  inline void usageConfigFile()
  { std::cout<<"usage: exA -c=configfile"<<std::endl;}
    
  //----------------------------------------------------------------------------
  /// "error: out of memory\n" 
  /// outOfMemory() : Prints Errormessage
  /// @return returns void
  inline void outOfMemory()
  { std::cout<<"error: out of memory"<<std::endl;}
    
  //----------------------------------------------------------------------------
  /// "error: cannot read configfile [filename]\n" 
  /// cannotReadConfigFile() : Prints Errormessage
  /// @param filename is the filename of the configfile
  /// @return returns void
  inline void cannotReadConfigFile(std::string filename)
  { std::cout<<"error: cannot read configfile "<<filename<<std::endl;}
    
  //----------------------------------------------------------------------------
  /// "error: configfile [filename] corrupt\n" 
  /// configFileCorrupt() : Prints Errormessage
  /// @return returns void
  inline void configFileCorrupt(std::string filename)
  { std::cout<<"error: configfile "<<filename<<" corrupt"<<std::endl;}  
  
  //----------------------------------------------------------------------------
  /// "warning: file [filename] exists and will be replaced. Do you want to 
  ///  proceed? (y/n)\n" 
  /// filenameExists() : Prints Errormessage
  /// @return returns void
  inline void filenameExists(std::string filename)
  { std::cout<<"warning: file "<<filename<<" exists and will be "<<std::flush
             <<"replaced. Do you want to proceed? (y/n)"<<std::endl;}
  
  //----------------------------------------------------------------------------
  /// "error: unknown command\n" 
  /// unkownCommand() : Prints Errormessage
  /// @return returns void
  inline void unknownCommand()
  { std::cout<<"error: unknown command"<<std::endl;}  
  
  //----------------------------------------------------------------------------
  /// "error: invalid parameter - please enter an integer number\n" 
  /// invalidParameter() : Prints Errormessage
  /// @return returns void
  inline void invalidParameter()
  { std::cout<<"error: invalid parameter - please enter an "<<std::flush
             <<"integer number"<<std::endl;}
  
  //----------------------------------------------------------------------------
  /// "error: id does not exist\n" 
  /// idDoesnotExist() : Prints Errormessage
  /// @return returns void
  inline void idDoesnotExist()
  { std::cout<<"error: id does not exist"<<std::endl;}  
  
  //----------------------------------------------------------------------------
  /// "error: id does already exist\n" 
  /// idAlreadyExist() : Prints Errormessage
  /// @return returns void
  inline void idAlreadyExist()
  { std::cout<<"error: id does already exist"<<std::endl;}  
  
  //----------------------------------------------------------------------------
  /// "error: cannot write to savefile [filename]. Quit anyway? (y/n)\n" 
  /// cannotWriteToFile() : Prints Errormessage
  /// @return returns void
  inline void cannotWriteToFile(std::string filename)
  { std::cout<<"error: cannot write to savefile "<<filename<<". "<<std::flush
             <<"Quit anyway? (y/n)"<<std::endl;}  
}; 
#endif  //ERROR_H_INCLUDED
