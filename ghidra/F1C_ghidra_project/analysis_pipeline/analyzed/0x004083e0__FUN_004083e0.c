// Function: FUN_004083e0 @ 004083e0
// Size (bytes): 50


void __fastcall FUN_004083e0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0x3f800000;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  if (*(char *)((int)param_1 + 0x15) != '\0') {
    FUN_004d8860(1);
    *(undefined1 *)((int)param_1 + 0x15) = 0;
  }
  return;
}


