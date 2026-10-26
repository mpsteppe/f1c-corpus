// Function: FUN_004a47e0 @ 004a47e0
// Strings:  [FUEL:, ERROR, STOP/GO:, DAMAGE:, WING:, TYRES:]


char * __fastcall FUN_004a47e0(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return s_STOP_GO__005cd4d4;
  case 1:
    return &DAT_005ccc78;
  case 2:
    return s_TYRES__005cd4f0;
  case 3:
    return s_WING__005cd4e8;
  case 4:
    return s_DAMAGE__005cd4e0;
  default:
    return s_ERROR_005cd4cc;
  }
}


