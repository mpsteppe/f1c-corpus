// Function: FUN_004bb730 @ 004bb730
// Strings:  [Gearbox, Engine, Brakes, Suspension, Clutch, Electronics, Accident]


char * __fastcall FUN_004bb730(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return s_Engine_005c316c;
  case 2:
    return s_Gearbox_005c3164;
  case 3:
  case 7:
    return s_Clutch_005c55cc;
  case 4:
    return s_Suspension_005c317c;
  case 5:
    return s_Brakes_005c3174;
  case 6:
    return s_Accident_005d253c;
  case 8:
    return s_Electronics_005d2530;
  case 9:
    return &DAT_005d2528;
  default:
    return &DAT_005d2524;
  }
}


