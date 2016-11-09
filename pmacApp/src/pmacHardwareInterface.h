/*
 * pmacHardwareInterface.h
 *
 *  Created on: 27 Oct 2016
 *      Author: gnx91527
 */

#ifndef PMACAPP_SRC_PMACHARDWAREINTERFACE_H_
#define PMACAPP_SRC_PMACHARDWAREINTERFACE_H_

#include <string>
#include "asynDriver.h"
#include "pmacCommandStore.h"
#include "pmacMessageBroker.h"

struct globalStatus
{
  int status_;
  int stat1_;
  int stat2_;
  int stat3_;
};

struct csStatus
{
  int stat1_;
  int stat2_;
  int stat3_;
  int done_;
  int highLimit_;
  int lowLimit_;
  int followingError_;
  int moving_;
  int problem_;
};

struct axisStatus
{
  int status24Bit1_;
  int status24Bit2_;
  int status16Bit1_;
  int status16Bit2_;
  int status16Bit3_;
  int home_;
  int done_;
  int currentCS_;
  int highLimit_;
  int lowLimit_;
  int moving_;
  int followingError_;
  int power_;
  int ampEnabled_;
};

class pmacController;

class pmacHardwareInterface
{
  public:
    pmacHardwareInterface();
    virtual ~pmacHardwareInterface();
    void registerController(pmacController *pController);
    virtual std::string getGlobalStatusCmd() = 0;
    virtual asynStatus parseGlobalStatus(const std::string& statusString, globalStatus &status) = 0;
    virtual std::string getAxisStatusCmd(int axis) = 0;
    virtual asynStatus setupAxisStatus(int axis) = 0;
    virtual asynStatus parseAxisStatus(int axis, pmacCommandStore *sPtr, axisStatus &status) = 0;
    virtual asynStatus setupCSStatus(int csNo) = 0;
    virtual asynStatus parseCSStatus(int csNo, pmacCommandStore *sPtr, csStatus &status) = 0;

  protected:
    pmacController *pC_;
};

#endif /* PMACAPP_SRC_PMACHARDWAREINTERFACE_H_ */
