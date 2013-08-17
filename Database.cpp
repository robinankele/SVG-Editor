//------------------------------------------------------------------------------
/// Filename: Database.cpp
/// Description: The Database stores the SVGObject vector and handles with the 
///              Config File
/// Authors:
///         Robin Ankele(0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 08.09.2011
/// Last change: 09.09.2011
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Database.h"
#include "ErrorCodes.h"
#include "Constants.h"
#include "SVGHandler.h"

//------------------------------------------------------------------------------
Database::Database(std::string parameter,
                   SVGHandler *svgh) : svgh_(svgh),
                                       width_(0),
                                       height_(0),
                                       svg_objects_counter_(0)
{
  filename_.assign(parameter.erase(0,3));
  magic_number_.assign("YASVG");
}

//------------------------------------------------------------------------------
Database::~Database() throw()
{
  group_.clear();
  
  for(std::vector<SVGObject*>::iterator it = svg_objects_.begin(); 
      it != svg_objects_.end(); ++it)
    delete (*it);
}

//------------------------------------------------------------------------------
bool Database::checkConfigFile()
{
  std::fstream config_file;
  config_file.open(filename_.c_str(), std::fstream::in | std::ios::binary);
  
  if(config_file.is_open())
  {
    config_file.close();
    return true;
  }
  return false;
}

//------------------------------------------------------------------------------
bool Database::readConfigFile()
{
  std::ifstream config_file;
  config_file.open(filename_.c_str(), std::fstream::in | std::ios::binary);
  unsigned int length = 0;
  
  config_file.seekg(0, std::ios::end);
    length = config_file.tellg();
    length -= (MAGIC_SIZE + PROMPT_SIZE);
  config_file.seekg(0, std::ios::beg);
  if(length > MAX_FILE_SIZE)
  {
    config_file.close();
    return false;
  }
  
  unsigned char magic_number[MAGIC_SIZE], prompt[PROMPT_SIZE], *buffer;
  if(!readFile(magic_number, MAGIC_SIZE, config_file) ||
     !checkMagicNumber((char*)magic_number))
    return false;
  
  if(!readFile(prompt, PROMPT_SIZE, config_file) || !checkPrompt((char*)prompt))
    return false;

  try
  {
    buffer = new unsigned char[length + 1];
  }
  catch(std::bad_alloc& exception)
  {
    svgh_->setErrors(OUT_OF_MEMORY);
    return false;
  }
  
  if(!readFile(buffer, length, config_file) || 
     !setSVGDimensions((unsigned char*)buffer))
  {
    config_file.close();
    delete[] buffer;
    return false;
  }
  
  config_file.close();
  delete[] buffer;
  return true;
}

//------------------------------------------------------------------------------
bool Database::readFile(unsigned char *buffer, unsigned int length, 
                        std::ifstream &config_file)
{
  config_file.read((char*)buffer, length);
  if(!config_file.good())
    return false;
  return true;
}

//------------------------------------------------------------------------------
bool Database::checkMagicNumber(char *content)
{
  std::string magic_number(content);
 
  if(magic_number.empty() || magic_number.compare(0, MAGIC_SIZE, magic_number_))
    return false;
  return true;
}

//------------------------------------------------------------------------------
bool Database::checkPrompt(char *buffer)
{
  bool check_tokens = true;
  unsigned int check_char = 0;
  
  for(unsigned int counter = 0; counter < 3; counter++)
  {
    check_char = static_cast<unsigned int>(buffer[counter]);
    if(check_char < A_LOWER || check_char > Z_LOWER && 
       check_char < A_UPPER || check_char > Z_UPPER)
      check_tokens = false;
  }
  if(!check_tokens || buffer[3] != 0)
    return false;

  svgh_->setPrompt(std::string(buffer));
  return true;
}

//------------------------------------------------------------------------------
bool Database::setSVGDimensions(unsigned char *buffer)
{
  unsigned char width[4], height[4];
  
  for(unsigned int counter = 0; counter < 4; counter++)
  {
    width[counter] = buffer[counter];
    height[counter] = buffer[counter + 4];
  }
  width_ = charToSignedInt((unsigned char*)width);
  height_ = charToSignedInt((unsigned char*)height);

  if(width_ < 0 || height_ < 0)
    return false;
  return true;
}

//------------------------------------------------------------------------------
signed int Database::charToSignedInt(unsigned char *content)
{  
  signed int result = 0;

  for(unsigned int counter = 0; counter < 4; counter++)
    result |= (content[counter] << (SHIFT_CONSTANT * counter));

  return result;
}

//------------------------------------------------------------------------------
void Database::setSVGObject(SVGObject *svg_object)
{
  svg_objects_.push_back(svg_object);
  svg_objects_counter_++;
  sort();
}

//------------------------------------------------------------------------------
bool sortbyGrp(SVGObject *current, SVGObject *prev) 
{
  return current->getGrpID() < prev->getGrpID();
}

//------------------------------------------------------------------------------
bool sortbyID(SVGObject *current, SVGObject *prev) 
{
  return current->getID() < prev->getID();
}

//------------------------------------------------------------------------------
void Database::sort()
{
  if(svg_objects_counter_ == 1)
    return;
    
  std::sort(svg_objects_.begin(), svg_objects_.end(), sortbyID);
  std::sort(svg_objects_.begin(), svg_objects_.end(), sortbyGrp);
}

//------------------------------------------------------------------------------
std::vector<SVGObject*>& Database::getSVGObjectByGrp(signed int grp_id)
{
  group_.clear();
  for(std::vector<SVGObject*>::iterator it = svg_objects_.begin(); 
      it != svg_objects_.end(); ++it)
  {
    if((*it)->getGrpID() == grp_id)
      group_.push_back((*it));
  }
  return group_;
}

//------------------------------------------------------------------------------
SVGObject* Database::getSVGObjectByID(signed int id)
{
  for(std::vector<SVGObject*>::iterator it = svg_objects_.begin(); 
      it != svg_objects_.end(); ++it)
  {
    if((*it)->getID() == id)
      return (*it);
  }
  return NULL;
}
