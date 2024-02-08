
#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_

/*LEDs States Enum*/
typedef enum{
	LED_IDLE ,LED_ACTIVE
}LED_STATE_t;


/*mode state*/
typedef enum{
	NORMAL_MODE, PEDESTRIAN_MODE
}MODE_t;






/*all Initials I need */
void APP_voidInit(void);

/*All application logic*/
void APP_voidPeriodicTask(void);

/*INT0_ISR function Prototype*/
void INT0_ISR(void);

#endif /* APP_APP_INTERFACE_H_ */
