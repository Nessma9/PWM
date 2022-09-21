/*
 * port.c
 *
 *  Created on: seb 21, 2022
 *      Author: Nessma
 */

#include"type.h"
#include"port.h"
#include"bit_utils.h"
#include"register.h"



Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDirection)
{

	// Data validation to the inputs
	    Port_tenuErrorStatus Loc_enuReturnStatus = Port_enuOk ;
	 //Local variables area
	    u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
	    u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D


	    // Data validation to the inputs
	    //Check if the channel is not valid
	    if( Copy_u8PinNum> Port_u8MAXPin ||Copy_u8PinNum<Port_u8MIMPin){
	        Loc_enuReturnStatus =Port_enuPinError;
	    }
	    else if(Copy_u8PinDirection!=PORT_u8INPUT && Copy_u8PinDirection!=PORT_u8OUTPUT  ){
	        Loc_enuReturnStatus = Port_enuDirectionError;
	    }
	    // Our Logic
	    else{
	        Loc_u8PinNum =  Copy_u8PinNum% PORT_u8REG_SIZE;
	        Loc_u8PortNum =Copy_u8PinNum / PORT_u8REG_SIZE ;


	   switch(Loc_u8PortNum)
	   {
		   case PORT_u8PORTA:
			   switch(Copy_u8PinDirection)
			   {
			   case PORT_u8INPUT:
				   CLR_BIT(DDRA,Loc_u8PinNum);
				   break;
			   case PORT_u8OUTPUT :
				   SET_BIT(DDRA,Loc_u8PinNum);
				   break;
			   default:
				    break;
                       }
		    case PORT_u8PORTB:
		   		   switch(Copy_u8PinDirection)
		   		   {
		   		   case PORT_u8INPUT:
		   			   CLR_BIT(DDRB,Loc_u8PinNum);
		   			   break;
		   		   case PORT_u8OUTPUT :
		   			   SET_BIT(DDRB,Loc_u8PinNum);
		   			   break;
		   		   default:
		   			   break;
		   		   }
		   	case PORT_u8PORTC:
		   		   switch(Copy_u8PinDirection){
		   				 case PORT_u8INPUT:
		   				   		 CLR_BIT(DDRC,Loc_u8PinNum);
		   				   			   break;
		   				   	 case PORT_u8OUTPUT :
		   				   		  SET_BIT(DDRC,Loc_u8PinNum);
		   				   			   break;
		   				   	default:
		   				   			 break;
		   		   }
		   	 case PORT_u8PORTD:
		   			switch(Copy_u8PinDirection){
		   				 case PORT_u8INPUT:
		   				 		CLR_BIT(DDRD,Loc_u8PinNum);
		   				 		   	 break;
		   				 case PORT_u8OUTPUT :
		   				       SET_BIT(DDRD,Loc_u8PinNum);
		   				 		   	break;
		   				 default:
		   				 		    break;
		   				 		 }
		   	default:
		   		break;
		   		   }
	   }
		   		   return  Loc_enuReturnStatus ;
}


Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum , u8 Copy_u8PinMode)
{
	// Data validation to the inputs
		    Port_tenuErrorStatus Loc_enuReturnStatus = Port_enuOk ;
		 //Local variables area
		    u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
		    u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D
		    if( Copy_u8PinNum> Port_u8MAXPin ||Copy_u8PinNum<Port_u8MIMPin){
		   	        Loc_enuReturnStatus =Port_enuPinError;
		    }
		    else if(Copy_u8PinMode!= PORT_u8INPUT_FLOATING && Copy_u8PinMode!=PORT_u8INPUT_PULLUP && Copy_u8PinMode!=PORT_u8OUTPUT_LOW && Copy_u8PinMode!=PORT_u8OUTPUT_HIGH)
		    {
		    	Loc_enuReturnStatus =Port_enuModeError;

		    }
		    else
		    {
		    	 Loc_u8PinNum =  Copy_u8PinNum% PORT_u8REG_SIZE;
		    	 Loc_u8PortNum =Copy_u8PinNum / PORT_u8REG_SIZE ;
		    	 switch(Loc_u8PortNum)
		    	 	   {
		    	 		   case PORT_u8PORTA:
		    	 			   switch(Copy_u8PinMode)
		    	 			   {
		    	 			   case PORT_u8INPUT_FLOATING:
		    	 				  CLR_BIT(DDRA,Loc_u8PinNum);
		    	 				 CLR_BIT(PORTA,Loc_u8PinNum);
		    	 				 break;
		    	 			   case PORT_u8INPUT_PULLUP:
		    	 				  CLR_BIT(DDRA,Loc_u8PinNum);
		    	 				 SET_BIT(PORTA,Loc_u8PinNum);
		    	 				 break;
		    	 			   case PORT_u8OUTPUT_LOW:

							     SET_BIT(DDRA,Loc_u8PinNum);
							     CLR_BIT(PORTA,Loc_u8PinNum);
							     break;
		    	 			   case PORT_u8OUTPUT_HIGH :
		    	 				  SET_BIT(DDRA,Loc_u8PinNum);
		    	 				 SET_BIT(PORTA,Loc_u8PinNum);
		    	 				 break;
		    	 			   default:
		    	 				   break;
		    	 	             }
		    	 	    case PORT_u8PORTB:
		    	 	    	switch(Copy_u8PinMode) {
		    	 	    	case PORT_u8INPUT_FLOATING:
		    	 				  CLR_BIT(DDRB,Loc_u8PinNum);
		    	 				 CLR_BIT(PORTB,Loc_u8PinNum);
		    	 				 break;
		    	 			   case PORT_u8INPUT_PULLUP:
		    	 				  CLR_BIT(DDRB,Loc_u8PinNum);
		    	 				 SET_BIT(PORTB,Loc_u8PinNum);
		    	 				 break;
		    	 			   case PORT_u8OUTPUT_LOW:

							     SET_BIT(DDRB,Loc_u8PinNum);
							     CLR_BIT(PORTB,Loc_u8PinNum);
							     break;
		    	 			   case PORT_u8OUTPUT_HIGH :
		    	 				  SET_BIT(DDRB,Loc_u8PinNum);
		    	 				 SET_BIT(PORTB,Loc_u8PinNum);
		    	 				 break;
		    	 			   default:
		    	 				   break;
		    	 	             }
		    	 	    	case PORT_u8PORTC:
		 		    	 	    switch(Copy_u8PinMode) {
		 		    	 	    	case PORT_u8INPUT_FLOATING:
		 		    	 				  CLR_BIT(DDRC,Loc_u8PinNum);
		 		    	 				 CLR_BIT(PORTC,Loc_u8PinNum);
		 		    	 				 break;
		 		    	 			   case PORT_u8INPUT_PULLUP:
		 		    	 				  CLR_BIT(DDRC,Loc_u8PinNum);
		 		    	 				 SET_BIT(PORTC,Loc_u8PinNum);
		 		    	 				 break;
		 		    	 			   case PORT_u8OUTPUT_LOW:

		 							     SET_BIT(DDRC,Loc_u8PinNum);
		 							     CLR_BIT(PORTC,Loc_u8PinNum);
		 							     break;
		 		    	 			   case PORT_u8OUTPUT_HIGH :
		 		    	 				  SET_BIT(DDRC,Loc_u8PinNum);
		 		    	 				 SET_BIT(PORTC,Loc_u8PinNum);
		 		    	 				 break;
		 		    	 			   default:
		 		    	 				   break;

		 		    	 	             }
		 		    	 	    case PORT_u8PORTD:
		 			 		    	 	    switch(Copy_u8PinMode) {
		 			 		    	 	    	case PORT_u8INPUT_FLOATING:
		 			 		    	 				  CLR_BIT(DDRD,Loc_u8PinNum);
		 			 		    	 				 CLR_BIT(PORTD,Loc_u8PinNum);
		 			 		    	 				 break;
		 			 		    	 			   case PORT_u8INPUT_PULLUP:
		 			 		    	 				  CLR_BIT(DDRD,Loc_u8PinNum);
		 			 		    	 				 SET_BIT(PORTD,Loc_u8PinNum);
		 			 		    	 				 break;
		 			 		    	 			   case PORT_u8OUTPUT_LOW:

		 			 							     SET_BIT(DDRD,Loc_u8PinNum);
		 			 							     CLR_BIT(PORTD,Loc_u8PinNum);
		 			 							     break;
		 			 		    	 			   case PORT_u8OUTPUT_HIGH :
		 			 		    	 				  SET_BIT(DDRD,Loc_u8PinNum);
		 			 		    	 				 SET_BIT(PORTD,Loc_u8PinNum);
		 			 		    	 				 break;
		 			 		    	 			   default:
		 			 		    	 				   break;
		 			 		    	 	    }
		 			 		     default:
		 			 		    	 break;

		    	 	    	}
		    }

		    return  Loc_enuReturnStatus ;


}
