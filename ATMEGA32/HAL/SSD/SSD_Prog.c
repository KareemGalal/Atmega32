#include "..\..\Utilities\Types.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "SSD_Config.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"

typedef struct {u8 SEGA : 1, SEGB : 1, SEGC : 1, SEGD : 1, SEGE : 1, SEGF : 1, SEGG : 1;} SevSegPins;

/*Comment!: Global Array for ComCath Type Segments(SEGA:G) Status for a Specific Number*/
static const SevSegPins SSD_Digits_ComCath[10] = { { 1, 1, 1, 1, 1, 1, 0 },  // = 0
		{ 0, 1, 1, 0, 0, 0, 0 },  // = 1
		{ 1, 1, 0, 1, 1, 0, 1 },  // = 2
		{ 1, 1, 1, 1, 0, 0, 1 },  // = 3
		{ 0, 1, 1, 0, 0, 1, 1 },  // = 4
		{ 1, 0, 1, 1, 0, 1, 1 },  // = 5
		{ 1, 0, 1, 1, 1, 1, 1 },  // = 6
		{ 1, 1, 1, 0, 0, 0, 0 },  // = 7
		{ 1, 1, 1, 1, 1, 1, 1 },  // = 8
		{ 1, 1, 1, 1, 0, 1, 1 }   // = 9
};

// make it empty and initialize it in the init function

/*Comment!: Global Array for ComAnod Type Segments(SEGA:G) Status for a Specific Number*/
static const SevSegPins SSD_Digits_ComAnod[10] = { { 0, 0, 0, 0, 0, 0, 1 },  // = 0
		{ 1, 0, 0, 1, 1, 1, 1 },  // = 1
		{ 0, 0, 1, 0, 0, 1, 0 },  // = 2
		{ 0, 0, 0, 0, 1, 1, 0 },  // = 3
		{ 1, 0, 0, 1, 1, 0, 0 },  // = 4
		{ 0, 1, 0, 0, 1, 0, 0 },  // = 5
		{ 0, 1, 0, 0, 0, 0, 0 },  // = 6
		{ 0, 0, 0, 1, 1, 1, 1 },  // = 7
		{ 0, 0, 0, 0, 0, 0, 0 },  // = 8
		{ 0, 0, 0, 0, 1, 0, 0 }   // = 9
};

/*Comment!: Global Array of Current Values for the 6 Displays*/
static volatile u8 SSD_CurrentVal[SSD_u8TOTALSSDS] = { SSD_u8DISP1_INITVAL,
SSD_u8DISP2_INITVAL, SSD_u8DISP3_INITVAL, SSD_u8DISP4_INITVAL,
SSD_u8DISP5_INITVAL, SSD_u8DISP6_INITVAL };

/*Comment!: Function to Display a Specific Num on a Specific Display*/
extern u8 SSD_u8Display(u8 Copy_u8DispIdx, u8 Copy_u8DispVal) {
  u8 Local_u8RetrunStatus;
  //u8 Local_u8LoopCount;
  //if( (Copy_u8DispIdx >= SSD_u8DISP1) && (Copy_u8DispIdx <= SSD_u8DISP6) )
  switch (Copy_u8DispIdx) {
#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP1:
      /*for (Local_u8LoopCount = 0; Local_u8LoopCount < 7;Local_u8LoopCount++) {
        DIO_u8WritePinVal(SSD_u8DISP1_SEGA,SSD_Digits_ComCath[Copy_u8DispVal][Local_u8LoopCount]);
        }*/
      //DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComCath[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComCath[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComCath[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComCath[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComCath[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComCath[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComCath[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP1:
      //DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#endif
#endif
#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP2:
      //DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComCath[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComCath[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComCath[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComCath[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComCath[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComCath[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComCath[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP2:
      //DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#endif
#endif
#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP3:
      //DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComCath[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComCath[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComCath[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComCath[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComCath[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComCath[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComCath[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP3:
      //DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#endif
#endif
#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP4:
      //DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComCath[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComCath[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComCath[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComCath[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComCath[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComCath[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComCath[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP4:
      //DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#endif
#endif
#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP5:
      //DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComCath[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComCath[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComCath[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComCath[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComCath[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComCath[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComCath[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP5:
      //DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#endif
#endif
#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
    case SSD_u8DISP6:
      //DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComCath[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComCath[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComCath[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComCath[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComCath[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComCath[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComCath[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
    case SSD_u8DISP6:
      //DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComAnod[Copy_u8DispVal].SEGA);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComAnod[Copy_u8DispVal].SEGB);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComAnod[Copy_u8DispVal].SEGC);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComAnod[Copy_u8DispVal].SEGD);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComAnod[Copy_u8DispVal].SEGE);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComAnod[Copy_u8DispVal].SEGF);
      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComAnod[Copy_u8DispVal].SEGG);
      Local_u8RetrunStatus = u8OK;
      break;
#endif
#endif
    default:
      Local_u8RetrunStatus = u8ERROR;
      break;
  }
  return Local_u8RetrunStatus;
}

/*Comment!: Function to Get the Current value on a specific Display */
extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx, u8* Copy_u8DispVal) {
//maybe we use DIO_u8ReadPinVal then check value with the fixed array
	u8 Local_u8RetrunStatus;
	if( (Copy_u8DispIdx >= SSD_u8DISP1) && (Copy_u8DispIdx <= SSD_u8DISP6) ){
		*Copy_u8DispVal = SSD_CurrentVal[Copy_u8DispIdx];
		Local_u8RetrunStatus = u8OK;
	}else{
		Local_u8RetrunStatus = u8ERROR;
	}
	return Local_u8RetrunStatus;
}

