// Function: FUN_0054a580 @ 0054a580
// Size (bytes): 47


void __fastcall FUN_0054a580(undefined4 param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    DAT_008b8f3c = param_2;
    return;
  }
  if (param_3 != 2) {
    DAT_008b8f3c = DAT_008b8f3c + param_2;
    return;
  }
  DAT_008b8f3c = DAT_008b8f38 - param_2;
  return;
}


