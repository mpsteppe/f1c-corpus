// Function: FUN_0052da10 @ 0052da10
// Size (bytes): 31


void __fastcall FUN_0052da10(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0x240;
  if (DAT_008b0108 == 0) {
    iVar1 = 0x480;
  }
  for (; param_1 = param_1 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
  }
  return;
}