/*Comment!: Function to Turn ON a Specific Display*/
extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx) {
	u8 Local_u8RetrunStatus;
		switch (Copy_u8DispIdx) {
	#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP1:
			DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP1:
			DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#endif
	#endif
	#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP2:
			DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP2:
			DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#endif
	#endif
	#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP3:
			DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP3:
			DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#endif
	#endif
	#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP4:
			DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP4:
			DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#endif
	#endif
	#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP5:
			DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP5:
			DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#endif
	#endif
	#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
			case SSD_u8DISP6:
			DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
			case SSD_u8DISP6:
			DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
			Local_u8RetrunStatus = u8OK;
			break;
	#endif
	#endif
		default:
			Local_u8RetrunStatus = u8ERROR;
			break;
		}
		return Local_u8RetrunStatus;
}

/*Comment!: Function to Turn OFF a Specific Display*/
extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx) {
	u8 Local_u8RetrunStatus;
	switch (Copy_u8DispIdx) {
#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
	case SSD_u8DISP1:
		DIO_u8WritePinVal(SSD_u8DISP1_COM, !SSD_u8DISP1_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP1:
		DIO_u8WritePinVal(SSD_u8DISP1_COM, !SSD_u8DISP1_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#endif
#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP2:
		DIO_u8WritePinVal(SSD_u8DISP2_COM, !SSD_u8DISP2_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
	case SSD_u8DISP2:
		DIO_u8WritePinVal(SSD_u8DISP2_COM, !SSD_u8DISP2_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#endif
#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP3:
		DIO_u8WritePinVal(SSD_u8DISP3_COM, !SSD_u8DISP3_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP3:
		DIO_u8WritePinVal(SSD_u8DISP3_COM, !SSD_u8DISP3_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#endif
#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP4:
		DIO_u8WritePinVal(SSD_u8DISP4_COM, !SSD_u8DISP4_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP4:
		DIO_u8WritePinVal(SSD_u8DISP4_COM, !SSD_u8DISP4_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#endif
#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP5:
		DIO_u8WritePinVal(SSD_u8DISP5_COM, !SSD_u8DISP5_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP5:
		DIO_u8WritePinVal(SSD_u8DISP5_COM, !SSD_u8DISP5_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#endif
#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
		case SSD_u8DISP6:
		DIO_u8WritePinVal(SSD_u8DISP6_COM, !SSD_u8DISP6_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
		case SSD_u8DISP6:
		DIO_u8WritePinVal(SSD_u8DISP6_COM, !SSD_u8DISP6_TYPE);
		Local_u8RetrunStatus = u8OK;
		break;
#endif
#endif
	default:
		Local_u8RetrunStatus = u8ERROR;
		break;
	}
	return Local_u8RetrunStatus;
}

/*Comment!: Initialization Function*/
extern void SSD_voidInit(void) {
	// Initialize global variables
	#if (SSD_u8DISP1_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP1_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComCath[SSD_u8DISP1_INITVAL].SEGG);
	#elif (SSD_u8DISP1_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP1_COM, SSD_u8DISP1_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGA, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGB, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGC, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGD, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGE, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGF, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP1_SEGG, SSD_Digits_ComAnod[SSD_u8DISP1_INITVAL].SEGG);
	#endif
	#endif
	#if (SSD_u8DISP2_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP2_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComCath[SSD_u8DISP2_INITVAL].SEGG);
	#elif (SSD_u8DISP2_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP2_COM, SSD_u8DISP2_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGA, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGB, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGC, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGD, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGE, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGF, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP2_SEGG, SSD_Digits_ComAnod[SSD_u8DISP2_INITVAL].SEGG);
	#endif
	#endif
	#if (SSD_u8DISP3_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP3_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComCath[SSD_u8DISP3_INITVAL].SEGG);
	#elif (SSD_u8DISP3_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP3_COM, SSD_u8DISP3_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGA, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGB, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGC, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGD, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGE, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGF, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP3_SEGG, SSD_Digits_ComAnod[SSD_u8DISP3_INITVAL].SEGG);
	#endif
	#endif
	#if (SSD_u8DISP4_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP4_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComCath[SSD_u8DISP4_INITVAL].SEGG);
	#elif (SSD_u8DISP4_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP4_COM, SSD_u8DISP4_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGA, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGB, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGC, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGD, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGE, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGF, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP4_SEGG, SSD_Digits_ComAnod[SSD_u8DISP4_INITVAL].SEGG);
	      Local_u8RetrunStatus = u8OK;
	#endif
	#endif
	#if (SSD_u8DISP5_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP5_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComCath[SSD_u8DISP5_INITVAL].SEGG);
	#elif (SSD_u8DISP5_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP5_COM, SSD_u8DISP5_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGA, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGB, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGC, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGD, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGE, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGF, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP5_SEGG, SSD_Digits_ComAnod[SSD_u8DISP5_INITVAL].SEGG);
	#endif
	#endif
	#if (SSD_u8DISP6_INITSTATE==SSD_u8ONSTATE)
	#if (SSD_u8DISP6_TYPE==SSD_u8COMCATH)
	      DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComCath[SSD_u8DISP6_INITVAL].SEGG);
	#elif (SSD_u8DISP6_TYPE==SSD_u8COMANOD)
	      DIO_u8WritePinVal(SSD_u8DISP6_COM, SSD_u8DISP6_TYPE);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGA, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGA);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGB, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGB);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGC, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGC);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGD, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGD);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGE, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGE);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGF, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGF);
	      DIO_u8WritePinVal(SSD_u8DISP6_SEGG, SSD_Digits_ComAnod[SSD_u8DISP6_INITVAL].SEGG);
	#endif
	#endif
}
