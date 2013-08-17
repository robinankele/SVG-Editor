//------------------------------------------------------------------------------
/// Filename: ErrorCodes.h
/// Description: Enum for ErrorCodes
/// Authors:
///          Robin Ankele (0931951)
/// Tutor: Manuel Weber
/// Group: 24
/// Created: 18.09.2011
/// Last change: 18.09.2011
//------------------------------------------------------------------------------

#ifndef ERRORCODES_H_INCLUDED
#define ERRORCODES_H_INCLUDED

typedef enum _ErrorCodes_
{
  SUCCESS = 0,
  USAGE_CONFIG_FILE = -1,
  OUT_OF_MEMORY = -2,
  CANNOT_READ_CONFIG_FILE = -3,
  CONFIG_FILE_CORRUPT = -4
} ErrorCodes;
#endif  //ERRORCODES_H_INCLUDED
