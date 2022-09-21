/*
 * DIO.c
 *
 *  Created on: seb 21, 2022
 *      Author: Nessma
 */



#include"type.h"
#include"bit_utils.h"

#include"register.h"
#include"DIO.h"


Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level){
    // Data validation to the inputs
    Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk ;

    //Local variables area
    u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
    u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D

    // Data validation to the inputs
    //Check if the channel is not valid
    if(Copy_u8ChannelId > DIO_u8MAX_CHANNELS ){
        Loc_enuReturnStatus = Dio_enuChannelError;
    }
    else if(Copy_u8Level > DIO_u8HIGH ){
        Loc_enuReturnStatus = Dio_enuChannelError;
    }
    // Our Logic
    else{
        Loc_u8PinNum = Copy_u8ChannelId % DIO_u8REG_SIZE;
        Loc_u8PortNum = Copy_u8ChannelId / DIO_u8REG_SIZE ;

        switch(Loc_u8PortNum){
            case DIO_u8PORTA :
                if(GET_BIT(DDRA,Loc_u8PinNum)== DIO_u8OUTPUT){
                    switch(Copy_u8Level){
                        case DIO_u8HIGH:
                            SET_BIT(PORTA, Loc_u8PinNum);
                            break;
                        case DIO_u8LOW:
                        	CLR_BIT(PORTA, Loc_u8PinNum);
                            break;
                    }
                }
                else{
                    Loc_enuReturnStatus = Dio_enuDirectionError;
                }
                break;
            case DIO_u8PORTB:
			if(GET_BIT(DDRB,Loc_u8PinNum)== DIO_u8OUTPUT){
                    switch(Copy_u8Level){
                        case DIO_u8HIGH:
                            SET_BIT(PORTB, Loc_u8PinNum);
                            break;
                        case DIO_u8LOW:
                            CLR_BIT(PORTB, Loc_u8PinNum);
                            break;
                    }
                }
                else{
                    Loc_enuReturnStatus = Dio_enuDirectionError;
                }
                break;
                case DIO_u8PORTC:
			if(GET_BIT(DDRC,Loc_u8PinNum)== DIO_u8OUTPUT){
                    switch(Copy_u8Level){
                        case DIO_u8HIGH:
                            SET_BIT(PORTC, Loc_u8PinNum);
                            break;
                        case DIO_u8LOW:
                            CLR_BIT(PORTC, Loc_u8PinNum);
                            break;
                    }
                }
                else{
                    Loc_enuReturnStatus = Dio_enuDirectionError;
                }
                break;
                case DIO_u8PORTD:
			if(GET_BIT(DDRD,Loc_u8PinNum)== DIO_u8OUTPUT){
                    switch(Copy_u8Level){
                        case DIO_u8HIGH:
                            SET_BIT(PORTD, Loc_u8PinNum);
                            break;
                        case DIO_u8LOW:
                            CLR_BIT(PORTD, Loc_u8PinNum);
                            break;
                    }
                }
                else{
                    Loc_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            default:
            	break;
        }
    }

    return Loc_enuReturnStatus ;

}
Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId ,pu8 Add_pu8ChannelId)
{
	//Data validation
		Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
		if (Copy_u8ChannelId > DIO_u8MAX_CHANNELS || Copy_u8ChannelId < DIO_u8MIN_CHANNELS) {
			Loc_enuReturnStatus = Dio_enuChannelError;
		}
		else if (Add_pu8ChannelId == NULL) {
			Loc_enuReturnStatus = Dio_enuNullPointer;
		}
		else {
			u8 Loc_u8PinNum = Copy_u8ChannelId % DIO_u8REG_SIZE ;
			u8 Loc_u8PortNum = Copy_u8ChannelId / DIO_u8REG_SIZE ;
			switch (Loc_u8PortNum) {
			case DIO_u8PORTA:
				if (GET_BIT(DDRA, Loc_u8PinNum) == DIO_u8INPUT) {
					*Add_pu8ChannelId = GET_BIT(PINA, Loc_u8PinNum);
				}
				else {
					Loc_enuReturnStatus = Dio_enuDirectionError;
				}
				break;
		      case DIO_u8PORTB:
							if (GET_BIT(DDRB, Loc_u8PinNum) == DIO_u8INPUT) {
								*Add_pu8ChannelId = GET_BIT(PINB, Loc_u8PinNum);
							}
							else {
								Loc_enuReturnStatus = Dio_enuDirectionError;
							}
							break;
		      case DIO_u8PORTC:
							if (GET_BIT(DDRC, Loc_u8PinNum) == DIO_u8INPUT) {
								*Add_pu8ChannelId = GET_BIT(PINC, Loc_u8PinNum);
							}
							else {
								Loc_enuReturnStatus = Dio_enuDirectionError;
							}
							break;
		      case DIO_u8PORTD:
							if (GET_BIT(DDRD, Loc_u8PinNum) == DIO_u8INPUT) {
								*Add_pu8ChannelId = GET_BIT(PIND, Loc_u8PinNum);
							}
							else {
								Loc_enuReturnStatus = Dio_enuDirectionError;
							}
							break;
		      default:
		    	  break;


			}
}
		 return Loc_enuReturnStatus ;
}
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value)
{
	//Data validation
			Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
			 u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D
			 if(Copy_u8PortId > DIO_u8MAX_PORTS|| Copy_u8PortId < DIO_u8MIN_PORTS){
			        Loc_enuReturnStatus =  Dio_enuPortError;
			    }
			 else{
				 switch(Loc_u8PortNum)
				 {
				 case DIO_u8PORTA:
					 if(DDRA==DIO_u8OUTPUT_PORT)
					 {
						 PORTA=Copy_u8Value;

					 }
					 else {
							Loc_enuReturnStatus = Dio_enuDirectionError;
						}
						break;
				   case DIO_u8PORTB:
									 if(DDRB==DIO_u8OUTPUT_PORT)
									 {
										 PORTB=Copy_u8Value;

									 }
									 else {
											Loc_enuReturnStatus = Dio_enuDirectionError;
										}
										break;
				   case DIO_u8PORTC:
				  					 if(DDRC==DIO_u8OUTPUT_PORT)
				  					 {
				  						 PORTC=Copy_u8Value;

				  					 }
				  					 else {
				  							Loc_enuReturnStatus = Dio_enuDirectionError;
				  						}
				  						break;
				   case DIO_u8PORTD:
				  					 if(DDRD==DIO_u8OUTPUT_PORT)
				  					 {
				  						 PORTD=Copy_u8Value;

				  					 }
				  					 else {
				  							Loc_enuReturnStatus = Dio_enuDirectionError;
				  						}
				  						break;
				   default:
					   break;

				 }
			 }

			 return Loc_enuReturnStatus ;

}
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId ,pu8 Add_up8PortId)
{
	//Data validation
				Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;

				 if(Copy_u8PortId > DIO_u8MAX_PORTS|| Copy_u8PortId < DIO_u8MIN_PORTS){
				 			        Loc_enuReturnStatus =  Dio_enuPortError;
				 			    }
				 else if (Add_up8PortId == NULL) {
				 			Loc_enuReturnStatus = Dio_enuNullPointer;
				 }
				 else
				 {
					 u8 Loc_u8PortNum = Copy_u8PortId / DIO_u8REG_SIZE ;
					 switch(Loc_u8PortNum)
					 {
					 case DIO_u8PORTA:
						 if(DDRA==DIO_u8INPUT_PORT){
						 *Add_up8PortId= PINA;
						 }
						 else {
						 	    Loc_enuReturnStatus = Dio_enuDirectionError;
						 	}
						 break;
					 case DIO_u8PORTB:
							if(DDRB==DIO_u8INPUT_PORT){
									*Add_up8PortId= PINB;
								}
							else {
									 Loc_enuReturnStatus = Dio_enuDirectionError;
								}
									break;
					 case DIO_u8PORTC:
							if(DDRC==DIO_u8INPUT_PORT){
								*Add_up8PortId= PINC;
								}
							else {
									 Loc_enuReturnStatus = Dio_enuDirectionError;
								}
									break;
					 case DIO_u8PORTD:
					 	 if(DDRD==DIO_u8INPUT_PORT){
					 			*Add_up8PortId= PIND;
					 			}
					 	else {
					 			 Loc_enuReturnStatus = Dio_enuDirectionError;
					 		}
					 									break;

					 default:
						 break;


					 }
				 }

				 return Loc_enuReturnStatus ;

}


Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId){
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
	u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
	u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D
	if((Copy_u8ChannelId > DIO_u8MAX_CHANNELS) || (Copy_u8ChannelId < DIO_u8MIN_CHANNELS)  )
			{
				Loc_enuReturnStatus = Dio_enuChannelError;
			}

			else
			{
				Loc_u8PinNum = Copy_u8ChannelId % DIO_u8REG_SIZE;
				Loc_u8PortNum = Copy_u8ChannelId / DIO_u8REG_SIZE ;

				switch(Loc_u8PortNum)
				{
					case DIO_u8PORTA :
						TGL_BIT(PORTA, Loc_u8PinNum);
						break;
					case DIO_u8PORTB:
						TGL_BIT(PORTB, Loc_u8PinNum);
						break;
					case DIO_u8PORTC:
						TGL_BIT(PORTC, Loc_u8PinNum);
						break;
					case DIO_u8PORTD:
						TGL_BIT(PORTD, Loc_u8PinNum);
						break;
					default:
					{
						Loc_enuReturnStatus = Dio_enuChannelError;
					}
				}
			}
			return Loc_enuReturnStatus ;
	}






