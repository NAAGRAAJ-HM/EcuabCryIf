/******************************************************************************/
/* File   : CryIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infCryIf_EcuM.hpp"
#include "infCryIf_Dcm.hpp"
#include "infCryIf_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CRYIF_AR_RELEASE_VERSION_MAJOR                                         4
#define CRYIF_AR_RELEASE_VERSION_MINOR                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CRYIF_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CRYIF_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CRYIF_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CRYIF_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_CryIf:
      public abstract_module
   ,  public class_CryIf_Functionality
{
   public:
      module_CryIf(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, CRYIF_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, CRYIF_CONFIG_DATA, CRYIF_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CRYIF_CODE) DeInitFunction (void);
      FUNC(void, CRYIF_CODE) MainFunction   (void);
};

extern VAR(module_CryIf, CRYIF_VAR) CryIf;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, CRYIF_VAR, CRYIF_CONST) gptrinfEcuMClient_CryIf = &CryIf;
CONSTP2VAR(infDcmClient,  CRYIF_VAR, CRYIF_CONST) gptrinfDcmClient_CryIf  = &CryIf;
CONSTP2VAR(infSchMClient, CRYIF_VAR, CRYIF_CONST) gptrinfSchMClient_CryIf = &CryIf;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgCryIf.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CryIf, CRYIF_VAR) CryIf(
   {
         CRYIF_AR_RELEASE_VERSION_MAJOR
      ,  CRYIF_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CRYIF_CODE) module_CryIf::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, CRYIF_CONFIG_DATA, CRYIF_APPL_CONST) lptrCfgModule
){
#if(STD_ON == CryIf_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == CryIf_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == CryIf_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgCryIf;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == CryIf_InitCheck)
   }
#endif
}

FUNC(void, CRYIF_CODE) module_CryIf::DeInitFunction(void){
#if(STD_ON == CryIf_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == CryIf_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == CryIf_InitCheck)
   }
#endif
}

FUNC(void, CRYIF_CODE) module_CryIf::MainFunction(void){
#if(STD_ON == CryIf_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == CryIf_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == CryIf_InitCheck)
   }
#endif
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::ProcessJob(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::CancelJob(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyElementSet(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeySetValid(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyElementGet(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyElementCopy(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyElementCopyPartial(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyCopy(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::RandomSeed(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyGenerate(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyDerive(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyExchangeCalcPubVal(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::KeyExchangeCalcSecret(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Functionality::CbNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

