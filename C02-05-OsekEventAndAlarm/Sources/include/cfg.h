#ifndef OCC_CFG_H
#define OCC_CFG_H

#define     OSDEFAULTAPPMODE        0


//ISR functions
extern      void        Ir_RealTimInt(void);

//Task IDs
#define     Task1       0
#define     Task2       1
#define     Task3       2
#define     Task4       3
#define     Task5       4
#define     Task6       5
#define     Task7       6
#define     Task8       7
#define     Task9       8
#define     Task10      9

//task functions
extern  void    FuncTask1(void);
extern  void    FuncTask2(void);
extern  void    FuncTask3(void);
extern  void    FuncTask4(void);
extern  void    FuncTask5(void);
extern  void    FuncTask6(void);
extern  void    FuncTask7(void);
extern  void    FuncTask8(void);
extern  void    FuncTask9(void);
extern  void    FuncTask10(void);

//COUNTER IDs
#define     SysCounter      0

//RESOURCE IDs
#define     R1      &osekResource_ResourceTable[0]
#define     R2      &osekResource_ResourceTable[1]
#define     R3      &osekResource_ResourceTable[2]

//ALARM configuration lists
#define     Alarm1      &osekAlarm_AlarmTable[0]
#define     Alarm2      &osekAlarm_AlarmTable[1]
#define     Alarm3      &osekAlarm_AlarmTable[2]
#define     Alarm4      &osekAlarm_AlarmTable[3]
#define     Alarm5      &osekAlarm_AlarmTable[4]
#define     Alarm6      &osekAlarm_AlarmTable[5]
#define     Alarm7      &osekAlarm_AlarmTable[6]
#define     Alarm8      &osekAlarm_AlarmTable[7]

#if defined (OCC_LOCALMESSAGESONLY)
//message IDs
#define     Msg1        &osekMsg_MessageTable[0]
#define     Msg2        &osekMsg_MessageTable[1]

#endif  /* OCC_LOCALMESSAGESONLY */

#endif /* ifndef OCC_CFG_H */
