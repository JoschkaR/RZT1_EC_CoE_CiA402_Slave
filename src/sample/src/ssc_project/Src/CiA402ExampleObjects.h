/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup CiA402Example CiA402Example
* @{
*/

/**
\file CiA402ExampleObjects
\author ET9300Utilities.ApplicationHandler (Version 1.5.0.0) | EthercatSSC@beckhoff.com

\brief CiA402Example specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : RxPdoMappingCspCsV
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | RxPdoMappingCspCsV
* @{
* \brief Object 0x1600 (RxPdoMappingCspCsV) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - map control word<br>
* SubIndex 2 - map taget position<br>
* SubIndex 3 - map target velocity<br>
* SubIndex 4 - map mode of operation<br>
* SubIndex 5 - add 24bit padding to get an 32Bit object/process data structure<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - map control word */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - map taget position */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - map target velocity */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - map mode of operation */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex5 - add 24bit padding to get an 32Bit object/process data structure */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "RxPdoMappingCspCsV\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - map control word */
UINT32 SI2; /* Subindex2 - map taget position */
UINT32 SI3; /* Subindex3 - map target velocity */
UINT32 SI4; /* Subindex4 - map mode of operation */
UINT32 SI5; /* Subindex5 - add 24bit padding to get an 32Bit object/process data structure */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 RxPdoMappingCspCsV0x1600
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={5,0x60400010,0x607A0020,0x60FF0020,0x60600008,0x00000018}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1601 : RxPdoMappingCsp
******************************************************************************/
/**
* \addtogroup 0x1601 0x1601 | RxPdoMappingCsp
* @{
* \brief Object 0x1601 (RxPdoMappingCsp) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - map control word<br>
* SubIndex 2 - map target position<br>
* SubIndex 3 - add 16bit padding to get an 32Bit object/process data structure<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1601[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - map control word */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - map target position */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1601[] = "RxPdoMappingCsp\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - map control word */
UINT32 SI2; /* Subindex2 - map target position */
UINT32 SI3; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */
} OBJ_STRUCT_PACKED_END
TOBJ1601;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1601 RxPdoMappingCsp0x1601
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={3,0x60400010,0x607A0020,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1602 : RxPdoMappingCsv
******************************************************************************/
/**
* \addtogroup 0x1602 0x1602 | RxPdoMappingCsv
* @{
* \brief Object 0x1602 (RxPdoMappingCsv) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - map control word<br>
* SubIndex 2 - map target velocity<br>
* SubIndex 3 - add 16bit padding to get an 32Bit object/process data structure<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1602[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - map control word */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - map target velocity */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1602[] = "RxPdoMappingCsv\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - map control word */
UINT32 SI2; /* Subindex2 - map target velocity */
UINT32 SI3; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */
} OBJ_STRUCT_PACKED_END
TOBJ1602;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1602 RxPdoMappingCsv0x1602
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={3,0x60400010,0x60FF0020,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : TxPdoMappingCspCsV
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | TxPdoMappingCspCsV
* @{
* \brief Object 0x1A00 (TxPdoMappingCspCsV) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - map status word<br>
* SubIndex 2 - map actual position<br>
* SubIndex 3 - map actual velocity<br>
* SubIndex 4 - map mode of operation display<br>
* SubIndex 5 - add 24bit padding to get an 32Bit object/process data structure<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - map status word */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - map actual position */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - map actual velocity */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - map mode of operation display */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex5 - add 24bit padding to get an 32Bit object/process data structure */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "TxPdoMappingCspCsV\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - map status word */
UINT32 SI2; /* Subindex2 - map actual position */
UINT32 SI3; /* Subindex3 - map actual velocity */
UINT32 SI4; /* Subindex4 - map mode of operation display */
UINT32 SI5; /* Subindex5 - add 24bit padding to get an 32Bit object/process data structure */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 TxPdoMappingCspCsV0x1A00
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={5,0x60410010,0x60640020,0x606C0020,0x60610008,0x00000018}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A01 : TxPdoMappingCsp
******************************************************************************/
/**
* \addtogroup 0x1A01 0x1A01 | TxPdoMappingCsp
* @{
* \brief Object 0x1A01 (TxPdoMappingCsp) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - map status word<br>
* SubIndex 2 - map actual position<br>
* SubIndex 3 - add 16bit padding to get an 32Bit object/process data structure<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A01[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - map status word */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - map actual position */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A01[] = "TxPdoMappingCsp\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - map status word */
UINT32 SI2; /* Subindex2 - map actual position */
UINT32 SI3; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */
} OBJ_STRUCT_PACKED_END
TOBJ1A01;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A01 TxPdoMappingCsp0x1A01
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={3,0x60410010,0x60640020,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A02 : TxPdoMappingCsv
******************************************************************************/
/**
* \addtogroup 0x1A02 0x1A02 | TxPdoMappingCsv
* @{
* \brief Object 0x1A02 (TxPdoMappingCsv) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - map control word<br>
* SubIndex 2 - map actual position<br>
* SubIndex 3 - add 16bit padding to get an 32Bit object/process data structure<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A02[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - map control word */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - map actual position */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A02[] = "TxPdoMappingCsv\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - map control word */
UINT32 SI2; /* Subindex2 - map actual position */
UINT32 SI3; /* Subindex3 - add 16bit padding to get an 32Bit object/process data structure */
} OBJ_STRUCT_PACKED_END
TOBJ1A02;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A02 TxPdoMappingCsv0x1A02
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={3,0x60410010,0x60640020,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SM2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SM2 assignment
* @{
* \brief Object 0x1C12 (SM2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ | ACCESS_WRITE_PREOP },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ | ACCESS_WRITE_PREOP }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SM2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={1,{0x1601}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SM3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SM3 assignment
* @{
* \brief Object 0x1C13 (SM3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ | ACCESS_WRITE_PREOP },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ | ACCESS_WRITE_PREOP }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SM3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={1,{0x1A01}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x3500 : sdoData0
******************************************************************************/
/**
* \addtogroup 0x3500 0x3500 | sdoData0
* @{
* \brief Object 0x3500 (sdoData0) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x3500 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x3500[] = "sdoData0\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 SdoData00x3500
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x3501 : sdoData1
******************************************************************************/
/**
* \addtogroup 0x3501 0x3501 | sdoData1
* @{
* \brief Object 0x3501 (sdoData1) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x3501 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x3501[] = "sdoData1\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 SdoData10x3501
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x3502 : sdoData2
******************************************************************************/
/**
* \addtogroup 0x3502 0x3502 | sdoData2
* @{
* \brief Object 0x3502 (sdoData2) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x3502 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x3502[] = "sdoData2\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 SdoData20x3502
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x603F : Error Code
******************************************************************************/
/**
* \addtogroup 0x603F 0x603F | Error Code
* @{
* \brief Object 0x603F (Error Code) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x603F = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x603F[] = "Error Code\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 ErrorCode0x603F
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6040 : Controlword
******************************************************************************/
/**
* \addtogroup 0x6040 0x6040 | Controlword
* @{
* \brief Object 0x6040 (Controlword) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6040 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6040[] = "Controlword\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Controlword0x6040
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6041 : Statusword
******************************************************************************/
/**
* \addtogroup 0x6041 0x6041 | Statusword
* @{
* \brief Object 0x6041 (Statusword) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6041 = { DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6041[] = "Statusword\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT16 Statusword0x6041
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x605A : Quick stop option code
******************************************************************************/
/**
* \addtogroup 0x605A 0x605A | Quick stop option code
* @{
* \brief Object 0x605A (Quick stop option code) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x605A = { DEFTYPE_INTEGER16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x605A[] = "Quick stop option code\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT16 QuickStopOptionCode0x605A
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x605B : Shutdown option code
******************************************************************************/
/**
* \addtogroup 0x605B 0x605B | Shutdown option code
* @{
* \brief Object 0x605B (Shutdown option code) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x605B = { DEFTYPE_INTEGER16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x605B[] = "Shutdown option code\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT16 ShutdownOptionCode0x605B
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x605C : Disable operation option code
******************************************************************************/
/**
* \addtogroup 0x605C 0x605C | Disable operation option code
* @{
* \brief Object 0x605C (Disable operation option code) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x605C = { DEFTYPE_INTEGER16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x605C[] = "Disable operation option code\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT16 DisableOperationOptionCode0x605C
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x605E : Fault reaction option code
******************************************************************************/
/**
* \addtogroup 0x605E 0x605E | Fault reaction option code
* @{
* \brief Object 0x605E (Fault reaction option code) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x605E = { DEFTYPE_INTEGER16 , 0x10 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x605E[] = "Fault reaction option code\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT16 FaultReactionOptionCode0x605E
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x0000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6060 : Modes of operation
******************************************************************************/
/**
* \addtogroup 0x6060 0x6060 | Modes of operation
* @{
* \brief Object 0x6060 (Modes of operation) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6060 = { DEFTYPE_INTEGER8 , 0x08 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6060[] = "Modes of operation\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT8 ModesOfOperation0x6060
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6061 : Modes of operation display
******************************************************************************/
/**
* \addtogroup 0x6061 0x6061 | Modes of operation display
* @{
* \brief Object 0x6061 (Modes of operation display) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6061 = { DEFTYPE_INTEGER8 , 0x08 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6061[] = "Modes of operation display\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT8 ModesOfOperationDisplay0x6061
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6064 : Position actual value
******************************************************************************/
/**
* \addtogroup 0x6064 0x6064 | Position actual value
* @{
* \brief Object 0x6064 (Position actual value) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6064 = { DEFTYPE_INTEGER32 , 0x20 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6064[] = "Position actual value\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT32 PositionActualValue0x6064
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x606C : Velocity Actual Value
******************************************************************************/
/**
* \addtogroup 0x606C 0x606C | Velocity Actual Value
* @{
* \brief Object 0x606C (Velocity Actual Value) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x606C = { DEFTYPE_INTEGER32 , 0x20 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x606C[] = "Velocity Actual Value\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT32 VelocityActualValue0x606C
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6077 : Torque actual value
******************************************************************************/
/**
* \addtogroup 0x6077 0x6077 | Torque actual value
* @{
* \brief Object 0x6077 (Torque actual value) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6077 = { DEFTYPE_INTEGER32 , 0x20 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6077[] = "Torque actual value\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT32 TorqueActualValue0x6077
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x607A : Target position
******************************************************************************/
/**
* \addtogroup 0x607A 0x607A | Target position
* @{
* \brief Object 0x607A (Target position) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x607A = { DEFTYPE_INTEGER32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x607A[] = "Target position\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT32 TargetPosition0x607A
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x607D : Software position limit
******************************************************************************/
/**
* \addtogroup 0x607D 0x607D | Software position limit
* @{
* \brief Object 0x607D (Software position limit) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Min position limit<br>
* SubIndex 2 - Max position limit<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x607D[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_INTEGER32 , 0x20 , ACCESS_READWRITE }, /* Subindex1 - Min position limit */
{ DEFTYPE_INTEGER32 , 0x20 , ACCESS_READWRITE }}; /* Subindex2 - Max position limit */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x607D[] = "Software position limit\000"
"Min position limit\000"
"Max position limit\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
INT32 MinPositionLimit; /* Subindex1 - Min position limit */
INT32 MaxPositionLimit; /* Subindex2 - Max position limit */
} OBJ_STRUCT_PACKED_END
TOBJ607D;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ607D SoftwarePositionLimit0x607D
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={2,0x00000000,0x00000000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6085 : Quick stop deceleration
******************************************************************************/
/**
* \addtogroup 0x6085 0x6085 | Quick stop deceleration
* @{
* \brief Object 0x6085 (Quick stop deceleration) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6085 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6085[] = "Quick stop deceleration\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 QuickStopDeceleration0x6085
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x60C2 : Interpolation time period
******************************************************************************/
/**
* \addtogroup 0x60C2 0x60C2 | Interpolation time period
* @{
* \brief Object 0x60C2 (Interpolation time period) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Interpolation time period value<br>
* SubIndex 2 - Interpolation time index<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x60C2[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE }, /* Subindex1 - Interpolation time period value */
{ DEFTYPE_INTEGER8 , 0x08 , ACCESS_READWRITE }}; /* Subindex2 - Interpolation time index */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x60C2[] = "Interpolation time period\000"
"Interpolation time period value\000"
"Interpolation time index\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 InterpolationTimePeriodValue; /* Subindex1 - Interpolation time period value */
INT8 InterpolationTimeIndex; /* Subindex2 - Interpolation time index */
} OBJ_STRUCT_PACKED_END
TOBJ60C2;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ60C2 InterpolationTimePeriod0x60C2
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={2,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x60FF : Target velocity
******************************************************************************/
/**
* \addtogroup 0x60FF 0x60FF | Target velocity
* @{
* \brief Object 0x60FF (Target velocity) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x60FF = { DEFTYPE_INTEGER32 , 0x20 , ACCESS_READWRITE };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x60FF[] = "Target velocity\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO INT32 TargetVelocity0x60FF
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000000
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6502 : Supported drive modes
******************************************************************************/
/**
* \addtogroup 0x6502 0x6502 | Supported drive modes
* @{
* \brief Object 0x6502 (Supported drive modes) definition
*/
#ifdef _OBJD_
/**
* \brief Entry description
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM sEntryDesc0x6502 = { DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ };
/**
* \brief Object name
*/
OBJCONST UCHAR OBJMEM aName0x6502[] = "Supported drive modes\000\377";
#endif //#ifdef _OBJD_

/**
* \brief Object variable
*/
PROTO UINT32 SupportedDriveModes0x6502
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
= 0x00000180
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0xF000 : Modular Device Profile
******************************************************************************/
/**
* \addtogroup 0xF000 0xF000 | Modular Device Profile
* @{
* \brief Object 0xF000 (Modular Device Profile) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Index distance <br>
* SubIndex 2 - Maximum number of modules <br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex1 - Index distance  */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex2 - Maximum number of modules  */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0xF000[] = "Modular Device Profile\000"
"Index distance \000"
"Maximum number of modules \000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 IndexDistance; /* Subindex1 - Index distance  */
UINT16 MaximumNumberOfModules; /* Subindex2 - Maximum number of modules  */
} OBJ_STRUCT_PACKED_END
TOBJF000;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJF000 ModularDeviceProfile0xF000
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={2,0x0800,0x0001}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0xF010 : Module Profile List
******************************************************************************/
/**
* \addtogroup 0xF010 0xF010 | Module Profile List
* @{
* \brief Object 0xF010 (Module Profile List) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF010[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0xF010[] = "Module Profile List\000\377";
#endif //#ifdef _OBJD_

#ifndef _CI_A402_EXAMPLE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT32 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJF010;
#endif //#ifndef _CI_A402_EXAMPLE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJF010 ModuleProfileList0xF010
#if defined(_CI_A402_EXAMPLE_) && (_CI_A402_EXAMPLE_ == 1)
={1,{0x00020192}}
#endif
;
/** @}*/





PROTO UINT8 ModeRead(UINT16 index, UINT8 subindex, UINT32 dataSize, UINT16 MBXMEM * pData, UINT8 bCompleteAccess);
PROTO UINT8 ModeWrite(UINT16 index, UINT8 subindex, UINT32 dataSize, UINT16 MBXMEM * pData, UINT8 bCompleteAccess);


#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 5 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &RxPdoMappingCspCsV0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1601 */
{NULL , NULL ,  0x1601 , {DEFTYPE_PDOMAPPING , 3 | (OBJCODE_REC << 8)} , asEntryDesc0x1601 , aName0x1601 , &RxPdoMappingCsp0x1601 , NULL , NULL , 0x0000 },
/* Object 0x1602 */
{NULL , NULL ,  0x1602 , {DEFTYPE_PDOMAPPING , 3 | (OBJCODE_REC << 8)} , asEntryDesc0x1602 , aName0x1602 , &RxPdoMappingCsv0x1602 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 5 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &TxPdoMappingCspCsV0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1A01 */
{NULL , NULL ,  0x1A01 , {DEFTYPE_PDOMAPPING , 3 | (OBJCODE_REC << 8)} , asEntryDesc0x1A01 , aName0x1A01 , &TxPdoMappingCsp0x1A01 , NULL , NULL , 0x0000 },
/* Object 0x1A02 */
{NULL , NULL ,  0x1A02 , {DEFTYPE_PDOMAPPING , 3 | (OBJCODE_REC << 8)} , asEntryDesc0x1A02 , aName0x1A02 , &TxPdoMappingCsv0x1A02 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x3500 */
{NULL , NULL ,  0x3500 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x3500 , aName0x3500 , &SdoData00x3500 , NULL , NULL , 0x0000 },
/* Object 0x3501 */
{NULL , NULL ,  0x3501 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x3501 , aName0x3501 , &SdoData10x3501 , NULL , NULL , 0x0000 },
/* Object 0x3502 */
{NULL , NULL ,  0x3502 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x3502 , aName0x3502 , &SdoData20x3502 , NULL , NULL , 0x0000 },
/* Object 0x603F */
{NULL , NULL ,  0x603F , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x603F , aName0x603F , &ErrorCode0x603F , NULL , NULL , 0x0000 },
/* Object 0x6040 */
{NULL , NULL ,  0x6040 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6040 , aName0x6040 , &Controlword0x6040 , NULL , NULL , 0x0000 },
/* Object 0x6041 */
{NULL , NULL ,  0x6041 , {DEFTYPE_UNSIGNED16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6041 , aName0x6041 , &Statusword0x6041 , NULL , NULL , 0x0000 },
/* Object 0x605A */
{NULL , NULL ,  0x605A , {DEFTYPE_INTEGER16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x605A , aName0x605A , &QuickStopOptionCode0x605A , NULL , NULL , 0x0000 },
/* Object 0x605B */
{NULL , NULL ,  0x605B , {DEFTYPE_INTEGER16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x605B , aName0x605B , &ShutdownOptionCode0x605B , NULL , NULL , 0x0000 },
/* Object 0x605C */
{NULL , NULL ,  0x605C , {DEFTYPE_INTEGER16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x605C , aName0x605C , &DisableOperationOptionCode0x605C , NULL , NULL , 0x0000 },
/* Object 0x605E */
{NULL , NULL ,  0x605E , {DEFTYPE_INTEGER16 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x605E , aName0x605E , &FaultReactionOptionCode0x605E , NULL , NULL , 0x0000 },
/* Object 0x6060 */
{NULL , NULL ,  0x6060 , {DEFTYPE_INTEGER8 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6060 , aName0x6060 , &ModesOfOperation0x6060 , ModeRead , ModeWrite , 0x0000 },
/* Object 0x6061 */
{NULL , NULL ,  0x6061 , {DEFTYPE_INTEGER8 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6061 , aName0x6061 , &ModesOfOperationDisplay0x6061 , ModeRead , ModeWrite , 0x0000 },
/* Object 0x6064 */
{NULL , NULL ,  0x6064 , {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6064 , aName0x6064 , &PositionActualValue0x6064 , NULL , NULL , 0x0000 },
/* Object 0x606C */
{NULL , NULL ,  0x606C , {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x606C , aName0x606C , &VelocityActualValue0x606C , NULL , NULL , 0x0000 },
/* Object 0x6077 */
{NULL , NULL ,  0x6077 , {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6077 , aName0x6077 , &TorqueActualValue0x6077 , NULL , NULL , 0x0000 },
/* Object 0x607A */
{NULL , NULL ,  0x607A , {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x607A , aName0x607A , &TargetPosition0x607A , NULL , NULL , 0x0000 },
/* Object 0x607D */
{NULL , NULL ,  0x607D , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x607D , aName0x607D , &SoftwarePositionLimit0x607D , NULL , NULL , 0x0000 },
/* Object 0x6085 */
{NULL , NULL ,  0x6085 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6085 , aName0x6085 , &QuickStopDeceleration0x6085 , NULL , NULL , 0x0000 },
/* Object 0x60C2 */
{NULL , NULL ,  0x60C2 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x60C2 , aName0x60C2 , &InterpolationTimePeriod0x60C2 , NULL , NULL , 0x0000 },
/* Object 0x60FF */
{NULL , NULL ,  0x60FF , {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x60FF , aName0x60FF , &TargetVelocity0x60FF , NULL , NULL , 0x0000 },
/* Object 0x6502 */
{NULL , NULL ,  0x6502 , {DEFTYPE_UNSIGNED32 , 0 | (OBJCODE_VAR << 8)} , &sEntryDesc0x6502 , aName0x6502 , &SupportedDriveModes0x6502 , NULL , NULL , 0x0000 },
/* Object 0xF000 */
{NULL , NULL ,  0xF000 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0xF000 , aName0xF000 , &ModularDeviceProfile0xF000 , NULL , NULL , 0x0000 },
/* Object 0xF010 */
{NULL , NULL ,  0xF010 , {DEFTYPE_UNSIGNED32 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0xF010 , aName0xF010 , &ModuleProfileList0xF010 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _CI_A402_EXAMPLE_OBJECTS_H_
