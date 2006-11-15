#ifndef _SHOCKS_HH
#define _SHOCKS_HH
//------------------------------------------------------------------------------
/** \file
 * \version 1.0
 * \date 04/26/2004
 * \par This file defines the Shocks class.
 */
//------------------------------------------------------------------------------
#include <string>
#include <sstream>
#include <list>
#include <vector>

//------------------------------------------------------------------------------
/*!
  \class  Shocks
  \brief  Handles Shocks command
*/
class Shocks
{
private :
  int mshock_flag;
  /*!
    \class ShockElement
    \brief Shock element strcuture
  */
  struct ShockElement
  {
    std::string period1;
    std::string period2;
    std::string value;
  };
  /*!
    \class Shock
    \brief Shock Structure
  */
  struct Shock
  {
    int     id1;
    int     id2;
    std::list<ShockElement> shock_elems;
    std::string value;
  };
  /*! Output string of this class */
  std::ostringstream    *output;
  /*! Vector of begin period range */
  std::vector<std::string>    mPeriod1;
  /*! vector of end period range */
  std::vector<std::string>    mPeriod2;
  /*! vector of shock values */
  std::vector<std::string>    mValues;
public :
  /*! Constructor */
  Shocks();
  /*! Destructor */
  ~Shocks();
  /*! Pointer to error function of parser class */
  void (* error) (const char* m);
  /*!
    Set output reference
    \param iOutput : reference to an ostringstream
  */
  void  setOutput(std::ostringstream* iOutput);
  /*! Initialize shocks (or mshocks, for multiplicative shocks) block */
  void  BeginShocks(void);
  void  BeginMShocks(void);
  void  EndShocks(void);
  /*! Sets a shock */
  void  AddDetShockExo(int id1);
  void  AddDetShockExoDet(int id1);
  void  AddSTDShock(int id1, std::string value);
  void  AddVARShock(int id1, std::string value);
  void  AddCOVAShock(int id1, int id2 , std::string value);
  void  AddCORRShock(int id1, int id2 , std::string value);
  /*! Adds a period rage */
  void  AddPeriod(std::string p1, std::string p2);
  /*! Adds a period */
  void  AddPeriod(std::string p1);
  /*! Adds a value */
  void  AddValue(std::string value);
};
//------------------------------------------------------------------------------
#endif
